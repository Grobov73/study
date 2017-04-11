#define cbmsim_reduced_cxx
#include "cbmsim_reduced.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

void cbmsim_reduced::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L cbmsim_reduced.C
//      Root > cbmsim_reduced t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      // Fill pt histogram

   for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && PDG_code_mc[id_from_mc_mpd[itracks]]==2212 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_pt_mpd->Fill(TMath::Abs(signed_pt_mpd[itracks]));
      }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mc;itracks++){
      if(pt_mc[itracks]<=3 && PDG_code_mc[itracks]==2212 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1) {
      h_pt_mc->Fill(pt_mc[itracks]);
   }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && TMath::Abs(PDG_code_mc[id_from_mc_mpd[itracks]])==321 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_kaon_pt_mpd->Fill(TMath::Abs(signed_pt_mpd[itracks]));
      }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mc;itracks++){
      if(pt_mc[itracks]<=3 && TMath::Abs(PDG_code_mc[itracks])==321 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1) {
      h_kaon_pt_mc->Fill(pt_mc[itracks]);
   }
   }


   for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && TMath::Abs(PDG_code_mc[id_from_mc_mpd[itracks]])==211 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_pion_pt_mpd->Fill(TMath::Abs(signed_pt_mpd[itracks]));
      }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mc;itracks++){
      if(pt_mc[itracks]<=3 && TMath::Abs(PDG_code_mc[itracks])==211 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1) {
      h_pion_pt_mc->Fill(pt_mc[itracks]);
   }
   }

   // fill eta histogram

      for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && PDG_code_mc[id_from_mc_mpd[itracks]]==2212 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_p_eta_mpd->Fill(eta_mpd[itracks]);
      }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mc;itracks++){
      if(pt_mc[itracks]<=3 && PDG_code_mc[itracks]==2212 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1) {
      h_p_eta_mc->Fill(eta_mc[itracks]);
   }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && TMath::Abs(PDG_code_mc[id_from_mc_mpd[itracks]])==321 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_kaon_eta_mpd->Fill(eta_mpd[itracks]);
      }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mc;itracks++){
      if(pt_mc[itracks]<=3 && TMath::Abs(PDG_code_mc[itracks])==321 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1) {
      h_kaon_eta_mc->Fill(eta_mc[itracks]);
   }
   }


   for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && TMath::Abs(PDG_code_mc[id_from_mc_mpd[itracks]])==211 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_pion_eta_mpd->Fill(eta_mpd[itracks]);
      }
   }

   for (Long64_t itracks=0;itracks<n_tracks_mc;itracks++){
      if(pt_mc[itracks]<=3 && TMath::Abs(PDG_code_mc[itracks])==211 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1) {
      h_pion_eta_mc->Fill(eta_mc[itracks]);
   }
   }

   // Fill 2D histogram *I know that cuts should be rewrited using "continue"
    for (Long64_t itracks=0;itracks<n_tracks_mpd;itracks++){
      if(TMath::Abs(signed_pt_mpd[itracks])<=3 && pt_mc[itracks]<=3 && PDG_code_mc[itracks]==2212 && TMath::Abs(eta_mc[itracks])<=1.5 && mother_ID_mc[itracks]==-1&& TMath::Abs(PDG_code_mc[id_from_mc_mpd[itracks]])==2212 && TMath::Abs(eta_mpd[itracks])<=1.5 && n_hits_mpd[itracks]>=32 && mother_ID_mc[id_from_mc_mpd[itracks]]==-1) {
      h_ptcorr->Fill(pt_mc[id_from_mc_mpd[itracks]], TMath::Abs(signed_pt_mpd[itracks]));
      }
   }


   }
   // pt efficiencies

   h_p_eff->Divide(h_pt_mpd,h_pt_mc);
   h_k_eff->Divide(h_kaon_pt_mpd,h_kaon_pt_mc);
   h_pi_eff->Divide(h_pion_pt_mpd,h_pion_pt_mc);

   // Create a beauty

   h_p_eff->SetMarkerStyle(kFullTriangleUp);
   h_k_eff->SetMarkerStyle(kFullTriangleDown);
   h_pi_eff->SetMarkerStyle(kCircle);

   h_p_eff->SetLineColor(kBlack);
   h_pi_eff->SetLineColor(kBlue);
   h_k_eff->SetLineColor(kRed);

   h_p_eff->SetMarkerColor(kBlack);
   h_pi_eff->SetMarkerColor(kBlue);
   h_k_eff->SetMarkerColor(kRed);

   // Draw three efficiency histos on one Fig.
   TCanvas *C = new TCanvas("pt efficiencies","pt efficiences",600,400);
   TH1F *frame = (TH1F*)C->DrawFrame(0,-1,3,7);
   frame->GetXaxis()->SetTitle("transverse momentum, [GeV]");
   frame->GetYaxis()->SetTitle("Efficiency");
   h_p_eff->Draw("same");
   h_k_eff->Draw("same");
   h_pi_eff->Draw("same");
   // I'm a legend (c)
   TLegend *legend = new TLegend(0.55,0.65,0.16,0.82);
   legend->SetHeader("Efficiencies of particle reconstruction");
   legend->AddEntry(h_p_eff,"protons","lep");
   legend->AddEntry(h_k_eff,"kaons","lep");
   legend->AddEntry(h_pi_eff,"pions","lep");
   legend->Draw();

   // Difference of momenta
   h_p_diff->Add(h_pt_mpd, h_pt_mc, -1,1);
   h_p_diff->SetMarkerStyle(29);
   h_p_diff->SetMarkerColor(8);
   TCanvas *C1=new TCanvas("diff", "Difference of events with reco and mc momenta", 600,400);
   h_p_diff->Draw();


   // eta efficiencies

   h_peta_eff->Divide(h_p_eta_mpd,h_p_eta_mc);
   h_keta_eff->Divide(h_kaon_eta_mpd,h_kaon_eta_mc);
   h_pieta_eff->Divide(h_pion_eta_mpd,h_pion_eta_mc);

   //Draw a histo with three eta efficiencies
   h_peta_eff->SetMarkerStyle(kFullTriangleUp);
   h_keta_eff->SetMarkerStyle(kFullTriangleDown);
   h_pieta_eff->SetMarkerStyle(kCircle);

   h_peta_eff->SetLineColor(kBlack);
   h_pieta_eff->SetLineColor(kBlue);
   h_keta_eff->SetLineColor(kRed);

   h_peta_eff->SetMarkerColor(kBlack);
   h_pieta_eff->SetMarkerColor(kBlue);
   h_keta_eff->SetMarkerColor(kRed);

   TCanvas *CC = new TCanvas("eta efficiencies","eta efficiencies",600,400);
   TH1F *framee = (TH1F*)CC->DrawFrame(0,0,1.5,2.5);
   framee->GetXaxis()->SetTitle("eta");
   framee->GetYaxis()->SetTitle("Efficiency");
   h_peta_eff->Draw("same");
   h_keta_eff->Draw("same");
   h_pieta_eff->Draw("same");
   TLegend *legend = new TLegend(0.55,0.65,0.16,0.82);
   legend->SetHeader("Efficiencies of particle reconstruction");
   legend->AddEntry(h_peta_eff,"protons","lep");
   legend->AddEntry(h_keta_eff,"kaons","lep");
   legend->AddEntry(h_pieta_eff,"pions","lep");
   legend->Draw();
   
   //Correlation of momenta
   TCanvas *C2=new TCanvas("2d", "Correlation between pt", 600,400);
   h_ptcorr->Draw("colz");


   // Write this all into a file
   TFile *foutput=new TFile("foutput.root","recreate");
   foutput->cd();
   h_pt_mpd->Write();
   h_pt_mc->Write();
   h_p_eff->Write();
   h_k_eff->Write();
   h_pi_eff->Write();
   h_peta_eff->Write();
   h_keta_eff->Write();
   h_pieta_eff->Write();
   h_kaon_pt_mpd->Write();
   h_kaon_pt_mc->Write();
   h_pion_pt_mpd->Write();
   h_pion_pt_mc->Write();
   h_p_eta_mpd->Write();
   h_p_eta_mc->Write();
   h_kaon_eta_mpd->Write();
   h_kaon_eta_mc->Write();
   h_pion_eta_mpd->Write();
   h_pion_eta_mc->Write();
   foutput->Close();

   delete foutput;
   
}
