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






// creation d'u tableau contenant toutes les reservations 
	std::vector<Reservation> tblreservation;

//debut partie validation des dates du sejour


/*	Date datedebutsejour , datefinsejour ;
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
	datedebutsejour=datedebut1;
	datefinsejour=datedefin1;

	std::cout<<"les dates sont valides merci \n";
	nombredenuit(datedebutsejour, datefinsejour);
*/

//fin de la partie: validation des dates du sejour


Date firsttest(2020, 1, 1) , firsttest2(2020,1,5), firsttest3(2020,1,14), firsttest4(2020,1,8);
	Reservation first(132 , firsttest ,firsttest2 ,hotel2.GetId(), 0 , 17 ,0);
	Reservation second(133 , firsttest ,firsttest4 ,hotel2.GetId(), 1 , 21 ,0);
	Reservation third(134 , firsttest2 ,firsttest3 ,hotel2.GetId(), 2 , 54, 0);
	Reservation quatre(152, firsttest ,firsttest2 ,hotel2.GetId() , 8 ,45421 ,0);
	tblreservation.push_back(first);
	tblreservation.push_back(second);
	tblreservation.push_back(third);
	tblreservation.push_back(quatre);








//debut de la partie choix des chambres
			//permet de saisir le type de cambre souhaite
	/*std::string type;
	std::cout << "quel type de chambre desirez-vous (single, double ,suite) \n";
	std::cin>> type;
	std::cout <<"vous avez choisis une chambre: " << type << std::endl;
	//
*/

std::vector<Reservation>& tblreservationref = tblreservation ;


//verification de la disponibilite de la chambre dans le tableau de reservation (question 10 incluse)

for (int i=0 ; i<listeclient.size() ; i++){
		std::string type;
		std::cout << "quel type de chambre desirez-vous (single, double ,suite) \n";
		std::cin>> type;
		std::cout <<"vous avez choisis une chambre: " << type << std::endl;



//question 7

		Date datedebutsejour , datefinsejour ;
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
		datedebutsejour=datedebut1;
		datefinsejour=datedefin1;

		std::cout<<"les dates sont valides merci \n";
		nombredenuit(datedebutsejour, datefinsejour);
		//fin de la question 7
//
		//


		validationresa( hotel2 ,listeclient[i], tblreservationref ,type , datedebutsejour ,datefinsejour);

	}



 	affichertoutelesresa(tblreservation);



	afficherresa( listeclient[1].GetId() , tblreservation);

	afficherresanom( "salomo" , "Jacques", tblreservation , listeclient  );
//
	afficherreservation(132, tblreservation);

	Date one(2020, 2, 1);
	Date two(2020, 5, 15);

	std::cout<< tblreservation[1]<<std::endl;
	tblreservation[1].modifyreservationbyhotel(5, one , two ,"salut", 50,151,2000);
	std::cout << tblreservation[1] <<std::endl;



	return 0;
}
