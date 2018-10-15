//**********Initial Variables**********
//Information on process and associated colors
static TString Data [30][6] =
{	/*Dataset*/								/*cross section*/			/*nGen*/			/*kCol*/			/*Process*/		/*To Use*/
	{"ZZTo2L2Nu",							"0.564",					"8842475",			"kOrange-2",		"ZZ",			"YES"},
	{"TTTo2L2Nu",							"87.3",						"77853420",			"kGray+1",			"TT",			"YES"},
	{"WWTo2L2Nu",							"12.178",					"1999000",			"kTeal+2",			"WW",			"YES"},
	{"DYJetsToLL",							"4958. * (1921.8*3/4958.)",	"49144274",			"kPink+1",			"DY",			"NO"},
	{"WZTo3LNu",							"4.42965*1.109",			"1993200",			"kAzure-4",			"WZ",			"YES"},
	{"ZZJJ_ZZTo2L2Nu",						"0.002618",					"100000",			"kBlue",			"VBS",			"NO"},
	{"DYJetsToLL50To100",					"354.6*(1921.8*3/5938)",	"20907519",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL100To250",					"83.05*(1921.8*3/5938)",	"2040596",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL250To400",					"3.043*(1921.8*3/5938)",	"423976",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL400To650",					".3921*(1921.8*3/5938)",	"432056",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL650Toinf",					".03823*(1921.8*3/5938)",	"430691",			"kPink+1",			"DY",			"YES"},
	{"LLDMMx2Heavy",						"0.027605911000284",		"47032",			"kRed",				"LLDM",			"NO"},
	{"LLDMMx2Light",						"0.028245862461968",		"42885",			"kRed",				"LLDM",			"NO"},
	
	{"DYJetsToLL_HT-70to100_2017",			"175.3*1.23",				"6462960",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-100to200_2017",			"147.4*1.23",				"9855000",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-200to400_2017",			"40.99*1.23",				"10179000",			"kkPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-400to600_2017",			"5.678*1.23",				"3318000",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-600to800_2017",			"1.367*1.23",				"8225000",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-800to1200_2017",		"0.6304*1.23",				"3090000",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-1200to2500_2017",		"0.1514*1.23",				"625500",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL_HT-2500toInf_2017",		"0.003565*1.23",			"405000",			"kPink+1",			"DY",			"YES"},
	{"TTTo2L2Nu_2017",						"87.31",					"8306000",			"kGray+1",			"TT",			"YES"},
	{"WWTo2L2Nu_2017",						"12.178",					"16002",			"kTeal+2",			"WW",			"YES"},
	{"ZZTo2L2Nu_2017",						"0.564",					"7412900",			"kOrange-2",		"ZZ",			"YES"},
	{"WZTo3LNu_2017",						"4.42965",					"4939000",			"kAzure-4",			"WZ",			"YES"},
	{"DoubleEG_2017",						"1",						"1",				"kBlack",			"Data",			"YES"},
	{"DoubleMuon_2017",						"1",						"1",				"kBlack",			"Data",			"YES"},
	{"MuonEG_2017",							"1",						"1",				"kBlack",			"Data",			"YES"},
	{"SingleElectron_2017",					"1",						"1",				"kBlack",			"Data",			"YES"},
	{"SingleMuon_2017",						"1",						"1",				"kBlack",			"Data",			"YES"}
};
static Int_t nData = 30;
//**************************************


//**********Branch Variables**********
static TString variable[] = {"Z_mass", "met_pt", "Z_pt", "DeltaPhiZMet", "Balance", "DeltaPhill", "DeltaEtall", "LeadingPtll", "TrailingPtll", "LeadingEtall", "TrailingEtall", "Etall", "Rapidityll", "ngoodjets", "LeadingJetPt", "subLeadingJetPt", "LeadingJetEta", "subLeadingJetEta", "DijetMass", "DeltaPhijj", "DeltaEtajj", "nBjets", "xJet", "xZ","Zeppenfeld", "ZeppenfeldLeadLep","ZeppenfeldTrailLep", "xMet", "HT", "HTF", "JetPtRatio", "JetEtaMultiplicity", "DPTOZ", "CJVPt", "CJVPtSum", "Rpt", "genjets", "DeltaPhiLeadingJetMet", "DeltaPhiClosestJetMet", "DeltaPhiFarthestJetMet", "Z_mt"};

