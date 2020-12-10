#include "chambre.h"
#include<string>
#include "date.h"
#include <iostream>

	Chambre :: Chambre(int identifiant, std::string type ,double prix){
		_identifiant=identifiant;
		_type=type;
		_prix=prix;
	}

	int Chambre::getidentifiant() const{
		return _identifiant;
	}

	std ::string Chambre::gettype() const{
		return _type;
	}

	double Chambre::getprix() const{
		return _prix;
	}

	void Chambre::setidentifiant(int identifiant){
		_identifiant=identifiant;
	}

	void Chambre::settype(std::string type){
		_type=type;
	}

	void Chambre::setprix(double prix){
		_prix=prix;
	}

	void Chambre::setchambre(int identifiant ,std::string type , double prix){
		
		Chambre::setidentifiant(identifiant);
		Chambre::settype(type);
		Chambre::setprix(prix);

	}

	Chambre ::~Chambre(){
				//std::cout << "  Destructor: " << _identifiant << "/" << _type << "/" << _prix << '\n';
	}


	std::ostream& operator<<(std::ostream& os, const Chambre chambre){
		os<< chambre.getidentifiant() << "/" << chambre.gettype() << "/" << chambre.getprix() << "\n" ;
		return os;
	}







