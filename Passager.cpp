#include <iostream>
#include<string>
#include "Passager.h"
int Passager::getId(){return idP;}
int Passager::getAge(){return age;}
void Passager::saisirPassager()
{
    cout << "--->Entrer l'id de passager \n";
    cin >> idP;
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
}
void Passager::afficherPassager()
{
    cout << "\n==============Affichage de Passager==============\n";
    cout << "\t id : " << idP << "\n\t nom : " << nom << "\n\t prenom : " << prenom << "\n\t adress : " << adresse << "\n\t age : " << age << "\n\t numero de tele : " << tele << "\n\t  ";
}
void Passager::modifierInformationPassager(string newNom,string newPrenom,string newAdress,int newAge,int newTele)
{
    nom= newNom;
    prenom = newPrenom;
    adresse = newAdress;
    age = newAge;
    tele = newTele;
    cout<<"[ Le passager avec l'id ("<<idP<<")est bien modifier ]";
}
void Passager::SetPassager(int i,string n,string p,string a,int ag,int t){
    idP=i;
    nom=n;
    prenom=p;
    adresse=a;
    age=ag;
    tele=t;
}