//static char *variable[] = {"preZmass", "prepfMet", "Zpt_Reco", "DeltaPhiZMet", "Balance", "DeltaPhill", "DeltaEtall", "LeadingPtll", "TrailingPtll", "LeadingEtall", "TrailingEtall", "Etall", "Rapidityll", "ngoodjets", "LeadingJetPt", "subLeadingJetPt", "LeadingJetEta", "subLeadingJetEta", "DijetMass", "DeltaPhijj", "DeltaEtajj", "nBjets", "xJet", "xZ","Zeppenfeld", "ZeppenfeldLeadLep","ZeppenfeldTrailLep", "xMet", "HT", "HTF", "JetPtRatio", "JetEtaMultiplicity", "DPTOZ", "CJVPt", "CJVPtSum"};

static TString axis[] = {"M_{Z} [GeV]", "P_{T}^{miss} [GeV]", "Z P_{t} [GeV]", "#Delta#phi_{Z,P_{T}^{miss}}", "Balance", "#Delta#phi_{ll}", "#Delta#eta_{ll}", "Leading Lepton P_{T} [GeV]", "Trailing Lepton P_{T} [GeV]", "Leading Lepton #eta", "Trailing Lepton #eta", "#eta_{ll}", "Rapidity_{ll}", "# of Jets", "Leading Jet P_{t} [GeV]", "sub-Leading Jet P_{t} [GeV]", "Leading Jet #eta", "sub-Leading Jet #eta", "M_{jj} [GeV]", "#Delta#phi_{jj}", "#Delta#eta_{jj}", "# of B Jets", "xJet", "xZ", "Zeppenfeld", "Zeppenfeld_{l}^{1}", "Zeppenfeld_{l}^{2}","xMet", "H_{T} [GeV]", "P_{T}^{j1}+P_{T}^{j2}/H_{T}", "P_{T}^{j2}/P_{T}^{j1}", "#eta_{j1}*#eta_{j2}", "P_{T}^{j1}-P_{T}^{j2}/P_{T}^{Z}", "Central Jet P_{T}", "Central Jet P_{T} Sum", "P_{T}^{l1}*P_{T}^{l2}/P_{T}^{j1}*P_{T}^{j2}", "# of genjets", "#Delta#phi_{J^{1},P_{T}^{miss}}", "#Delta#phi_{J^{closest},P_{T}^{miss}}", "#Delta#phi_{J^{farthest},P_{T}^{miss}}", " Z m_{T} [GeV]" };

static Double_t xlow[] = { 60 /*ZMass*/, 40/*prepfMet*/, 60/*Zpt_Reco*/, 0/*DeltaPhiZMet*/, 0/*Balance*/, 0/*DeltaPhill*/, 0/*DeltaEtall*/, 0/*LeadingPtll*/, 0/*TrailingPtll*/, -2.5/*LeadingEtall*/, -2.5/*TrailingEtall*/, -4.5/*Etall*/, -2.5/*Rapidityll*/, 0/*ngoodjets*/, 0/*LeadingJetPt*/, 0/*subLeadingJetPt*/, -4.5/*LeadingJetEta*/, -4.5/*subLeadingJetEta*/, 0/*DijetMass*/, 0/*DeltaPhijj*/, 0/*DeltaEtajjll*/, 0/*nBjets*/, 0/*xJet*/, 0/*xZ*/, -6 /*Zeppenfeld*/, -6 /*ZeppenfeldLep1*/, -6 /*ZeppenfeldLep2*/, 0/*xMet*/, 0/*HT*/, 0/*HTF*/, 0/*JetPtRatio*/, -7/*JetEtaMultiplicity*/, 0/*DPTOZ*/, 0/*CJVPt*/, 50/*CJVPtSum*/, 0/*Rpt*/, 0/*genjets*/, 0/*DeltaPhiLeadingJetMet*/, 0/*DeltaPhiClosestJetMet*/, 0/*DeltaPhiFarthestJetMet*/, 50/*Z_mt*/};

