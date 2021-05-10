void projection(){
	
	// These are the y axis bins you want to slice on
	int lowbin = 0;
	int uppbin = 1000;
    
    //Edit 7 Feb, conversion between bins to degrees
//    Bin 100 - 18 deg OR 0.031 Rad
//    Bin 200 - 36 deg OR 0.063 Rad
//    Bin 300 - 54 deg OR 0.094 Rad
//    Bin 400 - 72 deg OR 0.126 Rad
//    Bin 500 - 90 deg OR 0.157 Rad
//    Bin 600 - 108 deg OR 0.188 Rad
//    Bin 700 - 126 deg OR 0.220 Rad
//    Bin 800 - 144 deg OR 0.251 Rad
//    Bin 900 - 162 deg OR 0.283 Rad
//    Bin 1000 - 180 deg OR 0.314 Rad
    //End of edit
	
	TFile *fin = new TFile( "222Rn_120Sn_hists.root" ); // input file with histograms
	TFile *fout = new TFile( "0-1000_222.root", "RECREATE" ); // output file to save new projection
	
	TH2F *h2 =  (TH2F*)fin->Get( "AnEn" ); // this is the 2D hist of energy vs emission angles

    //Updated hist name 8.2.21
	TH1F *projAnEn = (TH1F*) h2->ProjectionX( "projAnEn", lowbin, uppbin );
    // do the slicing by bin number
    projAnEn->SetTitle("^{222}Rn Projection of Energy for Angles 0-180#circ");
    
    //Edit 8.2.21
    projAnEn->GetXaxis()->SetTitle("Energy [keV]");
    projAnEn->GetYaxis()->SetTitle("Counts per keV");
    //End of edit
    
    projAnEn->Draw();
	// Write to output
	fout->cd();
    projAnEn->Write();
	
	return;
	
}
