#include <iostream>
#include "Passager.h"
#include "avion.h"
#include "vol.h"
#include "Vols.h"
using namespace std;

int main() {
    Vols vols;
    Vol v;
    int idv,idAv,idvaff,idaff1,idpa,idpa2,modp,mvd,supv;
    int choix;
    do {
            cout<<"\n=============== Menu ================\n";
            cout<<"\n Choisir Le nombre de votre choix \n";
            cout<<"[1]:Ajouter des Passager au Vol\n";
            cout<<"[2]:Ajouter un Vol\n";
            cout<<"[3]:Afficher Les Passager au Vol\n";
            cout<<"[4]:Afficher  un Vol\n";
            cout<<"[5]:Tester si  un Passager existe au Vol\n";
            cout<<"[6]:Afficher le vol est destination d'un passager\n";
            cout<<"[7]:Modifier  un Passager au Vol\n";
            cout<<"[8]:Modifier les dates d'un vol  \n";
            cout<<"[9]:Afficher les Passagers ayant moins de 10 \n";
            cout<<"[10]:Afficher Tous les vols avec leur Passagers \n";
            cout<<"[11]:Supprimer un vol  \n";
            cout<<"[0]:Quite le programme ! \n";
            cout<<"=====================================\n";
            cin>>choix;
            int counter=0;
        switch (choix) {
            case 1:
                do {
                    cout<<"\nEntrer l'id de vol pour ajouter le passager";
                    cin>>idv;
                    counter++;
                    if (counter==2){
                        cout<<"\n[ Le vol n'existe pas ] changer a choix [2] ajouter un vol ";
                        break;
                    }
                } while (!(vols.TesterExistenceVol(idv)));
                    vols.AjouterDesPassagersAuVol(idv);
                break;
            case 2:
                 cout<<"\nEntrer l'id de vol pour Ajouter :";
                 cin>>idAv;
                 if(!(vols.TesterExistenceVol(idAv))){
                     vols.AjouterVolAuTableu(idAv);
                 } else{
                     cout<<"\n[Desole!] Le Vol avec id "<<idAv<<"deja existe";
                 }
                break;
            case 3:
                cout<<"\nEntrer l'id de vol pour afficher leur passagers :";
                cin>>idvaff;
                if(!(vols.AfficherPassagersVol(idvaff))){
                    //vols.AfficherPassagersVol(idvaff);
                }else{
                    cout<<"[Desole!] le vol n'existe pas.!!!";
                }
                break;
            case 4:
                cout<<"\nEntrer l'id de vol pour Afficher :";
                cin>>idaff1;
                if(vols.AfficherUnVol(idaff1)){
                    //vols.AfficherUnVol(idaff1);
                } else {
                    cout<<"\n[Desole!] le vol n'existe pas.!!!";
                }
                break;
            case 5:
                cout<<"Entrer l'id de vol pour Tester ";
                cin>>idpa;
                vols.TesterSiUnPassagerDansVol(idpa);
                break;
            case 6:
                cout<<"\n Entrer l'id de passager ";
                cin>>idpa2;
                if(vols.AfficherDestinationDePassager(idpa2)){
                    //vols.AfficherDestinationDePassager(idpa2);
                } else{
                    cout<<"\n[Desole!] Le Passager n'existe pas";
                }
                break;
            case 7:
                cout<<"\n Entrer l'id de Passager peux modifier";
                cin>>modp;
                if(vols.ModifierPassager(modp)){
                    v.ModifierInformationPassager(modp);
                }
                else{
                    cout<<"\n[Desole!] Le Passager n'existe pas";
                }
                break;
            case 8:
                cout<<"\nEntrer l'id de vol pour modifier leur dates ";
                cin>>mvd;
                if(vols.TesterExistenceVol(mvd)){
                    vols.ModifierDates(mvd);
                }
                break;
            case 9:
                vols.AfficherPassagersMoin();
                break;
            case 10:
                vols.AfficherVols();
                break;
            case 11:
                cout<<"Entrer l'id de vol pour Suppimer";
                cin>>supv;
                if(vols.TesterExistenceVol(supv)){
                    vols.SupprimeVol(supv);
                    cout<<"le vol avec id "<<supv<<" Supprimer !";
                }
                else{
                    cout<<"[Desole!] Le vol n'existe pas ";
                }
                break;
            case 0:
                cout<<"\n[ Au Revoir ]";
                choix=0;
                break;
            default:
                cout<<"\nVotre choix n'est pas desponible reessayer";
                break;
        }
    } while (choix!=0);
    return 0;
}
