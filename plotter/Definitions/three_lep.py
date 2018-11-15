import yaml
from ROOT import *

gROOT.SetBatch(1)

with open('ROOTfiles.yml', 'r') as f_yml:
    dict_yml = yaml.load(f_yml)

datasets = [
   'ZZTo2L2Nu_13TeV_powheg_pythia8',
   'WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8',
   'WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8',
   'TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8',
   'ZZZ_TuneCP5_13TeV-amcatnlo-pythia8',
   'WZZ_TuneCP5_13TeV-amcatnlo-pythia8',
   'WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8',
   'DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8']

ndatasets = len(datasets)

PDs = [
   'MuonEG',
   'SingleElectron',
   'SingleMuon',
   'DoubleMuon',
   'DoubleEG']

nPDs = len(PDs)
def test():
   prf = TProof.Open("lite://")
   hists = [None] * ndatasets
   stk = THStack("stk", ";;Events / Bin ")
   MC = TH1F('h', 'h', 10, 60, 260)
   for i in range(ndatasets):
      dataset = datasets[i]
      chain = TChain("Events") 
      for file in dict_yml[dataset]['files']:
         chain.Add(file)
      chain.SetProof()
      if dataset == 'TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8': name = 'TT'
      if dataset == 'DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8': name = 'DY'
      if dataset == 'WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8': name = 'WW'
      if dataset == 'ZZTo2L2Nu_13TeV_powheg_pythia8': name = 'ZZ'
      if dataset == 'WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8': name = 'WZ'
      if dataset == 'ZZZ_TuneCP5_13TeV-amcatnlo-pythia8': name = 'VVV'
      if dataset == 'WZZ_TuneCP5_13TeV-amcatnlo-pythia8': name = 'VVV'
      if dataset == 'WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8': name = 'VVV'
      #hist_name = dataset.split('_')[0]
      hists[i] = TH1F(name, name, 10, 60, 260)
      chain.Project(name, 'Z_pt', "puWeight * lumiWeight * (lep_category>3 && lep_category < 6 && Z_pt>60 && met_pt>40 && Z_mass>81 && Z_mass<101 && ngood_jets<2 && ngood_bjets==0)")
      hists[i].SetName(name)
      chain.Reset()
      chain.Delete()
      if dataset == 'TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8': hists[i].SetFillColor(kGray+1)
      if dataset == 'DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8': hists[i].SetFillColor(kPink+1)
      if dataset == 'WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8': hists[i].SetFillColor(kTeal+2)
      if dataset == 'ZZTo2L2Nu_13TeV_powheg_pythia8': hists[i].SetFillColor(kOrange-2)
      if dataset == 'WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8': hists[i].SetFillColor(kAzure-4)
      if dataset == 'ZZZ_TuneCP5_13TeV-amcatnlo-pythia8': hists[i].SetFillColor(kPink-5)
      if dataset == 'WZZ_TuneCP5_13TeV-amcatnlo-pythia8': hists[i].SetFillColor(kPink-5)
      if dataset == 'WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8': hists[i].SetFillColor(kPink-5)
      hists[i].Scale(41.5)
      stk.Add(hists[i])
      MC.Add(hists[i])

   dathists = [None] * nPDs
   dat = TH1F('data', 'data', 10, 60, 260)
   for j in range(nPDs):
      PD = PDs[j]
      chain = TChain("Events")
      for file in dict_yml[PD]['files']:
         chain.Add(file)
      chain.SetProof()
      hist_name = PD.split('_')[0]
      dathists[j] = TH1F('data', 'data', 10, 60, 260)
      chain.Project('data', 'Z_pt', "(lep_category>3 && lep_category < 6 && Z_pt>60 && met_pt>40 && Z_mass>81 && Z_mass<101 && ngood_jets<2 && ngood_bjets==0)")
      dathists[j].SetName(hist_name)
      chain.Reset()
      chain.Delete()
      dat.Add(dathists[j])   
   
   cOutput = TCanvas("cOutput", "cOutput", 500, 500)
   cOutput.SetFillStyle(4000)
   gStyle.SetOptStat(0)

   stk.Draw("hist")
   dat.SetMarkerStyle(20)
   dat.SetMarkerColor(kBlack)
   dat.SetMarkerSize(0.5)
   dat.Draw("Esame")
   lg = gPad.BuildLegend(0.7, 0.7, 0.9, 0.9, "", "fNDC")
   lg.SetNColumns(1)
   lg.SetFillStyle(0)
   lg.SetBorderSize(0)
   pad = cOutput.cd()
   l = pad.GetLeftMargin()
   t = pad.GetTopMargin()
   r = pad.GetRightMargin()
   b = pad.GetBottomMargin()
   lab1 = TLatex()
   lab1.SetTextSize(0.03)
   lab1.SetTextAlign(11)
   lab1.SetTextFont(42)
   cmsTag = '#bf{CMS Work in Progress}'
   lab1.DrawLatexNDC(l+0.01, 1-t+0.015, cmsTag)
   lab2 = TLatex()
   lab2.SetTextSize(0.03)
   lab2.SetTextAlign(11)
   lab2.SetTextFont(42)
   cmsTag = 'll ch., 41.5 fb^{-1} (13 TeV)'
   lab1.DrawLatexNDC(l+0.55, 1-t+0.015, cmsTag)
   cOutput.SetLogy()
   cOutput.SaveAs("plot.pdf")

   for dathist in dathists:
      dathist.Delete()
   for hist in hists:
      hist.Delete()
   dat.Delete()
   stk.Delete()
   prf.Close()
   prf.Delete()   
test()
