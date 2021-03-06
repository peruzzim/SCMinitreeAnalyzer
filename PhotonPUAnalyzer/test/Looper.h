//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Sep 22 16:33:55 2012 by ROOT version 5.32/01
// from TTree Tree/Minitree
// found on file: DYJetsToLL_M_50_TuneZ2Star_8TeV_madgraph_tarball_Summer12_DR53X_PU_S10_START53_V7A_v1_AODSIM.root
//////////////////////////////////////////////////////////

#ifndef Looper_h
#define Looper_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include "TH1F.h"
#include <vector>
#include "TLorentzVector.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

struct ParticleObject {
   // Declaration of leaf types
   Int_t           event_number;
   Int_t           event_run;
   Int_t           event_ls;
   Int_t           event_SCindex;
   Int_t           event_coll_size;
   Int_t           event_nRecoVertex;
   Float_t         event_rho;
   Float_t         event_sigma;
   Float_t         GenEnergy;
   Float_t         GenEta;
   Float_t         GenPhi;
   Int_t           event_genPU;
   Int_t           event_genPUtrue;
   Int_t           ele_looseID;
   Int_t           ele_mediumID;
   Int_t           ele_tightID;
   Float_t         track_pt;
   Float_t         track_eta;
   Float_t         track_phi;
   Int_t           pixelseed;
   Int_t           pho_isInPhiCrack;
   Int_t           pho_isInEtaCrack;
   Int_t           pho_isInEBEEGap;
   Float_t         phoSC_energy;
   Float_t         phoSC_RawEnergy;
   Float_t         phoSC_et;
   Float_t         phoSC_RawEt;
   Float_t         phoSC_RawEtCetaCorr;
   Float_t         phoSC_RawEnergyCetaCorr;
   Float_t         phoSC_GeomEta;
   Float_t         phoSC_GeomPhi;
   Float_t         pho_r9;
   Float_t         pho_sigmaIetaIeta;
   Float_t         pho_e3x3;
   Float_t         pho_e5x5;
   Float_t         pho_etaWidth;
   Float_t         pho_phiWidth;
   Float_t         pho_Brem;
};



class Looper {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   ParticleObject obj_;

   // List of branches
   TBranch        *b_event_number;   //!
   TBranch        *b_event_run;   //!
   TBranch        *b_event_ls;   //!
   TBranch        *b_event_SCindex;   //!
   TBranch        *b_event_coll_size;   //!
   TBranch        *b_event_nRecoVertex;   //!
   TBranch        *b_event_rho;   //!
   TBranch        *b_event_sigma;   //!
   TBranch        *b_GenEnergy;   //!
   TBranch        *b_GenEta;   //!
   TBranch        *b_GenPhi;   //!
   TBranch        *b_event_genPU;   //!
   TBranch        *b_event_genPUtrue;   //!
   TBranch        *b_ele_looseID;   //!
   TBranch        *b_ele_mediumID;   //!
   TBranch        *b_ele_tightID;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_pixelseed;   //!
   TBranch        *b_pho_isInPhiCrack;   //!
   TBranch        *b_pho_isInEtaCrack;   //!
   TBranch        *b_pho_isInEBEEGap;   //!
   TBranch        *b_phoSC_energy;   //!
   TBranch        *b_phoSC_RawEnergy;   //!
   TBranch        *b_phoSC_et;   //!
   TBranch        *b_phoSC_RawEt;   //!
   TBranch        *b_phoSC_RawEtCetaCorr;   //!
   TBranch        *b_phoSC_RawEnergyCetaCorr;   //!
   TBranch        *b_phoSC_GeomEta;   //!
   TBranch        *b_phoSC_GeomPhi;   //!
   TBranch        *b_pho_r9;   //!
   TBranch        *b_pho_sigmaIetaIeta;   //!
   TBranch        *b_pho_e3x3;   //!
   TBranch        *b_pho_e5x5;   //!
   TBranch        *b_pho_etaWidth;   //!
   TBranch        *b_pho_phiWidth;   //!
   TBranch        *b_pho_Brem;   //!

