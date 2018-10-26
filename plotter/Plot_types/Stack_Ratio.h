//Code to make colored stack plots

TCanvas * Distribution_Ratio_plots(int Branch_count) {
        gErrorIgnoreLevel = kError; //Ignore everything below error
        gStyle->SetOptStat(0);
        gROOT->SetBatch(kTRUE); //do not display the canvas every time we make one.
     
	//grab the file and the branches
	//TCanvas * cs = new TCanvas("cs", "cs", 600, 500);
	TCanvas *cs = new TCanvas("cc", "cc", 600, 600);
	TPad *p1 = new TPad("p1", "p1", 0, 0.23, 1, 1);//Add for ratio plot
	TPad *p2 = new TPad("p2", "p2", 0, 0.05, 1, 0.23);//Add for ratio plot
	p1->SetBottomMargin(0);//Add for ratio plot
	p2->SetTopMargin(0.05);//Add for ratio plot
	p2->SetBottomMargin(0.20);
	p2->SetBorderMode(0);//Add for ratio plot
	cs->Draw();
	cs->cd();
	p1->Draw();
	p2->Draw();
	p1->cd();
	
	
	//Histograms
	
	//***********************ZZ***********************
	//TH1D *ZZTo2L2Nu = GethPt(f, "ZZTo2L2Nu_13TeV_powheg_pythia8", "ZZTo2L2Nu", "ZZTo2L2Nu",Branch_count, 0); //2016 ZZ
	TH1D *ZZTo2L2Nu_2017 = GethPt(fZZ_2017, "Events", "ZZTo2L2Nu_2017", "ZZTo2L2Nu_2017",Branch_count, 0); //2017 ZZ
	//ZZTo2L2Nu->Add(ZZTo2L2Nu_2017); //Combine
	
	//***********************TT***********************
	//TH1D *TTTo2L2Nu = GethPt(f, "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8", "TTTo2L2Nu", "TTTo2L2Nu",Branch_count, 0); //2016 TT
	TH1D *TTTo2L2Nu_2017 = GethPt(fTT_2017, "Events", "TTTo2L2Nu_2017", "TTTo2L2Nu_2017",Branch_count, 0); //2017 TT
	//TTTo2L2Nu->Add(TTTo2L2Nu_2017); //combine
	
	//***********************WW***********************
	//TH1D *WWTo2L2Nu = GethPt(f, "WWTo2L2Nu_13TeV-powheg", "WWTo2L2Nu", "WWTo2L2Nu",Branch_count, 0); //2016 WW
	TH1D *WWTo2L2Nu_2017 = GethPt(fWW_2017, "Events", "WWTo2L2Nu_2017", "WWTo2L2Nu_2017",Branch_count, 0); //2016 WW
	//WWTo2L2Nu->Add(WWTo2L2Nu_2017); //combine
	
	//***********************WZ***********************
	//TH1D *WZTo3LNu = GethPt(f, "WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8", "WZTo3LNu", "WZTo3LNu",Branch_count, 0); //2016 WZ
	TH1D *WZTo3LNu_2017 = GethPt(fWZ_2017, "Events", "WZTo3LNu_2017", "WZTo3LNu_2017",Branch_count, 0); //2017 WZ
	//WZTo3LNu->Add(WZTo3LNu_2017); //combine

        //***********************VVV***********************
        //TH1D *WWZ_2016 = GethPt(fWWZ_2016, "Events", "WWZ_2016", "WWZ_2016",Branch_count, 0); //2016 WZ
        TH1D *WWZ_2017 = GethPt(fWWZ_2017, "Events", "WWZ_2017", "WWZ_2017",Branch_count, 0); //2017 WZ
        //WWZ_2016->Add(WWZ_2017); //combine
        
        //TH1D *WZZ_2016 = GethPt(fWZZ_2016, "Events", "WZZ_2016", "WZZ_2016",Branch_count, 0); //2016 WZ
        TH1D *WZZ_2017 = GethPt(fWZZ_2017, "Events", "WZZ_2017", "WZZ_2017",Branch_count, 0); //2017 WZ
        //WZZ_2016->Add(WZZ_2017); //combine
        
        //TH1D *ZZZ_2016 = GethPt(fZZZ_2016, "Events", "ZZZ_2016", "ZZZ_2016",Branch_count, 0); //2016 WZ
        TH1D *ZZZ_2017 = GethPt(fZZ_2017, "Events", "ZZZ_2017", "ZZZ_2017",Branch_count, 0); //2017 WZ
        //ZZZ_2016->Add(ZZZ_2017); //combine

        WWZ_2017->Add(WZZ_2017);
	WWZ_2017->Add(ZZZ_2017);
	
	//***********************DY***********************
	//Start with pt-binned 2016 DY
//        TH1D *DYJetsToLL50To100 = GethPt(f, "DYJetsToLL_Pt-50To100_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL50To100","DYJetsToLL50To100",Branch_count, 0);
//        TH1D *DYJetsToLL100To250 = GethPt(f, "DYJetsToLL_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL100To250","DYJetsToLL100To250",Branch_count, 0);
//        TH1D *DYJetsToLL250To400 = GethPt(f, "DYJetsToLL_Pt-250To400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL250To400","DYJetsToLL250To400",Branch_count, 0);
//        TH1D *DYJetsToLL400To650 = GethPt(f, "DYJetsToLL_Pt-400To650_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL400To650","DYJetsToLL400To650",Branch_count, 0);
//        TH1D *DYJetsToLL650Toinf = GethPt(f, "DYJetsToLL_Pt-650ToInf_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL650Toinf","DYJetsToLL650Toinf",Branch_count, 0);
//        //stitch together DY processes
//        DYJetsToLL50To100->Add(DYJetsToLL100To250);
//        DYJetsToLL50To100->Add(DYJetsToLL250To400);
//        DYJetsToLL50To100->Add(DYJetsToLL400To650);
//        DYJetsToLL50To100->Add(DYJetsToLL650Toinf);
	
	//Now 2017 ht-binned DY
	//TH1D *DYJetsToLL_HT70to100 = GethPt(fDY70_100_2017, "Events", "DYJetsToLL_HT-70to100_2017","DYJetsToLL_HT-70to100_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT100to200 = GethPt(fDY100_200_2017, "Events", "DYJetsToLL_HT-100to200_2017","DYJetsToLL_HT-100to200_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT200to400 = GethPt(fDY200_400_2017, "Events", "DYJetsToLL_HT-200to400_2017","DYJetsToLL_HT-200to400_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT400to600 = GethPt(fDY400_600_2017, "Events", "DYJetsToLL_HT-400to600_2017","DYJetsToLL_HT-400to600_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT600to800 = GethPt(fDY600_800_2017, "Events", "DYJetsToLL_HT-600to800_2017","DYJetsToLL_HT-600to800_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT800to1200 = GethPt(fDY800_1200_2017, "Events", "DYJetsToLL_HT-800to1200_2017","DYJetsToLL_HT-800to1200_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT1200to2500 = GethPt(fDY1200_2500_2017, "Events", "DYJetsToLL_HT-1200to2500_2017","DYJetsToLL_HT-1200to2500_2017",Branch_count, 0);
	//TH1D *DYJetsToLL_HT2500toInf = GethPt(fDY2500_Inf_2017, "Events", "DYJetsToLL_HT-2500toInf_2017","DYJetsToLL_HT-2500toInf_2017",Branch_count, 0);
	////Stitch them all together
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT100to200);
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT200to400);
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT400to600);
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT600to800);
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT800to1200);
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT1200to2500);
	//DYJetsToLL_HT70to100->Add(DYJetsToLL_HT2500toInf);

        TH1D *DYJetsToLL_HT70to100 = GethPt(fDY_2017, "Events", "DYJetsToLL_2017","DYJetsToLL_2017",Branch_count, 0);

	TH1D *fullMC = (TH1D*)DYJetsToLL_HT70to100->Clone("copy");
	fullMC->Add(ZZTo2L2Nu_2017);
	fullMC->Add(TTTo2L2Nu_2017);
	fullMC->Add(WWTo2L2Nu_2017);
	fullMC->Add(WZTo3LNu_2017);
        fullMC->Add(WWZ_2017);
	
        //Plot everything
	THStack *s = new THStack("s", variable[Branch_count]);
    
	s->Add(ZZTo2L2Nu_2017);
	s->Add(WZTo3LNu_2017);
	s->Add(WWTo2L2Nu_2017);
	s->Add(TTTo2L2Nu_2017);
	s->Add(WWZ_2017);
        s->Add(DYJetsToLL_HT70to100);

        s->Draw("hist");

	s->SetMinimum(0.01);
        s->GetYaxis()->SetTitle("Events/Bin");
        s->GetXaxis()->SetTitle(axis[Branch_count]);
        s->SetTitle(variable[Branch_count]);
        s->GetYaxis()->SetTitleOffset(1.4);

