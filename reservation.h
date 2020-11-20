#ifndef RESERATION_H
#define RESERVATION_H
#include "date.h"
#include <string>
#include "chambre.h"

namespace reservation{
	class Reservation
	{
		public:
			Reservation();
			~Reservation();
			Reservation(int idreservation, date::Date datedebut, date::Date datedefin , std::string idhotel , int idchambre ,int idclient ,double total);
			bool checkdatereservation(date ::Date datedebut , date::Date datedefin);
			int getidreservation() const;
			date::Date getdatededebut() const;
			date::Date getdatedefin() const;
			std::string getidhotel() const;
			int getidchambre() const;
			int getidclient() const;
			double gettotal() const;
			void setdatedusejour(date::Date datededebut ,date::Date datedefin);
			void setidchambre(int idnouvellechambre);
			double montanttotal(date::Date datededebut ,date::Date datedefin, double prixparnuit , double reduc);
		private:
			int _idreservation , _idchambre ,_idclient ;
			date::Date _datedebut;
			date::Date _datedefin;
			double _total;
			std::string _idhotel;

	};	
};



#endif