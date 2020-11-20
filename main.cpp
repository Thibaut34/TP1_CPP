#include <iostream>
#include "Hotel.h"

using namespace std;

int main()
{
    Hotel hotel1("BALCON12", "Le balcon", "Dijon", 2);
    cout<<"On a "<<hotel1.GetNbrechambre()<<" Chambres"<<endl;
    hotel1.InitTab(2);
    return 0;
}
