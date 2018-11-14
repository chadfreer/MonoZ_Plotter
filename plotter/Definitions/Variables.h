//**********Initial Variables**********
//Information on process and associated colors
static TString Data [34][6] =
{	/*Dataset*/				/*cross section*/		/*nGen*/		/*kCol*/		/*Process*/		/*To Use*/
	//MC 2016
	{"ZZTo2L2Nu",				"0.564",			"8842475",		"kOrange-2",		"ZZ",			"YES"},/*1*/      
	{"TTTo2L2Nu",				"87.3",				"77853420",		"kGray+1",		"TT",			"YES"},/*2*/
	{"WWTo2L2Nu",				"12.178",			"1999000",		"kTeal+2",		"WW",			"YES"},/*3*/
	{"DYJetsToLL",				"4958. * (1921.8*3/4958.)",	"49144274",		"kPink+1",		"DY",			"NO"},/*4*/
	{"WZTo3LNu",				"4.42965*1.109",		"1993200",		"kAzure-4",		"WZ",			"YES"},/*5*/
	{"ZZJJ_ZZTo2L2Nu",			"0.002618",			"100000",		"kBlue",		"VBS",			"NO"},/*6*/
	{"DYJetsToLL50To100",			"354.6*(1921.8*3/5938)",	"20907519",		"kPink+1",		"DY",			"YES"},/*7*/
	{"DYJetsToLL100To250",			"83.05*(1921.8*3/5938)",	"2040596",		"kPink+1",		"DY",			"YES"},/*8*/
	{"DYJetsToLL250To400",			"3.043*(1921.8*3/5938)",	"423976",		"kPink+1",		"DY",			"YES"},/*9*/
	{"DYJetsToLL400To650",			".3921*(1921.8*3/5938)",	"432056",		"kPink+1",		"DY",			"YES"},/*10*/
	{"DYJetsToLL650Toinf",			".03823*(1921.8*3/5938)",	"430691",		"kPink+1",		"DY",			"YES"},/*11*/
	{"LLDMMx2Heavy",			"0.027605911000284",		"47032",		"kRed",			"LLDM",			"NO"},/*12*/
	{"LLDMMx2Light",			"0.028245862461968",		"42885",		"kRed",			"LLDM",			"NO"},/*13*/
	//MC 2017
	{"DYJetsToLL_HT-70to100_2017",		"175.3*1.23",			"9344037",		"kPink+1",		"DY",			"YES"},/*14*/
	{"DYJetsToLL_HT-100to200_2017",		"161.1*1.23",			"11197488",		"kPink+1",		"DY",			"YES"},/*15*/
	{"DYJetsToLL_HT-200to400_2017",		"48.66*1.23",			"10181069",		"kkPink+1",		"DY",			"YES"},/*16*/
	{"DYJetsToLL_HT-400to600_2017",		"6.968*1.23",			"9365135",		"kPink+1",		"DY",			"YES"},/*17*/
	{"DYJetsToLL_HT-600to800_2017",		"1.743*1.23",			"8225050",		"kPink+1",		"DY",			"YES"},/*18*/
	{"DYJetsToLL_HT-800to1200_2017",	"0.8052*1.23",			"3089861",		"kPink+1",		"DY",			"YES"},/*19*/
	{"DYJetsToLL_HT-1200to2500_2017",	"0.1933*1.23",			"625517",		"kPink+1",		"DY",			"YES"},/*20*/
	{"DYJetsToLL_HT-2500toInf_2017",	"0.003468*1.23",		"404986",		"kPink+1",		"DY",			"YES"},/*21*/
        {"WWZ_2017", 			        "0.16510",                	"244000",               "kPink-5",              "VVV",                  "YES"},/*22*/
        {"WZZ_2017",       			"0.05565",                	"250000",               "kPink-5",              "VVV",                  "YES"},/*23*/
        {"ZZZ_2017",       			"0.01398",               	"250000",               "kPink-5",              "VVV",                  "YES"},/*24*/
	{"TTTo2L2Nu_2017",			"88.29",			"8705576",		"kGray+1",		"TT",			"YES"},/*25*/
	{"WWTo2L2Nu_2017",			"11.08",			"1915563",		"kTeal+2",		"WW",			"YES"},/*26*/
	{"ZZTo2L2Nu_2017",			"0.5644",			"8744768",		"kOrange-2",		"ZZ",			"YES"},/*27*/
	{"WZTo3LNu_2017",			"5.052",			"10881896",		"kAzure-4",		"WZ",			"YES"},/*28*/
        {"DYJetsToLL_2017",                     "6529",                         "27413121",             "kpink+1",              "DY",                   "YES"},/*29*/
	//Data 201
	{"DoubleEG_2017",			"1",				"1",			"kBlack",		"Data",			"YES"},/*30*/
	{"DoubleMuon_2017",			"1",				"1",			"kBlack",		"Data",			"YES"},/*31*/
	{"MuonEG_2017",				"1",				"1",			"kBlack",		"Data",			"YES"},/*32*/
	{"SingleElectron_2017",			"1",				"1",			"kBlack",		"Data",			"YES"},/*33*/
	{"SingleMuon_2017",			"1",				"1",			"kBlack",		"Data",			"YES"}/*34*/
};
static Int_t nData = 34;
//**************************************

