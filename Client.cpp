#include <iostream>
#include <string>
#include "Client.h"
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
