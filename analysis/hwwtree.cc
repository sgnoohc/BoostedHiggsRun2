#include "hwwtree.h"
hwwtree hww;

void hwwtree::Init(TTree *tree) {
  lep_p4_branch = tree->GetBranch("lep_p4");
  if (lep_p4_branch) lep_p4_branch->SetAddress(&lep_p4_);
  ak8jets_p4_branch = tree->GetBranch("ak8jets_p4");
  if (ak8jets_p4_branch) ak8jets_p4_branch->SetAddress(&ak8jets_p4_);
  jets_p4_branch = tree->GetBranch("jets_p4");
  if (jets_p4_branch) jets_p4_branch->SetAddress(&jets_p4_);
  alljets_p4_branch = tree->GetBranch("alljets_p4");
  if (alljets_p4_branch) alljets_p4_branch->SetAddress(&alljets_p4_);
  gen_recoil_p4_branch = tree->GetBranch("gen_recoil_p4");
  if (gen_recoil_p4_branch) gen_recoil_p4_branch->SetAddress(&gen_recoil_p4_);
  gen_higgs_p4_branch = tree->GetBranch("gen_higgs_p4");
  if (gen_higgs_p4_branch) gen_higgs_p4_branch->SetAddress(&gen_higgs_p4_);
  gen_whad_p4_branch = tree->GetBranch("gen_whad_p4");
  if (gen_whad_p4_branch) gen_whad_p4_branch->SetAddress(&gen_whad_p4_);
  gen_wlep_p4_branch = tree->GetBranch("gen_wlep_p4");
  if (gen_wlep_p4_branch) gen_wlep_p4_branch->SetAddress(&gen_wlep_p4_);
  gen_q0_p4_branch = tree->GetBranch("gen_q0_p4");
  if (gen_q0_p4_branch) gen_q0_p4_branch->SetAddress(&gen_q0_p4_);
  gen_q1_p4_branch = tree->GetBranch("gen_q1_p4");
  if (gen_q1_p4_branch) gen_q1_p4_branch->SetAddress(&gen_q1_p4_);
  gen_lep_p4_branch = tree->GetBranch("gen_lep_p4");
  if (gen_lep_p4_branch) gen_lep_p4_branch->SetAddress(&gen_lep_p4_);
  gen_neu_p4_branch = tree->GetBranch("gen_neu_p4");
  if (gen_neu_p4_branch) gen_neu_p4_branch->SetAddress(&gen_neu_p4_);
  gen_wlep_rest_p4_branch = tree->GetBranch("gen_wlep_rest_p4");
  if (gen_wlep_rest_p4_branch) gen_wlep_rest_p4_branch->SetAddress(&gen_wlep_rest_p4_);
  gen_whad_rest_p4_branch = tree->GetBranch("gen_whad_rest_p4");
  if (gen_whad_rest_p4_branch) gen_whad_rest_p4_branch->SetAddress(&gen_whad_rest_p4_);
  gen_Vq0_p4_branch = tree->GetBranch("gen_Vq0_p4");
  if (gen_Vq0_p4_branch) gen_Vq0_p4_branch->SetAddress(&gen_Vq0_p4_);
  gen_Vq1_p4_branch = tree->GetBranch("gen_Vq1_p4");
  if (gen_Vq1_p4_branch) gen_Vq1_p4_branch->SetAddress(&gen_Vq1_p4_);
  J_p4_branch = tree->GetBranch("J_p4");
  if (J_p4_branch) J_p4_branch->SetAddress(&J_p4_);
  Jmet_p4_branch = tree->GetBranch("Jmet_p4");
  if (Jmet_p4_branch) Jmet_p4_branch->SetAddress(&Jmet_p4_);
  L_p4_branch = tree->GetBranch("L_p4");
  if (L_p4_branch) L_p4_branch->SetAddress(&L_p4_);
  Lmet_p4_branch = tree->GetBranch("Lmet_p4");
  if (Lmet_p4_branch) Lmet_p4_branch->SetAddress(&Lmet_p4_);
  QQ_p4_branch = tree->GetBranch("QQ_p4");
  if (QQ_p4_branch) QQ_p4_branch->SetAddress(&QQ_p4_);
  QQp_p4_branch = tree->GetBranch("QQp_p4");
  if (QQp_p4_branch) QQp_p4_branch->SetAddress(&QQp_p4_);
  LQQ_p4_branch = tree->GetBranch("LQQ_p4");
  if (LQQ_p4_branch) LQQ_p4_branch->SetAddress(&LQQ_p4_);
  LQQp_p4_branch = tree->GetBranch("LQQp_p4");
  if (LQQp_p4_branch) LQQp_p4_branch->SetAddress(&LQQp_p4_);
  H_p4_branch = tree->GetBranch("H_p4");
  if (H_p4_branch) H_p4_branch->SetAddress(&H_p4_);
  Hp_p4_branch = tree->GetBranch("Hp_p4");
  if (Hp_p4_branch) Hp_p4_branch->SetAddress(&Hp_p4_);
  v_p4_branch = tree->GetBranch("v_p4");
  if (v_p4_branch) v_p4_branch->SetAddress(&v_p4_);
  J_near_ak4jets_p4_branch = tree->GetBranch("J_near_ak4jets_p4");
  if (J_near_ak4jets_p4_branch) J_near_ak4jets_p4_branch->SetAddress(&J_near_ak4jets_p4_);
  L_subjet1_p4_branch = tree->GetBranch("L_subjet1_p4");
  if (L_subjet1_p4_branch) L_subjet1_p4_branch->SetAddress(&L_subjet1_p4_);
  L_subjet2_p4_branch = tree->GetBranch("L_subjet2_p4");
  if (L_subjet2_p4_branch) L_subjet2_p4_branch->SetAddress(&L_subjet2_p4_);
  Recoil_p4_branch = tree->GetBranch("Recoil_p4");
  if (Recoil_p4_branch) Recoil_p4_branch->SetAddress(&Recoil_p4_);
  Recoil_leadak4_p4_branch = tree->GetBranch("Recoil_leadak4_p4");
  if (Recoil_leadak4_p4_branch) Recoil_leadak4_p4_branch->SetAddress(&Recoil_leadak4_p4_);
  Recoil_allj_1_4_p4_branch = tree->GetBranch("Recoil_allj_1_4_p4");
  if (Recoil_allj_1_4_p4_branch) Recoil_allj_1_4_p4_branch->SetAddress(&Recoil_allj_1_4_p4_);
  Recoil_allj_1_4_leadak4_p4_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_p4");
  if (Recoil_allj_1_4_leadak4_p4_branch) Recoil_allj_1_4_leadak4_p4_branch->SetAddress(&Recoil_allj_1_4_leadak4_p4_);
  Recoil_j_3_4_p4_branch = tree->GetBranch("Recoil_j_3_4_p4");
  if (Recoil_j_3_4_p4_branch) Recoil_j_3_4_p4_branch->SetAddress(&Recoil_j_3_4_p4_);
  Recoil_j_3_4_leadak4_p4_branch = tree->GetBranch("Recoil_j_3_4_leadak4_p4");
  if (Recoil_j_3_4_leadak4_p4_branch) Recoil_j_3_4_leadak4_p4_branch->SetAddress(&Recoil_j_3_4_leadak4_p4_);

  tree->SetMakeClass(1);

  run_branch = tree->GetBranch("run");
  if (run_branch) run_branch->SetAddress(&run_);
  lumi_branch = tree->GetBranch("lumi");
  if (lumi_branch) lumi_branch->SetAddress(&lumi_);
  evt_branch = tree->GetBranch("evt");
  if (evt_branch) evt_branch->SetAddress(&evt_);
  isData_branch = tree->GetBranch("isData");
  if (isData_branch) isData_branch->SetAddress(&isData_);
  evt_scale1fb_branch = tree->GetBranch("evt_scale1fb");
  if (evt_scale1fb_branch) evt_scale1fb_branch->SetAddress(&evt_scale1fb_);
  genps_weight_branch = tree->GetBranch("genps_weight");
  if (genps_weight_branch) genps_weight_branch->SetAddress(&genps_weight_);
  xsec_br_branch = tree->GetBranch("xsec_br");
  if (xsec_br_branch) xsec_br_branch->SetAddress(&xsec_br_);
  evt_passgoodrunlist_branch = tree->GetBranch("evt_passgoodrunlist");
  if (evt_passgoodrunlist_branch) evt_passgoodrunlist_branch->SetAddress(&evt_passgoodrunlist_);
  CMS4path_branch = tree->GetBranch("CMS4path");
  if (CMS4path_branch) CMS4path_branch->SetAddress(&CMS4path_);
  CMS4index_branch = tree->GetBranch("CMS4index");
  if (CMS4index_branch) CMS4index_branch->SetAddress(&CMS4index_);
  weight_fr_r1_f1_branch = tree->GetBranch("weight_fr_r1_f1");
  if (weight_fr_r1_f1_branch) weight_fr_r1_f1_branch->SetAddress(&weight_fr_r1_f1_);
  weight_fr_r1_f2_branch = tree->GetBranch("weight_fr_r1_f2");
  if (weight_fr_r1_f2_branch) weight_fr_r1_f2_branch->SetAddress(&weight_fr_r1_f2_);
  weight_fr_r1_f0p5_branch = tree->GetBranch("weight_fr_r1_f0p5");
  if (weight_fr_r1_f0p5_branch) weight_fr_r1_f0p5_branch->SetAddress(&weight_fr_r1_f0p5_);
  weight_fr_r2_f1_branch = tree->GetBranch("weight_fr_r2_f1");
  if (weight_fr_r2_f1_branch) weight_fr_r2_f1_branch->SetAddress(&weight_fr_r2_f1_);
  weight_fr_r2_f2_branch = tree->GetBranch("weight_fr_r2_f2");
  if (weight_fr_r2_f2_branch) weight_fr_r2_f2_branch->SetAddress(&weight_fr_r2_f2_);
  weight_fr_r2_f0p5_branch = tree->GetBranch("weight_fr_r2_f0p5");
  if (weight_fr_r2_f0p5_branch) weight_fr_r2_f0p5_branch->SetAddress(&weight_fr_r2_f0p5_);
  weight_fr_r0p5_f1_branch = tree->GetBranch("weight_fr_r0p5_f1");
  if (weight_fr_r0p5_f1_branch) weight_fr_r0p5_f1_branch->SetAddress(&weight_fr_r0p5_f1_);
  weight_fr_r0p5_f2_branch = tree->GetBranch("weight_fr_r0p5_f2");
  if (weight_fr_r0p5_f2_branch) weight_fr_r0p5_f2_branch->SetAddress(&weight_fr_r0p5_f2_);
  weight_fr_r0p5_f0p5_branch = tree->GetBranch("weight_fr_r0p5_f0p5");
  if (weight_fr_r0p5_f0p5_branch) weight_fr_r0p5_f0p5_branch->SetAddress(&weight_fr_r0p5_f0p5_);
  weight_pdf_up_branch = tree->GetBranch("weight_pdf_up");
  if (weight_pdf_up_branch) weight_pdf_up_branch->SetAddress(&weight_pdf_up_);
  weight_pdf_down_branch = tree->GetBranch("weight_pdf_down");
  if (weight_pdf_down_branch) weight_pdf_down_branch->SetAddress(&weight_pdf_down_);
  weight_alphas_down_branch = tree->GetBranch("weight_alphas_down");
  if (weight_alphas_down_branch) weight_alphas_down_branch->SetAddress(&weight_alphas_down_);
  weight_alphas_up_branch = tree->GetBranch("weight_alphas_up");
  if (weight_alphas_up_branch) weight_alphas_up_branch->SetAddress(&weight_alphas_up_);
  nrecolep_branch = tree->GetBranch("nrecolep");
  if (nrecolep_branch) nrecolep_branch->SetAddress(&nrecolep_);
  nak8jets_branch = tree->GetBranch("nak8jets");
  if (nak8jets_branch) nak8jets_branch->SetAddress(&nak8jets_);
  nj_branch = tree->GetBranch("nj");
  if (nj_branch) nj_branch->SetAddress(&nj_);
  nb_branch = tree->GetBranch("nb");
  if (nb_branch) nb_branch->SetAddress(&nb_);
  nbmed_branch = tree->GetBranch("nbmed");
  if (nbmed_branch) nbmed_branch->SetAddress(&nbmed_);
  nbtight_branch = tree->GetBranch("nbtight");
  if (nbtight_branch) nbtight_branch->SetAddress(&nbtight_);
  jets_idx_branch = tree->GetBranch("jets_idx");
  if (jets_idx_branch) jets_idx_branch->SetAddress(&jets_idx_);
  alljets_idx_branch = tree->GetBranch("alljets_idx");
  if (alljets_idx_branch) alljets_idx_branch->SetAddress(&alljets_idx_);
  met_pt_branch = tree->GetBranch("met_pt");
  if (met_pt_branch) met_pt_branch->SetAddress(&met_pt_);
  met_phi_branch = tree->GetBranch("met_phi");
  if (met_phi_branch) met_phi_branch->SetAddress(&met_phi_);
  met_up_pt_branch = tree->GetBranch("met_up_pt");
  if (met_up_pt_branch) met_up_pt_branch->SetAddress(&met_up_pt_);
  met_up_phi_branch = tree->GetBranch("met_up_phi");
  if (met_up_phi_branch) met_up_phi_branch->SetAddress(&met_up_phi_);
  met_dn_pt_branch = tree->GetBranch("met_dn_pt");
  if (met_dn_pt_branch) met_dn_pt_branch->SetAddress(&met_dn_pt_);
  met_dn_phi_branch = tree->GetBranch("met_dn_phi");
  if (met_dn_phi_branch) met_dn_phi_branch->SetAddress(&met_dn_phi_);
  met_gen_pt_branch = tree->GetBranch("met_gen_pt");
  if (met_gen_pt_branch) met_gen_pt_branch->SetAddress(&met_gen_pt_);
  met_gen_phi_branch = tree->GetBranch("met_gen_phi");
  if (met_gen_phi_branch) met_gen_phi_branch->SetAddress(&met_gen_phi_);
  HLT_Ele27_WPLoose_Gsf_branch = tree->GetBranch("HLT_Ele27_WPLoose_Gsf");
  if (HLT_Ele27_WPLoose_Gsf_branch) HLT_Ele27_WPLoose_Gsf_branch->SetAddress(&HLT_Ele27_WPLoose_Gsf_);
  HLT_Ele30_WPLoose_Gsf_branch = tree->GetBranch("HLT_Ele30_WPLoose_Gsf");
  if (HLT_Ele30_WPLoose_Gsf_branch) HLT_Ele30_WPLoose_Gsf_branch->SetAddress(&HLT_Ele30_WPLoose_Gsf_);
  HLT_Ele45_WPLoose_Gsf_branch = tree->GetBranch("HLT_Ele45_WPLoose_Gsf");
  if (HLT_Ele45_WPLoose_Gsf_branch) HLT_Ele45_WPLoose_Gsf_branch->SetAddress(&HLT_Ele45_WPLoose_Gsf_);
  HLT_Ele105_CaloIdVT_GsfTrkIdT_branch = tree->GetBranch("HLT_Ele105_CaloIdVT_GsfTrkIdT");
  if (HLT_Ele105_CaloIdVT_GsfTrkIdT_branch) HLT_Ele105_CaloIdVT_GsfTrkIdT_branch->SetAddress(&HLT_Ele105_CaloIdVT_GsfTrkIdT_);
  HLT_Ele115_CaloIdVT_GsfTrkIdT_branch = tree->GetBranch("HLT_Ele115_CaloIdVT_GsfTrkIdT");
  if (HLT_Ele115_CaloIdVT_GsfTrkIdT_branch) HLT_Ele115_CaloIdVT_GsfTrkIdT_branch->SetAddress(&HLT_Ele115_CaloIdVT_GsfTrkIdT_);
  HLT_IsoTkMu24_branch = tree->GetBranch("HLT_IsoTkMu24");
  if (HLT_IsoTkMu24_branch) HLT_IsoTkMu24_branch->SetAddress(&HLT_IsoTkMu24_);
  HLT_IsoMu24_branch = tree->GetBranch("HLT_IsoMu24");
  if (HLT_IsoMu24_branch) HLT_IsoMu24_branch->SetAddress(&HLT_IsoMu24_);
  HLT_SingleMu50_branch = tree->GetBranch("HLT_SingleMu50");
  if (HLT_SingleMu50_branch) HLT_SingleMu50_branch->SetAddress(&HLT_SingleMu50_);
  HLT_SingleEl40_branch = tree->GetBranch("HLT_SingleEl40");
  if (HLT_SingleEl40_branch) HLT_SingleEl40_branch->SetAddress(&HLT_SingleEl40_);
  HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch = tree->GetBranch("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165");
  if (HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch) HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch->SetAddress(&HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_);
  HLT_Mu50_branch = tree->GetBranch("HLT_Mu50");
  if (HLT_Mu50_branch) HLT_Mu50_branch->SetAddress(&HLT_Mu50_);
  HLT_TkMu50_branch = tree->GetBranch("HLT_TkMu50");
  if (HLT_TkMu50_branch) HLT_TkMu50_branch->SetAddress(&HLT_TkMu50_);
  HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch = tree->GetBranch("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50");
  if (HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch) HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch->SetAddress(&HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_);
  HLT_AK8PFJet360_TrimMass30_branch = tree->GetBranch("HLT_AK8PFJet360_TrimMass30");
  if (HLT_AK8PFJet360_TrimMass30_branch) HLT_AK8PFJet360_TrimMass30_branch->SetAddress(&HLT_AK8PFJet360_TrimMass30_);
  HLT_PFHT800_branch = tree->GetBranch("HLT_PFHT800");
  if (HLT_PFHT800_branch) HLT_PFHT800_branch->SetAddress(&HLT_PFHT800_);
  HLT_PFHT900_branch = tree->GetBranch("HLT_PFHT900");
  if (HLT_PFHT900_branch) HLT_PFHT900_branch->SetAddress(&HLT_PFHT900_);
  HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch = tree->GetBranch("HLT_PFHT650_WideJetMJJ900DEtaJJ1p5");
  if (HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch) HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch->SetAddress(&HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_);
  HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch = tree->GetBranch("HLT_PFHT650_WideJetMJJ950DEtaJJ1p5");
  if (HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch) HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch->SetAddress(&HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_);
  HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch = tree->GetBranch("HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20");
  if (HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch) HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch->SetAddress(&HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_);
  pass_duplicate_se_sm_branch = tree->GetBranch("pass_duplicate_se_sm");
  if (pass_duplicate_se_sm_branch) pass_duplicate_se_sm_branch->SetAddress(&pass_duplicate_se_sm_);
  pass_duplicate_sm_se_branch = tree->GetBranch("pass_duplicate_sm_se");
  if (pass_duplicate_sm_se_branch) pass_duplicate_sm_se_branch->SetAddress(&pass_duplicate_sm_se_);
  gen_recoil_id_branch = tree->GetBranch("gen_recoil_id");
  if (gen_recoil_id_branch) gen_recoil_id_branch->SetAddress(&gen_recoil_id_);
  gen_channel_branch = tree->GetBranch("gen_channel");
  if (gen_channel_branch) gen_channel_branch->SetAddress(&gen_channel_);
  gen_Vq0_id_branch = tree->GetBranch("gen_Vq0_id");
  if (gen_Vq0_id_branch) gen_Vq0_id_branch->SetAddress(&gen_Vq0_id_);
  gen_Vq1_id_branch = tree->GetBranch("gen_Vq1_id");
  if (gen_Vq1_id_branch) gen_Vq1_id_branch->SetAddress(&gen_Vq1_id_);
  gen_q0_id_branch = tree->GetBranch("gen_q0_id");
  if (gen_q0_id_branch) gen_q0_id_branch->SetAddress(&gen_q0_id_);
  gen_q1_id_branch = tree->GetBranch("gen_q1_id");
  if (gen_q1_id_branch) gen_q1_id_branch->SetAddress(&gen_q1_id_);
  gen_lep_id_branch = tree->GetBranch("gen_lep_id");
  if (gen_lep_id_branch) gen_lep_id_branch->SetAddress(&gen_lep_id_);
  gen_neu_id_branch = tree->GetBranch("gen_neu_id");
  if (gen_neu_id_branch) gen_neu_id_branch->SetAddress(&gen_neu_id_);
  dphi_met_J_branch = tree->GetBranch("dphi_met_J");
  if (dphi_met_J_branch) dphi_met_J_branch->SetAddress(&dphi_met_J_);
  dr_L_QQ_branch = tree->GetBranch("dr_L_QQ");
  if (dr_L_QQ_branch) dr_L_QQ_branch->SetAddress(&dr_L_QQ_);
  dr_L_QQp_branch = tree->GetBranch("dr_L_QQp");
  if (dr_L_QQp_branch) dr_L_QQp_branch->SetAddress(&dr_L_QQp_);
  is_whad_lead_branch = tree->GetBranch("is_whad_lead");
  if (is_whad_lead_branch) is_whad_lead_branch->SetAddress(&is_whad_lead_);
  J_area_branch = tree->GetBranch("J_area");
  if (J_area_branch) J_area_branch->SetAddress(&J_area_);
  J_mass_branch = tree->GetBranch("J_mass");
  if (J_mass_branch) J_mass_branch->SetAddress(&J_mass_);
  J_softdropMass_branch = tree->GetBranch("J_softdropMass");
  if (J_softdropMass_branch) J_softdropMass_branch->SetAddress(&J_softdropMass_);
  J_nJettinessTau1_branch = tree->GetBranch("J_nJettinessTau1");
  if (J_nJettinessTau1_branch) J_nJettinessTau1_branch->SetAddress(&J_nJettinessTau1_);
  J_nJettinessTau2_branch = tree->GetBranch("J_nJettinessTau2");
  if (J_nJettinessTau2_branch) J_nJettinessTau2_branch->SetAddress(&J_nJettinessTau2_);
  J_nJettinessTau3_branch = tree->GetBranch("J_nJettinessTau3");
  if (J_nJettinessTau3_branch) J_nJettinessTau3_branch->SetAddress(&J_nJettinessTau3_);
  J_deep_rawdisc_h4q_branch = tree->GetBranch("J_deep_rawdisc_h4q");
  if (J_deep_rawdisc_h4q_branch) J_deep_rawdisc_h4q_branch->SetAddress(&J_deep_rawdisc_h4q_);
  J_deep_rawdisc_hbb_branch = tree->GetBranch("J_deep_rawdisc_hbb");
  if (J_deep_rawdisc_hbb_branch) J_deep_rawdisc_hbb_branch->SetAddress(&J_deep_rawdisc_hbb_);
  J_deep_rawdisc_qcd_branch = tree->GetBranch("J_deep_rawdisc_qcd");
  if (J_deep_rawdisc_qcd_branch) J_deep_rawdisc_qcd_branch->SetAddress(&J_deep_rawdisc_qcd_);
  J_deep_rawdisc_top_branch = tree->GetBranch("J_deep_rawdisc_top");
  if (J_deep_rawdisc_top_branch) J_deep_rawdisc_top_branch->SetAddress(&J_deep_rawdisc_top_);
  J_deep_rawdisc_w_branch = tree->GetBranch("J_deep_rawdisc_w");
  if (J_deep_rawdisc_w_branch) J_deep_rawdisc_w_branch->SetAddress(&J_deep_rawdisc_w_);
  J_deep_rawdisc_z_branch = tree->GetBranch("J_deep_rawdisc_z");
  if (J_deep_rawdisc_z_branch) J_deep_rawdisc_z_branch->SetAddress(&J_deep_rawdisc_z_);
  J_deep_rawdisc_zbb_branch = tree->GetBranch("J_deep_rawdisc_zbb");
  if (J_deep_rawdisc_zbb_branch) J_deep_rawdisc_zbb_branch->SetAddress(&J_deep_rawdisc_zbb_);
  J_softdropPuppiSubjet1_pt_branch = tree->GetBranch("J_softdropPuppiSubjet1_pt");
  if (J_softdropPuppiSubjet1_pt_branch) J_softdropPuppiSubjet1_pt_branch->SetAddress(&J_softdropPuppiSubjet1_pt_);
  J_softdropPuppiSubjet1_eta_branch = tree->GetBranch("J_softdropPuppiSubjet1_eta");
  if (J_softdropPuppiSubjet1_eta_branch) J_softdropPuppiSubjet1_eta_branch->SetAddress(&J_softdropPuppiSubjet1_eta_);
  J_softdropPuppiSubjet1_phi_branch = tree->GetBranch("J_softdropPuppiSubjet1_phi");
  if (J_softdropPuppiSubjet1_phi_branch) J_softdropPuppiSubjet1_phi_branch->SetAddress(&J_softdropPuppiSubjet1_phi_);
  J_softdropPuppiSubjet1_mass_branch = tree->GetBranch("J_softdropPuppiSubjet1_mass");
  if (J_softdropPuppiSubjet1_mass_branch) J_softdropPuppiSubjet1_mass_branch->SetAddress(&J_softdropPuppiSubjet1_mass_);
  J_softdropPuppiSubjet1_energy_branch = tree->GetBranch("J_softdropPuppiSubjet1_energy");
  if (J_softdropPuppiSubjet1_energy_branch) J_softdropPuppiSubjet1_energy_branch->SetAddress(&J_softdropPuppiSubjet1_energy_);
  J_softdropPuppiSubjet2_pt_branch = tree->GetBranch("J_softdropPuppiSubjet2_pt");
  if (J_softdropPuppiSubjet2_pt_branch) J_softdropPuppiSubjet2_pt_branch->SetAddress(&J_softdropPuppiSubjet2_pt_);
  J_softdropPuppiSubjet2_eta_branch = tree->GetBranch("J_softdropPuppiSubjet2_eta");
  if (J_softdropPuppiSubjet2_eta_branch) J_softdropPuppiSubjet2_eta_branch->SetAddress(&J_softdropPuppiSubjet2_eta_);
  J_softdropPuppiSubjet2_phi_branch = tree->GetBranch("J_softdropPuppiSubjet2_phi");
  if (J_softdropPuppiSubjet2_phi_branch) J_softdropPuppiSubjet2_phi_branch->SetAddress(&J_softdropPuppiSubjet2_phi_);
  J_softdropPuppiSubjet2_mass_branch = tree->GetBranch("J_softdropPuppiSubjet2_mass");
  if (J_softdropPuppiSubjet2_mass_branch) J_softdropPuppiSubjet2_mass_branch->SetAddress(&J_softdropPuppiSubjet2_mass_);
  J_softdropPuppiSubjet2_energy_branch = tree->GetBranch("J_softdropPuppiSubjet2_energy");
  if (J_softdropPuppiSubjet2_energy_branch) J_softdropPuppiSubjet2_energy_branch->SetAddress(&J_softdropPuppiSubjet2_energy_);
  J_npfcands_branch = tree->GetBranch("J_npfcands");
  if (J_npfcands_branch) J_npfcands_branch->SetAddress(&J_npfcands_);
  J_partonFlavour_branch = tree->GetBranch("J_partonFlavour");
  if (J_partonFlavour_branch) J_partonFlavour_branch->SetAddress(&J_partonFlavour_);
  L_id_branch = tree->GetBranch("L_id");
  if (L_id_branch) L_id_branch->SetAddress(&L_id_);
  L_idx_branch = tree->GetBranch("L_idx");
  if (L_idx_branch) L_idx_branch->SetAddress(&L_idx_);
  L_miniIsoEA_branch = tree->GetBranch("L_miniIsoEA");
  if (L_miniIsoEA_branch) L_miniIsoEA_branch->SetAddress(&L_miniIsoEA_);
  L_relIso03EA_branch = tree->GetBranch("L_relIso03EA");
  if (L_relIso03EA_branch) L_relIso03EA_branch->SetAddress(&L_relIso03EA_);
  L_relIso04DB_branch = tree->GetBranch("L_relIso04DB");
  if (L_relIso04DB_branch) L_relIso04DB_branch->SetAddress(&L_relIso04DB_);
  L_customrelIso005EA_branch = tree->GetBranch("L_customrelIso005EA");
  if (L_customrelIso005EA_branch) L_customrelIso005EA_branch->SetAddress(&L_customrelIso005EA_);
  L_customrelIso01EA_branch = tree->GetBranch("L_customrelIso01EA");
  if (L_customrelIso01EA_branch) L_customrelIso01EA_branch->SetAddress(&L_customrelIso01EA_);
  L_subjet1_dr_branch = tree->GetBranch("L_subjet1_dr");
  if (L_subjet1_dr_branch) L_subjet1_dr_branch->SetAddress(&L_subjet1_dr_);
  L_subjet2_dr_branch = tree->GetBranch("L_subjet2_dr");
  if (L_subjet2_dr_branch) L_subjet2_dr_branch->SetAddress(&L_subjet2_dr_);
  L_subjet1_deg_branch = tree->GetBranch("L_subjet1_deg");
  if (L_subjet1_deg_branch) L_subjet1_deg_branch->SetAddress(&L_subjet1_deg_);
  L_subjet2_deg_branch = tree->GetBranch("L_subjet2_deg");
  if (L_subjet2_deg_branch) L_subjet2_deg_branch->SetAddress(&L_subjet2_deg_);
  Recoil_leadak4_npfcands_branch = tree->GetBranch("Recoil_leadak4_npfcands");
  if (Recoil_leadak4_npfcands_branch) Recoil_leadak4_npfcands_branch->SetAddress(&Recoil_leadak4_npfcands_);
  Recoil_leadak4_chargedHadronMultiplicity_branch = tree->GetBranch("Recoil_leadak4_chargedHadronMultiplicity");
  if (Recoil_leadak4_chargedHadronMultiplicity_branch) Recoil_leadak4_chargedHadronMultiplicity_branch->SetAddress(&Recoil_leadak4_chargedHadronMultiplicity_);
  Recoil_leadak4_chargedMultiplicity_branch = tree->GetBranch("Recoil_leadak4_chargedMultiplicity");
  if (Recoil_leadak4_chargedMultiplicity_branch) Recoil_leadak4_chargedMultiplicity_branch->SetAddress(&Recoil_leadak4_chargedMultiplicity_);
  Recoil_leadak4_electronMultiplicity_branch = tree->GetBranch("Recoil_leadak4_electronMultiplicity");
  if (Recoil_leadak4_electronMultiplicity_branch) Recoil_leadak4_electronMultiplicity_branch->SetAddress(&Recoil_leadak4_electronMultiplicity_);
  Recoil_leadak4_muonMultiplicity_branch = tree->GetBranch("Recoil_leadak4_muonMultiplicity");
  if (Recoil_leadak4_muonMultiplicity_branch) Recoil_leadak4_muonMultiplicity_branch->SetAddress(&Recoil_leadak4_muonMultiplicity_);
  Recoil_leadak4_neutralHadronMultiplicity_branch = tree->GetBranch("Recoil_leadak4_neutralHadronMultiplicity");
  if (Recoil_leadak4_neutralHadronMultiplicity_branch) Recoil_leadak4_neutralHadronMultiplicity_branch->SetAddress(&Recoil_leadak4_neutralHadronMultiplicity_);
  Recoil_leadak4_neutralMultiplicity_branch = tree->GetBranch("Recoil_leadak4_neutralMultiplicity");
  if (Recoil_leadak4_neutralMultiplicity_branch) Recoil_leadak4_neutralMultiplicity_branch->SetAddress(&Recoil_leadak4_neutralMultiplicity_);
  Recoil_leadak4_photonMultiplicity_branch = tree->GetBranch("Recoil_leadak4_photonMultiplicity");
  if (Recoil_leadak4_photonMultiplicity_branch) Recoil_leadak4_photonMultiplicity_branch->SetAddress(&Recoil_leadak4_photonMultiplicity_);
  Recoil_leadak4_totalMultiplicity_branch = tree->GetBranch("Recoil_leadak4_totalMultiplicity");
  if (Recoil_leadak4_totalMultiplicity_branch) Recoil_leadak4_totalMultiplicity_branch->SetAddress(&Recoil_leadak4_totalMultiplicity_);
  Recoil_leadak4_puppi_chargedHadronMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_chargedHadronMultiplicity");
  if (Recoil_leadak4_puppi_chargedHadronMultiplicity_branch) Recoil_leadak4_puppi_chargedHadronMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_chargedHadronMultiplicity_);
  Recoil_leadak4_puppi_chargedMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_chargedMultiplicity");
  if (Recoil_leadak4_puppi_chargedMultiplicity_branch) Recoil_leadak4_puppi_chargedMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_chargedMultiplicity_);
  Recoil_leadak4_puppi_electronMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_electronMultiplicity");
  if (Recoil_leadak4_puppi_electronMultiplicity_branch) Recoil_leadak4_puppi_electronMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_electronMultiplicity_);
  Recoil_leadak4_puppi_muonMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_muonMultiplicity");
  if (Recoil_leadak4_puppi_muonMultiplicity_branch) Recoil_leadak4_puppi_muonMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_muonMultiplicity_);
  Recoil_leadak4_puppi_neutralHadronMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_neutralHadronMultiplicity");
  if (Recoil_leadak4_puppi_neutralHadronMultiplicity_branch) Recoil_leadak4_puppi_neutralHadronMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_neutralHadronMultiplicity_);
  Recoil_leadak4_puppi_neutralMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_neutralMultiplicity");
  if (Recoil_leadak4_puppi_neutralMultiplicity_branch) Recoil_leadak4_puppi_neutralMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_neutralMultiplicity_);
  Recoil_leadak4_puppi_photonMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_photonMultiplicity");
  if (Recoil_leadak4_puppi_photonMultiplicity_branch) Recoil_leadak4_puppi_photonMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_photonMultiplicity_);
  Recoil_leadak4_puppi_totalMultiplicity_branch = tree->GetBranch("Recoil_leadak4_puppi_totalMultiplicity");
  if (Recoil_leadak4_puppi_totalMultiplicity_branch) Recoil_leadak4_puppi_totalMultiplicity_branch->SetAddress(&Recoil_leadak4_puppi_totalMultiplicity_);
  Recoil_allj_1_4_leadak4_npfcands_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_npfcands");
  if (Recoil_allj_1_4_leadak4_npfcands_branch) Recoil_allj_1_4_leadak4_npfcands_branch->SetAddress(&Recoil_allj_1_4_leadak4_npfcands_);
  Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_chargedHadronMultiplicity");
  if (Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch) Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_);
  Recoil_allj_1_4_leadak4_chargedMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_chargedMultiplicity");
  if (Recoil_allj_1_4_leadak4_chargedMultiplicity_branch) Recoil_allj_1_4_leadak4_chargedMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_chargedMultiplicity_);
  Recoil_allj_1_4_leadak4_electronMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_electronMultiplicity");
  if (Recoil_allj_1_4_leadak4_electronMultiplicity_branch) Recoil_allj_1_4_leadak4_electronMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_electronMultiplicity_);
  Recoil_allj_1_4_leadak4_muonMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_muonMultiplicity");
  if (Recoil_allj_1_4_leadak4_muonMultiplicity_branch) Recoil_allj_1_4_leadak4_muonMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_muonMultiplicity_);
  Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_neutralHadronMultiplicity");
  if (Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch) Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_);
  Recoil_allj_1_4_leadak4_neutralMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_neutralMultiplicity");
  if (Recoil_allj_1_4_leadak4_neutralMultiplicity_branch) Recoil_allj_1_4_leadak4_neutralMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_neutralMultiplicity_);
  Recoil_allj_1_4_leadak4_photonMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_photonMultiplicity");
  if (Recoil_allj_1_4_leadak4_photonMultiplicity_branch) Recoil_allj_1_4_leadak4_photonMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_photonMultiplicity_);
  Recoil_allj_1_4_leadak4_totalMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_totalMultiplicity");
  if (Recoil_allj_1_4_leadak4_totalMultiplicity_branch) Recoil_allj_1_4_leadak4_totalMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_totalMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_electronMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_muonMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_photonMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_);
  Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch = tree->GetBranch("Recoil_allj_1_4_leadak4_puppi_totalMultiplicity");
  if (Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch) Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch->SetAddress(&Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_);
  Recoil_j_3_4_leadak4_npfcands_branch = tree->GetBranch("Recoil_j_3_4_leadak4_npfcands");
  if (Recoil_j_3_4_leadak4_npfcands_branch) Recoil_j_3_4_leadak4_npfcands_branch->SetAddress(&Recoil_j_3_4_leadak4_npfcands_);
  Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_chargedHadronMultiplicity");
  if (Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch) Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_chargedHadronMultiplicity_);
  Recoil_j_3_4_leadak4_chargedMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_chargedMultiplicity");
  if (Recoil_j_3_4_leadak4_chargedMultiplicity_branch) Recoil_j_3_4_leadak4_chargedMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_chargedMultiplicity_);
  Recoil_j_3_4_leadak4_electronMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_electronMultiplicity");
  if (Recoil_j_3_4_leadak4_electronMultiplicity_branch) Recoil_j_3_4_leadak4_electronMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_electronMultiplicity_);
  Recoil_j_3_4_leadak4_muonMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_muonMultiplicity");
  if (Recoil_j_3_4_leadak4_muonMultiplicity_branch) Recoil_j_3_4_leadak4_muonMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_muonMultiplicity_);
  Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_neutralHadronMultiplicity");
  if (Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch) Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_neutralHadronMultiplicity_);
  Recoil_j_3_4_leadak4_neutralMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_neutralMultiplicity");
  if (Recoil_j_3_4_leadak4_neutralMultiplicity_branch) Recoil_j_3_4_leadak4_neutralMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_neutralMultiplicity_);
  Recoil_j_3_4_leadak4_photonMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_photonMultiplicity");
  if (Recoil_j_3_4_leadak4_photonMultiplicity_branch) Recoil_j_3_4_leadak4_photonMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_photonMultiplicity_);
  Recoil_j_3_4_leadak4_totalMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_totalMultiplicity");
  if (Recoil_j_3_4_leadak4_totalMultiplicity_branch) Recoil_j_3_4_leadak4_totalMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_totalMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_chargedMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_electronMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_electronMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_muonMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_muonMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_neutralMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_photonMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_photonMultiplicity_);
  Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch = tree->GetBranch("Recoil_j_3_4_leadak4_puppi_totalMultiplicity");
  if (Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch) Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch->SetAddress(&Recoil_j_3_4_leadak4_puppi_totalMultiplicity_);

  tree->SetMakeClass(0);
}

