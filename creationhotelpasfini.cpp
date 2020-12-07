#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"

int main(){
	std::vector<int> nombredechambre;
	Hotel2 hotel2("1hotel", "intercontinental" ,"Marseille" ,nombredechambre);
	hotel2.remplir(10 , hotel2.GetNumero() );
	for (int i; i<10 ; i++){
		if (i>=0 && i<=2){
			chambre::Chambre (hotel2.GetNumero()[i+1], "Single" , 100);
		}
		else if(i>=3 && i<=7){
			chambre::Chambre (hotel2.GetNumero()[i+1], "Double", 125);
		}
		else if(i>=8 && i<=9){
			chambre::Chambre (hotel2.GetNumero()[i+1], "Suite", 210);
		}

	}
}