   Looper(TString datafile, TString mcfile);
   virtual ~Looper();
   //   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   Int_t Choose_bin_eta(float eta, int region);
   Float_t GetWeight(int nvtx);

   void SetupPUReweighting(TString datafile, TString mcfile);
   bool purewsetup;
   TH1F histo_purew;
};

static const int n_templates_EB=7;
static const int n_templates_EE=5;
static const int n_templates_max=7;
float binsdef_single_gamma_EB_eta[n_templates_EB+1]={0,0.2,0.4,0.6,0.8,1,1.2,1.44};
float binsdef_single_gamma_EE_eta[n_templates_EE+1]={1.56,1.653,1.8,2,2.2,2.5};

#endif

#ifdef Looper_cxx

Float_t Looper::GetWeight(int nvtx){
  if (!purewsetup) return -999;
  return histo_purew.GetBinContent(histo_purew.FindBin(nvtx));
}

void Looper::SetupPUReweighting(TString datafile, TString mcfile){

  TFile *f1 = new TFile(datafile.Data(),"read");
  TFile *f2 = new TFile(mcfile.Data(),"read");

  if (f1->IsZombie() || f2->IsZombie()){
    std::cout << "Error in PU reweighting files" << std::endl;
    return;
  }

  TH1F *hdata;
  TH1F *hmc;
  f1->GetObject("histo_nrecvtx_norew",hdata);
  f2->GetObject("histo_nrecvtx_norew",hmc);

  hdata->Sumw2();
  hmc->Sumw2();

  hdata->Scale(1.0/hdata->Integral());
  hmc->Scale(1.0/hmc->Integral());
 
  hdata->Divide(hmc);

  hdata->Copy(histo_purew);
  purewsetup=1;
}

Looper::Looper(TString datafile, TString mcfile) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

  TTree *tree;
  gDirectory->GetObject("Tree",tree);
  Init(tree);
  
  purewsetup=0;
  SetupPUReweighting(datafile,mcfile);

}