void hwwtree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  run_isLoaded = false;
  lumi_isLoaded = false;
  evt_isLoaded = false;
  isData_isLoaded = false;
  evt_scale1fb_isLoaded = false;
  genps_weight_isLoaded = false;
  xsec_br_isLoaded = false;
  evt_passgoodrunlist_isLoaded = false;
  CMS4path_isLoaded = false;
  CMS4index_isLoaded = false;
  weight_fr_r1_f1_isLoaded = false;
  weight_fr_r1_f2_isLoaded = false;
  weight_fr_r1_f0p5_isLoaded = false;
  weight_fr_r2_f1_isLoaded = false;
  weight_fr_r2_f2_isLoaded = false;
  weight_fr_r2_f0p5_isLoaded = false;
  weight_fr_r0p5_f1_isLoaded = false;
  weight_fr_r0p5_f2_isLoaded = false;
  weight_fr_r0p5_f0p5_isLoaded = false;
  weight_pdf_up_isLoaded = false;
  weight_pdf_down_isLoaded = false;
  weight_alphas_down_isLoaded = false;
  weight_alphas_up_isLoaded = false;
  nrecolep_isLoaded = false;
  lep_p4_isLoaded = false;
  nak8jets_isLoaded = false;
  ak8jets_p4_isLoaded = false;
  nj_isLoaded = false;
  nb_isLoaded = false;
  nbmed_isLoaded = false;
  nbtight_isLoaded = false;
  jets_p4_isLoaded = false;
  alljets_p4_isLoaded = false;
  jets_idx_isLoaded = false;
  alljets_idx_isLoaded = false;
  met_pt_isLoaded = false;
  met_phi_isLoaded = false;
  met_up_pt_isLoaded = false;
  met_up_phi_isLoaded = false;
  met_dn_pt_isLoaded = false;
  met_dn_phi_isLoaded = false;
  met_gen_pt_isLoaded = false;
  met_gen_phi_isLoaded = false;
  HLT_Ele27_WPLoose_Gsf_isLoaded = false;
  HLT_Ele30_WPLoose_Gsf_isLoaded = false;
  HLT_Ele45_WPLoose_Gsf_isLoaded = false;
  HLT_Ele105_CaloIdVT_GsfTrkIdT_isLoaded = false;
  HLT_Ele115_CaloIdVT_GsfTrkIdT_isLoaded = false;
  HLT_IsoTkMu24_isLoaded = false;
  HLT_IsoMu24_isLoaded = false;
  HLT_SingleMu50_isLoaded = false;
  HLT_SingleEl40_isLoaded = false;
  HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_isLoaded = false;
  HLT_Mu50_isLoaded = false;
  HLT_TkMu50_isLoaded = false;
  HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded = false;
  HLT_AK8PFJet360_TrimMass30_isLoaded = false;
  HLT_PFHT800_isLoaded = false;
  HLT_PFHT900_isLoaded = false;
  HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded = false;
  HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded = false;
  HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_isLoaded = false;
  pass_duplicate_se_sm_isLoaded = false;
  pass_duplicate_sm_se_isLoaded = false;
  gen_recoil_p4_isLoaded = false;
  gen_recoil_id_isLoaded = false;
  gen_higgs_p4_isLoaded = false;
  gen_whad_p4_isLoaded = false;
  gen_wlep_p4_isLoaded = false;
  gen_q0_p4_isLoaded = false;
  gen_q1_p4_isLoaded = false;
  gen_lep_p4_isLoaded = false;
  gen_neu_p4_isLoaded = false;
  gen_channel_isLoaded = false;
  gen_wlep_rest_p4_isLoaded = false;
  gen_whad_rest_p4_isLoaded = false;
  gen_Vq0_p4_isLoaded = false;
  gen_Vq1_p4_isLoaded = false;
  gen_Vq0_id_isLoaded = false;
  gen_Vq1_id_isLoaded = false;
  gen_q0_id_isLoaded = false;
  gen_q1_id_isLoaded = false;
  gen_lep_id_isLoaded = false;
  gen_neu_id_isLoaded = false;
  J_p4_isLoaded = false;
  dphi_met_J_isLoaded = false;
  Jmet_p4_isLoaded = false;
  L_p4_isLoaded = false;
  Lmet_p4_isLoaded = false;
  QQ_p4_isLoaded = false;
  dr_L_QQ_isLoaded = false;
  QQp_p4_isLoaded = false;
  dr_L_QQp_isLoaded = false;
  LQQ_p4_isLoaded = false;
  LQQp_p4_isLoaded = false;
  H_p4_isLoaded = false;
  Hp_p4_isLoaded = false;
  is_whad_lead_isLoaded = false;
  v_p4_isLoaded = false;
  J_area_isLoaded = false;
  J_mass_isLoaded = false;
  J_softdropMass_isLoaded = false;
  J_nJettinessTau1_isLoaded = false;
  J_nJettinessTau2_isLoaded = false;
  J_nJettinessTau3_isLoaded = false;
  J_deep_rawdisc_h4q_isLoaded = false;
  J_deep_rawdisc_hbb_isLoaded = false;
  J_deep_rawdisc_qcd_isLoaded = false;
  J_deep_rawdisc_top_isLoaded = false;
  J_deep_rawdisc_w_isLoaded = false;
  J_deep_rawdisc_z_isLoaded = false;
  J_deep_rawdisc_zbb_isLoaded = false;
  J_softdropPuppiSubjet1_pt_isLoaded = false;
  J_softdropPuppiSubjet1_eta_isLoaded = false;
  J_softdropPuppiSubjet1_phi_isLoaded = false;
  J_softdropPuppiSubjet1_mass_isLoaded = false;
  J_softdropPuppiSubjet1_energy_isLoaded = false;
  J_softdropPuppiSubjet2_pt_isLoaded = false;
  J_softdropPuppiSubjet2_eta_isLoaded = false;
  J_softdropPuppiSubjet2_phi_isLoaded = false;
  J_softdropPuppiSubjet2_mass_isLoaded = false;
  J_softdropPuppiSubjet2_energy_isLoaded = false;
  J_npfcands_isLoaded = false;
  J_partonFlavour_isLoaded = false;
  L_id_isLoaded = false;
  L_idx_isLoaded = false;
  L_miniIsoEA_isLoaded = false;
  L_relIso03EA_isLoaded = false;
  L_relIso04DB_isLoaded = false;
  L_customrelIso005EA_isLoaded = false;
  L_customrelIso01EA_isLoaded = false;
  J_near_ak4jets_p4_isLoaded = false;
  L_subjet1_p4_isLoaded = false;
  L_subjet2_p4_isLoaded = false;
  L_subjet1_dr_isLoaded = false;
  L_subjet2_dr_isLoaded = false;
  L_subjet1_deg_isLoaded = false;
  L_subjet2_deg_isLoaded = false;
  Recoil_p4_isLoaded = false;
  Recoil_leadak4_p4_isLoaded = false;
  Recoil_leadak4_npfcands_isLoaded = false;
  Recoil_leadak4_chargedHadronMultiplicity_isLoaded = false;
  Recoil_leadak4_chargedMultiplicity_isLoaded = false;
  Recoil_leadak4_electronMultiplicity_isLoaded = false;
  Recoil_leadak4_muonMultiplicity_isLoaded = false;
  Recoil_leadak4_neutralHadronMultiplicity_isLoaded = false;
  Recoil_leadak4_neutralMultiplicity_isLoaded = false;
  Recoil_leadak4_photonMultiplicity_isLoaded = false;
  Recoil_leadak4_totalMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_chargedHadronMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_chargedMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_electronMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_muonMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_neutralHadronMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_neutralMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_photonMultiplicity_isLoaded = false;
  Recoil_leadak4_puppi_totalMultiplicity_isLoaded = false;
  Recoil_allj_1_4_p4_isLoaded = false;
  Recoil_allj_1_4_leadak4_p4_isLoaded = false;
  Recoil_allj_1_4_leadak4_npfcands_isLoaded = false;
  Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_chargedMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_electronMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_muonMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_neutralMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_photonMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_totalMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_isLoaded = false;
  Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_isLoaded = false;
  Recoil_j_3_4_p4_isLoaded = false;
  Recoil_j_3_4_leadak4_p4_isLoaded = false;
  Recoil_j_3_4_leadak4_npfcands_isLoaded = false;
  Recoil_j_3_4_leadak4_chargedHadronMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_chargedMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_electronMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_muonMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_neutralHadronMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_neutralMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_photonMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_totalMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_electronMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_muonMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_photonMultiplicity_isLoaded = false;
  Recoil_j_3_4_leadak4_puppi_totalMultiplicity_isLoaded = false;
}

