#include "saeugetier.h"
#include <iostream>
using namespace std;
Saeugetier::Saeugetier()
{
    int wahl;
    bool rudeltier=false;
    do{
        cout<<"Ist es ein Rudeltier?"<<endl;
        cout<<"1. ja"<<endl;
        cout<<"2. nein"<<endl;
        cin>>wahl;
        if(wahl==1){
            m_rudelTier=true;
            rudeltier=true;
        }
        else if(wahl==2){
            m_rudelTier=false;
            rudeltier=true;
        } else{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
        }
    } while(rudeltier==false);
    cout<<"wie viele Tragzeit? (in Wochen) "<<endl;
    cin>>m_tragzeit;
    cout<<"wie viel ist der Gewicht durchschnittlich? (in kg)"<<endl;
    cin>>m_durschnittsgewicht;

}

void Saeugetier::TiereAnzeigen()
{
cout<<"-------------------------------------------------------------"<<endl;
cout<<"Tier: Vogel"<<endl;
Tier::TiereAnzeigen();
cout<<"Tragzeit: "<<m_tragzeit<<" Woche/n "<<endl;
cout<<"Durchschnittsgewicht: "<<m_durschnittsgewicht<<" kg "<<endl;
cout<<"Rudeltier: ";
if(!m_rudelTier){
    cout<<"nein"<<endl;
} else cout<<"ja"<<endl;

cout<<"-------------------------------------------------------------"<<endl;
}

void Saeugetier::serialize(ofstream&ausgabe)
{
    Tier::serialize(ausgabe);
    ausgabe.write((char*)&m_rudelTier, sizeof(m_rudelTier));
    ausgabe.write((char*)&m_tragzeit, sizeof(m_tragzeit));
    ausgabe.write((char*)&m_durschnittsgewicht, sizeof(m_durschnittsgewicht));


}

void Saeugetier::deserialize(ifstream& eingabe)
{

}
