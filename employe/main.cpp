#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
#include "employe.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    connexion c;

bool y=c.ouvrirConnexion();
    if(y)
    {MainWindow w;
     w.show();

return a.exec();}
}
