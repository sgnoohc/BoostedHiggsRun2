#include "hwwtree.h"
#include "rooutil.h"
#include "pfcand_calculator.h"

// ./process INPUTFILEPATH OUTPUTINDEX [NEVENTS]
int main(int argc, char** argv)
{
    // Argument checking
    if (argc < 3)
    {
        std::cout << "Usage:" << std::endl;
        std::cout << "  $ ./process INPUTFILES OUTPUTFILE [NEVENTS]" << std::endl;
        std::cout << std::endl;
        std::cout << "  INPUTFILES      comma separated file list" << std::endl;
        std::cout << "  OUTPUTFILE      output file" << std::endl;
        std::cout << "  [NEVENTS=-1]    # of events to run over" << std::endl;
        std::cout << std::endl;
        return 1;
    }

    // Creating output file where we will put the outputs of the processing
    TFile* ofile = new TFile(argv[2], "create");

    if (not ofile->IsOpen())
    {
        std::cout << "Error: output already exists! provide new output name or delete old file. OUTPUTFILE=" << argv[2] << std::endl;
        return 1;
    }

    // Create a TChain of the input files
    // The input files can be comma separated (e.g. "file1.root,file2.root") or with wildcard (n.b. be sure to escape)
    TChain* ch = RooUtil::FileUtil::createTChain("t", argv[1]);

    // Number of events to loop over
    int nEvents = argc > 3 ? atoi(argv[3]) : -1;

    // Create a Looper object to loop over input files
    RooUtil::Looper<hwwtree> looper(ch, &hww, nEvents);

    // Cutflow utility object that creates a tree structure of cuts
    RooUtil::Cutflow cutflow(ofile);

    // Some booleans to identify which sample I am running over
    bool is_wjet_incl = TString(argv[1]).Contains("WJetsToLNu_TuneCUETP8M1");
    bool is_higgs = TString(argv[1]).Contains("M125");

    //=============================================================================
    //
    //
    // Cuts and selections
    //
    //
    //=============================================================================

    //_____________________________________________________________________________
    // The most basic cuts
    cutflow.addCut("CutWeight"               , [&]() { if (is_wjet_incl) return hww.gen_ht() < 400.; else return true; } , [&]() { return hww.evt_scale1fb() * 35.9; } );
    cutflow.addCutToLastActiveCut("CutBVeto" , [&]() { return hww.nbmed()   == 0;                                      } , UNITY                                       );
    cutflow.addCutToLastActiveCut("CutNLep"  , [&]() { return hww.L_p4().pt() > 0;                                     } , UNITY                                       );
    cutflow.addCutToLastActiveCut("CutNAK8"  , [&]() { return hww.J_p4().pt() > 0;                                     } , UNITY                                       );

    //_____________________________________________________________________________
    // Some nested loops to create various cut regions with shorter lines of code
    // std::vector<TString> ISRbins = {"200", "200to300", "300", "300to400", "400", "400to450", "450", "450to500", "500", "500to600", "600"};
    // std::vector<TString> ISRbins = {"200", "300", "400", "450", "500", "600"};
    // std::vector<TString> ISRbins = {"300", "400", "500", "600"};
    std::vector<TString> ISRbins = {"400"};
    std::vector<TString> LeptonChannels = {"El", "Mu"};
    std::vector<TString> Charges = {"Plus", "Minus"};

    for (auto& ISRbin : ISRbins)
    {
        std::vector<TString> ISRbinsLiteral;
        // If the ISRbin literal expression contains "to" (e.g. 400to450) then define upper and lower cut
        if (ISRbin.Contains("to"))
        {
            ISRbinsLiteral = RooUtil::StringUtil::split(ISRbin, "to");
        }
        // Otherwise go from lower cut to very large number cut
        else
        {
            ISRbinsLiteral.push_back(ISRbin);
            ISRbinsLiteral.push_back("999999999");
        }
        float lowISRbin  = ISRbinsLiteral[0].Atof(); // lower cut
        float highISRbin = ISRbinsLiteral[1].Atof(); // upper cut
        cutflow.getCut("CutNAK8");
        cutflow.addCutToLastActiveCut("CutISR"+ISRbin, [=]() { return hww.Recoil_p4().pt() > lowISRbin and hww.Recoil_p4().pt() < highISRbin; }, UNITY);
        for (auto& lepton : LeptonChannels)
        {
            cutflow.getCut("CutISR"+ISRbin);
            cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton, [&]() { return lepton.EqualTo("El") ? abs(hww.L_id())==11 : abs(hww.L_id())==13; }, UNITY);
            for (auto& charge : Charges)
            {
                cutflow.getCut("CutISR"+ISRbin+lepton);
                cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return charge.EqualTo("Plus") ? lepton.EqualTo("El") ? hww.L_id()==-11 : hww.L_id()==-13 : lepton.EqualTo("El") ? hww.L_id()==11 : hww.L_id()==13 ;}, UNITY );
                cutflow.getCut("CutISR"+ISRbin+lepton+charge);
                cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had", [&]() { return (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0) and (hww.dr_L_QQ() < 0.75) and (hww.J_softdropMass() > 15. and hww.J_softdropMass() < 108); }, UNITY);
                {
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHad", [&]() { return is_higgs ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLep", [&]() { return is_higgs ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHadOff", [&]() { return is_higgs ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() < 60.: 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLepOff", [&]() { return is_higgs ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() < 60. : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHadOn", [&]() { return is_higgs ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() >= 60. : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLepOn", [&]() { return is_higgs ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() >= 60. : 1; }, UNITY);
                }
                cutflow.getCut("CutISR"+ISRbin+lepton+charge);
                cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep", [&]() { return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() > 0; }, UNITY);
                {
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHad", [&]() { return is_higgs ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLep", [&]() { return is_higgs ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHadOff", [&]() { return is_higgs ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() < 60.: 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLepOff", [&]() { return is_higgs ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() < 60. : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHadOn", [&]() { return is_higgs ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() >= 60. : 1; }, UNITY);
                    cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLepOn", [&]() { return is_higgs ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() >= 60. : 1; }, UNITY);
                }
            }
        }
    }

    //_____________________________________________________________________________
    // Some strawman selections to each of the channel for study
    for (auto& ISRbin : ISRbins)
    {
        // CutMuMinusHad
        cutflow.getCut("CutISR"+ISRbin+"MuMinusHad");
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return (hww.dr_L_QQ() < 0.8)                           ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.J_softdropMass() > 20.)                    ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)       ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return hww.QQ_p4().mass() > 65. and hww.QQ_p4().mass() < 100.; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return hww.L_customrelIso005EA() < 1.2                 ;}, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass() < 170;}, UNITY);

        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return hww.QQ_p4().mass() < 95. and hww.QQ_p4().mass() > 70.; }, UNITY);
        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return ((hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass()) < 180; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return hww.J_softdropMass() > 80; }, UNITY);
        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return hww.L_customrelIso005EA() < 1.12; }, UNITY);
        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.); }, UNITY);
        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return (hww.J_near_ak4jets_p4().size() > 0 ? fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[0])) : -999) < 0.4; }, UNITY);

        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return hww.J_softdropMass() > 15. and hww.J_softdropMass() < 108; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.J_mass() < 130.)                    ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return hww.L_customrelIso005EA() < 1.12                 ;}, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 154.)       ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return ((hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass()) < 200.; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return hww.Recoil_p4().pt() / (hww.J_p4().pt() + hww.met_pt()) - 1; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut7", [&]() { return hww.QQ_p4().mass() > 70. and hww.QQ_p4().mass() < 100.; }, UNITY);

        // CutMuPlusHad
        cutflow.getCut("CutISR"+ISRbin+"MuPlusHad");
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut1", [&]() { return (hww.dr_L_QQ() < 0.8)                            ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut2", [&]() { return (hww.J_softdropMass() > 20.)                     ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)        ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut4", [&]() { return hww.QQ_p4().mass() > 65. and hww.QQ_p4().mass() < 100.; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut5", [&]() { return hww.L_customrelIso005EA() < 1.2                  ;}, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut6", [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass() < 170;}, UNITY);

        // CutMuMinusLep
        cutflow.getCut("CutISR"+ISRbin+"MuMinusLep");
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                          ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut2", [&]() { return (hww.J_npfcands() > 15)                         ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)       ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut4", [&]() { return (hww.J_softdropMass() > 20)                     ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut5", [&]() { return (hww.J_deep_rawdisc_qcd() < 0.5)                ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut6", [&]() { return (hww.L_relIso03EA() > 0.2)                      ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut7", [&]() { return (hww.L_miniIsoEA() < 0.04)                      ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut8", [&]() { return (hww.J_deep_rawdisc_w() > 0.1)                  ; }, UNITY);

        // CutMuPlusLep
        cutflow.getCut("CutISR"+ISRbin+"MuPlusLep");
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                           ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut2", [&]() { return (hww.J_npfcands() > 15)                          ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)        ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut4", [&]() { return (hww.J_softdropMass() > 20)                      ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut5", [&]() { return (hww.J_deep_rawdisc_qcd() < 0.3)                 ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut6", [&]() { return (hww.L_relIso03EA() > 0.2)                       ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut7", [&]() { return (hww.L_miniIsoEA() < 0.04)                       ; }, UNITY);
        // cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut8", [&]() { return (hww.J_deep_rawdisc_w() > 0.1)                   ; }, UNITY);
    }

    //_____________________________________________________________________________
    // two ak8jets bin
    cutflow.getCut("CutNLep");
    cutflow.addCutToLastActiveCut("Cut2AK8"             , [&]() { return hww.nak8jets() > 1;         } , UNITY );
    cutflow.addCutToLastActiveCut("Cut2AK8ISR400"       , [&]() { return hww.Recoil_p4().pt() > 400; } , UNITY );
    cutflow.addCutToLastActiveCut("Cut2AK8ISR400VMass"  , [&]() { return hww.V_softdropMass() > 65 and hww.V_softdropMass() < 130; } , UNITY );
    cutflow.addCutToLastActiveCut("Cut2AK8ISR400NPFCand", [&]() { return hww.V_npfcands() < 40; } , UNITY );
    cutflow.addCutToLastActiveCut("Cut2AK8ISR400DRLQQ"  , [&]() { return hww.dr_L_QQ() < 0.72; } , UNITY );
    cutflow.addCutToLastActiveCut("Cut2AK8ISR400SubJetEta1", [&]() { return fabs(hww.V_softdropPuppiSubjet1_eta()) < 1.66; } , UNITY );

    //_____________________________________________________________________________
    // VBF bins
    LV vbf_tag_jet0, vbf_tag_jet1;
    int nj_ORed; // Overlap Removed (OR'ed) number of jets
    cutflow.getCut("CutNAK8");
    cutflow.addCutToLastActiveCut("CutNj2" , [&]() { return nj_ORed >= 2; }, UNITY );
    cutflow.addCutToLastActiveCut("CutDEta", [&]() { return fabs(RooUtil::Calc::DeltaEta(vbf_tag_jet0, vbf_tag_jet1)) > 3.5; }, UNITY );
    cutflow.addCutToLastActiveCut("CutVBF" , [&]() { return (vbf_tag_jet0 + vbf_tag_jet1).mass() > 500.; }, UNITY );









    //=============================================================================
    //
    //
    // Histogram definitions
    //
    //
    //=============================================================================

    // Histogram utility object that is used to define the histograms
    RooUtil::Histograms histograms;

    //_____________________________________________________________________________
    // Histogram defintiions
    histograms.addHistogram("Lmet_mass"                , 180 , 0    , 600 , [&](){ return hww.Lmet_p4().mass()                            ;} );
    histograms.addHistogram("Lmet_mt"                  , 180 , 0    , 300 , [&](){ return hww.Lmet_p4().mt()                              ;} );
    histograms.addHistogram("LQQp_mass"                , 180 , 0    , 300 , [&](){ return hww.LQQp_p4().mass()                            ;} );
    histograms.addHistogram("LQQ_mass"                 , 180 , 0    , 300 , [&](){ return hww.LQQ_p4().mass()                             ;} );
    histograms.addHistogram("QQp_mass"                 , 180 , 0    , 300 , [&](){ return hww.QQp_p4().mass()                             ;} );
    histograms.addHistogram("QQ_mass"                  , 180 , 0    , 300 , [&](){ return hww.QQ_p4().mass()                              ;} );

    histograms.addHistogram("QQ_mass_v2"               , 180 , 0    , 300 , [&](){ return RooUtil::Calc::DeltaR(hww.J_p4(), hww.L_p4()) < 0.8 ? (hww.J_p4() - hww.L_p4()).mass() : hww.J_p4().mass() ;} );
    histograms.addHistogram("QQ_mass_SD"               , 180 , 0    , 300 , [&]()
            {
                LV J_SD = RooUtil::Calc::getLV(hww.J_p4().pt(), hww.J_p4().eta(), hww.J_p4().phi(), hww.J_softdropMass());
                return RooUtil::Calc::DeltaR(J_SD, hww.L_p4()) < 0.8 ? (J_SD - hww.L_p4()).mass() : J_SD.mass() ;
            } );
    histograms.addHistogram("QQ_mass_SDv2"             , 180 , 0    , 300 , [&]()
            {
                LV J_SD = RooUtil::Calc::getLV(hww.J_p4().pt(), hww.J_p4().eta(), hww.J_p4().phi(), hww.J_softdropMass());
                return (J_SD - hww.L_p4()).mass() > 0 ? (J_SD - hww.L_p4()).mass() : J_SD.mass() ;
            } );

    histograms.addHistogram("RecoH_mass"               , 180 , 0    , 600 , [&](){ return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass();} );
    histograms.addHistogram("RecoH_mass_maxsol12"      , 180 , 0    , 600 , [&](){ return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() > (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass();} );
    histograms.addHistogram("RecoH_mass_minsol12"      , 180 , 0    , 600 , [&](){ return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass();} );

    histograms.addHistogram("L_relIso03EA"             , 180 , 0    , 4     , [&](){ return hww.L_relIso03EA()                              ;} );
    histograms.addHistogram("L_relIso04DB"             , 180 , 0    , 4     , [&](){ return hww.L_relIso04DB()                              ;} );
    histograms.addHistogram("L_miniIsoEA"              , 180 , 0    , 4     , [&](){ return hww.L_miniIsoEA()                               ;} );
    histograms.addHistogram("L_customrelIso005EA"      , 180 , 0    , 10    , [&](){ return hww.L_customrelIso005EA()                       ;} );
    histograms.addHistogram("L_customrelIso010EA"      , 180 , 0    , 10    , [&](){ return hww.L_customrelIso01EA()                        ;} );
    histograms.addHistogram("L_relIso03EA_zoom"        , 180 , 0    , 0.5   , [&](){ return hww.L_relIso03EA()                              ;} );
    histograms.addHistogram("L_miniIsoEA_zoom"         , 180 , 0    , 0.5   , [&](){ return hww.L_miniIsoEA()                               ;} );
    histograms.addHistogram("L_miniIsoEA_zoomzoom"     , 180 , 0    , 0.05  , [&](){ return hww.L_miniIsoEA()                               ;} );
    histograms.addHistogram("L_customrelIso005EA_zoom" , 180 , 0    , 1.5   , [&](){ return hww.L_customrelIso005EA()                       ;} );
    histograms.addHistogram("L_customrelIso010EA_zoom" , 180 , 0    , 1.5   , [&](){ return hww.L_customrelIso01EA()                        ;} );
    histograms.addHistogram("J_mass"                   , 180 , 0    , 300   , [&](){ return hww.J_mass()                                    ;} );
    histograms.addHistogram("H_mass"                   , 180 , 0    , 500   , [&](){ return hww.H_p4().mass()                               ;} );
    histograms.addHistogram("dr_L_QQ"                  , 180 , 0    , 4     , [&](){ return hww.dr_L_QQ()                                   ;} );
    histograms.addHistogram("dr_L_QQp"                 , 180 , 0    , 4     , [&](){ return hww.dr_L_QQp()                                  ;} );
    histograms.addHistogram("dr_L_J"                   , 180 , 0    , 4     , [&](){ return (RooUtil::Calc::DeltaR(hww.L_p4(), hww.J_p4())) ;} );
    histograms.addHistogram("recoil_pt"                , 180 , 0    , 1500  , [&](){ return hww.Recoil_p4().pt()                            ;} );
    histograms.addHistogram("isrbalancev2"             , 180 , -1.5 , 1.5   , [&](){ return hww.Recoil_p4().pt() / (hww.H_p4().pt()) - 1    ;} );
    histograms.addHistogram("isrbalance"               , 180 , -1.5 , 1.5   , [&](){ return hww.Recoil_p4().pt() / (hww.J_p4().pt() + hww.met_pt()) - 1    ;} );
    histograms.addHistogram("mljreg"                   , 180 , 0    , 500   , [&](){ return (hww.L_p4() + hww.J_p4()).mass()                ;} );
    histograms.addHistogram("mljak4"                   , 180 , 0    , 500   , [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? (hww.L_p4() + hww.J_near_ak4jets_p4()[0]).mass() : -999;} );
    histograms.addHistogram("dphilj"                   , 180 , -1   , 3.1416, [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[0])) : -999;} );
    histograms.addHistogram("drlj"                     , 180 , -1   , 2.    , [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? fabs(RooUtil::Calc::DeltaR(hww.L_p4(), hww.J_near_ak4jets_p4()[0])) : -999;} );
    histograms.addHistogram("detalj"                   , 180 , -1   , 2.    , [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), hww.J_near_ak4jets_p4()[0])) : -999;} );
    histograms.addHistogram("dphilj2"                  , 180 , -1   , 3.1416, [&](){ return hww.J_near_ak4jets_p4().size() > 1 ? fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[1])) : -999;} );
    histograms.addHistogram("drlj2"                    , 180 , -1   , 2.    , [&](){ return hww.J_near_ak4jets_p4().size() > 1 ? fabs(RooUtil::Calc::DeltaR(hww.L_p4(), hww.J_near_ak4jets_p4()[1])) : -999;} );
    histograms.addHistogram("detalj2"                  , 180 , -1   , 2.    , [&](){ return hww.J_near_ak4jets_p4().size() > 1 ? fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), hww.J_near_ak4jets_p4()[1])) : -999;} );
    histograms.addHistogram("dphilj3"                  , 180 , -1   , 3.1416, [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? (RooUtil::Calc::DeltaR(hww.J_near_ak4jets_p4()[0], hww.L_p4()) < 0.4 ? fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[0] - hww.L_p4())) : fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[0]))): -999;} );
    histograms.addHistogram("drlj3"                    , 180 , -1   , 2.    , [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? (RooUtil::Calc::DeltaR(hww.J_near_ak4jets_p4()[0], hww.L_p4()) < 0.4 ? fabs(RooUtil::Calc::DeltaR  (hww.L_p4(), hww.J_near_ak4jets_p4()[0] - hww.L_p4())) : fabs(RooUtil::Calc::DeltaR  (hww.L_p4(), hww.J_near_ak4jets_p4()[0]))): -999;} );
    histograms.addHistogram("detalj3"                  , 180 , -1   , 2.    , [&](){ return hww.J_near_ak4jets_p4().size() > 0 ? (RooUtil::Calc::DeltaR(hww.J_near_ak4jets_p4()[0], hww.L_p4()) < 0.4 ? fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), hww.J_near_ak4jets_p4()[0] - hww.L_p4())) : fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), hww.J_near_ak4jets_p4()[0]))): -999;} );
    histograms.addHistogram("nak8jets"                 , 4   , 1    , 5     , [&](){ return hww.nak8jets()                                  ;} );
    histograms.addHistogram("nb"                       , 5   , 0    , 5     , [&](){ return hww.nb()                                        ;} );
    histograms.addHistogram("nbmed"                    , 5   , 0    , 5     , [&](){ return hww.nbmed()                                     ;} );
    histograms.addHistogram("nbtight"                  , 5   , 0    , 5     , [&](){ return hww.nbtight()                                   ;} );
    histograms.addHistogram("yield"                    , 8   , 0    , 8     , [&](){
                                                                                int yield = -1;
                                                                                if (hww.L_id()== 11&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0)) yield = 0;
                                                                                if (hww.L_id()==-11&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0)) yield = 1;
                                                                                if (hww.L_id()== 11&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() >=0)) yield = 2;
                                                                                if (hww.L_id()==-11&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() >=0)) yield = 3;
                                                                                if (hww.L_id()== 13&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0)) yield = 4;
                                                                                if (hww.L_id()==-13&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0)) yield = 5;
                                                                                if (hww.L_id()== 13&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() >=0)) yield = 6;
                                                                                if (hww.L_id()==-13&& (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() >=0)) yield = 7;
                                                                                return yield;
                                                                            });
    histograms.addHistogram("ak8jet_pt0"             , 180 , 0, 1500, [&](){ return hww.ak8jets_p4().size() > 0 ? hww.ak8jets_p4()[0].pt() : -999; } );
    histograms.addHistogram("ak8jet_pt1"             , 180 , 0, 1500, [&](){ return hww.ak8jets_p4().size() > 1 ? hww.ak8jets_p4()[1].pt() : -999; } );
    histograms.addHistogram("ak8jet_ptr"             , 180 , 0, 1, [&](){ return hww.ak8jets_p4().size() > 1 ? hww.ak8jets_p4()[1].pt() / hww.ak8jets_p4()[0].pt() : -999; } );

    histograms.addHistogram("whad_o_higgs"           , 180 , 0, 2, [&](){ return hww.QQ_p4().pt()   / hww.H_p4().pt() ;} );
    histograms.addHistogram("whad_o_isr"             , 180 , 0, 2, [&](){ return hww.QQ_p4().pt()   / hww.Recoil_p4().pt() ;} );
    histograms.addHistogram("wlep_o_higgs"           , 180 , 0, 2, [&](){ return hww.Lmet_p4().pt() / hww.H_p4().pt() ;} );
    histograms.addHistogram("wlep_o_isr"             , 180 , 0, 2, [&](){ return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() ;} );
    histograms.addHistogram("wlep_minus_whad_o_higgs", 180 ,-2, 2, [&](){ return hww.Lmet_p4().pt() / hww.H_p4().pt() - hww.QQ_p4().pt() / hww.H_p4().pt() ;} );
    histograms.addHistogram("wlep_minus_whad_o_isr"  , 180 ,-2, 2, [&](){ return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() ;} );
    histograms.addHistogram("wlep_minus_J_o_isr"     , 180 ,-2, 2, [&](){ return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.J_p4().pt() / hww.Recoil_p4().pt() ;} );

    histograms.addHistogram("J_softdropMass"                , 180 ,   0 , 300 , [&]() { return hww.J_softdropMass()                ;} );
    histograms.addHistogram("J_nJettinessTau1"              , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau1()              ;} );
    histograms.addHistogram("J_nJettinessTau2"              , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau2()              ;} );
    histograms.addHistogram("J_nJettinessTau3"              , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau3()              ;} );
    histograms.addHistogram("J_deep_rawdisc_h4q"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_h4q()            ;} );
    histograms.addHistogram("J_deep_rawdisc_hbb"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_hbb()            ;} );
    histograms.addHistogram("J_deep_rawdisc_qcd"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_qcd()            ;} );
    histograms.addHistogram("J_deep_rawdisc_top"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_top()            ;} );
    histograms.addHistogram("J_deep_rawdisc_w"              , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_w()              ;} );
    histograms.addHistogram("J_deep_bindisc_w"              , 180 ,   0 ,   1 , [&]() { return hww.J_deep_bindisc_w()              ;} );
    histograms.addHistogram("J_deep_rawdisc_z"              , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_z()              ;} );
    histograms.addHistogram("J_deep_rawdisc_zbb"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_zbb()            ;} );
    histograms.addHistogram("J_softdropPuppiSubjet1_pt"     , 180 ,   0 , 900 , [&]() { return hww.J_softdropPuppiSubjet1_pt()     ;} );
    histograms.addHistogram("J_softdropPuppiSubjet1_eta"    , 180 ,  -5 ,   5 , [&]() { return hww.J_softdropPuppiSubjet1_eta()    ;} );
    histograms.addHistogram("J_softdropPuppiSubjet1_mass"   , 180 ,  -5 ,  80 , [&]() { return hww.J_softdropPuppiSubjet1_mass()   ;} );
    histograms.addHistogram("J_softdropPuppiSubjet2_pt"     , 180 ,   0 , 450 , [&]() { return hww.J_softdropPuppiSubjet2_pt()     ;} );
    histograms.addHistogram("J_softdropPuppiSubjet2_eta"    , 180 ,  -5 ,   5 , [&]() { return hww.J_softdropPuppiSubjet2_eta()    ;} );
    histograms.addHistogram("J_softdropPuppiSubjet2_mass"   , 180 ,  -5 ,  40 , [&]() { return hww.J_softdropPuppiSubjet2_mass()   ;} );
    histograms.addHistogram("J_npfcands"                    , 100 ,   0 , 100 , [&]() { return hww.J_npfcands()                    ;} );
    histograms.addHistogram("J_partonFlavour"               ,  40 ,   0 ,  40 , [&]() { return abs(hww.J_partonFlavour())          ;} );


    // multiplicity
    histograms.addHistogram("nrecolep"               ,  4 ,   0 ,  4 , [&]() { return hww.nrecolep()          ;} );

    // VBF variables
    histograms.addHistogram("detajj"                 , 180 , 0,    6 , [&](){ return nj_ORed >= 2 ? fabs(RooUtil::Calc::DeltaEta(vbf_tag_jet0, vbf_tag_jet1)) : -999;} );
    histograms.addHistogram("mjj"                    , 180 , 0, 2500 , [&](){ return nj_ORed >= 2 ? (vbf_tag_jet0 + vbf_tag_jet1).mass() : -999;} );

    // BDT binning
    std::vector<float> bdt_contents;
    for (unsigned int ii = 0; ii < 18; ++ii)
        bdt_contents.push_back(0);

    for (unsigned int ii = 0; ii < 18; ++ii)
    {
        histograms.addHistogram(TString::Format("BDT%d", ii), 180, 0, 30, [&]() { return bdt_contents[ii]; });
    }

    //_____________________________________________________________________________
    // Below are unused histograms

    // Matching reco ak8 to gen reco isr
    // histograms.addHistogram("V_mass"                        , 180 ,   0 , 300 , [&]() { return hww.V_mass()                        ;} );
    // histograms.addHistogram("V_softdropMass"                , 180 ,   0 , 300 , [&]() { return hww.V_softdropMass()                ;} );
    // histograms.addHistogram("V_nJettinessTau1"              , 180 ,   0 ,   1 , [&]() { return hww.V_nJettinessTau1()              ;} );
    // histograms.addHistogram("V_nJettinessTau2"              , 180 ,   0 ,   1 , [&]() { return hww.V_nJettinessTau2()              ;} );
    // histograms.addHistogram("V_nJettinessTau3"              , 180 ,   0 ,   1 , [&]() { return hww.V_nJettinessTau3()              ;} );
    // histograms.addHistogram("V_deep_rawdisc_h4q"            , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_h4q()            ;} );
    // histograms.addHistogram("V_deep_rawdisc_hbb"            , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_hbb()            ;} );
    // histograms.addHistogram("V_deep_rawdisc_qcd"            , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_qcd()            ;} );
    // histograms.addHistogram("V_deep_rawdisc_top"            , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_top()            ;} );
    // histograms.addHistogram("V_deep_rawdisc_w"              , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_w()              ;} );
    // histograms.addHistogram("V_deep_rawdisc_z"              , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_z()              ;} );
    // histograms.addHistogram("V_deep_rawdisc_zbb"            , 180 ,   0 ,   1 , [&]() { return hww.V_deep_rawdisc_zbb()            ;} );
    // histograms.addHistogram("V_softdropPuppiSubjet1_pt"     , 180 ,   0 , 900 , [&]() { return hww.V_softdropPuppiSubjet1_pt()     ;} );
    // histograms.addHistogram("V_softdropPuppiSubjet1_eta"    , 180 ,  -5 ,   5 , [&]() { return hww.V_softdropPuppiSubjet1_eta()    ;} );
    // histograms.addHistogram("V_softdropPuppiSubjet1_mass"   , 180 ,   0 , 150 , [&]() { return hww.V_softdropPuppiSubjet1_mass()   ;} );
    // histograms.addHistogram("V_softdropPuppiSubjet2_pt"     , 180 ,   0 , 450 , [&]() { return hww.V_softdropPuppiSubjet2_pt()     ;} );
    // histograms.addHistogram("V_softdropPuppiSubjet2_eta"    , 180 ,  -5 ,   5 , [&]() { return hww.V_softdropPuppiSubjet2_eta()    ;} );
    // histograms.addHistogram("V_softdropPuppiSubjet2_mass"   , 180 ,   0 , 150 , [&]() { return hww.V_softdropPuppiSubjet2_mass()   ;} );
    // histograms.addHistogram("V_npfcands"                    , 100 ,   0 , 100 , [&]() { return hww.V_npfcands()                    ;} );
    // histograms.addHistogram("V_partonFlavour"               ,  40 ,   0 ,  40 , [&]() { return abs(hww.V_partonFlavour())          ;} );

    // // opening angle in eta-phi space between lepton and nearest lepton
    // histograms.addHistogram("L_ak4_alpha" , 180, -1, 3.1416, [&]()
    //         { 
    //             if (hww.J_near_ak4jets_p4().size() == 0)
    //                 return -999.9;
    //             TVector2 L(RooUtil::Calc::DeltaEta(hww.L_p4(), hww.J_p4()), RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_p4()));
    //             TVector2 ak4(RooUtil::Calc::DeltaEta(hww.J_near_ak4jets_p4()[0], hww.J_p4()), RooUtil::Calc::DeltaPhi(hww.J_near_ak4jets_p4()[0], hww.J_p4()));
    //             return TMath::ACos(L*ak4 / L.Mod() / ak4.Mod());
    //         });
    // histograms.addHistogram("J_near_ak4jets_pt0", 180, 0, 1000, [&]() { return hww.J_near_ak4jets_p4().size() > 0 ? hww.J_near_ak4jets_p4()[0].pt() : -999; } );
    // histograms.addHistogram("L_ak4_ratio", 180, 0, 4, [&]() { return hww.J_near_ak4jets_p4().size() > 0 ? hww.J_near_ak4jets_p4()[0].pt() / hww.L_p4().pt() : -999; } );

    // histograms.addHistogram("Jmet_mass"                     , 180 ,   0 , 700 , [&]() { return abs(hww.Jmet_p4().mass())           ;} );
    // histograms.addHistogram("Jmet_mt"                       , 180 ,   0 ,1500 , [&]() { return abs(hww.Jmet_p4().mt())             ;} );






    //=============================================================================
    //
    //
    // Booking Cutflow histograms and Variable histograms
    //
    //
    //=============================================================================

    //_____________________________________________________________________________
    // Book cutflows
    cutflow.bookCutflows();

    //_____________________________________________________________________________
    // Book Histograms
    for (auto& ISRbin : ISRbins)
    {
        // cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"ElPlusHad");
        // cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"ElPlusLep");
        // cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"ElMinusHad");
        // cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"ElMinusLep");
        // cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuPlusHad");
        // cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuPlusLep");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusHad");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusLep");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusHadGenHadOn");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusHadGenLepOn");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusHadGenHadOff");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusHadGenLepOff");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusLepGenHadOn");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusLepGenLepOn");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusLepGenHadOff");
        cutflow.bookHistogramsForCutAndBelow(histograms, "CutISR"+ISRbin+"MuMinusLepGenLepOff");
    }

    cutflow.bookHistogramsForCut(histograms, "CutNLep");
    // cutflow.bookHistogramsForCutAndBelow(histograms, "Cut2AK8");
    // cutflow.bookHistogramsForCutAndBelow(histograms, "CutNj2");

    // cutflow.bookHistograms(histograms);







    //=============================================================================
    //
    //
    // Main event loop
    //
    //
    //=============================================================================

    // Print cut structure before starting the loop just to visually see it
    cutflow.printCuts();

    // Looping input file
    while (looper.nextEvent())
    {
        nj_ORed = -999;
        vbf_tag_jet0 = LV();
        vbf_tag_jet1 = LV();
        if (hww.nj() >= 2) // Only do if you have at least two to start with
        {
            // select VBF jets
            std::vector<LV> jets_ORed; // overlap removed (OR'ed)
            for (auto& jet : hww.jets_p4())
            {
                float tmpdr = RooUtil::Calc::DeltaR(jet, hww.J_p4());
                if (tmpdr > 1.2)
                {
                    jets_ORed.push_back(jet);
                }
            }
            nj_ORed = jets_ORed.size();
            if (nj_ORed >= 2)
            {
                vbf_tag_jet0 = jets_ORed[0];
                vbf_tag_jet1 = jets_ORed[1];
            }
        }
        cutflow.fill();

        if (cutflow.getCut("CutISR400MuMinusLep").pass)
        {
            bdt_contents = get_bdt_bin_contents();

            for (unsigned int ii = 0; ii < 18; ++ii)
                std::cout <<  " ii: " << ii <<  " bdt_contents[ii]: " << bdt_contents[ii] <<  std::endl;
        }

    }






    //=============================================================================
    //
    //
    // Exit...
    //
    //
    //=============================================================================

    // Writing output file
    cutflow.saveOutput();

    delete ofile;
}

