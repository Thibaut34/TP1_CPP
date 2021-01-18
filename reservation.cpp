#include "reservation.h"
#include "date.h"
#include <string>
#include "chambre.h"
#include "date.h"
#include "client.h"
#include "hotel.h"
#include "hotel2.h"

	
bool Reservation:: checkdatereservation(Date datedebut , Date datedefin ){
	bool status;
	if ((datedebut<=datedefin)==1){
		status=true;
	}
	else
		status=false;
	return status;
}//verifie si la date de fin et bien après la date de debut

Reservation::Reservation(int idreservation, Date datedebut, Date datedefin , std::string idhotel , int idchambre,int idclient ,double total){
	if(checkdatereservation(datedebut , datedefin)==true){ 
		_idreservation=idreservation;
		_idhotel=idhotel;
		_idclient=idclient;
		_idchambre=idchambre;
		_datedebut=datedebut;
		_datedefin=datedefin;
		_total=total;
	}
	else 
		std::cout<< "erreur la reservation ne peut pas etre creer (les dates ne sont pas bonnes)" << std::endl;
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

void Reservation::setidresa(int idreservation){
	_idreservation=idreservation;
}

void Reservation::setidhotel(std::string idhotel){
	_idhotel=idhotel;
}






std::ostream& operator<<(std::ostream& os,  Reservation reservationtest){
	os<< reservationtest.getidreservation() << "/" << reservationtest.getdatededebut().toString() << "/" << reservationtest.getdatedefin().toString() << "/" << reservationtest.getidhotel() << "/" << reservationtest.getidchambre() <<"/" << reservationtest.getidclient() << "/" <<   reservationtest.gettotal() <<  "\n" ;
	return os;
	}

std::ostream& operator<<(std::ostream& os, const std::vector<Reservation>& listeReservation) {
	for (Reservation reservation : listeReservation)
		os << reservation << " ";
	os << std::endl;
	return os;
}



double prixtotalsejour(Date datededebut ,Date datedefin, double prix){
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

	return nbdenuit*prix ;
}	



void afficherreservation(int identreservation, std::vector<Reservation> tableaureservation){
	auto it=tableaureservation.begin();
	while(it!=tableaureservation.end()){
		if ((*it).getidreservation()==identreservation){
			std::cout << *it << std::endl;
			it=tableaureservation.end();
		}
		it++;
	}
}



void afficherreservation2(std::string nom , std::string prenom , int id , std::vector<Reservation> tableaureservation, std::vector<Client> listeclient){
	int identif=id;
	if(id==0){
		auto it2= listeclient.begin();
		while(it2!=listeclient.end()){
			if(((*it2).GetNom()==nom)&&((*it2).GetPrenom()==prenom)){
				identif=(*it2).GetId();
				std::cout<<"hey"<< std::endl;
			}
		}
	}
	auto it=tableaureservation.begin();
	while(it!=tableaureservation.end()){
		if((*it).getidclient()==identif){
			std::cout << *it << std::endl;
		}
		it++;
	}
}
	
























void validationresa(Hotel2 hotel2 ,Client client1 ,std::vector<Reservation>& tblreservation , std::string type , Date datedebutsejour , Date datefinsejour){
	std::vector<Chambre> tblchambre;
	int informateur=0 , identifiantchambre , prixdelachambre;
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
		std::cout << "" << std::endl;
		std::cout <<"votre reservation a bien été pris en compte. vous avez donc reserver une chambre de type " << type << " l'identifiant de la chambre est: " << identifiantchambre << ",le prix par nuit de cette chambre est de: " << prixdelachambre << "euros " << std::endl;
		idnouvellereservation2=rand();
		Reservation nouvellereservation(idnouvellereservation2 ,datedebutsejour ,datefinsejour, hotel2.GetId() , identifiantchambre, client1.GetId(), 0.0 );
		std::cout << "les informaions de la reservation sont " << nouvellereservation << std::endl;
		tblreservation.push_back(nouvellereservation);
		double prixfinal=prixtotalsejour(datedebutsejour,datefinsejour, prixdelachambre);
		std::cout<< "le prix final du sejour est de " << prixfinal << "euros" << std::endl;
		std::cout << "" << std::endl;

		}	
	else if (informateur==0){
		std::cout<< "ce type ( " << type << ") de chambre n'existe pas essayez avec un des types de chambre proposé dans la liste. Merci \n";
	}


}




void afficherresa(int idclient,  std::vector<Reservation> tableaureservation){
	auto it2=tableaureservation.begin();
	while(it2!=tableaureservation.end()){
		if ((*it2).getidclient()==idclient){
			std::cout << *it2 << std::endl;
		}
		it2++;
	}
}


/*

void afficherresa(int idclient, std::vector<Reservation> tblreservation){
	for(int i=0 ; i<tblreservation.size() ; i++){
		std::cout << "salut" << std::endl; 
		if ((tblreservation[i].getidclient())==idclient){
			std::cout << tblreservation[i] << std::endl;;
		}
	}
}
*/

void afficherresanom(std::string nom , std::string prenom ,std::vector<Reservation>  tableaureservation ,std::vector<Client>  listeclient){
	auto it3=listeclient.begin();
	int id;
	while(it3!=listeclient.end()){
		if(((*it3).GetNom()==nom) && ((*it3).GetPrenom()==prenom)){
			id=(*it3).GetId();
		}
		it3++;
	}
	auto it2=tableaureservation.begin();
	while(it2!=tableaureservation.end()){
		if ((*it2).getidclient()==id){
			std::cout << *it2 << std::endl;
		}
		it2++;
	}
}




void Reservation:: modifyreservationbyhotel(int idreservation, Date datededebut , Date datedefin,  std::string idhotel , int idchambre ,int idclient ,double total){
	if(idreservation!=-1){
		_idreservation=idreservation;
	}
	if (datededebut.year()!=0 && datededebut.month()!=0 && datededebut.day()!=0 && datedefin.year()!=0 && datedefin.month()!=0 && datedefin.day()!=0){
		_datedebut=datededebut;
		_datedefin=datedefin;
	}
	if(idhotel!=""){
		_idhotel=idhotel;
	}
	if(idchambre!=0){
		_idchambre=idchambre;
	}
	if(idclient!=0){
		_idclient=idclient;
	}

	if(total!=0){
		_total=total;
	}
}




