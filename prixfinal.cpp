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
	Hotel2 hotel2("hotel2", "intercontinental" ,"Marseille" ,nombredechambre);

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

	//std::cout << hotel2.GetTabChambre()<< std::endl;


	//std::cout << hotel2 << std::endl;



//creation d'un client
	int idnouveauclient=rand();
	Client client1(idnouveauclient ,"arhi",  "KDa" ,0 );


//creation d'un tableau de reservation
	std::vector<Reservation> tblreservation;
	Date firsttest(2020, 1, 1) , firsttest2(2020,1,5), firsttest3(2020,1,14), firsttest4(2020,1,8);
	Reservation first(132 , firsttest ,firsttest2 ,hotel2.GetId(), 0 , 17 ,0);
	Reservation second(133 , firsttest ,firsttest4 ,hotel2.GetId(), 1 , 21 ,0);
	Reservation third(134 , firsttest2 ,firsttest3 ,hotel2.GetId(), 2 , 54, 0);
	Reservation quatre(152, firsttest ,firsttest2 ,hotel2.GetId() , 8 ,45421 ,0);
	tblreservation.push_back(first);
	tblreservation.push_back(second);
	tblreservation.push_back(third);
	tblreservation.push_back(quatre);


	//permet de saisir le type de cambre souhaite
	std::string type;
	std::cout << "quel type de chambre desirez-vous (Single, Double ,Suite) \n";
	std::cin>> type;
	std::cout <<"vous avez choisis une chambre: " << type << std::endl;
	//


	//demande de dates de reservation

int year , month ,day;
	std::cout <<"quelles sont les dates de votre sejour (\n";
	std::cout<<"date d'arrivée (annee , mois , jour \n";
	std::cin>>year >>month >> day;
	Date datedebutsejour(year, month , day);
	std::cout<<"date de départ (annee , mois, jour \n";
	std::cin>>year>> month >> day ;
	Date datefinsejour(year , month , day);

	//verification de la disponibilite de la chambre dans le tableau de reservation
	std::vector<Chambre> tblchambre;
	int informateur , identifiantchambre , prixdelachambre;
	int idnouvellereservation2;
	tblchambre=hotel2.GetTabChambre();
	for(int i=0 ; i<tblchambre.size() ; i++){ 
		if (informateur<=2){ 
	  		if (tblchambre[i].gettype()==type){
	  			prixdelachambre=tblchambre[i].getprix();
	  			informateur=1;
  				for(int y=0 ; y<tblreservation.size() ; y++) {
					if(tblreservation[y].getidchambre()==tblchambre[i].getidentifiant()){ 
						Date datedebtbl, datefintbl;
						datedebtbl=tblreservation[y].getdatededebut();
						datefintbl=tblreservation[y].getdatedefin();

						if((datefinsejour<=datedebtbl) || (datedebutsejour>=datefintbl) ){
							informateur=3;
							identifiantchambre=(tblchambre[i]).getidentifiant();

							}
						else if((datedebutsejour>=datedebtbl && datedebutsejour<=datefintbl)||(datefinsejour>=datedebtbl && datefinsejour<=datefintbl)||(datedebtbl>=datedebutsejour) && (datedebtbl<=datefinsejour) || (datefintbl>=datedebutsejour) && (datefintbl<= datefinsejour)){ 
							informateur=2;
						}
					}
			}
			
				if (informateur==1){
					identifiantchambre=tblchambre[i].getidentifiant();
					informateur=4;
				}
	  	}
	  }









	}
	if(informateur==2){
				std::cout << "desole aucune chambre du type "<< type<< " disponible pour les dates que vous avez indique , essayez avec un autre type de chambre \n";
			}
	else if ((informateur==4) || (informateur==3)){ 
		std::cout <<"votre reservation a bien été pris en compte. vous avez donc reserver une chambre de type" << type << "lidentifiant de la chambre est: " << identifiantchambre << ",le prix par nuit de cette chambre est de: " << prixdelachambre << "euros " << 	std::endl;
		idnouvellereservation2=rand();
		Reservation nouvellereservation(idnouvellereservation2 ,datedebutsejour ,datefinsejour, hotel2.GetId() , identifiantchambre, client1.GetId(), 0.0 );
		tblreservation.push_back(nouvellereservation);
		double prixfinal=prixtotalsejour(datedebutsejour,datefinsejour, prixdelachambre);
		std::cout<< "le prix final du sejour est" << prixfinal << std::endl;

	}
	else if (informateur==0){
		std::cout<< "ce type ( " << type << ") de chambre n'existe pas essayez avec un des types de chambre proposé dans la liste. Merci \n";
	}

	std::cout<< tblreservation <<  std::endl;


	return 0;

}