//static TString Variables [][] =
//{       /*Variable*/                            /*XAxis*/						/*xlow*/                        /*xhi*/                 /*nBins*/               /*Branch_Count */
//        {"preZmass",                            "M_{Z} [GeV]",                                        "0",                            "200",                  "200"},                 /*1*/
//        {"prepfMet",                            "P_{T}^{miss} [GeV]",                                 "0",                            "600",                  "60"},                  /*2*/
//        {"Zpt_Reco",                            "Z P_{t} [GeV]",                                      "0",                            "1000",                 "100"},                 /*3*/
//        {"DeltaPhiZMet",                        "#Delta#phi_{Z,P_{T}^{miss}}",                        "0",                            "3.2",                  "32"},                  /*4*/
//        {"Balance",                             "Balance",                                            "0",                            "10",                   "50"},                  /*5*/
//        {"DeltaPhill",                          "#Delta#phi_{ll}",                                    "0",                            "3.2",                  "32"},                  /*6*/
//        {"DeltaEtall",                          "#Delta#eta_{ll}",                                    "0",                            "2.5",                  "50"},                  /*7*/
//        {"LeadingPtll",                         "Leading Lepton P_{T} [GeV]",                         "0",                            "1000",                 "100"},                 /*8*/
//        {"TrailingPtll",                        "Trailing Lepton P_{T} [GeV]",                        "0",                            "500",                  "50"},                  /*9*/
//        {"LeadingEtall",                        "Leading Lepton #eta",                                "-2.5",                         "2.5",                  "50"},                  /*10*/
//        {"TrailingEtall",                       "Trailing Lepton #eta",                               "-2.5",                         "2.5",                  "50"},                  /*11*/
//        {"Etall",                               "#eta_{ll}",                                          "-4.5",                         "4.5",                  "50"},                  /*12*/
//        {"Rapidityll",                          "Rapidity_{ll}",                                      "-2.5",                         "2.5",                  "50"},                  /*13*/
//        {"ngoodjets",                           "# of Jets",                                          "0",                            "14",                   "14"},                  /*14*/
//        {"LeadingJetPt",                        "Leading Jet P_{t} [GeV]",                            "0",                            "2000",                 "200"},                 /*15*/
//        {"subLeadingJetPt",                     "sub-Leading Jet P_{t} [GeV]",                        "0",                            "1000",                 "100"},                 /*16*/
//        {"LeadingJetEta",                       "Leading Jet #eta",                                   "-4.5",                         "4.5",                  "90"},                  /*17*/
//        {"subLeadingJetEta",            	"sub-Leading Jet #eta",                                 "-4.5",                         "4.5",                  "90"},                  /*18*/
//        {"DijetMass",                           "M_{jj} [GeV]",                                       "0",                            "5000",                 "100"},                 /*19*/
//        {"DeltaPhijj",                          "#Delta#phi_{jj}",                                    "0",                            "3.2",                  "32"},                  /*20*/
//        {"DeltaEtajj",                          "#Delta#eta_{jj}",                                    "0",                            "9",                    "90"},                  /*21*/
//        {"nBjets",                              "# of B Jets",                                        "0",                            "10",                   "10"},                  /*22*/
//        {"xJet",                                "xJet",                                               "0",                            "1",                    "100"},                 /*23*/
//        {"xZ",                                  "xZ",                                                 "0",                            "1",                    "100"},                 /*24*/
//        {"Zeppenfeld",                          "Zeppenfeld",                                         "-6",                           "6",                    "60"},                  /*25*/
//        {"ZeppenfeldLeadLep",           	"Zeppenfeld_{l}^{1}",                                   "-6",                           "6",                    "60"},                  /*26*/
//        {"ZeppenfeldTrailLep",          	"Zeppenfeld_{l}^{2}",                                   "-6",                           "6",                    "60"},                  /*27*/
//        {"xMet",                                "xMet",                                               "0",                            "1",                    "100"},                 /*28*/
//        {"HT",                                  "H_{T} [GeV]",                                        "0",                            "3000",                 "50"},                  /*29*/
//        {"HTF",                                 "P_{T}^{j1}+P_{T}^{j2}/H_{T}",                        "0",                            "1",                    "50"},                  /*30*/
//        {"JetPtRatio",                          "P_{T}^{j2}/P_{T}^{j1}",                              "0",                            "1",                    "50"},                  /*31*/
//        {"JetEtaMultiplicity",          	"#eta_{j1}*#eta_{j2}",                                  "-7",                           "7",                    "140"},                 /*32*/
//        {"DPTOZ",                               "P_{T}^{j1}-P_{T}^{j2}/P_{T}^{Z}",                    "0",                            "10",                   "100"},                 /*33*/
//        {"CJVPt",                               "Central Jet P_{T}",                                  "0",                            "500",                  "100"},                 /*34*/
//        {"CJVPtSum",                            "Central Jet P_{T} Sum",                              "0",                            "1000",                 "200"},                 /*35*/
//        {"Rpt",                                 "P_{T}^{l1}*P_{T}^{l2}/P_{T}^{j1}*P_{T}^{j2}",        "0",                            "10",                   "25"},                  /*36*/
//        {"genjets",                             "# of genjets",                                       "0",                            "10",                   "10"},                  /*37*/
//        {"DeltaPhiLeadingJetMet",       	"#Delta#phi_{J^{1},P_{T}^{miss}}",                      "0",                            "3.2",                  "32"},                  /*38*/
//        {"DeltaPhiClosestJetMet",       	"#Delta#phi_{J^{closest},P_{T}^{miss}}",                "0",                            "3.2",                  "32"},                  /*39*/
//        {"DeltaPhiFarthestJetMet",      	"#Delta#phi_{J^{farthest},P_{T}^{miss}}",               "0",                            "3.2",                  "32"},                  /*40*/
//        {"EtaThirdJet",                         "#eta_{j^{3}}",                                       "-5",                           "5",                    "100"}                  /*41*/
//        /*Finish Declaring. Add more if necessary*/
//}

