#include <vector>
#include <iostream>
#include <string>
#include "client.h"


Client::Client(int id, std::string nom, std::string prenom, int reservations):m_id(id), m_nom(nom), m_prenom(prenom), m_reservations(reservations){}
int Client::GetId() const{
    return m_id;
}
std::string Client::GetNom() const{
    return m_nom;
}
std::string Client::GetPrenom() const{
    return m_prenom;
}
int Client::GetReservations() const{
    return m_reservations;
}
void Client::SetClient(int id, std::string nom, std::string prenom, int reservations){
    m_id = id;
    m_nom = nom;
    m_prenom = prenom;
    m_reservations = reservations;
}


std::ostream& operator<<(std::ostream& os,  Client listeclienttest){
	os<< listeclienttest.GetId() << "/" << listeclienttest.GetNom() << "/" << listeclienttest.GetPrenom() << "/" << listeclienttest.GetReservations() <<  "\n" ;
	return os;
	}

std::ostream& operator<<(std::ostream& os, const std::vector<Client>& listeclient) {
	for (Client client : listeclient)
		os << client<< " ";
	os << std::endl;
	return os;
}