//        //add the signal on top
//	  TH1D *ZZJJ_ZZTo2L2Nu = GethPt(f, "ZZJJ_ZZTo2L2Nu_EWK_13TeV-madgraph-pythia8", "ZZJJ_ZZTo2L2Nu", "ZZJJ_ZZTo2L2Nu",Branch_count, 0);
//	  ZZJJ_ZZTo2L2Nu->SetFillColorAlpha(2,0.1);
//	  ZZJJ_ZZTo2L2Nu->SetLineColorAlpha(2,.9);
// 	  ZZJJ_ZZTo2L2Nu->SetLineWidth(2);
//
//        ZZJJ_ZZTo2L2Nu->Draw("histsame");
	
	//Prepare the data now
	TH1D *DoubleEG_2017 = GetDATAhPt(fDoubleEG_2017, "Events", "DoubleEG_2017", "DoubleEG_2017",Branch_count, 0);
	TH1D *DoubleMuon_2017 = GetDATAhPt(fDoubleMuon_2017, "Events", "DoubleMuon_2017", "DoubleMuon_2017",Branch_count, 0);
	TH1D *MuonEG_2017 = GetDATAhPt(fMuonEG_2017, "Events", "MuonEG_2017", "MuonEG_2017",Branch_count, 0);
	TH1D *SingleElectron_2017 = GetDATAhPt(fSingleElectron_2017, "Events", "SingleElectron_2017", "SingleElectron_2017",Branch_count, 0);
	//TH1D *SingleMuon_2017 = GetDATAhPt(fSingleMuon_2017, "Events", "SingleMuon_2017", "SingleMuon_2017",Branch_count, 0);
	//Stitch together the data
        TH1D *SingleMuon_2017_1 = GetDATAhPt(fSingleMuon_2017_1, "Events", "SingleMuon_2017", "SingleMuon_2017",Branch_count, 0);
	TH1D *SingleMuon_2017_2 = GetDATAhPt(fSingleMuon_2017_2, "Events", "SingleMuon_2017", "SingleMuon_2017",Branch_count, 0);
	TH1D *SingleMuon_2017_3 = GetDATAhPt(fSingleMuon_2017_3, "Events", "SingleMuon_2017", "SingleMuon_2017",Branch_count, 0);
	TH1D *SingleMuon_2017_4 = GetDATAhPt(fSingleMuon_2017_4, "Events", "SingleMuon_2017", "SingleMuon_2017",Branch_count, 0);
	TH1D *SingleMuon_2017_5 = GetDATAhPt(fSingleMuon_2017_5, "Events", "SingleMuon_2017", "SingleMuon_2017",Branch_count, 0); 
        DoubleEG_2017->Add(SingleMuon_2017_1);
        DoubleEG_2017->Add(SingleMuon_2017_2);
        DoubleEG_2017->Add(SingleMuon_2017_3);
        DoubleEG_2017->Add(SingleMuon_2017_4);
        DoubleEG_2017->Add(SingleMuon_2017_5);



	DoubleEG_2017->Add(DoubleMuon_2017);
	DoubleEG_2017->Add(MuonEG_2017);
	DoubleEG_2017->Add(SingleElectron_2017);
	//DoubleEG_2017->Add(SingleMuon_2017);
	
	DoubleEG_2017->SetMarkerStyle(20);
	DoubleEG_2017->SetMarkerSize(0.5);
	DoubleEG_2017->Draw("Esame");
	
	TH1D *ratio = (TH1D*)DoubleEG_2017->Clone("copy");
	
	
	//Adjust canvas
	cs->SetLeftMargin(0.1);
        //cs->SetTitle(axis[Branch_count]);
	cs->SetLogy();
	p1->SetLogy();
	s->SetMinimum(0.1);
        //cs->Modified();
	addText( 0.1, 0.5, 0.9, 0.95, "#bf{CMS Work in Progress}", kBlack);
	addText(0.65, 0.9, 0.9, 0.95,"ee ch., 41.2 fb^{-1} (13 TeV)",kBlack);
	//addText(0.65, 0.9, 0.9, 0.95,"#mu#mu ch., 9.755 fb^{-1} (13 TeV)",kBlack);


        //Set up legend
    
	//TLegend* leg  = new TLegend(.62,.65,.85,.89);
	TLegend* leg  = new TLegend(.72,.65,.95,.89);
	leg->AddEntry(ZZTo2L2Nu_2017,"ZZ#rightarrow2l2#nu","F");
	leg->AddEntry(WZTo3LNu_2017, "WZ#rightarrow3l#nu","F");
	leg->AddEntry(WWTo2L2Nu_2017,"WW#rightarrow2l2#nu","F");
	leg->AddEntry(TTTo2L2Nu_2017,"TT#rightarrow2l2#nu","F");
        leg->AddEntry(WWZ_2017,"VVV","F");
	leg->AddEntry(DYJetsToLL_HT70to100,"DYJets#rightarrow2l","F");
	//leg->AddEntry(ZZJJ_ZZTo2L2Nu,"ZZJJ#rightarrow2l2#nu","F");
	
	leg->SetFillColor(0);
	leg->SetFillStyle(0);
	leg->SetLineColor(0);
	leg->SetHeader("");
	leg->Draw("same");
	leg->SetTextFont(42);

    
	//Find number of events/process
	float ZZev = ZZTo2L2Nu_2017->Integral(0,nBins[Branch_count]);
	float WZev = WZTo3LNu_2017->Integral(0,nBins[Branch_count]);
	float WWev = WWTo2L2Nu_2017->Integral(0,nBins[Branch_count]);
	float TTev = TTTo2L2Nu_2017->Integral(0,nBins[Branch_count]);
        float DYev = DYJetsToLL_HT70to100->Integral(0,nBins[Branch_count]);
	float background = ZZev + WZev + WWev + TTev + DYev;
	//float VBS = ZZJJ_ZZTo2L2Nu->Integral(0,nBins[Branch_count]);
	float Dataev = DoubleEG_2017->Integral(0,nBins[Branch_count]);
	//float Dataev = 0.0;
    
	//Add event numbers to plot
	TPaveText *table = new TPaveText(0.8,0.63,0.99,0.89,"brNDC");
	table->AddText(Form("ZZ Events#Rightarrow%g",ZZev));
	table->AddText(Form("WZ Events#Rightarrow%g",WZev));
	table->AddText(Form("WZ Events#Rightarrow%g",WWev));
	table->AddText(Form("TT Events#Rightarrow%g",TTev));
	table->AddText(Form("DY Events#Rightarrow%g",DYev));
	table->AddText(Form("Background#Rightarrow%g",background));
	table->AddLine(.0,.28,1.,.28);
	//table->AddText(Form("VBS#Rightarrow%g",VBS));
	table->AddText(Form("Data#Rightarrow%g",Dataev));
        table->SetFillColor(kGray);
	//table->Draw("same");
	
	
	p2->cd();
	ratio->Divide(fullMC);
	ratio->SetTitleSize(0.5,"t");
	ratio->GetXaxis()->SetLabelSize(.1);
	ratio->GetXaxis()->SetTitleSize(.12);
	ratio->GetXaxis()->SetTitleOffset(0.7);
	ratio->GetXaxis()->SetTitle(axis[Branch_count]);
	ratio->GetYaxis()->SetTitle("#frac{Data}{#SigmaMC}");
	ratio->GetYaxis()->SetTitleSize(.12);
	ratio->GetYaxis()->SetTitleOffset(0.35);
	ratio->GetYaxis()->SetLabelSize(0.1);
	ratio->SetMaximum(2);
	ratio->SetMinimum(0);
	ratio->SetStats(0);
	ratio->SetMarkerColor(kBlack);
	ratio->SetLineColor(kBlack);
	ratio->SetTitle("");
	
	//Add red line at 1 for ratio  plot
	TLine *ll = new TLine(xlow[Branch_count], 1., xhi[Branch_count], 1.);
	ll->SetLineWidth(2);
	ll->SetLineStyle(7);
	ll->SetLineColor(kRed);
	
	ratio->Draw();
	ll->Draw();
	ratio->Draw("same");
	p2->SetGridx();
	p2->SetGridy();
	
	cs->Modified();
	cs->Update();
        return cs;
};
