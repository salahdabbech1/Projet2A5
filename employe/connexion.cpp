#include "connexion.h"

connexion::connexion()
{
}
bool connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("salah");
db.setPassword("esprit20");
if(db.open())
    test=true;
else throw QString("erreur"+test);
return test;
}
void connexion::fermerConnexion()
{db.close();}
