#ifndef GESTIONVOLS_TP_VOLS_H
#define GESTIONVOLS_TP_VOLS_H
#include <iostream>
#include <string>
#include <vector>
#include "vol.h"

class Vols{
private:
    vector<Vol> listDeVols;
public:
    auto getListDeVols();
    void AjouterDesPassagersAuVol(int idv);
    bool TesterExistenceVol(int id);
    bool AfficherUnVol(int id);
    void AfficherVols();
    void AjouterVolAuTableu(int idv);
    bool AfficherPassagersVol(int id);
    void TesterSiUnPassagerDansVol(int id);
    bool AfficherDestinationDePassager(int id);
    bool ModifierPassager(int id);
    void ModifierDates(int id);
    void AfficherPassagersMoin();
    void SupprimeVol(int id){
        for (size_t i = 0; i < listDeVols.size(); i++)
        {
            if (listDeVols[i].getIdVol() == id)
            {
                listDeVols.erase(listDeVols.begin() + i);
            }
        }
    }


};
#endif //GESTIONVOLS_TP_VOLS_H
