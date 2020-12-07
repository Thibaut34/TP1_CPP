#include "hotel2.h"
#include <string>
#include <iostream>
#include <vector>

Hotel2::Hotel2(std::string id , std::string nom , std::string ville ,std::vector<int> numero){ 
	_id=id;
	_nom=nom;
	_ville=ville;
	_numero=numero;
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

std::vector<int> Hotel2::GetNumero() const{
	return _numero;
}

void Hotel2::remplir(int numeros, std::vector<int> chambre){
	for (int i; i<=numeros ; i++){
		chambre.push_back(i+1);
	};
}
