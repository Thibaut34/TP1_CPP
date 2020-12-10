#ifndef HOTEL_H
#define HOTEL_H
#include<string>
#include<vector>
#include<iostream>
#include"chambre.h"


class Hotel2{

	public:

	Hotel2(std::string id , std::string nom , std::string ville , std::vector<Chambre> chambre);
	std::string GetId() const;
    std::string GetNom() const;
    std::string GetVille() const;
    std::vector<Chambre>& GetTabChambre();
    std::vector<Chambre>& remplir(int numeros);
    void setTabChambre(int i ,Chambre chambrearemplir);


	private:
	std::string _id;
    std::string _nom;
    std::string _ville;
    std::vector<Chambre> _tabchambre;
};

    std::ostream& operator<<(std::ostream& os, const std::vector<int>& vect);
    std::ostream& operator<<(std::ostream& os,  Hotel2 hotel2);
    std::ostream& operator<<(std::ostream& os, const std::vector<Chambre>& chambretab);

#endif
