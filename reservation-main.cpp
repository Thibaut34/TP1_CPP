#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>


int main(){
	date::Date datededebut(2020,12,21);
	date::Date datedefin(2020,12,30);
	chambre::Chambre chambre1(132, "single" ,135);
	double prixfinal=(reservation::Reservation::montanttotal(datededebut ,datedefin , chambre1.getprix(), 0));
	reservation::Reservation reservationnoel(13225 ,datededebut ,datedefin ,"ocean11" , chambre1.getidentifiant(), 132515,prixfinal);
	std::cout << reservationnoel.getidreservation() << "/" << reservationnoel.getidclient() << "\n";
	return 0;
}