#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>


int main(){

//PARTIE 6: CREATION D'UN HOTEL ET DE CLIENTS
	//creation de l'hotel
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

	//creation de la liste des clients

	std::vector<Client> listeclient;

	Client client1(1,"nomtest1" ,"prenomtest1" , 0);
	listeclient.push_back(client1);
	Client client2(2,"nomtest1" ,"prenomtest2" , 0);
	listeclient.push_back(client2);
	Client client3(3,"nomtest1" ,"prenomtest3" , 0);
	listeclient.push_back(client3);
	Client client4(4,"nomtest1" ,"prenomtest4" , 0);
	listeclient.push_back(client4);
	Client client5(5,"nomtest1" ,"prenomtest5" , 0);
	listeclient.push_back(client5);
	Client client6(6,"nomtest1" ,"prenomtest6" , 0);
	listeclient.push_back(client6);
	Client client7(7,"nomtest1" ,"prenomtest7" , 0);
	listeclient.push_back(client7);
	Client client8(8,"nomtest1" ,"prenomtest8" , 0);
	listeclient.push_back(client8);
	Client client9(9,"nomtest1" ,"prenomtest9" , 0);
	listeclient.push_back(client9);
	Client client10(10,"nomtest10" ,"prenomtest10" , 0);
	listeclient.push_back(client10);

	std::cout<<listeclient << std::endl;

//fin de la question 6 

//quesiton 7:VALIDATION DES DATES DE RESERVATION

	// creation d'u tableau contenant toutes les reservations 
	std::vector<Reservation> tblreservation;
	std::vector<Reservation>& tblreservationref = tblreservation ;//reference permettant de modifier le tableau des reservations 

//toute ces reservations ne sont pas demandés dans le tp mais sont utiles afin d'illustrer le bon fonctionnement de certaines fonctions plus loin
Date firsttest(2020, 1, 1) , firsttest2(2020,1,5), firsttest3(2020,1,14), firsttest4(2020,1,8);
	Reservation first(132 , firsttest ,firsttest2 ,hotel2.GetId(), 0 , 17 ,0);
	Reservation second(133 , firsttest ,firsttest4 ,hotel2.GetId(), 1 , 21 ,0);
	Reservation third(134 , firsttest2 ,firsttest3 ,hotel2.GetId(), 2 , 54, 0);
	Reservation quatre(152, firsttest ,firsttest2 ,hotel2.GetId() , 8 ,45421 ,0);
	tblreservation.push_back(first);
	tblreservation.push_back(second);
	tblreservation.push_back(third);
	tblreservation.push_back(quatre);

/*question 7)a) permet de saisir au clavier les dates d'une réservation et de verifier si elles sont bonnes,
si elles sont bonnes le code affiche un message de confirmation
si elles sont mauvaises le coed demande de resaisir les dates 
*/
std::cout<<"dans ce cas on montre que tout fonctionne bien aussi " << std::endl;


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

//fin de la question 7)a)
//quesiton 7)b) calcule et affiche le nomnbre de nuit de la reservation
	nombredenuit(datedebutsejour, datefinsejour);

//fin de la question 7

//question 8: CHOIX D'UNE CHAMBRE

//qestion 8a) permet de saisir au clavier le type de chambre souhaité
	std::string type;
	std::cout << "quel type de chambre desirez-vous (single, double ,suite) \n";
	std::cin>> type;
	std::cout <<"vous avez choisis une chambre: " << type << std::endl;
//fin de la question 8)a)

//question 8)b)la fonction suivante permet de vérifier si une chambre de ce type est disponible dans l'hôtel à la période donnée et la première chambre possible est sélectionée
//dans le cas où aucune chambre n'est disponible un message d'erreur apparait et demande à l'utilisateur d'essayer avec un autre type de chambre
	
	bool dispo=validationresa( hotel2 ,listeclient[0], tblreservationref ,type , datedebutsejour ,datefinsejour);
	while(dispo==false){
		std::string type;
		std::cout << "quel type de chambre desirez-vous (single, double ,suite) \n";
		std::cin>> type;
		std::cout <<"vous avez choisis une chambre: " << type << std::endl;
		dispo=validationresa( hotel2 ,listeclient[0], tblreservationref ,type , datedebutsejour ,datefinsejour);
	}

//fin de la question 8

//question 9;CHOIX DU CLIENT
//creation d'un client dont le nom est saisi au clavier 
    Client client_test(0,"Indiquez","Indiquez",0);
    std::string nom_client;
    std::cout<<"Entrez le nom du client"<<std::endl;
    std::cin>> nom_client;
    client_test.SetClient(0, nom_client, "Indiquez", 0);
 
  //gestion des homonymes, permet a l'utilisateur de selectionner son client en fonction de son nom parmis tous ceux qui possèdent le même nom
    client_test=choixclient(nom_client, listeclient);

//affiche les informations du client  à l'écran
	std::cout<< client_test << std::endl;

//fin de la question 9


//quesiton 10:VALIDATION DE LA RESERVATION

//les questionq 10)a 10)b 10) ont étés traitées dans la fonction "validationresa" pour plus de clareté et de simplicité

//question 10)c)
	/*5 cas on été traités (erreur de dates, plus de chambre disponible ,mauvais type demandé, le cas où il y a plusieurs chambres 
	disponibles pour montrer que la fonction prend bien la première chambre disponble, cas où tout est bon )
	ces captures d'écran sont à retrouver dans le compte rendu

*/

//question 11:GESTION DES RESERVATION:
//les questions de cette partie sont traitées dans les fichier de la classe Reservation des exemples d'applications sont donnée ci dessous

	affichertoutelesresa(tblreservation);//affiche toutes les reservations 

	afficherresa( 1 , tblreservation);//affiche la reservation en fonction de l'identifiant du client

	afficherresanom( "nomtest1" , "prenomtest1", tblreservation , listeclient  );//affiche toute les reservations d'un client en renseignant son nom et son prenom

	afficherreservation(132, tblreservation);//affcihe une reservation en fonction de l'identifiant de cette reservation

	//les lignes de codes qui suivent permmettent de montrer le bon fonctionnement de la fonction "modifyreservationbyhotel" qui permet d'effectuer une modification d'une réservation par l'hotel

	Date one(2020, 2, 1);
	Date two(2020, 5, 15);

	std::cout<< tblreservation[1]<<std::endl;
	tblreservation[1].modifyreservationbyhotel(5, one , two ,"salut", 50,151,2000);
	std::cout << tblreservation[1] <<std::endl;

//



	return 0;
}