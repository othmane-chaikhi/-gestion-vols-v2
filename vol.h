#ifndef GESTIONVOLS_TP_VOL_H
#define GESTIONVOLS_TP_VOL_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Passager.h"
#include "avion.h"
#include "chrono"
#include "Date.cpp"

using namespace std;
class Vol{
private:
    int idV;
    Avion avion;
    vector<Passager> passagers;
    tm dateDipart = {}, dateArrivee = {};
    int nbPassagers;
    string destination;
public:
    //[ getters ]
    int getIdVol();
    int getSizeListPassager();
    int getCurrentYear();
    // month
    int getCurrentmonth();
    // day
    int getCurrentday();
    //saisie de vol
    void saisirDateDipart();
    void saisirDateArrivee();
    void saisirVol();
    void AjouterVol(int IDV);
    //afficher Vol
    void afficherVol();
    bool ControlNbPassager(int nb);
    bool testerExictencePassager(int idp);
    void AjouterPassager(int i);
    void AfficherPassagers();
    void AfficherUnPassager(int id);
    void ModifierInformationPassager(int id);
    bool AfficherPassagerMoin10ans();

};
#endif //GESTIONVOLS_TP_VOL_H
