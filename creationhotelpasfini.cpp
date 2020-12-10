#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>



int main(){
	std::vector<Chambre> nombredechambre;
	Hotel2 hotel2("hotel1", "intercontinental" ,"Marseille" ,nombredechambre);

	hotel2.remplir(10);


Chambre type1 (0 , "single" ,100);
Chambre type2 (0, "double" ,125);
Chambre type3 (0 ,"suite" ,210);


	for (int i=0 ; i<10 ; i++){
		if (i>=0 && i<=2){
			type1.setidentifiant(i);
			hotel2.setTabChambre(i ,type1);

		}
		else if(i>=3 && i<=7){
			type2.setidentifiant(i);
			hotel2.setTabChambre(i, type2);
		}
		else if(i>=8 && i<=9){
			type3.setidentifiant(i);
			hotel2.setTabChambre(i, type3);
		}

	};

std::cout << hotel2.GetTabChambre()<< std::endl;




std::cout << hotel2 << std::endl;


	return 0;
}