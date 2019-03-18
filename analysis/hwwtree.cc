#include "hwwtree.h"
hwwtree hww;

void hwwtree::Init(TTree *tree) {
  L_p4_branch = tree->GetBranch("L_p4");
  if (L_p4_branch) L_p4_branch->SetAddress(&L_p4_);
  X_p4_branch = tree->GetBranch("X_p4");
  if (X_p4_branch) X_p4_branch->SetAddress(&X_p4_);
  J_p4_branch = tree->GetBranch("J_p4");
  if (J_p4_branch) J_p4_branch->SetAddress(&J_p4_);
  J_SD_p4_branch = tree->GetBranch("J_SD_p4");
  if (J_SD_p4_branch) J_SD_p4_branch->SetAddress(&J_SD_p4_);
  q0_p4_branch = tree->GetBranch("q0_p4");
  if (q0_p4_branch) q0_p4_branch->SetAddress(&q0_p4_);
  q1_p4_branch = tree->GetBranch("q1_p4");
  if (q1_p4_branch) q1_p4_branch->SetAddress(&q1_p4_);
  V_p4_branch = tree->GetBranch("V_p4");
  if (V_p4_branch) V_p4_branch->SetAddress(&V_p4_);
  LXJ_p4_branch = tree->GetBranch("LXJ_p4");
  if (LXJ_p4_branch) LXJ_p4_branch->SetAddress(&LXJ_p4_);
  LXJ_SD_p4_branch = tree->GetBranch("LXJ_SD_p4");
  if (LXJ_SD_p4_branch) LXJ_SD_p4_branch->SetAddress(&LXJ_SD_p4_);
  neu_p4_branch = tree->GetBranch("neu_p4");
  if (neu_p4_branch) neu_p4_branch->SetAddress(&neu_p4_);
  neu_p4_h_branch = tree->GetBranch("neu_p4_h");
  if (neu_p4_h_branch) neu_p4_h_branch->SetAddress(&neu_p4_h_);
  Wlep_p4_branch = tree->GetBranch("Wlep_p4");
  if (Wlep_p4_branch) Wlep_p4_branch->SetAddress(&Wlep_p4_);
  Wlep_h_p4_branch = tree->GetBranch("Wlep_h_p4");
  if (Wlep_h_p4_branch) Wlep_h_p4_branch->SetAddress(&Wlep_h_p4_);
  H_p4_branch = tree->GetBranch("H_p4");
  if (H_p4_branch) H_p4_branch->SetAddress(&H_p4_);
  H_mh_p4_branch = tree->GetBranch("H_mh_p4");
  if (H_mh_p4_branch) H_mh_p4_branch->SetAddress(&H_mh_p4_);
  R_p4_branch = tree->GetBranch("R_p4");
  if (R_p4_branch) R_p4_branch->SetAddress(&R_p4_);
  R_cent_p4_branch = tree->GetBranch("R_cent_p4");
  if (R_cent_p4_branch) R_cent_p4_branch->SetAddress(&R_cent_p4_);
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
  gen_Vq0_p4_branch = tree->GetBranch("gen_Vq0_p4");
  if (gen_Vq0_p4_branch) gen_Vq0_p4_branch->SetAddress(&gen_Vq0_p4_);
  gen_Vq1_p4_branch = tree->GetBranch("gen_Vq1_p4");
  if (gen_Vq1_p4_branch) gen_Vq1_p4_branch->SetAddress(&gen_Vq1_p4_);
  gen_b0_p4_branch = tree->GetBranch("gen_b0_p4");
  if (gen_b0_p4_branch) gen_b0_p4_branch->SetAddress(&gen_b0_p4_);
  gen_b1_p4_branch = tree->GetBranch("gen_b1_p4");
  if (gen_b1_p4_branch) gen_b1_p4_branch->SetAddress(&gen_b1_p4_);
  gen_t0_p4_branch = tree->GetBranch("gen_t0_p4");
  if (gen_t0_p4_branch) gen_t0_p4_branch->SetAddress(&gen_t0_p4_);
  gen_t1_p4_branch = tree->GetBranch("gen_t1_p4");
  if (gen_t1_p4_branch) gen_t1_p4_branch->SetAddress(&gen_t1_p4_);

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
  gen_ht_branch = tree->GetBranch("gen_ht");
  if (gen_ht_branch) gen_ht_branch->SetAddress(&gen_ht_);
  nvtx_branch = tree->GetBranch("nvtx");
  if (nvtx_branch) nvtx_branch->SetAddress(&nvtx_);
  L_pt_branch = tree->GetBranch("L_pt");
  if (L_pt_branch) L_pt_branch->SetAddress(&L_pt_);
  L_eta_branch = tree->GetBranch("L_eta");
  if (L_eta_branch) L_eta_branch->SetAddress(&L_eta_);
  L_phi_branch = tree->GetBranch("L_phi");
  if (L_phi_branch) L_phi_branch->SetAddress(&L_phi_);
  L_mass_branch = tree->GetBranch("L_mass");
  if (L_mass_branch) L_mass_branch->SetAddress(&L_mass_);
  L_energy_branch = tree->GetBranch("L_energy");
  if (L_energy_branch) L_energy_branch->SetAddress(&L_energy_);
  L_id_branch = tree->GetBranch("L_id");
  if (L_id_branch) L_id_branch->SetAddress(&L_id_);
  L_idx_branch = tree->GetBranch("L_idx");
  if (L_idx_branch) L_idx_branch->SetAddress(&L_idx_);
  L_isTightPOG_branch = tree->GetBranch("L_isTightPOG");
  if (L_isTightPOG_branch) L_isTightPOG_branch->SetAddress(&L_isTightPOG_);
  L_miniIsoEA_branch = tree->GetBranch("L_miniIsoEA");
  if (L_miniIsoEA_branch) L_miniIsoEA_branch->SetAddress(&L_miniIsoEA_);
  L_relIso03EA_branch = tree->GetBranch("L_relIso03EA");
  if (L_relIso03EA_branch) L_relIso03EA_branch->SetAddress(&L_relIso03EA_);
  L_relIso04DB_branch = tree->GetBranch("L_relIso04DB");
  if (L_relIso04DB_branch) L_relIso04DB_branch->SetAddress(&L_relIso04DB_);
  L_relIso0025EA_branch = tree->GetBranch("L_relIso0025EA");
  if (L_relIso0025EA_branch) L_relIso0025EA_branch->SetAddress(&L_relIso0025EA_);
  L_relIso005EA_branch = tree->GetBranch("L_relIso005EA");
  if (L_relIso005EA_branch) L_relIso005EA_branch->SetAddress(&L_relIso005EA_);
  L_relIso01EA_branch = tree->GetBranch("L_relIso01EA");
  if (L_relIso01EA_branch) L_relIso01EA_branch->SetAddress(&L_relIso01EA_);
  L_relIso02EA_branch = tree->GetBranch("L_relIso02EA");
  if (L_relIso02EA_branch) L_relIso02EA_branch->SetAddress(&L_relIso02EA_);
  L_relIso04EA_branch = tree->GetBranch("L_relIso04EA");
  if (L_relIso04EA_branch) L_relIso04EA_branch->SetAddress(&L_relIso04EA_);
  L_relIso08EA_branch = tree->GetBranch("L_relIso08EA");
  if (L_relIso08EA_branch) L_relIso08EA_branch->SetAddress(&L_relIso08EA_);
  L_relIso0025EAwLep_branch = tree->GetBranch("L_relIso0025EAwLep");
  if (L_relIso0025EAwLep_branch) L_relIso0025EAwLep_branch->SetAddress(&L_relIso0025EAwLep_);
  L_relIso005EAwLep_branch = tree->GetBranch("L_relIso005EAwLep");
  if (L_relIso005EAwLep_branch) L_relIso005EAwLep_branch->SetAddress(&L_relIso005EAwLep_);
  L_relIso01EAwLep_branch = tree->GetBranch("L_relIso01EAwLep");
  if (L_relIso01EAwLep_branch) L_relIso01EAwLep_branch->SetAddress(&L_relIso01EAwLep_);
  L_relIso02EAwLep_branch = tree->GetBranch("L_relIso02EAwLep");
  if (L_relIso02EAwLep_branch) L_relIso02EAwLep_branch->SetAddress(&L_relIso02EAwLep_);
  L_relIso04EAwLep_branch = tree->GetBranch("L_relIso04EAwLep");
  if (L_relIso04EAwLep_branch) L_relIso04EAwLep_branch->SetAddress(&L_relIso04EAwLep_);
  L_relIso08EAwLep_branch = tree->GetBranch("L_relIso08EAwLep");
  if (L_relIso08EAwLep_branch) L_relIso08EAwLep_branch->SetAddress(&L_relIso08EAwLep_);
  L_ip3d_branch = tree->GetBranch("L_ip3d");
  if (L_ip3d_branch) L_ip3d_branch->SetAddress(&L_ip3d_);
  L_ip3derr_branch = tree->GetBranch("L_ip3derr");
  if (L_ip3derr_branch) L_ip3derr_branch->SetAddress(&L_ip3derr_);
  L_dxy_branch = tree->GetBranch("L_dxy");
  if (L_dxy_branch) L_dxy_branch->SetAddress(&L_dxy_);
  L_dz_branch = tree->GetBranch("L_dz");
  if (L_dz_branch) L_dz_branch->SetAddress(&L_dz_);
  L_isFromW_branch = tree->GetBranch("L_isFromW");
  if (L_isFromW_branch) L_isFromW_branch->SetAddress(&L_isFromW_);
  X_pt_branch = tree->GetBranch("X_pt");
  if (X_pt_branch) X_pt_branch->SetAddress(&X_pt_);
  X_phi_branch = tree->GetBranch("X_phi");
  if (X_phi_branch) X_phi_branch->SetAddress(&X_phi_);
  X_up_pt_branch = tree->GetBranch("X_up_pt");
  if (X_up_pt_branch) X_up_pt_branch->SetAddress(&X_up_pt_);
  X_up_phi_branch = tree->GetBranch("X_up_phi");
  if (X_up_phi_branch) X_up_phi_branch->SetAddress(&X_up_phi_);
  X_dn_pt_branch = tree->GetBranch("X_dn_pt");
  if (X_dn_pt_branch) X_dn_pt_branch->SetAddress(&X_dn_pt_);
  X_dn_phi_branch = tree->GetBranch("X_dn_phi");
  if (X_dn_phi_branch) X_dn_phi_branch->SetAddress(&X_dn_phi_);
  X_gen_pt_branch = tree->GetBranch("X_gen_pt");
  if (X_gen_pt_branch) X_gen_pt_branch->SetAddress(&X_gen_pt_);
  X_gen_phi_branch = tree->GetBranch("X_gen_phi");
  if (X_gen_phi_branch) X_gen_phi_branch->SetAddress(&X_gen_phi_);
  J_pt_branch = tree->GetBranch("J_pt");
  if (J_pt_branch) J_pt_branch->SetAddress(&J_pt_);
  J_eta_branch = tree->GetBranch("J_eta");
  if (J_eta_branch) J_eta_branch->SetAddress(&J_eta_);
  J_phi_branch = tree->GetBranch("J_phi");
  if (J_phi_branch) J_phi_branch->SetAddress(&J_phi_);
  J_mass_branch = tree->GetBranch("J_mass");
  if (J_mass_branch) J_mass_branch->SetAddress(&J_mass_);
  J_energy_branch = tree->GetBranch("J_energy");
  if (J_energy_branch) J_energy_branch->SetAddress(&J_energy_);
  J_tau31_branch = tree->GetBranch("J_tau31");
  if (J_tau31_branch) J_tau31_branch->SetAddress(&J_tau31_);
  J_tau32_branch = tree->GetBranch("J_tau32");
  if (J_tau32_branch) J_tau32_branch->SetAddress(&J_tau32_);
  J_tau21_branch = tree->GetBranch("J_tau21");
  if (J_tau21_branch) J_tau21_branch->SetAddress(&J_tau21_);
  J_tau1_branch = tree->GetBranch("J_tau1");
  if (J_tau1_branch) J_tau1_branch->SetAddress(&J_tau1_);
  J_tau2_branch = tree->GetBranch("J_tau2");
  if (J_tau2_branch) J_tau2_branch->SetAddress(&J_tau2_);
  J_tau3_branch = tree->GetBranch("J_tau3");
  if (J_tau3_branch) J_tau3_branch->SetAddress(&J_tau3_);
  J_undoJEC_branch = tree->GetBranch("J_undoJEC");
  if (J_undoJEC_branch) J_undoJEC_branch->SetAddress(&J_undoJEC_);
  J_shift_branch = tree->GetBranch("J_shift");
  if (J_shift_branch) J_shift_branch->SetAddress(&J_shift_);
  J_SD_pt_branch = tree->GetBranch("J_SD_pt");
  if (J_SD_pt_branch) J_SD_pt_branch->SetAddress(&J_SD_pt_);
  J_SD_eta_branch = tree->GetBranch("J_SD_eta");
  if (J_SD_eta_branch) J_SD_eta_branch->SetAddress(&J_SD_eta_);
  J_SD_phi_branch = tree->GetBranch("J_SD_phi");
  if (J_SD_phi_branch) J_SD_phi_branch->SetAddress(&J_SD_phi_);
  J_SD_mass_branch = tree->GetBranch("J_SD_mass");
  if (J_SD_mass_branch) J_SD_mass_branch->SetAddress(&J_SD_mass_);
  J_SD_energy_branch = tree->GetBranch("J_SD_energy");
  if (J_SD_energy_branch) J_SD_energy_branch->SetAddress(&J_SD_energy_);
  J_SD_tau31_branch = tree->GetBranch("J_SD_tau31");
  if (J_SD_tau31_branch) J_SD_tau31_branch->SetAddress(&J_SD_tau31_);
  J_SD_tau32_branch = tree->GetBranch("J_SD_tau32");
  if (J_SD_tau32_branch) J_SD_tau32_branch->SetAddress(&J_SD_tau32_);
  J_SD_tau21_branch = tree->GetBranch("J_SD_tau21");
  if (J_SD_tau21_branch) J_SD_tau21_branch->SetAddress(&J_SD_tau21_);
  J_SD_tau1_branch = tree->GetBranch("J_SD_tau1");
  if (J_SD_tau1_branch) J_SD_tau1_branch->SetAddress(&J_SD_tau1_);
  J_SD_tau2_branch = tree->GetBranch("J_SD_tau2");
  if (J_SD_tau2_branch) J_SD_tau2_branch->SetAddress(&J_SD_tau2_);
  J_SD_tau3_branch = tree->GetBranch("J_SD_tau3");
  if (J_SD_tau3_branch) J_SD_tau3_branch->SetAddress(&J_SD_tau3_);
  q0_pt_branch = tree->GetBranch("q0_pt");
  if (q0_pt_branch) q0_pt_branch->SetAddress(&q0_pt_);
  q0_eta_branch = tree->GetBranch("q0_eta");
  if (q0_eta_branch) q0_eta_branch->SetAddress(&q0_eta_);
  q0_phi_branch = tree->GetBranch("q0_phi");
  if (q0_phi_branch) q0_phi_branch->SetAddress(&q0_phi_);
  q0_mass_branch = tree->GetBranch("q0_mass");
  if (q0_mass_branch) q0_mass_branch->SetAddress(&q0_mass_);
  q0_energy_branch = tree->GetBranch("q0_energy");
  if (q0_energy_branch) q0_energy_branch->SetAddress(&q0_energy_);
  q1_pt_branch = tree->GetBranch("q1_pt");
  if (q1_pt_branch) q1_pt_branch->SetAddress(&q1_pt_);
  q1_eta_branch = tree->GetBranch("q1_eta");
  if (q1_eta_branch) q1_eta_branch->SetAddress(&q1_eta_);
  q1_phi_branch = tree->GetBranch("q1_phi");
  if (q1_phi_branch) q1_phi_branch->SetAddress(&q1_phi_);
  q1_mass_branch = tree->GetBranch("q1_mass");
  if (q1_mass_branch) q1_mass_branch->SetAddress(&q1_mass_);
  q1_energy_branch = tree->GetBranch("q1_energy");
  if (q1_energy_branch) q1_energy_branch->SetAddress(&q1_energy_);
  V_pt_branch = tree->GetBranch("V_pt");
  if (V_pt_branch) V_pt_branch->SetAddress(&V_pt_);
  V_eta_branch = tree->GetBranch("V_eta");
  if (V_eta_branch) V_eta_branch->SetAddress(&V_eta_);
  V_phi_branch = tree->GetBranch("V_phi");
  if (V_phi_branch) V_phi_branch->SetAddress(&V_phi_);
  V_mass_branch = tree->GetBranch("V_mass");
  if (V_mass_branch) V_mass_branch->SetAddress(&V_mass_);
  V_energy_branch = tree->GetBranch("V_energy");
  if (V_energy_branch) V_energy_branch->SetAddress(&V_energy_);
  V_SD_mass_branch = tree->GetBranch("V_SD_mass");
  if (V_SD_mass_branch) V_SD_mass_branch->SetAddress(&V_SD_mass_);
  V_tau31_branch = tree->GetBranch("V_tau31");
  if (V_tau31_branch) V_tau31_branch->SetAddress(&V_tau31_);
  V_tau32_branch = tree->GetBranch("V_tau32");
  if (V_tau32_branch) V_tau32_branch->SetAddress(&V_tau32_);
  V_tau21_branch = tree->GetBranch("V_tau21");
  if (V_tau21_branch) V_tau21_branch->SetAddress(&V_tau21_);
  V_tau1_branch = tree->GetBranch("V_tau1");
  if (V_tau1_branch) V_tau1_branch->SetAddress(&V_tau1_);
  V_tau2_branch = tree->GetBranch("V_tau2");
  if (V_tau2_branch) V_tau2_branch->SetAddress(&V_tau2_);
  V_tau3_branch = tree->GetBranch("V_tau3");
  if (V_tau3_branch) V_tau3_branch->SetAddress(&V_tau3_);
  V_undoJEC_branch = tree->GetBranch("V_undoJEC");
  if (V_undoJEC_branch) V_undoJEC_branch->SetAddress(&V_undoJEC_);
  V_shift_branch = tree->GetBranch("V_shift");
  if (V_shift_branch) V_shift_branch->SetAddress(&V_shift_);
  V_deep_rawdisc_h4q_branch = tree->GetBranch("V_deep_rawdisc_h4q");
  if (V_deep_rawdisc_h4q_branch) V_deep_rawdisc_h4q_branch->SetAddress(&V_deep_rawdisc_h4q_);
  V_deep_rawdisc_hbb_branch = tree->GetBranch("V_deep_rawdisc_hbb");
  if (V_deep_rawdisc_hbb_branch) V_deep_rawdisc_hbb_branch->SetAddress(&V_deep_rawdisc_hbb_);
  V_deep_rawdisc_qcd_branch = tree->GetBranch("V_deep_rawdisc_qcd");
  if (V_deep_rawdisc_qcd_branch) V_deep_rawdisc_qcd_branch->SetAddress(&V_deep_rawdisc_qcd_);
  V_deep_rawdisc_top_branch = tree->GetBranch("V_deep_rawdisc_top");
  if (V_deep_rawdisc_top_branch) V_deep_rawdisc_top_branch->SetAddress(&V_deep_rawdisc_top_);
  V_deep_rawdisc_w_branch = tree->GetBranch("V_deep_rawdisc_w");
  if (V_deep_rawdisc_w_branch) V_deep_rawdisc_w_branch->SetAddress(&V_deep_rawdisc_w_);
  V_deep_rawdisc_z_branch = tree->GetBranch("V_deep_rawdisc_z");
  if (V_deep_rawdisc_z_branch) V_deep_rawdisc_z_branch->SetAddress(&V_deep_rawdisc_z_);
  V_deep_rawdisc_zbb_branch = tree->GetBranch("V_deep_rawdisc_zbb");
  if (V_deep_rawdisc_zbb_branch) V_deep_rawdisc_zbb_branch->SetAddress(&V_deep_rawdisc_zbb_);
  V_softdropPuppiSubjet1_pt_branch = tree->GetBranch("V_softdropPuppiSubjet1_pt");
  if (V_softdropPuppiSubjet1_pt_branch) V_softdropPuppiSubjet1_pt_branch->SetAddress(&V_softdropPuppiSubjet1_pt_);
  V_softdropPuppiSubjet1_eta_branch = tree->GetBranch("V_softdropPuppiSubjet1_eta");
  if (V_softdropPuppiSubjet1_eta_branch) V_softdropPuppiSubjet1_eta_branch->SetAddress(&V_softdropPuppiSubjet1_eta_);
  V_softdropPuppiSubjet1_phi_branch = tree->GetBranch("V_softdropPuppiSubjet1_phi");
  if (V_softdropPuppiSubjet1_phi_branch) V_softdropPuppiSubjet1_phi_branch->SetAddress(&V_softdropPuppiSubjet1_phi_);
  V_softdropPuppiSubjet1_mass_branch = tree->GetBranch("V_softdropPuppiSubjet1_mass");
  if (V_softdropPuppiSubjet1_mass_branch) V_softdropPuppiSubjet1_mass_branch->SetAddress(&V_softdropPuppiSubjet1_mass_);
  V_softdropPuppiSubjet1_energy_branch = tree->GetBranch("V_softdropPuppiSubjet1_energy");
  if (V_softdropPuppiSubjet1_energy_branch) V_softdropPuppiSubjet1_energy_branch->SetAddress(&V_softdropPuppiSubjet1_energy_);
  V_softdropPuppiSubjet2_pt_branch = tree->GetBranch("V_softdropPuppiSubjet2_pt");
  if (V_softdropPuppiSubjet2_pt_branch) V_softdropPuppiSubjet2_pt_branch->SetAddress(&V_softdropPuppiSubjet2_pt_);
  V_softdropPuppiSubjet2_eta_branch = tree->GetBranch("V_softdropPuppiSubjet2_eta");
  if (V_softdropPuppiSubjet2_eta_branch) V_softdropPuppiSubjet2_eta_branch->SetAddress(&V_softdropPuppiSubjet2_eta_);
  V_softdropPuppiSubjet2_phi_branch = tree->GetBranch("V_softdropPuppiSubjet2_phi");
  if (V_softdropPuppiSubjet2_phi_branch) V_softdropPuppiSubjet2_phi_branch->SetAddress(&V_softdropPuppiSubjet2_phi_);
  V_softdropPuppiSubjet2_mass_branch = tree->GetBranch("V_softdropPuppiSubjet2_mass");
  if (V_softdropPuppiSubjet2_mass_branch) V_softdropPuppiSubjet2_mass_branch->SetAddress(&V_softdropPuppiSubjet2_mass_);
  V_softdropPuppiSubjet2_energy_branch = tree->GetBranch("V_softdropPuppiSubjet2_energy");
  if (V_softdropPuppiSubjet2_energy_branch) V_softdropPuppiSubjet2_energy_branch->SetAddress(&V_softdropPuppiSubjet2_energy_);
  LXJ_pt_branch = tree->GetBranch("LXJ_pt");
  if (LXJ_pt_branch) LXJ_pt_branch->SetAddress(&LXJ_pt_);
  LXJ_eta_branch = tree->GetBranch("LXJ_eta");
  if (LXJ_eta_branch) LXJ_eta_branch->SetAddress(&LXJ_eta_);
  LXJ_phi_branch = tree->GetBranch("LXJ_phi");
  if (LXJ_phi_branch) LXJ_phi_branch->SetAddress(&LXJ_phi_);
  LXJ_mass_branch = tree->GetBranch("LXJ_mass");
  if (LXJ_mass_branch) LXJ_mass_branch->SetAddress(&LXJ_mass_);
  LXJ_energy_branch = tree->GetBranch("LXJ_energy");
  if (LXJ_energy_branch) LXJ_energy_branch->SetAddress(&LXJ_energy_);
  LXJ_SD_pt_branch = tree->GetBranch("LXJ_SD_pt");
  if (LXJ_SD_pt_branch) LXJ_SD_pt_branch->SetAddress(&LXJ_SD_pt_);
  LXJ_SD_eta_branch = tree->GetBranch("LXJ_SD_eta");
  if (LXJ_SD_eta_branch) LXJ_SD_eta_branch->SetAddress(&LXJ_SD_eta_);
  LXJ_SD_phi_branch = tree->GetBranch("LXJ_SD_phi");
  if (LXJ_SD_phi_branch) LXJ_SD_phi_branch->SetAddress(&LXJ_SD_phi_);
  LXJ_SD_mass_branch = tree->GetBranch("LXJ_SD_mass");
  if (LXJ_SD_mass_branch) LXJ_SD_mass_branch->SetAddress(&LXJ_SD_mass_);
  LXJ_SD_energy_branch = tree->GetBranch("LXJ_SD_energy");
  if (LXJ_SD_energy_branch) LXJ_SD_energy_branch->SetAddress(&LXJ_SD_energy_);
  LX_pt_branch = tree->GetBranch("LX_pt");
  if (LX_pt_branch) LX_pt_branch->SetAddress(&LX_pt_);
  LX_mt_branch = tree->GetBranch("LX_mt");
  if (LX_mt_branch) LX_mt_branch->SetAddress(&LX_mt_);
  LX_mass_branch = tree->GetBranch("LX_mass");
  if (LX_mass_branch) LX_mass_branch->SetAddress(&LX_mass_);
  LX_dphi_branch = tree->GetBranch("LX_dphi");
  if (LX_dphi_branch) LX_dphi_branch->SetAddress(&LX_dphi_);
  LJ_pt_branch = tree->GetBranch("LJ_pt");
  if (LJ_pt_branch) LJ_pt_branch->SetAddress(&LJ_pt_);
  LJ_mt_branch = tree->GetBranch("LJ_mt");
  if (LJ_mt_branch) LJ_mt_branch->SetAddress(&LJ_mt_);
  LJ_mass_branch = tree->GetBranch("LJ_mass");
  if (LJ_mass_branch) LJ_mass_branch->SetAddress(&LJ_mass_);
  LJ_dphi_branch = tree->GetBranch("LJ_dphi");
  if (LJ_dphi_branch) LJ_dphi_branch->SetAddress(&LJ_dphi_);
  LJ_deta_branch = tree->GetBranch("LJ_deta");
  if (LJ_deta_branch) LJ_deta_branch->SetAddress(&LJ_deta_);
  LJ_dr_branch = tree->GetBranch("LJ_dr");
  if (LJ_dr_branch) LJ_dr_branch->SetAddress(&LJ_dr_);
  LJ_dptf_branch = tree->GetBranch("LJ_dptf");
  if (LJ_dptf_branch) LJ_dptf_branch->SetAddress(&LJ_dptf_);
  LJ_SD_pt_branch = tree->GetBranch("LJ_SD_pt");
  if (LJ_SD_pt_branch) LJ_SD_pt_branch->SetAddress(&LJ_SD_pt_);
  LJ_SD_mt_branch = tree->GetBranch("LJ_SD_mt");
  if (LJ_SD_mt_branch) LJ_SD_mt_branch->SetAddress(&LJ_SD_mt_);
  LJ_SD_mass_branch = tree->GetBranch("LJ_SD_mass");
  if (LJ_SD_mass_branch) LJ_SD_mass_branch->SetAddress(&LJ_SD_mass_);
  LJ_SD_dphi_branch = tree->GetBranch("LJ_SD_dphi");
  if (LJ_SD_dphi_branch) LJ_SD_dphi_branch->SetAddress(&LJ_SD_dphi_);
  LJ_SD_deta_branch = tree->GetBranch("LJ_SD_deta");
  if (LJ_SD_deta_branch) LJ_SD_deta_branch->SetAddress(&LJ_SD_deta_);
  LJ_SD_dr_branch = tree->GetBranch("LJ_SD_dr");
  if (LJ_SD_dr_branch) LJ_SD_dr_branch->SetAddress(&LJ_SD_dr_);
  LJ_SD_dptf_branch = tree->GetBranch("LJ_SD_dptf");
  if (LJ_SD_dptf_branch) LJ_SD_dptf_branch->SetAddress(&LJ_SD_dptf_);
  Lq0_pt_branch = tree->GetBranch("Lq0_pt");
  if (Lq0_pt_branch) Lq0_pt_branch->SetAddress(&Lq0_pt_);
  Lq0_mt_branch = tree->GetBranch("Lq0_mt");
  if (Lq0_mt_branch) Lq0_mt_branch->SetAddress(&Lq0_mt_);
  Lq0_mass_branch = tree->GetBranch("Lq0_mass");
  if (Lq0_mass_branch) Lq0_mass_branch->SetAddress(&Lq0_mass_);
  Lq0_dphi_branch = tree->GetBranch("Lq0_dphi");
  if (Lq0_dphi_branch) Lq0_dphi_branch->SetAddress(&Lq0_dphi_);
  Lq0_deta_branch = tree->GetBranch("Lq0_deta");
  if (Lq0_deta_branch) Lq0_deta_branch->SetAddress(&Lq0_deta_);
  Lq0_dr_branch = tree->GetBranch("Lq0_dr");
  if (Lq0_dr_branch) Lq0_dr_branch->SetAddress(&Lq0_dr_);
  Lq0_dptf_branch = tree->GetBranch("Lq0_dptf");
  if (Lq0_dptf_branch) Lq0_dptf_branch->SetAddress(&Lq0_dptf_);
  Lq1_pt_branch = tree->GetBranch("Lq1_pt");
  if (Lq1_pt_branch) Lq1_pt_branch->SetAddress(&Lq1_pt_);
  Lq1_mt_branch = tree->GetBranch("Lq1_mt");
  if (Lq1_mt_branch) Lq1_mt_branch->SetAddress(&Lq1_mt_);
  Lq1_mass_branch = tree->GetBranch("Lq1_mass");
  if (Lq1_mass_branch) Lq1_mass_branch->SetAddress(&Lq1_mass_);
  Lq1_dphi_branch = tree->GetBranch("Lq1_dphi");
  if (Lq1_dphi_branch) Lq1_dphi_branch->SetAddress(&Lq1_dphi_);
  Lq1_deta_branch = tree->GetBranch("Lq1_deta");
  if (Lq1_deta_branch) Lq1_deta_branch->SetAddress(&Lq1_deta_);
  Lq1_dr_branch = tree->GetBranch("Lq1_dr");
  if (Lq1_dr_branch) Lq1_dr_branch->SetAddress(&Lq1_dr_);
  Lq1_dptf_branch = tree->GetBranch("Lq1_dptf");
  if (Lq1_dptf_branch) Lq1_dptf_branch->SetAddress(&Lq1_dptf_);
  Lqmax_pt_branch = tree->GetBranch("Lqmax_pt");
  if (Lqmax_pt_branch) Lqmax_pt_branch->SetAddress(&Lqmax_pt_);
  Lqmax_mt_branch = tree->GetBranch("Lqmax_mt");
  if (Lqmax_mt_branch) Lqmax_mt_branch->SetAddress(&Lqmax_mt_);
  Lqmax_mass_branch = tree->GetBranch("Lqmax_mass");
  if (Lqmax_mass_branch) Lqmax_mass_branch->SetAddress(&Lqmax_mass_);
  Lqmax_dphi_branch = tree->GetBranch("Lqmax_dphi");
  if (Lqmax_dphi_branch) Lqmax_dphi_branch->SetAddress(&Lqmax_dphi_);
  Lqmax_deta_branch = tree->GetBranch("Lqmax_deta");
  if (Lqmax_deta_branch) Lqmax_deta_branch->SetAddress(&Lqmax_deta_);
  Lqmax_dr_branch = tree->GetBranch("Lqmax_dr");
  if (Lqmax_dr_branch) Lqmax_dr_branch->SetAddress(&Lqmax_dr_);
  Lqmax_dptf_branch = tree->GetBranch("Lqmax_dptf");
  if (Lqmax_dptf_branch) Lqmax_dptf_branch->SetAddress(&Lqmax_dptf_);
  LHRatio_branch = tree->GetBranch("LHRatio");
  if (LHRatio_branch) LHRatio_branch->SetAddress(&LHRatio_);
  LHRatio_SD_branch = tree->GetBranch("LHRatio_SD");
  if (LHRatio_SD_branch) LHRatio_SD_branch->SetAddress(&LHRatio_SD_);
  det_branch = tree->GetBranch("det");
  if (det_branch) det_branch->SetAddress(&det_);
  detW_branch = tree->GetBranch("detW");
  if (detW_branch) detW_branch->SetAddress(&detW_);
  mH_branch = tree->GetBranch("mH");
  if (mH_branch) mH_branch->SetAddress(&mH_);
  mD_branch = tree->GetBranch("mD");
  if (mD_branch) mD_branch->SetAddress(&mD_);
  mD_SD_branch = tree->GetBranch("mD_SD");
  if (mD_SD_branch) mD_SD_branch->SetAddress(&mD_SD_);
  mD_Wlep_branch = tree->GetBranch("mD_Wlep");
  if (mD_Wlep_branch) mD_Wlep_branch->SetAddress(&mD_Wlep_);
  j_dphis_branch = tree->GetBranch("j_dphis");
  if (j_dphis_branch) j_dphis_branch->SetAddress(&j_dphis_);
  j_drs_branch = tree->GetBranch("j_drs");
  if (j_drs_branch) j_drs_branch->SetAddress(&j_drs_);
  j_SD_dphis_branch = tree->GetBranch("j_SD_dphis");
  if (j_SD_dphis_branch) j_SD_dphis_branch->SetAddress(&j_SD_dphis_);
  j_SD_drs_branch = tree->GetBranch("j_SD_drs");
  if (j_SD_drs_branch) j_SD_drs_branch->SetAddress(&j_SD_drs_);
  j_pts_branch = tree->GetBranch("j_pts");
  if (j_pts_branch) j_pts_branch->SetAddress(&j_pts_);
  nj_branch = tree->GetBranch("nj");
  if (nj_branch) nj_branch->SetAddress(&nj_);
  nj_in_branch = tree->GetBranch("nj_in");
  if (nj_in_branch) nj_in_branch->SetAddress(&nj_in_);
  nj_annuli_branch = tree->GetBranch("nj_annuli");
  if (nj_annuli_branch) nj_annuli_branch->SetAddress(&nj_annuli_);
  nj_same_branch = tree->GetBranch("nj_same");
  if (nj_same_branch) nj_same_branch->SetAddress(&nj_same_);
  nj_away_branch = tree->GetBranch("nj_away");
  if (nj_away_branch) nj_away_branch->SetAddress(&nj_away_);
  nj_SD_in_branch = tree->GetBranch("nj_SD_in");
  if (nj_SD_in_branch) nj_SD_in_branch->SetAddress(&nj_SD_in_);
  nj_SD_annuli_branch = tree->GetBranch("nj_SD_annuli");
  if (nj_SD_annuli_branch) nj_SD_annuli_branch->SetAddress(&nj_SD_annuli_);
  nj_SD_same_branch = tree->GetBranch("nj_SD_same");
  if (nj_SD_same_branch) nj_SD_same_branch->SetAddress(&nj_SD_same_);
  nj_SD_away_branch = tree->GetBranch("nj_SD_away");
  if (nj_SD_away_branch) nj_SD_away_branch->SetAddress(&nj_SD_away_);
  nb_branch = tree->GetBranch("nb");
  if (nb_branch) nb_branch->SetAddress(&nb_);
  nb_in_branch = tree->GetBranch("nb_in");
  if (nb_in_branch) nb_in_branch->SetAddress(&nb_in_);
  nb_annuli_branch = tree->GetBranch("nb_annuli");
  if (nb_annuli_branch) nb_annuli_branch->SetAddress(&nb_annuli_);
  nb_same_branch = tree->GetBranch("nb_same");
  if (nb_same_branch) nb_same_branch->SetAddress(&nb_same_);
  nb_away_branch = tree->GetBranch("nb_away");
  if (nb_away_branch) nb_away_branch->SetAddress(&nb_away_);
  nb_SD_in_branch = tree->GetBranch("nb_SD_in");
  if (nb_SD_in_branch) nb_SD_in_branch->SetAddress(&nb_SD_in_);
  nb_SD_annuli_branch = tree->GetBranch("nb_SD_annuli");
  if (nb_SD_annuli_branch) nb_SD_annuli_branch->SetAddress(&nb_SD_annuli_);
  nb_SD_same_branch = tree->GetBranch("nb_SD_same");
  if (nb_SD_same_branch) nb_SD_same_branch->SetAddress(&nb_SD_same_);
  nb_SD_away_branch = tree->GetBranch("nb_SD_away");
  if (nb_SD_away_branch) nb_SD_away_branch->SetAddress(&nb_SD_away_);
  nbmed_branch = tree->GetBranch("nbmed");
  if (nbmed_branch) nbmed_branch->SetAddress(&nbmed_);
  nbmed_in_branch = tree->GetBranch("nbmed_in");
  if (nbmed_in_branch) nbmed_in_branch->SetAddress(&nbmed_in_);
  nbmed_annuli_branch = tree->GetBranch("nbmed_annuli");
  if (nbmed_annuli_branch) nbmed_annuli_branch->SetAddress(&nbmed_annuli_);
  nbmed_same_branch = tree->GetBranch("nbmed_same");
  if (nbmed_same_branch) nbmed_same_branch->SetAddress(&nbmed_same_);
  nbmed_away_branch = tree->GetBranch("nbmed_away");
  if (nbmed_away_branch) nbmed_away_branch->SetAddress(&nbmed_away_);
  nbmed_SD_in_branch = tree->GetBranch("nbmed_SD_in");
  if (nbmed_SD_in_branch) nbmed_SD_in_branch->SetAddress(&nbmed_SD_in_);
  nbmed_SD_annuli_branch = tree->GetBranch("nbmed_SD_annuli");
  if (nbmed_SD_annuli_branch) nbmed_SD_annuli_branch->SetAddress(&nbmed_SD_annuli_);
  nbmed_SD_same_branch = tree->GetBranch("nbmed_SD_same");
  if (nbmed_SD_same_branch) nbmed_SD_same_branch->SetAddress(&nbmed_SD_same_);
  nbmed_SD_away_branch = tree->GetBranch("nbmed_SD_away");
  if (nbmed_SD_away_branch) nbmed_SD_away_branch->SetAddress(&nbmed_SD_away_);
  nbtight_branch = tree->GetBranch("nbtight");
  if (nbtight_branch) nbtight_branch->SetAddress(&nbtight_);
  nbtight_in_branch = tree->GetBranch("nbtight_in");
  if (nbtight_in_branch) nbtight_in_branch->SetAddress(&nbtight_in_);
  nbtight_annuli_branch = tree->GetBranch("nbtight_annuli");
  if (nbtight_annuli_branch) nbtight_annuli_branch->SetAddress(&nbtight_annuli_);
  nbtight_same_branch = tree->GetBranch("nbtight_same");
  if (nbtight_same_branch) nbtight_same_branch->SetAddress(&nbtight_same_);
  nbtight_away_branch = tree->GetBranch("nbtight_away");
  if (nbtight_away_branch) nbtight_away_branch->SetAddress(&nbtight_away_);
  nbtight_SD_in_branch = tree->GetBranch("nbtight_SD_in");
  if (nbtight_SD_in_branch) nbtight_SD_in_branch->SetAddress(&nbtight_SD_in_);
  nbtight_SD_annuli_branch = tree->GetBranch("nbtight_SD_annuli");
  if (nbtight_SD_annuli_branch) nbtight_SD_annuli_branch->SetAddress(&nbtight_SD_annuli_);
  nbtight_SD_same_branch = tree->GetBranch("nbtight_SD_same");
  if (nbtight_SD_same_branch) nbtight_SD_same_branch->SetAddress(&nbtight_SD_same_);
  nbtight_SD_away_branch = tree->GetBranch("nbtight_SD_away");
  if (nbtight_SD_away_branch) nbtight_SD_away_branch->SetAddress(&nbtight_SD_away_);
  ht_branch = tree->GetBranch("ht");
  if (ht_branch) ht_branch->SetAddress(&ht_);
  ht_in_branch = tree->GetBranch("ht_in");
  if (ht_in_branch) ht_in_branch->SetAddress(&ht_in_);
  ht_annuli_branch = tree->GetBranch("ht_annuli");
  if (ht_annuli_branch) ht_annuli_branch->SetAddress(&ht_annuli_);
  ht_same_branch = tree->GetBranch("ht_same");
  if (ht_same_branch) ht_same_branch->SetAddress(&ht_same_);
  ht_away_branch = tree->GetBranch("ht_away");
  if (ht_away_branch) ht_away_branch->SetAddress(&ht_away_);
  ht_SD_in_branch = tree->GetBranch("ht_SD_in");
  if (ht_SD_in_branch) ht_SD_in_branch->SetAddress(&ht_SD_in_);
  ht_SD_annuli_branch = tree->GetBranch("ht_SD_annuli");
  if (ht_SD_annuli_branch) ht_SD_annuli_branch->SetAddress(&ht_SD_annuli_);
  ht_SD_same_branch = tree->GetBranch("ht_SD_same");
  if (ht_SD_same_branch) ht_SD_same_branch->SetAddress(&ht_SD_same_);
  ht_SD_away_branch = tree->GetBranch("ht_SD_away");
  if (ht_SD_away_branch) ht_SD_away_branch->SetAddress(&ht_SD_away_);
  R_pt_branch = tree->GetBranch("R_pt");
  if (R_pt_branch) R_pt_branch->SetAddress(&R_pt_);
  R_eta_branch = tree->GetBranch("R_eta");
  if (R_eta_branch) R_eta_branch->SetAddress(&R_eta_);
  R_phi_branch = tree->GetBranch("R_phi");
  if (R_phi_branch) R_phi_branch->SetAddress(&R_phi_);
  R_mass_branch = tree->GetBranch("R_mass");
  if (R_mass_branch) R_mass_branch->SetAddress(&R_mass_);
  R_energy_branch = tree->GetBranch("R_energy");
  if (R_energy_branch) R_energy_branch->SetAddress(&R_energy_);
  R_cent_pt_branch = tree->GetBranch("R_cent_pt");
  if (R_cent_pt_branch) R_cent_pt_branch->SetAddress(&R_cent_pt_);
  R_cent_eta_branch = tree->GetBranch("R_cent_eta");
  if (R_cent_eta_branch) R_cent_eta_branch->SetAddress(&R_cent_eta_);
  R_cent_phi_branch = tree->GetBranch("R_cent_phi");
  if (R_cent_phi_branch) R_cent_phi_branch->SetAddress(&R_cent_phi_);
  R_cent_mass_branch = tree->GetBranch("R_cent_mass");
  if (R_cent_mass_branch) R_cent_mass_branch->SetAddress(&R_cent_mass_);
  R_cent_energy_branch = tree->GetBranch("R_cent_energy");
  if (R_cent_energy_branch) R_cent_energy_branch->SetAddress(&R_cent_energy_);
  gen_recoil_id_branch = tree->GetBranch("gen_recoil_id");
  if (gen_recoil_id_branch) gen_recoil_id_branch->SetAddress(&gen_recoil_id_);
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
  gen_b0_pt_branch = tree->GetBranch("gen_b0_pt");
  if (gen_b0_pt_branch) gen_b0_pt_branch->SetAddress(&gen_b0_pt_);
  gen_b0_eta_branch = tree->GetBranch("gen_b0_eta");
  if (gen_b0_eta_branch) gen_b0_eta_branch->SetAddress(&gen_b0_eta_);
  gen_b0_phi_branch = tree->GetBranch("gen_b0_phi");
  if (gen_b0_phi_branch) gen_b0_phi_branch->SetAddress(&gen_b0_phi_);
  gen_b0_mass_branch = tree->GetBranch("gen_b0_mass");
  if (gen_b0_mass_branch) gen_b0_mass_branch->SetAddress(&gen_b0_mass_);
  gen_b0_energy_branch = tree->GetBranch("gen_b0_energy");
  if (gen_b0_energy_branch) gen_b0_energy_branch->SetAddress(&gen_b0_energy_);
  gen_b1_pt_branch = tree->GetBranch("gen_b1_pt");
  if (gen_b1_pt_branch) gen_b1_pt_branch->SetAddress(&gen_b1_pt_);
  gen_b1_eta_branch = tree->GetBranch("gen_b1_eta");
  if (gen_b1_eta_branch) gen_b1_eta_branch->SetAddress(&gen_b1_eta_);
  gen_b1_phi_branch = tree->GetBranch("gen_b1_phi");
  if (gen_b1_phi_branch) gen_b1_phi_branch->SetAddress(&gen_b1_phi_);
  gen_b1_mass_branch = tree->GetBranch("gen_b1_mass");
  if (gen_b1_mass_branch) gen_b1_mass_branch->SetAddress(&gen_b1_mass_);
  gen_b1_energy_branch = tree->GetBranch("gen_b1_energy");
  if (gen_b1_energy_branch) gen_b1_energy_branch->SetAddress(&gen_b1_energy_);
  gen_t0_pt_branch = tree->GetBranch("gen_t0_pt");
  if (gen_t0_pt_branch) gen_t0_pt_branch->SetAddress(&gen_t0_pt_);
  gen_t0_eta_branch = tree->GetBranch("gen_t0_eta");
  if (gen_t0_eta_branch) gen_t0_eta_branch->SetAddress(&gen_t0_eta_);
  gen_t0_phi_branch = tree->GetBranch("gen_t0_phi");
  if (gen_t0_phi_branch) gen_t0_phi_branch->SetAddress(&gen_t0_phi_);
  gen_t0_mass_branch = tree->GetBranch("gen_t0_mass");
  if (gen_t0_mass_branch) gen_t0_mass_branch->SetAddress(&gen_t0_mass_);
  gen_t0_energy_branch = tree->GetBranch("gen_t0_energy");
  if (gen_t0_energy_branch) gen_t0_energy_branch->SetAddress(&gen_t0_energy_);
  gen_t1_pt_branch = tree->GetBranch("gen_t1_pt");
  if (gen_t1_pt_branch) gen_t1_pt_branch->SetAddress(&gen_t1_pt_);
  gen_t1_eta_branch = tree->GetBranch("gen_t1_eta");
  if (gen_t1_eta_branch) gen_t1_eta_branch->SetAddress(&gen_t1_eta_);
  gen_t1_phi_branch = tree->GetBranch("gen_t1_phi");
  if (gen_t1_phi_branch) gen_t1_phi_branch->SetAddress(&gen_t1_phi_);
  gen_t1_mass_branch = tree->GetBranch("gen_t1_mass");
  if (gen_t1_mass_branch) gen_t1_mass_branch->SetAddress(&gen_t1_mass_);
  gen_t1_energy_branch = tree->GetBranch("gen_t1_energy");
  if (gen_t1_energy_branch) gen_t1_energy_branch->SetAddress(&gen_t1_energy_);
  gen_b0_dr_branch = tree->GetBranch("gen_b0_dr");
  if (gen_b0_dr_branch) gen_b0_dr_branch->SetAddress(&gen_b0_dr_);
  gen_b0_in_branch = tree->GetBranch("gen_b0_in");
  if (gen_b0_in_branch) gen_b0_in_branch->SetAddress(&gen_b0_in_);
  gen_b0_annuli_branch = tree->GetBranch("gen_b0_annuli");
  if (gen_b0_annuli_branch) gen_b0_annuli_branch->SetAddress(&gen_b0_annuli_);
  gen_b0_same_branch = tree->GetBranch("gen_b0_same");
  if (gen_b0_same_branch) gen_b0_same_branch->SetAddress(&gen_b0_same_);
  gen_b0_away_branch = tree->GetBranch("gen_b0_away");
  if (gen_b0_away_branch) gen_b0_away_branch->SetAddress(&gen_b0_away_);
  gen_b1_dr_branch = tree->GetBranch("gen_b1_dr");
  if (gen_b1_dr_branch) gen_b1_dr_branch->SetAddress(&gen_b1_dr_);
  gen_b1_in_branch = tree->GetBranch("gen_b1_in");
  if (gen_b1_in_branch) gen_b1_in_branch->SetAddress(&gen_b1_in_);
  gen_b1_annuli_branch = tree->GetBranch("gen_b1_annuli");
  if (gen_b1_annuli_branch) gen_b1_annuli_branch->SetAddress(&gen_b1_annuli_);
  gen_b1_same_branch = tree->GetBranch("gen_b1_same");
  if (gen_b1_same_branch) gen_b1_same_branch->SetAddress(&gen_b1_same_);
  gen_b1_away_branch = tree->GetBranch("gen_b1_away");
  if (gen_b1_away_branch) gen_b1_away_branch->SetAddress(&gen_b1_away_);
  gen_b0_SD_dr_branch = tree->GetBranch("gen_b0_SD_dr");
  if (gen_b0_SD_dr_branch) gen_b0_SD_dr_branch->SetAddress(&gen_b0_SD_dr_);
  gen_b0_SD_in_branch = tree->GetBranch("gen_b0_SD_in");
  if (gen_b0_SD_in_branch) gen_b0_SD_in_branch->SetAddress(&gen_b0_SD_in_);
  gen_b0_SD_annuli_branch = tree->GetBranch("gen_b0_SD_annuli");
  if (gen_b0_SD_annuli_branch) gen_b0_SD_annuli_branch->SetAddress(&gen_b0_SD_annuli_);
  gen_b0_SD_same_branch = tree->GetBranch("gen_b0_SD_same");
  if (gen_b0_SD_same_branch) gen_b0_SD_same_branch->SetAddress(&gen_b0_SD_same_);
  gen_b0_SD_away_branch = tree->GetBranch("gen_b0_SD_away");
  if (gen_b0_SD_away_branch) gen_b0_SD_away_branch->SetAddress(&gen_b0_SD_away_);
  gen_b1_SD_dr_branch = tree->GetBranch("gen_b1_SD_dr");
  if (gen_b1_SD_dr_branch) gen_b1_SD_dr_branch->SetAddress(&gen_b1_SD_dr_);
  gen_b1_SD_in_branch = tree->GetBranch("gen_b1_SD_in");
  if (gen_b1_SD_in_branch) gen_b1_SD_in_branch->SetAddress(&gen_b1_SD_in_);
  gen_b1_SD_annuli_branch = tree->GetBranch("gen_b1_SD_annuli");
  if (gen_b1_SD_annuli_branch) gen_b1_SD_annuli_branch->SetAddress(&gen_b1_SD_annuli_);
  gen_b1_SD_same_branch = tree->GetBranch("gen_b1_SD_same");
  if (gen_b1_SD_same_branch) gen_b1_SD_same_branch->SetAddress(&gen_b1_SD_same_);
  gen_b1_SD_away_branch = tree->GetBranch("gen_b1_SD_away");
  if (gen_b1_SD_away_branch) gen_b1_SD_away_branch->SetAddress(&gen_b1_SD_away_);
  gen_t0_dr_branch = tree->GetBranch("gen_t0_dr");
  if (gen_t0_dr_branch) gen_t0_dr_branch->SetAddress(&gen_t0_dr_);
  gen_t0_in_branch = tree->GetBranch("gen_t0_in");
  if (gen_t0_in_branch) gen_t0_in_branch->SetAddress(&gen_t0_in_);
  gen_t0_annuli_branch = tree->GetBranch("gen_t0_annuli");
  if (gen_t0_annuli_branch) gen_t0_annuli_branch->SetAddress(&gen_t0_annuli_);
  gen_t0_same_branch = tree->GetBranch("gen_t0_same");
  if (gen_t0_same_branch) gen_t0_same_branch->SetAddress(&gen_t0_same_);
  gen_t0_away_branch = tree->GetBranch("gen_t0_away");
  if (gen_t0_away_branch) gen_t0_away_branch->SetAddress(&gen_t0_away_);
  gen_t1_dr_branch = tree->GetBranch("gen_t1_dr");
  if (gen_t1_dr_branch) gen_t1_dr_branch->SetAddress(&gen_t1_dr_);
  gen_t1_in_branch = tree->GetBranch("gen_t1_in");
  if (gen_t1_in_branch) gen_t1_in_branch->SetAddress(&gen_t1_in_);
  gen_t1_annuli_branch = tree->GetBranch("gen_t1_annuli");
  if (gen_t1_annuli_branch) gen_t1_annuli_branch->SetAddress(&gen_t1_annuli_);
  gen_t1_same_branch = tree->GetBranch("gen_t1_same");
  if (gen_t1_same_branch) gen_t1_same_branch->SetAddress(&gen_t1_same_);
  gen_t1_away_branch = tree->GetBranch("gen_t1_away");
  if (gen_t1_away_branch) gen_t1_away_branch->SetAddress(&gen_t1_away_);
  gen_t0_SD_dr_branch = tree->GetBranch("gen_t0_SD_dr");
  if (gen_t0_SD_dr_branch) gen_t0_SD_dr_branch->SetAddress(&gen_t0_SD_dr_);
  gen_t0_SD_in_branch = tree->GetBranch("gen_t0_SD_in");
  if (gen_t0_SD_in_branch) gen_t0_SD_in_branch->SetAddress(&gen_t0_SD_in_);
  gen_t0_SD_annuli_branch = tree->GetBranch("gen_t0_SD_annuli");
  if (gen_t0_SD_annuli_branch) gen_t0_SD_annuli_branch->SetAddress(&gen_t0_SD_annuli_);
  gen_t0_SD_same_branch = tree->GetBranch("gen_t0_SD_same");
  if (gen_t0_SD_same_branch) gen_t0_SD_same_branch->SetAddress(&gen_t0_SD_same_);
  gen_t0_SD_away_branch = tree->GetBranch("gen_t0_SD_away");
  if (gen_t0_SD_away_branch) gen_t0_SD_away_branch->SetAddress(&gen_t0_SD_away_);
  gen_t1_SD_dr_branch = tree->GetBranch("gen_t1_SD_dr");
  if (gen_t1_SD_dr_branch) gen_t1_SD_dr_branch->SetAddress(&gen_t1_SD_dr_);
  gen_t1_SD_in_branch = tree->GetBranch("gen_t1_SD_in");
  if (gen_t1_SD_in_branch) gen_t1_SD_in_branch->SetAddress(&gen_t1_SD_in_);
  gen_t1_SD_annuli_branch = tree->GetBranch("gen_t1_SD_annuli");
  if (gen_t1_SD_annuli_branch) gen_t1_SD_annuli_branch->SetAddress(&gen_t1_SD_annuli_);
  gen_t1_SD_same_branch = tree->GetBranch("gen_t1_SD_same");
  if (gen_t1_SD_same_branch) gen_t1_SD_same_branch->SetAddress(&gen_t1_SD_same_);
  gen_t1_SD_away_branch = tree->GetBranch("gen_t1_SD_away");
  if (gen_t1_SD_away_branch) gen_t1_SD_away_branch->SetAddress(&gen_t1_SD_away_);

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
  gen_ht_isLoaded = false;
  nvtx_isLoaded = false;
  L_p4_isLoaded = false;
  L_pt_isLoaded = false;
  L_eta_isLoaded = false;
  L_phi_isLoaded = false;
  L_mass_isLoaded = false;
  L_energy_isLoaded = false;
  L_id_isLoaded = false;
  L_idx_isLoaded = false;
  L_isTightPOG_isLoaded = false;
  L_miniIsoEA_isLoaded = false;
  L_relIso03EA_isLoaded = false;
  L_relIso04DB_isLoaded = false;
  L_relIso0025EA_isLoaded = false;
  L_relIso005EA_isLoaded = false;
  L_relIso01EA_isLoaded = false;
  L_relIso02EA_isLoaded = false;
  L_relIso04EA_isLoaded = false;
  L_relIso08EA_isLoaded = false;
  L_relIso0025EAwLep_isLoaded = false;
  L_relIso005EAwLep_isLoaded = false;
  L_relIso01EAwLep_isLoaded = false;
  L_relIso02EAwLep_isLoaded = false;
  L_relIso04EAwLep_isLoaded = false;
  L_relIso08EAwLep_isLoaded = false;
  L_ip3d_isLoaded = false;
  L_ip3derr_isLoaded = false;
  L_dxy_isLoaded = false;
  L_dz_isLoaded = false;
  L_isFromW_isLoaded = false;
  X_p4_isLoaded = false;
  X_pt_isLoaded = false;
  X_phi_isLoaded = false;
  X_up_pt_isLoaded = false;
  X_up_phi_isLoaded = false;
  X_dn_pt_isLoaded = false;
  X_dn_phi_isLoaded = false;
  X_gen_pt_isLoaded = false;
  X_gen_phi_isLoaded = false;
  J_p4_isLoaded = false;
  J_pt_isLoaded = false;
  J_eta_isLoaded = false;
  J_phi_isLoaded = false;
  J_mass_isLoaded = false;
  J_energy_isLoaded = false;
  J_tau31_isLoaded = false;
  J_tau32_isLoaded = false;
  J_tau21_isLoaded = false;
  J_tau1_isLoaded = false;
  J_tau2_isLoaded = false;
  J_tau3_isLoaded = false;
  J_undoJEC_isLoaded = false;
  J_shift_isLoaded = false;
  J_SD_p4_isLoaded = false;
  J_SD_pt_isLoaded = false;
  J_SD_eta_isLoaded = false;
  J_SD_phi_isLoaded = false;
  J_SD_mass_isLoaded = false;
  J_SD_energy_isLoaded = false;
  J_SD_tau31_isLoaded = false;
  J_SD_tau32_isLoaded = false;
  J_SD_tau21_isLoaded = false;
  J_SD_tau1_isLoaded = false;
  J_SD_tau2_isLoaded = false;
  J_SD_tau3_isLoaded = false;
  q0_p4_isLoaded = false;
  q0_pt_isLoaded = false;
  q0_eta_isLoaded = false;
  q0_phi_isLoaded = false;
  q0_mass_isLoaded = false;
  q0_energy_isLoaded = false;
  q1_p4_isLoaded = false;
  q1_pt_isLoaded = false;
  q1_eta_isLoaded = false;
  q1_phi_isLoaded = false;
  q1_mass_isLoaded = false;
  q1_energy_isLoaded = false;
  V_p4_isLoaded = false;
  V_pt_isLoaded = false;
  V_eta_isLoaded = false;
  V_phi_isLoaded = false;
  V_mass_isLoaded = false;
  V_energy_isLoaded = false;
  V_SD_mass_isLoaded = false;
  V_tau31_isLoaded = false;
  V_tau32_isLoaded = false;
  V_tau21_isLoaded = false;
  V_tau1_isLoaded = false;
  V_tau2_isLoaded = false;
  V_tau3_isLoaded = false;
  V_undoJEC_isLoaded = false;
  V_shift_isLoaded = false;
  V_deep_rawdisc_h4q_isLoaded = false;
  V_deep_rawdisc_hbb_isLoaded = false;
  V_deep_rawdisc_qcd_isLoaded = false;
  V_deep_rawdisc_top_isLoaded = false;
  V_deep_rawdisc_w_isLoaded = false;
  V_deep_rawdisc_z_isLoaded = false;
  V_deep_rawdisc_zbb_isLoaded = false;
  V_softdropPuppiSubjet1_pt_isLoaded = false;
  V_softdropPuppiSubjet1_eta_isLoaded = false;
  V_softdropPuppiSubjet1_phi_isLoaded = false;
  V_softdropPuppiSubjet1_mass_isLoaded = false;
  V_softdropPuppiSubjet1_energy_isLoaded = false;
  V_softdropPuppiSubjet2_pt_isLoaded = false;
  V_softdropPuppiSubjet2_eta_isLoaded = false;
  V_softdropPuppiSubjet2_phi_isLoaded = false;
  V_softdropPuppiSubjet2_mass_isLoaded = false;
  V_softdropPuppiSubjet2_energy_isLoaded = false;
  LXJ_p4_isLoaded = false;
  LXJ_pt_isLoaded = false;
  LXJ_eta_isLoaded = false;
  LXJ_phi_isLoaded = false;
  LXJ_mass_isLoaded = false;
  LXJ_energy_isLoaded = false;
  LXJ_SD_p4_isLoaded = false;
  LXJ_SD_pt_isLoaded = false;
  LXJ_SD_eta_isLoaded = false;
  LXJ_SD_phi_isLoaded = false;
  LXJ_SD_mass_isLoaded = false;
  LXJ_SD_energy_isLoaded = false;
  LX_pt_isLoaded = false;
  LX_mt_isLoaded = false;
  LX_mass_isLoaded = false;
  LX_dphi_isLoaded = false;
  LJ_pt_isLoaded = false;
  LJ_mt_isLoaded = false;
  LJ_mass_isLoaded = false;
  LJ_dphi_isLoaded = false;
  LJ_deta_isLoaded = false;
  LJ_dr_isLoaded = false;
  LJ_dptf_isLoaded = false;
  LJ_SD_pt_isLoaded = false;
  LJ_SD_mt_isLoaded = false;
  LJ_SD_mass_isLoaded = false;
  LJ_SD_dphi_isLoaded = false;
  LJ_SD_deta_isLoaded = false;
  LJ_SD_dr_isLoaded = false;
  LJ_SD_dptf_isLoaded = false;
  Lq0_pt_isLoaded = false;
  Lq0_mt_isLoaded = false;
  Lq0_mass_isLoaded = false;
  Lq0_dphi_isLoaded = false;
  Lq0_deta_isLoaded = false;
  Lq0_dr_isLoaded = false;
  Lq0_dptf_isLoaded = false;
  Lq1_pt_isLoaded = false;
  Lq1_mt_isLoaded = false;
  Lq1_mass_isLoaded = false;
  Lq1_dphi_isLoaded = false;
  Lq1_deta_isLoaded = false;
  Lq1_dr_isLoaded = false;
  Lq1_dptf_isLoaded = false;
  Lqmax_pt_isLoaded = false;
  Lqmax_mt_isLoaded = false;
  Lqmax_mass_isLoaded = false;
  Lqmax_dphi_isLoaded = false;
  Lqmax_deta_isLoaded = false;
  Lqmax_dr_isLoaded = false;
  Lqmax_dptf_isLoaded = false;
  LHRatio_isLoaded = false;
  LHRatio_SD_isLoaded = false;
  neu_p4_isLoaded = false;
  neu_p4_h_isLoaded = false;
  Wlep_p4_isLoaded = false;
  Wlep_h_p4_isLoaded = false;
  H_p4_isLoaded = false;
  H_mh_p4_isLoaded = false;
  det_isLoaded = false;
  detW_isLoaded = false;
  mH_isLoaded = false;
  mD_isLoaded = false;
  mD_SD_isLoaded = false;
  mD_Wlep_isLoaded = false;
  j_dphis_isLoaded = false;
  j_drs_isLoaded = false;
  j_SD_dphis_isLoaded = false;
  j_SD_drs_isLoaded = false;
  j_pts_isLoaded = false;
  nj_isLoaded = false;
  nj_in_isLoaded = false;
  nj_annuli_isLoaded = false;
  nj_same_isLoaded = false;
  nj_away_isLoaded = false;
  nj_SD_in_isLoaded = false;
  nj_SD_annuli_isLoaded = false;
  nj_SD_same_isLoaded = false;
  nj_SD_away_isLoaded = false;
  nb_isLoaded = false;
  nb_in_isLoaded = false;
  nb_annuli_isLoaded = false;
  nb_same_isLoaded = false;
  nb_away_isLoaded = false;
  nb_SD_in_isLoaded = false;
  nb_SD_annuli_isLoaded = false;
  nb_SD_same_isLoaded = false;
  nb_SD_away_isLoaded = false;
  nbmed_isLoaded = false;
  nbmed_in_isLoaded = false;
  nbmed_annuli_isLoaded = false;
  nbmed_same_isLoaded = false;
  nbmed_away_isLoaded = false;
  nbmed_SD_in_isLoaded = false;
  nbmed_SD_annuli_isLoaded = false;
  nbmed_SD_same_isLoaded = false;
  nbmed_SD_away_isLoaded = false;
  nbtight_isLoaded = false;
  nbtight_in_isLoaded = false;
  nbtight_annuli_isLoaded = false;
  nbtight_same_isLoaded = false;
  nbtight_away_isLoaded = false;
  nbtight_SD_in_isLoaded = false;
  nbtight_SD_annuli_isLoaded = false;
  nbtight_SD_same_isLoaded = false;
  nbtight_SD_away_isLoaded = false;
  ht_isLoaded = false;
  ht_in_isLoaded = false;
  ht_annuli_isLoaded = false;
  ht_same_isLoaded = false;
  ht_away_isLoaded = false;
  ht_SD_in_isLoaded = false;
  ht_SD_annuli_isLoaded = false;
  ht_SD_same_isLoaded = false;
  ht_SD_away_isLoaded = false;
  R_p4_isLoaded = false;
  R_pt_isLoaded = false;
  R_eta_isLoaded = false;
  R_phi_isLoaded = false;
  R_mass_isLoaded = false;
  R_energy_isLoaded = false;
  R_cent_p4_isLoaded = false;
  R_cent_pt_isLoaded = false;
  R_cent_eta_isLoaded = false;
  R_cent_phi_isLoaded = false;
  R_cent_mass_isLoaded = false;
  R_cent_energy_isLoaded = false;
  gen_recoil_p4_isLoaded = false;
  gen_recoil_id_isLoaded = false;
  gen_higgs_p4_isLoaded = false;
  gen_whad_p4_isLoaded = false;
  gen_wlep_p4_isLoaded = false;
  gen_q0_p4_isLoaded = false;
  gen_q1_p4_isLoaded = false;
  gen_lep_p4_isLoaded = false;
  gen_neu_p4_isLoaded = false;
  gen_Vq0_p4_isLoaded = false;
  gen_Vq1_p4_isLoaded = false;
  gen_Vq0_id_isLoaded = false;
  gen_Vq1_id_isLoaded = false;
  gen_q0_id_isLoaded = false;
  gen_q1_id_isLoaded = false;
  gen_lep_id_isLoaded = false;
  gen_neu_id_isLoaded = false;
  gen_b0_p4_isLoaded = false;
  gen_b0_pt_isLoaded = false;
  gen_b0_eta_isLoaded = false;
  gen_b0_phi_isLoaded = false;
  gen_b0_mass_isLoaded = false;
  gen_b0_energy_isLoaded = false;
  gen_b1_p4_isLoaded = false;
  gen_b1_pt_isLoaded = false;
  gen_b1_eta_isLoaded = false;
  gen_b1_phi_isLoaded = false;
  gen_b1_mass_isLoaded = false;
  gen_b1_energy_isLoaded = false;
  gen_t0_p4_isLoaded = false;
  gen_t0_pt_isLoaded = false;
  gen_t0_eta_isLoaded = false;
  gen_t0_phi_isLoaded = false;
  gen_t0_mass_isLoaded = false;
  gen_t0_energy_isLoaded = false;
  gen_t1_p4_isLoaded = false;
  gen_t1_pt_isLoaded = false;
  gen_t1_eta_isLoaded = false;
  gen_t1_phi_isLoaded = false;
  gen_t1_mass_isLoaded = false;
  gen_t1_energy_isLoaded = false;
  gen_b0_dr_isLoaded = false;
  gen_b0_in_isLoaded = false;
  gen_b0_annuli_isLoaded = false;
  gen_b0_same_isLoaded = false;
  gen_b0_away_isLoaded = false;
  gen_b1_dr_isLoaded = false;
  gen_b1_in_isLoaded = false;
  gen_b1_annuli_isLoaded = false;
  gen_b1_same_isLoaded = false;
  gen_b1_away_isLoaded = false;
  gen_b0_SD_dr_isLoaded = false;
  gen_b0_SD_in_isLoaded = false;
  gen_b0_SD_annuli_isLoaded = false;
  gen_b0_SD_same_isLoaded = false;
  gen_b0_SD_away_isLoaded = false;
  gen_b1_SD_dr_isLoaded = false;
  gen_b1_SD_in_isLoaded = false;
  gen_b1_SD_annuli_isLoaded = false;
  gen_b1_SD_same_isLoaded = false;
  gen_b1_SD_away_isLoaded = false;
  gen_t0_dr_isLoaded = false;
  gen_t0_in_isLoaded = false;
  gen_t0_annuli_isLoaded = false;
  gen_t0_same_isLoaded = false;
  gen_t0_away_isLoaded = false;
  gen_t1_dr_isLoaded = false;
  gen_t1_in_isLoaded = false;
  gen_t1_annuli_isLoaded = false;
  gen_t1_same_isLoaded = false;
  gen_t1_away_isLoaded = false;
  gen_t0_SD_dr_isLoaded = false;
  gen_t0_SD_in_isLoaded = false;
  gen_t0_SD_annuli_isLoaded = false;
  gen_t0_SD_same_isLoaded = false;
  gen_t0_SD_away_isLoaded = false;
  gen_t1_SD_dr_isLoaded = false;
  gen_t1_SD_in_isLoaded = false;
  gen_t1_SD_annuli_isLoaded = false;
  gen_t1_SD_same_isLoaded = false;
  gen_t1_SD_away_isLoaded = false;
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
  if (gen_ht_branch != 0) gen_ht();
  if (nvtx_branch != 0) nvtx();
  if (L_p4_branch != 0) L_p4();
  if (L_pt_branch != 0) L_pt();
  if (L_eta_branch != 0) L_eta();
  if (L_phi_branch != 0) L_phi();
  if (L_mass_branch != 0) L_mass();
  if (L_energy_branch != 0) L_energy();
  if (L_id_branch != 0) L_id();
  if (L_idx_branch != 0) L_idx();
  if (L_isTightPOG_branch != 0) L_isTightPOG();
  if (L_miniIsoEA_branch != 0) L_miniIsoEA();
  if (L_relIso03EA_branch != 0) L_relIso03EA();
  if (L_relIso04DB_branch != 0) L_relIso04DB();
  if (L_relIso0025EA_branch != 0) L_relIso0025EA();
  if (L_relIso005EA_branch != 0) L_relIso005EA();
  if (L_relIso01EA_branch != 0) L_relIso01EA();
  if (L_relIso02EA_branch != 0) L_relIso02EA();
  if (L_relIso04EA_branch != 0) L_relIso04EA();
  if (L_relIso08EA_branch != 0) L_relIso08EA();
  if (L_relIso0025EAwLep_branch != 0) L_relIso0025EAwLep();
  if (L_relIso005EAwLep_branch != 0) L_relIso005EAwLep();
  if (L_relIso01EAwLep_branch != 0) L_relIso01EAwLep();
  if (L_relIso02EAwLep_branch != 0) L_relIso02EAwLep();
  if (L_relIso04EAwLep_branch != 0) L_relIso04EAwLep();
  if (L_relIso08EAwLep_branch != 0) L_relIso08EAwLep();
  if (L_ip3d_branch != 0) L_ip3d();
  if (L_ip3derr_branch != 0) L_ip3derr();
  if (L_dxy_branch != 0) L_dxy();
  if (L_dz_branch != 0) L_dz();
  if (L_isFromW_branch != 0) L_isFromW();
  if (X_p4_branch != 0) X_p4();
  if (X_pt_branch != 0) X_pt();
  if (X_phi_branch != 0) X_phi();
  if (X_up_pt_branch != 0) X_up_pt();
  if (X_up_phi_branch != 0) X_up_phi();
  if (X_dn_pt_branch != 0) X_dn_pt();
  if (X_dn_phi_branch != 0) X_dn_phi();
  if (X_gen_pt_branch != 0) X_gen_pt();
  if (X_gen_phi_branch != 0) X_gen_phi();
  if (J_p4_branch != 0) J_p4();
  if (J_pt_branch != 0) J_pt();
  if (J_eta_branch != 0) J_eta();
  if (J_phi_branch != 0) J_phi();
  if (J_mass_branch != 0) J_mass();
  if (J_energy_branch != 0) J_energy();
  if (J_tau31_branch != 0) J_tau31();
  if (J_tau32_branch != 0) J_tau32();
  if (J_tau21_branch != 0) J_tau21();
  if (J_tau1_branch != 0) J_tau1();
  if (J_tau2_branch != 0) J_tau2();
  if (J_tau3_branch != 0) J_tau3();
  if (J_undoJEC_branch != 0) J_undoJEC();
  if (J_shift_branch != 0) J_shift();
  if (J_SD_p4_branch != 0) J_SD_p4();
  if (J_SD_pt_branch != 0) J_SD_pt();
  if (J_SD_eta_branch != 0) J_SD_eta();
  if (J_SD_phi_branch != 0) J_SD_phi();
  if (J_SD_mass_branch != 0) J_SD_mass();
  if (J_SD_energy_branch != 0) J_SD_energy();
  if (J_SD_tau31_branch != 0) J_SD_tau31();
  if (J_SD_tau32_branch != 0) J_SD_tau32();
  if (J_SD_tau21_branch != 0) J_SD_tau21();
  if (J_SD_tau1_branch != 0) J_SD_tau1();
  if (J_SD_tau2_branch != 0) J_SD_tau2();
  if (J_SD_tau3_branch != 0) J_SD_tau3();
  if (q0_p4_branch != 0) q0_p4();
  if (q0_pt_branch != 0) q0_pt();
  if (q0_eta_branch != 0) q0_eta();
  if (q0_phi_branch != 0) q0_phi();
  if (q0_mass_branch != 0) q0_mass();
  if (q0_energy_branch != 0) q0_energy();
  if (q1_p4_branch != 0) q1_p4();
  if (q1_pt_branch != 0) q1_pt();
  if (q1_eta_branch != 0) q1_eta();
  if (q1_phi_branch != 0) q1_phi();
  if (q1_mass_branch != 0) q1_mass();
  if (q1_energy_branch != 0) q1_energy();
  if (V_p4_branch != 0) V_p4();
  if (V_pt_branch != 0) V_pt();
  if (V_eta_branch != 0) V_eta();
  if (V_phi_branch != 0) V_phi();
  if (V_mass_branch != 0) V_mass();
  if (V_energy_branch != 0) V_energy();
  if (V_SD_mass_branch != 0) V_SD_mass();
  if (V_tau31_branch != 0) V_tau31();
  if (V_tau32_branch != 0) V_tau32();
  if (V_tau21_branch != 0) V_tau21();
  if (V_tau1_branch != 0) V_tau1();
  if (V_tau2_branch != 0) V_tau2();
  if (V_tau3_branch != 0) V_tau3();
  if (V_undoJEC_branch != 0) V_undoJEC();
  if (V_shift_branch != 0) V_shift();
  if (V_deep_rawdisc_h4q_branch != 0) V_deep_rawdisc_h4q();
  if (V_deep_rawdisc_hbb_branch != 0) V_deep_rawdisc_hbb();
  if (V_deep_rawdisc_qcd_branch != 0) V_deep_rawdisc_qcd();
  if (V_deep_rawdisc_top_branch != 0) V_deep_rawdisc_top();
  if (V_deep_rawdisc_w_branch != 0) V_deep_rawdisc_w();
  if (V_deep_rawdisc_z_branch != 0) V_deep_rawdisc_z();
  if (V_deep_rawdisc_zbb_branch != 0) V_deep_rawdisc_zbb();
  if (V_softdropPuppiSubjet1_pt_branch != 0) V_softdropPuppiSubjet1_pt();
  if (V_softdropPuppiSubjet1_eta_branch != 0) V_softdropPuppiSubjet1_eta();
  if (V_softdropPuppiSubjet1_phi_branch != 0) V_softdropPuppiSubjet1_phi();
  if (V_softdropPuppiSubjet1_mass_branch != 0) V_softdropPuppiSubjet1_mass();
  if (V_softdropPuppiSubjet1_energy_branch != 0) V_softdropPuppiSubjet1_energy();
  if (V_softdropPuppiSubjet2_pt_branch != 0) V_softdropPuppiSubjet2_pt();
  if (V_softdropPuppiSubjet2_eta_branch != 0) V_softdropPuppiSubjet2_eta();
  if (V_softdropPuppiSubjet2_phi_branch != 0) V_softdropPuppiSubjet2_phi();
  if (V_softdropPuppiSubjet2_mass_branch != 0) V_softdropPuppiSubjet2_mass();
  if (V_softdropPuppiSubjet2_energy_branch != 0) V_softdropPuppiSubjet2_energy();
  if (LXJ_p4_branch != 0) LXJ_p4();
  if (LXJ_pt_branch != 0) LXJ_pt();
  if (LXJ_eta_branch != 0) LXJ_eta();
  if (LXJ_phi_branch != 0) LXJ_phi();
  if (LXJ_mass_branch != 0) LXJ_mass();
  if (LXJ_energy_branch != 0) LXJ_energy();
  if (LXJ_SD_p4_branch != 0) LXJ_SD_p4();
  if (LXJ_SD_pt_branch != 0) LXJ_SD_pt();
  if (LXJ_SD_eta_branch != 0) LXJ_SD_eta();
  if (LXJ_SD_phi_branch != 0) LXJ_SD_phi();
  if (LXJ_SD_mass_branch != 0) LXJ_SD_mass();
  if (LXJ_SD_energy_branch != 0) LXJ_SD_energy();
  if (LX_pt_branch != 0) LX_pt();
  if (LX_mt_branch != 0) LX_mt();
  if (LX_mass_branch != 0) LX_mass();
  if (LX_dphi_branch != 0) LX_dphi();
  if (LJ_pt_branch != 0) LJ_pt();
  if (LJ_mt_branch != 0) LJ_mt();
  if (LJ_mass_branch != 0) LJ_mass();
  if (LJ_dphi_branch != 0) LJ_dphi();
  if (LJ_deta_branch != 0) LJ_deta();
  if (LJ_dr_branch != 0) LJ_dr();
  if (LJ_dptf_branch != 0) LJ_dptf();
  if (LJ_SD_pt_branch != 0) LJ_SD_pt();
  if (LJ_SD_mt_branch != 0) LJ_SD_mt();
  if (LJ_SD_mass_branch != 0) LJ_SD_mass();
  if (LJ_SD_dphi_branch != 0) LJ_SD_dphi();
  if (LJ_SD_deta_branch != 0) LJ_SD_deta();
  if (LJ_SD_dr_branch != 0) LJ_SD_dr();
  if (LJ_SD_dptf_branch != 0) LJ_SD_dptf();
  if (Lq0_pt_branch != 0) Lq0_pt();
  if (Lq0_mt_branch != 0) Lq0_mt();
  if (Lq0_mass_branch != 0) Lq0_mass();
  if (Lq0_dphi_branch != 0) Lq0_dphi();
  if (Lq0_deta_branch != 0) Lq0_deta();
  if (Lq0_dr_branch != 0) Lq0_dr();
  if (Lq0_dptf_branch != 0) Lq0_dptf();
  if (Lq1_pt_branch != 0) Lq1_pt();
  if (Lq1_mt_branch != 0) Lq1_mt();
  if (Lq1_mass_branch != 0) Lq1_mass();
  if (Lq1_dphi_branch != 0) Lq1_dphi();
  if (Lq1_deta_branch != 0) Lq1_deta();
  if (Lq1_dr_branch != 0) Lq1_dr();
  if (Lq1_dptf_branch != 0) Lq1_dptf();
  if (Lqmax_pt_branch != 0) Lqmax_pt();
  if (Lqmax_mt_branch != 0) Lqmax_mt();
  if (Lqmax_mass_branch != 0) Lqmax_mass();
  if (Lqmax_dphi_branch != 0) Lqmax_dphi();
  if (Lqmax_deta_branch != 0) Lqmax_deta();
  if (Lqmax_dr_branch != 0) Lqmax_dr();
  if (Lqmax_dptf_branch != 0) Lqmax_dptf();
  if (LHRatio_branch != 0) LHRatio();
  if (LHRatio_SD_branch != 0) LHRatio_SD();
  if (neu_p4_branch != 0) neu_p4();
  if (neu_p4_h_branch != 0) neu_p4_h();
  if (Wlep_p4_branch != 0) Wlep_p4();
  if (Wlep_h_p4_branch != 0) Wlep_h_p4();
  if (H_p4_branch != 0) H_p4();
  if (H_mh_p4_branch != 0) H_mh_p4();
  if (det_branch != 0) det();
  if (detW_branch != 0) detW();
  if (mH_branch != 0) mH();
  if (mD_branch != 0) mD();
  if (mD_SD_branch != 0) mD_SD();
  if (mD_Wlep_branch != 0) mD_Wlep();
  if (j_dphis_branch != 0) j_dphis();
  if (j_drs_branch != 0) j_drs();
  if (j_SD_dphis_branch != 0) j_SD_dphis();
  if (j_SD_drs_branch != 0) j_SD_drs();
  if (j_pts_branch != 0) j_pts();
  if (nj_branch != 0) nj();
  if (nj_in_branch != 0) nj_in();
  if (nj_annuli_branch != 0) nj_annuli();
  if (nj_same_branch != 0) nj_same();
  if (nj_away_branch != 0) nj_away();
  if (nj_SD_in_branch != 0) nj_SD_in();
  if (nj_SD_annuli_branch != 0) nj_SD_annuli();
  if (nj_SD_same_branch != 0) nj_SD_same();
  if (nj_SD_away_branch != 0) nj_SD_away();
  if (nb_branch != 0) nb();
  if (nb_in_branch != 0) nb_in();
  if (nb_annuli_branch != 0) nb_annuli();
  if (nb_same_branch != 0) nb_same();
  if (nb_away_branch != 0) nb_away();
  if (nb_SD_in_branch != 0) nb_SD_in();
  if (nb_SD_annuli_branch != 0) nb_SD_annuli();
  if (nb_SD_same_branch != 0) nb_SD_same();
  if (nb_SD_away_branch != 0) nb_SD_away();
  if (nbmed_branch != 0) nbmed();
  if (nbmed_in_branch != 0) nbmed_in();
  if (nbmed_annuli_branch != 0) nbmed_annuli();
  if (nbmed_same_branch != 0) nbmed_same();
  if (nbmed_away_branch != 0) nbmed_away();
  if (nbmed_SD_in_branch != 0) nbmed_SD_in();
  if (nbmed_SD_annuli_branch != 0) nbmed_SD_annuli();
  if (nbmed_SD_same_branch != 0) nbmed_SD_same();
  if (nbmed_SD_away_branch != 0) nbmed_SD_away();
  if (nbtight_branch != 0) nbtight();
  if (nbtight_in_branch != 0) nbtight_in();
  if (nbtight_annuli_branch != 0) nbtight_annuli();
  if (nbtight_same_branch != 0) nbtight_same();
  if (nbtight_away_branch != 0) nbtight_away();
  if (nbtight_SD_in_branch != 0) nbtight_SD_in();
  if (nbtight_SD_annuli_branch != 0) nbtight_SD_annuli();
  if (nbtight_SD_same_branch != 0) nbtight_SD_same();
  if (nbtight_SD_away_branch != 0) nbtight_SD_away();
  if (ht_branch != 0) ht();
  if (ht_in_branch != 0) ht_in();
  if (ht_annuli_branch != 0) ht_annuli();
  if (ht_same_branch != 0) ht_same();
  if (ht_away_branch != 0) ht_away();
  if (ht_SD_in_branch != 0) ht_SD_in();
  if (ht_SD_annuli_branch != 0) ht_SD_annuli();
  if (ht_SD_same_branch != 0) ht_SD_same();
  if (ht_SD_away_branch != 0) ht_SD_away();
  if (R_p4_branch != 0) R_p4();
  if (R_pt_branch != 0) R_pt();
  if (R_eta_branch != 0) R_eta();
  if (R_phi_branch != 0) R_phi();
  if (R_mass_branch != 0) R_mass();
  if (R_energy_branch != 0) R_energy();
  if (R_cent_p4_branch != 0) R_cent_p4();
  if (R_cent_pt_branch != 0) R_cent_pt();
  if (R_cent_eta_branch != 0) R_cent_eta();
  if (R_cent_phi_branch != 0) R_cent_phi();
  if (R_cent_mass_branch != 0) R_cent_mass();
  if (R_cent_energy_branch != 0) R_cent_energy();
  if (gen_recoil_p4_branch != 0) gen_recoil_p4();
  if (gen_recoil_id_branch != 0) gen_recoil_id();
  if (gen_higgs_p4_branch != 0) gen_higgs_p4();
  if (gen_whad_p4_branch != 0) gen_whad_p4();
  if (gen_wlep_p4_branch != 0) gen_wlep_p4();
  if (gen_q0_p4_branch != 0) gen_q0_p4();
  if (gen_q1_p4_branch != 0) gen_q1_p4();
  if (gen_lep_p4_branch != 0) gen_lep_p4();
  if (gen_neu_p4_branch != 0) gen_neu_p4();
  if (gen_Vq0_p4_branch != 0) gen_Vq0_p4();
  if (gen_Vq1_p4_branch != 0) gen_Vq1_p4();
  if (gen_Vq0_id_branch != 0) gen_Vq0_id();
  if (gen_Vq1_id_branch != 0) gen_Vq1_id();
  if (gen_q0_id_branch != 0) gen_q0_id();
  if (gen_q1_id_branch != 0) gen_q1_id();
  if (gen_lep_id_branch != 0) gen_lep_id();
  if (gen_neu_id_branch != 0) gen_neu_id();
  if (gen_b0_p4_branch != 0) gen_b0_p4();
  if (gen_b0_pt_branch != 0) gen_b0_pt();
  if (gen_b0_eta_branch != 0) gen_b0_eta();
  if (gen_b0_phi_branch != 0) gen_b0_phi();
  if (gen_b0_mass_branch != 0) gen_b0_mass();
  if (gen_b0_energy_branch != 0) gen_b0_energy();
  if (gen_b1_p4_branch != 0) gen_b1_p4();
  if (gen_b1_pt_branch != 0) gen_b1_pt();
  if (gen_b1_eta_branch != 0) gen_b1_eta();
  if (gen_b1_phi_branch != 0) gen_b1_phi();
  if (gen_b1_mass_branch != 0) gen_b1_mass();
  if (gen_b1_energy_branch != 0) gen_b1_energy();
  if (gen_t0_p4_branch != 0) gen_t0_p4();
  if (gen_t0_pt_branch != 0) gen_t0_pt();
  if (gen_t0_eta_branch != 0) gen_t0_eta();
  if (gen_t0_phi_branch != 0) gen_t0_phi();
  if (gen_t0_mass_branch != 0) gen_t0_mass();
  if (gen_t0_energy_branch != 0) gen_t0_energy();
  if (gen_t1_p4_branch != 0) gen_t1_p4();
  if (gen_t1_pt_branch != 0) gen_t1_pt();
  if (gen_t1_eta_branch != 0) gen_t1_eta();
  if (gen_t1_phi_branch != 0) gen_t1_phi();
  if (gen_t1_mass_branch != 0) gen_t1_mass();
  if (gen_t1_energy_branch != 0) gen_t1_energy();
  if (gen_b0_dr_branch != 0) gen_b0_dr();
  if (gen_b0_in_branch != 0) gen_b0_in();
  if (gen_b0_annuli_branch != 0) gen_b0_annuli();
  if (gen_b0_same_branch != 0) gen_b0_same();
  if (gen_b0_away_branch != 0) gen_b0_away();
  if (gen_b1_dr_branch != 0) gen_b1_dr();
  if (gen_b1_in_branch != 0) gen_b1_in();
  if (gen_b1_annuli_branch != 0) gen_b1_annuli();
  if (gen_b1_same_branch != 0) gen_b1_same();
  if (gen_b1_away_branch != 0) gen_b1_away();
  if (gen_b0_SD_dr_branch != 0) gen_b0_SD_dr();
  if (gen_b0_SD_in_branch != 0) gen_b0_SD_in();
  if (gen_b0_SD_annuli_branch != 0) gen_b0_SD_annuli();
  if (gen_b0_SD_same_branch != 0) gen_b0_SD_same();
  if (gen_b0_SD_away_branch != 0) gen_b0_SD_away();
  if (gen_b1_SD_dr_branch != 0) gen_b1_SD_dr();
  if (gen_b1_SD_in_branch != 0) gen_b1_SD_in();
  if (gen_b1_SD_annuli_branch != 0) gen_b1_SD_annuli();
  if (gen_b1_SD_same_branch != 0) gen_b1_SD_same();
  if (gen_b1_SD_away_branch != 0) gen_b1_SD_away();
  if (gen_t0_dr_branch != 0) gen_t0_dr();
  if (gen_t0_in_branch != 0) gen_t0_in();
  if (gen_t0_annuli_branch != 0) gen_t0_annuli();
  if (gen_t0_same_branch != 0) gen_t0_same();
  if (gen_t0_away_branch != 0) gen_t0_away();
  if (gen_t1_dr_branch != 0) gen_t1_dr();
  if (gen_t1_in_branch != 0) gen_t1_in();
  if (gen_t1_annuli_branch != 0) gen_t1_annuli();
  if (gen_t1_same_branch != 0) gen_t1_same();
  if (gen_t1_away_branch != 0) gen_t1_away();
  if (gen_t0_SD_dr_branch != 0) gen_t0_SD_dr();
  if (gen_t0_SD_in_branch != 0) gen_t0_SD_in();
  if (gen_t0_SD_annuli_branch != 0) gen_t0_SD_annuli();
  if (gen_t0_SD_same_branch != 0) gen_t0_SD_same();
  if (gen_t0_SD_away_branch != 0) gen_t0_SD_away();
  if (gen_t1_SD_dr_branch != 0) gen_t1_SD_dr();
  if (gen_t1_SD_in_branch != 0) gen_t1_SD_in();
  if (gen_t1_SD_annuli_branch != 0) gen_t1_SD_annuli();
  if (gen_t1_SD_same_branch != 0) gen_t1_SD_same();
  if (gen_t1_SD_away_branch != 0) gen_t1_SD_away();
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

const float &hwwtree::gen_ht() {
  if (not gen_ht_isLoaded) {
    if (gen_ht_branch != 0) {
      gen_ht_branch->GetEntry(index);
    } else {
      printf("branch gen_ht_branch does not exist!\n");
      exit(1);
    }
    gen_ht_isLoaded = true;
  }
  return gen_ht_;
}

const float &hwwtree::nvtx() {
  if (not nvtx_isLoaded) {
    if (nvtx_branch != 0) {
      nvtx_branch->GetEntry(index);
    } else {
      printf("branch nvtx_branch does not exist!\n");
      exit(1);
    }
    nvtx_isLoaded = true;
  }
  return nvtx_;
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

const float &hwwtree::L_pt() {
  if (not L_pt_isLoaded) {
    if (L_pt_branch != 0) {
      L_pt_branch->GetEntry(index);
    } else {
      printf("branch L_pt_branch does not exist!\n");
      exit(1);
    }
    L_pt_isLoaded = true;
  }
  return L_pt_;
}

const float &hwwtree::L_eta() {
  if (not L_eta_isLoaded) {
    if (L_eta_branch != 0) {
      L_eta_branch->GetEntry(index);
    } else {
      printf("branch L_eta_branch does not exist!\n");
      exit(1);
    }
    L_eta_isLoaded = true;
  }
  return L_eta_;
}

const float &hwwtree::L_phi() {
  if (not L_phi_isLoaded) {
    if (L_phi_branch != 0) {
      L_phi_branch->GetEntry(index);
    } else {
      printf("branch L_phi_branch does not exist!\n");
      exit(1);
    }
    L_phi_isLoaded = true;
  }
  return L_phi_;
}

const float &hwwtree::L_mass() {
  if (not L_mass_isLoaded) {
    if (L_mass_branch != 0) {
      L_mass_branch->GetEntry(index);
    } else {
      printf("branch L_mass_branch does not exist!\n");
      exit(1);
    }
    L_mass_isLoaded = true;
  }
  return L_mass_;
}

const float &hwwtree::L_energy() {
  if (not L_energy_isLoaded) {
    if (L_energy_branch != 0) {
      L_energy_branch->GetEntry(index);
    } else {
      printf("branch L_energy_branch does not exist!\n");
      exit(1);
    }
    L_energy_isLoaded = true;
  }
  return L_energy_;
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

const int &hwwtree::L_isTightPOG() {
  if (not L_isTightPOG_isLoaded) {
    if (L_isTightPOG_branch != 0) {
      L_isTightPOG_branch->GetEntry(index);
    } else {
      printf("branch L_isTightPOG_branch does not exist!\n");
      exit(1);
    }
    L_isTightPOG_isLoaded = true;
  }
  return L_isTightPOG_;
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

const float &hwwtree::L_relIso0025EA() {
  if (not L_relIso0025EA_isLoaded) {
    if (L_relIso0025EA_branch != 0) {
      L_relIso0025EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso0025EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso0025EA_isLoaded = true;
  }
  return L_relIso0025EA_;
}

const float &hwwtree::L_relIso005EA() {
  if (not L_relIso005EA_isLoaded) {
    if (L_relIso005EA_branch != 0) {
      L_relIso005EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso005EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso005EA_isLoaded = true;
  }
  return L_relIso005EA_;
}

const float &hwwtree::L_relIso01EA() {
  if (not L_relIso01EA_isLoaded) {
    if (L_relIso01EA_branch != 0) {
      L_relIso01EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso01EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso01EA_isLoaded = true;
  }
  return L_relIso01EA_;
}

const float &hwwtree::L_relIso02EA() {
  if (not L_relIso02EA_isLoaded) {
    if (L_relIso02EA_branch != 0) {
      L_relIso02EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso02EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso02EA_isLoaded = true;
  }
  return L_relIso02EA_;
}

const float &hwwtree::L_relIso04EA() {
  if (not L_relIso04EA_isLoaded) {
    if (L_relIso04EA_branch != 0) {
      L_relIso04EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso04EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso04EA_isLoaded = true;
  }
  return L_relIso04EA_;
}

const float &hwwtree::L_relIso08EA() {
  if (not L_relIso08EA_isLoaded) {
    if (L_relIso08EA_branch != 0) {
      L_relIso08EA_branch->GetEntry(index);
    } else {
      printf("branch L_relIso08EA_branch does not exist!\n");
      exit(1);
    }
    L_relIso08EA_isLoaded = true;
  }
  return L_relIso08EA_;
}

const float &hwwtree::L_relIso0025EAwLep() {
  if (not L_relIso0025EAwLep_isLoaded) {
    if (L_relIso0025EAwLep_branch != 0) {
      L_relIso0025EAwLep_branch->GetEntry(index);
    } else {
      printf("branch L_relIso0025EAwLep_branch does not exist!\n");
      exit(1);
    }
    L_relIso0025EAwLep_isLoaded = true;
  }
  return L_relIso0025EAwLep_;
}

const float &hwwtree::L_relIso005EAwLep() {
  if (not L_relIso005EAwLep_isLoaded) {
    if (L_relIso005EAwLep_branch != 0) {
      L_relIso005EAwLep_branch->GetEntry(index);
    } else {
      printf("branch L_relIso005EAwLep_branch does not exist!\n");
      exit(1);
    }
    L_relIso005EAwLep_isLoaded = true;
  }
  return L_relIso005EAwLep_;
}

const float &hwwtree::L_relIso01EAwLep() {
  if (not L_relIso01EAwLep_isLoaded) {
    if (L_relIso01EAwLep_branch != 0) {
      L_relIso01EAwLep_branch->GetEntry(index);
    } else {
      printf("branch L_relIso01EAwLep_branch does not exist!\n");
      exit(1);
    }
    L_relIso01EAwLep_isLoaded = true;
  }
  return L_relIso01EAwLep_;
}

const float &hwwtree::L_relIso02EAwLep() {
  if (not L_relIso02EAwLep_isLoaded) {
    if (L_relIso02EAwLep_branch != 0) {
      L_relIso02EAwLep_branch->GetEntry(index);
    } else {
      printf("branch L_relIso02EAwLep_branch does not exist!\n");
      exit(1);
    }
    L_relIso02EAwLep_isLoaded = true;
  }
  return L_relIso02EAwLep_;
}

const float &hwwtree::L_relIso04EAwLep() {
  if (not L_relIso04EAwLep_isLoaded) {
    if (L_relIso04EAwLep_branch != 0) {
      L_relIso04EAwLep_branch->GetEntry(index);
    } else {
      printf("branch L_relIso04EAwLep_branch does not exist!\n");
      exit(1);
    }
    L_relIso04EAwLep_isLoaded = true;
  }
  return L_relIso04EAwLep_;
}

const float &hwwtree::L_relIso08EAwLep() {
  if (not L_relIso08EAwLep_isLoaded) {
    if (L_relIso08EAwLep_branch != 0) {
      L_relIso08EAwLep_branch->GetEntry(index);
    } else {
      printf("branch L_relIso08EAwLep_branch does not exist!\n");
      exit(1);
    }
    L_relIso08EAwLep_isLoaded = true;
  }
  return L_relIso08EAwLep_;
}

const float &hwwtree::L_ip3d() {
  if (not L_ip3d_isLoaded) {
    if (L_ip3d_branch != 0) {
      L_ip3d_branch->GetEntry(index);
    } else {
      printf("branch L_ip3d_branch does not exist!\n");
      exit(1);
    }
    L_ip3d_isLoaded = true;
  }
  return L_ip3d_;
}

const float &hwwtree::L_ip3derr() {
  if (not L_ip3derr_isLoaded) {
    if (L_ip3derr_branch != 0) {
      L_ip3derr_branch->GetEntry(index);
    } else {
      printf("branch L_ip3derr_branch does not exist!\n");
      exit(1);
    }
    L_ip3derr_isLoaded = true;
  }
  return L_ip3derr_;
}

const float &hwwtree::L_dxy() {
  if (not L_dxy_isLoaded) {
    if (L_dxy_branch != 0) {
      L_dxy_branch->GetEntry(index);
    } else {
      printf("branch L_dxy_branch does not exist!\n");
      exit(1);
    }
    L_dxy_isLoaded = true;
  }
  return L_dxy_;
}

const float &hwwtree::L_dz() {
  if (not L_dz_isLoaded) {
    if (L_dz_branch != 0) {
      L_dz_branch->GetEntry(index);
    } else {
      printf("branch L_dz_branch does not exist!\n");
      exit(1);
    }
    L_dz_isLoaded = true;
  }
  return L_dz_;
}

const int &hwwtree::L_isFromW() {
  if (not L_isFromW_isLoaded) {
    if (L_isFromW_branch != 0) {
      L_isFromW_branch->GetEntry(index);
    } else {
      printf("branch L_isFromW_branch does not exist!\n");
      exit(1);
    }
    L_isFromW_isLoaded = true;
  }
  return L_isFromW_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::X_p4() {
  if (not X_p4_isLoaded) {
    if (X_p4_branch != 0) {
      X_p4_branch->GetEntry(index);
    } else {
      printf("branch X_p4_branch does not exist!\n");
      exit(1);
    }
    X_p4_isLoaded = true;
  }
  return *X_p4_;
}

const float &hwwtree::X_pt() {
  if (not X_pt_isLoaded) {
    if (X_pt_branch != 0) {
      X_pt_branch->GetEntry(index);
    } else {
      printf("branch X_pt_branch does not exist!\n");
      exit(1);
    }
    X_pt_isLoaded = true;
  }
  return X_pt_;
}

const float &hwwtree::X_phi() {
  if (not X_phi_isLoaded) {
    if (X_phi_branch != 0) {
      X_phi_branch->GetEntry(index);
    } else {
      printf("branch X_phi_branch does not exist!\n");
      exit(1);
    }
    X_phi_isLoaded = true;
  }
  return X_phi_;
}

const float &hwwtree::X_up_pt() {
  if (not X_up_pt_isLoaded) {
    if (X_up_pt_branch != 0) {
      X_up_pt_branch->GetEntry(index);
    } else {
      printf("branch X_up_pt_branch does not exist!\n");
      exit(1);
    }
    X_up_pt_isLoaded = true;
  }
  return X_up_pt_;
}

const float &hwwtree::X_up_phi() {
  if (not X_up_phi_isLoaded) {
    if (X_up_phi_branch != 0) {
      X_up_phi_branch->GetEntry(index);
    } else {
      printf("branch X_up_phi_branch does not exist!\n");
      exit(1);
    }
    X_up_phi_isLoaded = true;
  }
  return X_up_phi_;
}

const float &hwwtree::X_dn_pt() {
  if (not X_dn_pt_isLoaded) {
    if (X_dn_pt_branch != 0) {
      X_dn_pt_branch->GetEntry(index);
    } else {
      printf("branch X_dn_pt_branch does not exist!\n");
      exit(1);
    }
    X_dn_pt_isLoaded = true;
  }
  return X_dn_pt_;
}

const float &hwwtree::X_dn_phi() {
  if (not X_dn_phi_isLoaded) {
    if (X_dn_phi_branch != 0) {
      X_dn_phi_branch->GetEntry(index);
    } else {
      printf("branch X_dn_phi_branch does not exist!\n");
      exit(1);
    }
    X_dn_phi_isLoaded = true;
  }
  return X_dn_phi_;
}

const float &hwwtree::X_gen_pt() {
  if (not X_gen_pt_isLoaded) {
    if (X_gen_pt_branch != 0) {
      X_gen_pt_branch->GetEntry(index);
    } else {
      printf("branch X_gen_pt_branch does not exist!\n");
      exit(1);
    }
    X_gen_pt_isLoaded = true;
  }
  return X_gen_pt_;
}

const float &hwwtree::X_gen_phi() {
  if (not X_gen_phi_isLoaded) {
    if (X_gen_phi_branch != 0) {
      X_gen_phi_branch->GetEntry(index);
    } else {
      printf("branch X_gen_phi_branch does not exist!\n");
      exit(1);
    }
    X_gen_phi_isLoaded = true;
  }
  return X_gen_phi_;
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

const float &hwwtree::J_pt() {
  if (not J_pt_isLoaded) {
    if (J_pt_branch != 0) {
      J_pt_branch->GetEntry(index);
    } else {
      printf("branch J_pt_branch does not exist!\n");
      exit(1);
    }
    J_pt_isLoaded = true;
  }
  return J_pt_;
}

const float &hwwtree::J_eta() {
  if (not J_eta_isLoaded) {
    if (J_eta_branch != 0) {
      J_eta_branch->GetEntry(index);
    } else {
      printf("branch J_eta_branch does not exist!\n");
      exit(1);
    }
    J_eta_isLoaded = true;
  }
  return J_eta_;
}

const float &hwwtree::J_phi() {
  if (not J_phi_isLoaded) {
    if (J_phi_branch != 0) {
      J_phi_branch->GetEntry(index);
    } else {
      printf("branch J_phi_branch does not exist!\n");
      exit(1);
    }
    J_phi_isLoaded = true;
  }
  return J_phi_;
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

const float &hwwtree::J_energy() {
  if (not J_energy_isLoaded) {
    if (J_energy_branch != 0) {
      J_energy_branch->GetEntry(index);
    } else {
      printf("branch J_energy_branch does not exist!\n");
      exit(1);
    }
    J_energy_isLoaded = true;
  }
  return J_energy_;
}

const float &hwwtree::J_tau31() {
  if (not J_tau31_isLoaded) {
    if (J_tau31_branch != 0) {
      J_tau31_branch->GetEntry(index);
    } else {
      printf("branch J_tau31_branch does not exist!\n");
      exit(1);
    }
    J_tau31_isLoaded = true;
  }
  return J_tau31_;
}

const float &hwwtree::J_tau32() {
  if (not J_tau32_isLoaded) {
    if (J_tau32_branch != 0) {
      J_tau32_branch->GetEntry(index);
    } else {
      printf("branch J_tau32_branch does not exist!\n");
      exit(1);
    }
    J_tau32_isLoaded = true;
  }
  return J_tau32_;
}

const float &hwwtree::J_tau21() {
  if (not J_tau21_isLoaded) {
    if (J_tau21_branch != 0) {
      J_tau21_branch->GetEntry(index);
    } else {
      printf("branch J_tau21_branch does not exist!\n");
      exit(1);
    }
    J_tau21_isLoaded = true;
  }
  return J_tau21_;
}

const float &hwwtree::J_tau1() {
  if (not J_tau1_isLoaded) {
    if (J_tau1_branch != 0) {
      J_tau1_branch->GetEntry(index);
    } else {
      printf("branch J_tau1_branch does not exist!\n");
      exit(1);
    }
    J_tau1_isLoaded = true;
  }
  return J_tau1_;
}

const float &hwwtree::J_tau2() {
  if (not J_tau2_isLoaded) {
    if (J_tau2_branch != 0) {
      J_tau2_branch->GetEntry(index);
    } else {
      printf("branch J_tau2_branch does not exist!\n");
      exit(1);
    }
    J_tau2_isLoaded = true;
  }
  return J_tau2_;
}

const float &hwwtree::J_tau3() {
  if (not J_tau3_isLoaded) {
    if (J_tau3_branch != 0) {
      J_tau3_branch->GetEntry(index);
    } else {
      printf("branch J_tau3_branch does not exist!\n");
      exit(1);
    }
    J_tau3_isLoaded = true;
  }
  return J_tau3_;
}

const float &hwwtree::J_undoJEC() {
  if (not J_undoJEC_isLoaded) {
    if (J_undoJEC_branch != 0) {
      J_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch J_undoJEC_branch does not exist!\n");
      exit(1);
    }
    J_undoJEC_isLoaded = true;
  }
  return J_undoJEC_;
}

const float &hwwtree::J_shift() {
  if (not J_shift_isLoaded) {
    if (J_shift_branch != 0) {
      J_shift_branch->GetEntry(index);
    } else {
      printf("branch J_shift_branch does not exist!\n");
      exit(1);
    }
    J_shift_isLoaded = true;
  }
  return J_shift_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::J_SD_p4() {
  if (not J_SD_p4_isLoaded) {
    if (J_SD_p4_branch != 0) {
      J_SD_p4_branch->GetEntry(index);
    } else {
      printf("branch J_SD_p4_branch does not exist!\n");
      exit(1);
    }
    J_SD_p4_isLoaded = true;
  }
  return *J_SD_p4_;
}

const float &hwwtree::J_SD_pt() {
  if (not J_SD_pt_isLoaded) {
    if (J_SD_pt_branch != 0) {
      J_SD_pt_branch->GetEntry(index);
    } else {
      printf("branch J_SD_pt_branch does not exist!\n");
      exit(1);
    }
    J_SD_pt_isLoaded = true;
  }
  return J_SD_pt_;
}

const float &hwwtree::J_SD_eta() {
  if (not J_SD_eta_isLoaded) {
    if (J_SD_eta_branch != 0) {
      J_SD_eta_branch->GetEntry(index);
    } else {
      printf("branch J_SD_eta_branch does not exist!\n");
      exit(1);
    }
    J_SD_eta_isLoaded = true;
  }
  return J_SD_eta_;
}

const float &hwwtree::J_SD_phi() {
  if (not J_SD_phi_isLoaded) {
    if (J_SD_phi_branch != 0) {
      J_SD_phi_branch->GetEntry(index);
    } else {
      printf("branch J_SD_phi_branch does not exist!\n");
      exit(1);
    }
    J_SD_phi_isLoaded = true;
  }
  return J_SD_phi_;
}

const float &hwwtree::J_SD_mass() {
  if (not J_SD_mass_isLoaded) {
    if (J_SD_mass_branch != 0) {
      J_SD_mass_branch->GetEntry(index);
    } else {
      printf("branch J_SD_mass_branch does not exist!\n");
      exit(1);
    }
    J_SD_mass_isLoaded = true;
  }
  return J_SD_mass_;
}

const float &hwwtree::J_SD_energy() {
  if (not J_SD_energy_isLoaded) {
    if (J_SD_energy_branch != 0) {
      J_SD_energy_branch->GetEntry(index);
    } else {
      printf("branch J_SD_energy_branch does not exist!\n");
      exit(1);
    }
    J_SD_energy_isLoaded = true;
  }
  return J_SD_energy_;
}

const float &hwwtree::J_SD_tau31() {
  if (not J_SD_tau31_isLoaded) {
    if (J_SD_tau31_branch != 0) {
      J_SD_tau31_branch->GetEntry(index);
    } else {
      printf("branch J_SD_tau31_branch does not exist!\n");
      exit(1);
    }
    J_SD_tau31_isLoaded = true;
  }
  return J_SD_tau31_;
}

const float &hwwtree::J_SD_tau32() {
  if (not J_SD_tau32_isLoaded) {
    if (J_SD_tau32_branch != 0) {
      J_SD_tau32_branch->GetEntry(index);
    } else {
      printf("branch J_SD_tau32_branch does not exist!\n");
      exit(1);
    }
    J_SD_tau32_isLoaded = true;
  }
  return J_SD_tau32_;
}

const float &hwwtree::J_SD_tau21() {
  if (not J_SD_tau21_isLoaded) {
    if (J_SD_tau21_branch != 0) {
      J_SD_tau21_branch->GetEntry(index);
    } else {
      printf("branch J_SD_tau21_branch does not exist!\n");
      exit(1);
    }
    J_SD_tau21_isLoaded = true;
  }
  return J_SD_tau21_;
}

const float &hwwtree::J_SD_tau1() {
  if (not J_SD_tau1_isLoaded) {
    if (J_SD_tau1_branch != 0) {
      J_SD_tau1_branch->GetEntry(index);
    } else {
      printf("branch J_SD_tau1_branch does not exist!\n");
      exit(1);
    }
    J_SD_tau1_isLoaded = true;
  }
  return J_SD_tau1_;
}

const float &hwwtree::J_SD_tau2() {
  if (not J_SD_tau2_isLoaded) {
    if (J_SD_tau2_branch != 0) {
      J_SD_tau2_branch->GetEntry(index);
    } else {
      printf("branch J_SD_tau2_branch does not exist!\n");
      exit(1);
    }
    J_SD_tau2_isLoaded = true;
  }
  return J_SD_tau2_;
}

const float &hwwtree::J_SD_tau3() {
  if (not J_SD_tau3_isLoaded) {
    if (J_SD_tau3_branch != 0) {
      J_SD_tau3_branch->GetEntry(index);
    } else {
      printf("branch J_SD_tau3_branch does not exist!\n");
      exit(1);
    }
    J_SD_tau3_isLoaded = true;
  }
  return J_SD_tau3_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::q0_p4() {
  if (not q0_p4_isLoaded) {
    if (q0_p4_branch != 0) {
      q0_p4_branch->GetEntry(index);
    } else {
      printf("branch q0_p4_branch does not exist!\n");
      exit(1);
    }
    q0_p4_isLoaded = true;
  }
  return *q0_p4_;
}

const float &hwwtree::q0_pt() {
  if (not q0_pt_isLoaded) {
    if (q0_pt_branch != 0) {
      q0_pt_branch->GetEntry(index);
    } else {
      printf("branch q0_pt_branch does not exist!\n");
      exit(1);
    }
    q0_pt_isLoaded = true;
  }
  return q0_pt_;
}

const float &hwwtree::q0_eta() {
  if (not q0_eta_isLoaded) {
    if (q0_eta_branch != 0) {
      q0_eta_branch->GetEntry(index);
    } else {
      printf("branch q0_eta_branch does not exist!\n");
      exit(1);
    }
    q0_eta_isLoaded = true;
  }
  return q0_eta_;
}

const float &hwwtree::q0_phi() {
  if (not q0_phi_isLoaded) {
    if (q0_phi_branch != 0) {
      q0_phi_branch->GetEntry(index);
    } else {
      printf("branch q0_phi_branch does not exist!\n");
      exit(1);
    }
    q0_phi_isLoaded = true;
  }
  return q0_phi_;
}

const float &hwwtree::q0_mass() {
  if (not q0_mass_isLoaded) {
    if (q0_mass_branch != 0) {
      q0_mass_branch->GetEntry(index);
    } else {
      printf("branch q0_mass_branch does not exist!\n");
      exit(1);
    }
    q0_mass_isLoaded = true;
  }
  return q0_mass_;
}

const float &hwwtree::q0_energy() {
  if (not q0_energy_isLoaded) {
    if (q0_energy_branch != 0) {
      q0_energy_branch->GetEntry(index);
    } else {
      printf("branch q0_energy_branch does not exist!\n");
      exit(1);
    }
    q0_energy_isLoaded = true;
  }
  return q0_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::q1_p4() {
  if (not q1_p4_isLoaded) {
    if (q1_p4_branch != 0) {
      q1_p4_branch->GetEntry(index);
    } else {
      printf("branch q1_p4_branch does not exist!\n");
      exit(1);
    }
    q1_p4_isLoaded = true;
  }
  return *q1_p4_;
}

const float &hwwtree::q1_pt() {
  if (not q1_pt_isLoaded) {
    if (q1_pt_branch != 0) {
      q1_pt_branch->GetEntry(index);
    } else {
      printf("branch q1_pt_branch does not exist!\n");
      exit(1);
    }
    q1_pt_isLoaded = true;
  }
  return q1_pt_;
}

const float &hwwtree::q1_eta() {
  if (not q1_eta_isLoaded) {
    if (q1_eta_branch != 0) {
      q1_eta_branch->GetEntry(index);
    } else {
      printf("branch q1_eta_branch does not exist!\n");
      exit(1);
    }
    q1_eta_isLoaded = true;
  }
  return q1_eta_;
}

const float &hwwtree::q1_phi() {
  if (not q1_phi_isLoaded) {
    if (q1_phi_branch != 0) {
      q1_phi_branch->GetEntry(index);
    } else {
      printf("branch q1_phi_branch does not exist!\n");
      exit(1);
    }
    q1_phi_isLoaded = true;
  }
  return q1_phi_;
}

const float &hwwtree::q1_mass() {
  if (not q1_mass_isLoaded) {
    if (q1_mass_branch != 0) {
      q1_mass_branch->GetEntry(index);
    } else {
      printf("branch q1_mass_branch does not exist!\n");
      exit(1);
    }
    q1_mass_isLoaded = true;
  }
  return q1_mass_;
}

const float &hwwtree::q1_energy() {
  if (not q1_energy_isLoaded) {
    if (q1_energy_branch != 0) {
      q1_energy_branch->GetEntry(index);
    } else {
      printf("branch q1_energy_branch does not exist!\n");
      exit(1);
    }
    q1_energy_isLoaded = true;
  }
  return q1_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::V_p4() {
  if (not V_p4_isLoaded) {
    if (V_p4_branch != 0) {
      V_p4_branch->GetEntry(index);
    } else {
      printf("branch V_p4_branch does not exist!\n");
      exit(1);
    }
    V_p4_isLoaded = true;
  }
  return *V_p4_;
}

const float &hwwtree::V_pt() {
  if (not V_pt_isLoaded) {
    if (V_pt_branch != 0) {
      V_pt_branch->GetEntry(index);
    } else {
      printf("branch V_pt_branch does not exist!\n");
      exit(1);
    }
    V_pt_isLoaded = true;
  }
  return V_pt_;
}

const float &hwwtree::V_eta() {
  if (not V_eta_isLoaded) {
    if (V_eta_branch != 0) {
      V_eta_branch->GetEntry(index);
    } else {
      printf("branch V_eta_branch does not exist!\n");
      exit(1);
    }
    V_eta_isLoaded = true;
  }
  return V_eta_;
}

const float &hwwtree::V_phi() {
  if (not V_phi_isLoaded) {
    if (V_phi_branch != 0) {
      V_phi_branch->GetEntry(index);
    } else {
      printf("branch V_phi_branch does not exist!\n");
      exit(1);
    }
    V_phi_isLoaded = true;
  }
  return V_phi_;
}

const float &hwwtree::V_mass() {
  if (not V_mass_isLoaded) {
    if (V_mass_branch != 0) {
      V_mass_branch->GetEntry(index);
    } else {
      printf("branch V_mass_branch does not exist!\n");
      exit(1);
    }
    V_mass_isLoaded = true;
  }
  return V_mass_;
}

const float &hwwtree::V_energy() {
  if (not V_energy_isLoaded) {
    if (V_energy_branch != 0) {
      V_energy_branch->GetEntry(index);
    } else {
      printf("branch V_energy_branch does not exist!\n");
      exit(1);
    }
    V_energy_isLoaded = true;
  }
  return V_energy_;
}

const float &hwwtree::V_SD_mass() {
  if (not V_SD_mass_isLoaded) {
    if (V_SD_mass_branch != 0) {
      V_SD_mass_branch->GetEntry(index);
    } else {
      printf("branch V_SD_mass_branch does not exist!\n");
      exit(1);
    }
    V_SD_mass_isLoaded = true;
  }
  return V_SD_mass_;
}

const float &hwwtree::V_tau31() {
  if (not V_tau31_isLoaded) {
    if (V_tau31_branch != 0) {
      V_tau31_branch->GetEntry(index);
    } else {
      printf("branch V_tau31_branch does not exist!\n");
      exit(1);
    }
    V_tau31_isLoaded = true;
  }
  return V_tau31_;
}

const float &hwwtree::V_tau32() {
  if (not V_tau32_isLoaded) {
    if (V_tau32_branch != 0) {
      V_tau32_branch->GetEntry(index);
    } else {
      printf("branch V_tau32_branch does not exist!\n");
      exit(1);
    }
    V_tau32_isLoaded = true;
  }
  return V_tau32_;
}

const float &hwwtree::V_tau21() {
  if (not V_tau21_isLoaded) {
    if (V_tau21_branch != 0) {
      V_tau21_branch->GetEntry(index);
    } else {
      printf("branch V_tau21_branch does not exist!\n");
      exit(1);
    }
    V_tau21_isLoaded = true;
  }
  return V_tau21_;
}

const float &hwwtree::V_tau1() {
  if (not V_tau1_isLoaded) {
    if (V_tau1_branch != 0) {
      V_tau1_branch->GetEntry(index);
    } else {
      printf("branch V_tau1_branch does not exist!\n");
      exit(1);
    }
    V_tau1_isLoaded = true;
  }
  return V_tau1_;
}

const float &hwwtree::V_tau2() {
  if (not V_tau2_isLoaded) {
    if (V_tau2_branch != 0) {
      V_tau2_branch->GetEntry(index);
    } else {
      printf("branch V_tau2_branch does not exist!\n");
      exit(1);
    }
    V_tau2_isLoaded = true;
  }
  return V_tau2_;
}

const float &hwwtree::V_tau3() {
  if (not V_tau3_isLoaded) {
    if (V_tau3_branch != 0) {
      V_tau3_branch->GetEntry(index);
    } else {
      printf("branch V_tau3_branch does not exist!\n");
      exit(1);
    }
    V_tau3_isLoaded = true;
  }
  return V_tau3_;
}

const float &hwwtree::V_undoJEC() {
  if (not V_undoJEC_isLoaded) {
    if (V_undoJEC_branch != 0) {
      V_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch V_undoJEC_branch does not exist!\n");
      exit(1);
    }
    V_undoJEC_isLoaded = true;
  }
  return V_undoJEC_;
}

const float &hwwtree::V_shift() {
  if (not V_shift_isLoaded) {
    if (V_shift_branch != 0) {
      V_shift_branch->GetEntry(index);
    } else {
      printf("branch V_shift_branch does not exist!\n");
      exit(1);
    }
    V_shift_isLoaded = true;
  }
  return V_shift_;
}

const float &hwwtree::V_deep_rawdisc_h4q() {
  if (not V_deep_rawdisc_h4q_isLoaded) {
    if (V_deep_rawdisc_h4q_branch != 0) {
      V_deep_rawdisc_h4q_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_h4q_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_h4q_isLoaded = true;
  }
  return V_deep_rawdisc_h4q_;
}

const float &hwwtree::V_deep_rawdisc_hbb() {
  if (not V_deep_rawdisc_hbb_isLoaded) {
    if (V_deep_rawdisc_hbb_branch != 0) {
      V_deep_rawdisc_hbb_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_hbb_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_hbb_isLoaded = true;
  }
  return V_deep_rawdisc_hbb_;
}

const float &hwwtree::V_deep_rawdisc_qcd() {
  if (not V_deep_rawdisc_qcd_isLoaded) {
    if (V_deep_rawdisc_qcd_branch != 0) {
      V_deep_rawdisc_qcd_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_qcd_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_qcd_isLoaded = true;
  }
  return V_deep_rawdisc_qcd_;
}

const float &hwwtree::V_deep_rawdisc_top() {
  if (not V_deep_rawdisc_top_isLoaded) {
    if (V_deep_rawdisc_top_branch != 0) {
      V_deep_rawdisc_top_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_top_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_top_isLoaded = true;
  }
  return V_deep_rawdisc_top_;
}

const float &hwwtree::V_deep_rawdisc_w() {
  if (not V_deep_rawdisc_w_isLoaded) {
    if (V_deep_rawdisc_w_branch != 0) {
      V_deep_rawdisc_w_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_w_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_w_isLoaded = true;
  }
  return V_deep_rawdisc_w_;
}

const float &hwwtree::V_deep_rawdisc_z() {
  if (not V_deep_rawdisc_z_isLoaded) {
    if (V_deep_rawdisc_z_branch != 0) {
      V_deep_rawdisc_z_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_z_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_z_isLoaded = true;
  }
  return V_deep_rawdisc_z_;
}

const float &hwwtree::V_deep_rawdisc_zbb() {
  if (not V_deep_rawdisc_zbb_isLoaded) {
    if (V_deep_rawdisc_zbb_branch != 0) {
      V_deep_rawdisc_zbb_branch->GetEntry(index);
    } else {
      printf("branch V_deep_rawdisc_zbb_branch does not exist!\n");
      exit(1);
    }
    V_deep_rawdisc_zbb_isLoaded = true;
  }
  return V_deep_rawdisc_zbb_;
}

const float &hwwtree::V_softdropPuppiSubjet1_pt() {
  if (not V_softdropPuppiSubjet1_pt_isLoaded) {
    if (V_softdropPuppiSubjet1_pt_branch != 0) {
      V_softdropPuppiSubjet1_pt_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet1_pt_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet1_pt_isLoaded = true;
  }
  return V_softdropPuppiSubjet1_pt_;
}

const float &hwwtree::V_softdropPuppiSubjet1_eta() {
  if (not V_softdropPuppiSubjet1_eta_isLoaded) {
    if (V_softdropPuppiSubjet1_eta_branch != 0) {
      V_softdropPuppiSubjet1_eta_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet1_eta_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet1_eta_isLoaded = true;
  }
  return V_softdropPuppiSubjet1_eta_;
}

const float &hwwtree::V_softdropPuppiSubjet1_phi() {
  if (not V_softdropPuppiSubjet1_phi_isLoaded) {
    if (V_softdropPuppiSubjet1_phi_branch != 0) {
      V_softdropPuppiSubjet1_phi_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet1_phi_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet1_phi_isLoaded = true;
  }
  return V_softdropPuppiSubjet1_phi_;
}

const float &hwwtree::V_softdropPuppiSubjet1_mass() {
  if (not V_softdropPuppiSubjet1_mass_isLoaded) {
    if (V_softdropPuppiSubjet1_mass_branch != 0) {
      V_softdropPuppiSubjet1_mass_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet1_mass_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet1_mass_isLoaded = true;
  }
  return V_softdropPuppiSubjet1_mass_;
}

const float &hwwtree::V_softdropPuppiSubjet1_energy() {
  if (not V_softdropPuppiSubjet1_energy_isLoaded) {
    if (V_softdropPuppiSubjet1_energy_branch != 0) {
      V_softdropPuppiSubjet1_energy_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet1_energy_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet1_energy_isLoaded = true;
  }
  return V_softdropPuppiSubjet1_energy_;
}

const float &hwwtree::V_softdropPuppiSubjet2_pt() {
  if (not V_softdropPuppiSubjet2_pt_isLoaded) {
    if (V_softdropPuppiSubjet2_pt_branch != 0) {
      V_softdropPuppiSubjet2_pt_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet2_pt_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet2_pt_isLoaded = true;
  }
  return V_softdropPuppiSubjet2_pt_;
}

const float &hwwtree::V_softdropPuppiSubjet2_eta() {
  if (not V_softdropPuppiSubjet2_eta_isLoaded) {
    if (V_softdropPuppiSubjet2_eta_branch != 0) {
      V_softdropPuppiSubjet2_eta_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet2_eta_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet2_eta_isLoaded = true;
  }
  return V_softdropPuppiSubjet2_eta_;
}

const float &hwwtree::V_softdropPuppiSubjet2_phi() {
  if (not V_softdropPuppiSubjet2_phi_isLoaded) {
    if (V_softdropPuppiSubjet2_phi_branch != 0) {
      V_softdropPuppiSubjet2_phi_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet2_phi_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet2_phi_isLoaded = true;
  }
  return V_softdropPuppiSubjet2_phi_;
}

const float &hwwtree::V_softdropPuppiSubjet2_mass() {
  if (not V_softdropPuppiSubjet2_mass_isLoaded) {
    if (V_softdropPuppiSubjet2_mass_branch != 0) {
      V_softdropPuppiSubjet2_mass_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet2_mass_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet2_mass_isLoaded = true;
  }
  return V_softdropPuppiSubjet2_mass_;
}

const float &hwwtree::V_softdropPuppiSubjet2_energy() {
  if (not V_softdropPuppiSubjet2_energy_isLoaded) {
    if (V_softdropPuppiSubjet2_energy_branch != 0) {
      V_softdropPuppiSubjet2_energy_branch->GetEntry(index);
    } else {
      printf("branch V_softdropPuppiSubjet2_energy_branch does not exist!\n");
      exit(1);
    }
    V_softdropPuppiSubjet2_energy_isLoaded = true;
  }
  return V_softdropPuppiSubjet2_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::LXJ_p4() {
  if (not LXJ_p4_isLoaded) {
    if (LXJ_p4_branch != 0) {
      LXJ_p4_branch->GetEntry(index);
    } else {
      printf("branch LXJ_p4_branch does not exist!\n");
      exit(1);
    }
    LXJ_p4_isLoaded = true;
  }
  return *LXJ_p4_;
}

const float &hwwtree::LXJ_pt() {
  if (not LXJ_pt_isLoaded) {
    if (LXJ_pt_branch != 0) {
      LXJ_pt_branch->GetEntry(index);
    } else {
      printf("branch LXJ_pt_branch does not exist!\n");
      exit(1);
    }
    LXJ_pt_isLoaded = true;
  }
  return LXJ_pt_;
}

const float &hwwtree::LXJ_eta() {
  if (not LXJ_eta_isLoaded) {
    if (LXJ_eta_branch != 0) {
      LXJ_eta_branch->GetEntry(index);
    } else {
      printf("branch LXJ_eta_branch does not exist!\n");
      exit(1);
    }
    LXJ_eta_isLoaded = true;
  }
  return LXJ_eta_;
}

const float &hwwtree::LXJ_phi() {
  if (not LXJ_phi_isLoaded) {
    if (LXJ_phi_branch != 0) {
      LXJ_phi_branch->GetEntry(index);
    } else {
      printf("branch LXJ_phi_branch does not exist!\n");
      exit(1);
    }
    LXJ_phi_isLoaded = true;
  }
  return LXJ_phi_;
}

const float &hwwtree::LXJ_mass() {
  if (not LXJ_mass_isLoaded) {
    if (LXJ_mass_branch != 0) {
      LXJ_mass_branch->GetEntry(index);
    } else {
      printf("branch LXJ_mass_branch does not exist!\n");
      exit(1);
    }
    LXJ_mass_isLoaded = true;
  }
  return LXJ_mass_;
}

const float &hwwtree::LXJ_energy() {
  if (not LXJ_energy_isLoaded) {
    if (LXJ_energy_branch != 0) {
      LXJ_energy_branch->GetEntry(index);
    } else {
      printf("branch LXJ_energy_branch does not exist!\n");
      exit(1);
    }
    LXJ_energy_isLoaded = true;
  }
  return LXJ_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::LXJ_SD_p4() {
  if (not LXJ_SD_p4_isLoaded) {
    if (LXJ_SD_p4_branch != 0) {
      LXJ_SD_p4_branch->GetEntry(index);
    } else {
      printf("branch LXJ_SD_p4_branch does not exist!\n");
      exit(1);
    }
    LXJ_SD_p4_isLoaded = true;
  }
  return *LXJ_SD_p4_;
}

const float &hwwtree::LXJ_SD_pt() {
  if (not LXJ_SD_pt_isLoaded) {
    if (LXJ_SD_pt_branch != 0) {
      LXJ_SD_pt_branch->GetEntry(index);
    } else {
      printf("branch LXJ_SD_pt_branch does not exist!\n");
      exit(1);
    }
    LXJ_SD_pt_isLoaded = true;
  }
  return LXJ_SD_pt_;
}

const float &hwwtree::LXJ_SD_eta() {
  if (not LXJ_SD_eta_isLoaded) {
    if (LXJ_SD_eta_branch != 0) {
      LXJ_SD_eta_branch->GetEntry(index);
    } else {
      printf("branch LXJ_SD_eta_branch does not exist!\n");
      exit(1);
    }
    LXJ_SD_eta_isLoaded = true;
  }
  return LXJ_SD_eta_;
}

const float &hwwtree::LXJ_SD_phi() {
  if (not LXJ_SD_phi_isLoaded) {
    if (LXJ_SD_phi_branch != 0) {
      LXJ_SD_phi_branch->GetEntry(index);
    } else {
      printf("branch LXJ_SD_phi_branch does not exist!\n");
      exit(1);
    }
    LXJ_SD_phi_isLoaded = true;
  }
  return LXJ_SD_phi_;
}

const float &hwwtree::LXJ_SD_mass() {
  if (not LXJ_SD_mass_isLoaded) {
    if (LXJ_SD_mass_branch != 0) {
      LXJ_SD_mass_branch->GetEntry(index);
    } else {
      printf("branch LXJ_SD_mass_branch does not exist!\n");
      exit(1);
    }
    LXJ_SD_mass_isLoaded = true;
  }
  return LXJ_SD_mass_;
}

const float &hwwtree::LXJ_SD_energy() {
  if (not LXJ_SD_energy_isLoaded) {
    if (LXJ_SD_energy_branch != 0) {
      LXJ_SD_energy_branch->GetEntry(index);
    } else {
      printf("branch LXJ_SD_energy_branch does not exist!\n");
      exit(1);
    }
    LXJ_SD_energy_isLoaded = true;
  }
  return LXJ_SD_energy_;
}

const float &hwwtree::LX_pt() {
  if (not LX_pt_isLoaded) {
    if (LX_pt_branch != 0) {
      LX_pt_branch->GetEntry(index);
    } else {
      printf("branch LX_pt_branch does not exist!\n");
      exit(1);
    }
    LX_pt_isLoaded = true;
  }
  return LX_pt_;
}

const float &hwwtree::LX_mt() {
  if (not LX_mt_isLoaded) {
    if (LX_mt_branch != 0) {
      LX_mt_branch->GetEntry(index);
    } else {
      printf("branch LX_mt_branch does not exist!\n");
      exit(1);
    }
    LX_mt_isLoaded = true;
  }
  return LX_mt_;
}

const float &hwwtree::LX_mass() {
  if (not LX_mass_isLoaded) {
    if (LX_mass_branch != 0) {
      LX_mass_branch->GetEntry(index);
    } else {
      printf("branch LX_mass_branch does not exist!\n");
      exit(1);
    }
    LX_mass_isLoaded = true;
  }
  return LX_mass_;
}

const float &hwwtree::LX_dphi() {
  if (not LX_dphi_isLoaded) {
    if (LX_dphi_branch != 0) {
      LX_dphi_branch->GetEntry(index);
    } else {
      printf("branch LX_dphi_branch does not exist!\n");
      exit(1);
    }
    LX_dphi_isLoaded = true;
  }
  return LX_dphi_;
}

const float &hwwtree::LJ_pt() {
  if (not LJ_pt_isLoaded) {
    if (LJ_pt_branch != 0) {
      LJ_pt_branch->GetEntry(index);
    } else {
      printf("branch LJ_pt_branch does not exist!\n");
      exit(1);
    }
    LJ_pt_isLoaded = true;
  }
  return LJ_pt_;
}

const float &hwwtree::LJ_mt() {
  if (not LJ_mt_isLoaded) {
    if (LJ_mt_branch != 0) {
      LJ_mt_branch->GetEntry(index);
    } else {
      printf("branch LJ_mt_branch does not exist!\n");
      exit(1);
    }
    LJ_mt_isLoaded = true;
  }
  return LJ_mt_;
}

const float &hwwtree::LJ_mass() {
  if (not LJ_mass_isLoaded) {
    if (LJ_mass_branch != 0) {
      LJ_mass_branch->GetEntry(index);
    } else {
      printf("branch LJ_mass_branch does not exist!\n");
      exit(1);
    }
    LJ_mass_isLoaded = true;
  }
  return LJ_mass_;
}

const float &hwwtree::LJ_dphi() {
  if (not LJ_dphi_isLoaded) {
    if (LJ_dphi_branch != 0) {
      LJ_dphi_branch->GetEntry(index);
    } else {
      printf("branch LJ_dphi_branch does not exist!\n");
      exit(1);
    }
    LJ_dphi_isLoaded = true;
  }
  return LJ_dphi_;
}

const float &hwwtree::LJ_deta() {
  if (not LJ_deta_isLoaded) {
    if (LJ_deta_branch != 0) {
      LJ_deta_branch->GetEntry(index);
    } else {
      printf("branch LJ_deta_branch does not exist!\n");
      exit(1);
    }
    LJ_deta_isLoaded = true;
  }
  return LJ_deta_;
}

const float &hwwtree::LJ_dr() {
  if (not LJ_dr_isLoaded) {
    if (LJ_dr_branch != 0) {
      LJ_dr_branch->GetEntry(index);
    } else {
      printf("branch LJ_dr_branch does not exist!\n");
      exit(1);
    }
    LJ_dr_isLoaded = true;
  }
  return LJ_dr_;
}

const float &hwwtree::LJ_dptf() {
  if (not LJ_dptf_isLoaded) {
    if (LJ_dptf_branch != 0) {
      LJ_dptf_branch->GetEntry(index);
    } else {
      printf("branch LJ_dptf_branch does not exist!\n");
      exit(1);
    }
    LJ_dptf_isLoaded = true;
  }
  return LJ_dptf_;
}

const float &hwwtree::LJ_SD_pt() {
  if (not LJ_SD_pt_isLoaded) {
    if (LJ_SD_pt_branch != 0) {
      LJ_SD_pt_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_pt_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_pt_isLoaded = true;
  }
  return LJ_SD_pt_;
}

const float &hwwtree::LJ_SD_mt() {
  if (not LJ_SD_mt_isLoaded) {
    if (LJ_SD_mt_branch != 0) {
      LJ_SD_mt_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_mt_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_mt_isLoaded = true;
  }
  return LJ_SD_mt_;
}

const float &hwwtree::LJ_SD_mass() {
  if (not LJ_SD_mass_isLoaded) {
    if (LJ_SD_mass_branch != 0) {
      LJ_SD_mass_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_mass_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_mass_isLoaded = true;
  }
  return LJ_SD_mass_;
}

const float &hwwtree::LJ_SD_dphi() {
  if (not LJ_SD_dphi_isLoaded) {
    if (LJ_SD_dphi_branch != 0) {
      LJ_SD_dphi_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_dphi_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_dphi_isLoaded = true;
  }
  return LJ_SD_dphi_;
}

const float &hwwtree::LJ_SD_deta() {
  if (not LJ_SD_deta_isLoaded) {
    if (LJ_SD_deta_branch != 0) {
      LJ_SD_deta_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_deta_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_deta_isLoaded = true;
  }
  return LJ_SD_deta_;
}

const float &hwwtree::LJ_SD_dr() {
  if (not LJ_SD_dr_isLoaded) {
    if (LJ_SD_dr_branch != 0) {
      LJ_SD_dr_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_dr_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_dr_isLoaded = true;
  }
  return LJ_SD_dr_;
}

const float &hwwtree::LJ_SD_dptf() {
  if (not LJ_SD_dptf_isLoaded) {
    if (LJ_SD_dptf_branch != 0) {
      LJ_SD_dptf_branch->GetEntry(index);
    } else {
      printf("branch LJ_SD_dptf_branch does not exist!\n");
      exit(1);
    }
    LJ_SD_dptf_isLoaded = true;
  }
  return LJ_SD_dptf_;
}

const float &hwwtree::Lq0_pt() {
  if (not Lq0_pt_isLoaded) {
    if (Lq0_pt_branch != 0) {
      Lq0_pt_branch->GetEntry(index);
    } else {
      printf("branch Lq0_pt_branch does not exist!\n");
      exit(1);
    }
    Lq0_pt_isLoaded = true;
  }
  return Lq0_pt_;
}

const float &hwwtree::Lq0_mt() {
  if (not Lq0_mt_isLoaded) {
    if (Lq0_mt_branch != 0) {
      Lq0_mt_branch->GetEntry(index);
    } else {
      printf("branch Lq0_mt_branch does not exist!\n");
      exit(1);
    }
    Lq0_mt_isLoaded = true;
  }
  return Lq0_mt_;
}

const float &hwwtree::Lq0_mass() {
  if (not Lq0_mass_isLoaded) {
    if (Lq0_mass_branch != 0) {
      Lq0_mass_branch->GetEntry(index);
    } else {
      printf("branch Lq0_mass_branch does not exist!\n");
      exit(1);
    }
    Lq0_mass_isLoaded = true;
  }
  return Lq0_mass_;
}

const float &hwwtree::Lq0_dphi() {
  if (not Lq0_dphi_isLoaded) {
    if (Lq0_dphi_branch != 0) {
      Lq0_dphi_branch->GetEntry(index);
    } else {
      printf("branch Lq0_dphi_branch does not exist!\n");
      exit(1);
    }
    Lq0_dphi_isLoaded = true;
  }
  return Lq0_dphi_;
}

const float &hwwtree::Lq0_deta() {
  if (not Lq0_deta_isLoaded) {
    if (Lq0_deta_branch != 0) {
      Lq0_deta_branch->GetEntry(index);
    } else {
      printf("branch Lq0_deta_branch does not exist!\n");
      exit(1);
    }
    Lq0_deta_isLoaded = true;
  }
  return Lq0_deta_;
}

const float &hwwtree::Lq0_dr() {
  if (not Lq0_dr_isLoaded) {
    if (Lq0_dr_branch != 0) {
      Lq0_dr_branch->GetEntry(index);
    } else {
      printf("branch Lq0_dr_branch does not exist!\n");
      exit(1);
    }
    Lq0_dr_isLoaded = true;
  }
  return Lq0_dr_;
}

const float &hwwtree::Lq0_dptf() {
  if (not Lq0_dptf_isLoaded) {
    if (Lq0_dptf_branch != 0) {
      Lq0_dptf_branch->GetEntry(index);
    } else {
      printf("branch Lq0_dptf_branch does not exist!\n");
      exit(1);
    }
    Lq0_dptf_isLoaded = true;
  }
  return Lq0_dptf_;
}

const float &hwwtree::Lq1_pt() {
  if (not Lq1_pt_isLoaded) {
    if (Lq1_pt_branch != 0) {
      Lq1_pt_branch->GetEntry(index);
    } else {
      printf("branch Lq1_pt_branch does not exist!\n");
      exit(1);
    }
    Lq1_pt_isLoaded = true;
  }
  return Lq1_pt_;
}

const float &hwwtree::Lq1_mt() {
  if (not Lq1_mt_isLoaded) {
    if (Lq1_mt_branch != 0) {
      Lq1_mt_branch->GetEntry(index);
    } else {
      printf("branch Lq1_mt_branch does not exist!\n");
      exit(1);
    }
    Lq1_mt_isLoaded = true;
  }
  return Lq1_mt_;
}

const float &hwwtree::Lq1_mass() {
  if (not Lq1_mass_isLoaded) {
    if (Lq1_mass_branch != 0) {
      Lq1_mass_branch->GetEntry(index);
    } else {
      printf("branch Lq1_mass_branch does not exist!\n");
      exit(1);
    }
    Lq1_mass_isLoaded = true;
  }
  return Lq1_mass_;
}

const float &hwwtree::Lq1_dphi() {
  if (not Lq1_dphi_isLoaded) {
    if (Lq1_dphi_branch != 0) {
      Lq1_dphi_branch->GetEntry(index);
    } else {
      printf("branch Lq1_dphi_branch does not exist!\n");
      exit(1);
    }
    Lq1_dphi_isLoaded = true;
  }
  return Lq1_dphi_;
}

const float &hwwtree::Lq1_deta() {
  if (not Lq1_deta_isLoaded) {
    if (Lq1_deta_branch != 0) {
      Lq1_deta_branch->GetEntry(index);
    } else {
      printf("branch Lq1_deta_branch does not exist!\n");
      exit(1);
    }
    Lq1_deta_isLoaded = true;
  }
  return Lq1_deta_;
}

const float &hwwtree::Lq1_dr() {
  if (not Lq1_dr_isLoaded) {
    if (Lq1_dr_branch != 0) {
      Lq1_dr_branch->GetEntry(index);
    } else {
      printf("branch Lq1_dr_branch does not exist!\n");
      exit(1);
    }
    Lq1_dr_isLoaded = true;
  }
  return Lq1_dr_;
}

const float &hwwtree::Lq1_dptf() {
  if (not Lq1_dptf_isLoaded) {
    if (Lq1_dptf_branch != 0) {
      Lq1_dptf_branch->GetEntry(index);
    } else {
      printf("branch Lq1_dptf_branch does not exist!\n");
      exit(1);
    }
    Lq1_dptf_isLoaded = true;
  }
  return Lq1_dptf_;
}

const float &hwwtree::Lqmax_pt() {
  if (not Lqmax_pt_isLoaded) {
    if (Lqmax_pt_branch != 0) {
      Lqmax_pt_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_pt_branch does not exist!\n");
      exit(1);
    }
    Lqmax_pt_isLoaded = true;
  }
  return Lqmax_pt_;
}

const float &hwwtree::Lqmax_mt() {
  if (not Lqmax_mt_isLoaded) {
    if (Lqmax_mt_branch != 0) {
      Lqmax_mt_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_mt_branch does not exist!\n");
      exit(1);
    }
    Lqmax_mt_isLoaded = true;
  }
  return Lqmax_mt_;
}

const float &hwwtree::Lqmax_mass() {
  if (not Lqmax_mass_isLoaded) {
    if (Lqmax_mass_branch != 0) {
      Lqmax_mass_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_mass_branch does not exist!\n");
      exit(1);
    }
    Lqmax_mass_isLoaded = true;
  }
  return Lqmax_mass_;
}

const float &hwwtree::Lqmax_dphi() {
  if (not Lqmax_dphi_isLoaded) {
    if (Lqmax_dphi_branch != 0) {
      Lqmax_dphi_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_dphi_branch does not exist!\n");
      exit(1);
    }
    Lqmax_dphi_isLoaded = true;
  }
  return Lqmax_dphi_;
}

const float &hwwtree::Lqmax_deta() {
  if (not Lqmax_deta_isLoaded) {
    if (Lqmax_deta_branch != 0) {
      Lqmax_deta_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_deta_branch does not exist!\n");
      exit(1);
    }
    Lqmax_deta_isLoaded = true;
  }
  return Lqmax_deta_;
}

const float &hwwtree::Lqmax_dr() {
  if (not Lqmax_dr_isLoaded) {
    if (Lqmax_dr_branch != 0) {
      Lqmax_dr_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_dr_branch does not exist!\n");
      exit(1);
    }
    Lqmax_dr_isLoaded = true;
  }
  return Lqmax_dr_;
}

const float &hwwtree::Lqmax_dptf() {
  if (not Lqmax_dptf_isLoaded) {
    if (Lqmax_dptf_branch != 0) {
      Lqmax_dptf_branch->GetEntry(index);
    } else {
      printf("branch Lqmax_dptf_branch does not exist!\n");
      exit(1);
    }
    Lqmax_dptf_isLoaded = true;
  }
  return Lqmax_dptf_;
}

const float &hwwtree::LHRatio() {
  if (not LHRatio_isLoaded) {
    if (LHRatio_branch != 0) {
      LHRatio_branch->GetEntry(index);
    } else {
      printf("branch LHRatio_branch does not exist!\n");
      exit(1);
    }
    LHRatio_isLoaded = true;
  }
  return LHRatio_;
}

const float &hwwtree::LHRatio_SD() {
  if (not LHRatio_SD_isLoaded) {
    if (LHRatio_SD_branch != 0) {
      LHRatio_SD_branch->GetEntry(index);
    } else {
      printf("branch LHRatio_SD_branch does not exist!\n");
      exit(1);
    }
    LHRatio_SD_isLoaded = true;
  }
  return LHRatio_SD_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::neu_p4() {
  if (not neu_p4_isLoaded) {
    if (neu_p4_branch != 0) {
      neu_p4_branch->GetEntry(index);
    } else {
      printf("branch neu_p4_branch does not exist!\n");
      exit(1);
    }
    neu_p4_isLoaded = true;
  }
  return *neu_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::neu_p4_h() {
  if (not neu_p4_h_isLoaded) {
    if (neu_p4_h_branch != 0) {
      neu_p4_h_branch->GetEntry(index);
    } else {
      printf("branch neu_p4_h_branch does not exist!\n");
      exit(1);
    }
    neu_p4_h_isLoaded = true;
  }
  return *neu_p4_h_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Wlep_p4() {
  if (not Wlep_p4_isLoaded) {
    if (Wlep_p4_branch != 0) {
      Wlep_p4_branch->GetEntry(index);
    } else {
      printf("branch Wlep_p4_branch does not exist!\n");
      exit(1);
    }
    Wlep_p4_isLoaded = true;
  }
  return *Wlep_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::Wlep_h_p4() {
  if (not Wlep_h_p4_isLoaded) {
    if (Wlep_h_p4_branch != 0) {
      Wlep_h_p4_branch->GetEntry(index);
    } else {
      printf("branch Wlep_h_p4_branch does not exist!\n");
      exit(1);
    }
    Wlep_h_p4_isLoaded = true;
  }
  return *Wlep_h_p4_;
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::H_mh_p4() {
  if (not H_mh_p4_isLoaded) {
    if (H_mh_p4_branch != 0) {
      H_mh_p4_branch->GetEntry(index);
    } else {
      printf("branch H_mh_p4_branch does not exist!\n");
      exit(1);
    }
    H_mh_p4_isLoaded = true;
  }
  return *H_mh_p4_;
}

const float &hwwtree::det() {
  if (not det_isLoaded) {
    if (det_branch != 0) {
      det_branch->GetEntry(index);
    } else {
      printf("branch det_branch does not exist!\n");
      exit(1);
    }
    det_isLoaded = true;
  }
  return det_;
}

const float &hwwtree::detW() {
  if (not detW_isLoaded) {
    if (detW_branch != 0) {
      detW_branch->GetEntry(index);
    } else {
      printf("branch detW_branch does not exist!\n");
      exit(1);
    }
    detW_isLoaded = true;
  }
  return detW_;
}

const float &hwwtree::mH() {
  if (not mH_isLoaded) {
    if (mH_branch != 0) {
      mH_branch->GetEntry(index);
    } else {
      printf("branch mH_branch does not exist!\n");
      exit(1);
    }
    mH_isLoaded = true;
  }
  return mH_;
}

const float &hwwtree::mD() {
  if (not mD_isLoaded) {
    if (mD_branch != 0) {
      mD_branch->GetEntry(index);
    } else {
      printf("branch mD_branch does not exist!\n");
      exit(1);
    }
    mD_isLoaded = true;
  }
  return mD_;
}

const float &hwwtree::mD_SD() {
  if (not mD_SD_isLoaded) {
    if (mD_SD_branch != 0) {
      mD_SD_branch->GetEntry(index);
    } else {
      printf("branch mD_SD_branch does not exist!\n");
      exit(1);
    }
    mD_SD_isLoaded = true;
  }
  return mD_SD_;
}

const float &hwwtree::mD_Wlep() {
  if (not mD_Wlep_isLoaded) {
    if (mD_Wlep_branch != 0) {
      mD_Wlep_branch->GetEntry(index);
    } else {
      printf("branch mD_Wlep_branch does not exist!\n");
      exit(1);
    }
    mD_Wlep_isLoaded = true;
  }
  return mD_Wlep_;
}

const vector<float> &hwwtree::j_dphis() {
  if (not j_dphis_isLoaded) {
    if (j_dphis_branch != 0) {
      j_dphis_branch->GetEntry(index);
    } else {
      printf("branch j_dphis_branch does not exist!\n");
      exit(1);
    }
    j_dphis_isLoaded = true;
  }
  return *j_dphis_;
}

const vector<float> &hwwtree::j_drs() {
  if (not j_drs_isLoaded) {
    if (j_drs_branch != 0) {
      j_drs_branch->GetEntry(index);
    } else {
      printf("branch j_drs_branch does not exist!\n");
      exit(1);
    }
    j_drs_isLoaded = true;
  }
  return *j_drs_;
}

const vector<float> &hwwtree::j_SD_dphis() {
  if (not j_SD_dphis_isLoaded) {
    if (j_SD_dphis_branch != 0) {
      j_SD_dphis_branch->GetEntry(index);
    } else {
      printf("branch j_SD_dphis_branch does not exist!\n");
      exit(1);
    }
    j_SD_dphis_isLoaded = true;
  }
  return *j_SD_dphis_;
}

const vector<float> &hwwtree::j_SD_drs() {
  if (not j_SD_drs_isLoaded) {
    if (j_SD_drs_branch != 0) {
      j_SD_drs_branch->GetEntry(index);
    } else {
      printf("branch j_SD_drs_branch does not exist!\n");
      exit(1);
    }
    j_SD_drs_isLoaded = true;
  }
  return *j_SD_drs_;
}

const vector<float> &hwwtree::j_pts() {
  if (not j_pts_isLoaded) {
    if (j_pts_branch != 0) {
      j_pts_branch->GetEntry(index);
    } else {
      printf("branch j_pts_branch does not exist!\n");
      exit(1);
    }
    j_pts_isLoaded = true;
  }
  return *j_pts_;
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

const int &hwwtree::nj_in() {
  if (not nj_in_isLoaded) {
    if (nj_in_branch != 0) {
      nj_in_branch->GetEntry(index);
    } else {
      printf("branch nj_in_branch does not exist!\n");
      exit(1);
    }
    nj_in_isLoaded = true;
  }
  return nj_in_;
}

const int &hwwtree::nj_annuli() {
  if (not nj_annuli_isLoaded) {
    if (nj_annuli_branch != 0) {
      nj_annuli_branch->GetEntry(index);
    } else {
      printf("branch nj_annuli_branch does not exist!\n");
      exit(1);
    }
    nj_annuli_isLoaded = true;
  }
  return nj_annuli_;
}

const int &hwwtree::nj_same() {
  if (not nj_same_isLoaded) {
    if (nj_same_branch != 0) {
      nj_same_branch->GetEntry(index);
    } else {
      printf("branch nj_same_branch does not exist!\n");
      exit(1);
    }
    nj_same_isLoaded = true;
  }
  return nj_same_;
}

const int &hwwtree::nj_away() {
  if (not nj_away_isLoaded) {
    if (nj_away_branch != 0) {
      nj_away_branch->GetEntry(index);
    } else {
      printf("branch nj_away_branch does not exist!\n");
      exit(1);
    }
    nj_away_isLoaded = true;
  }
  return nj_away_;
}

const int &hwwtree::nj_SD_in() {
  if (not nj_SD_in_isLoaded) {
    if (nj_SD_in_branch != 0) {
      nj_SD_in_branch->GetEntry(index);
    } else {
      printf("branch nj_SD_in_branch does not exist!\n");
      exit(1);
    }
    nj_SD_in_isLoaded = true;
  }
  return nj_SD_in_;
}

const int &hwwtree::nj_SD_annuli() {
  if (not nj_SD_annuli_isLoaded) {
    if (nj_SD_annuli_branch != 0) {
      nj_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch nj_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    nj_SD_annuli_isLoaded = true;
  }
  return nj_SD_annuli_;
}

const int &hwwtree::nj_SD_same() {
  if (not nj_SD_same_isLoaded) {
    if (nj_SD_same_branch != 0) {
      nj_SD_same_branch->GetEntry(index);
    } else {
      printf("branch nj_SD_same_branch does not exist!\n");
      exit(1);
    }
    nj_SD_same_isLoaded = true;
  }
  return nj_SD_same_;
}

const int &hwwtree::nj_SD_away() {
  if (not nj_SD_away_isLoaded) {
    if (nj_SD_away_branch != 0) {
      nj_SD_away_branch->GetEntry(index);
    } else {
      printf("branch nj_SD_away_branch does not exist!\n");
      exit(1);
    }
    nj_SD_away_isLoaded = true;
  }
  return nj_SD_away_;
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

const int &hwwtree::nb_in() {
  if (not nb_in_isLoaded) {
    if (nb_in_branch != 0) {
      nb_in_branch->GetEntry(index);
    } else {
      printf("branch nb_in_branch does not exist!\n");
      exit(1);
    }
    nb_in_isLoaded = true;
  }
  return nb_in_;
}

const int &hwwtree::nb_annuli() {
  if (not nb_annuli_isLoaded) {
    if (nb_annuli_branch != 0) {
      nb_annuli_branch->GetEntry(index);
    } else {
      printf("branch nb_annuli_branch does not exist!\n");
      exit(1);
    }
    nb_annuli_isLoaded = true;
  }
  return nb_annuli_;
}

const int &hwwtree::nb_same() {
  if (not nb_same_isLoaded) {
    if (nb_same_branch != 0) {
      nb_same_branch->GetEntry(index);
    } else {
      printf("branch nb_same_branch does not exist!\n");
      exit(1);
    }
    nb_same_isLoaded = true;
  }
  return nb_same_;
}

const int &hwwtree::nb_away() {
  if (not nb_away_isLoaded) {
    if (nb_away_branch != 0) {
      nb_away_branch->GetEntry(index);
    } else {
      printf("branch nb_away_branch does not exist!\n");
      exit(1);
    }
    nb_away_isLoaded = true;
  }
  return nb_away_;
}

const int &hwwtree::nb_SD_in() {
  if (not nb_SD_in_isLoaded) {
    if (nb_SD_in_branch != 0) {
      nb_SD_in_branch->GetEntry(index);
    } else {
      printf("branch nb_SD_in_branch does not exist!\n");
      exit(1);
    }
    nb_SD_in_isLoaded = true;
  }
  return nb_SD_in_;
}

const int &hwwtree::nb_SD_annuli() {
  if (not nb_SD_annuli_isLoaded) {
    if (nb_SD_annuli_branch != 0) {
      nb_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch nb_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    nb_SD_annuli_isLoaded = true;
  }
  return nb_SD_annuli_;
}

const int &hwwtree::nb_SD_same() {
  if (not nb_SD_same_isLoaded) {
    if (nb_SD_same_branch != 0) {
      nb_SD_same_branch->GetEntry(index);
    } else {
      printf("branch nb_SD_same_branch does not exist!\n");
      exit(1);
    }
    nb_SD_same_isLoaded = true;
  }
  return nb_SD_same_;
}

const int &hwwtree::nb_SD_away() {
  if (not nb_SD_away_isLoaded) {
    if (nb_SD_away_branch != 0) {
      nb_SD_away_branch->GetEntry(index);
    } else {
      printf("branch nb_SD_away_branch does not exist!\n");
      exit(1);
    }
    nb_SD_away_isLoaded = true;
  }
  return nb_SD_away_;
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

const int &hwwtree::nbmed_in() {
  if (not nbmed_in_isLoaded) {
    if (nbmed_in_branch != 0) {
      nbmed_in_branch->GetEntry(index);
    } else {
      printf("branch nbmed_in_branch does not exist!\n");
      exit(1);
    }
    nbmed_in_isLoaded = true;
  }
  return nbmed_in_;
}

const int &hwwtree::nbmed_annuli() {
  if (not nbmed_annuli_isLoaded) {
    if (nbmed_annuli_branch != 0) {
      nbmed_annuli_branch->GetEntry(index);
    } else {
      printf("branch nbmed_annuli_branch does not exist!\n");
      exit(1);
    }
    nbmed_annuli_isLoaded = true;
  }
  return nbmed_annuli_;
}

const int &hwwtree::nbmed_same() {
  if (not nbmed_same_isLoaded) {
    if (nbmed_same_branch != 0) {
      nbmed_same_branch->GetEntry(index);
    } else {
      printf("branch nbmed_same_branch does not exist!\n");
      exit(1);
    }
    nbmed_same_isLoaded = true;
  }
  return nbmed_same_;
}

const int &hwwtree::nbmed_away() {
  if (not nbmed_away_isLoaded) {
    if (nbmed_away_branch != 0) {
      nbmed_away_branch->GetEntry(index);
    } else {
      printf("branch nbmed_away_branch does not exist!\n");
      exit(1);
    }
    nbmed_away_isLoaded = true;
  }
  return nbmed_away_;
}

const int &hwwtree::nbmed_SD_in() {
  if (not nbmed_SD_in_isLoaded) {
    if (nbmed_SD_in_branch != 0) {
      nbmed_SD_in_branch->GetEntry(index);
    } else {
      printf("branch nbmed_SD_in_branch does not exist!\n");
      exit(1);
    }
    nbmed_SD_in_isLoaded = true;
  }
  return nbmed_SD_in_;
}

const int &hwwtree::nbmed_SD_annuli() {
  if (not nbmed_SD_annuli_isLoaded) {
    if (nbmed_SD_annuli_branch != 0) {
      nbmed_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch nbmed_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    nbmed_SD_annuli_isLoaded = true;
  }
  return nbmed_SD_annuli_;
}

const int &hwwtree::nbmed_SD_same() {
  if (not nbmed_SD_same_isLoaded) {
    if (nbmed_SD_same_branch != 0) {
      nbmed_SD_same_branch->GetEntry(index);
    } else {
      printf("branch nbmed_SD_same_branch does not exist!\n");
      exit(1);
    }
    nbmed_SD_same_isLoaded = true;
  }
  return nbmed_SD_same_;
}

const int &hwwtree::nbmed_SD_away() {
  if (not nbmed_SD_away_isLoaded) {
    if (nbmed_SD_away_branch != 0) {
      nbmed_SD_away_branch->GetEntry(index);
    } else {
      printf("branch nbmed_SD_away_branch does not exist!\n");
      exit(1);
    }
    nbmed_SD_away_isLoaded = true;
  }
  return nbmed_SD_away_;
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

const int &hwwtree::nbtight_in() {
  if (not nbtight_in_isLoaded) {
    if (nbtight_in_branch != 0) {
      nbtight_in_branch->GetEntry(index);
    } else {
      printf("branch nbtight_in_branch does not exist!\n");
      exit(1);
    }
    nbtight_in_isLoaded = true;
  }
  return nbtight_in_;
}

const int &hwwtree::nbtight_annuli() {
  if (not nbtight_annuli_isLoaded) {
    if (nbtight_annuli_branch != 0) {
      nbtight_annuli_branch->GetEntry(index);
    } else {
      printf("branch nbtight_annuli_branch does not exist!\n");
      exit(1);
    }
    nbtight_annuli_isLoaded = true;
  }
  return nbtight_annuli_;
}

const int &hwwtree::nbtight_same() {
  if (not nbtight_same_isLoaded) {
    if (nbtight_same_branch != 0) {
      nbtight_same_branch->GetEntry(index);
    } else {
      printf("branch nbtight_same_branch does not exist!\n");
      exit(1);
    }
    nbtight_same_isLoaded = true;
  }
  return nbtight_same_;
}

const int &hwwtree::nbtight_away() {
  if (not nbtight_away_isLoaded) {
    if (nbtight_away_branch != 0) {
      nbtight_away_branch->GetEntry(index);
    } else {
      printf("branch nbtight_away_branch does not exist!\n");
      exit(1);
    }
    nbtight_away_isLoaded = true;
  }
  return nbtight_away_;
}

const int &hwwtree::nbtight_SD_in() {
  if (not nbtight_SD_in_isLoaded) {
    if (nbtight_SD_in_branch != 0) {
      nbtight_SD_in_branch->GetEntry(index);
    } else {
      printf("branch nbtight_SD_in_branch does not exist!\n");
      exit(1);
    }
    nbtight_SD_in_isLoaded = true;
  }
  return nbtight_SD_in_;
}

const int &hwwtree::nbtight_SD_annuli() {
  if (not nbtight_SD_annuli_isLoaded) {
    if (nbtight_SD_annuli_branch != 0) {
      nbtight_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch nbtight_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    nbtight_SD_annuli_isLoaded = true;
  }
  return nbtight_SD_annuli_;
}

const int &hwwtree::nbtight_SD_same() {
  if (not nbtight_SD_same_isLoaded) {
    if (nbtight_SD_same_branch != 0) {
      nbtight_SD_same_branch->GetEntry(index);
    } else {
      printf("branch nbtight_SD_same_branch does not exist!\n");
      exit(1);
    }
    nbtight_SD_same_isLoaded = true;
  }
  return nbtight_SD_same_;
}

const int &hwwtree::nbtight_SD_away() {
  if (not nbtight_SD_away_isLoaded) {
    if (nbtight_SD_away_branch != 0) {
      nbtight_SD_away_branch->GetEntry(index);
    } else {
      printf("branch nbtight_SD_away_branch does not exist!\n");
      exit(1);
    }
    nbtight_SD_away_isLoaded = true;
  }
  return nbtight_SD_away_;
}

const float &hwwtree::ht() {
  if (not ht_isLoaded) {
    if (ht_branch != 0) {
      ht_branch->GetEntry(index);
    } else {
      printf("branch ht_branch does not exist!\n");
      exit(1);
    }
    ht_isLoaded = true;
  }
  return ht_;
}

const float &hwwtree::ht_in() {
  if (not ht_in_isLoaded) {
    if (ht_in_branch != 0) {
      ht_in_branch->GetEntry(index);
    } else {
      printf("branch ht_in_branch does not exist!\n");
      exit(1);
    }
    ht_in_isLoaded = true;
  }
  return ht_in_;
}

const float &hwwtree::ht_annuli() {
  if (not ht_annuli_isLoaded) {
    if (ht_annuli_branch != 0) {
      ht_annuli_branch->GetEntry(index);
    } else {
      printf("branch ht_annuli_branch does not exist!\n");
      exit(1);
    }
    ht_annuli_isLoaded = true;
  }
  return ht_annuli_;
}

const float &hwwtree::ht_same() {
  if (not ht_same_isLoaded) {
    if (ht_same_branch != 0) {
      ht_same_branch->GetEntry(index);
    } else {
      printf("branch ht_same_branch does not exist!\n");
      exit(1);
    }
    ht_same_isLoaded = true;
  }
  return ht_same_;
}

const float &hwwtree::ht_away() {
  if (not ht_away_isLoaded) {
    if (ht_away_branch != 0) {
      ht_away_branch->GetEntry(index);
    } else {
      printf("branch ht_away_branch does not exist!\n");
      exit(1);
    }
    ht_away_isLoaded = true;
  }
  return ht_away_;
}

const float &hwwtree::ht_SD_in() {
  if (not ht_SD_in_isLoaded) {
    if (ht_SD_in_branch != 0) {
      ht_SD_in_branch->GetEntry(index);
    } else {
      printf("branch ht_SD_in_branch does not exist!\n");
      exit(1);
    }
    ht_SD_in_isLoaded = true;
  }
  return ht_SD_in_;
}

const float &hwwtree::ht_SD_annuli() {
  if (not ht_SD_annuli_isLoaded) {
    if (ht_SD_annuli_branch != 0) {
      ht_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch ht_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    ht_SD_annuli_isLoaded = true;
  }
  return ht_SD_annuli_;
}

const float &hwwtree::ht_SD_same() {
  if (not ht_SD_same_isLoaded) {
    if (ht_SD_same_branch != 0) {
      ht_SD_same_branch->GetEntry(index);
    } else {
      printf("branch ht_SD_same_branch does not exist!\n");
      exit(1);
    }
    ht_SD_same_isLoaded = true;
  }
  return ht_SD_same_;
}

const float &hwwtree::ht_SD_away() {
  if (not ht_SD_away_isLoaded) {
    if (ht_SD_away_branch != 0) {
      ht_SD_away_branch->GetEntry(index);
    } else {
      printf("branch ht_SD_away_branch does not exist!\n");
      exit(1);
    }
    ht_SD_away_isLoaded = true;
  }
  return ht_SD_away_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::R_p4() {
  if (not R_p4_isLoaded) {
    if (R_p4_branch != 0) {
      R_p4_branch->GetEntry(index);
    } else {
      printf("branch R_p4_branch does not exist!\n");
      exit(1);
    }
    R_p4_isLoaded = true;
  }
  return *R_p4_;
}

const float &hwwtree::R_pt() {
  if (not R_pt_isLoaded) {
    if (R_pt_branch != 0) {
      R_pt_branch->GetEntry(index);
    } else {
      printf("branch R_pt_branch does not exist!\n");
      exit(1);
    }
    R_pt_isLoaded = true;
  }
  return R_pt_;
}

const float &hwwtree::R_eta() {
  if (not R_eta_isLoaded) {
    if (R_eta_branch != 0) {
      R_eta_branch->GetEntry(index);
    } else {
      printf("branch R_eta_branch does not exist!\n");
      exit(1);
    }
    R_eta_isLoaded = true;
  }
  return R_eta_;
}

const float &hwwtree::R_phi() {
  if (not R_phi_isLoaded) {
    if (R_phi_branch != 0) {
      R_phi_branch->GetEntry(index);
    } else {
      printf("branch R_phi_branch does not exist!\n");
      exit(1);
    }
    R_phi_isLoaded = true;
  }
  return R_phi_;
}

const float &hwwtree::R_mass() {
  if (not R_mass_isLoaded) {
    if (R_mass_branch != 0) {
      R_mass_branch->GetEntry(index);
    } else {
      printf("branch R_mass_branch does not exist!\n");
      exit(1);
    }
    R_mass_isLoaded = true;
  }
  return R_mass_;
}

const float &hwwtree::R_energy() {
  if (not R_energy_isLoaded) {
    if (R_energy_branch != 0) {
      R_energy_branch->GetEntry(index);
    } else {
      printf("branch R_energy_branch does not exist!\n");
      exit(1);
    }
    R_energy_isLoaded = true;
  }
  return R_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::R_cent_p4() {
  if (not R_cent_p4_isLoaded) {
    if (R_cent_p4_branch != 0) {
      R_cent_p4_branch->GetEntry(index);
    } else {
      printf("branch R_cent_p4_branch does not exist!\n");
      exit(1);
    }
    R_cent_p4_isLoaded = true;
  }
  return *R_cent_p4_;
}

const float &hwwtree::R_cent_pt() {
  if (not R_cent_pt_isLoaded) {
    if (R_cent_pt_branch != 0) {
      R_cent_pt_branch->GetEntry(index);
    } else {
      printf("branch R_cent_pt_branch does not exist!\n");
      exit(1);
    }
    R_cent_pt_isLoaded = true;
  }
  return R_cent_pt_;
}

const float &hwwtree::R_cent_eta() {
  if (not R_cent_eta_isLoaded) {
    if (R_cent_eta_branch != 0) {
      R_cent_eta_branch->GetEntry(index);
    } else {
      printf("branch R_cent_eta_branch does not exist!\n");
      exit(1);
    }
    R_cent_eta_isLoaded = true;
  }
  return R_cent_eta_;
}

const float &hwwtree::R_cent_phi() {
  if (not R_cent_phi_isLoaded) {
    if (R_cent_phi_branch != 0) {
      R_cent_phi_branch->GetEntry(index);
    } else {
      printf("branch R_cent_phi_branch does not exist!\n");
      exit(1);
    }
    R_cent_phi_isLoaded = true;
  }
  return R_cent_phi_;
}

const float &hwwtree::R_cent_mass() {
  if (not R_cent_mass_isLoaded) {
    if (R_cent_mass_branch != 0) {
      R_cent_mass_branch->GetEntry(index);
    } else {
      printf("branch R_cent_mass_branch does not exist!\n");
      exit(1);
    }
    R_cent_mass_isLoaded = true;
  }
  return R_cent_mass_;
}

const float &hwwtree::R_cent_energy() {
  if (not R_cent_energy_isLoaded) {
    if (R_cent_energy_branch != 0) {
      R_cent_energy_branch->GetEntry(index);
    } else {
      printf("branch R_cent_energy_branch does not exist!\n");
      exit(1);
    }
    R_cent_energy_isLoaded = true;
  }
  return R_cent_energy_;
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_b0_p4() {
  if (not gen_b0_p4_isLoaded) {
    if (gen_b0_p4_branch != 0) {
      gen_b0_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_p4_branch does not exist!\n");
      exit(1);
    }
    gen_b0_p4_isLoaded = true;
  }
  return *gen_b0_p4_;
}

const float &hwwtree::gen_b0_pt() {
  if (not gen_b0_pt_isLoaded) {
    if (gen_b0_pt_branch != 0) {
      gen_b0_pt_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_pt_branch does not exist!\n");
      exit(1);
    }
    gen_b0_pt_isLoaded = true;
  }
  return gen_b0_pt_;
}

const float &hwwtree::gen_b0_eta() {
  if (not gen_b0_eta_isLoaded) {
    if (gen_b0_eta_branch != 0) {
      gen_b0_eta_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_eta_branch does not exist!\n");
      exit(1);
    }
    gen_b0_eta_isLoaded = true;
  }
  return gen_b0_eta_;
}

const float &hwwtree::gen_b0_phi() {
  if (not gen_b0_phi_isLoaded) {
    if (gen_b0_phi_branch != 0) {
      gen_b0_phi_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_phi_branch does not exist!\n");
      exit(1);
    }
    gen_b0_phi_isLoaded = true;
  }
  return gen_b0_phi_;
}

const float &hwwtree::gen_b0_mass() {
  if (not gen_b0_mass_isLoaded) {
    if (gen_b0_mass_branch != 0) {
      gen_b0_mass_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_mass_branch does not exist!\n");
      exit(1);
    }
    gen_b0_mass_isLoaded = true;
  }
  return gen_b0_mass_;
}

const float &hwwtree::gen_b0_energy() {
  if (not gen_b0_energy_isLoaded) {
    if (gen_b0_energy_branch != 0) {
      gen_b0_energy_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_energy_branch does not exist!\n");
      exit(1);
    }
    gen_b0_energy_isLoaded = true;
  }
  return gen_b0_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_b1_p4() {
  if (not gen_b1_p4_isLoaded) {
    if (gen_b1_p4_branch != 0) {
      gen_b1_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_p4_branch does not exist!\n");
      exit(1);
    }
    gen_b1_p4_isLoaded = true;
  }
  return *gen_b1_p4_;
}

const float &hwwtree::gen_b1_pt() {
  if (not gen_b1_pt_isLoaded) {
    if (gen_b1_pt_branch != 0) {
      gen_b1_pt_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_pt_branch does not exist!\n");
      exit(1);
    }
    gen_b1_pt_isLoaded = true;
  }
  return gen_b1_pt_;
}

const float &hwwtree::gen_b1_eta() {
  if (not gen_b1_eta_isLoaded) {
    if (gen_b1_eta_branch != 0) {
      gen_b1_eta_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_eta_branch does not exist!\n");
      exit(1);
    }
    gen_b1_eta_isLoaded = true;
  }
  return gen_b1_eta_;
}

const float &hwwtree::gen_b1_phi() {
  if (not gen_b1_phi_isLoaded) {
    if (gen_b1_phi_branch != 0) {
      gen_b1_phi_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_phi_branch does not exist!\n");
      exit(1);
    }
    gen_b1_phi_isLoaded = true;
  }
  return gen_b1_phi_;
}

const float &hwwtree::gen_b1_mass() {
  if (not gen_b1_mass_isLoaded) {
    if (gen_b1_mass_branch != 0) {
      gen_b1_mass_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_mass_branch does not exist!\n");
      exit(1);
    }
    gen_b1_mass_isLoaded = true;
  }
  return gen_b1_mass_;
}

const float &hwwtree::gen_b1_energy() {
  if (not gen_b1_energy_isLoaded) {
    if (gen_b1_energy_branch != 0) {
      gen_b1_energy_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_energy_branch does not exist!\n");
      exit(1);
    }
    gen_b1_energy_isLoaded = true;
  }
  return gen_b1_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_t0_p4() {
  if (not gen_t0_p4_isLoaded) {
    if (gen_t0_p4_branch != 0) {
      gen_t0_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_p4_branch does not exist!\n");
      exit(1);
    }
    gen_t0_p4_isLoaded = true;
  }
  return *gen_t0_p4_;
}

const float &hwwtree::gen_t0_pt() {
  if (not gen_t0_pt_isLoaded) {
    if (gen_t0_pt_branch != 0) {
      gen_t0_pt_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_pt_branch does not exist!\n");
      exit(1);
    }
    gen_t0_pt_isLoaded = true;
  }
  return gen_t0_pt_;
}

const float &hwwtree::gen_t0_eta() {
  if (not gen_t0_eta_isLoaded) {
    if (gen_t0_eta_branch != 0) {
      gen_t0_eta_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_eta_branch does not exist!\n");
      exit(1);
    }
    gen_t0_eta_isLoaded = true;
  }
  return gen_t0_eta_;
}

const float &hwwtree::gen_t0_phi() {
  if (not gen_t0_phi_isLoaded) {
    if (gen_t0_phi_branch != 0) {
      gen_t0_phi_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_phi_branch does not exist!\n");
      exit(1);
    }
    gen_t0_phi_isLoaded = true;
  }
  return gen_t0_phi_;
}

const float &hwwtree::gen_t0_mass() {
  if (not gen_t0_mass_isLoaded) {
    if (gen_t0_mass_branch != 0) {
      gen_t0_mass_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_mass_branch does not exist!\n");
      exit(1);
    }
    gen_t0_mass_isLoaded = true;
  }
  return gen_t0_mass_;
}

const float &hwwtree::gen_t0_energy() {
  if (not gen_t0_energy_isLoaded) {
    if (gen_t0_energy_branch != 0) {
      gen_t0_energy_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_energy_branch does not exist!\n");
      exit(1);
    }
    gen_t0_energy_isLoaded = true;
  }
  return gen_t0_energy_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &hwwtree::gen_t1_p4() {
  if (not gen_t1_p4_isLoaded) {
    if (gen_t1_p4_branch != 0) {
      gen_t1_p4_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_p4_branch does not exist!\n");
      exit(1);
    }
    gen_t1_p4_isLoaded = true;
  }
  return *gen_t1_p4_;
}

const float &hwwtree::gen_t1_pt() {
  if (not gen_t1_pt_isLoaded) {
    if (gen_t1_pt_branch != 0) {
      gen_t1_pt_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_pt_branch does not exist!\n");
      exit(1);
    }
    gen_t1_pt_isLoaded = true;
  }
  return gen_t1_pt_;
}

const float &hwwtree::gen_t1_eta() {
  if (not gen_t1_eta_isLoaded) {
    if (gen_t1_eta_branch != 0) {
      gen_t1_eta_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_eta_branch does not exist!\n");
      exit(1);
    }
    gen_t1_eta_isLoaded = true;
  }
  return gen_t1_eta_;
}

const float &hwwtree::gen_t1_phi() {
  if (not gen_t1_phi_isLoaded) {
    if (gen_t1_phi_branch != 0) {
      gen_t1_phi_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_phi_branch does not exist!\n");
      exit(1);
    }
    gen_t1_phi_isLoaded = true;
  }
  return gen_t1_phi_;
}

const float &hwwtree::gen_t1_mass() {
  if (not gen_t1_mass_isLoaded) {
    if (gen_t1_mass_branch != 0) {
      gen_t1_mass_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_mass_branch does not exist!\n");
      exit(1);
    }
    gen_t1_mass_isLoaded = true;
  }
  return gen_t1_mass_;
}

const float &hwwtree::gen_t1_energy() {
  if (not gen_t1_energy_isLoaded) {
    if (gen_t1_energy_branch != 0) {
      gen_t1_energy_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_energy_branch does not exist!\n");
      exit(1);
    }
    gen_t1_energy_isLoaded = true;
  }
  return gen_t1_energy_;
}

const float &hwwtree::gen_b0_dr() {
  if (not gen_b0_dr_isLoaded) {
    if (gen_b0_dr_branch != 0) {
      gen_b0_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_dr_branch does not exist!\n");
      exit(1);
    }
    gen_b0_dr_isLoaded = true;
  }
  return gen_b0_dr_;
}

const int &hwwtree::gen_b0_in() {
  if (not gen_b0_in_isLoaded) {
    if (gen_b0_in_branch != 0) {
      gen_b0_in_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_in_branch does not exist!\n");
      exit(1);
    }
    gen_b0_in_isLoaded = true;
  }
  return gen_b0_in_;
}

const int &hwwtree::gen_b0_annuli() {
  if (not gen_b0_annuli_isLoaded) {
    if (gen_b0_annuli_branch != 0) {
      gen_b0_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_b0_annuli_isLoaded = true;
  }
  return gen_b0_annuli_;
}

const int &hwwtree::gen_b0_same() {
  if (not gen_b0_same_isLoaded) {
    if (gen_b0_same_branch != 0) {
      gen_b0_same_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_same_branch does not exist!\n");
      exit(1);
    }
    gen_b0_same_isLoaded = true;
  }
  return gen_b0_same_;
}

const int &hwwtree::gen_b0_away() {
  if (not gen_b0_away_isLoaded) {
    if (gen_b0_away_branch != 0) {
      gen_b0_away_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_away_branch does not exist!\n");
      exit(1);
    }
    gen_b0_away_isLoaded = true;
  }
  return gen_b0_away_;
}

const float &hwwtree::gen_b1_dr() {
  if (not gen_b1_dr_isLoaded) {
    if (gen_b1_dr_branch != 0) {
      gen_b1_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_dr_branch does not exist!\n");
      exit(1);
    }
    gen_b1_dr_isLoaded = true;
  }
  return gen_b1_dr_;
}

const int &hwwtree::gen_b1_in() {
  if (not gen_b1_in_isLoaded) {
    if (gen_b1_in_branch != 0) {
      gen_b1_in_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_in_branch does not exist!\n");
      exit(1);
    }
    gen_b1_in_isLoaded = true;
  }
  return gen_b1_in_;
}

const int &hwwtree::gen_b1_annuli() {
  if (not gen_b1_annuli_isLoaded) {
    if (gen_b1_annuli_branch != 0) {
      gen_b1_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_b1_annuli_isLoaded = true;
  }
  return gen_b1_annuli_;
}

const int &hwwtree::gen_b1_same() {
  if (not gen_b1_same_isLoaded) {
    if (gen_b1_same_branch != 0) {
      gen_b1_same_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_same_branch does not exist!\n");
      exit(1);
    }
    gen_b1_same_isLoaded = true;
  }
  return gen_b1_same_;
}

const int &hwwtree::gen_b1_away() {
  if (not gen_b1_away_isLoaded) {
    if (gen_b1_away_branch != 0) {
      gen_b1_away_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_away_branch does not exist!\n");
      exit(1);
    }
    gen_b1_away_isLoaded = true;
  }
  return gen_b1_away_;
}

const float &hwwtree::gen_b0_SD_dr() {
  if (not gen_b0_SD_dr_isLoaded) {
    if (gen_b0_SD_dr_branch != 0) {
      gen_b0_SD_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_SD_dr_branch does not exist!\n");
      exit(1);
    }
    gen_b0_SD_dr_isLoaded = true;
  }
  return gen_b0_SD_dr_;
}

const int &hwwtree::gen_b0_SD_in() {
  if (not gen_b0_SD_in_isLoaded) {
    if (gen_b0_SD_in_branch != 0) {
      gen_b0_SD_in_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_SD_in_branch does not exist!\n");
      exit(1);
    }
    gen_b0_SD_in_isLoaded = true;
  }
  return gen_b0_SD_in_;
}

const int &hwwtree::gen_b0_SD_annuli() {
  if (not gen_b0_SD_annuli_isLoaded) {
    if (gen_b0_SD_annuli_branch != 0) {
      gen_b0_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_b0_SD_annuli_isLoaded = true;
  }
  return gen_b0_SD_annuli_;
}

const int &hwwtree::gen_b0_SD_same() {
  if (not gen_b0_SD_same_isLoaded) {
    if (gen_b0_SD_same_branch != 0) {
      gen_b0_SD_same_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_SD_same_branch does not exist!\n");
      exit(1);
    }
    gen_b0_SD_same_isLoaded = true;
  }
  return gen_b0_SD_same_;
}

const int &hwwtree::gen_b0_SD_away() {
  if (not gen_b0_SD_away_isLoaded) {
    if (gen_b0_SD_away_branch != 0) {
      gen_b0_SD_away_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_SD_away_branch does not exist!\n");
      exit(1);
    }
    gen_b0_SD_away_isLoaded = true;
  }
  return gen_b0_SD_away_;
}

const float &hwwtree::gen_b1_SD_dr() {
  if (not gen_b1_SD_dr_isLoaded) {
    if (gen_b1_SD_dr_branch != 0) {
      gen_b1_SD_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_SD_dr_branch does not exist!\n");
      exit(1);
    }
    gen_b1_SD_dr_isLoaded = true;
  }
  return gen_b1_SD_dr_;
}

const int &hwwtree::gen_b1_SD_in() {
  if (not gen_b1_SD_in_isLoaded) {
    if (gen_b1_SD_in_branch != 0) {
      gen_b1_SD_in_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_SD_in_branch does not exist!\n");
      exit(1);
    }
    gen_b1_SD_in_isLoaded = true;
  }
  return gen_b1_SD_in_;
}

const int &hwwtree::gen_b1_SD_annuli() {
  if (not gen_b1_SD_annuli_isLoaded) {
    if (gen_b1_SD_annuli_branch != 0) {
      gen_b1_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_b1_SD_annuli_isLoaded = true;
  }
  return gen_b1_SD_annuli_;
}

const int &hwwtree::gen_b1_SD_same() {
  if (not gen_b1_SD_same_isLoaded) {
    if (gen_b1_SD_same_branch != 0) {
      gen_b1_SD_same_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_SD_same_branch does not exist!\n");
      exit(1);
    }
    gen_b1_SD_same_isLoaded = true;
  }
  return gen_b1_SD_same_;
}

const int &hwwtree::gen_b1_SD_away() {
  if (not gen_b1_SD_away_isLoaded) {
    if (gen_b1_SD_away_branch != 0) {
      gen_b1_SD_away_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_SD_away_branch does not exist!\n");
      exit(1);
    }
    gen_b1_SD_away_isLoaded = true;
  }
  return gen_b1_SD_away_;
}

const float &hwwtree::gen_t0_dr() {
  if (not gen_t0_dr_isLoaded) {
    if (gen_t0_dr_branch != 0) {
      gen_t0_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_dr_branch does not exist!\n");
      exit(1);
    }
    gen_t0_dr_isLoaded = true;
  }
  return gen_t0_dr_;
}

const int &hwwtree::gen_t0_in() {
  if (not gen_t0_in_isLoaded) {
    if (gen_t0_in_branch != 0) {
      gen_t0_in_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_in_branch does not exist!\n");
      exit(1);
    }
    gen_t0_in_isLoaded = true;
  }
  return gen_t0_in_;
}

const int &hwwtree::gen_t0_annuli() {
  if (not gen_t0_annuli_isLoaded) {
    if (gen_t0_annuli_branch != 0) {
      gen_t0_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_t0_annuli_isLoaded = true;
  }
  return gen_t0_annuli_;
}

const int &hwwtree::gen_t0_same() {
  if (not gen_t0_same_isLoaded) {
    if (gen_t0_same_branch != 0) {
      gen_t0_same_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_same_branch does not exist!\n");
      exit(1);
    }
    gen_t0_same_isLoaded = true;
  }
  return gen_t0_same_;
}

const int &hwwtree::gen_t0_away() {
  if (not gen_t0_away_isLoaded) {
    if (gen_t0_away_branch != 0) {
      gen_t0_away_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_away_branch does not exist!\n");
      exit(1);
    }
    gen_t0_away_isLoaded = true;
  }
  return gen_t0_away_;
}

const float &hwwtree::gen_t1_dr() {
  if (not gen_t1_dr_isLoaded) {
    if (gen_t1_dr_branch != 0) {
      gen_t1_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_dr_branch does not exist!\n");
      exit(1);
    }
    gen_t1_dr_isLoaded = true;
  }
  return gen_t1_dr_;
}

const int &hwwtree::gen_t1_in() {
  if (not gen_t1_in_isLoaded) {
    if (gen_t1_in_branch != 0) {
      gen_t1_in_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_in_branch does not exist!\n");
      exit(1);
    }
    gen_t1_in_isLoaded = true;
  }
  return gen_t1_in_;
}

const int &hwwtree::gen_t1_annuli() {
  if (not gen_t1_annuli_isLoaded) {
    if (gen_t1_annuli_branch != 0) {
      gen_t1_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_t1_annuli_isLoaded = true;
  }
  return gen_t1_annuli_;
}

const int &hwwtree::gen_t1_same() {
  if (not gen_t1_same_isLoaded) {
    if (gen_t1_same_branch != 0) {
      gen_t1_same_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_same_branch does not exist!\n");
      exit(1);
    }
    gen_t1_same_isLoaded = true;
  }
  return gen_t1_same_;
}

const int &hwwtree::gen_t1_away() {
  if (not gen_t1_away_isLoaded) {
    if (gen_t1_away_branch != 0) {
      gen_t1_away_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_away_branch does not exist!\n");
      exit(1);
    }
    gen_t1_away_isLoaded = true;
  }
  return gen_t1_away_;
}

const float &hwwtree::gen_t0_SD_dr() {
  if (not gen_t0_SD_dr_isLoaded) {
    if (gen_t0_SD_dr_branch != 0) {
      gen_t0_SD_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_SD_dr_branch does not exist!\n");
      exit(1);
    }
    gen_t0_SD_dr_isLoaded = true;
  }
  return gen_t0_SD_dr_;
}

const int &hwwtree::gen_t0_SD_in() {
  if (not gen_t0_SD_in_isLoaded) {
    if (gen_t0_SD_in_branch != 0) {
      gen_t0_SD_in_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_SD_in_branch does not exist!\n");
      exit(1);
    }
    gen_t0_SD_in_isLoaded = true;
  }
  return gen_t0_SD_in_;
}

const int &hwwtree::gen_t0_SD_annuli() {
  if (not gen_t0_SD_annuli_isLoaded) {
    if (gen_t0_SD_annuli_branch != 0) {
      gen_t0_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_t0_SD_annuli_isLoaded = true;
  }
  return gen_t0_SD_annuli_;
}

const int &hwwtree::gen_t0_SD_same() {
  if (not gen_t0_SD_same_isLoaded) {
    if (gen_t0_SD_same_branch != 0) {
      gen_t0_SD_same_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_SD_same_branch does not exist!\n");
      exit(1);
    }
    gen_t0_SD_same_isLoaded = true;
  }
  return gen_t0_SD_same_;
}

const int &hwwtree::gen_t0_SD_away() {
  if (not gen_t0_SD_away_isLoaded) {
    if (gen_t0_SD_away_branch != 0) {
      gen_t0_SD_away_branch->GetEntry(index);
    } else {
      printf("branch gen_t0_SD_away_branch does not exist!\n");
      exit(1);
    }
    gen_t0_SD_away_isLoaded = true;
  }
  return gen_t0_SD_away_;
}

const float &hwwtree::gen_t1_SD_dr() {
  if (not gen_t1_SD_dr_isLoaded) {
    if (gen_t1_SD_dr_branch != 0) {
      gen_t1_SD_dr_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_SD_dr_branch does not exist!\n");
      exit(1);
    }
    gen_t1_SD_dr_isLoaded = true;
  }
  return gen_t1_SD_dr_;
}

const int &hwwtree::gen_t1_SD_in() {
  if (not gen_t1_SD_in_isLoaded) {
    if (gen_t1_SD_in_branch != 0) {
      gen_t1_SD_in_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_SD_in_branch does not exist!\n");
      exit(1);
    }
    gen_t1_SD_in_isLoaded = true;
  }
  return gen_t1_SD_in_;
}

const int &hwwtree::gen_t1_SD_annuli() {
  if (not gen_t1_SD_annuli_isLoaded) {
    if (gen_t1_SD_annuli_branch != 0) {
      gen_t1_SD_annuli_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_SD_annuli_branch does not exist!\n");
      exit(1);
    }
    gen_t1_SD_annuli_isLoaded = true;
  }
  return gen_t1_SD_annuli_;
}

const int &hwwtree::gen_t1_SD_same() {
  if (not gen_t1_SD_same_isLoaded) {
    if (gen_t1_SD_same_branch != 0) {
      gen_t1_SD_same_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_SD_same_branch does not exist!\n");
      exit(1);
    }
    gen_t1_SD_same_isLoaded = true;
  }
  return gen_t1_SD_same_;
}

const int &hwwtree::gen_t1_SD_away() {
  if (not gen_t1_SD_away_isLoaded) {
    if (gen_t1_SD_away_branch != 0) {
      gen_t1_SD_away_branch->GetEntry(index);
    } else {
      printf("branch gen_t1_SD_away_branch does not exist!\n");
      exit(1);
    }
    gen_t1_SD_away_isLoaded = true;
  }
  return gen_t1_SD_away_;
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
const float &gen_ht() { return hww.gen_ht(); }
const float &nvtx() { return hww.nvtx(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &L_p4() { return hww.L_p4(); }
const float &L_pt() { return hww.L_pt(); }
const float &L_eta() { return hww.L_eta(); }
const float &L_phi() { return hww.L_phi(); }
const float &L_mass() { return hww.L_mass(); }
const float &L_energy() { return hww.L_energy(); }
const int &L_id() { return hww.L_id(); }
const int &L_idx() { return hww.L_idx(); }
const int &L_isTightPOG() { return hww.L_isTightPOG(); }
const float &L_miniIsoEA() { return hww.L_miniIsoEA(); }
const float &L_relIso03EA() { return hww.L_relIso03EA(); }
const float &L_relIso04DB() { return hww.L_relIso04DB(); }
const float &L_relIso0025EA() { return hww.L_relIso0025EA(); }
const float &L_relIso005EA() { return hww.L_relIso005EA(); }
const float &L_relIso01EA() { return hww.L_relIso01EA(); }
const float &L_relIso02EA() { return hww.L_relIso02EA(); }
const float &L_relIso04EA() { return hww.L_relIso04EA(); }
const float &L_relIso08EA() { return hww.L_relIso08EA(); }
const float &L_relIso0025EAwLep() { return hww.L_relIso0025EAwLep(); }
const float &L_relIso005EAwLep() { return hww.L_relIso005EAwLep(); }
const float &L_relIso01EAwLep() { return hww.L_relIso01EAwLep(); }
const float &L_relIso02EAwLep() { return hww.L_relIso02EAwLep(); }
const float &L_relIso04EAwLep() { return hww.L_relIso04EAwLep(); }
const float &L_relIso08EAwLep() { return hww.L_relIso08EAwLep(); }
const float &L_ip3d() { return hww.L_ip3d(); }
const float &L_ip3derr() { return hww.L_ip3derr(); }
const float &L_dxy() { return hww.L_dxy(); }
const float &L_dz() { return hww.L_dz(); }
const int &L_isFromW() { return hww.L_isFromW(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &X_p4() { return hww.X_p4(); }
const float &X_pt() { return hww.X_pt(); }
const float &X_phi() { return hww.X_phi(); }
const float &X_up_pt() { return hww.X_up_pt(); }
const float &X_up_phi() { return hww.X_up_phi(); }
const float &X_dn_pt() { return hww.X_dn_pt(); }
const float &X_dn_phi() { return hww.X_dn_phi(); }
const float &X_gen_pt() { return hww.X_gen_pt(); }
const float &X_gen_phi() { return hww.X_gen_phi(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &J_p4() { return hww.J_p4(); }
const float &J_pt() { return hww.J_pt(); }
const float &J_eta() { return hww.J_eta(); }
const float &J_phi() { return hww.J_phi(); }
const float &J_mass() { return hww.J_mass(); }
const float &J_energy() { return hww.J_energy(); }
const float &J_tau31() { return hww.J_tau31(); }
const float &J_tau32() { return hww.J_tau32(); }
const float &J_tau21() { return hww.J_tau21(); }
const float &J_tau1() { return hww.J_tau1(); }
const float &J_tau2() { return hww.J_tau2(); }
const float &J_tau3() { return hww.J_tau3(); }
const float &J_undoJEC() { return hww.J_undoJEC(); }
const float &J_shift() { return hww.J_shift(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &J_SD_p4() { return hww.J_SD_p4(); }
const float &J_SD_pt() { return hww.J_SD_pt(); }
const float &J_SD_eta() { return hww.J_SD_eta(); }
const float &J_SD_phi() { return hww.J_SD_phi(); }
const float &J_SD_mass() { return hww.J_SD_mass(); }
const float &J_SD_energy() { return hww.J_SD_energy(); }
const float &J_SD_tau31() { return hww.J_SD_tau31(); }
const float &J_SD_tau32() { return hww.J_SD_tau32(); }
const float &J_SD_tau21() { return hww.J_SD_tau21(); }
const float &J_SD_tau1() { return hww.J_SD_tau1(); }
const float &J_SD_tau2() { return hww.J_SD_tau2(); }
const float &J_SD_tau3() { return hww.J_SD_tau3(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &q0_p4() { return hww.q0_p4(); }
const float &q0_pt() { return hww.q0_pt(); }
const float &q0_eta() { return hww.q0_eta(); }
const float &q0_phi() { return hww.q0_phi(); }
const float &q0_mass() { return hww.q0_mass(); }
const float &q0_energy() { return hww.q0_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &q1_p4() { return hww.q1_p4(); }
const float &q1_pt() { return hww.q1_pt(); }
const float &q1_eta() { return hww.q1_eta(); }
const float &q1_phi() { return hww.q1_phi(); }
const float &q1_mass() { return hww.q1_mass(); }
const float &q1_energy() { return hww.q1_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V_p4() { return hww.V_p4(); }
const float &V_pt() { return hww.V_pt(); }
const float &V_eta() { return hww.V_eta(); }
const float &V_phi() { return hww.V_phi(); }
const float &V_mass() { return hww.V_mass(); }
const float &V_energy() { return hww.V_energy(); }
const float &V_SD_mass() { return hww.V_SD_mass(); }
const float &V_tau31() { return hww.V_tau31(); }
const float &V_tau32() { return hww.V_tau32(); }
const float &V_tau21() { return hww.V_tau21(); }
const float &V_tau1() { return hww.V_tau1(); }
const float &V_tau2() { return hww.V_tau2(); }
const float &V_tau3() { return hww.V_tau3(); }
const float &V_undoJEC() { return hww.V_undoJEC(); }
const float &V_shift() { return hww.V_shift(); }
const float &V_deep_rawdisc_h4q() { return hww.V_deep_rawdisc_h4q(); }
const float &V_deep_rawdisc_hbb() { return hww.V_deep_rawdisc_hbb(); }
const float &V_deep_rawdisc_qcd() { return hww.V_deep_rawdisc_qcd(); }
const float &V_deep_rawdisc_top() { return hww.V_deep_rawdisc_top(); }
const float &V_deep_rawdisc_w() { return hww.V_deep_rawdisc_w(); }
const float &V_deep_rawdisc_z() { return hww.V_deep_rawdisc_z(); }
const float &V_deep_rawdisc_zbb() { return hww.V_deep_rawdisc_zbb(); }
const float &V_softdropPuppiSubjet1_pt() { return hww.V_softdropPuppiSubjet1_pt(); }
const float &V_softdropPuppiSubjet1_eta() { return hww.V_softdropPuppiSubjet1_eta(); }
const float &V_softdropPuppiSubjet1_phi() { return hww.V_softdropPuppiSubjet1_phi(); }
const float &V_softdropPuppiSubjet1_mass() { return hww.V_softdropPuppiSubjet1_mass(); }
const float &V_softdropPuppiSubjet1_energy() { return hww.V_softdropPuppiSubjet1_energy(); }
const float &V_softdropPuppiSubjet2_pt() { return hww.V_softdropPuppiSubjet2_pt(); }
const float &V_softdropPuppiSubjet2_eta() { return hww.V_softdropPuppiSubjet2_eta(); }
const float &V_softdropPuppiSubjet2_phi() { return hww.V_softdropPuppiSubjet2_phi(); }
const float &V_softdropPuppiSubjet2_mass() { return hww.V_softdropPuppiSubjet2_mass(); }
const float &V_softdropPuppiSubjet2_energy() { return hww.V_softdropPuppiSubjet2_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &LXJ_p4() { return hww.LXJ_p4(); }
const float &LXJ_pt() { return hww.LXJ_pt(); }
const float &LXJ_eta() { return hww.LXJ_eta(); }
const float &LXJ_phi() { return hww.LXJ_phi(); }
const float &LXJ_mass() { return hww.LXJ_mass(); }
const float &LXJ_energy() { return hww.LXJ_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &LXJ_SD_p4() { return hww.LXJ_SD_p4(); }
const float &LXJ_SD_pt() { return hww.LXJ_SD_pt(); }
const float &LXJ_SD_eta() { return hww.LXJ_SD_eta(); }
const float &LXJ_SD_phi() { return hww.LXJ_SD_phi(); }
const float &LXJ_SD_mass() { return hww.LXJ_SD_mass(); }
const float &LXJ_SD_energy() { return hww.LXJ_SD_energy(); }
const float &LX_pt() { return hww.LX_pt(); }
const float &LX_mt() { return hww.LX_mt(); }
const float &LX_mass() { return hww.LX_mass(); }
const float &LX_dphi() { return hww.LX_dphi(); }
const float &LJ_pt() { return hww.LJ_pt(); }
const float &LJ_mt() { return hww.LJ_mt(); }
const float &LJ_mass() { return hww.LJ_mass(); }
const float &LJ_dphi() { return hww.LJ_dphi(); }
const float &LJ_deta() { return hww.LJ_deta(); }
const float &LJ_dr() { return hww.LJ_dr(); }
const float &LJ_dptf() { return hww.LJ_dptf(); }
const float &LJ_SD_pt() { return hww.LJ_SD_pt(); }
const float &LJ_SD_mt() { return hww.LJ_SD_mt(); }
const float &LJ_SD_mass() { return hww.LJ_SD_mass(); }
const float &LJ_SD_dphi() { return hww.LJ_SD_dphi(); }
const float &LJ_SD_deta() { return hww.LJ_SD_deta(); }
const float &LJ_SD_dr() { return hww.LJ_SD_dr(); }
const float &LJ_SD_dptf() { return hww.LJ_SD_dptf(); }
const float &Lq0_pt() { return hww.Lq0_pt(); }
const float &Lq0_mt() { return hww.Lq0_mt(); }
const float &Lq0_mass() { return hww.Lq0_mass(); }
const float &Lq0_dphi() { return hww.Lq0_dphi(); }
const float &Lq0_deta() { return hww.Lq0_deta(); }
const float &Lq0_dr() { return hww.Lq0_dr(); }
const float &Lq0_dptf() { return hww.Lq0_dptf(); }
const float &Lq1_pt() { return hww.Lq1_pt(); }
const float &Lq1_mt() { return hww.Lq1_mt(); }
const float &Lq1_mass() { return hww.Lq1_mass(); }
const float &Lq1_dphi() { return hww.Lq1_dphi(); }
const float &Lq1_deta() { return hww.Lq1_deta(); }
const float &Lq1_dr() { return hww.Lq1_dr(); }
const float &Lq1_dptf() { return hww.Lq1_dptf(); }
const float &Lqmax_pt() { return hww.Lqmax_pt(); }
const float &Lqmax_mt() { return hww.Lqmax_mt(); }
const float &Lqmax_mass() { return hww.Lqmax_mass(); }
const float &Lqmax_dphi() { return hww.Lqmax_dphi(); }
const float &Lqmax_deta() { return hww.Lqmax_deta(); }
const float &Lqmax_dr() { return hww.Lqmax_dr(); }
const float &Lqmax_dptf() { return hww.Lqmax_dptf(); }
const float &LHRatio() { return hww.LHRatio(); }
const float &LHRatio_SD() { return hww.LHRatio_SD(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &neu_p4() { return hww.neu_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &neu_p4_h() { return hww.neu_p4_h(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Wlep_p4() { return hww.Wlep_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Wlep_h_p4() { return hww.Wlep_h_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &H_p4() { return hww.H_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &H_mh_p4() { return hww.H_mh_p4(); }
const float &det() { return hww.det(); }
const float &detW() { return hww.detW(); }
const float &mH() { return hww.mH(); }
const float &mD() { return hww.mD(); }
const float &mD_SD() { return hww.mD_SD(); }
const float &mD_Wlep() { return hww.mD_Wlep(); }
const vector<float> &j_dphis() { return hww.j_dphis(); }
const vector<float> &j_drs() { return hww.j_drs(); }
const vector<float> &j_SD_dphis() { return hww.j_SD_dphis(); }
const vector<float> &j_SD_drs() { return hww.j_SD_drs(); }
const vector<float> &j_pts() { return hww.j_pts(); }
const int &nj() { return hww.nj(); }
const int &nj_in() { return hww.nj_in(); }
const int &nj_annuli() { return hww.nj_annuli(); }
const int &nj_same() { return hww.nj_same(); }
const int &nj_away() { return hww.nj_away(); }
const int &nj_SD_in() { return hww.nj_SD_in(); }
const int &nj_SD_annuli() { return hww.nj_SD_annuli(); }
const int &nj_SD_same() { return hww.nj_SD_same(); }
const int &nj_SD_away() { return hww.nj_SD_away(); }
const int &nb() { return hww.nb(); }
const int &nb_in() { return hww.nb_in(); }
const int &nb_annuli() { return hww.nb_annuli(); }
const int &nb_same() { return hww.nb_same(); }
const int &nb_away() { return hww.nb_away(); }
const int &nb_SD_in() { return hww.nb_SD_in(); }
const int &nb_SD_annuli() { return hww.nb_SD_annuli(); }
const int &nb_SD_same() { return hww.nb_SD_same(); }
const int &nb_SD_away() { return hww.nb_SD_away(); }
const int &nbmed() { return hww.nbmed(); }
const int &nbmed_in() { return hww.nbmed_in(); }
const int &nbmed_annuli() { return hww.nbmed_annuli(); }
const int &nbmed_same() { return hww.nbmed_same(); }
const int &nbmed_away() { return hww.nbmed_away(); }
const int &nbmed_SD_in() { return hww.nbmed_SD_in(); }
const int &nbmed_SD_annuli() { return hww.nbmed_SD_annuli(); }
const int &nbmed_SD_same() { return hww.nbmed_SD_same(); }
const int &nbmed_SD_away() { return hww.nbmed_SD_away(); }
const int &nbtight() { return hww.nbtight(); }
const int &nbtight_in() { return hww.nbtight_in(); }
const int &nbtight_annuli() { return hww.nbtight_annuli(); }
const int &nbtight_same() { return hww.nbtight_same(); }
const int &nbtight_away() { return hww.nbtight_away(); }
const int &nbtight_SD_in() { return hww.nbtight_SD_in(); }
const int &nbtight_SD_annuli() { return hww.nbtight_SD_annuli(); }
const int &nbtight_SD_same() { return hww.nbtight_SD_same(); }
const int &nbtight_SD_away() { return hww.nbtight_SD_away(); }
const float &ht() { return hww.ht(); }
const float &ht_in() { return hww.ht_in(); }
const float &ht_annuli() { return hww.ht_annuli(); }
const float &ht_same() { return hww.ht_same(); }
const float &ht_away() { return hww.ht_away(); }
const float &ht_SD_in() { return hww.ht_SD_in(); }
const float &ht_SD_annuli() { return hww.ht_SD_annuli(); }
const float &ht_SD_same() { return hww.ht_SD_same(); }
const float &ht_SD_away() { return hww.ht_SD_away(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &R_p4() { return hww.R_p4(); }
const float &R_pt() { return hww.R_pt(); }
const float &R_eta() { return hww.R_eta(); }
const float &R_phi() { return hww.R_phi(); }
const float &R_mass() { return hww.R_mass(); }
const float &R_energy() { return hww.R_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &R_cent_p4() { return hww.R_cent_p4(); }
const float &R_cent_pt() { return hww.R_cent_pt(); }
const float &R_cent_eta() { return hww.R_cent_eta(); }
const float &R_cent_phi() { return hww.R_cent_phi(); }
const float &R_cent_mass() { return hww.R_cent_mass(); }
const float &R_cent_energy() { return hww.R_cent_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_recoil_p4() { return hww.gen_recoil_p4(); }
const int &gen_recoil_id() { return hww.gen_recoil_id(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_higgs_p4() { return hww.gen_higgs_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_whad_p4() { return hww.gen_whad_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_wlep_p4() { return hww.gen_wlep_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_q0_p4() { return hww.gen_q0_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_q1_p4() { return hww.gen_q1_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_lep_p4() { return hww.gen_lep_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_neu_p4() { return hww.gen_neu_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_Vq0_p4() { return hww.gen_Vq0_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_Vq1_p4() { return hww.gen_Vq1_p4(); }
const int &gen_Vq0_id() { return hww.gen_Vq0_id(); }
const int &gen_Vq1_id() { return hww.gen_Vq1_id(); }
const int &gen_q0_id() { return hww.gen_q0_id(); }
const int &gen_q1_id() { return hww.gen_q1_id(); }
const int &gen_lep_id() { return hww.gen_lep_id(); }
const int &gen_neu_id() { return hww.gen_neu_id(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_b0_p4() { return hww.gen_b0_p4(); }
const float &gen_b0_pt() { return hww.gen_b0_pt(); }
const float &gen_b0_eta() { return hww.gen_b0_eta(); }
const float &gen_b0_phi() { return hww.gen_b0_phi(); }
const float &gen_b0_mass() { return hww.gen_b0_mass(); }
const float &gen_b0_energy() { return hww.gen_b0_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_b1_p4() { return hww.gen_b1_p4(); }
const float &gen_b1_pt() { return hww.gen_b1_pt(); }
const float &gen_b1_eta() { return hww.gen_b1_eta(); }
const float &gen_b1_phi() { return hww.gen_b1_phi(); }
const float &gen_b1_mass() { return hww.gen_b1_mass(); }
const float &gen_b1_energy() { return hww.gen_b1_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_t0_p4() { return hww.gen_t0_p4(); }
const float &gen_t0_pt() { return hww.gen_t0_pt(); }
const float &gen_t0_eta() { return hww.gen_t0_eta(); }
const float &gen_t0_phi() { return hww.gen_t0_phi(); }
const float &gen_t0_mass() { return hww.gen_t0_mass(); }
const float &gen_t0_energy() { return hww.gen_t0_energy(); }
const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &gen_t1_p4() { return hww.gen_t1_p4(); }
const float &gen_t1_pt() { return hww.gen_t1_pt(); }
const float &gen_t1_eta() { return hww.gen_t1_eta(); }
const float &gen_t1_phi() { return hww.gen_t1_phi(); }
const float &gen_t1_mass() { return hww.gen_t1_mass(); }
const float &gen_t1_energy() { return hww.gen_t1_energy(); }
const float &gen_b0_dr() { return hww.gen_b0_dr(); }
const int &gen_b0_in() { return hww.gen_b0_in(); }
const int &gen_b0_annuli() { return hww.gen_b0_annuli(); }
const int &gen_b0_same() { return hww.gen_b0_same(); }
const int &gen_b0_away() { return hww.gen_b0_away(); }
const float &gen_b1_dr() { return hww.gen_b1_dr(); }
const int &gen_b1_in() { return hww.gen_b1_in(); }
const int &gen_b1_annuli() { return hww.gen_b1_annuli(); }
const int &gen_b1_same() { return hww.gen_b1_same(); }
const int &gen_b1_away() { return hww.gen_b1_away(); }
const float &gen_b0_SD_dr() { return hww.gen_b0_SD_dr(); }
const int &gen_b0_SD_in() { return hww.gen_b0_SD_in(); }
const int &gen_b0_SD_annuli() { return hww.gen_b0_SD_annuli(); }
const int &gen_b0_SD_same() { return hww.gen_b0_SD_same(); }
const int &gen_b0_SD_away() { return hww.gen_b0_SD_away(); }
const float &gen_b1_SD_dr() { return hww.gen_b1_SD_dr(); }
const int &gen_b1_SD_in() { return hww.gen_b1_SD_in(); }
const int &gen_b1_SD_annuli() { return hww.gen_b1_SD_annuli(); }
const int &gen_b1_SD_same() { return hww.gen_b1_SD_same(); }
const int &gen_b1_SD_away() { return hww.gen_b1_SD_away(); }
const float &gen_t0_dr() { return hww.gen_t0_dr(); }
const int &gen_t0_in() { return hww.gen_t0_in(); }
const int &gen_t0_annuli() { return hww.gen_t0_annuli(); }
const int &gen_t0_same() { return hww.gen_t0_same(); }
const int &gen_t0_away() { return hww.gen_t0_away(); }
const float &gen_t1_dr() { return hww.gen_t1_dr(); }
const int &gen_t1_in() { return hww.gen_t1_in(); }
const int &gen_t1_annuli() { return hww.gen_t1_annuli(); }
const int &gen_t1_same() { return hww.gen_t1_same(); }
const int &gen_t1_away() { return hww.gen_t1_away(); }
const float &gen_t0_SD_dr() { return hww.gen_t0_SD_dr(); }
const int &gen_t0_SD_in() { return hww.gen_t0_SD_in(); }
const int &gen_t0_SD_annuli() { return hww.gen_t0_SD_annuli(); }
const int &gen_t0_SD_same() { return hww.gen_t0_SD_same(); }
const int &gen_t0_SD_away() { return hww.gen_t0_SD_away(); }
const float &gen_t1_SD_dr() { return hww.gen_t1_SD_dr(); }
const int &gen_t1_SD_in() { return hww.gen_t1_SD_in(); }
const int &gen_t1_SD_annuli() { return hww.gen_t1_SD_annuli(); }
const int &gen_t1_SD_same() { return hww.gen_t1_SD_same(); }
const int &gen_t1_SD_away() { return hww.gen_t1_SD_away(); }

}

#include "rooutil.cc"
