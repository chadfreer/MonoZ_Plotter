import yaml
from ROOT import *

gROOT.SetBatch(1)

#with open('Definitions/ROOTfiles.yml', 'r') as f_yml:
#    dict_yml = yaml.load(f_yml)

def test(dataset,title,nBins,xlow,xhi))
   with open('ROOTfiles.yml', 'r') as f_yml:
       dict_yml = yaml.load(f_yml)
   TProof.Open("")
   chain = TChain("Events") 
   for file in dict_yml[dataset]['files']:
      chain.Add(file)
   chain.SetProof()
   #h = TH1F('h', 'h', 1000, 0, 1000)
   chain.Project('h', 'Z_pt', "weight * (met_pt>90 && abs(Z_mass-91.1876)<8)")
   #h.Draw()
   #gPad.SaveAs('test.pdf')
   return h
test()
