#include "mainwindow.h"
#include <QApplication>
#include "includes.h" //общий файл с внешними библиотеками
#include "lhistcreator2d.h"
#include "lex1.h"
#include "lex1_p2.h"

//По-идее, все должно быть готово. Можно начинать делать проект.
int main(int argc, char *argv[])
{
    QList<double> xData, yData;
    xData = {1, 2, 3, 4, 5, 6};
    yData = {2*1+3, 2*2+3+1, 2*3+3+2, 2*4+3-1, 2*5+3, 2*6+3};


    QApplication a(argc, argv);
    //TH1* hist1 = new TH1();
    //TH1* hist = new TH2D();
    //LHistCreator2D* HC = new LHistCreator2D(xData, yData);
    //HC->SetHistName("fok");
    //HC->SaveHist();
    LEx1_p2* dcp = new LEx1_p2(xData, "lab2_hist");
    QList<double> res;
    //dcp->setData(xData, yData);
    res = dcp->MNK();
    QMessageBox messageBox;
    //QString aaaa = QString::number(res[0]) + "   " + QString::number(res[1]);
    QString aaaa = "k = " + QString::number(res[0]) +
            "   b = " + QString::number(res[1]) + "\n" +
            "Cov = " + QString::number(dcp->getCov()) + "\n" +
            "Corr = " + QString::number(dcp->getCorr()) + "\n"
            "T = " + QString::number(dcp->getT()) + "\n";
    messageBox.critical(0,"Output", aaaa);
    messageBox.setFixedSize(500,200);
    std::cout << "\n\n PIZDAAAAAAAAAA! \n\n";

    //MainWindow w;
    //w.show(); //пизда рулю
    //return a.exec();
    return 0;
}
