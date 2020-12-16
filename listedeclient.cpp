#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>
#include<random>
#include <cstdlib>


std::ostream& operator<<(std::ostream& os,  Client listeclienttest){
	os<< listeclienttest.GetId() << "/" << listeclienttest.GetNom() << "/" << listeclienttest.GetPrenom() << "/" << listeclienttest.GetReservations() <<  "\n" ;
	return os;
	}

std::ostream& operator<<(std::ostream& os, const std::vector<Client>& listeclient) {
	for (Client client : listeclient)
		os << client<< " ";
	os << std::endl;
	return os;
}

int main(){ 
	std::vector<Client> listeclient;
	std::cout<< "combien de client voulez vous creer \n";
	int y;
	std::cin>>y;
	for(int i=0 ; i<y; i++){
		int idreservation;
		idreservation=rand();
		std::string nom, prenom;
		std::cout << "remplir votre votre nom et votre prenom \n";
		std::cin>> nom	>> prenom  ;
		Client test(i ,nom , prenom , idreservation);
		listeclient.push_back(test);
	}
	std::cout << listeclient << std::endl;
	return 0;
	}
