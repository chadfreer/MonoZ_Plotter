//Code to make colored stack plots
//#include "Cuts.h"
//#include "Variables.h"

TCanvas * Cutflow_plots() {
    gErrorIgnoreLevel = kError; //Ignore everything below error
    Int_t xcut = 5000;
    gStyle->SetOptStat(0);
    gROOT->SetBatch(kTRUE); //do not display the canvas every time we make one.
    
	//grab the file and the branches
	TCanvas * cs = new TCanvas("cs", "cs", 600, 500);
    TFile *f = new TFile("/Users/Chad/Desktop/MonoZ_Analysis_Moriond-2019/root_files/MINIAOD/Oct-8-2018/MonoZ_Combine-VBS.root");
	THStack *s = new THStack("s", "Cutflow (N-1)");
	
    //figure out the number of cuts
    int num_cuts = 0;
    for (int Test_count = 0 ; Test_count < 41; Test_count++){
        //if (TCuts[Test_count] == "") continue;
		if (strcmp(TCuts[Test_count],"")==0) continue;
		//if (variable[Test_count] == "Zpt_Reco" || variable[Test_count] == "DeltaPhiZMet" || variable[Test_count] == "LeadingPtll" || variable[Test_count] == "TrailingPtll" || variable[Test_count] == "LeadingJetPt" || variable[Test_count] == "subLeadingJetPt" || variable[Test_count] == "prepfMet" || variable[Test_count] == "ngoodjets" || variable[Test_count] == "nBjets" ) continue;
		if (strcmp(variable[Test_count],"Zpt_Reco")==0 || strcmp(variable[Test_count],"DeltaPhiZMet")==0 || strcmp(variable[Test_count],"LeadingPtll")==0 || strcmp(variable[Test_count],"TrailingPtll")==0 || strcmp(variable[Test_count],"LeadingJetPt")==0 || strcmp(variable[Test_count],"subLeadingJetPt")==0 || strcmp(variable[Test_count],"prepfMet")==0 || strcmp(variable[Test_count],"ngoodjets")==0 || strcmp(variable[Test_count],"nBjets")==0 ) continue;
        num_cuts++;
    }
    
    //Set up cutflow histos
    TH1D *ZZTo2L2Nu_Cutflow = new TH1D("ZZTo2L2Nu_Cutflow","ZZTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    TH1D *TTTo2L2Nu_Cutflow = new TH1D("TTTo2L2Nu_Cutflow","TTTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    TH1D *WWTo2L2Nu_Cutflow = new TH1D("WWTo2L2Nu_Cutflow","ZZTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
    TH1D *WZTo3LNu_Cutflow = new TH1D("WZTo3LNu_Cutflow","WZTo3LNu_Cutflow",num_cuts,0,num_cuts);
    TH1D *DYJetsToLL50To100_Cutflow = new TH1D("DYJetsToLL50To100_Cutflow","DYJetsToLL50To100_Cutflow",num_cuts,0,num_cuts);
    TH1D *ZZJJ_ZZTo2L2Nu_Cutflow = new TH1D("ZZJJ_ZZTo2L2Nu_Cutflow","ZZJJ_ZZTo2L2Nu_Cutflow",num_cuts,0,num_cuts);
	
	//Addition
	//TH1D *Background = new TH1D("Background","Background",num_cuts,0,num_cuts);
	//TH1D *Background_NoCut = new TH1D("Background_NoCut","Background_NoCut",num_cuts,0,num_cuts);
	TH1D *Background_Cutflow = new TH1D("Background_Cutflow","Background_Cutflow",num_cuts,0,num_cuts);
	
    int num_bin = 1;
    for (int Branch_count = 0 ; Branch_count < 41; Branch_count++){
		//if (strcmp(TCuts[Branch_count],"preZmass > 81 && preZmass < 101")==0) cout << "Im here" << endl;
        //if (TCuts[Branch_count] == "") continue;
		if (strcmp(TCuts[Branch_count],"")==0) continue;
		//if (variable[Branch_count] == "Zpt_Reco" || variable[Branch_count] == "DeltaPhiZMet" || variable[Branch_count] == "LeadingPtll" || variable[Branch_count] == "TrailingPtll" || variable[Branch_count] == "LeadingJetPt" || variable[Branch_count] == "subLeadingJetPt"|| variable[Branch_count] == "prepfMet" || variable[Branch_count] == "ngoodjets" || variable[Branch_count] == "nBjets") continue;
		if (strcmp(variable[Branch_count],"Zpt_Reco")==0 || strcmp(variable[Branch_count],"DeltaPhiZMet")==0 || strcmp(variable[Branch_count],"LeadingPtll")==0 || strcmp(variable[Branch_count],"TrailingPtll")==0 || strcmp(variable[Branch_count],"LeadingJetPt")==0 || strcmp(variable[Branch_count],"subLeadingJetPt")==0 || strcmp(variable[Branch_count],"prepfMet")==0 || strcmp(variable[Branch_count],"ngoodjets")==0 || strcmp(variable[Branch_count],"nBjets")==0 ) continue;
		
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
        TH1D *ZZTo2L2Nu_NoCut = GethPt(f, "ZZTo2L2Nu_13TeV_powheg_pythia8", "ZZTo2L2Nu_NoCut", "ZZTo2L2Nu",Branch_count, 1);
        TH1D *TTTo2L2Nu_NoCut = GethPt(f, "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8", "TTTo2L2Nu_NoCut", "TTTo2L2Nu",Branch_count, 1);
        TH1D *WWTo2L2Nu_NoCut = GethPt(f, "WWTo2L2Nu_13TeV-powheg", "WWTo2L2Nu_NoCut", "WWTo2L2Nu",Branch_count, 1);
        TH1D *WZTo3LNu_NoCut = GethPt(f, "WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8", "WZTo3LNu_NoCut", "WZTo3LNu",Branch_count, 1);
        TH1D *DYJetsToLL50To100_NoCut = GethPt(f, "DYJetsToLL_Pt-50To100_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL50To100_NoCut","DYJetsToLL50To100",Branch_count, 1);
        TH1D *DYJetsToLL100To250_NoCut = GethPt(f, "DYJetsToLL_Pt-100To250_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL100To250_NoCut","DYJetsToLL100To250",Branch_count, 1);
        TH1D *DYJetsToLL250To400_NoCut = GethPt(f, "DYJetsToLL_Pt-250To400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL250To400_NoCut","DYJetsToLL250To400",Branch_count, 1);
        TH1D *DYJetsToLL400To650_NoCut = GethPt(f, "DYJetsToLL_Pt-400To650_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL400To650_NoCut","DYJetsToLL400To650",Branch_count, 1);
		TH1D *DYJetsToLL650Toinf_NoCut = GethPt(f, "DYJetsToLL_Pt-650ToInf_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8", "DYJetsToLL650Toinf_NoCut","DYJetsToLL650Toinf",Branch_count, 1);
		
        //stitch together DY processes
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL100To250_NoCut);
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL250To400_NoCut);
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL400To650_NoCut);
        DYJetsToLL50To100_NoCut->Add(DYJetsToLL650Toinf_NoCut);

        TH1D *ZZJJ_ZZTo2L2Nu_NoCut = GethPt(f, "ZZJJ_ZZTo2L2Nu_EWK_13TeV-madgraph-pythia8", "ZZJJ_ZZTo2L2Nu_NoCut", "ZZJJ_ZZTo2L2Nu",Branch_count, 1);
        
        //Now we integrate
        float ZZTo2L2Nu_eff = ZZTo2L2Nu->Integral(0,nBins[Branch_count]) / ZZTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]);
        ZZTo2L2Nu_Cutflow->SetBinContent(num_bin,ZZTo2L2Nu_eff);
        float TTTo2L2Nu_eff = TTTo2L2Nu->Integral(0,nBins[Branch_count]) / TTTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]);
        TTTo2L2Nu_Cutflow->SetBinContent(num_bin,TTTo2L2Nu_eff);
        float WWTo2L2Nu_eff = WWTo2L2Nu->Integral(0,nBins[Branch_count]) / WWTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]);
        WWTo2L2Nu_Cutflow->SetBinContent(num_bin,WWTo2L2Nu_eff);
        float WZTo3LNu_eff = WZTo3LNu->Integral(0,nBins[Branch_count]) / WZTo3LNu_NoCut->Integral(0,nBins[Branch_count]);
        WZTo3LNu_Cutflow->SetBinContent(num_bin,WZTo3LNu_eff);
        float DYJetsToLL50To100_eff = DYJetsToLL50To100->Integral(0,nBins[Branch_count]) / DYJetsToLL50To100_NoCut->Integral(0,nBins[Branch_count]);
        DYJetsToLL50To100_Cutflow->SetBinContent(num_bin,DYJetsToLL50To100_eff);
        float ZZJJ_ZZTo2L2Nu_eff = ZZJJ_ZZTo2L2Nu->Integral(0,nBins[Branch_count]) / ZZJJ_ZZTo2L2Nu_NoCut->Integral(0,nBins[Branch_count]);
        ZZJJ_ZZTo2L2Nu_Cutflow->SetBinContent(num_bin,ZZJJ_ZZTo2L2Nu_eff);

		//Additions'
		TH1D *Background = new TH1D("Background","Background",num_cuts,0,num_cuts);
		TH1D *Background_NoCut = new TH1D("Background_NoCut","Background_NoCut",num_cuts,0,num_cuts);
		Background->Add(ZZTo2L2Nu);
		Background->Add(TTTo2L2Nu);
		Background->Add(WWTo2L2Nu);
		Background->Add(WZTo3LNu);
		Background->Add(DYJetsToLL50To100);

		Background_NoCut->Add(ZZTo2L2Nu_NoCut);
		Background_NoCut->Add(TTTo2L2Nu_NoCut);
		Background_NoCut->Add(WWTo2L2Nu_NoCut);
		Background_NoCut->Add(WZTo3LNu_NoCut);
		Background_NoCut->Add(DYJetsToLL50To100_NoCut);
		
		float Background_eff = Background->Integral(0,nBins[Branch_count]) / Background_NoCut->Integral(0,nBins[Branch_count]);
        Background_Cutflow->SetBinContent(num_bin,Background_eff);
		
		
		cout << "here is my axis title    " << axis[Branch_count] << "   for bin number     " << num_bin << endl;
        ZZTo2L2Nu_Cutflow->GetXaxis()->SetBinLabel(num_bin, axis[Branch_count] );
		ZZJJ_ZZTo2L2Nu_Cutflow->GetXaxis()->SetBinLabel(num_bin, axis[Branch_count] );
		
		delete ZZTo2L2Nu;
		delete TTTo2L2Nu;
		delete WWTo2L2Nu;
		delete WZTo3LNu;
		delete DYJetsToLL50To100;
		delete DYJetsToLL100To250;
		delete DYJetsToLL250To400;
		delete DYJetsToLL400To650;
		delete DYJetsToLL650Toinf;
		delete ZZJJ_ZZTo2L2Nu;
	
		delete ZZTo2L2Nu_NoCut;
		delete TTTo2L2Nu_NoCut;
		delete WWTo2L2Nu_NoCut;
		delete WZTo3LNu_NoCut;
		delete DYJetsToLL50To100_NoCut;
		delete DYJetsToLL100To250_NoCut;
		delete DYJetsToLL250To400_NoCut;
		delete DYJetsToLL400To650_NoCut;
		delete DYJetsToLL650Toinf_NoCut;
		delete ZZJJ_ZZTo2L2Nu_NoCut;
		
		delete Background;
		delete Background_NoCut;
		
        num_bin++;
    }
                                                

                                                
