#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include <string>
#include <iostream>
#include <array>
#include "Chambre.h"


class Hotel {
public:
    Hotel(std::string id, std::string nom, std::string ville, int nbrechambre);
    std::string GetId() const;
    std::string GetNom() const;
    std::string GetVille() const;
    int GetNbrechambre() const;
    void InitTab(int nbrechambre);
private:
    std::string m_id;
    std::string m_nom;
    std::string m_ville;
    int m_nbrechambre;


};


#endif // HOTEL_H_INCLUDED
