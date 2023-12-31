#ifndef GESTIONVOLS_TP_AVION_H
#define GESTIONVOLS_TP_AVION_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Passager.h"
//#include "vol.h"
using namespace std;
class Avion{
private:
    string codeAvion;
    string pilot;
    int modele, capacite, nbVolsAssure;
    tm dateFabrication = {};
public:
    //CONSTRUCTOR
    Avion();
    //gettersDate
    int getCapacite();
    // year
    int getCurrentYear();
    // month
    int getCurrentmonth();
    // day
    int getCurrentday();

    //saisir Avion
    void saisirDatefab();
    void saisirAvion();
    //bool ControlCapacitenb(int nbPassager);
   // bool ControlCapacite(int size,int nb);
    //afficher avion
    void afficherAvion();
};
#endif //GESTIONVOLS_TP_AVION_H