//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.lep_miniIsoEA()<0.02)                                     ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawMan"    , [&]() { return (hww.recowhad_puppi_mass()>60)*(hww.recowhad_puppi_mass()<105) ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut2", [&]() { return (hww.lep_miniIsoEA()<0.02)                                      ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut3", [&]() { return (hww.recohiggs_max()<200.)                                      ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawMan"    , [&]() { return (hww.recowhad_puppi_mass()>60)*(hww.recowhad_puppi_mass()<105)  ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut3", [&]() { return (hww.lep_customrelIso005EA()<1.12)                                              ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut4", [&]() { return (hww.recowhad_plep_puppi_mass()<154.)                                           ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut5", [&]() { return (hww.recohiggs_min()<200.)                                                      ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut6", [&]() { return ((hww.recoisrmegajet_pt() / (hww.recowhad_puppi_pt() + hww.met_pt()) - 1)<0.2)  ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawMan"    , [&]() { return ((hww.recowhad_mlep_puppi_mass()>70)*(hww.recowhad_mlep_puppi_mass()<100))      ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut2", [&]() { return (hww.recowhad_puppi_mass()<125)                                             ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut3", [&]() { return (hww.lep_customrelIso010EA()<1.28)                                          ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut4", [&]() { return (hww.recowhad_plep_puppi_mass()<141.)                                       ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut5", [&]() { return (hww.recohiggs_min()<200.)                                                  ; }, UNITY);
//        cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawMan"    , [&]() { return ((hww.recowhad_mlep_puppi_mass()>75)*(hww.recowhad_mlep_puppi_mass()<105))  ; }, UNITY);

    // histograms.add2DVecHistogram("zoommoremoreimage_dr", 51, -bound/8., bound/8., "zoommoremoreimage_alpha", 51, -bound/8., bound/8.,
    //         [&]()
    //         {
    //             std::vector<float> rtn;
    //             for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    //             {
    //                 float dr = hww.Htag_pf_dr()[ii];
    //                 float x = dr * TMath::Sin(hww.Htag_pf_alpha()[ii]-hww.Htag_L_alpha());
    //                 rtn.push_back(x);
    //             }
    //             return rtn;
    //         },
    //         [&]()
    //         {
    //             std::vector<float> rtn;
    //             for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    //             {
    //                 float dr = hww.Htag_pf_dr()[ii];
    //                 float y = dr * TMath::Cos(hww.Htag_pf_alpha()[ii]-hww.Htag_L_alpha());
    //                 rtn.push_back(y);
    //             }
    //             return rtn;
    //         },
    //         [&]()
    //         {
    //             std::vector<float> rtn;
    //             for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    //             {
    //                 float wgt = hww.Htag_pf_ptfrac()[ii];
    //                 wgt *= hww.Htag_pf_puppi_wgt()[ii];
    //                 rtn.push_back(wgt);
    //             }
    //             return rtn;
    //         }
    //         );


    // histograms.add2DVecHistogram("zoommoreimage_dr", 51, -bound/4., bound/4., "zoommoreimage_alpha", 51, -bound/4., bound/4.,
    //         [&]()
    //         {
    //             std::vector<float> rtn;
    //             for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    //             {
    //                 float dr = hww.Htag_pf_dr()[ii];
    //                 float x = dr * TMath::Sin(hww.Htag_pf_alpha()[ii]-hww.Htag_L_alpha());
    //                 rtn.push_back(x);
    //             }
    //             return rtn;
    //         },
    //         [&]()
    //         {
    //             std::vector<float> rtn;
    //             for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    //             {
    //                 float dr = hww.Htag_pf_dr()[ii];
    //                 float y = dr * TMath::Cos(hww.Htag_pf_alpha()[ii]-hww.Htag_L_alpha());
    //                 rtn.push_back(y);
    //             }
    //             return rtn;
    //         },
    //         [&]()
    //         {
    //             std::vector<float> rtn;
    //             for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    //             {
    //                 float wgt = hww.Htag_pf_ptfrac()[ii];
    //                 wgt *= hww.Htag_pf_puppi_wgt()[ii];
    //                 rtn.push_back(wgt);
    //             }
    //             return rtn;
    //         }
    //         );