//**********Branch Variables**********
static TString variable[] = {"Z_mass", "met_pt", "Z_pt", "delta_phi_ZMet", "sca_balance", "delta_phi_ll", "delta_eta_ll", "LeadingPtll", "TrailingPtll", "LeadingEtall", "TrailingEtall", "Etall", "Rapidityll", "ngood_jets", "LeadingJetPt", "subLeadingJetPt", "LeadingJetEta", "subLeadingJetEta", "DijetMass", "DeltaPhijj", "DeltaEtajj", "ngood_bjets", "xJet", "xZ","Zeppenfeld", "ZeppenfeldLeadLep","ZeppenfeldTrailLep", "xMet", "HT", "HTF", "JetPtRatio", "JetEtaMultiplicity", "DPTOZ", "CJVPt", "CJVPtSum", "Rpt", "genjets", "DeltaPhiLeadingJetMet", "delta_phi_j_met", "Pileup_nPU", "Z_mt"};

//static char *variable[] = {"preZmass", "prepfMet", "Zpt_Reco", "DeltaPhiZMet", "Balance", "DeltaPhill", "DeltaEtall", "LeadingPtll", "TrailingPtll", "LeadingEtall", "TrailingEtall", "Etall", "Rapidityll", "ngoodjets", "LeadingJetPt", "subLeadingJetPt", "LeadingJetEta", "subLeadingJetEta", "DijetMass", "DeltaPhijj", "DeltaEtajj", "nBjets", "xJet", "xZ","Zeppenfeld", "ZeppenfeldLeadLep","ZeppenfeldTrailLep", "xMet", "HT", "HTF", "JetPtRatio", "JetEtaMultiplicity", "DPTOZ", "CJVPt", "CJVPtSum"};

static TString axis[] = {"M_{Z} [GeV]", "P_{T}^{miss} [GeV]", "Z P_{t} [GeV]", "#Delta#phi_{Z,P_{T}^{miss}}", "P_{T}^{miss}/Z P_{T}", "#Delta#phi_{ll}", "#Delta#eta_{ll}", "Leading Lepton P_{T} [GeV]", "Trailing Lepton P_{T} [GeV]", "Leading Lepton #eta", "Trailing Lepton #eta", "#eta_{ll}", "Rapidity_{ll}", "# of Jets", "Leading Jet P_{t} [GeV]", "sub-Leading Jet P_{t} [GeV]", "Leading Jet #eta", "sub-Leading Jet #eta", "M_{jj} [GeV]", "#Delta#phi_{jj}", "#Delta#eta_{jj}", "# of B Jets", "xJet", "xZ", "Zeppenfeld", "Zeppenfeld_{l}^{1}", "Zeppenfeld_{l}^{2}","xMet", "H_{T} [GeV]", "P_{T}^{j1}+P_{T}^{j2}/H_{T}", "P_{T}^{j2}/P_{T}^{j1}", "#eta_{j1}*#eta_{j2}", "P_{T}^{j1}-P_{T}^{j2}/P_{T}^{Z}", "Central Jet P_{T}", "Central Jet P_{T} Sum", "P_{T}^{l1}*P_{T}^{l2}/P_{T}^{j1}*P_{T}^{j2}", "# of genjets", "#Delta#phi_{J^{1},P_{T}^{miss}}", "#Delta#phi_{Jet,P_{T}^{miss}}", "nVTX", " Z m_{T} [GeV]" };

