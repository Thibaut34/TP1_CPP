#include <iostream>
#include <array>
#include "Chambre.h"
#include "Hotel.h"
Hotel::Hotel(std::string id, std::string nom, std::string ville, int nbrechambre): m_id(id), m_nom(nom), m_ville(ville), m_nbrechambre(nbrechambre){}
std::string Hotel::GetId() const{
    return m_id;
}
std::string Hotel::GetNom() const{
    return m_nom;
}
std::string Hotel::GetVille() const{
    return m_ville;
}
int Hotel::GetNbrechambre() const{
    return m_nbrechambre;
}
void Hotel::InitTab(int nbrechambre){
    int tab[nbrechambre];
    for(int i = 0; i<nbrechambre; i++){
        std::cout<<"Saisir l'id de la chambre numero "<<i+1<<std::endl;
        int id_chambre;
        std::cin>>id_chambre;
        tab[i]=id_chambre;

    }
    std::cout<<tab<<std::endl;
}
