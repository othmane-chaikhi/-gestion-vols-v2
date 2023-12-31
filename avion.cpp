#include "avion.h"

Avion::Avion() {
    codeAvion="xxxx";
    pilot="xxxx";
    modele=0000;
    capacite=0;
    nbVolsAssure=0;
    dateFabrication={0,0,0,00,00,0000};
}
int Avion::getCapacite(){
    return capacite;
}
// year
int Avion::getCurrentYear()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentyear = now->tm_year + 1900;
    return currentyear;
}
// month
int Avion::getCurrentmonth()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentmonth = now->tm_mon + 1;
    return currentmonth;
}
// day
int Avion::getCurrentday()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentday = now->tm_mday;
    return currentday;
}
void Avion::saisirDatefab(){
    int i;
    // Control de saisie de date
    do
    {
        cout << "--->Entrer la date de fabrication avion (DD MM YYYY):  \n ";
        int dd, mm, yy;
        cin >> dd >> mm >> yy;

        // Date validation
        if ((dd >= 1 && dd <= 31) && (mm >= 1 && mm <= 12) && (yy >= 1900 && yy <= getCurrentYear()))
        {
            dateFabrication.tm_mday = dd;
            dateFabrication.tm_mon = mm;
            dateFabrication.tm_year = yy;
            i = 1;
        }
        else
        {
            cout<<"[ incorrect  date. S'il veut  entrer  correct date.]\n";
            i = 2;
        }
    } while (i == 2);
};
void Avion::saisirAvion(){
    cout << "\n=========== Saisir Avion de vol ===========\n";
    cout << "--->Entrer le code d'avion :\n";
    cin >> codeAvion;
    cout << "--->Entrer le pilot d'avion :\n";
    cin >> pilot;
    cout << "--->Entrer le modele d'avion : \n";
    cin >> modele;
    cout << "--->Entrer la capacite d'avion :\n";
    cin >> capacite;
    // date de fabrication
    saisirDatefab();
    cout << "--->Entrer le nombre de vols assures d'avion : \n";
    cin >> nbVolsAssure;
}
void Avion::afficherAvion()
{
    cout << "\n==============Afficher Avion==============\n";
    cout << "{\n \t code avion : " << codeAvion << "\n \t pilot : " << pilot << "\n \t modele : " << modele << "\n \t capacite : " << capacite << "\n \t date de fabrication : " << dateFabrication.tm_mday << "/" << dateFabrication.tm_mon << "/" << dateFabrication.tm_year << "\n \t nombre de vols assures : " << nbVolsAssure << "\n } ";
}
/*bool Avion::ControlCapacitenb(int nbPassager){

    if ((nbPassager>capacite) || (capacite+nbPassager<0) ){
        cout<<"Le nombre de passager est hors capacite avion NB[ la capacite :"<<capacite<<"]\n";
        return true;
    } else{
        if(nbPassager==capacite){
            cout<<"Le nombre de passagers est equivalent a la capacite de l'avion, donc le vol est plein.\n";
        }
        return false;
    }
}*/
//size+nbpassager<= capacite
int nbres;
/*bool Avion::ControlCapacite(int size,int nb){
   nbres=capacite-size;
    if (nbres>capacite){
        int rst=capacite-size;
        cout<<"\nLe nombre de place restant est "<<rst<<" NB[ la capacite :"<<capacite<<"]\n";
        return true;
    }else if(size==capacite){
        cout<<"\nle vol est plein.\n";
        return false;
    }
    else{
        return false;
    }
}*/