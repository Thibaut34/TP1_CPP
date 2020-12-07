#ifndef HOTEL_H
#define HOTEL_H
#include<string>
#include<vector>
#include<iostream>


class Hotel2{

	public:

	Hotel2(std::string id , std::string nom , std::string ville , std::vector<int> numero);
	std::string GetId() const;
    std::string GetNom() const;
    std::string GetVille() const;
    std::vector<int> GetNumero() const;
    void remplir(int numeros, std::vector<int> chambre);


	private:
	std::string _id;
    std::string _nom;
    std::string _ville;
    std::vector<int> _numero;
};

#endif
