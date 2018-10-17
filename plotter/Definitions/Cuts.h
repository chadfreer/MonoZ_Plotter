//Code to choose the cuts desired

char const *TCuts[] = {		"preZmass > 81 && preZmass < 101"               /*ZMass				(0)*/,
				"prepfMet > 100"                                /*prepfMet			(1)*/,
				"Zpt_Reco>20"                                   /*Zpt_Reco			(2)*/,
				"DeltaPhiZMet > .8"                             /*DeltaPhiZMet			(3)*/,
				"Balance > 0.6"                                   /*Balance			(4)*/,
				""                                              /*DeltaPhill			(5)*/,
				""                                              /*DeltaEtall			(6)*/,
				"LeadingPtll > 20"                              /*LeadingPtll			(7)*/,
				"TrailingPtll >20"                              /*TrailingPtll			(8)*/,
				""                                              /*LeadingEtall			(9)*/,
				""                                              /*TrailingEtall			(10)*/,
				""                                              /*Etall				(11)*/,
				""                                              /*Rapidityll			(12)*/,
				"ngoodjets > 1"                                 /*ngoodjets			(13)*/,
				"LeadingJetPt > 50"                             /*LeadingJetPt			(14)*/,
				"subLeadingJetPt > 30"                          /*subLeadingJetPt		(15)*/,
				""						/*LeadingJetEta			(16)*/,
				""						/*subLeadingJetEta		(17)*/,
				"DijetMass > 500"                               /*DijetMass			(18)*/,
				""                                              /*DeltaPhijj			(19)*/,
				"DeltaEtajj > 3"                                /*DeltaEtajj			(20)*/,
				"nBjets < 1"                                    /*nBjets			(21)*/,
				""                                              /*xJet				(22)*/,
				"xZ < 0.5"                                      /*xZ				(23)*/,
				"Zeppenfeld > -2 && Zeppenfeld < 2"             /*Zeppenfeld			(24)*/,
				""                                              /*ZeppenfeldLep1		(25)*/,
				""                                              /*ZeppenfeldLep2		(26)*/,
				"xMet > 0.2"					/*xMet				(27)*/,
				"HT>200"                                        /*HT				(28)*/,
				"HTF > 0.7"                                     /*HTF	0.55			(29)*/,
				""                                              /*JetPtRatio			(30)*/,
				"JetEtaMultiplicity < -2"                       /*JetEtaMultiplicity 1		(31)*/,
				""                                              /*DPTOZ				(32)*/,
				""                                              /*CJVPt				(33)*/,
				""                                              /*CJVPtSum			(34)*/,
				""						/*Rpt				(35)*/,
				""						/*genjets			(36)*/,
				"DeltaPhiLeadingJetMet > 1"			/*DeltaPhiLeadingJetMet		(37)*/,
				""						/*DeltaPhiClosestJetMet		(38)*/,
				"DeltaPhiFarthestJetMet > 1"			/*DeltaPhiFarthestJetMet	(39)*/,
				""						/*EtaThirdJet			(40)*/};



