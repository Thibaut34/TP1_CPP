#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>


int main(){
	Client client1(312 , "Jordan" , "Michael" , 0);
	Date datededebut(2020,12,21);
	Date datedefin(2020,12,30);
	Chambre chambre1(132, "single" ,135);
	Hotel hotel1("135Adk" , "OCEAN11" , "marseille" , 500);
	Reservation reservationnoel(13225 ,datededebut ,datedefin ,hotel1.GetId() , chambre1.getidentifiant(), client1.GetId() ,0.0);
	double prixfinal;
	prixfinal= reservationnoel.montanttotal( reservationnoel.getdatededebut() ,reservationnoel.getdatedefin() , chambre1.getprix() , 10);
	reservationnoel.setprixtotal( prixfinal);


	std::cout << reservationnoel.getidreservation() << " "<< reservationnoel.getdatededebut() << " " << reservationnoel.getdatedefin() << " " << reservationnoel.getidhotel() << " " << reservationnoel.getidchambre() << " " << reservationnoel.getidclient() << " " << reservationnoe;lgettotal() << std::endl;

	Date ndatededebut(2020,12,25);
	Date ndatedefin(2020,12,31);


	reservationnoel.setdatedusejour(ndatededebut , ndatedefin);
	reservationnoel.setidchambre(151);
	std::cout << reservationnoel.getdatededebut() << " " << reservationnoel.getdatedefin() << " " << reservationnoel.getidchambre() << std::endl;

	Date datenulle(0,0,0);

	reservationnoel.modifyreservationbyhote(101, datenulle , datenulle , "test" , 0,0,0 );

	std::cout << reservationnoel << std::endl;
	




	std::cout<< prixfinal << std::endl;


	return 0;
};


