#include "etc.h"

QList<double> qStrToQList(QString str_x)
{
    QString buff;
    QList<double> xData;
    bool isDouble;

    isDouble = false;
    xData.clear();
    buff.clear();

    for(int i=0; i<str_x.size(); i++){
        if(!str_x.at(i).isDigit() and !str_x.at(i).isSpace() and !str_x.at(i).isPunct()){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Data set is incorrect!");
            messageBox.setFixedSize(500,200);
        }
        else if(str_x.at(i).isDigit()){
            buff.append(str_x.at(i));
        }
        else if(str_x.at(i) == QChar('.') and isDouble){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Data set is incorrect!");
            messageBox.setFixedSize(500,200);
        }
        else if(str_x.at(i) == QChar('.') and !isDouble){
            buff.append(str_x.at(i));
            isDouble = true;
        }
        else if(str_x.at(i) == QChar(',')){
            try{
                double a = buff.toDouble();
                xData.append(a); //1, 2, 3, 4, 5, 6, 7
            }
            catch(...){
                QMessageBox messageBox;
                messageBox.critical(0,"Error","Data set is incorrect!");
                messageBox.setFixedSize(500,200);
            }
            isDouble = false;
            buff.clear();
        }
        if(i == str_x.count()-1 and str_x.at(i).isDigit()){
            try{
                double a = buff.toDouble();
                xData.append(a);
            }
            catch(...){
                QMessageBox messageBox;
                messageBox.critical(0,"Error","Data set is incorrect!");
                messageBox.setFixedSize(500,200);
            }
        }
        std::cout << str_x.count()-1 << std::endl;

    }

    return xData;
}
