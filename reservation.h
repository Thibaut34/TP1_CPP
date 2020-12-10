#ifndef RESERATION_H
#define RESERVATION_H
#include "date.h"
#include <string>
#include "chambre.h"
#include "client.h"
#include "hotel.h"


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
			
		private:
			int _idreservation , _idchambre ,_idclient ;
			Date _datedebut;
			Date _datedefin;
			double _total;
			std::string _idhotel;

	};	



#endif 
//creation de la clase reservation en utilisant les classe chambre et date deja existante