Looper::~Looper()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Looper::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Looper::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Looper::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_number", &(obj_.event_number), &b_event_number);
   fChain->SetBranchAddress("event_run", &(obj_.event_run), &b_event_run);
   fChain->SetBranchAddress("event_ls", &(obj_.event_ls), &b_event_ls);
   fChain->SetBranchAddress("event_SCindex", &(obj_.event_SCindex), &b_event_SCindex);
   fChain->SetBranchAddress("event_coll_size", &(obj_.event_coll_size), &b_event_coll_size);
   fChain->SetBranchAddress("event_nRecoVertex", &(obj_.event_nRecoVertex), &b_event_nRecoVertex);
   fChain->SetBranchAddress("event_rho", &(obj_.event_rho), &b_event_rho);
   fChain->SetBranchAddress("event_sigma", &(obj_.event_sigma), &b_event_sigma);
   fChain->SetBranchAddress("GenEnergy", &(obj_.GenEnergy), &b_GenEnergy);
   fChain->SetBranchAddress("GenEta", &(obj_.GenEta), &b_GenEta);
   fChain->SetBranchAddress("GenPhi", &(obj_.GenPhi), &b_GenPhi);
   fChain->SetBranchAddress("event_genPU", &(obj_.event_genPU), &b_event_genPU);
   fChain->SetBranchAddress("event_genPUtrue", &(obj_.event_genPUtrue), &b_event_genPUtrue);
   fChain->SetBranchAddress("ele_looseID", &(obj_.ele_looseID), &b_ele_looseID);
   fChain->SetBranchAddress("ele_mediumID", &(obj_.ele_mediumID), &b_ele_mediumID);
   fChain->SetBranchAddress("ele_tightID", &(obj_.ele_tightID), &b_ele_tightID);
   fChain->SetBranchAddress("track_pt", &(obj_.track_pt), &b_track_pt);
   fChain->SetBranchAddress("track_eta", &(obj_.track_eta), &b_track_eta);
   fChain->SetBranchAddress("track_phi", &(obj_.track_phi), &b_track_phi);
   fChain->SetBranchAddress("pixelseed", &(obj_.pixelseed), &b_pixelseed);
   fChain->SetBranchAddress("pho_isInPhiCrack", &(obj_.pho_isInPhiCrack), &b_pho_isInPhiCrack);
   fChain->SetBranchAddress("pho_isInEtaCrack", &(obj_.pho_isInEtaCrack), &b_pho_isInEtaCrack);
   fChain->SetBranchAddress("pho_isInEBEEGap", &(obj_.pho_isInEBEEGap), &b_pho_isInEBEEGap);
   fChain->SetBranchAddress("phoSC_energy", &(obj_.phoSC_energy), &b_phoSC_energy);
   fChain->SetBranchAddress("phoSC_RawEnergy", &(obj_.phoSC_RawEnergy), &b_phoSC_RawEnergy);
   fChain->SetBranchAddress("phoSC_et", &(obj_.phoSC_et), &b_phoSC_et);
   fChain->SetBranchAddress("phoSC_RawEt", &(obj_.phoSC_RawEt), &b_phoSC_RawEt);
   fChain->SetBranchAddress("phoSC_RawEtCetaCorr", &(obj_.phoSC_RawEtCetaCorr), &b_phoSC_RawEtCetaCorr);
   fChain->SetBranchAddress("phoSC_RawEnergyCetaCorr", &(obj_.phoSC_RawEnergyCetaCorr), &b_phoSC_RawEnergyCetaCorr);
   fChain->SetBranchAddress("phoSC_GeomEta", &(obj_.phoSC_GeomEta), &b_phoSC_GeomEta);
   fChain->SetBranchAddress("phoSC_GeomPhi", &(obj_.phoSC_GeomPhi), &b_phoSC_GeomPhi);
   fChain->SetBranchAddress("pho_r9", &(obj_.pho_r9), &b_pho_r9);
   fChain->SetBranchAddress("pho_sigmaIetaIeta", &(obj_.pho_sigmaIetaIeta), &b_pho_sigmaIetaIeta);
   fChain->SetBranchAddress("pho_e3x3", &(obj_.pho_e3x3), &b_pho_e3x3);
   fChain->SetBranchAddress("pho_e5x5", &(obj_.pho_e5x5), &b_pho_e5x5);
   fChain->SetBranchAddress("pho_etaWidth", &(obj_.pho_etaWidth), &b_pho_etaWidth);
   fChain->SetBranchAddress("pho_phiWidth", &(obj_.pho_phiWidth), &b_pho_phiWidth);
   fChain->SetBranchAddress("pho_Brem", &(obj_.pho_Brem), &b_pho_Brem);
   Notify();
}

Bool_t Looper::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Looper::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
//Int_t Looper::Cut(Long64_t entry)
//{
//// This function may be called from Loop.
//// returns  1 if entry is accepted.
//// returns -1 otherwise.
//   return 1;
//}

Int_t Looper::Choose_bin_eta(float eta, int region){

  eta=fabs(eta);

  int index;

  float *cuts=NULL;

  if (region==0) {cuts=binsdef_single_gamma_EB_eta; index=n_templates_EB;}
  if (region==1) {cuts=binsdef_single_gamma_EE_eta; index=n_templates_EE;}

  assert (cuts!=NULL);
  assert (index!=0);

  if (eta<cuts[0]){
    std::cout << "WARNING: called bin choice for out-of-range value " << eta << " cuts[0]=" << cuts[0] << std::endl;
    return -999;
  }

  for (int i=0; i<index; i++) if ((eta>=cuts[i]) && (eta<cuts[i+1])) return i;

  std::cout << "WARNING: called bin choice for out-of-range value " << eta << std::endl;
  return -999;

};


#endif // #ifdef Looper_cxx
