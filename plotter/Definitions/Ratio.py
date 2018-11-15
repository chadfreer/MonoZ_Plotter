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
   MC = TH1F('h', 'h', 20, 60, 260)
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
      #hist_name = dataset.split('_')[0]
      hists[i] = TH1F(name, name, 20, 60, 260)
      chain.Project(name, 'Z_pt', "puWeight * lumiWeight * (lep_category==3 && Z_pt>60 && met_pt>40 && Z_mass>81 && Z_mass<101 && ngood_jets<2 && ngood_bjets==0)")
      hists[i].SetName(name)
      chain.Reset()
      chain.Delete()
      if dataset == 'TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8': hists[i].SetFillColor(kGray+1)
      if dataset == 'DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8': hists[i].SetFillColor(kPink+1)
      if dataset == 'WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8': hists[i].SetFillColor(kTeal+2)
      if dataset == 'ZZTo2L2Nu_13TeV_powheg_pythia8': hists[i].SetFillColor(kOrange-2)
      if dataset == 'WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8': hists[i].SetFillColor(kAzure-4)
      hists[i].Scale(41.5)
      stk.Add(hists[i])
      MC.Add(hists[i])

   dathists = [None] * nPDs
   dat = TH1F('data', 'data', 30, 0, 300)
   for j in range(nPDs):
      PD = PDs[j]
      chain = TChain("Events")
      for file in dict_yml[PD]['files']:
         chain.Add(file)
      chain.SetProof()
      hist_name = PD.split('_')[0]
      dathists[j] = TH1F('data', 'data', 30, 0, 300)
      chain.Project('data', 'Z_pt', "(lep_category==3 && Z_pt>60 && met_pt>40 && Z_mass>81 && Z_mass<101 && ngood_jets<2 && ngood_bjets==0)")
      dathists[j].SetName(hist_name)
      chain.Reset()
      chain.Delete()
      dat.Add(dathists[j])   
   
   cOutput = TCanvas("cOutput", "cOutput", 500, 500)
   cOutput.SetFillStyle(4000)
   p1 = TPad("p1", "p1", 0, 0.23, 1, 1)
   p2 = TPad("p2", "p2", 0, 0.05, 1, 0.23)
   p1.SetBottomMargin(0)
   p2.SetTopMargin(0.05)
   p2.SetBottomMargin(0.20)
   p2.SetBorderMode(0)
   cOutput.Draw()
   cOutput.cd()
   p1.Draw()
   p2.Draw()
   p1.cd()
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
   p1.SetLogy()

   p2.cd()
   dat.Divide(MC)   
   dat.SetTitleSize(0.5,"t")
   #dat.GetXaxis().SetLabelSize(.1)
   #dat.GetXaxis().SetTitleSize(.12)
   #dat.GetXaxis().SetTitleOffset(0.7)
   #dat.GetXaxis().SetTitle(axis[Branch_count])
   #dat.GetYaxis().SetTitle("#frac{Data}{#SigmaMC}")
   #dat.GetYaxis().SetTitleSize(.12)
   #dat.GetYaxis().SetTitleOffset(0.35)
   #dat.GetYaxis().SetLabelSize(0.1)
   dat.SetMaximum(2)
   dat.SetMinimum(0)
   dat.SetStats(0)
   dat.SetMarkerColor(kBlack)
   dat.SetLineColor(kBlack)
   dat.SetTitle("")
   dat.Draw()
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
