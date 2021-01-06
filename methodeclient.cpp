#include <iostream>
#include <string>
#include <vector>
#include "Client.h"


int main2()
{
    Client client_test(0,"Indiquez","Indiquez",0);
    std::string nom_client;
    std::cout<<"Entrez le nom du client"<<std::endl;
    client_test.SetClient(0, nom_client, "Indiquez", 0);
    return 0;

}
void AffichageNom(Client client,std::string nom_client){
    if(client.GetNom()==nom_client){
        std::vector<Client> listeclient;
        listeclient.push_back(client);
        std::cout<<"Selectionnez le client"<<std::endl;
        std::cout<<"Les infos du client sont : "<<std::endl;
        std::cout<<client.GetId()<<","<<client.GetPrenom()<<","<<client.GetReservations()<<std::endl;

    }

}
