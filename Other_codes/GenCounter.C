
#include "TFile.h"
#include "TSystem.h"
#include "TChain.h"
#include "TTree.h"
#include "TBranch.h"
#include "TStyle.h"
#include "TMath.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TH1.h"

//TH1F * Gethisto2(TFile *f, TString name,TString title, TString variable) {

    //Grab Branch and set axis limits
//    TDirectory *dir = f->GetDirectory("FlatNtupleData");
//    TTree *tr = (TTree*)dir->Get("tree");
//    float nEv = tr->GetEntries();
    //TH1D *hPt = new TH1D(name, title, binnum, bins);//if options for variable binning are set above
//    TH1F *histo = new TH1F(name, title, nBins, Xlow, Xhi);
//    tr->Project(name,variable , cBase);
    //histo->Scale(1/nEv);
//    return histo;
//}


void GenCounter() {
TFile *f = new TFile("ZZTo2L2Nu.root");
TTree *tr = (TTree*)f->Get("Runs");
TH1D *hPt = new TH1D("h", "h2", 1000000, 0, 1000000);
tr->Project("h","genEventCount" ,"");
double integral = hPt->Integral(0,1000000,"width");
std::cout << integral << std::endl;
}