static Double_t xhi[] = { 110 /*ZMass*/, 340/*prepfMet*/, 260/*Zpt_Reco*/, 3.2/*DeltaPhiZMet*/, 10/*Balance*/, 3.2/*DeltaPhill*/, 2.5/*DeltaEtall*/, 1000/*LeadingPtll*/, 500/*TrailingPtll*/, 2.5/*LeadingEtall*/, 2.5/*TrailingEtall*/, 4.5/*Etall*/, 2.5/*Rapidityll*/, 14/*ngoodjets*/, 2000/*LeadingJetPt*/, 1000/*subLeadingJetPt*/, 4.5/*LeadingJetEta*/, 4.5/*subLeadingJetEta*/, 5000/*DijetMass*/, 3.2/*DeltaPhijj*/, 9/*DeltaEtajjll*/, 10/*nBjets*/, 1/*xJet*/, 1/*xZ*/, 6 /*Zeppenfeld*/, 6 /*ZeppenfeldLep1*/, 6 /*ZeppenfeldLep2*/, 1/*xMet*/, 3000/*HT*/, 1/*HTF*/, 1/*JetPtRatio*/, 7/*JetEtaMultiplicity*/, 10/*DPTOZ*/, 550/*CJVPt*/, 1050/*CJVPtSum*/, 10/*Rpt*/, 10/*genjets*/, 3.2/*DeltaPhiLeadingJetMet*/, 3.2/*DeltaPhiClosestJetMet*/, 3.2/*DeltaPhiFarthestJetMet*/, 150/*Z_mt*/};

static Int_t nBins[] = { 25 /*ZMass*/, 15/*prepfMet*/, 20/*Zpt_Reco*/, 32/*DeltaPhiZMet*/, 50/*Balance*/, 32/*DeltaPhill*/, 50/*DeltaEtall*/, 100/*LeadingPtll*/, 50/*TrailingPtll*/, 50/*LeadingEtall*/, 50/*TrailingEtall*/, 90/*Etall*/, 50/*Rapidityll*/, 14/*ngoodjets*/, 200/*LeadingJetPt*/, 100/*subLeadingJetPt*/, 90/*LeadingJetEta*/, 90/*subLeadingJetEta*/, 100/*DijetMass*/, 32/*DeltaPhijj*/, 90/*DeltaEtajjll*/, 10/*nBjets*/, 100/*xJet*/, 100/*xZ*/, 60 /*Zeppenfeld*/, 60 /*ZeppenfeldLep1*/, 60 /*ZeppenfeldLep2*/, 100/*xMet*/, 50/*HT*/, 50/*HTF*/, 50/*JetPtRatio*/, 140/*JetEtaMultiplicity*/, 100/*DPTOZ*/, 100/*CJVPt*/, 200/*CJVPtSum*/, 25/*Rpt*/, 10/*genjets*/, 32/*DeltaPhiLeadingJetMet*/, 32/*DeltaPhiClosestJetMet*/, 32/*DeltaPhiFarthestJetMet*/, 25/*Z_mt*/};





