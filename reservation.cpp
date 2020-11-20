#include "reservation.h"
#include "date.h"
#include<string>
#include "chambre.h"

namespace reservation{ 
bool Reservation:: checkdatereservation(date ::Date datedebut , date::Date datedefin ){
	bool status;
	if (datedebut<=datedefin){
		status==true;
	}
	return status;
}


Reservation::Reservation(int idreservation, date::Date datedebut, date::Date datedefin , std::string idhotel , int idchambre,int idclient ,double total){
	_idreservation=idreservation;
	_idhotel=idhotel;
	_idclient=idclient;
	_idchambre=idchambre;
	_datedebut=_datedebut;
	_datedefin=datedefin;
	_total=total;
}


int Reservation:: getidreservation() const{
	return _idreservation;
}

date::Date Reservation:: getdatededebut() const{
	return _datedebut;
}
date::Date Reservation:: getdatedefin() const{
	return _datedefin;
}

std::string Reservation:: getidhotel() const{
	return _idhotel;
}

int Reservation:: getidchambre() const{
	return _idchambre;
}
int Reservation:: getidclient() const{
	return _idclient;
}
double Reservation:: gettotal() const{
	return _total;
}


void Reservation:: setdatedusejour(date::Date datededebut ,date::Date datedefin){
	_datedebut=datededebut;
	_datedefin=datedefin;
}


void Reservation::setidchambre(int idnouvellechambre){
	_idchambre=idnouvellechambre;
}


double Reservation::montanttotal(date::Date datededebut ,date::Date datedefin , double prixparnuit , double reduc){
	int nbdenuit=(datedefin.day()-datededebut.day());
	double prixbrut = nbdenuit*prixparnuit;
	double prixfinal;
	if (reduc ==0 ){
		prixfinal=prixbrut;
	}
	else 
		prixfinal=prixbrut*(reduc/100);
	return prixfinal;
}





}