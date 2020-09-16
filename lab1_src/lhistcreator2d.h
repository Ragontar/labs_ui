#ifndef LHISTCREATOR_H
#define LHISTCREATOR_H
#include "includes.h"

class LHistCreator2D
{
private:
    QList<double> x, y; //Datasets
    TH2D* hist; //Histo of (X,Y)
    TCanvas* c1; //Canvas for histo
    TString hist_name = ""; //Histo filename
public:
    LHistCreator2D();
    LHistCreator2D(QList<double>, QList<double>); //Setting constructor. Args: X, Y
    LHistCreator2D(QList<double>, QList<double>, TString); //Setting constructor. Args: X, Y, filename
    bool SetData(QList<double>, QList<double>); //Set data. Args: X, Y
    QList<double> GetData(); //Get data. Data format: {(x1, y1); (x2, y2); ...}
    TH2D* GetHist(); //Get histo
    TCanvas* GetCanvas(); //Returns c1
    void SetCanvas(TCanvas*);
    bool SaveHist(TString); //Saves histo as png. Args: path
    bool SaveHist(); //Saves histo as png with std path
    bool SetHistName(TString); //Sets histo name
};

#endif // LHISTCREATOR_H
