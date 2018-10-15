
//**********Initial Variables**********
//Information on process and associated colors
static TString Data [][] =
{	/*Dataset*/					/*cross section*/			/*nGen*/			/*kCol*/			/*Process*/		/*To Use*/
	{"ZZTo2L2Nu",				"0.564",					"8842475",			"kOrange-2",		"ZZ",			"YES"},
	{"TTTo2L2Nu",				"87.3",						"77853420",			"kGray+1",			"TT",			"YES"},
	{"WWTo2L2Nu",				"12.178",					"1999000",			"kTeal+2",			"WW",			"YES"},
	{"DYJetsToLL",				"4958. * (1921.8*3/4958.)",	"49144274",			"kPink+1",			"DY",			"NO"},
	{"WZTo3LNu",				"4.42965*1.109",			"1993200",			"kAzure-4",			"WZ",			"YES"},
	{"ZZJJ_ZZTo2L2Nu",			"0.002618",					"100000",			"kBlue",			"VBS",			"NO"},
	{"DYJetsToLL50To100",		"354.6*(1921.8*3/5938)",	"20907519",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL100To250",		"83.05*(1921.8*3/5938)",	"2040596",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL250To400",		"3.043*(1921.8*3/5938)",	"423976",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL400To650",		".3921*(1921.8*3/5938)",	"432056",			"kPink+1",			"DY",			"YES"},
	{"DYJetsToLL650Toinf",		".03823*(1921.8*3/5938)",	"430691",			"kPink+1",			"DY",			"YES"},
	{"LLDMMx2Heavy",			"0.027605911000284",		"47032",			"kRed",				"LLDM",			"NO"},
	{"LLDMMx2Light",			"0.028245862461968",		"42885",			"kRed",				"LLDM",			"NO"}
}static Int_t nData = 13;



//**********Branch Variables**********
static TString Variables [][] =
{	/*Variable*/				/*XAxis*/											/*xlow*/			/*xhi*/			/*nBins*/		/*Branch_Count */
	{"preZmass",				"M_{Z} [GeV]",										"0",				"200",			"200"},			/*1*/
	{"prepfMet",				"P_{T}^{miss} [GeV]",								"0",				"600",			"60"},			/*2*/
	{"Zpt_Reco",				"Z P_{t} [GeV]",									"0",				"1000",			"100"},			/*3*/
	{"DeltaPhiZMet",			"#Delta#phi_{Z,P_{T}^{miss}}",						"0",				"3.2",			"32"},			/*4*/
	{"Balance",					"Balance",											"0",				"10",			"50"},			/*5*/
	{"DeltaPhill",				"#Delta#phi_{ll}",									"0",				"3.2",			"32"},			/*6*/
	{"DeltaEtall",				"#Delta#eta_{ll}",									"0",				"2.5",			"50"},			/*7*/
	{"LeadingPtll",				"Leading Lepton P_{T} [GeV]",						"0",				"1000",			"100"},			/*8*/
	{"TrailingPtll",			"Trailing Lepton P_{T} [GeV]",						"0",				"500",			"50"},			/*9*/
	{"LeadingEtall",			"Leading Lepton #eta",								"-2.5",				"2.5",			"50"},			/*10*/
	{"TrailingEtall",			"Trailing Lepton #eta",								"-2.5",				"2.5",			"50"},			/*11*/
	{"Etall",					"#eta_{ll}",										"-4.5",				"4.5",			"50"},			/*12*/
	{"Rapidityll",				"Rapidity_{ll}",									"-2.5",				"2.5",			"50"},			/*13*/
	{"ngoodjets",				"# of Jets",										"0",				"14",			"14"},			/*14*/
	{"LeadingJetPt",			"Leading Jet P_{t} [GeV]",							"0",				"2000",			"200"},			/*15*/
	{"subLeadingJetPt",			"sub-Leading Jet P_{t} [GeV]",						"0",				"1000",			"100"},			/*16*/
	{"LeadingJetEta",			"Leading Jet #eta",									"-4.5",				"4.5",			"90"},			/*17*/
	{"subLeadingJetEta",		"sub-Leading Jet #eta",								"-4.5",				"4.5",			"90"},			/*18*/
	{"DijetMass",				"M_{jj} [GeV]",										"0",				"5000",			"100"},			/*19*/
	{"DeltaPhijj",				"#Delta#phi_{jj}",									"0",				"3.2",			"32"},			/*20*/
	{"DeltaEtajj",				"#Delta#eta_{jj}",									"0",				"9",			"90"},			/*21*/
	{"nBjets",					"# of B Jets",										"0",				"10",			"10"},			/*22*/
	{"xJet",					"xJet",												"0",				"1",			"100"},			/*23*/
	{"xZ",						"xZ",												"0",				"1",			"100"},			/*24*/
	{"Zeppenfeld",				"Zeppenfeld",										"-6",				"6",			"60"},			/*25*/
	{"ZeppenfeldLeadLep",		"Zeppenfeld_{l}^{1}",								"-6",				"6",			"60"},			/*26*/
	{"ZeppenfeldTrailLep",		"Zeppenfeld_{l}^{2}",								"-6",				"6",			"60"},			/*27*/
	{"xMet",					"xMet",												"0",				"1",			"100"},			/*28*/
	{"HT",						"H_{T} [GeV]",										"0",				"3000",			"50"},			/*29*/
	{"HTF",						"P_{T}^{j1}+P_{T}^{j2}/H_{T}",						"0",				"1",			"50"},			/*30*/
	{"JetPtRatio",				"P_{T}^{j2}/P_{T}^{j1}",							"0",				"1",			"50"},			/*31*/
	{"JetEtaMultiplicity",		"#eta_{j1}*#eta_{j2}",								"-7",				"7",			"140"},			/*32*/
	{"DPTOZ",					"P_{T}^{j1}-P_{T}^{j2}/P_{T}^{Z}",					"0",				"10",			"100"},			/*33*/
	{"CJVPt",					"Central Jet P_{T}",								"0",				"500",			"100"},			/*34*/
	{"CJVPtSum",				"Central Jet P_{T} Sum",							"0",				"1000",			"200"},			/*35*/
	{"Rpt",						"P_{T}^{l1}*P_{T}^{l2}/P_{T}^{j1}*P_{T}^{j2}",		"0",				"10",			"25"},			/*36*/
	{"genjets",					"# of genjets",										"0",				"10",			"10"},			/*37*/
	{"DeltaPhiLeadingJetMet",	"#Delta#phi_{J^{1},P_{T}^{miss}}",					"0",				"3.2",			"32"},			/*38*/
	{"DeltaPhiClosestJetMet",	"#Delta#phi_{J^{closest},P_{T}^{miss}}",			"0",				"3.2",			"32"},			/*39*/
	{"DeltaPhiFarthestJetMet",	"#Delta#phi_{J^{farthest},P_{T}^{miss}}",			"0",				"3.2",			"32"},			/*40*/
	{"EtaThirdJet",				"#eta_{j^{3}}",										"-5",				"5",			"100"}			/*41*/
	/*Finish Declaring. Add more if necessary*/
}
