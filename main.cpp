#include "mainwindow.h"
#include <QApplication>
#include "includes.h" //общий файл с внешними библиотеками
//#include "lab1_src/lhistcreator2d.h"
//#include "lab1_src/lex1.h"
//#include "lab1_src/lex1_p2.h"
//#include "lab1_src/lex1_p3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();
    return a.exec();
}