void hwwtree::LoadAllBranches() {
  // load all branches
  if (run_branch != 0) run();
  if (lumi_branch != 0) lumi();
  if (evt_branch != 0) evt();
  if (isData_branch != 0) isData();
  if (evt_scale1fb_branch != 0) evt_scale1fb();
  if (genps_weight_branch != 0) genps_weight();
  if (xsec_br_branch != 0) xsec_br();
  if (evt_passgoodrunlist_branch != 0) evt_passgoodrunlist();
  if (CMS4path_branch != 0) CMS4path();
  if (CMS4index_branch != 0) CMS4index();
  if (weight_fr_r1_f1_branch != 0) weight_fr_r1_f1();
  if (weight_fr_r1_f2_branch != 0) weight_fr_r1_f2();
  if (weight_fr_r1_f0p5_branch != 0) weight_fr_r1_f0p5();
  if (weight_fr_r2_f1_branch != 0) weight_fr_r2_f1();
  if (weight_fr_r2_f2_branch != 0) weight_fr_r2_f2();
  if (weight_fr_r2_f0p5_branch != 0) weight_fr_r2_f0p5();
  if (weight_fr_r0p5_f1_branch != 0) weight_fr_r0p5_f1();
  if (weight_fr_r0p5_f2_branch != 0) weight_fr_r0p5_f2();
  if (weight_fr_r0p5_f0p5_branch != 0) weight_fr_r0p5_f0p5();
  if (weight_pdf_up_branch != 0) weight_pdf_up();
  if (weight_pdf_down_branch != 0) weight_pdf_down();
  if (weight_alphas_down_branch != 0) weight_alphas_down();
  if (weight_alphas_up_branch != 0) weight_alphas_up();
  if (nrecolep_branch != 0) nrecolep();
  if (lep_p4_branch != 0) lep_p4();
  if (nak8jets_branch != 0) nak8jets();
  if (ak8jets_p4_branch != 0) ak8jets_p4();
  if (nj_branch != 0) nj();
  if (nb_branch != 0) nb();
  if (nbmed_branch != 0) nbmed();
  if (nbtight_branch != 0) nbtight();
  if (jets_p4_branch != 0) jets_p4();
  if (alljets_p4_branch != 0) alljets_p4();
  if (jets_idx_branch != 0) jets_idx();
  if (alljets_idx_branch != 0) alljets_idx();
  if (met_pt_branch != 0) met_pt();
  if (met_phi_branch != 0) met_phi();
  if (met_up_pt_branch != 0) met_up_pt();
  if (met_up_phi_branch != 0) met_up_phi();
  if (met_dn_pt_branch != 0) met_dn_pt();
  if (met_dn_phi_branch != 0) met_dn_phi();
  if (met_gen_pt_branch != 0) met_gen_pt();
  if (met_gen_phi_branch != 0) met_gen_phi();
  if (HLT_Ele27_WPLoose_Gsf_branch != 0) HLT_Ele27_WPLoose_Gsf();
  if (HLT_Ele30_WPLoose_Gsf_branch != 0) HLT_Ele30_WPLoose_Gsf();
  if (HLT_Ele45_WPLoose_Gsf_branch != 0) HLT_Ele45_WPLoose_Gsf();
  if (HLT_Ele105_CaloIdVT_GsfTrkIdT_branch != 0) HLT_Ele105_CaloIdVT_GsfTrkIdT();
  if (HLT_Ele115_CaloIdVT_GsfTrkIdT_branch != 0) HLT_Ele115_CaloIdVT_GsfTrkIdT();
  if (HLT_IsoTkMu24_branch != 0) HLT_IsoTkMu24();
  if (HLT_IsoMu24_branch != 0) HLT_IsoMu24();
  if (HLT_SingleMu50_branch != 0) HLT_SingleMu50();
  if (HLT_SingleEl40_branch != 0) HLT_SingleEl40();
  if (HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch != 0) HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165();
  if (HLT_Mu50_branch != 0) HLT_Mu50();
  if (HLT_TkMu50_branch != 0) HLT_TkMu50();
  if (HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch != 0) HLT_AK8PFHT700_TrimR0p1PT0p03Mass50();
  if (HLT_AK8PFJet360_TrimMass30_branch != 0) HLT_AK8PFJet360_TrimMass30();
  if (HLT_PFHT800_branch != 0) HLT_PFHT800();
  if (HLT_PFHT900_branch != 0) HLT_PFHT900();
  if (HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch != 0) HLT_PFHT650_WideJetMJJ900DEtaJJ1p5();
  if (HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch != 0) HLT_PFHT650_WideJetMJJ950DEtaJJ1p5();
  if (HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch != 0) HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20();
  if (pass_duplicate_se_sm_branch != 0) pass_duplicate_se_sm();
  if (pass_duplicate_sm_se_branch != 0) pass_duplicate_sm_se();
  if (gen_recoil_p4_branch != 0) gen_recoil_p4();
  if (gen_recoil_id_branch != 0) gen_recoil_id();
  if (gen_higgs_p4_branch != 0) gen_higgs_p4();
  if (gen_whad_p4_branch != 0) gen_whad_p4();
  if (gen_wlep_p4_branch != 0) gen_wlep_p4();
  if (gen_q0_p4_branch != 0) gen_q0_p4();
  if (gen_q1_p4_branch != 0) gen_q1_p4();
  if (gen_lep_p4_branch != 0) gen_lep_p4();
  if (gen_neu_p4_branch != 0) gen_neu_p4();
  if (gen_channel_branch != 0) gen_channel();
  if (gen_wlep_rest_p4_branch != 0) gen_wlep_rest_p4();
  if (gen_whad_rest_p4_branch != 0) gen_whad_rest_p4();
  if (gen_Vq0_p4_branch != 0) gen_Vq0_p4();
  if (gen_Vq1_p4_branch != 0) gen_Vq1_p4();
  if (gen_Vq0_id_branch != 0) gen_Vq0_id();
  if (gen_Vq1_id_branch != 0) gen_Vq1_id();
  if (gen_q0_id_branch != 0) gen_q0_id();
  if (gen_q1_id_branch != 0) gen_q1_id();
  if (gen_lep_id_branch != 0) gen_lep_id();
  if (gen_neu_id_branch != 0) gen_neu_id();
  if (J_p4_branch != 0) J_p4();
  if (dphi_met_J_branch != 0) dphi_met_J();
  if (Jmet_p4_branch != 0) Jmet_p4();
  if (L_p4_branch != 0) L_p4();
  if (Lmet_p4_branch != 0) Lmet_p4();
  if (QQ_p4_branch != 0) QQ_p4();
  if (dr_L_QQ_branch != 0) dr_L_QQ();
  if (QQp_p4_branch != 0) QQp_p4();
  if (dr_L_QQp_branch != 0) dr_L_QQp();
  if (LQQ_p4_branch != 0) LQQ_p4();
  if (LQQp_p4_branch != 0) LQQp_p4();
  if (H_p4_branch != 0) H_p4();
  if (Hp_p4_branch != 0) Hp_p4();
  if (is_whad_lead_branch != 0) is_whad_lead();
  if (v_p4_branch != 0) v_p4();
  if (J_area_branch != 0) J_area();
  if (J_mass_branch != 0) J_mass();
  if (J_softdropMass_branch != 0) J_softdropMass();
  if (J_nJettinessTau1_branch != 0) J_nJettinessTau1();
  if (J_nJettinessTau2_branch != 0) J_nJettinessTau2();
  if (J_nJettinessTau3_branch != 0) J_nJettinessTau3();
  if (J_deep_rawdisc_h4q_branch != 0) J_deep_rawdisc_h4q();
  if (J_deep_rawdisc_hbb_branch != 0) J_deep_rawdisc_hbb();
  if (J_deep_rawdisc_qcd_branch != 0) J_deep_rawdisc_qcd();
  if (J_deep_rawdisc_top_branch != 0) J_deep_rawdisc_top();
  if (J_deep_rawdisc_w_branch != 0) J_deep_rawdisc_w();
  if (J_deep_rawdisc_z_branch != 0) J_deep_rawdisc_z();
  if (J_deep_rawdisc_zbb_branch != 0) J_deep_rawdisc_zbb();
  if (J_softdropPuppiSubjet1_pt_branch != 0) J_softdropPuppiSubjet1_pt();
  if (J_softdropPuppiSubjet1_eta_branch != 0) J_softdropPuppiSubjet1_eta();
  if (J_softdropPuppiSubjet1_phi_branch != 0) J_softdropPuppiSubjet1_phi();
  if (J_softdropPuppiSubjet1_mass_branch != 0) J_softdropPuppiSubjet1_mass();
  if (J_softdropPuppiSubjet1_energy_branch != 0) J_softdropPuppiSubjet1_energy();
  if (J_softdropPuppiSubjet2_pt_branch != 0) J_softdropPuppiSubjet2_pt();
  if (J_softdropPuppiSubjet2_eta_branch != 0) J_softdropPuppiSubjet2_eta();
  if (J_softdropPuppiSubjet2_phi_branch != 0) J_softdropPuppiSubjet2_phi();
  if (J_softdropPuppiSubjet2_mass_branch != 0) J_softdropPuppiSubjet2_mass();
  if (J_softdropPuppiSubjet2_energy_branch != 0) J_softdropPuppiSubjet2_energy();
  if (J_npfcands_branch != 0) J_npfcands();
  if (J_partonFlavour_branch != 0) J_partonFlavour();
  if (L_id_branch != 0) L_id();
  if (L_idx_branch != 0) L_idx();
  if (L_miniIsoEA_branch != 0) L_miniIsoEA();
  if (L_relIso03EA_branch != 0) L_relIso03EA();
  if (L_relIso04DB_branch != 0) L_relIso04DB();
  if (L_customrelIso005EA_branch != 0) L_customrelIso005EA();
  if (L_customrelIso01EA_branch != 0) L_customrelIso01EA();
  if (J_near_ak4jets_p4_branch != 0) J_near_ak4jets_p4();
  if (L_subjet1_p4_branch != 0) L_subjet1_p4();
  if (L_subjet2_p4_branch != 0) L_subjet2_p4();
  if (L_subjet1_dr_branch != 0) L_subjet1_dr();
  if (L_subjet2_dr_branch != 0) L_subjet2_dr();
  if (L_subjet1_deg_branch != 0) L_subjet1_deg();
  if (L_subjet2_deg_branch != 0) L_subjet2_deg();
  if (Recoil_p4_branch != 0) Recoil_p4();
  if (Recoil_leadak4_p4_branch != 0) Recoil_leadak4_p4();
  if (Recoil_leadak4_npfcands_branch != 0) Recoil_leadak4_npfcands();
  if (Recoil_leadak4_chargedHadronMultiplicity_branch != 0) Recoil_leadak4_chargedHadronMultiplicity();
  if (Recoil_leadak4_chargedMultiplicity_branch != 0) Recoil_leadak4_chargedMultiplicity();
  if (Recoil_leadak4_electronMultiplicity_branch != 0) Recoil_leadak4_electronMultiplicity();
  if (Recoil_leadak4_muonMultiplicity_branch != 0) Recoil_leadak4_muonMultiplicity();
  if (Recoil_leadak4_neutralHadronMultiplicity_branch != 0) Recoil_leadak4_neutralHadronMultiplicity();
  if (Recoil_leadak4_neutralMultiplicity_branch != 0) Recoil_leadak4_neutralMultiplicity();
  if (Recoil_leadak4_photonMultiplicity_branch != 0) Recoil_leadak4_photonMultiplicity();
  if (Recoil_leadak4_totalMultiplicity_branch != 0) Recoil_leadak4_totalMultiplicity();
  if (Recoil_leadak4_puppi_chargedHadronMultiplicity_branch != 0) Recoil_leadak4_puppi_chargedHadronMultiplicity();
  if (Recoil_leadak4_puppi_chargedMultiplicity_branch != 0) Recoil_leadak4_puppi_chargedMultiplicity();
  if (Recoil_leadak4_puppi_electronMultiplicity_branch != 0) Recoil_leadak4_puppi_electronMultiplicity();
  if (Recoil_leadak4_puppi_muonMultiplicity_branch != 0) Recoil_leadak4_puppi_muonMultiplicity();
  if (Recoil_leadak4_puppi_neutralHadronMultiplicity_branch != 0) Recoil_leadak4_puppi_neutralHadronMultiplicity();
  if (Recoil_leadak4_puppi_neutralMultiplicity_branch != 0) Recoil_leadak4_puppi_neutralMultiplicity();
  if (Recoil_leadak4_puppi_photonMultiplicity_branch != 0) Recoil_leadak4_puppi_photonMultiplicity();
  if (Recoil_leadak4_puppi_totalMultiplicity_branch != 0) Recoil_leadak4_puppi_totalMultiplicity();
  if (Recoil_allj_1_4_p4_branch != 0) Recoil_allj_1_4_p4();
  if (Recoil_allj_1_4_leadak4_p4_branch != 0) Recoil_allj_1_4_leadak4_p4();
  if (Recoil_allj_1_4_leadak4_npfcands_branch != 0) Recoil_allj_1_4_leadak4_npfcands();
  if (Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_chargedHadronMultiplicity();
  if (Recoil_allj_1_4_leadak4_chargedMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_chargedMultiplicity();
  if (Recoil_allj_1_4_leadak4_electronMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_electronMultiplicity();
  if (Recoil_allj_1_4_leadak4_muonMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_muonMultiplicity();
  if (Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_neutralHadronMultiplicity();
  if (Recoil_allj_1_4_leadak4_neutralMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_neutralMultiplicity();
  if (Recoil_allj_1_4_leadak4_photonMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_photonMultiplicity();
  if (Recoil_allj_1_4_leadak4_totalMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_totalMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_electronMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_muonMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_photonMultiplicity();
  if (Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch != 0) Recoil_allj_1_4_leadak4_puppi_totalMultiplicity();
  if (Recoil_j_3_4_p4_branch != 0) Recoil_j_3_4_p4();
  if (Recoil_j_3_4_leadak4_p4_branch != 0) Recoil_j_3_4_leadak4_p4();
  if (Recoil_j_3_4_leadak4_npfcands_branch != 0) Recoil_j_3_4_leadak4_npfcands();
  if (Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch != 0) Recoil_j_3_4_leadak4_chargedHadronMultiplicity();
  if (Recoil_j_3_4_leadak4_chargedMultiplicity_branch != 0) Recoil_j_3_4_leadak4_chargedMultiplicity();
  if (Recoil_j_3_4_leadak4_electronMultiplicity_branch != 0) Recoil_j_3_4_leadak4_electronMultiplicity();
  if (Recoil_j_3_4_leadak4_muonMultiplicity_branch != 0) Recoil_j_3_4_leadak4_muonMultiplicity();
  if (Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch != 0) Recoil_j_3_4_leadak4_neutralHadronMultiplicity();
  if (Recoil_j_3_4_leadak4_neutralMultiplicity_branch != 0) Recoil_j_3_4_leadak4_neutralMultiplicity();
  if (Recoil_j_3_4_leadak4_photonMultiplicity_branch != 0) Recoil_j_3_4_leadak4_photonMultiplicity();
  if (Recoil_j_3_4_leadak4_totalMultiplicity_branch != 0) Recoil_j_3_4_leadak4_totalMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_chargedMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_electronMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_muonMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_neutralMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_photonMultiplicity();
  if (Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch != 0) Recoil_j_3_4_leadak4_puppi_totalMultiplicity();
}

const int &hwwtree::run() {
  if (not run_isLoaded) {
    if (run_branch != 0) {
      run_branch->GetEntry(index);
    } else {
      printf("branch run_branch does not exist!\n");
      exit(1);
    }
    run_isLoaded = true;
  }
  return run_;
}

const int &hwwtree::lumi() {
  if (not lumi_isLoaded) {
    if (lumi_branch != 0) {
      lumi_branch->GetEntry(index);
    } else {
      printf("branch lumi_branch does not exist!\n");
      exit(1);
    }
    lumi_isLoaded = true;
  }
  return lumi_;
}

const unsigned long long &hwwtree::evt() {
  if (not evt_isLoaded) {
    if (evt_branch != 0) {
      evt_branch->GetEntry(index);
    } else {
      printf("branch evt_branch does not exist!\n");
      exit(1);
    }
    evt_isLoaded = true;
  }
  return evt_;
}

const int &hwwtree::isData() {
  if (not isData_isLoaded) {
    if (isData_branch != 0) {
      isData_branch->GetEntry(index);
    } else {
      printf("branch isData_branch does not exist!\n");
      exit(1);
    }
    isData_isLoaded = true;
  }
  return isData_;
}

const float &hwwtree::evt_scale1fb() {
  if (not evt_scale1fb_isLoaded) {
    if (evt_scale1fb_branch != 0) {
      evt_scale1fb_branch->GetEntry(index);
    } else {
      printf("branch evt_scale1fb_branch does not exist!\n");
      exit(1);
    }
    evt_scale1fb_isLoaded = true;
  }
  return evt_scale1fb_;
}

const float &hwwtree::genps_weight() {
  if (not genps_weight_isLoaded) {
    if (genps_weight_branch != 0) {
      genps_weight_branch->GetEntry(index);
    } else {
      printf("branch genps_weight_branch does not exist!\n");
      exit(1);
    }
    genps_weight_isLoaded = true;
  }
  return genps_weight_;
}

const float &hwwtree::xsec_br() {
  if (not xsec_br_isLoaded) {
    if (xsec_br_branch != 0) {
      xsec_br_branch->GetEntry(index);
    } else {
      printf("branch xsec_br_branch does not exist!\n");
      exit(1);
    }
    xsec_br_isLoaded = true;
  }
  return xsec_br_;
}

const int &hwwtree::evt_passgoodrunlist() {
  if (not evt_passgoodrunlist_isLoaded) {
    if (evt_passgoodrunlist_branch != 0) {
      evt_passgoodrunlist_branch->GetEntry(index);
    } else {
      printf("branch evt_passgoodrunlist_branch does not exist!\n");
      exit(1);
    }
    evt_passgoodrunlist_isLoaded = true;
  }
  return evt_passgoodrunlist_;
}

const TString &hwwtree::CMS4path() {
  if (not CMS4path_isLoaded) {
    if (CMS4path_branch != 0) {
      CMS4path_branch->GetEntry(index);
    } else {
      printf("branch CMS4path_branch does not exist!\n");
      exit(1);
    }
    CMS4path_isLoaded = true;
  }
  return *CMS4path_;
}

const int &hwwtree::CMS4index() {
  if (not CMS4index_isLoaded) {
    if (CMS4index_branch != 0) {
      CMS4index_branch->GetEntry(index);
    } else {
      printf("branch CMS4index_branch does not exist!\n");
      exit(1);
    }
    CMS4index_isLoaded = true;
  }
  return CMS4index_;
}

const float &hwwtree::weight_fr_r1_f1() {
  if (not weight_fr_r1_f1_isLoaded) {
    if (weight_fr_r1_f1_branch != 0) {
      weight_fr_r1_f1_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r1_f1_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r1_f1_isLoaded = true;
  }
  return weight_fr_r1_f1_;
}

const float &hwwtree::weight_fr_r1_f2() {
  if (not weight_fr_r1_f2_isLoaded) {
    if (weight_fr_r1_f2_branch != 0) {
      weight_fr_r1_f2_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r1_f2_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r1_f2_isLoaded = true;
  }
  return weight_fr_r1_f2_;
}

const float &hwwtree::weight_fr_r1_f0p5() {
  if (not weight_fr_r1_f0p5_isLoaded) {
    if (weight_fr_r1_f0p5_branch != 0) {
      weight_fr_r1_f0p5_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r1_f0p5_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r1_f0p5_isLoaded = true;
  }
  return weight_fr_r1_f0p5_;
}

const float &hwwtree::weight_fr_r2_f1() {
  if (not weight_fr_r2_f1_isLoaded) {
    if (weight_fr_r2_f1_branch != 0) {
      weight_fr_r2_f1_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r2_f1_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r2_f1_isLoaded = true;
  }
  return weight_fr_r2_f1_;
}

const float &hwwtree::weight_fr_r2_f2() {
  if (not weight_fr_r2_f2_isLoaded) {
    if (weight_fr_r2_f2_branch != 0) {
      weight_fr_r2_f2_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r2_f2_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r2_f2_isLoaded = true;
  }
  return weight_fr_r2_f2_;
}

const float &hwwtree::weight_fr_r2_f0p5() {
  if (not weight_fr_r2_f0p5_isLoaded) {
    if (weight_fr_r2_f0p5_branch != 0) {
      weight_fr_r2_f0p5_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r2_f0p5_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r2_f0p5_isLoaded = true;
  }
  return weight_fr_r2_f0p5_;
}

const float &hwwtree::weight_fr_r0p5_f1() {
  if (not weight_fr_r0p5_f1_isLoaded) {
    if (weight_fr_r0p5_f1_branch != 0) {
      weight_fr_r0p5_f1_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r0p5_f1_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r0p5_f1_isLoaded = true;
  }
  return weight_fr_r0p5_f1_;
}

const float &hwwtree::weight_fr_r0p5_f2() {
  if (not weight_fr_r0p5_f2_isLoaded) {
    if (weight_fr_r0p5_f2_branch != 0) {
      weight_fr_r0p5_f2_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r0p5_f2_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r0p5_f2_isLoaded = true;
  }
  return weight_fr_r0p5_f2_;
}

const float &hwwtree::weight_fr_r0p5_f0p5() {
  if (not weight_fr_r0p5_f0p5_isLoaded) {
    if (weight_fr_r0p5_f0p5_branch != 0) {
      weight_fr_r0p5_f0p5_branch->GetEntry(index);
    } else {
      printf("branch weight_fr_r0p5_f0p5_branch does not exist!\n");
      exit(1);
    }
    weight_fr_r0p5_f0p5_isLoaded = true;
  }
  return weight_fr_r0p5_f0p5_;
}

const float &hwwtree::weight_pdf_up() {
  if (not weight_pdf_up_isLoaded) {
    if (weight_pdf_up_branch != 0) {
      weight_pdf_up_branch->GetEntry(index);
    } else {
      printf("branch weight_pdf_up_branch does not exist!\n");
      exit(1);
    }
    weight_pdf_up_isLoaded = true;
  }
  return weight_pdf_up_;
}

const float &hwwtree::weight_pdf_down() {
  if (not weight_pdf_down_isLoaded) {
    if (weight_pdf_down_branch != 0) {
      weight_pdf_down_branch->GetEntry(index);
    } else {
      printf("branch weight_pdf_down_branch does not exist!\n");
      exit(1);
    }
    weight_pdf_down_isLoaded = true;
  }
  return weight_pdf_down_;
}

const float &hwwtree::weight_alphas_down() {
  if (not weight_alphas_down_isLoaded) {
    if (weight_alphas_down_branch != 0) {
      weight_alphas_down_branch->GetEntry(index);
    } else {
      printf("branch weight_alphas_down_branch does not exist!\n");
      exit(1);
    }
    weight_alphas_down_isLoaded = true;
  }
  return weight_alphas_down_;
}

const float &hwwtree::weight_alphas_up() {
  if (not weight_alphas_up_isLoaded) {
    if (weight_alphas_up_branch != 0) {
      weight_alphas_up_branch->GetEntry(index);
    } else {
      printf("branch weight_alphas_up_branch does not exist!\n");
      exit(1);
    }
    weight_alphas_up_isLoaded = true;
  }
  return weight_alphas_up_;
}

const int &hwwtree::nrecolep() {
  if (not nrecolep_isLoaded) {
    if (nrecolep_branch != 0) {
      nrecolep_branch->GetEntry(index);
    } else {
      printf("branch nrecolep_branch does not exist!\n");
      exit(1);
    }
    nrecolep_isLoaded = true;
  }
  return nrecolep_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hwwtree::lep_p4() {
  if (not lep_p4_isLoaded) {
    if (lep_p4_branch != 0) {
      lep_p4_branch->GetEntry(index);
    } else {
      printf("branch lep_p4_branch does not exist!\n");
      exit(1);
    }
    lep_p4_isLoaded = true;
  }
  return *lep_p4_;
}

const int &hwwtree::nak8jets() {
  if (not nak8jets_isLoaded) {
    if (nak8jets_branch != 0) {
      nak8jets_branch->GetEntry(index);
    } else {
      printf("branch nak8jets_branch does not exist!\n");
      exit(1);
    }
    nak8jets_isLoaded = true;
  }
  return nak8jets_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hwwtree::ak8jets_p4() {
  if (not ak8jets_p4_isLoaded) {
    if (ak8jets_p4_branch != 0) {
      ak8jets_p4_branch->GetEntry(index);
    } else {
      printf("branch ak8jets_p4_branch does not exist!\n");
      exit(1);
    }
    ak8jets_p4_isLoaded = true;
  }
  return *ak8jets_p4_;
}

const int &hwwtree::nj() {
  if (not nj_isLoaded) {
    if (nj_branch != 0) {
      nj_branch->GetEntry(index);
    } else {
      printf("branch nj_branch does not exist!\n");
      exit(1);
    }
    nj_isLoaded = true;
  }
  return nj_;
}

const int &hwwtree::nb() {
  if (not nb_isLoaded) {
    if (nb_branch != 0) {
      nb_branch->GetEntry(index);
    } else {
      printf("branch nb_branch does not exist!\n");
      exit(1);
    }
    nb_isLoaded = true;
  }
  return nb_;
}

const int &hwwtree::nbmed() {
  if (not nbmed_isLoaded) {
    if (nbmed_branch != 0) {
      nbmed_branch->GetEntry(index);
    } else {
      printf("branch nbmed_branch does not exist!\n");
      exit(1);
    }
    nbmed_isLoaded = true;
  }
  return nbmed_;
}

const int &hwwtree::nbtight() {
  if (not nbtight_isLoaded) {
    if (nbtight_branch != 0) {
      nbtight_branch->GetEntry(index);
    } else {
      printf("branch nbtight_branch does not exist!\n");
      exit(1);
    }
    nbtight_isLoaded = true;
  }
  return nbtight_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hwwtree::jets_p4() {
  if (not jets_p4_isLoaded) {
    if (jets_p4_branch != 0) {
      jets_p4_branch->GetEntry(index);
    } else {
      printf("branch jets_p4_branch does not exist!\n");
      exit(1);
    }
    jets_p4_isLoaded = true;
  }
  return *jets_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hwwtree::alljets_p4() {
  if (not alljets_p4_isLoaded) {
    if (alljets_p4_branch != 0) {
      alljets_p4_branch->GetEntry(index);
    } else {
      printf("branch alljets_p4_branch does not exist!\n");
      exit(1);
    }
    alljets_p4_isLoaded = true;
  }
  return *alljets_p4_;
}

const vector<int> &hwwtree::jets_idx() {
  if (not jets_idx_isLoaded) {
    if (jets_idx_branch != 0) {
      jets_idx_branch->GetEntry(index);
    } else {
      printf("branch jets_idx_branch does not exist!\n");
      exit(1);
    }
    jets_idx_isLoaded = true;
  }
  return *jets_idx_;
}

const vector<int> &hwwtree::alljets_idx() {
  if (not alljets_idx_isLoaded) {
    if (alljets_idx_branch != 0) {
      alljets_idx_branch->GetEntry(index);
    } else {
      printf("branch alljets_idx_branch does not exist!\n");
      exit(1);
    }
    alljets_idx_isLoaded = true;
  }
  return *alljets_idx_;
}

const float &hwwtree::met_pt() {
  if (not met_pt_isLoaded) {
    if (met_pt_branch != 0) {
      met_pt_branch->GetEntry(index);
    } else {
      printf("branch met_pt_branch does not exist!\n");
      exit(1);
    }
    met_pt_isLoaded = true;
  }
  return met_pt_;
}

const float &hwwtree::met_phi() {
  if (not met_phi_isLoaded) {
    if (met_phi_branch != 0) {
      met_phi_branch->GetEntry(index);
    } else {
      printf("branch met_phi_branch does not exist!\n");
      exit(1);
    }
    met_phi_isLoaded = true;
  }
  return met_phi_;
}

const float &hwwtree::met_up_pt() {
  if (not met_up_pt_isLoaded) {
    if (met_up_pt_branch != 0) {
      met_up_pt_branch->GetEntry(index);
    } else {
      printf("branch met_up_pt_branch does not exist!\n");
      exit(1);
    }
    met_up_pt_isLoaded = true;
  }
  return met_up_pt_;
}

const float &hwwtree::met_up_phi() {
  if (not met_up_phi_isLoaded) {
    if (met_up_phi_branch != 0) {
      met_up_phi_branch->GetEntry(index);
    } else {
      printf("branch met_up_phi_branch does not exist!\n");
      exit(1);
    }
    met_up_phi_isLoaded = true;
  }
  return met_up_phi_;
}

const float &hwwtree::met_dn_pt() {
  if (not met_dn_pt_isLoaded) {
    if (met_dn_pt_branch != 0) {
      met_dn_pt_branch->GetEntry(index);
    } else {
      printf("branch met_dn_pt_branch does not exist!\n");
      exit(1);
    }
    met_dn_pt_isLoaded = true;
  }
  return met_dn_pt_;
}

const float &hwwtree::met_dn_phi() {
  if (not met_dn_phi_isLoaded) {
    if (met_dn_phi_branch != 0) {
      met_dn_phi_branch->GetEntry(index);
    } else {
      printf("branch met_dn_phi_branch does not exist!\n");
      exit(1);
    }
    met_dn_phi_isLoaded = true;
  }
  return met_dn_phi_;
}

const float &hwwtree::met_gen_pt() {
  if (not met_gen_pt_isLoaded) {
    if (met_gen_pt_branch != 0) {
      met_gen_pt_branch->GetEntry(index);
    } else {
      printf("branch met_gen_pt_branch does not exist!\n");
      exit(1);
    }
    met_gen_pt_isLoaded = true;
  }
  return met_gen_pt_;
}

const float &hwwtree::met_gen_phi() {
  if (not met_gen_phi_isLoaded) {
    if (met_gen_phi_branch != 0) {
      met_gen_phi_branch->GetEntry(index);
    } else {
      printf("branch met_gen_phi_branch does not exist!\n");
      exit(1);
    }
    met_gen_phi_isLoaded = true;
  }
  return met_gen_phi_;
}

const int &hwwtree::HLT_Ele27_WPLoose_Gsf() {
  if (not HLT_Ele27_WPLoose_Gsf_isLoaded) {
    if (HLT_Ele27_WPLoose_Gsf_branch != 0) {
      HLT_Ele27_WPLoose_Gsf_branch->GetEntry(index);
    } else {
      printf("branch HLT_Ele27_WPLoose_Gsf_branch does not exist!\n");
      exit(1);
    }
    HLT_Ele27_WPLoose_Gsf_isLoaded = true;
  }
  return HLT_Ele27_WPLoose_Gsf_;
}

const int &hwwtree::HLT_Ele30_WPLoose_Gsf() {
  if (not HLT_Ele30_WPLoose_Gsf_isLoaded) {
    if (HLT_Ele30_WPLoose_Gsf_branch != 0) {
      HLT_Ele30_WPLoose_Gsf_branch->GetEntry(index);
    } else {
      printf("branch HLT_Ele30_WPLoose_Gsf_branch does not exist!\n");
      exit(1);
    }
    HLT_Ele30_WPLoose_Gsf_isLoaded = true;
  }
  return HLT_Ele30_WPLoose_Gsf_;
}

const int &hwwtree::HLT_Ele45_WPLoose_Gsf() {
  if (not HLT_Ele45_WPLoose_Gsf_isLoaded) {
    if (HLT_Ele45_WPLoose_Gsf_branch != 0) {
      HLT_Ele45_WPLoose_Gsf_branch->GetEntry(index);
    } else {
      printf("branch HLT_Ele45_WPLoose_Gsf_branch does not exist!\n");
      exit(1);
    }
    HLT_Ele45_WPLoose_Gsf_isLoaded = true;
  }
  return HLT_Ele45_WPLoose_Gsf_;
}

const int &hwwtree::HLT_Ele105_CaloIdVT_GsfTrkIdT() {
  if (not HLT_Ele105_CaloIdVT_GsfTrkIdT_isLoaded) {
    if (HLT_Ele105_CaloIdVT_GsfTrkIdT_branch != 0) {
      HLT_Ele105_CaloIdVT_GsfTrkIdT_branch->GetEntry(index);
    } else {
      printf("branch HLT_Ele105_CaloIdVT_GsfTrkIdT_branch does not exist!\n");
      exit(1);
    }
    HLT_Ele105_CaloIdVT_GsfTrkIdT_isLoaded = true;
  }
  return HLT_Ele105_CaloIdVT_GsfTrkIdT_;
}

const int &hwwtree::HLT_Ele115_CaloIdVT_GsfTrkIdT() {
  if (not HLT_Ele115_CaloIdVT_GsfTrkIdT_isLoaded) {
    if (HLT_Ele115_CaloIdVT_GsfTrkIdT_branch != 0) {
      HLT_Ele115_CaloIdVT_GsfTrkIdT_branch->GetEntry(index);
    } else {
      printf("branch HLT_Ele115_CaloIdVT_GsfTrkIdT_branch does not exist!\n");
      exit(1);
    }
    HLT_Ele115_CaloIdVT_GsfTrkIdT_isLoaded = true;
  }
  return HLT_Ele115_CaloIdVT_GsfTrkIdT_;
}

const int &hwwtree::HLT_IsoTkMu24() {
  if (not HLT_IsoTkMu24_isLoaded) {
    if (HLT_IsoTkMu24_branch != 0) {
      HLT_IsoTkMu24_branch->GetEntry(index);
    } else {
      printf("branch HLT_IsoTkMu24_branch does not exist!\n");
      exit(1);
    }
    HLT_IsoTkMu24_isLoaded = true;
  }
  return HLT_IsoTkMu24_;
}

const int &hwwtree::HLT_IsoMu24() {
  if (not HLT_IsoMu24_isLoaded) {
    if (HLT_IsoMu24_branch != 0) {
      HLT_IsoMu24_branch->GetEntry(index);
    } else {
      printf("branch HLT_IsoMu24_branch does not exist!\n");
      exit(1);
    }
    HLT_IsoMu24_isLoaded = true;
  }
  return HLT_IsoMu24_;
}

const int &hwwtree::HLT_SingleMu50() {
  if (not HLT_SingleMu50_isLoaded) {
    if (HLT_SingleMu50_branch != 0) {
      HLT_SingleMu50_branch->GetEntry(index);
    } else {
      printf("branch HLT_SingleMu50_branch does not exist!\n");
      exit(1);
    }
    HLT_SingleMu50_isLoaded = true;
  }
  return HLT_SingleMu50_;
}

const int &hwwtree::HLT_SingleEl40() {
  if (not HLT_SingleEl40_isLoaded) {
    if (HLT_SingleEl40_branch != 0) {
      HLT_SingleEl40_branch->GetEntry(index);
    } else {
      printf("branch HLT_SingleEl40_branch does not exist!\n");
      exit(1);
    }
    HLT_SingleEl40_isLoaded = true;
  }
  return HLT_SingleEl40_;
}

const int &hwwtree::HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165() {
  if (not HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_isLoaded) {
    if (HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch != 0) {
      HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch->GetEntry(index);
    } else {
      printf("branch HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_branch does not exist!\n");
      exit(1);
    }
    HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_isLoaded = true;
  }
  return HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_;
}

const int &hwwtree::HLT_Mu50() {
  if (not HLT_Mu50_isLoaded) {
    if (HLT_Mu50_branch != 0) {
      HLT_Mu50_branch->GetEntry(index);
    } else {
      printf("branch HLT_Mu50_branch does not exist!\n");
      exit(1);
    }
    HLT_Mu50_isLoaded = true;
  }
  return HLT_Mu50_;
}

const int &hwwtree::HLT_TkMu50() {
  if (not HLT_TkMu50_isLoaded) {
    if (HLT_TkMu50_branch != 0) {
      HLT_TkMu50_branch->GetEntry(index);
    } else {
      printf("branch HLT_TkMu50_branch does not exist!\n");
      exit(1);
    }
    HLT_TkMu50_isLoaded = true;
  }
  return HLT_TkMu50_;
}

const int &hwwtree::HLT_AK8PFHT700_TrimR0p1PT0p03Mass50() {
  if (not HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded) {
    if (HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch != 0) {
      HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch->GetEntry(index);
    } else {
      printf("branch HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch does not exist!\n");
      exit(1);
    }
    HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded = true;
  }
  return HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_;
}

const int &hwwtree::HLT_AK8PFJet360_TrimMass30() {
  if (not HLT_AK8PFJet360_TrimMass30_isLoaded) {
    if (HLT_AK8PFJet360_TrimMass30_branch != 0) {
      HLT_AK8PFJet360_TrimMass30_branch->GetEntry(index);
    } else {
      printf("branch HLT_AK8PFJet360_TrimMass30_branch does not exist!\n");
      exit(1);
    }
    HLT_AK8PFJet360_TrimMass30_isLoaded = true;
  }
  return HLT_AK8PFJet360_TrimMass30_;
}

const int &hwwtree::HLT_PFHT800() {
  if (not HLT_PFHT800_isLoaded) {
    if (HLT_PFHT800_branch != 0) {
      HLT_PFHT800_branch->GetEntry(index);
    } else {
      printf("branch HLT_PFHT800_branch does not exist!\n");
      exit(1);
    }
    HLT_PFHT800_isLoaded = true;
  }
  return HLT_PFHT800_;
}

const int &hwwtree::HLT_PFHT900() {
  if (not HLT_PFHT900_isLoaded) {
    if (HLT_PFHT900_branch != 0) {
      HLT_PFHT900_branch->GetEntry(index);
    } else {
      printf("branch HLT_PFHT900_branch does not exist!\n");
      exit(1);
    }
    HLT_PFHT900_isLoaded = true;
  }
  return HLT_PFHT900_;
}

const int &hwwtree::HLT_PFHT650_WideJetMJJ900DEtaJJ1p5() {
  if (not HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded) {
    if (HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch != 0) {
      HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch->GetEntry(index);
    } else {
      printf("branch HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch does not exist!\n");
      exit(1);
    }
    HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded = true;
  }
  return HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_;
}

const int &hwwtree::HLT_PFHT650_WideJetMJJ950DEtaJJ1p5() {
  if (not HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded) {
    if (HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch != 0) {
      HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch->GetEntry(index);
    } else {
      printf("branch HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch does not exist!\n");
      exit(1);
    }
    HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded = true;
  }
  return HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_;
}

const int &hwwtree::HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20() {
  if (not HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_isLoaded) {
    if (HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch != 0) {
      HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch->GetEntry(index);
    } else {
      printf("branch HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_branch does not exist!\n");
      exit(1);
    }
    HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_isLoaded = true;
  }
  return HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20_;
}

const int &hwwtree::pass_duplicate_se_sm() {
  if (not pass_duplicate_se_sm_isLoaded) {
    if (pass_duplicate_se_sm_branch != 0) {
      pass_duplicate_se_sm_branch->GetEntry(index);
    } else {
      printf("branch pass_duplicate_se_sm_branch does not exist!\n");
      exit(1);
    }
    pass_duplicate_se_sm_isLoaded = true;
  }
  return pass_duplicate_se_sm_;
}

const int &hwwtree::pass_duplicate_sm_se() {
  if (not pass_duplicate_sm_se_isLoaded) {
    if (pass_duplicate_sm_se_branch != 0) {
      pass_duplicate_sm_se_branch->GetEntry(index);
    } else {
      printf("branch pass_duplicate_sm_se_branch does not exist!\n");
      exit(1);
    }
    pass_duplicate_sm_se_isLoaded = true;
  }
  return pass_duplicate_sm_se_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_recoil_p4() {
  if (not gen_recoil_p4_isLoaded) {
    if (gen_recoil_p4_branch != 0) {
      gen_recoil_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_recoil_p4_branch does not exist!\n");
      exit(1);
    }
    gen_recoil_p4_isLoaded = true;
  }
  return *gen_recoil_p4_;
}

const int &hwwtree::gen_recoil_id() {
  if (not gen_recoil_id_isLoaded) {
    if (gen_recoil_id_branch != 0) {
      gen_recoil_id_branch->GetEntry(index);
    } else {
      printf("branch gen_recoil_id_branch does not exist!\n");
      exit(1);
    }
    gen_recoil_id_isLoaded = true;
  }
  return gen_recoil_id_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_higgs_p4() {
  if (not gen_higgs_p4_isLoaded) {
    if (gen_higgs_p4_branch != 0) {
      gen_higgs_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_higgs_p4_branch does not exist!\n");
      exit(1);
    }
    gen_higgs_p4_isLoaded = true;
  }
  return *gen_higgs_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_whad_p4() {
  if (not gen_whad_p4_isLoaded) {
    if (gen_whad_p4_branch != 0) {
      gen_whad_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_whad_p4_branch does not exist!\n");
      exit(1);
    }
    gen_whad_p4_isLoaded = true;
  }
  return *gen_whad_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_wlep_p4() {
  if (not gen_wlep_p4_isLoaded) {
    if (gen_wlep_p4_branch != 0) {
      gen_wlep_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_wlep_p4_branch does not exist!\n");
      exit(1);
    }
    gen_wlep_p4_isLoaded = true;
  }
  return *gen_wlep_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_q0_p4() {
  if (not gen_q0_p4_isLoaded) {
    if (gen_q0_p4_branch != 0) {
      gen_q0_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_q0_p4_branch does not exist!\n");
      exit(1);
    }
    gen_q0_p4_isLoaded = true;
  }
  return *gen_q0_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_q1_p4() {
  if (not gen_q1_p4_isLoaded) {
    if (gen_q1_p4_branch != 0) {
      gen_q1_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_q1_p4_branch does not exist!\n");
      exit(1);
    }
    gen_q1_p4_isLoaded = true;
  }
  return *gen_q1_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_lep_p4() {
  if (not gen_lep_p4_isLoaded) {
    if (gen_lep_p4_branch != 0) {
      gen_lep_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_lep_p4_branch does not exist!\n");
      exit(1);
    }
    gen_lep_p4_isLoaded = true;
  }
  return *gen_lep_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_neu_p4() {
  if (not gen_neu_p4_isLoaded) {
    if (gen_neu_p4_branch != 0) {
      gen_neu_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_neu_p4_branch does not exist!\n");
      exit(1);
    }
    gen_neu_p4_isLoaded = true;
  }
  return *gen_neu_p4_;
}

const int &hwwtree::gen_channel() {
  if (not gen_channel_isLoaded) {
    if (gen_channel_branch != 0) {
      gen_channel_branch->GetEntry(index);
    } else {
      printf("branch gen_channel_branch does not exist!\n");
      exit(1);
    }
    gen_channel_isLoaded = true;
  }
  return gen_channel_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_wlep_rest_p4() {
  if (not gen_wlep_rest_p4_isLoaded) {
    if (gen_wlep_rest_p4_branch != 0) {
      gen_wlep_rest_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_wlep_rest_p4_branch does not exist!\n");
      exit(1);
    }
    gen_wlep_rest_p4_isLoaded = true;
  }
  return *gen_wlep_rest_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_whad_rest_p4() {
  if (not gen_whad_rest_p4_isLoaded) {
    if (gen_whad_rest_p4_branch != 0) {
      gen_whad_rest_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_whad_rest_p4_branch does not exist!\n");
      exit(1);
    }
    gen_whad_rest_p4_isLoaded = true;
  }
  return *gen_whad_rest_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_Vq0_p4() {
  if (not gen_Vq0_p4_isLoaded) {
    if (gen_Vq0_p4_branch != 0) {
      gen_Vq0_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_Vq0_p4_branch does not exist!\n");
      exit(1);
    }
    gen_Vq0_p4_isLoaded = true;
  }
  return *gen_Vq0_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_Vq1_p4() {
  if (not gen_Vq1_p4_isLoaded) {
    if (gen_Vq1_p4_branch != 0) {
      gen_Vq1_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_Vq1_p4_branch does not exist!\n");
      exit(1);
    }
    gen_Vq1_p4_isLoaded = true;
  }
  return *gen_Vq1_p4_;
}

const int &hwwtree::gen_Vq0_id() {
  if (not gen_Vq0_id_isLoaded) {
    if (gen_Vq0_id_branch != 0) {
      gen_Vq0_id_branch->GetEntry(index);
    } else {
      printf("branch gen_Vq0_id_branch does not exist!\n");
      exit(1);
    }
    gen_Vq0_id_isLoaded = true;
  }
  return gen_Vq0_id_;
}

const int &hwwtree::gen_Vq1_id() {
  if (not gen_Vq1_id_isLoaded) {
    if (gen_Vq1_id_branch != 0) {
      gen_Vq1_id_branch->GetEntry(index);
    } else {
      printf("branch gen_Vq1_id_branch does not exist!\n");
      exit(1);
    }
    gen_Vq1_id_isLoaded = true;
  }
  return gen_Vq1_id_;
}

const int &hwwtree::gen_q0_id() {
  if (not gen_q0_id_isLoaded) {
    if (gen_q0_id_branch != 0) {
      gen_q0_id_branch->GetEntry(index);
    } else {
      printf("branch gen_q0_id_branch does not exist!\n");
      exit(1);
    }
    gen_q0_id_isLoaded = true;
  }
  return gen_q0_id_;
}

const int &hwwtree::gen_q1_id() {
  if (not gen_q1_id_isLoaded) {
    if (gen_q1_id_branch != 0) {
      gen_q1_id_branch->GetEntry(index);
    } else {
      printf("branch gen_q1_id_branch does not exist!\n");
      exit(1);
    }
    gen_q1_id_isLoaded = true;
  }
  return gen_q1_id_;
}

const int &hwwtree::gen_lep_id() {
  if (not gen_lep_id_isLoaded) {
    if (gen_lep_id_branch != 0) {
      gen_lep_id_branch->GetEntry(index);
    } else {
      printf("branch gen_lep_id_branch does not exist!\n");
      exit(1);
    }
    gen_lep_id_isLoaded = true;
  }
  return gen_lep_id_;
}

const int &hwwtree::gen_neu_id() {
  if (not gen_neu_id_isLoaded) {
    if (gen_neu_id_branch != 0) {
      gen_neu_id_branch->GetEntry(index);
    } else {
      printf("branch gen_neu_id_branch does not exist!\n");
      exit(1);
    }
    gen_neu_id_isLoaded = true;
  }
  return gen_neu_id_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::J_p4() {
  if (not J_p4_isLoaded) {
    if (J_p4_branch != 0) {
      J_p4_branch->GetEntry(index);
    } else {
      printf("branch J_p4_branch does not exist!\n");
      exit(1);
    }
    J_p4_isLoaded = true;
  }
  return *J_p4_;
}

const float &hwwtree::dphi_met_J() {
  if (not dphi_met_J_isLoaded) {
    if (dphi_met_J_branch != 0) {
      dphi_met_J_branch->GetEntry(index);
    } else {
      printf("branch dphi_met_J_branch does not exist!\n");
      exit(1);
    }
    dphi_met_J_isLoaded = true;
  }
  return dphi_met_J_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Jmet_p4() {
  if (not Jmet_p4_isLoaded) {
    if (Jmet_p4_branch != 0) {
      Jmet_p4_branch->GetEntry(index);
    } else {
      printf("branch Jmet_p4_branch does not exist!\n");
      exit(1);
    }
    Jmet_p4_isLoaded = true;
  }
  return *Jmet_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::L_p4() {
  if (not L_p4_isLoaded) {
    if (L_p4_branch != 0) {
      L_p4_branch->GetEntry(index);
    } else {
      printf("branch L_p4_branch does not exist!\n");
      exit(1);
    }
    L_p4_isLoaded = true;
  }
  return *L_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Lmet_p4() {
  if (not Lmet_p4_isLoaded) {
    if (Lmet_p4_branch != 0) {
      Lmet_p4_branch->GetEntry(index);
    } else {
      printf("branch Lmet_p4_branch does not exist!\n");
      exit(1);
    }
    Lmet_p4_isLoaded = true;
  }
  return *Lmet_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::QQ_p4() {
  if (not QQ_p4_isLoaded) {
    if (QQ_p4_branch != 0) {
      QQ_p4_branch->GetEntry(index);
    } else {
      printf("branch QQ_p4_branch does not exist!\n");
      exit(1);
    }
    QQ_p4_isLoaded = true;
  }
  return *QQ_p4_;
}

const float &hwwtree::dr_L_QQ() {
  if (not dr_L_QQ_isLoaded) {
    if (dr_L_QQ_branch != 0) {
      dr_L_QQ_branch->GetEntry(index);
    } else {
      printf("branch dr_L_QQ_branch does not exist!\n");
      exit(1);
    }
    dr_L_QQ_isLoaded = true;
  }
  return dr_L_QQ_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::QQp_p4() {
  if (not QQp_p4_isLoaded) {
    if (QQp_p4_branch != 0) {
      QQp_p4_branch->GetEntry(index);
    } else {
      printf("branch QQp_p4_branch does not exist!\n");
      exit(1);
    }
    QQp_p4_isLoaded = true;
  }
  return *QQp_p4_;
}

const float &hwwtree::dr_L_QQp() {
  if (not dr_L_QQp_isLoaded) {
    if (dr_L_QQp_branch != 0) {
      dr_L_QQp_branch->GetEntry(index);
    } else {
      printf("branch dr_L_QQp_branch does not exist!\n");
      exit(1);
    }
    dr_L_QQp_isLoaded = true;
  }
  return dr_L_QQp_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::LQQ_p4() {
  if (not LQQ_p4_isLoaded) {
    if (LQQ_p4_branch != 0) {
      LQQ_p4_branch->GetEntry(index);
    } else {
      printf("branch LQQ_p4_branch does not exist!\n");
      exit(1);
    }
    LQQ_p4_isLoaded = true;
  }
  return *LQQ_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::LQQp_p4() {
  if (not LQQp_p4_isLoaded) {
    if (LQQp_p4_branch != 0) {
      LQQp_p4_branch->GetEntry(index);
    } else {
      printf("branch LQQp_p4_branch does not exist!\n");
      exit(1);
    }
    LQQp_p4_isLoaded = true;
  }
  return *LQQp_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::H_p4() {
  if (not H_p4_isLoaded) {
    if (H_p4_branch != 0) {
      H_p4_branch->GetEntry(index);
    } else {
      printf("branch H_p4_branch does not exist!\n");
      exit(1);
    }
    H_p4_isLoaded = true;
  }
  return *H_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Hp_p4() {
  if (not Hp_p4_isLoaded) {
    if (Hp_p4_branch != 0) {
      Hp_p4_branch->GetEntry(index);
    } else {
      printf("branch Hp_p4_branch does not exist!\n");
      exit(1);
    }
    Hp_p4_isLoaded = true;
  }
  return *Hp_p4_;
}

const int &hwwtree::is_whad_lead() {
  if (not is_whad_lead_isLoaded) {
    if (is_whad_lead_branch != 0) {
      is_whad_lead_branch->GetEntry(index);
    } else {
      printf("branch is_whad_lead_branch does not exist!\n");
      exit(1);
    }
    is_whad_lead_isLoaded = true;
  }
  return is_whad_lead_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::v_p4() {
  if (not v_p4_isLoaded) {
    if (v_p4_branch != 0) {
      v_p4_branch->GetEntry(index);
    } else {
      printf("branch v_p4_branch does not exist!\n");
      exit(1);
    }
    v_p4_isLoaded = true;
  }
  return *v_p4_;
}

const float &hwwtree::J_area() {
  if (not J_area_isLoaded) {
    if (J_area_branch != 0) {
      J_area_branch->GetEntry(index);
    } else {
      printf("branch J_area_branch does not exist!\n");
      exit(1);
    }
    J_area_isLoaded = true;
  }
  return J_area_;
}

const float &hwwtree::J_mass() {
  if (not J_mass_isLoaded) {
    if (J_mass_branch != 0) {
      J_mass_branch->GetEntry(index);
    } else {
      printf("branch J_mass_branch does not exist!\n");
      exit(1);
    }
    J_mass_isLoaded = true;
  }
  return J_mass_;
}

const float &hwwtree::J_softdropMass() {
  if (not J_softdropMass_isLoaded) {
    if (J_softdropMass_branch != 0) {
      J_softdropMass_branch->GetEntry(index);
    } else {
      printf("branch J_softdropMass_branch does not exist!\n");
      exit(1);
    }
    J_softdropMass_isLoaded = true;
  }
  return J_softdropMass_;
}

const float &hwwtree::J_nJettinessTau1() {
  if (not J_nJettinessTau1_isLoaded) {
    if (J_nJettinessTau1_branch != 0) {
      J_nJettinessTau1_branch->GetEntry(index);
    } else {
      printf("branch J_nJettinessTau1_branch does not exist!\n");
      exit(1);
    }
    J_nJettinessTau1_isLoaded = true;
  }
  return J_nJettinessTau1_;
}

const float &hwwtree::J_nJettinessTau2() {
  if (not J_nJettinessTau2_isLoaded) {
    if (J_nJettinessTau2_branch != 0) {
      J_nJettinessTau2_branch->GetEntry(index);
    } else {
      printf("branch J_nJettinessTau2_branch does not exist!\n");
      exit(1);
    }
    J_nJettinessTau2_isLoaded = true;
  }
  return J_nJettinessTau2_;
}

const float &hwwtree::J_nJettinessTau3() {
  if (not J_nJettinessTau3_isLoaded) {
    if (J_nJettinessTau3_branch != 0) {
      J_nJettinessTau3_branch->GetEntry(index);
    } else {
      printf("branch J_nJettinessTau3_branch does not exist!\n");
      exit(1);
    }
    J_nJettinessTau3_isLoaded = true;
  }
  return J_nJettinessTau3_;
}

const float &hwwtree::J_deep_rawdisc_h4q() {
  if (not J_deep_rawdisc_h4q_isLoaded) {
    if (J_deep_rawdisc_h4q_branch != 0) {
      J_deep_rawdisc_h4q_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_h4q_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_h4q_isLoaded = true;
  }
  return J_deep_rawdisc_h4q_;
}

const float &hwwtree::J_deep_rawdisc_hbb() {
  if (not J_deep_rawdisc_hbb_isLoaded) {
    if (J_deep_rawdisc_hbb_branch != 0) {
      J_deep_rawdisc_hbb_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_hbb_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_hbb_isLoaded = true;
  }
  return J_deep_rawdisc_hbb_;
}

const float &hwwtree::J_deep_rawdisc_qcd() {
  if (not J_deep_rawdisc_qcd_isLoaded) {
    if (J_deep_rawdisc_qcd_branch != 0) {
      J_deep_rawdisc_qcd_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_qcd_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_qcd_isLoaded = true;
  }
  return J_deep_rawdisc_qcd_;
}

const float &hwwtree::J_deep_rawdisc_top() {
  if (not J_deep_rawdisc_top_isLoaded) {
    if (J_deep_rawdisc_top_branch != 0) {
      J_deep_rawdisc_top_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_top_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_top_isLoaded = true;
  }
  return J_deep_rawdisc_top_;
}

const float &hwwtree::J_deep_rawdisc_w() {
  if (not J_deep_rawdisc_w_isLoaded) {
    if (J_deep_rawdisc_w_branch != 0) {
      J_deep_rawdisc_w_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_w_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_w_isLoaded = true;
  }
  return J_deep_rawdisc_w_;
}

const float &hwwtree::J_deep_rawdisc_z() {
  if (not J_deep_rawdisc_z_isLoaded) {
    if (J_deep_rawdisc_z_branch != 0) {
      J_deep_rawdisc_z_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_z_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_z_isLoaded = true;
  }
  return J_deep_rawdisc_z_;
}

const float &hwwtree::J_deep_rawdisc_zbb() {
  if (not J_deep_rawdisc_zbb_isLoaded) {
    if (J_deep_rawdisc_zbb_branch != 0) {
      J_deep_rawdisc_zbb_branch->GetEntry(index);
    } else {
      printf("branch J_deep_rawdisc_zbb_branch does not exist!\n");
      exit(1);
    }
    J_deep_rawdisc_zbb_isLoaded = true;
  }
  return J_deep_rawdisc_zbb_;
}

const float &hwwtree::J_softdropPuppiSubjet1_pt() {
  if (not J_softdropPuppiSubjet1_pt_isLoaded) {
    if (J_softdropPuppiSubjet1_pt_branch != 0) {
      J_softdropPuppiSubjet1_pt_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet1_pt_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet1_pt_isLoaded = true;
  }
  return J_softdropPuppiSubjet1_pt_;
}

const float &hwwtree::J_softdropPuppiSubjet1_eta() {
  if (not J_softdropPuppiSubjet1_eta_isLoaded) {
    if (J_softdropPuppiSubjet1_eta_branch != 0) {
      J_softdropPuppiSubjet1_eta_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet1_eta_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet1_eta_isLoaded = true;
  }
  return J_softdropPuppiSubjet1_eta_;
}

const float &hwwtree::J_softdropPuppiSubjet1_phi() {
  if (not J_softdropPuppiSubjet1_phi_isLoaded) {
    if (J_softdropPuppiSubjet1_phi_branch != 0) {
      J_softdropPuppiSubjet1_phi_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet1_phi_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet1_phi_isLoaded = true;
  }
  return J_softdropPuppiSubjet1_phi_;
}

const float &hwwtree::J_softdropPuppiSubjet1_mass() {
  if (not J_softdropPuppiSubjet1_mass_isLoaded) {
    if (J_softdropPuppiSubjet1_mass_branch != 0) {
      J_softdropPuppiSubjet1_mass_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet1_mass_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet1_mass_isLoaded = true;
  }
  return J_softdropPuppiSubjet1_mass_;
}

const float &hwwtree::J_softdropPuppiSubjet1_energy() {
  if (not J_softdropPuppiSubjet1_energy_isLoaded) {
    if (J_softdropPuppiSubjet1_energy_branch != 0) {
      J_softdropPuppiSubjet1_energy_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet1_energy_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet1_energy_isLoaded = true;
  }
  return J_softdropPuppiSubjet1_energy_;
}

const float &hwwtree::J_softdropPuppiSubjet2_pt() {
  if (not J_softdropPuppiSubjet2_pt_isLoaded) {
    if (J_softdropPuppiSubjet2_pt_branch != 0) {
      J_softdropPuppiSubjet2_pt_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet2_pt_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet2_pt_isLoaded = true;
  }
  return J_softdropPuppiSubjet2_pt_;
}

const float &hwwtree::J_softdropPuppiSubjet2_eta() {
  if (not J_softdropPuppiSubjet2_eta_isLoaded) {
    if (J_softdropPuppiSubjet2_eta_branch != 0) {
      J_softdropPuppiSubjet2_eta_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet2_eta_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet2_eta_isLoaded = true;
  }
  return J_softdropPuppiSubjet2_eta_;
}

const float &hwwtree::J_softdropPuppiSubjet2_phi() {
  if (not J_softdropPuppiSubjet2_phi_isLoaded) {
    if (J_softdropPuppiSubjet2_phi_branch != 0) {
      J_softdropPuppiSubjet2_phi_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet2_phi_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet2_phi_isLoaded = true;
  }
  return J_softdropPuppiSubjet2_phi_;
}

const float &hwwtree::J_softdropPuppiSubjet2_mass() {
  if (not J_softdropPuppiSubjet2_mass_isLoaded) {
    if (J_softdropPuppiSubjet2_mass_branch != 0) {
      J_softdropPuppiSubjet2_mass_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet2_mass_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet2_mass_isLoaded = true;
  }
  return J_softdropPuppiSubjet2_mass_;
}

const float &hwwtree::J_softdropPuppiSubjet2_energy() {
  if (not J_softdropPuppiSubjet2_energy_isLoaded) {
    if (J_softdropPuppiSubjet2_energy_branch != 0) {
      J_softdropPuppiSubjet2_energy_branch->GetEntry(index);
    } else {
      printf("branch J_softdropPuppiSubjet2_energy_branch does not exist!\n");
      exit(1);
    }
    J_softdropPuppiSubjet2_energy_isLoaded = true;
  }
  return J_softdropPuppiSubjet2_energy_;
}

const int &hwwtree::J_npfcands() {
  if (not J_npfcands_isLoaded) {
    if (J_npfcands_branch != 0) {
      J_npfcands_branch->GetEntry(index);
    } else {
      printf("branch J_npfcands_branch does not exist!\n");
      exit(1);
    }
    J_npfcands_isLoaded = true;
  }
  return J_npfcands_;
}

const int &hwwtree::J_partonFlavour() {
  if (not J_partonFlavour_isLoaded) {
    if (J_partonFlavour_branch != 0) {
      J_partonFlavour_branch->GetEntry(index);
    } else {
      printf("branch J_partonFlavour_branch does not exist!\n");
      exit(1);
    }
    J_partonFlavour_isLoaded = true;
  }
  return J_partonFlavour_;
}

const int &hwwtree::L_id() {
  if (not L_id_isLoaded) {
    if (L_id_branch != 0) {
      L_id_branch->GetEntry(index);
    } else {
      printf("branch L_id_branch does not exist!\n");
      exit(1);
    }
    L_id_isLoaded = true;
  }
  return L_id_;
}

const int &hwwtree::L_idx() {
  if (not L_idx_isLoaded) {
    if (L_idx_branch != 0) {
      L_idx_branch->GetEntry(index);
    } else {
      printf("branch L_idx_branch does not exist!\n");
      exit(1);
    }
    L_idx_isLoaded = true;
  }
  return L_idx_;
}

const float &hwwtree::L_miniIsoEA() {
  if (not L_miniIsoEA_isLoaded) {
    if (L_miniIsoEA_branch != 0) {
      L_miniIsoEA_branch->GetEntry(index);
    } else {
      printf("branch L_miniIsoEA_branch does not exist!\n");
      exit(1);
    }
    L_miniIsoEA_isLoaded = true;
  }
  return L_miniIsoEA_;
}

const float &hwwtree::L_relIso03EA() {
  if (not L_relIso03EA_isLoaded) {
    if (L_relIso03EA_branch != 0) {
      L_relIso03EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso03EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso03EA_isLoaded = true;
  }
  return L_relIso03EA_;
}

const float &hwwtree::L_relIso04DB() {
  if (not L_relIso04DB_isLoaded) {
    if (L_relIso04DB_branch != 0) {
      L_relIso04DB_branch->GetEntry(index);
    } else {
      printf("branch L_relIso04DB_branch does not exist!\n");
      exit(1);
    }
    L_relIso04DB_isLoaded = true;
  }
  return L_relIso04DB_;
}

const float &hwwtree::L_customrelIso005EA() {
  if (not L_customrelIso005EA_isLoaded) {
    if (L_customrelIso005EA_branch != 0) {
      L_customrelIso005EA_branch->GetEntry(index);
    } else {
      printf("branch L_customrelIso005EA_branch does not exist!\n");
      exit(1);
    }
    L_customrelIso005EA_isLoaded = true;
  }
  return L_customrelIso005EA_;
}

const float &hwwtree::L_customrelIso01EA() {
  if (not L_customrelIso01EA_isLoaded) {
    if (L_customrelIso01EA_branch != 0) {
      L_customrelIso01EA_branch->GetEntry(index);
    } else {
      printf("branch L_customrelIso01EA_branch does not exist!\n");
      exit(1);
    }
    L_customrelIso01EA_isLoaded = true;
  }
  return L_customrelIso01EA_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hwwtree::J_near_ak4jets_p4() {
  if (not J_near_ak4jets_p4_isLoaded) {
    if (J_near_ak4jets_p4_branch != 0) {
      J_near_ak4jets_p4_branch->GetEntry(index);
    } else {
      printf("branch J_near_ak4jets_p4_branch does not exist!\n");
      exit(1);
    }
    J_near_ak4jets_p4_isLoaded = true;
  }
  return *J_near_ak4jets_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::L_subjet1_p4() {
  if (not L_subjet1_p4_isLoaded) {
    if (L_subjet1_p4_branch != 0) {
      L_subjet1_p4_branch->GetEntry(index);
    } else {
      printf("branch L_subjet1_p4_branch does not exist!\n");
      exit(1);
    }
    L_subjet1_p4_isLoaded = true;
  }
  return *L_subjet1_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::L_subjet2_p4() {
  if (not L_subjet2_p4_isLoaded) {
    if (L_subjet2_p4_branch != 0) {
      L_subjet2_p4_branch->GetEntry(index);
    } else {
      printf("branch L_subjet2_p4_branch does not exist!\n");
      exit(1);
    }
    L_subjet2_p4_isLoaded = true;
  }
  return *L_subjet2_p4_;
}

const float &hwwtree::L_subjet1_dr() {
  if (not L_subjet1_dr_isLoaded) {
    if (L_subjet1_dr_branch != 0) {
      L_subjet1_dr_branch->GetEntry(index);
    } else {
      printf("branch L_subjet1_dr_branch does not exist!\n");
      exit(1);
    }
    L_subjet1_dr_isLoaded = true;
  }
  return L_subjet1_dr_;
}

const float &hwwtree::L_subjet2_dr() {
  if (not L_subjet2_dr_isLoaded) {
    if (L_subjet2_dr_branch != 0) {
      L_subjet2_dr_branch->GetEntry(index);
    } else {
      printf("branch L_subjet2_dr_branch does not exist!\n");
      exit(1);
    }
    L_subjet2_dr_isLoaded = true;
  }
  return L_subjet2_dr_;
}

const float &hwwtree::L_subjet1_deg() {
  if (not L_subjet1_deg_isLoaded) {
    if (L_subjet1_deg_branch != 0) {
      L_subjet1_deg_branch->GetEntry(index);
    } else {
      printf("branch L_subjet1_deg_branch does not exist!\n");
      exit(1);
    }
    L_subjet1_deg_isLoaded = true;
  }
  return L_subjet1_deg_;
}

const float &hwwtree::L_subjet2_deg() {
  if (not L_subjet2_deg_isLoaded) {
    if (L_subjet2_deg_branch != 0) {
      L_subjet2_deg_branch->GetEntry(index);
    } else {
      printf("branch L_subjet2_deg_branch does not exist!\n");
      exit(1);
    }
    L_subjet2_deg_isLoaded = true;
  }
  return L_subjet2_deg_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Recoil_p4() {
  if (not Recoil_p4_isLoaded) {
    if (Recoil_p4_branch != 0) {
      Recoil_p4_branch->GetEntry(index);
    } else {
      printf("branch Recoil_p4_branch does not exist!\n");
      exit(1);
    }
    Recoil_p4_isLoaded = true;
  }
  return *Recoil_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Recoil_leadak4_p4() {
  if (not Recoil_leadak4_p4_isLoaded) {
    if (Recoil_leadak4_p4_branch != 0) {
      Recoil_leadak4_p4_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_p4_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_p4_isLoaded = true;
  }
  return *Recoil_leadak4_p4_;
}

const int &hwwtree::Recoil_leadak4_npfcands() {
  if (not Recoil_leadak4_npfcands_isLoaded) {
    if (Recoil_leadak4_npfcands_branch != 0) {
      Recoil_leadak4_npfcands_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_npfcands_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_npfcands_isLoaded = true;
  }
  return Recoil_leadak4_npfcands_;
}

const int &hwwtree::Recoil_leadak4_chargedHadronMultiplicity() {
  if (not Recoil_leadak4_chargedHadronMultiplicity_isLoaded) {
    if (Recoil_leadak4_chargedHadronMultiplicity_branch != 0) {
      Recoil_leadak4_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_chargedHadronMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_chargedHadronMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_chargedMultiplicity() {
  if (not Recoil_leadak4_chargedMultiplicity_isLoaded) {
    if (Recoil_leadak4_chargedMultiplicity_branch != 0) {
      Recoil_leadak4_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_chargedMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_chargedMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_electronMultiplicity() {
  if (not Recoil_leadak4_electronMultiplicity_isLoaded) {
    if (Recoil_leadak4_electronMultiplicity_branch != 0) {
      Recoil_leadak4_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_electronMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_electronMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_muonMultiplicity() {
  if (not Recoil_leadak4_muonMultiplicity_isLoaded) {
    if (Recoil_leadak4_muonMultiplicity_branch != 0) {
      Recoil_leadak4_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_muonMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_muonMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_neutralHadronMultiplicity() {
  if (not Recoil_leadak4_neutralHadronMultiplicity_isLoaded) {
    if (Recoil_leadak4_neutralHadronMultiplicity_branch != 0) {
      Recoil_leadak4_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_neutralHadronMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_neutralHadronMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_neutralMultiplicity() {
  if (not Recoil_leadak4_neutralMultiplicity_isLoaded) {
    if (Recoil_leadak4_neutralMultiplicity_branch != 0) {
      Recoil_leadak4_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_neutralMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_neutralMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_photonMultiplicity() {
  if (not Recoil_leadak4_photonMultiplicity_isLoaded) {
    if (Recoil_leadak4_photonMultiplicity_branch != 0) {
      Recoil_leadak4_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_photonMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_photonMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_totalMultiplicity() {
  if (not Recoil_leadak4_totalMultiplicity_isLoaded) {
    if (Recoil_leadak4_totalMultiplicity_branch != 0) {
      Recoil_leadak4_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_totalMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_totalMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_chargedHadronMultiplicity() {
  if (not Recoil_leadak4_puppi_chargedHadronMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_chargedHadronMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_chargedHadronMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_chargedHadronMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_chargedMultiplicity() {
  if (not Recoil_leadak4_puppi_chargedMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_chargedMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_chargedMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_chargedMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_electronMultiplicity() {
  if (not Recoil_leadak4_puppi_electronMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_electronMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_electronMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_electronMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_muonMultiplicity() {
  if (not Recoil_leadak4_puppi_muonMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_muonMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_muonMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_muonMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_neutralHadronMultiplicity() {
  if (not Recoil_leadak4_puppi_neutralHadronMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_neutralHadronMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_neutralHadronMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_neutralHadronMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_neutralMultiplicity() {
  if (not Recoil_leadak4_puppi_neutralMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_neutralMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_neutralMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_neutralMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_photonMultiplicity() {
  if (not Recoil_leadak4_puppi_photonMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_photonMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_photonMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_photonMultiplicity_;
}

const int &hwwtree::Recoil_leadak4_puppi_totalMultiplicity() {
  if (not Recoil_leadak4_puppi_totalMultiplicity_isLoaded) {
    if (Recoil_leadak4_puppi_totalMultiplicity_branch != 0) {
      Recoil_leadak4_puppi_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_leadak4_puppi_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_leadak4_puppi_totalMultiplicity_isLoaded = true;
  }
  return Recoil_leadak4_puppi_totalMultiplicity_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Recoil_allj_1_4_p4() {
  if (not Recoil_allj_1_4_p4_isLoaded) {
    if (Recoil_allj_1_4_p4_branch != 0) {
      Recoil_allj_1_4_p4_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_p4_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_p4_isLoaded = true;
  }
  return *Recoil_allj_1_4_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Recoil_allj_1_4_leadak4_p4() {
  if (not Recoil_allj_1_4_leadak4_p4_isLoaded) {
    if (Recoil_allj_1_4_leadak4_p4_branch != 0) {
      Recoil_allj_1_4_leadak4_p4_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_p4_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_p4_isLoaded = true;
  }
  return *Recoil_allj_1_4_leadak4_p4_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_npfcands() {
  if (not Recoil_allj_1_4_leadak4_npfcands_isLoaded) {
    if (Recoil_allj_1_4_leadak4_npfcands_branch != 0) {
      Recoil_allj_1_4_leadak4_npfcands_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_npfcands_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_npfcands_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_npfcands_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_chargedHadronMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_chargedHadronMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_chargedMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_chargedMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_chargedMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_chargedMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_chargedMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_electronMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_electronMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_electronMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_electronMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_electronMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_muonMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_muonMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_muonMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_muonMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_muonMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_neutralHadronMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_neutralHadronMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_neutralMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_neutralMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_neutralMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_neutralMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_neutralMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_photonMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_photonMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_photonMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_photonMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_photonMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_totalMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_totalMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_totalMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_totalMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_totalMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_electronMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_electronMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_muonMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_muonMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_photonMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_photonMultiplicity_;
}

const int &hwwtree::Recoil_allj_1_4_leadak4_puppi_totalMultiplicity() {
  if (not Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_isLoaded) {
    if (Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch != 0) {
      Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_isLoaded = true;
  }
  return Recoil_allj_1_4_leadak4_puppi_totalMultiplicity_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Recoil_j_3_4_p4() {
  if (not Recoil_j_3_4_p4_isLoaded) {
    if (Recoil_j_3_4_p4_branch != 0) {
      Recoil_j_3_4_p4_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_p4_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_p4_isLoaded = true;
  }
  return *Recoil_j_3_4_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Recoil_j_3_4_leadak4_p4() {
  if (not Recoil_j_3_4_leadak4_p4_isLoaded) {
    if (Recoil_j_3_4_leadak4_p4_branch != 0) {
      Recoil_j_3_4_leadak4_p4_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_p4_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_p4_isLoaded = true;
  }
  return *Recoil_j_3_4_leadak4_p4_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_npfcands() {
  if (not Recoil_j_3_4_leadak4_npfcands_isLoaded) {
    if (Recoil_j_3_4_leadak4_npfcands_branch != 0) {
      Recoil_j_3_4_leadak4_npfcands_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_npfcands_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_npfcands_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_npfcands_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_chargedHadronMultiplicity() {
  if (not Recoil_j_3_4_leadak4_chargedHadronMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_chargedHadronMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_chargedHadronMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_chargedMultiplicity() {
  if (not Recoil_j_3_4_leadak4_chargedMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_chargedMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_chargedMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_chargedMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_electronMultiplicity() {
  if (not Recoil_j_3_4_leadak4_electronMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_electronMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_electronMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_electronMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_muonMultiplicity() {
  if (not Recoil_j_3_4_leadak4_muonMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_muonMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_muonMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_muonMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_neutralHadronMultiplicity() {
  if (not Recoil_j_3_4_leadak4_neutralHadronMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_neutralHadronMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_neutralHadronMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_neutralMultiplicity() {
  if (not Recoil_j_3_4_leadak4_neutralMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_neutralMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_neutralMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_neutralMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_photonMultiplicity() {
  if (not Recoil_j_3_4_leadak4_photonMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_photonMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_photonMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_photonMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_totalMultiplicity() {
  if (not Recoil_j_3_4_leadak4_totalMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_totalMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_totalMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_totalMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_chargedMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_chargedMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_electronMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_electronMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_electronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_electronMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_electronMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_muonMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_muonMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_muonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_muonMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_muonMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_neutralMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_neutralMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_photonMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_photonMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_photonMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_photonMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_photonMultiplicity_;
}

const int &hwwtree::Recoil_j_3_4_leadak4_puppi_totalMultiplicity() {
  if (not Recoil_j_3_4_leadak4_puppi_totalMultiplicity_isLoaded) {
    if (Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch != 0) {
      Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch->GetEntry(index);
    } else {
      printf("branch Recoil_j_3_4_leadak4_puppi_totalMultiplicity_branch does not exist!\n");
      exit(1);
    }
    Recoil_j_3_4_leadak4_puppi_totalMultiplicity_isLoaded = true;
  }
  return Recoil_j_3_4_leadak4_puppi_totalMultiplicity_;
}


void hwwtree::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

const int &run() { return hww.run(); }
const int &lumi() { return hww.lumi(); }
const unsigned long long &evt() { return hww.evt(); }
const int &isData() { return hww.isData(); }
const float &evt_scale1fb() { return hww.evt_scale1fb(); }
const float &genps_weight() { return hww.genps_weight(); }
const float &xsec_br() { return hww.xsec_br(); }
const int &evt_passgoodrunlist() { return hww.evt_passgoodrunlist(); }
const TString &CMS4path() { return hww.CMS4path(); }
const int &CMS4index() { return hww.CMS4index(); }
const float &weight_fr_r1_f1() { return hww.weight_fr_r1_f1(); }
const float &weight_fr_r1_f2() { return hww.weight_fr_r1_f2(); }
const float &weight_fr_r1_f0p5() { return hww.weight_fr_r1_f0p5(); }
const float &weight_fr_r2_f1() { return hww.weight_fr_r2_f1(); }
const float &weight_fr_r2_f2() { return hww.weight_fr_r2_f2(); }
const float &weight_fr_r2_f0p5() { return hww.weight_fr_r2_f0p5(); }
const float &weight_fr_r0p5_f1() { return hww.weight_fr_r0p5_f1(); }
const float &weight_fr_r0p5_f2() { return hww.weight_fr_r0p5_f2(); }
const float &weight_fr_r0p5_f0p5() { return hww.weight_fr_r0p5_f0p5(); }
const float &weight_pdf_up() { return hww.weight_pdf_up(); }
const float &weight_pdf_down() { return hww.weight_pdf_down(); }
const float &weight_alphas_down() { return hww.weight_alphas_down(); }
const float &weight_alphas_up() { return hww.weight_alphas_up(); }
const int &nrecolep() { return hww.nrecolep(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &lep_p4() { return hww.lep_p4(); }
const int &nak8jets() { return hww.nak8jets(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8jets_p4() { return hww.ak8jets_p4(); }
const int &nj() { return hww.nj(); }
const int &nb() { return hww.nb(); }
const int &nbmed() { return hww.nbmed(); }
const int &nbtight() { return hww.nbtight(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4() { return hww.jets_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &alljets_p4() { return hww.alljets_p4(); }
const vector<int> &jets_idx() { return hww.jets_idx(); }
const vector<int> &alljets_idx() { return hww.alljets_idx(); }
const float &met_pt() { return hww.met_pt(); }
const float &met_phi() { return hww.met_phi(); }
const float &met_up_pt() { return hww.met_up_pt(); }
const float &met_up_phi() { return hww.met_up_phi(); }
const float &met_dn_pt() { return hww.met_dn_pt(); }
const float &met_dn_phi() { return hww.met_dn_phi(); }
const float &met_gen_pt() { return hww.met_gen_pt(); }
const float &met_gen_phi() { return hww.met_gen_phi(); }
const int &HLT_Ele27_WPLoose_Gsf() { return hww.HLT_Ele27_WPLoose_Gsf(); }
const int &HLT_Ele30_WPLoose_Gsf() { return hww.HLT_Ele30_WPLoose_Gsf(); }
const int &HLT_Ele45_WPLoose_Gsf() { return hww.HLT_Ele45_WPLoose_Gsf(); }
const int &HLT_Ele105_CaloIdVT_GsfTrkIdT() { return hww.HLT_Ele105_CaloIdVT_GsfTrkIdT(); }
const int &HLT_Ele115_CaloIdVT_GsfTrkIdT() { return hww.HLT_Ele115_CaloIdVT_GsfTrkIdT(); }
const int &HLT_IsoTkMu24() { return hww.HLT_IsoTkMu24(); }
const int &HLT_IsoMu24() { return hww.HLT_IsoMu24(); }
const int &HLT_SingleMu50() { return hww.HLT_SingleMu50(); }
const int &HLT_SingleEl40() { return hww.HLT_SingleEl40(); }
const int &HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165() { return hww.HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165(); }
const int &HLT_Mu50() { return hww.HLT_Mu50(); }
const int &HLT_TkMu50() { return hww.HLT_TkMu50(); }
const int &HLT_AK8PFHT700_TrimR0p1PT0p03Mass50() { return hww.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50(); }
const int &HLT_AK8PFJet360_TrimMass30() { return hww.HLT_AK8PFJet360_TrimMass30(); }
const int &HLT_PFHT800() { return hww.HLT_PFHT800(); }
const int &HLT_PFHT900() { return hww.HLT_PFHT900(); }
const int &HLT_PFHT650_WideJetMJJ900DEtaJJ1p5() { return hww.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5(); }
const int &HLT_PFHT650_WideJetMJJ950DEtaJJ1p5() { return hww.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5(); }
const int &HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20() { return hww.HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20(); }
const int &pass_duplicate_se_sm() { return hww.pass_duplicate_se_sm(); }
const int &pass_duplicate_sm_se() { return hww.pass_duplicate_sm_se(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_recoil_p4() { return hww.gen_recoil_p4(); }
const int &gen_recoil_id() { return hww.gen_recoil_id(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_higgs_p4() { return hww.gen_higgs_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_whad_p4() { return hww.gen_whad_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_wlep_p4() { return hww.gen_wlep_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_q0_p4() { return hww.gen_q0_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_q1_p4() { return hww.gen_q1_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_lep_p4() { return hww.gen_lep_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_neu_p4() { return hww.gen_neu_p4(); }
const int &gen_channel() { return hww.gen_channel(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_wlep_rest_p4() { return hww.gen_wlep_rest_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_whad_rest_p4() { return hww.gen_whad_rest_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_Vq0_p4() { return hww.gen_Vq0_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_Vq1_p4() { return hww.gen_Vq1_p4(); }
const int &gen_Vq0_id() { return hww.gen_Vq0_id(); }
const int &gen_Vq1_id() { return hww.gen_Vq1_id(); }
const int &gen_q0_id() { return hww.gen_q0_id(); }
const int &gen_q1_id() { return hww.gen_q1_id(); }
const int &gen_lep_id() { return hww.gen_lep_id(); }
const int &gen_neu_id() { return hww.gen_neu_id(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &J_p4() { return hww.J_p4(); }
const float &dphi_met_J() { return hww.dphi_met_J(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Jmet_p4() { return hww.Jmet_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &L_p4() { return hww.L_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Lmet_p4() { return hww.Lmet_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &QQ_p4() { return hww.QQ_p4(); }
const float &dr_L_QQ() { return hww.dr_L_QQ(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &QQp_p4() { return hww.QQp_p4(); }
const float &dr_L_QQp() { return hww.dr_L_QQp(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &LQQ_p4() { return hww.LQQ_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &LQQp_p4() { return hww.LQQp_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &H_p4() { return hww.H_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Hp_p4() { return hww.Hp_p4(); }
const int &is_whad_lead() { return hww.is_whad_lead(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &v_p4() { return hww.v_p4(); }
const float &J_area() { return hww.J_area(); }
const float &J_mass() { return hww.J_mass(); }
const float &J_softdropMass() { return hww.J_softdropMass(); }
const float &J_nJettinessTau1() { return hww.J_nJettinessTau1(); }
const float &J_nJettinessTau2() { return hww.J_nJettinessTau2(); }
const float &J_nJettinessTau3() { return hww.J_nJettinessTau3(); }
const float &J_deep_rawdisc_h4q() { return hww.J_deep_rawdisc_h4q(); }
const float &J_deep_rawdisc_hbb() { return hww.J_deep_rawdisc_hbb(); }
const float &J_deep_rawdisc_qcd() { return hww.J_deep_rawdisc_qcd(); }
const float &J_deep_rawdisc_top() { return hww.J_deep_rawdisc_top(); }
const float &J_deep_rawdisc_w() { return hww.J_deep_rawdisc_w(); }
const float &J_deep_rawdisc_z() { return hww.J_deep_rawdisc_z(); }
const float &J_deep_rawdisc_zbb() { return hww.J_deep_rawdisc_zbb(); }
const float &J_softdropPuppiSubjet1_pt() { return hww.J_softdropPuppiSubjet1_pt(); }
const float &J_softdropPuppiSubjet1_eta() { return hww.J_softdropPuppiSubjet1_eta(); }
const float &J_softdropPuppiSubjet1_phi() { return hww.J_softdropPuppiSubjet1_phi(); }
const float &J_softdropPuppiSubjet1_mass() { return hww.J_softdropPuppiSubjet1_mass(); }
const float &J_softdropPuppiSubjet1_energy() { return hww.J_softdropPuppiSubjet1_energy(); }
const float &J_softdropPuppiSubjet2_pt() { return hww.J_softdropPuppiSubjet2_pt(); }
const float &J_softdropPuppiSubjet2_eta() { return hww.J_softdropPuppiSubjet2_eta(); }
const float &J_softdropPuppiSubjet2_phi() { return hww.J_softdropPuppiSubjet2_phi(); }
const float &J_softdropPuppiSubjet2_mass() { return hww.J_softdropPuppiSubjet2_mass(); }
const float &J_softdropPuppiSubjet2_energy() { return hww.J_softdropPuppiSubjet2_energy(); }
const int &J_npfcands() { return hww.J_npfcands(); }
const int &J_partonFlavour() { return hww.J_partonFlavour(); }
const int &L_id() { return hww.L_id(); }
const int &L_idx() { return hww.L_idx(); }
const float &L_miniIsoEA() { return hww.L_miniIsoEA(); }
const float &L_relIso03EA() { return hww.L_relIso03EA(); }
const float &L_relIso04DB() { return hww.L_relIso04DB(); }
const float &L_customrelIso005EA() { return hww.L_customrelIso005EA(); }
const float &L_customrelIso01EA() { return hww.L_customrelIso01EA(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &J_near_ak4jets_p4() { return hww.J_near_ak4jets_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &L_subjet1_p4() { return hww.L_subjet1_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &L_subjet2_p4() { return hww.L_subjet2_p4(); }
const float &L_subjet1_dr() { return hww.L_subjet1_dr(); }
const float &L_subjet2_dr() { return hww.L_subjet2_dr(); }
const float &L_subjet1_deg() { return hww.L_subjet1_deg(); }
const float &L_subjet2_deg() { return hww.L_subjet2_deg(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Recoil_p4() { return hww.Recoil_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Recoil_leadak4_p4() { return hww.Recoil_leadak4_p4(); }
const int &Recoil_leadak4_npfcands() { return hww.Recoil_leadak4_npfcands(); }
const int &Recoil_leadak4_chargedHadronMultiplicity() { return hww.Recoil_leadak4_chargedHadronMultiplicity(); }
const int &Recoil_leadak4_chargedMultiplicity() { return hww.Recoil_leadak4_chargedMultiplicity(); }
const int &Recoil_leadak4_electronMultiplicity() { return hww.Recoil_leadak4_electronMultiplicity(); }
const int &Recoil_leadak4_muonMultiplicity() { return hww.Recoil_leadak4_muonMultiplicity(); }
const int &Recoil_leadak4_neutralHadronMultiplicity() { return hww.Recoil_leadak4_neutralHadronMultiplicity(); }
const int &Recoil_leadak4_neutralMultiplicity() { return hww.Recoil_leadak4_neutralMultiplicity(); }
const int &Recoil_leadak4_photonMultiplicity() { return hww.Recoil_leadak4_photonMultiplicity(); }
const int &Recoil_leadak4_totalMultiplicity() { return hww.Recoil_leadak4_totalMultiplicity(); }
const int &Recoil_leadak4_puppi_chargedHadronMultiplicity() { return hww.Recoil_leadak4_puppi_chargedHadronMultiplicity(); }
const int &Recoil_leadak4_puppi_chargedMultiplicity() { return hww.Recoil_leadak4_puppi_chargedMultiplicity(); }
const int &Recoil_leadak4_puppi_electronMultiplicity() { return hww.Recoil_leadak4_puppi_electronMultiplicity(); }
const int &Recoil_leadak4_puppi_muonMultiplicity() { return hww.Recoil_leadak4_puppi_muonMultiplicity(); }
const int &Recoil_leadak4_puppi_neutralHadronMultiplicity() { return hww.Recoil_leadak4_puppi_neutralHadronMultiplicity(); }
const int &Recoil_leadak4_puppi_neutralMultiplicity() { return hww.Recoil_leadak4_puppi_neutralMultiplicity(); }
const int &Recoil_leadak4_puppi_photonMultiplicity() { return hww.Recoil_leadak4_puppi_photonMultiplicity(); }
const int &Recoil_leadak4_puppi_totalMultiplicity() { return hww.Recoil_leadak4_puppi_totalMultiplicity(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Recoil_allj_1_4_p4() { return hww.Recoil_allj_1_4_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Recoil_allj_1_4_leadak4_p4() { return hww.Recoil_allj_1_4_leadak4_p4(); }
const int &Recoil_allj_1_4_leadak4_npfcands() { return hww.Recoil_allj_1_4_leadak4_npfcands(); }
const int &Recoil_allj_1_4_leadak4_chargedHadronMultiplicity() { return hww.Recoil_allj_1_4_leadak4_chargedHadronMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_chargedMultiplicity() { return hww.Recoil_allj_1_4_leadak4_chargedMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_electronMultiplicity() { return hww.Recoil_allj_1_4_leadak4_electronMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_muonMultiplicity() { return hww.Recoil_allj_1_4_leadak4_muonMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_neutralHadronMultiplicity() { return hww.Recoil_allj_1_4_leadak4_neutralHadronMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_neutralMultiplicity() { return hww.Recoil_allj_1_4_leadak4_neutralMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_photonMultiplicity() { return hww.Recoil_allj_1_4_leadak4_photonMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_totalMultiplicity() { return hww.Recoil_allj_1_4_leadak4_totalMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_chargedHadronMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_chargedMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_electronMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_electronMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_muonMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_muonMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_neutralHadronMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_neutralMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_photonMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_photonMultiplicity(); }
const int &Recoil_allj_1_4_leadak4_puppi_totalMultiplicity() { return hww.Recoil_allj_1_4_leadak4_puppi_totalMultiplicity(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Recoil_j_3_4_p4() { return hww.Recoil_j_3_4_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Recoil_j_3_4_leadak4_p4() { return hww.Recoil_j_3_4_leadak4_p4(); }
const int &Recoil_j_3_4_leadak4_npfcands() { return hww.Recoil_j_3_4_leadak4_npfcands(); }
const int &Recoil_j_3_4_leadak4_chargedHadronMultiplicity() { return hww.Recoil_j_3_4_leadak4_chargedHadronMultiplicity(); }
const int &Recoil_j_3_4_leadak4_chargedMultiplicity() { return hww.Recoil_j_3_4_leadak4_chargedMultiplicity(); }
const int &Recoil_j_3_4_leadak4_electronMultiplicity() { return hww.Recoil_j_3_4_leadak4_electronMultiplicity(); }
const int &Recoil_j_3_4_leadak4_muonMultiplicity() { return hww.Recoil_j_3_4_leadak4_muonMultiplicity(); }
const int &Recoil_j_3_4_leadak4_neutralHadronMultiplicity() { return hww.Recoil_j_3_4_leadak4_neutralHadronMultiplicity(); }
const int &Recoil_j_3_4_leadak4_neutralMultiplicity() { return hww.Recoil_j_3_4_leadak4_neutralMultiplicity(); }
const int &Recoil_j_3_4_leadak4_photonMultiplicity() { return hww.Recoil_j_3_4_leadak4_photonMultiplicity(); }
const int &Recoil_j_3_4_leadak4_totalMultiplicity() { return hww.Recoil_j_3_4_leadak4_totalMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_chargedHadronMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_chargedMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_chargedMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_electronMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_electronMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_muonMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_muonMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_neutralHadronMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_neutralMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_neutralMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_photonMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_photonMultiplicity(); }
const int &Recoil_j_3_4_leadak4_puppi_totalMultiplicity() { return hww.Recoil_j_3_4_leadak4_puppi_totalMultiplicity(); }

}

#include "rooutil/rooutil.cc"
