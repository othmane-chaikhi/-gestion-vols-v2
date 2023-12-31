#ifndef GESTIONVOLS_TP_PASSAGER_H
#define GESTIONVOLS_TP_PASSAGER_H
#include <iostream>
#include<string>

using namespace std;

class Passager{
    private:
        int idP;
        string nom;
        string prenom;
        string adresse;
        int age;
        int tele;
    public:
    //getters
    int getId();
    int getAge();
    //saisir passager
    void saisirPassager();
    //afficher passager
    void afficherPassager();
    //fonction AjouterPassager pour saisie a nouveau sans saisi id ;
    void SetPassager(int i,string n,string p,string a,int ag,int t);
    void modifierInformationPassager(string newNom,string newPrenom,string newAdress,int newAge,int newTele);
};
#endif //GESTIONVOLS_TP_PASSAGER_H
