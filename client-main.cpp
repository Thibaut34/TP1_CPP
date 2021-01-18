#include <iostream>
#include "client.h"

using namespace std;

int main()
{
    Client client(32422, "Pignon", "François", 2);
    cout<<"L'identifiant est :"<<client.GetId()<<endl;
    cout<<"Le nom est :"<<client.GetNom()<<endl;
    cout<<"Le prenom est :"<<client.GetPrenom()<<endl;
    cout<<"Le nbre de reservations est :"<<client.GetReservations()<<endl;
    client.SetClient();
    cout<<"L'identifiant est :"<<client.GetId()<<endl;
    cout<<"Le nom est :"<<client.GetNom()<<endl;
    cout<<"Le prenom est :"<<client.GetPrenom()<<endl;
    cout<<"Le nbre de reservations est :"<<client.GetReservations()<<endl;
    return 0;
}