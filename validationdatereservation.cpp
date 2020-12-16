#include "reservation.h"
#include "date.h"
#include <string>
#include"chambre.h"
#include <iostream>
#include "hotel2.h"
#include "client.h"
#include <vector>

int nbjourdsmois(int month , int year){
	if( (month == 1 || month == 3 || month == 5 || month == 7|| month == 8 || month == 10 || month == 12) ){
		return 31;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11)){
		return 30;
	}
	else if((month==2)&&(year%4==0)){
		return 29;
	}
	else if((month==2)&&(year%4!=0)){
		return 28;
	}
	else 
		std::cout<<"date impossible\n";
	return 0;
};


void nombredenuit(Date datededebut ,Date datedefin){
	int nbdemois=(datedefin.month() - datededebut.month());
	int nbdenuit;

	if(nbdemois>1){
		nbdenuit=(nbjourdsmois(datededebut.month() , datededebut.year())-datededebut.day());
		for(int i=1; i<(nbdemois); i++){
			int compteur;
			int nombredemois=(datededebut.month()+i);
			compteur=nbjourdsmois(nombredemois, datededebut.year());
			nbdenuit+=compteur;

		}
		nbdenuit+=datedefin.day();
	}
	else if(nbdemois==1){
		nbdenuit=(nbjourdsmois(datededebut.month() , datededebut.year())-datededebut.day());
		nbdenuit+=datedefin.day();

	}
	else 
		nbdenuit=datedefin.day()-datededebut.day();

	std::cout << "vous passerez: " << nbdenuit << " nuits dans l'hotel" << std::endl;
}	;



bool checkdatereservationvalides(Date datedebut , Date datedefin ){
	bool status;
	if ((datedebut<=datedefin)==1){
		status=true;
	}
	else
		status=false;
	return status;
}

int main(){
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

	return 0;
}