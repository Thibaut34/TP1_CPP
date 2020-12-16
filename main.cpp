#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>





int main(){

//debut partie;creation hotel 

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


//fin partie::creation hotel
//partie liste de client





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

//fin de la partie:liste de client 
//debut partie validation des dates du sejour


	Date datedebut , datedefin ;
	int year , month, day; 
	std::cout <<"renseigner les dates de debut du sejour (au format (year/month/day) \n";
	std::cin>>year >> month >> day ;
	Date datedebut1(year, month,day);
	std::cout <<"renseigner les dates de fin du sejour (au format (year/month/day) \n";
	std::cin>>year >> month >> day ;
	Date datedefin1(year, month,day);
	bool test =checkdatereservationvalides(datedebut1 , datedefin1);

	while(test==false){
		std::cout <<"les dates ne sont pas valides ressayer s'il vous plait \n";
		std::cout <<"renseigner les dates de debut du sejour (au format (year/month/day) \n";
		std::cin>>year >> month >> day ;
		datedebut1.setYear(year);
		datedebut1.setMonth(month);
		datedebut1.setDay(day);
		std::cout <<"renseigner les dates de fin du sejour (au format (year/month/day) \n";
		std::cin>>year >> month >> day ;
		datedefin1.setYear(year);
		datedefin1.setMonth(month);
		datedefin1.setDay(day);
		test =checkdatereservationvalides(datedebut1 , datedefin1);
	};
	datedebut=datedebut1;
	datedefin=datedefin1;

	std::cout<<"les dates sont valides merci \n";
	nombredenuit(datedebut1, datedefin1);


//fin de la partie: validation des dates du sejour

	return 0;
}