TH1D * GethPt(TFile *f, TString dataset,TString name,TString title, int Branch_count, bool NminusOne) {
    Int_t opt = 0;
	

    //Set up N-1 plots
    if (NminusOne == 1) {
        TCuts[Branch_count] = "";
    }

	
    //Cut Parameters
    TCut cBase = TCuts[2];
    TCut cJets = "ngoodjets > 1 && nBjets < 1";
    //TCut cJets = "";
    //TCut PassMET = "prepfMet > 100";
    
    //TCut cJets = "";// && nBjets < 1";
    TCut PassMET = TCuts[1];
	//TCut PassMET = "prepfMet > 90";
    TCut PassDphiZMET = TCuts[3];
    TCut PassBalance = TCuts[4];
    TCut PassDijetMass = TCuts[18];
    TCut PassZmass = TCuts[0];
    //TCut PassZmass = "preZmass > 86 && preZmass < 96";
    TCut PassLeadingPtll = TCuts[7];
    TCut PassTrailingPtll = TCuts[8];
    TCut PassLeadingJetPt = TCuts[14];
    TCut PassSubLeadingJetPt = TCuts[15];
    //TCut PassBDTResponse = "BDT_response>.5";
    TCut PassChannel = "prechannel<9";
    TCut PassxZ = TCuts[23];
    TCut PassxMet = TCuts[27];
    TCut PassHTF = TCuts[29];
    TCut PassEtaMultiplied = TCuts[31];
    TCut PassDeltaEtajj = TCuts[20];
    TCut PassHT = TCuts[28];
    TCut PassZeppenfeld = TCuts[24];
    TCut PassLeadingJetEta = TCuts[16];
    TCut PassSubLeadingJetEta = TCuts[17];
    
    //Set up the trigger
    TCut cOther = "HLT_Ele27_WPTight_Gsf || HLT_IsoMu24 || HLT_Mu50 || HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ|| HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL || HLT_Mu17_TrkIsoVVL || HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL || HLT_Photon50_R9Id90_HE10_IsoM || HLT_Photon75_R9Id90_HE10_IsoM || HLT_Photon90_R9Id90_HE10_IsoM || HLT_Mu17 || HLT_Ele115_CaloIdVT_GsfTrkIdT";
    //No Cuts
    if (opt==0) cOther = "";

    //Basic Preselection
    if (opt==1) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel;

    //Tight Cuts VBS
    if (opt==2) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel && PassDijetMass && PassxZ && PassxMet && PassHTF && PassEtaMultiplied && PassBalance && PassDeltaEtajj && PassHT && PassZeppenfeld && PassLeadingJetEta && PassSubLeadingJetEta;
    
	if (opt==3) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel && PassDijetMass &&   PassEtaMultiplied  && PassDeltaEtajj && PassHT && TCuts[37] && TCuts[39] && PassxZ && PassxMet && PassHTF && PassBalance && PassZeppenfeld;// && PassLeadingJetEta && PassSubLeadingJetEta;
    
	if (opt==4) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel && PassEtaMultiplied && PassDeltaEtajj && TCuts[37] && TCuts[39] && PassZeppenfeld;
	
		if (opt==5) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel  && PassDeltaEtajj && PassDijetMass && TCuts[37];

	int ind = -1 ;
    //Grab Branch and set axis limits
    //TDirectory *dir = f->GetDirectory(dataset);
    //TTree *tr = (TTree*)dir->Get("preSelection");
	TTree *tr = (TTree*)f->Get("Events");
    //float nEv = tr->GetEntries();
    //TH1D *hPt = new TH1D(name, title, binnum, bins);
    TH1D *hPt = new TH1D(name, title, nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    //tr->Project(name,variable[Branch_count] ,"weight" && cBase && cJets && cOther);
	//tr->Project(name,variable[Branch_count] ,"lep_category==1 && Z_pt > 60 && met_pt > 40 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0" && cOther);

	tr->Project(name,variable[Branch_count],"genWeight && puWeight && lep_category==1 && Z_pt > 60 && met_pt > 40 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0" && cOther);
        float nEv = hPt->Integral(0,nBins[Branch_count]);

	//Color and normalize plots
	for (int i = 0; i < nData; ++i) if (Data[i][0]==title) ind = i;
	double nGen = atof(Data[ind][2]);
	double kCX = atof(Data[ind][1]);
	double kSc = (nEv==0) ? 0 : 41200/nGen*kCX;
	//double kSc = (nEv==0) ? 0 : 16800/nGen*kCX;
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
	if (NminusOne == 1) {
		TCuts[Branch_count] = "";
	}
	
	
	//Cut Parameters
	TCut cBase = TCuts[2];
	TCut cJets = "ngoodjets > 1 && nBjets < 1";
	//TCut cJets = "";
	//TCut PassMET = "prepfMet > 100";
	
	//TCut cJets = "";// && nBjets < 1";
	TCut PassMET = TCuts[1];
	//TCut PassMET = "prepfMet > 90";
	TCut PassDphiZMET = TCuts[3];
	TCut PassBalance = TCuts[4];
	TCut PassDijetMass = TCuts[18];
	TCut PassZmass = TCuts[0];
	//TCut PassZmass = "preZmass > 86 && preZmass < 96";
	TCut PassLeadingPtll = TCuts[7];
	TCut PassTrailingPtll = TCuts[8];
	TCut PassLeadingJetPt = TCuts[14];
	TCut PassSubLeadingJetPt = TCuts[15];
	//TCut PassBDTResponse = "BDT_response>.5";
	TCut PassChannel = "prechannel<9";
	TCut PassxZ = TCuts[23];
	TCut PassxMet = TCuts[27];
	TCut PassHTF = TCuts[29];
	TCut PassEtaMultiplied = TCuts[31];
	TCut PassDeltaEtajj = TCuts[20];
	TCut PassHT = TCuts[28];
	TCut PassZeppenfeld = TCuts[24];
	TCut PassLeadingJetEta = TCuts[16];
	TCut PassSubLeadingJetEta = TCuts[17];
	
	//Set up the trigger
	TCut cOther = "HLT_Ele27_WPTight_Gsf || HLT_IsoMu24 || HLT_Mu50 || HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ|| HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL || HLT_Mu17_TrkIsoVVL || HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ || HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL || HLT_Photon50_R9Id90_HE10_IsoM || HLT_Photon75_R9Id90_HE10_IsoM || HLT_Photon90_R9Id90_HE10_IsoM || HLT_Mu17 || HLT_Ele115_CaloIdVT_GsfTrkIdT";
	//No Cuts
	if (opt==0) cOther = "";
	
	//Basic Preselection
	if (opt==1) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel;
	
	//Tight Cuts VBS
	if (opt==2) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel && PassDijetMass && PassxZ && PassxMet && PassHTF && PassEtaMultiplied && PassBalance && PassDeltaEtajj && PassHT && PassZeppenfeld && PassLeadingJetEta && PassSubLeadingJetEta;
	
	if (opt==3) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel && PassDijetMass &&   PassEtaMultiplied  && PassDeltaEtajj && PassHT && TCuts[37] && TCuts[39] && PassxZ && PassxMet && PassHTF && PassBalance && PassZeppenfeld;// && PassLeadingJetEta && PassSubLeadingJetEta;
	
	if (opt==4) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel && PassEtaMultiplied && PassDeltaEtajj && TCuts[37] && TCuts[39] && PassZeppenfeld;
	
	if (opt==5) cOther = PassZmass && PassLeadingPtll && PassTrailingPtll && PassLeadingJetPt && PassSubLeadingJetPt && PassChannel  && PassDeltaEtajj && PassDijetMass && TCuts[37];
	
	int ind = -1 ;
	//Grab Branch and set axis limits
	//TDirectory *dir = f->GetDirectory(dataset);
	//TTree *tr = (TTree*)dir->Get("preSelection");
	TTree *tr = (TTree*)f->Get("Events");
	//float nEv = tr->GetEntries();
	//TH1D *hPt = new TH1D(name, title, binnum, bins);
	TH1D *hPt = new TH1D(name, title, nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
	//tr->Project(name,variable[Branch_count] ,"weight" && cBase && cJets && cOther);
	tr->Project(name,variable[Branch_count] ,"lep_category==1 && Z_pt > 60 && met_pt > 40 && Z_mass > 81 && Z_mass < 101 && ngood_jets < 2 && ngood_bjets ==0" && cOther);
	//float nEv = hPt->Integral(0,nBins[Branch_count]);
	
	for (int i = 0; i < nData; ++i) if (Data[i][0]==title) ind = i;
	float nEv2 = hPt->Integral(0,nBins[Branch_count]);
	cout << title << "    GEN:   NONE"  << "     RECO:   " << nEv2 <<endl;
	
	return hPt;
};
