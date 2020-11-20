#ifndef CHAMBRE_H
#define CHAMBRE_H
#include<string>

namespace chambre{ 
	class Chambre
	{
		public:
			Chambre();
			~Chambre();
			Chambre(int identifiant , std::string type , double prix);
			int getidentifiant() const;
			std::string gettype() const;
			double getprix() const;
			void setidentifiant(int identifiant);
			void settype(std::string type);
			void setprix(double prix);
			void setchambre(int identifiant ,std :: string type ,double prix);
		private:
			int _identifiant;
			std::string _type;
			double _prix;
		};
	};








#endif 