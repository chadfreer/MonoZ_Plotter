#include <Python.h>
//Code to choose the cuts desired

TH1D * GethPt(TFile *f, TString dataset,TString name,TString title, int Branch_count, bool NminusOne) {
    Int_t opt = 0;
	

    //Set up N-1 plots
    //if (NminusOne == 1) {
    //    TCuts[Branch_count] = "";
    //}

    //Set up the trigger
    TCut cOther = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL||HLT_DoubleEle33_CaloIdL_MW||HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8||HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8||HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL||HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ||HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ||HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ||HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ||HLT_Mu8_DiEle12_CaloIdL_TrackIdL||HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ||HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL||HLT_TripleMu_10_5_5_DZ||HLT_TripleMu_12_10_5||HLT_Ele35_WPTight_Gsf||HLT_Ele38_WPTight_Gsf||HLT_Ele40_WPTight_Gsf||HLT_IsoMu27";
   // TCut cOther = "HLT_Ele27_WPTight_Gsf || HLT_IsoMu24 || HLT_Mu50 || HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ|| HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL || HLT_Mu17_TrkIsoVVL || HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL || HLT_Photon50_R9Id90_HE10_IsoM || HLT_Photon75_R9Id90_HE10_IsoM || HLT_Photon90_R9Id90_HE10_IsoM || HLT_Mu17 || HLT_Ele115_CaloIdVT_GsfTrkIdT";
    //No Cuts

	int ind = -1 ;
    //Grab Branch and set axis limits
    //TDirectory *dir = f->GetDirectory(dataset);
    //TTree *tr = (TTree*)dir->Get("preSelection");



     //	TTree *tr = (TTree*)f->Get("Events");
    //float nEv = tr->GetEntries();
    //TH1D *hPt = new TH1D(name, title, binnum, bins);

    
    PyObject* myModuleString = PyString_FromString((char*)"example");
    PyObject* myModule = PyImport_Import(myModuleString);
    
    PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)"test");
    //PyObject* args = PyTuple_Pack(name, title, nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    PyObject* args = PyString_FromString((char)name);
    //PyObject* myResult = PyObject_CallObject(myFunction, args);
    PyObject* myResult = PyObject_CallObject(myFunction, args);
    //TH1D hPt = myResult;

    //TH1D *hPt = new TH1D(name, title, nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    //tr->Project(name,variable[Branch_count] ,"weight" && cBase && cJets && cOther);
	//tr->Project(name,variable[Branch_count] ,"lep_category==1 && Z_pt > 60 && met_pt > 40 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0" && cOther);

	//tr->Project(name,variable[Branch_count],"genWeight && puWeight && lep_category==1 && Z_pt > 60 && met_pt > 40 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0" && cOther);
        //tr->Project(name,variable[Branch_count],"puWeight * lumiWeight * (lep_category==1 && Z_pt > 60 && met_pt > 40 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0)"&& cOther);
        //tr->Project(name,variable[Branch_count],"puWeight * lumiWeight * (lep_category>0 && lep_category < 4 && lep_category!=2 && met_pt > 50 && met_pt < 100 && Z_pt > 60 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0)"&& cOther);
        //tr->Project(name,variable[Branch_count] , cOther);
        float nEv = hPt->Integral(0,nBins[Branch_count]);

	//Color and normalize plots
	for (int i = 0; i < nData; ++i) if (Data[i][0]==title) ind = i;
	double nGen = atof(Data[ind][2]);
	double kCX = atof(Data[ind][1]);
	//double kSc = (nEv==0) ? 0 : 41500/nGen*kCX;
	double kSc = (nEv==0) ? 0 : 41.5;
	hPt->Scale(kSc);
	Color_t kCol;
	if (Data[ind][4]=="DY") kCol = kPink+1;
	if (Data[ind][4]=="ZZ") kCol = kOrange-2;
	if (Data[ind][4]=="TT") kCol = kGray+1;
	if (Data[ind][4]=="WW") kCol = kTeal+2;
	if (Data[ind][4]=="WZ") kCol = kAzure-4;
        if (Data[ind][4]=="VVV") kCol = kPink-5;
	if (Data[ind][4]=="VBS") kCol = kRed;
	if (Data[ind][4]=="LLDM") kCol = kBlue;
	hPt->SetFillColor(kCol);
	float nEv2 = hPt->Integral(0,nBins[Branch_count]);
	cout << title << "    GEN:   " <<  nEv << "     RECO:   " << nEv2 <<endl;
	
	return hPt;
};


TH1D * GetDATAhPt(TFile *f, TString dataset,TString name,TString title, int Branch_count, bool NminusOne) {
	Int_t opt = 0;
	
	
	//Set up N-1 plots
	//if (NminusOne == 1) {
	//	TCuts[Branch_count] = "";
	//}
	
	
	//Set up the trigger
TCut cOther = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL||HLT_DoubleEle33_CaloIdL_MW||HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8||HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8||HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL||HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ||HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ||HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ||HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ||HLT_Mu8_DiEle12_CaloIdL_TrackIdL||HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ||HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL||HLT_TripleMu_10_5_5_DZ||HLT_TripleMu_12_10_5||HLT_Ele35_WPTight_Gsf||HLT_Ele38_WPTight_Gsf||HLT_Ele40_WPTight_Gsf||HLT_IsoMu27a";
	//TCut cOther = "HLT_Ele27_WPTight_Gsf || HLT_IsoMu24 || HLT_Mu50 || HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ|| HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL || HLT_Mu17_TrkIsoVVL || HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL || HLT_Photon50_R9Id90_HE10_IsoM || HLT_Photon75_R9Id90_HE10_IsoM || HLT_Photon90_R9Id90_HE10_IsoM || HLT_Mu17 || HLT_Ele115_CaloIdVT_GsfTrkIdT";
	//No Cuts
	
	int ind = -1 ;
	//Grab Branch and set axis limits
	//TDirectory *dir = f->GetDirectory(dataset);
	//TTree *tr = (TTree*)dir->Get("preSelection");
	TTree *tr = (TTree*)f->Get("Events");
	//float nEv = tr->GetEntries();
	//TH1D *hPt = new TH1D(name, title, binnum, bins);
	TH1D *hPt = new TH1D(name, title, nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
	//tr->Project(name,variable[Branch_count] , cOther);
	tr->Project(name,variable[Branch_count] ,"lep_category>0 && lep_category < 4 && lep_category!=2 && met_pt > 50 && met_pt < 100 && Z_pt > 60 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0"&& cOther);
	//float nEv = hPt->Integral(0,nBins[Branch_count]);
	
	for (int i = 0; i < nData; ++i) if (Data[i][0]==title) ind = i;
	float nEv2 = hPt->Integral(0,nBins[Branch_count]);
	cout << title << "    GEN:   NONE"  << "     RECO:   " << nEv2 <<endl;
	
	return hPt;
};
