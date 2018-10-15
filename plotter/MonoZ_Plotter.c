//MonoZ plotting tool (Used for VBS currently)
//Chad Freer Jun, 2017
/*
 Data summary in nice table because code is hard to read well
 Backgrounds=================================================================
 Data                       xSec                nGen            color
 ZZTo2L2Nu                   0.564               8842475         kOrange-2
 TTTo2L2Nu                   87.3                77853420        kGray+1
 WWTo2L2Nu                   12.178              1999000         kTeal+2
 WZTo3LNu                4.42965*1.109           1993200         kAzure-4
 DYJetsToLL          4958. * (1921.8*3/4958.)    49144274        kPink+1
 DYJetsToLL50To100   354.6*(1921.8*3/5938)       20907519        kPink+1
 DYJetsToLL100To250  83.05*(1921.8*3/5938)       2040596         kPink+1
 DYJetsToLL250To400  3.043*(1921.8*3/5938)       423976          kPink+1
 DYJetsToLL400To650  .3921*(1921.8*3/5938)       432056          kPink+1
 DYJetsToLL650Toinf  .03823*(1921.8*3/5938)      430691          kPink+1
 Signals======================================================================
 ZZJJ_ZZTo2L2Nu              0.002618            100000          Red
 LLDMMx2Heavy            0.027605911000284       47032           Blue
 LLDMMx2Light            0.028245862461968       42885           Black
 End===========================================================================*/

//Includes
#include <stdio.h>
#include "TAttFill.h"
//#include "iostream.h"

//My tools and Paramters
#include "Definitions/Utils.h"
#include "Definitions/Variables.h"
#include "Definitions/Cuts.h"
#include "Definitions/Output.h"

//Different Plotting methods
#include "Plot_types/Distributions.h"			//Stacked Histograms
#include "Plot_types/Normalized.h"			//Normalized Background vs Signal Histograms
#include "Plot_types/Significance.h"			//Significance for distributions
#include "Plot_types/NminusOne.h"			//Make N-1 plots
#include "Plot_types/HeatMap.h"				//HeatMap for testing variables against each other
#include "Plot_types/Cutflow.h"				//Cutflow map
#include "Plot_types/Stack_Ratio.h"			//Data MC comparison

//Statics
static int Total_count = 41;    //total number of variables for loops
static TString workspace;

