#include "chambre.h"
#include<string>
#include<iostream>


int main(){
	chambre::Chambre premiere(1, "single" , 100);
	premiere.getidentifiant();
	premiere.gettype();
	premiere.getprix();
	std:: cout << premiere.getidentifiant() <<"/" << premiere.gettype() <<"/"<<premiere.getprix() << std ::endl;
	premiere.setidentifiant(50);
	premiere.settype("double");
	std::cout << premiere.getidentifiant()<< premiere.gettype() << std ::endl;	
	premiere.setchambre(001, "suite" , 2000);
	std:: cout << premiere.getidentifiant() <<"/" << premiere.gettype() <<"/"<<premiere.getprix() << std ::endl;

	return 0;
		}