#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QDateEdit>
#include<QUuid>
#include <random>
#include <time.h>
#include"contrat.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabemploye->setModel(tmpemploye.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QDate date_debut= ui->dateEdit_4->date();
    QDate date_fin=ui->dateEdit_5->date();
    int salaire=ui->lineEdit_20->text().toInt();
    int ref=ui->lineEdit_21->text().toInt();
    int jourabs=0;
    int idemp=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit->text();
   QString prenom=ui->lineEdit_2->text();
   QString departement=ui->lineEdit_4->text();
   employe e(idemp,jourabs,nom,prenom,departement);
   contrat c(date_debut,date_fin,ref,idemp,salaire);
   bool test=(e.ajouter()&& c.ajouter());
if(test)
{


    ui->tabemploye->setModel(tmpemploye.afficher());

    QMessageBox::information(nullptr,QObject::tr("Ajout"),"Ajout effectué");

    }
    else QMessageBox::information(nullptr,QObject::tr("Ajout"),"ajout impossible");
}


void MainWindow::on_pushButton_2_clicked()
{
    int idemp =ui-> lineEdit_5->text().toInt();
    bool test=tmpemploye.supprimer(idemp);
    if(test)
    {ui->tabemploye->setModel(tmpemploye.afficher());
   QMessageBox::information(nullptr,QObject::tr("suppression"),"employé supprimé");
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    int idemp =ui-> lineEdit_5->text().toInt();
   int jourabs=ui->lineEdit_7->text().toInt();
   QString nom=ui->lineEdit_8->text();
   QString prenom=ui->lineEdit_9->text();
   QString departement=ui->lineEdit_10->text();
   QDate date_fin=ui->dateEdit->date();
   int salaire=ui->lineEdit_6->text().toInt();
   contrat c;
   employe e;

 bool y= (e.update(nom,prenom,departement,jourabs,idemp)or c.update(date_fin,salaire,idemp));

 if(y)

 {ui->tabemploye->setModel(tmpemploye.afficher());
 QMessageBox::information(nullptr,QObject::tr("modification employe"),"modification fait");
 }
 else{
     QMessageBox::information(nullptr,QObject::tr("modification employe"),"modification pas fait");
     }
}

void MainWindow::on_pushButton_4_clicked()
{

}
