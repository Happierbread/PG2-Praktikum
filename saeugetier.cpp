#include "saeugetier.h"
#include <iostream>
using namespace std;

Saeugetier::Saeugetier(bool rudelTier, int tragzeit, double durschnittsgewicht, const string &bezeichung, bool gefaehrdet, bool raubtier) : Tier(bezeichung, gefaehrdet, raubtier),
    m_rudelTier(rudelTier),
    m_tragzeit(tragzeit),
    m_durschnittsgewicht(durschnittsgewicht)
{}


void Saeugetier::TiereAnzeigen()
{
cout<<"-------------------------------------------------------------"<<endl;
cout<<"Tier: Saeugetier"<<endl;
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
    ausgabe.close();


}

void Saeugetier::deserialize(ifstream& eingabe)
{
    Tier::serialize(eingabe);
    eingabe.read((char*)&m_rudelTier, sizeof(m_rudelTier));
    eingabe.read((char*)&m_tragzeit, sizeof(m_tragzeit));
    eingabe.read((char*)&m_durschnittsgewicht, sizeof(m_durschnittsgewicht));
    eingabe.close();

}

