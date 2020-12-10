#include <iostream>
#include "Reservation.h"
#include "date.h"

using namespace std;

int main(){
    void Ajout_Reserv(date::Date date1, date::Date date2;){
        date::Date date1;
    date::Date date2;
    cout<<"Entrez le jour"<<endl;
    int day1, day2;
    cin>>day1;
    cin>>day2;
    date1.setDay(day1);
    date2.setDay(day2);
    cout<<"Entrez le mois"<<endl;
    int month1, month2;
    cin>>month1;
    cin>>month2;
    date1.setMonth(month1);
    date2.setMonth(month2);
    cout<<"Entrez l'année"<<endl;
    int year1, year2;
    cin>>year1;
    cin>>year2;
    date1.setYear(year1);
    date2.setYear(year2);
    cout<<"On a donc : "<<date1.day()<<", "<<date1.month()<< ", "<<date1.year()<<"et "<<date2.day()<<", "<<date2.month()<<", "<<date2.year()<<endl;
    }

    if(date1.checkDate(year1, month1, day1)==false && date2.checkDate(year2, month2, day2)){
        cout<<"Les dates ne sont pas conformes"<<endl;

    }elif(date1.day()<=date2.day() && date1.month()<=date2.month() && date1.year()<=date2.year() ){
        cout<<"Les dates ne sont pas ordonnées"<<endl;
    }
    return 0;

}
