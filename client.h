#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>

class Client {
public:
    Client(int id, std::string nom, std::string prenom, int reservations);
    int GetId() const;
    std::string GetNom() const;
    std::string GetPrenom() const;
    int GetReservations() const;
    void SetClient(int id = 0, std::string nom = "Indiquez", std::string prenom = "Indiquez", int reservations = 0);
private:
    int m_id;
    std::string m_nom;
    std::string m_prenom;
    int m_reservations;

};


std::ostream& operator<<(std::ostream& os,  Client listeclienttest);

std::ostream& operator<<(std::ostream& os, const std::vector<Client>& listeclient);

#endif // CLIENT_H_INCLUDED