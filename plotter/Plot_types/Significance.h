TCanvas * Significance_plots(int Branch_count) {
    gErrorIgnoreLevel = kError; //Ignore everything below error
        //cout << variable[Branch_count] << axis[Branch_count] << xlow[Branch_count] << xhi[Branch_count] << nBins[Branch_count] << endl;
    gStyle->SetOptStat(0);
    gROOT->SetBatch(kTRUE); //do not display the canvas every time we make one.
	//grab the file and the branches
	TCanvas * cs = new TCanvas("cs", "cs", 600, 500);
	//TFile *f = new TFile("TMVAPt-binned.root");
    TFile *f = new TFile("/Users/Chad/Desktop/MonoZ_Analysis_Moriond-2019/root_files/MINIAOD/Oct-8-2018/MonoZ_Combine-VBS.root");
	TH1D *ZZTo2L2Nu = GethPt(f, "ZZTo2L2Nu_13TeV_powheg_pythia8", "ZZTo2L2Nu", "ZZTo2L2Nu",Branch_count, 0);
	TH1D *TTTo2L2Nu = GethPt(f, "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8", "TTTo2L2Nu", "TTTo2L2Nu",Branch_count, 0);
	TH1D *WWTo2L2Nu = GethPt(f, "WWTo2L2Nu_13TeV-powheg", "WWTo2L2Nu", "WWTo2L2Nu",Branch_count, 0);
	//TH1D *DYJetsToLL = GethPt(f, "DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", "DYJetsToLL", "DYJetsToLL",Branch_count);
	TH1D *WZTo3LNu = GethPt(f, "WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8", "WZTo3LNu", "WZTo3LNu",Branch_count, 0);
    //TEMPORARY FIX WITH WRONG WZ GENERATOR!!!!!!!!!!!!
    //TH1D *WZTo3LNu = GethPt(f, "WZTo3LNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "WZTo3LNu", "WZTo3LNu");
    TH1D *DYJetsToLL50To100 = GethPt(f, "DYJetsToLL_Pt-50To100_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL50To100","DYJetsToLL50To100",Branch_count, 0);
    TH1D *DYJetsToLL100To250 = GethPt(f, "DYJetsToLL_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL100To250","DYJetsToLL100To250",Branch_count, 0);
    TH1D *DYJetsToLL250To400 = GethPt(f, "DYJetsToLL_Pt-250To400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL250To400","DYJetsToLL250To400",Branch_count, 0);
    TH1D *DYJetsToLL400To650 = GethPt(f, "DYJetsToLL_Pt-400To650_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL400To650","DYJetsToLL400To650",Branch_count, 0);
    TH1D *DYJetsToLL650Toinf = GethPt(f, "DYJetsToLL_Pt-650ToInf_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL650Toinf","DYJetsToLL650Toinf",Branch_count, 0);
    
    //stitch together DY processes
    DYJetsToLL50To100->Add(DYJetsToLL100To250);
    DYJetsToLL50To100->Add(DYJetsToLL250To400);
    DYJetsToLL50To100->Add(DYJetsToLL400To650);
    DYJetsToLL50To100->Add(DYJetsToLL650Toinf);
	
    //Plot everything
	//THStack *s = new THStack("s", variable);
    
	//s->Add(ZZTo2L2Nu);
	ZZTo2L2Nu->Add(WZTo3LNu);
	ZZTo2L2Nu->Add(WWTo2L2Nu);
	ZZTo2L2Nu->Add(TTTo2L2Nu);
	//s->Add(DYJetsToLL);
    ZZTo2L2Nu->Add(DYJetsToLL50To100);
    //ZZTo2L2Nu->GetYaxis()->SetTitle("Normalized Distribution");
    //ZZTo2L2Nu->GetXaxis()->SetTitle(axis[Branch_count]);
    //ZZTo2L2Nu->SetTitle(variable[Branch_count]);
    //ZZTo2L2Nu->GetYaxis()->SetTitleOffset(1.4);
    //ZZTo2L2Nu->SetMinimum(0.01);
    //ZZTo2L2Nu->SetStats(0);
    //ZZTo2L2Nu->DrawNormalized();
    //float Normalize = ZZTo2L2Nu->Integral(0,nBins);
    //ZZTo2L2Nu->Scale(1/Normalize);
    
	//add the signal on top
	TH1D *ZZJJ_ZZTo2L2Nu = GethPt(f, "ZZJJ_ZZTo2L2Nu_EWK_13TeV-madgraph-pythia8", "ZZJJ_ZZTo2L2Nu", "ZZJJ_ZZTo2L2Nu",Branch_count, 0);
    //float Normalize2 = ZZJJ_ZZTo2L2Nu->Integral(0,nBins);
    //ZZJJ_ZZTo2L2Nu->Scale(1/Normalize2);
	//ZZJJ_ZZTo2L2Nu->SetFillColorAlpha(2,0.1);
	//ZZJJ_ZZTo2L2Nu->SetLineColorAlpha(2,.9);
	//ZZJJ_ZZTo2L2Nu->SetLineWidth(2);
    //TH1F *Sigma_H = new TH1F(variable[Branch_count], axis[Branch_count], nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    //TH1F *Sigma_H2 = new TH1F(variable[Branch_count], axis[Branch_count], nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    TH1D *Sigma_H = new TH1D(variable[Branch_count], axis[Branch_count], nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    TH1D *Sigma_H2 = new TH1D(variable[Branch_count], axis[Branch_count], nBins[Branch_count], xlow[Branch_count], xhi[Branch_count]);
    float Sigma = 0;
    float Sigma2 = 0;

    
    for (int Bin_count = 0 ; Bin_count < nBins[Branch_count]; Bin_count++){

        float Background = ZZTo2L2Nu->Integral(Bin_count, nBins[Branch_count]);
        float Signal = ZZJJ_ZZTo2L2Nu->Integral(Bin_count, nBins[Branch_count]);
        if (Signal + Background == 0) Sigma = 0 ;
        if (Signal + Background != 0) Sigma = Signal/sqrt(Signal+Background);
        Sigma_H->SetBinContent(Bin_count,Sigma);
    

        float Background2 = ZZTo2L2Nu->Integral(0,Bin_count);
        float Signal2 = ZZJJ_ZZTo2L2Nu->Integral(0,Bin_count);
        if (Signal2 + Background2 == 0) Sigma2 = 0 ;
        if (Signal2 + Background2 != 0) Sigma2 = Signal2/sqrt(Signal2+Background2);
        Sigma_H2->SetBinContent(Bin_count, Sigma2);

    }
    
    Sigma_H->GetYaxis()->SetTitle("#frac{S}{#sqrt{S+B}}");
    Sigma_H->GetXaxis()->SetTitle(axis[Branch_count]);
    Sigma_H->SetTitle("Significance");
    Sigma_H->SetTitleSize(0.1);
    Sigma_H->GetYaxis()->SetTitleOffset(1.35);
    Sigma_H->SetMinimum(0.01);
    Sigma_H->SetStats(0);
    
    Sigma_H->SetFillColorAlpha(2,0.5);
    Sigma_H2->SetFillColorAlpha(6,0.5);
    
    Sigma_H->Draw();
    Sigma_H2->Draw("same");
    //Sigma_H->Draw("same");
    /*
    ZZJJ_ZZTo2L2Nu->GetYaxis()->SetTitle("Normalized Distribution");
    ZZJJ_ZZTo2L2Nu->GetXaxis()->SetTitle(axis);
    ZZJJ_ZZTo2L2Nu->SetTitle(variable);
    ZZJJ_ZZTo2L2Nu->GetYaxis()->SetTitleOffset(1.4);
    ZZJJ_ZZTo2L2Nu->SetMinimum(0.01);
    ZZJJ_ZZTo2L2Nu->SetStats(0);
	ZZJJ_ZZTo2L2Nu->DrawNormalized();
    ZZTo2L2Nu->DrawNormalized("same");
    */
    
    //ZZJJ_ZZTo2L2Nu->DrawNormalized("same");
    /*
    TH1D *LLDMMx2Heavy = GethPt(f, "DarkMatter_MonoZToLL_NLO_Vector_Mx2-150_Mv-500_gDM1_gQ0p25_TuneCUETP8M1_Mx1-1_ctau-1_13TeV-madgraph", "LLDMMx2Heavy", "LLDMMx2Heavy",Branch_count);
    LLDMMx2Heavy->SetFillColorAlpha(9,0.1);
    LLDMMx2Heavy->SetLineColorAlpha(9,.9);
    LLDMMx2Heavy->SetLineWidth(2);
    LLDMMx2Heavy->Draw("same");
    
    TH1D *LLDMMx2Light = GethPt(f, "DarkMatter_MonoZToLL_NLO_Vector_Mx2-1_Mv-500_gDM1_gQ0p25_TuneCUETP8M1_Mx1-0p1_ctau-1_13TeV-madgraph", "LLDMMx2Light", "LLDMMx2Light",Branch_count);
    LLDMMx2Light->SetFillColorAlpha(1,0.1);
    LLDMMx2Light->SetLineColorAlpha(1,.9);
    LLDMMx2Light->SetLineWidth(2);
    LLDMMx2Light->Draw("same");
   */
  //Add line to show cut
	//cs->Update();
	//TLine *line = new TLine(xcut, cs->GetUymin(), xcut, cs->GetUymax());
	//line->SetLineColor(kBlack);
	//line->SetLineWidth(4);
	//line->SetLineStyle(2);
	//line->Draw("same");
/*
	cs->Update();
	TLine *line2 = new TLine(81, cs->GetUymin(), 81, cs->GetUymax());
	line2->SetLineColor(kBlack);
	line2->SetLineWidth(4);
	line2->SetLineStyle(2);
	line2->Draw("same");
*/
	//Set up plot parameters
	//ZZTo2L2Nu->GetYaxis()->SetTitle("[Events / Bin]");
	//ZZTo2L2Nu->GetXaxis()->SetTitle(axis);
	//ZZTo2L2Nu->GetYaxis()->SetTitleOffset(1.1);
	//ZZTo2L2Nu->SetMinimum(0.01);
    //ZZTo2L2Nu->SetStats(0);
	cs->SetLeftMargin(0.1);
    //cs->SetTitle(axis[Branch_count]);
    //gPad->SetLogz();
	cs->SetLogz();
	//cs->Modified();
	addText( 0.1, 0.5, 0.9, 0.95, "#bf{CMS Work in Progress}", kBlack);
	addText(0.65, 0.9, 0.9, 0.95,"ll ch., 35.9 fb^{-1} (13 TeV)",kBlack);

//Set up legend

	TLegend* leg  = new TLegend(.62,.65,.85,.89);
	leg->AddEntry(Sigma_H,"Lower Cuts","F");
    leg->AddEntry(Sigma_H2,"Upper Cuts","F");
	//leg->AddEntry(WZTo3LNu, "WZ#rightarrow3l#nu","F");
	//leg->AddEntry(WWTo2L2Nu,"WW#rightarrow2l2#nu","F");
	//leg->AddEntry(TTTo2L2Nu,"TT#rightarrow2l2#nu","F");
	//leg->AddEntry(DYJetsToLL,"DYJets#rightarrow2l","F");
	//leg->AddEntry(ZZJJ_ZZTo2L2Nu,"ZZJJ#rightarrow2l2#nu","F");
    //leg->AddEntry(LLDMMx2Heavy,"LLDM M#Chi2=150","F");
    //leg->AddEntry(LLDMMx2Light,"LLDM M#Chi2=1","F");
	leg->SetFillColor(0);
	leg->SetFillStyle(0);
	leg->SetLineColor(0);
	leg->SetHeader("");
	leg->Draw("same");
	leg->SetTextFont(42);

    
	//Find number of events/process
    /*
	float ZZev = ZZTo2L2Nu->Integral(0,nBins);
	float WZev = WZTo3LNu->Integral(0,nBins);
	float WWev = WWTo2L2Nu->Integral(0,nBins);
	float TTev = TTTo2L2Nu->Integral(0,nBins);
	//float DYev = DYJetsToLL->Integral(0,nBins);
    float DYev = DYJetsToLL50To100->Integral(0,nBins);
	float background = ZZev + WZev + WWev + TTev + DYev;
	float VBS = ZZJJ_ZZTo2L2Nu->Integral(0,nBins);
    //float LLDMMx2Heavyev = LLDMMx2Heavy->Integral(0,nBins);
    //float LLDMMx2Lightev = LLDMMx2Light->Integral(0,nBins);
    
	//Add event numbers to plot
	TPaveText *table = new TPaveText(0.8,0.63,0.99,0.89,"brNDC");
	table->AddText(Form("ZZ Events#Rightarrow%g",ZZev));
	table->AddText(Form("WZ Events#Rightarrow%g",WWev));
	table->AddText(Form("TT Events#Rightarrow%g",TTev));
	table->AddText(Form("DY Events#Rightarrow%g",DYev));
	table->AddText(Form("Background#Rightarrow%g",background));
	table->AddLine(.0,.5,1.,.5);
	table->AddText(Form("VBS#Rightarrow%g",VBS));
    //table->AddText(Form("LLDM M#Chi2=150#Rightarrow%g",LLDMMx2Heavyev));
    //table->AddText(Form("LLDM M#Chi2=1#Rightarrow%g",LLDMMx2Lightev));
    table->SetFillColor(kGray);
	table->Draw("same");
    */
    return cs;
}