//Main Plotter
void MonoZ_Plotter(){
    //Intro to program
    ifstream myfile ("Params.txt");
    if (myfile.is_open()){
       while ( !myfile.eof() ){
          getline (myfile,workspace,'\t');
          //getline (myfile,var1,'\t');
          //getline (myfile,var2,'\t');
          //getline (myfile,var3,'\t');
          cout << workspace << endl:;
       }
       myfile.close();
    }
    else cout << "Unable to open file" << endl;	
    //Set up the curent files to choose from
	
	
    //begin the questioning
    cout << Intro << endl;
    cout << Charmeleon << endl;
    TString Style ;//= "Stack";
    TString Plot ;//
    TString Plot2 ; // Need a second input for the Heat Map
    int Plot_int =-1;
    int Plot2_int = -1;
    TString dir = "Plots/";
	//TCanvas *cc;
    
    //Choose plotting parameters
    cout << "Choose one of the plotting styles --> Stack, Norm, Sig, N-1, Heat, Cutflow, Ratio" << endl;
    cin >> Style;
    
    if (Style == "Cutflow"){
        cout << "you have chosen cutflow. I don't need any more from you" << endl << spacer << endl;
        TCanvas *cc = Cutflow_plots();
        cc->SaveAs(dir+"Cutflow.pdf");
        cout << "Saving " << dir << "Cutflow.pdf" << endl;
        delete cc;
		return 0;
    }
    
    cout << "Choose which variable to plot (type Options to see all variables)" << endl;
    cin >> Plot;
    if (Plot == "Options"){
        cout << spacer << endl << Name_Options << endl << spacer << endl << "Please select which variable to plot" << endl;
        cin >> Plot;
    }
    if (Style != "Cutflow") cout << "You have chosen to plot " << Plot << " using the " << Style << " style. Now shut up I'm working..." << endl;
    
    //Get second variable for Heat Map
    if (Style == "Heat"){
        cout << "For Heat Map I need a second input variable" << endl;
        cin >> Plot2;
    }
    
    if (Style != "Stack" && Style != "Norm" && Style != "Sig" && Style != "N-1" && Style != "Heat" && Style != "Ratio"){
        cout << "WARNING: You have not chosen a valid Style type!!! \nI will default to Stack" << endl;
        Style = "Stack";
    }
    
    //Check to see if plot is a valid option
    if (Plot != "all"){//START: 1
        for (int Branch_count = 0 ; Branch_count < Total_count; Branch_count++){
			if (Plot == variable[Branch_count]) Plot_int = Branch_count;
            if (Style == "Heat" && Plot2 == variable[Branch_count]) Plot2_int = Branch_count;
        }

        //second input for Heat did not make sense
        if (Style == "Heat" && Plot2_int == -1){
            cout << "Something in the input was wrong! I'm leaving you now." << endl;
            return 0;
        }
        
        //For individual plots
        if (Plot_int != -1){//START: 2
            cout << "I have found the variable " << variable[Plot_int] << "! Good job you know your variables :)" << endl << spacer <<  "\nPrinting # of events per process" << endl;
            if (Style == "Stack"){//START: 3
                TCanvas *cc = Distribution_plots(Plot_int);
				cc->SaveAs(dir+variable[Plot_int]+".pdf");
				cout << "Saving " << dir << variable[Plot_int] << ".pdf" << endl;
				delete cc;
            }else if (Style == "Norm"){//ELSE: 3
                TCanvas *cc = Normalized_plots(Plot_int);
				cc->SaveAs(dir+variable[Plot_int]+".pdf");
				cout << "Saving " << dir << variable[Plot_int] << ".pdf" << endl;
				delete cc;
            }else if (Style == "Sig"){//ELSE: 3
                TCanvas *cc = Significance_plots(Plot_int);
				cc->SaveAs(dir+variable[Plot_int]+".pdf");
				cout << "Saving " << dir << variable[Plot_int] << ".pdf" << endl;
				delete cc;
            }else if (Style == "N-1"){//ELSE: 3
                TCanvas *cc = NminusOne_plots(Plot_int);
				cc->SaveAs(dir+variable[Plot_int]+".pdf");
				cout << "Saving " << dir << variable[Plot_int] << ".pdf" << endl;
				delete cc;
            }else if (Style == "Heat"){//ELSE: 3
                TCanvas *cc = Heat_plots(Plot_int, Plot2_int);
				cc->SaveAs(dir+variable[Plot_int]+".pdf");
				cout << "Saving " << dir << variable[Plot_int] << ".pdf" << endl;
				delete cc;
			}else if (Style == "Ratio"){//ELSE: 3
				TCanvas *cc = Distribution_Ratio_plots(Plot_int);
				cc->SaveAs(dir+variable[Plot_int]+".pdf");
				cout << "Saving " << dir << variable[Plot_int] << ".pdf" << endl;
				delete cc;
			}//END: 3
        }//END: 2
    }//END: 1
    
    //If all plots is selected. Heat will use all variable combinations! (This will be a LOT of plots and will take a long time)
    if (Plot == "all"){//START: 1
        for (int Branch_count = 0 ; Branch_count < Total_count; Branch_count++){//START: 2
            if (Style == "Stack"){//START: 3
                TCanvas *cc = Distribution_plots(Branch_count);
				cc->SaveAs(dir+variable[Branch_count]+".pdf");
				cout << "Saving " << dir << variable[Branch_count] << ".pdf" << endl;
				delete cc;
            }else if (Style == "Norm"){//ELSE: 3
                TCanvas *cc = Normalized_plots(Branch_count);
				cc->SaveAs(dir+variable[Branch_count]+".pdf");
				cout << "Saving " << dir << variable[Branch_count] << ".pdf" << endl;
				delete cc;
            }else if (Style == "Sig"){//ELSE: 3
                TCanvas *cc = Significance_plots(Branch_count);
				cc->SaveAs(dir+variable[Branch_count]+".pdf");
				cout << "Saving " << dir << variable[Branch_count] << ".pdf" << endl;
				delete cc;
            }else if (Style == "N-1"){//ELSE: 3
                TCanvas *cc = NminusOne_plots(Branch_count);
				cc->SaveAs(dir+variable[Branch_count]+".pdf");
				cout << "Saving " << dir << variable[Branch_count] << ".pdf" << endl;
				delete cc;
			}else if (Style == "Ratio"){//ELSE: 3
				TCanvas *cc = Distribution_Ratio_plots(Branch_count);
				cc->SaveAs(dir+variable[Branch_count]+".pdf");
				cout << "Saving " << dir << variable[Branch_count] << ".pdf" << endl;
				delete cc;
			}else if (Style == "Heat"){//ELSE: 3
                dir = variable[Branch_count];
                for (int Branch_count2 = 0 ; Branch_count2 < Total_count; Branch_count2++){//START: 4
					if (Branch_count2 > Branch_count) {//START: 5
						TCanvas *cc = Heat_plots(Branch_count, Branch_count2);
						cc->SaveAs(dir+variable[Branch_count2]+".pdf");
						cout << "Saving " << dir << variable[Branch_count] << ".pdf" << endl;
						delete cc;
					}//END: 5
                } //END: 4
            } //END: 3
        } //END: 2
    } //END: 1
	
    if (Plot != "all" && Plot_int == -1) {
        cout << "Good job you broke me... I am quitting because input was nonsense" << endl;
        return 0;
    }
    cout << spacer << endl << "I have finished all of my business and plots have been made" << endl;
}

