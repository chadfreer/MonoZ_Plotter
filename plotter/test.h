//Code to make colored stack plots

TCanvas * Cutflow_plots() {
    gErrorIgnoreLevel = kError; //Ignore everything below error
    Int_t xcut = 5000;
    gStyle->SetOptStat(0);
    gROOT->SetBatch(kTRUE); //do not display the canvas every time we make one.
    
	//grab the file and the branches
	TCanvas * cs = new TCanvas("cs", "cs", 600, 500);
    TFile *f = new TFile("MonoZ_Combine.root");
    
    //figure out the number of cuts
    int num_cuts = 0;
    for (int Test_count = 0 ; Test_count < Total_count; Test_count++){
        if (TCuts[Test_count] == "") continue;
        num_cuts++;
    }
    
    //Set up cutflow histos
    TH1D *ZZTo2L2Nu_Cutflow = TH1D("ZZTo2L2Nu_Cutflow","ZZTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    TH1D *TTTo2L2Nu_Cutflow = TH1D("TTTo2L2Nu_Cutflow","TTTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    TH1D *WWTo2L2Nu_Cutflow = TH1D("WWTo2L2Nu_Cutflow","ZZTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    TH1D *WZTo3LNu_Cutflow = TH1D("WZTo3LNu_Cutflow","WZTo3LNu_Cutflow",num_cuts,0,num_cuts);
    TH1D *DYJetsToLL50To100_Cutflow = TH1D("DYJetsToLL50To100_Cutflow","DYJetsToLL50To100_Cutflow",num_cuts,0,num_cuts);
    TH1D *ZZJJ_ZZTo2L2Nu_Cutflow = TH1D("ZZJJ_ZZTo2L2Nu_Cutflow","ZZJJ_ZZTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    
    int num_bin = 0;
    for (int Branch_count = 0 ; Branch_count < Total_count; Branch_count++){
        if (TCuts[Test_count] == "") continue;

        TH1D *ZZTo2L2Nu = GethPt(f, "ZZTo2L2Nu_13TeV_powheg_pythia8", "ZZTo2L2Nu", "ZZTo2L2Nu",Branch_count, 0);
        TH1D *TTTo2L2Nu = GethPt(f, "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8", "TTTo2L2Nu", "TTTo2L2Nu",Branch_count, 0);
        TH1D *WWTo2L2Nu = GethPt(f, "WWTo2L2Nu_13TeV-powheg", "WWTo2L2Nu", "WWTo2L2Nu",Branch_count, 0);
        TH1D *WZTo3LNu = GethPt(f, "WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8", "WZTo3LNu", "WZTo3LNu",Branch_count, 0);
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
    
        TH1D *ZZJJ_ZZTo2L2Nu = GethPt(f, "ZZJJ_ZZTo2L2Nu_EWK_13TeV-madgraph-pythia8", "ZZJJ_ZZTo2L2Nu", "ZZJJ_ZZTo2L2Nu",Branch_count, 0);
    
        //Without Cut now!
        TH1D *ZZTo2L2Nu_NoCut = GethPt(f, "ZZTo2L2Nu_13TeV_powheg_pythia8", "ZZTo2L2Nu", "ZZTo2L2Nu",Branch_count, 1);
        TH1D *TTTo2L2Nu_NoCut = GethPt(f, "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8", "TTTo2L2Nu", "TTTo2L2Nu",Branch_count, 1);
        TH1D *WWTo2L2Nu_NoCut = GethPt(f, "WWTo2L2Nu_13TeV-powheg", "WWTo2L2Nu", "WWTo2L2Nu",Branch_count, 1);
        TH1D *WZTo3LNu_NoCut = GethPt(f, "WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8", "WZTo3LNu", "WZTo3LNu",Branch_count, 1);
        TH1D *DYJetsToLL50To100_NoCut = GethPt(f, "DYJetsToLL_Pt-50To100_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL50To100","DYJetsToLL50To100",Branch_count, 1);
        TH1D *DYJetsToLL100To250_NoCut = GethPt(f, "DYJetsToLL_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL100To250","DYJetsToLL100To250",Branch_count, 1);
        TH1D *DYJetsToLL250To400_NoCut = GethPt(f, "DYJetsToLL_Pt-250To400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL250To400","DYJetsToLL250To400",Branch_count, 1;
        TH1D *DYJetsToLL400To650_NoCut = GethPt(f, "DYJetsToLL_Pt-400To650_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL400To650","DYJetsToLL400To650",Branch_count, 1);
        TH1D *DYJetsToLL650Toinf_NoCut = GethPt(f, "DYJetsToLL_Pt-650ToInf_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL650Toinf","DYJetsToLL650Toinf",Branch_count, 1);
												
        //stitch together DY processes
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL100To250_NoCut);
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL250To400_NoCut);
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL400To650_NoCut);
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL650Toinf_NoCut);
        
        TH1D *ZZJJ_ZZTo2L2Nu_NoCut = GethPt(f, "ZZJJ_ZZTo2L2Nu_EWK_13TeV-madgraph-pythia8", "ZZJJ_ZZTo2L2Nu", "ZZJJ_ZZTo2L2Nu",Branch_count, 0);
        
        //Now we integrate
        float ZZTo2L2Nu_eff = ZZTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]) / ZZTo2L2Nu->Integral(0,nBins[Branch_count]);
        ZZTo2L2Nu_Cutflow->SetBinContent(num_bin,ZZTo2L2Nu_eff);
        float TTTo2L2Nu_eff = TTTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]) / TTTo2L2Nu->Integral(0,nBins[Branch_count]);
        TTTo2L2Nu_Cutflow->SetBinContent(num_bin,TTTo2L2Nu_eff);
        float WWTo2L2Nu_eff = WWTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]) / WWTo2L2Nu->Integral(0,nBins[Branch_count]);
        WWTo2L2Nu_Cutflow->SetBinContent(num_bin,WWTo2L2Nu_eff);
        float WZTo3LNu_eff = WZTo3LNu_NoCut->Integral(0,nBins[Branch_count]) / WZTo3LNu->Integral(0,nBins[Branch_count]);
        WZTo3LNu_Cutflow->SetBinContent(num_bin,WZTo3LNu_eff);
        float DYJetsToLL50To100_eff = DYJetsToLL50To100_NoCut->Integral(0,nBins[Branch_count]) / DYJetsToLL50To100->Integral(0,nBins[Branch_count]);
        DYJetsToLL50To100_Cutflow->SetBinContent(num_bin,DYJetsToLL50To100_eff);
        float ZZJJ_ZZTo2L2Nu_eff = ZZJJ_ZZTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]) / ZZJJ_ZZTo2L2Nu->Integral(0,nBins[Branch_count]);
        ZZJJ_ZZTo2L2Nu_Cutflow->SetBinContent(num_bin,ZZJJ_ZZTo2L2Nu_eff);
        ZZTo2L2Nu_Cutflow->GetXaxis()->SetBinLabel(num_bin, axis[Branch_count] );
        num_bin++;
        }
                        

                                                
    //Plot things now.
    ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitleOffset(1.4);
    ZZTo2L2Nu_Cutflow->SetLineColorAlpha(2,.9);
    ZZTo2L2Nu_Cutflow->SetLineWidth(2);
    ZZTo2L2Nu_Cutflow->Draw();
    ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitle("Efficiency");
    ZZTo2L2Nu_Cutflow->SetTitle("Cutflow");
    ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitleOffset(1.4);
                                                
    TTTo2L2Nu_Cutflow->SetLineColorAlpha(4,.9);
    TTTo2L2Nu_Cutflow->SetLineWidth(2);
    TTTo2L2Nu_Cutflow->Draw("same");
                    
    WWTo2L2Nu_Cutflow->SetLineColorAlpha(6,.9);
    WWTo2L2Nu_Cutflow->SetLineWidth(2);
    WWTo2L2Nu_Cutflow->Draw("same");
                                                
    WZTo3LNu_Cutflow->SetLineColorAlpha(8,.9);
    WZTo3LNu_Cutflow->SetLineWidth(2);
    WZTo3LNu_Cutflow->Draw("same");
                                                
    DYJetsToLL50To100_Cutflow->SetLineColorAlpha(10,.9);
    DYJetsToLL50To100_Cutflow->SetLineWidth(2);
    DYJetsToLL50To100_Cutflow->Draw("same");
                                                
    ZZJJ_ZZTo2L2Nu_Cutflow->SetLineColorAlpha(1,.9);
    ZZJJ_ZZTo2L2Nu_Cutflow->SetLineWidth(2);
    ZZJJ_ZZTo2L2Nu_Cutflow->Draw("same");
        
    
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


	cs->SetLeftMargin(0.1);
    cs->SetTitle(axis[Branch_count]);
	cs->SetLogy();
    cs->Modified();
	addText( 0.1, 0.5, 0.9, 0.95, "#bf{CMS Work in Progress}", kBlack);
	addText(0.65, 0.9, 0.9, 0.95,"ll ch., 35.9 fb^{-1} (13 TeV)",kBlack);

