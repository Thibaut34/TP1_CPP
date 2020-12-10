#include "hotel2.h"
#include <string>
#include <iostream>
#include <vector>
#include "chambre.h"

Hotel2::Hotel2(std::string id , std::string nom , std::string ville ,std::vector<Chambre> chambre){ 
	_id=id;
	_nom=nom;
	_ville=ville;
	_tabchambre=chambre;
}

std::string Hotel2::GetId() const{
	return _id;
}

std::string Hotel2::GetNom() const{
	return _nom;
}

std::string Hotel2::GetVille() const{
	return _ville;
}

std::vector<Chambre>& Hotel2::GetTabChambre(){
	return _tabchambre;
}

std::vector<Chambre>& Hotel2::remplir(int numeros){
	for (int i=0 ; i<numeros ; i++){
		Chambre test(i,"non determiné", 0);
		_tabchambre.push_back(test);
	};
	return _tabchambre;
}

void Hotel2::setTabChambre(int place ,Chambre chambrearemplir){
	_tabchambre[place]=chambrearemplir;
}


std::ostream& operator<<(std::ostream& os, const std::vector<int>& vect) {
	for (int number : vect)
		os << number << " ";
	os << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Chambre>& chambretab) {
	for (Chambre chambre : chambretab)
		os << chambre << " ";
	os << std::endl;
	return os;
}


std::ostream& operator<<(std::ostream& os,  Hotel2 hotel2){
	os<< hotel2.GetId() << "/" << hotel2.GetNom() << "/" << hotel2.GetVille() << "/" << hotel2.GetTabChambre() <<  "\n" ;
	return os;
	}
