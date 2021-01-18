#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>

class Client {
public:
    Client(int id, std::string nom, std::string prenom, int reservations);//constructor de l'objet client
    int GetId() const;//getter  de l'identifiant du client
    std::string GetNom() const;//getter du nom du client
    std::string GetPrenom() const;//getter du prenom du client
    int GetReservations() const;//getter du nombre de reservation qu'a déja fait le client
    void SetClient(int id = 0, std::string nom = "Indiquez", std::string prenom = "Indiquez", int reservations = 0);//setter du client qui permet de modifier un client
private:
    int m_id;
    std::string m_nom;
    std::string m_prenom;
    int m_reservations;

};


std::ostream& operator<<(std::ostream& os,  Client listeclienttest); //overload de l'operateur << qui permet d'afficher un client

std::ostream& operator<<(std::ostream& os, const std::vector<Client>& listeclient);//overload de l'operateur << qui permet d'afficher un vector de client

Client choixclient(std::string nom , std::vector<Client> listedeclient);//permet de selectoionner un client dans la liste des clients en foction du nom du client


#endif // CLIENT_H_INCLUDED