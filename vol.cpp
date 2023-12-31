//
// Created by stude on 30/12/2023.
//

#include "vol.h"
Passager p;
string nom;
string prenom;
string adresse;
int age;
int tele;
int Vol::getIdVol(){
    return idV;
}

int Vol::getSizeListPassager() {
    return passagers.size();
}
// Get the current date
// year
int Vol::getCurrentYear()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentyear = now->tm_year + 1900;
    return currentyear;
}
// month
int Vol::getCurrentmonth()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentmonth = now->tm_mon + 1;
    return currentmonth;
}
// day

int Vol::getCurrentday() {
    time_t t = time(0);
    struct tm * now = gmtime(& t);
    return now->tm_mday;
}
void Vol::saisirDateDipart(){
    int i = 1;
    do
    {
        cout << "--->Entrer la date de depart (DD MM YYYY):  \n ";
        int dd, mm, yy;
        cin >> dd >> mm >> yy;
        // Date validation
        if ((dd >= 1 && dd <= 31)  && (mm >= 1 && mm <= 12) && (yy < 10000))
        {
            dateDipart.tm_mday = dd;
            dateDipart.tm_mon = mm;
            dateDipart.tm_year = yy;
            i = 1;
        }
        else
        {
            cout << "[ incorrect  date. S'il veut plait entrer  la date correct. ]\n";
            i = 2;
        }
    } while (i == 2);

}
void Vol::saisirDateArrivee() {
    int i = 1;
    do
    {
        cout << "--->Entrer la date d'arrivee  (DD MM YYYY):  \n ";
        int da, ma, ya;
        cin >> da >> ma >> ya;
        // Date validation
        if ((da >= 1 && da <= 31) && (ma >= 1 && ma <= 12) && (ya >= 1900 && ya < 10000) &&
        // Tester si le date d'arrivee est  supérieux à date de depart
            ((ya > dateDipart.tm_year) || (ya == dateDipart.tm_year && ma > dateDipart.tm_mon) ||
             (ya == dateDipart.tm_year && ma == dateDipart.tm_mon && da > dateDipart.tm_mday)))
        {
            dateArrivee.tm_mday = da;
            dateArrivee.tm_mon = ma;
            dateArrivee.tm_year = ya;
            i = 1;
        }
        else
        {
            cout << "[ Incorrect date. Please enter a correct date after the departure date.]\n";
            i = 2;
        }
    } while (i == 2);
}
void Vol::saisirVol()
{
    avion.saisirAvion();
    cout << "\n=========== Saisir Vol ===========\n";
    cout << "--->Entrer l'id de vol :\n ";
    cin >> idV;
    saisirDateDipart();
    saisirDateArrivee();
    cout<<"--->Entrer la distination de vol :\n";
    cin>>destination;

}
//-----------------------------------------------------------affichage-------------------------------------------//
void Vol::afficherVol()
{
    cout << "\n============ Afficher Vol Num "<<idV<<", En direction  "<<destination<<" ===========\n";
    cout << "\n\t id vol : " << idV;
    avion.afficherAvion();
    cout << "\n\t date de depart : " << dateDipart.tm_mday << "/" << dateDipart.tm_mon << "/" << dateDipart.tm_year << " \n\t date d'arrivee :" << dateArrivee.tm_mday << "/" << dateArrivee.tm_mon << "/" << dateArrivee.tm_year;
    cout << "\n===========Fin affichage de vol==========================\n";
}

bool Vol::ControlNbPassager(int nb){
    int size=getSizeListPassager();
    int res=size+nb;
    int rest=avion.getCapacite()-size;
    if(avion.getCapacite()<res){
        cout<<"\nLe nombre de place restant est "<<rest<<" NB[ la capacite :"<<avion.getCapacite()<<"]\n";
        return true;

    } else{
        return false;
    }

}

bool Vol::testerExictencePassager(int idp){
    for (auto p: passagers) {
                if(idp==p.getId()){
                    return true;
                }
    }
    return false;
}

void Vol::AjouterPassager(int i) {
    cout<<"\n ====== Entrer les information de nouveau Passager ===============\n";
    cout << "--->Entrer le nom de passager \n";
    cin >> nom;
    cout << "--->Entrer le prenom de passager \n";
    cin >> prenom;
    cout << "--->Entrer l'adress de passager \n";
    cin >> adresse;
    cout << "--->Entrer l'age de passager \n";
    cin >> age;
    cout << "--->Entrer le numero de telephon de passager \n";
    cin >> tele;
    p.SetPassager(i,nom,prenom,adresse,age,tele);
    passagers.push_back(p);
}
void Vol::AfficherPassagers(){
    for(auto &p:passagers){
        p.afficherPassager();
    }
}
void Vol::AfficherUnPassager(int id){
    for(auto p :passagers){
        if(p.getId()==id){
            p.afficherPassager();
        }
    }
}
//cette fonction pour ajouter vol san repete saisie d'id
void Vol::AjouterVol(int IDV){
    idV=IDV;
    avion.saisirAvion();
    cout << "\n=========== Saisir Vol ===========\n";
    saisirDateDipart();
    saisirDateArrivee();
    cout<<"--->Entrer la distination de vol :\n";
    cin>>destination;
}
int nage,ntele;
string nnom,nprenom,nadresse;
void Vol::ModifierInformationPassager(int id){
    for(auto &p:passagers){
        if (p.getId()==id){
            cout << "--->Entrer le nouveau nom de passager \n";
            cin >> nnom;
            cout << "--->Entrer le nouveau prenom de passager \n";
            cin >> nprenom;
            cout << "--->Entrer le nouveau adresse de passager \n";
            cin >> nadresse;
            cout << "--->Entrer le nouveau age de passager \n";
            cin >> nage;
            cout << "--->Entrer le nouveau numero de telephon de passager \n";
            cin >> ntele;
            p.modifierInformationPassager(nnom,nprenom,nadresse,nage,ntele);
        }
    }
}
bool Vol::AfficherPassagerMoin10ans(){
    for(auto &p:passagers){
        if (p.getAge()<10){
            p.afficherPassager();
            return true;
        }
    }
    return false;
}