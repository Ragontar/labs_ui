#include "lhistcreator2d.h"
/*
 *
 * РЕАЛИЗАЦИЯ КОНСТРУКТОРОВ
 *
 */
LHistCreator2D::LHistCreator2D()
{

}
LHistCreator2D::LHistCreator2D(QList<double> xData, QList<double> yData){
    this->hist = new TH2D("","",30,0,0,30,0,0);
    this->c1 = new TCanvas();

    if(xData.size() == 0){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Data set is empty!");
        messageBox.setFixedSize(500,200);
    }
    else if(xData.size() != yData.size()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Data set is incorrect!");
        messageBox.setFixedSize(500,200);
    }
    else{
        std::cout << std::endl;
        for(int i=0; i<xData.size(); i++){
            this->hist->Fill(xData[i], yData[i]);
            std::cout << "(" << xData[i] << "; " << yData[i] << ")\n";
        }

        this->hist->SetMarkerStyle(22);
        this->hist->SetMarkerColor(2);
        this->hist->Draw("P");
    }

}
LHistCreator2D::LHistCreator2D(QList<double> xData, QList<double> yData, TString name){
    this->hist = new TH2D(name,name,3000,0,0,3000,0,0);
    this->c1 = new TCanvas();
    this->hist_name = name;

    if(xData.size() == 0){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Data set is empty!");
        messageBox.setFixedSize(500,200);
        return;
    }
    else if(xData.size() != yData.size()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Data set is incorrect!");
        messageBox.setFixedSize(500,200);
        return;
    }
    else{
        std::cout << std::endl;
        for(int i=0; i<xData.size(); i++){
            this->hist->Fill(xData[i], yData[i]);
            std::cout << "(" << xData[i] << "; " << yData[i] << ")\n";
        }

        this->hist->SetMarkerStyle(22);
        this->hist->SetMarkerColor(2);
        this->hist->SetMarkerSize(2);
        this->hist->Draw("P");
    }

}

/*
 *
 * РЕАЛИЗАЦИЯ МЕТОДОВ
 *
 */
bool LHistCreator2D::SaveHist(){
    char wd[1024];
    getwd(wd);
    TString path = wd;
    if(this->hist_name == ""){
        this->c1->SaveAs(path + "/hist.png");
    }
    else{
        this->c1->SaveAs(path + "/" + this->hist_name + ".png");
    }

    return 1;
}
bool LHistCreator2D::SetData(QList<double> xData, QList<double> yData){
    this->x = xData;
    this->y = yData;
    return 1;
}
QList<double> LHistCreator2D::GetData(){
    QList<double> ret;
    for(int i=0; i<this->x.size(); i++){
        ret[i] = this->x[i];
        i++;
        ret[i] = this->y[i-1];
    }

    return ret;

}
TH2D* LHistCreator2D::GetHist(){
    return this->hist;
}

TCanvas *LHistCreator2D::GetCanvas()
{
    return this->c1;
}

void LHistCreator2D::SetCanvas(TCanvas* canv)
{
    this->c1 = canv;
}
bool LHistCreator2D::SaveHist(TString path){
    if(this->hist_name == ""){
        this->c1->SaveAs(path + "/hist.png");
    }
    else{
        this->c1->SaveAs(path + "/" + this->hist_name + ".png");
    }
    return 1;
}
bool LHistCreator2D::SetHistName(TString name){
    this->hist_name = name;
    return 0;
}