//    //Plot things now.
//    ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitleOffset(1.4);
//    ZZTo2L2Nu_Cutflow->SetLineColorAlpha(kOrange-2,.9);
//    ZZTo2L2Nu_Cutflow->SetLineWidth(2);
//    ZZTo2L2Nu_Cutflow->Draw("bar");
//    ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitle("Efficiency");
//    ZZTo2L2Nu_Cutflow->SetTitle("Cutflow");
//    ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitleOffset(1.4);
//                                                
//    TTTo2L2Nu_Cutflow->SetLineColorAlpha(kGray+1,.9);
//    TTTo2L2Nu_Cutflow->SetLineWidth(2);
//    TTTo2L2Nu_Cutflow->Draw("barsame");
//                    
//    WWTo2L2Nu_Cutflow->SetLineColorAlpha(kTeal+2,.9);
//    WWTo2L2Nu_Cutflow->SetLineWidth(2);
//    WWTo2L2Nu_Cutflow->Draw("barsame");
//                                                
//    WZTo3LNu_Cutflow->SetLineColorAlpha(kAzure-4,.9);
//    WZTo3LNu_Cutflow->SetLineWidth(2);
//    WZTo3LNu_Cutflow->Draw("barsame");
//                                                
//    DYJetsToLL50To100_Cutflow->SetLineColorAlpha(kPink+1,.9);
//    DYJetsToLL50To100_Cutflow->SetLineWidth(2);
//    DYJetsToLL50To100_Cutflow->Draw("barsame");
//                                                
//    ZZJJ_ZZTo2L2Nu_Cutflow->SetLineColorAlpha(kRed,.9);
//    ZZJJ_ZZTo2L2Nu_Cutflow->SetLineWidth(2);
//    ZZJJ_ZZTo2L2Nu_Cutflow->Draw("barsame");

	
	//THStack *s = new THStack("s", "Cutflow (N-1)");
	
	//ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitleOffset(1.4);
	//ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitle("Efficiency");
	//ZZTo2L2Nu_Cutflow->SetTitle("Cutflow");
	//ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitleOffset(1.4);
	
	ZZTo2L2Nu_Cutflow->SetLineColorAlpha(kOrange-2,.9);
	TTTo2L2Nu_Cutflow->SetLineColorAlpha(kGray+1,.9);
	WWTo2L2Nu_Cutflow->SetLineColorAlpha(kTeal+2,.9);
	WZTo3LNu_Cutflow->SetLineColorAlpha(kAzure-4,.9);
	DYJetsToLL50To100_Cutflow->SetLineColorAlpha(kPink+1,.9);
	ZZJJ_ZZTo2L2Nu_Cutflow->SetLineColorAlpha(kRed,.9);

	ZZTo2L2Nu_Cutflow->SetFillColorAlpha(kOrange-2,.9);
	TTTo2L2Nu_Cutflow->SetFillColorAlpha(kGray+1,.9);
	WWTo2L2Nu_Cutflow->SetFillColorAlpha(kTeal+2,.9);
	WZTo3LNu_Cutflow->SetFillColorAlpha(kAzure-4,.9);
	DYJetsToLL50To100_Cutflow->SetFillColorAlpha(kPink+1,.9);
	//ZZJJ_ZZTo2L2Nu_Cutflow->SetLineColorAlpha(kRed,.9);
	ZZJJ_ZZTo2L2Nu_Cutflow->SetMinimum(0);
	ZZJJ_ZZTo2L2Nu_Cutflow->SetTitle("Cutflow (N-1)");
	ZZJJ_ZZTo2L2Nu_Cutflow->GetYaxis()->SetTitle("Cut Efficiency");
	
	s->Add(ZZTo2L2Nu_Cutflow);
	s->Add(TTTo2L2Nu_Cutflow);
	s->Add(WWTo2L2Nu_Cutflow);
	s->Add(WZTo3LNu_Cutflow);
	s->Add(DYJetsToLL50To100_Cutflow);
	//s->Add(ZZJJ_ZZTo2L2Nu_Cutflow);
	ZZJJ_ZZTo2L2Nu_Cutflow->Draw();
	s->Draw("nostack bar same");
	
	Background_Cutflow->SetFillColorAlpha(kBlack,.05);
	Background_Cutflow->Draw("same");
	
	//ZZJJ_ZZTo2L2Nu_Cutflow->Draw("same");
	
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
    //cs->SetTitle(axis[Branch_count]);
	//cs->SetLogy();
    //cs->Modified();
	addText( 0.1, 0.5, 0.9, 0.95, "#bf{CMS Work in Progress}", kBlack);
	addText(0.65, 0.9, 0.9, 0.95,"ll ch., 35.9 fb^{-1} (13 TeV)",kBlack);

//Set up legend
    
	//TLegend* leg  = new TLegend(.62,.65,.85,.89);
	TLegend* leg  = new TLegend(.90,.65,1,.89);
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
