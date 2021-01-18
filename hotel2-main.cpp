#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>


int main(){
	Chambre chambretest(1 , "double" , 125);
	std::vector<Chambre> vectortest;
	Hotel2 hotel2("identifianttest", "nomtest", "villetest" , vectortest);
	hotel2.remplir(10 );
	hotel2.setTabChambre(1, chambretest);
	std::cout<< hotel2.GetId() << " " << hotel2.GetNom() << " " << hotel2.GetVille() << " " << hotel2.GetTabChambre() << std::endl;
	hotel2.setTabChambre(5, chambretest);
	std::cout << hotel2 << std::endl;


	return 0;
}