static Double_t xlow[] = { 60 /*ZMass*/, 0/*prepfMet*/, 60/*Zpt_Reco*/, 0/*DeltaPhiZMet*/, 0/*Balance*/, 0/*DeltaPhill*/, 0/*DeltaEtall*/, 0/*LeadingPtll*/, 0/*TrailingPtll*/, -2.5/*LeadingEtall*/, -2.5/*TrailingEtall*/, -4.5/*Etall*/, -2.5/*Rapidityll*/, 0/*ngoodjets*/, 0/*LeadingJetPt*/, 0/*subLeadingJetPt*/, -4.5/*LeadingJetEta*/, -4.5/*subLeadingJetEta*/, 0/*DijetMass*/, 0/*DeltaPhijj*/, 0/*DeltaEtajjll*/, 0/*nBjets*/, 0/*xJet*/, 0/*xZ*/, -6 /*Zeppenfeld*/, -6 /*ZeppenfeldLep1*/, -6 /*ZeppenfeldLep2*/, 0/*xMet*/, 0/*HT*/, 0/*HTF*/, 0/*JetPtRatio*/, -7/*JetEtaMultiplicity*/, 0/*DPTOZ*/, 0/*CJVPt*/, 50/*CJVPtSum*/, 0/*Rpt*/, 0/*genjets*/, 0/*DeltaPhiLeadingJetMet*/, 0/*DeltaPhiClosestJetMet*/, 0/*DeltaPhiFarthestJetMet*/, 50/*Z_mt*/};

static Double_t xhi[] = { 110 /*ZMass*/, 200/*prepfMet*/, 260/*Zpt_Reco*/, 3.2/*DeltaPhiZMet*/, 5/*Balance*/, 3.2/*DeltaPhill*/, 2.5/*DeltaEtall*/, 1000/*LeadingPtll*/, 500/*TrailingPtll*/, 2.5/*LeadingEtall*/, 2.5/*TrailingEtall*/, 4.5/*Etall*/, 2.5/*Rapidityll*/, 14/*ngoodjets*/, 2000/*LeadingJetPt*/, 1000/*subLeadingJetPt*/, 4.5/*LeadingJetEta*/, 4.5/*subLeadingJetEta*/, 5000/*DijetMass*/, 3.2/*DeltaPhijj*/, 9/*DeltaEtajjll*/, 10/*nBjets*/, 1/*xJet*/, 1/*xZ*/, 6 /*Zeppenfeld*/, 6 /*ZeppenfeldLep1*/, 6 /*ZeppenfeldLep2*/, 1/*xMet*/, 3000/*HT*/, 1/*HTF*/, 1/*JetPtRatio*/, 7/*JetEtaMultiplicity*/, 10/*DPTOZ*/, 550/*CJVPt*/, 1050/*CJVPtSum*/, 10/*Rpt*/, 10/*genjets*/, 3.2/*DeltaPhiLeadingJetMet*/, 3.2/*DeltaPhiClosestJetMet*/, 100/*DeltaPhiFarthestJetMet*/, 150/*Z_mt*/};

static Int_t nBins[] = { 25 /*ZMass*/, 40/*prepfMet*/, 20/*Zpt_Reco*/, 16/*DeltaPhiZMet*/, 25/*Balance*/, 32/*DeltaPhill*/, 50/*DeltaEtall*/, 100/*LeadingPtll*/, 50/*TrailingPtll*/, 50/*LeadingEtall*/, 50/*TrailingEtall*/, 90/*Etall*/, 50/*Rapidityll*/, 14/*ngoodjets*/, 200/*LeadingJetPt*/, 100/*subLeadingJetPt*/, 90/*LeadingJetEta*/, 90/*subLeadingJetEta*/, 100/*DijetMass*/, 32/*DeltaPhijj*/, 90/*DeltaEtajjll*/, 10/*nBjets*/, 100/*xJet*/, 100/*xZ*/, 60 /*Zeppenfeld*/, 60 /*ZeppenfeldLep1*/, 60 /*ZeppenfeldLep2*/, 100/*xMet*/, 50/*HT*/, 50/*HTF*/, 50/*JetPtRatio*/, 140/*JetEtaMultiplicity*/, 100/*DPTOZ*/, 100/*CJVPt*/, 200/*CJVPtSum*/, 25/*Rpt*/, 10/*genjets*/, 16/*DeltaPhiLeadingJetMet*/, 16/*DeltaPhiClosestJetMet*/, 100/*DeltaPhiFarthestJetMet*/, 25/*Z_mt*/};





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
