#ifndef RESERATION_H
#define RESERVATION_H
#include "date.h"
#include <string>
#include "chambre.h"
#include "client.h"
#include "hotel.h"
#include "hotel2.h"


	class Reservation
	{
		public:
			Reservation();
			~Reservation();
			Reservation(int idreservation, Date datedebut, Date datedefin , std::string idhotel , int idchambre ,int idclient ,double total);
			bool checkdatereservation(Date datedebut , Date datedefin);
			int getidreservation() const;
			Date getdatededebut() const;
			Date getdatedefin() const;
			std::string getidhotel() const;
			int getidchambre() const;
			int getidclient() const;
			double gettotal() const;
			void setdatedusejour(Date datededebut ,Date datedefin);
			void setidchambre(int idnouvellechambre);
			double montanttotal(Date datededebut ,Date datedefin, double prixparnuit , double reduc);
			void setprixtotal(double prix);
			std::string toString(Date dateaafficher) const;
			void setidresa(int idreservation);
			void setidhotel(std::string idhotel);
			void modifyreservationbyhotel(int idreservation, Date datededebut , Date datedefin,  std::string idhotel , int idchambre ,int idclient ,double total);


			
		private:
			int _idreservation , _idchambre ,_idclient ;
			Date _datedebut;
			Date _datedefin;
			double _total;
			std::string _idhotel;

	};	


std::ostream& operator<<(std::ostream& os,  Reservation reservationtest);

std::ostream& operator<<(std::ostream& os, const std::vector<Reservation>& listeReservation) ;

double prixtotalsejour(Date datededebut ,Date datedefin, double prix);

void afficherreservation(int identreservation, std::vector<Reservation> tableaureservation);

void afficherreservation2(std::string nom , std::string prenom , int id , std::vector<Reservation> tableaureservation, std::vector<Client> listeclient);


bool validationresa(Hotel2 hotel2 ,Client client1 ,std::vector<Reservation>& tblreservation , std::string type , Date datedebutsejour , Date datefinsejour);

void afficherresa(int idclient, std::vector<Reservation> tblreservation);

void afficherresanom(std::string nom , std::string prenom ,std::vector<Reservation>  tblreservation ,std::vector<Client>  listeclient);

void supresa(std::vector<Reservation> tblreservation , int idreservation);


#endif 


//creation de la clase reservation en utilisant les classe chambre et date deja existante