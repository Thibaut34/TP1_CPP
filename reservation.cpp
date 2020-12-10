#include "reservation.h"
#include "date.h"
#include<string>
#include "chambre.h"
#include "date.h"
#include "client.h"
#include "hotel.h"

	
bool Reservation:: checkdatereservation(Date datedebut , Date datedefin ){
	bool status;
	if (datedebut<=datedefin){
		status==true;
	}
	return status;
}//verifie si la date de fin et bien après la date de debut

Reservation::Reservation(int idreservation, Date datedebut, Date datedefin , std::string idhotel , int idchambre,int idclient ,double total){
	_idreservation=idreservation;
	_idhotel=idhotel;
	_idclient=idclient;
	_idchambre=idchambre;
	_datedebut=datedebut;
	_datedefin=datedefin;
	_total=total;
}//constructeur de l'objet reservation 


Reservation::~Reservation(){
}


int Reservation:: getidreservation() const{
	return _idreservation;//getter de l'identifiant de la reservation pour pouvoir y acceder en dehors de la classe
}

Date Reservation:: getdatededebut() const{
	return _datedebut;//getter de la date de debut de la reservation pour pouvoir y acceder en dehors de la classe
}
Date Reservation:: getdatedefin() const{
	return _datedefin;//getter de la date de fin de la reservation pour pouvoir y acceder en dehors de la classe
}


std::string Reservation:: getidhotel() const{
	return _idhotel; //getter de l'identifiant de l'hotel'pour pouvoir y acceder en dehors de la classe

}

int Reservation:: getidchambre() const{
	return _idchambre;//getter de l'identifiant de la chambre pour pouvoir y acceder en dehors de la classe
}

int Reservation:: getidclient() const{
	return _idclient; //getter de l'identifiant du client pour pouvoir y acceder en dehors de la classe
}
double Reservation:: gettotal() const{
	return _total; //getter du total de la reservation pour pouvoir y acceder en dehors de la classe
}


void Reservation:: setdatedusejour(Date datededebut ,Date datedefin){
	_datedebut=datededebut;
	_datedefin=datedefin;
}
//permet de modifier les dates de debut et de fin du sejour


void Reservation::setidchambre(int idnouvellechambre){
	_idchambre=idnouvellechambre;
}
//modifie l'identifiant de la chambre 


double Reservation::montanttotal(Date datededebut ,Date datedefin , double prixparnuit , double reduc){
	int nbdenuit=(datedefin.day()-datededebut.day());
	double prixbrut = nbdenuit*prixparnuit;
	double prixfinal;
	if (reduc ==0 ){
		prixfinal=prixbrut;
	}
	else 
		prixfinal=prixbrut*(1-reduc/100);
	return prixfinal;
}
//donne le montant total en focntion de la duree du sejour , du prix de la chambre, et de l'existence ou non d'une reduction 

void Reservation::setprixtotal( double prix){
	_total=prix;
}

std::string Reservation::toString(Date dateaafficher) const {
	int year= dateaafficher.year();
	int months= dateaafficher.month();
	int day=dateaafficher.day(); 
	std::string month[12] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
	std::string to_display;
	to_display = std::to_string(year) + "/" + month[months-1] + "/" + std::to_string(day);
	return to_display;
}