////**********Branch Variables**********
//static TString variable[] = {"preZmass", "prepfMet", "Zpt_Reco", "DeltaPhiZMet", "Balance", "DeltaPhill", "DeltaEtall", "LeadingPtll", "TrailingPtll", "LeadingEtall", "TrailingEtall", "Etall", "Rapidityll", "ngoodjets", "LeadingJetPt", "subLeadingJetPt", "LeadingJetEta", "subLeadingJetEta", "DijetMass", "DeltaPhijj", "DeltaEtajj", "nBjets", "xJet", "xZ","Zeppenfeld", "ZeppenfeldLeadLep","ZeppenfeldTrailLep", "xMet", "HT", "HTF", "JetPtRatio", "JetEtaMultiplicity", "DPTOZ", "CJVPt", "CJVPtSum", "Rpt", "genjets", "DeltaPhiLeadingJetMet", "DeltaPhiClosestJetMet", "DeltaPhiFarthestJetMet", "EtaThirdJet"};
//
////static char *variable[] = {"preZmass", "prepfMet", "Zpt_Reco", "DeltaPhiZMet", "Balance", "DeltaPhill", "DeltaEtall", "LeadingPtll", "TrailingPtll", "LeadingEtall", "TrailingEtall", "Etall", "Rapidityll", "ngoodjets", "LeadingJetPt", "subLeadingJetPt", "LeadingJetEta", "subLeadingJetEta", "DijetMass", "DeltaPhijj", "DeltaEtajj", "nBjets", "xJet", "xZ","Zeppenfeld", "ZeppenfeldLeadLep","ZeppenfeldTrailLep", "xMet", "HT", "HTF", "JetPtRatio", "JetEtaMultiplicity", "DPTOZ", "CJVPt", "CJVPtSum"};
//
//static TString axis[] = {"M_{Z} [GeV]", "P_{T}^{miss} [GeV]", "Z P_{t} [GeV]", "#Delta#phi_{Z,P_{T}^{miss}}", "Balance", "#Delta#phi_{ll}", "#Delta#eta_{ll}", "Leading Lepton P_{T} [GeV]", "Trailing Lepton P_{T} [GeV]", "Leading Lepton #eta", "Trailing Lepton #eta", "#eta_{ll}", "Rapidity_{ll}", "# of Jets", "Leading Jet P_{t} [GeV]", "sub-Leading Jet P_{t} [GeV]", "Leading Jet #eta", "sub-Leading Jet #eta", "M_{jj} [GeV]", "#Delta#phi_{jj}", "#Delta#eta_{jj}", "# of B Jets", "xJet", "xZ", "Zeppenfeld", "Zeppenfeld_{l}^{1}", "Zeppenfeld_{l}^{2}","xMet", "H_{T} [GeV]", "P_{T}^{j1}+P_{T}^{j2}/H_{T}", "P_{T}^{j2}/P_{T}^{j1}", "#eta_{j1}*#eta_{j2}", "P_{T}^{j1}-P_{T}^{j2}/P_{T}^{Z}", "Central Jet P_{T}", "Central Jet P_{T} Sum", "P_{T}^{l1}*P_{T}^{l2}/P_{T}^{j1}*P_{T}^{j2}", "# of genjets", "#Delta#phi_{J^{1},P_{T}^{miss}}", "#Delta#phi_{J^{closest},P_{T}^{miss}}", "#Delta#phi_{J^{farthest},P_{T}^{miss}}", "#eta_{j^{3}}" };
//
//static Double_t xlow[] = { 0 /*ZMass*/, 0/*prepfMet*/, 0/*Zpt_Reco*/, 0/*DeltaPhiZMet*/, 0/*Balance*/, 0/*DeltaPhill*/, 0/*DeltaEtall*/, 0/*LeadingPtll*/, 0/*TrailingPtll*/, -2.5/*LeadingEtall*/, -2.5/*TrailingEtall*/, -4.5/*Etall*/, -2.5/*Rapidityll*/, 0/*ngoodjets*/, 0/*LeadingJetPt*/, 0/*subLeadingJetPt*/, -4.5/*LeadingJetEta*/, -4.5/*subLeadingJetEta*/, 0/*DijetMass*/, 0/*DeltaPhijj*/, 0/*DeltaEtajjll*/, 0/*nBjets*/, 0/*xJet*/, 0/*xZ*/, -6 /*Zeppenfeld*/, -6 /*ZeppenfeldLep1*/, -6 /*ZeppenfeldLep2*/, 0/*xMet*/, 0/*HT*/, 0/*HTF*/, 0/*JetPtRatio*/, -7/*JetEtaMultiplicity*/, 0/*DPTOZ*/, 0/*CJVPt*/, 50/*CJVPtSum*/, 0/*Rpt*/, 0/*genjets*/, 0/*DeltaPhiLeadingJetMet*/, 0/*DeltaPhiClosestJetMet*/, 0/*DeltaPhiFarthestJetMet*/, -5/*EtaThirdJet*/};
//
//static Double_t xhi[] = { 200 /*ZMass*/, 600/*prepfMet*/, 1000/*Zpt_Reco*/, 3.2/*DeltaPhiZMet*/, 10/*Balance*/, 3.2/*DeltaPhill*/, 2.5/*DeltaEtall*/, 1000/*LeadingPtll*/, 500/*TrailingPtll*/, 2.5/*LeadingEtall*/, 2.5/*TrailingEtall*/, 4.5/*Etall*/, 2.5/*Rapidityll*/, 14/*ngoodjets*/, 2000/*LeadingJetPt*/, 1000/*subLeadingJetPt*/, 4.5/*LeadingJetEta*/, 4.5/*subLeadingJetEta*/, 5000/*DijetMass*/, 3.2/*DeltaPhijj*/, 9/*DeltaEtajjll*/, 10/*nBjets*/, 1/*xJet*/, 1/*xZ*/, 6 /*Zeppenfeld*/, 6 /*ZeppenfeldLep1*/, 6 /*ZeppenfeldLep2*/, 1/*xMet*/, 3000/*HT*/, 1/*HTF*/, 1/*JetPtRatio*/, 7/*JetEtaMultiplicity*/, 10/*DPTOZ*/, 550/*CJVPt*/, 1050/*CJVPtSum*/, 10/*Rpt*/, 10/*genjets*/, 3.2/*DeltaPhiLeadingJetMet*/, 3.2/*DeltaPhiClosestJetMet*/, 3.2/*DeltaPhiFarthestJetMet*/, 5/*EtaThirdJet*/};
//
//static Int_t nBins[] = { 200 /*ZMass*/, 60/*prepfMet*/, 100/*Zpt_Reco*/, 32/*DeltaPhiZMet*/, 50/*Balance*/, 32/*DeltaPhill*/, 50/*DeltaEtall*/, 100/*LeadingPtll*/, 50/*TrailingPtll*/, 50/*LeadingEtall*/, 50/*TrailingEtall*/, 90/*Etall*/, 50/*Rapidityll*/, 14/*ngoodjets*/, 200/*LeadingJetPt*/, 100/*subLeadingJetPt*/, 90/*LeadingJetEta*/, 90/*subLeadingJetEta*/, 100/*DijetMass*/, 32/*DeltaPhijj*/, 90/*DeltaEtajjll*/, 10/*nBjets*/, 100/*xJet*/, 100/*xZ*/, 60 /*Zeppenfeld*/, 60 /*ZeppenfeldLep1*/, 60 /*ZeppenfeldLep2*/, 100/*xMet*/, 50/*HT*/, 50/*HTF*/, 50/*JetPtRatio*/, 140/*JetEtaMultiplicity*/, 100/*DPTOZ*/, 100/*CJVPt*/, 200/*CJVPtSum*/, 25/*Rpt*/, 10/*genjets*/, 32/*DeltaPhiLeadingJetMet*/, 32/*DeltaPhiClosestJetMet*/, 32/*DeltaPhiFarthestJetMet*/, 90/*EtaThirdJet*/};
