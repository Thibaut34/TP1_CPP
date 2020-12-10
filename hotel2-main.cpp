#include "hotel2.h"
#include <string>
#include <iostream>
#include <vector>

int main(){
	std::vector<int> vectortest;
	Hotel2 hotel2("identifianttest", "nomtest", "villetest" , vectortest);
	hotel2.remplir(10 , hotel2.GetNumero());
	std::cout << hotel2 << std::endl;

	std::cout << hotel2.GetId() << " " << hotel2.GetNom() <<std::endl;

	return 0;
}