//Set up legend
    
	TLegend* leg  = new TLegend(.62,.65,.85,.89);
	leg->AddEntry(ZZTo2L2Nu_Cutflow,"ZZ","F");
	leg->AddEntry(WZTo3LNu_Cutflow, "WZ","F");
	leg->AddEntry(WWTo2L2Nu_Cutflow,"WW","F");
	leg->AddEntry(TTTo2L2Nu_Cutflow,"TT","F");
	leg->AddEntry(DYJetsToLL50To100_Cutflow,"DY","F");
	leg->AddEntry(ZZJJ_ZZTo2L2Nu_Cutflow,"VBS","F");
    //leg->AddEntry(LLDMMx2Heavy,"LLDM M#Chi2=150","F");
    //leg->AddEntry(LLDMMx2Light,"LLDM M#Chi2=1","F");
	leg->SetFillColor(0);
	leg->SetFillStyle(0);
	leg->SetLineColor(0);
	leg->SetHeader("");
	leg->Draw("same");
	leg->SetTextFont(42);

    /*
	//Find number of events/process
	float ZZev = ZZTo2L2Nu->Integral(0,nBins[Branch_count]);
	float WZev = WZTo3LNu->Integral(0,nBins[Branch_count]);
	float WWev = WWTo2L2Nu->Integral(0,nBins[Branch_count]);
	float TTev = TTTo2L2Nu->Integral(0,nBins[Branch_count]);
	//float DYev = DYJetsToLL->Integral(0,nBins[Branch_count]);
    float DYev = DYJetsToLL50To100->Integral(0,nBins[Branch_count]);
	float background = ZZev + WZev + WWev + TTev + DYev;
	float VBS = ZZJJ_ZZTo2L2Nu->Integral(0,nBins[Branch_count]);
    //float LLDMMx2Heavyev = LLDMMx2Heavy->Integral(0,nBins[Branch_count]);
    //float LLDMMx2Lightev = LLDMMx2Light->Integral(0,nBins[Branch_count]);
    
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
};
