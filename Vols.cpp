#include "Vols.h"
#include "avion.h"
#include "vol.h"
auto Vols::getListDeVols(){
    return listDeVols;
}

int nbp,idp;


int idpas;
void Vols::AjouterDesPassagersAuVol(int idv) {
    for (auto &v : listDeVols)
    {
        if (v.getIdVol()==idv)
        {   int size=v.getSizeListPassager();
            cout << "Entrer le nomber de passager pour ajouter : ";
            cin >> nbp;
            if(v.ControlNbPassager(nbp)){
               v.ControlNbPassager(nbp);
            } else{
                for(int i=0;i<nbp;i++){

                    cout<<"\nEntrer l'id de passager";
                    cin>>idpas;
                    if(v.testerExictencePassager(idpas)){
                        cout<<"[Desole!] Le passager existe deja";
                    }else{
                        v.AjouterPassager(idpas);
                    }
                }
            }
        }
    }
}
bool Vols::TesterExistenceVol(int id){
    for (auto v:listDeVols) {
        if (id==v.getIdVol()){
            return true;
        }
    }
    return false;
}
Vol v;
bool Vols::AfficherUnVol(int id){
    for(auto v: listDeVols){
        if(v.getIdVol()==id){
            v.afficherVol();
            return true;
        }
    }
    return false;
}
void Vols::AfficherVols(){
    for(auto v:listDeVols){
        v.afficherVol();
        v.AfficherPassagers();
    }
}
void Vols::AjouterVolAuTableu(int idv){
    v.AjouterVol(idv);
    listDeVols.push_back(v);
}
bool Vols::AfficherPassagersVol(int id){
    for(auto v: listDeVols){
        if (v.getIdVol()==id){
            v.AfficherPassagers();
        }
    }
    return false;
}
//
int idpa;
void Vols::TesterSiUnPassagerDansVol(int id){
    for(auto v: listDeVols){
        if(v.getIdVol()==id){
            cout<<"\nEntrer l'id de Passager pour tester";
            cin>>idpa;
            if(v.testerExictencePassager(idpa)){
                cout<<"\nLe passager est existe ";
            }else{
                cout<<"\nLe passager n'existe pas";
            }
        }
    }
}
bool Vols::AfficherDestinationDePassager(int id){
    for(auto v: listDeVols){
        if(v.testerExictencePassager(id)){
            v.afficherVol();
            v.AfficherUnPassager(id);
            return true;
        }
    }
    return false;
}
bool Vols::ModifierPassager(int id){
    for(auto &v: listDeVols){
        if(v.testerExictencePassager(id)){
            v.ModifierInformationPassager(id);
            return true;
        }
    }
    return false;
}
void Vols::ModifierDates(int id){
    for(auto &v:listDeVols){
        if(v.getIdVol()==id){
            v.saisirDateDipart();
            v.saisirDateArrivee();

        }
    }
}
void Vols::AfficherPassagersMoin(){
    for(auto &v : listDeVols){
        if(v.AfficherPassagerMoin10ans()){
            v.AfficherPassagerMoin10ans();
        } else{
            cout<<"Accune Passager mois 10 ans";
        }
    }
}
