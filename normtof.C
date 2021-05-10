{
    gStyle->SetOptStat(0);
    
    TFile *_file0 = TFile::Open("222Rn_120Sn_hists.root");
    TFile *_file1 = TFile::Open("224Rn_120Sn_hists.root");
    TFile *_file2 = TFile::Open("226Rn_120Sn_hists.root");
    
    TH1F *hist0 = (TH1F*)_file0->Get("FT");
    TH1F *hist1 = (TH1F*)_file1->Get("FT");
    TH1F *hist2 = (TH1F*)_file2->Get("FT");
    
    hist0->Scale(1.0/hist0->Integral());
    hist1->Scale(1.0/hist1->Integral());
    hist2->Scale(1.0/hist2->Integral());
    
    TCanvas *c = new TCanvas("C","Time of Flight", 800,600);
    
    hist1->GetXaxis()->SetRangeUser(0.5*1e-9,2.0*1e-9);
    hist1->Draw("hist");
    hist0->Draw("hist same");
    hist2->Draw("hist same");
    
    hist0->SetLineColor(kRed-4);
    hist1->SetLineColor(kBlue-7);
    hist2->SetLineColor(kGreen-3);
    
    hist0->SetLineWidth(2);
    hist1->SetLineWidth(2);
    hist2->SetLineWidth(2);
    
    TLegend *Leg = new TLegend(0.7,0.7,0.9,0.9);
    Leg->AddEntry(hist0,"^{222}Rn");
    Leg->AddEntry(hist1,"^{224}Rn");
    Leg->AddEntry(hist2,"^{226}Rn");
    
    Leg->Draw("same");
    
    c->SaveAs("NormFT.pdf");
}
