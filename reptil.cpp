#include "reptil.h"
#include <iostream>
using namespace std;




Reptil::Reptil(bool giftig, double optimaleTemperatur, bool wechselwarm, const string &bezeichung, bool gefaehrdet, bool raubtier, int anzahl, int zeichen) : Tier(bezeichung, gefaehrdet, raubtier, anzahl, zeichen),
    m_giftig(giftig),
    m_optimaleTemperatur(optimaleTemperatur),
    m_wechselwarm(wechselwarm)
{}

void Reptil::TiereAnzeigen()
{
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Tier: Reptil"<<endl;
    Tier::TiereAnzeigen();
    cout<<"Optimale Temperatur: "<<m_optimaleTemperatur<<" Celcius "<<endl;
    cout<<"Giftig: ";
    if(!m_giftig){
        cout<<"nein"<<endl;
    } else cout<<"ja"<<endl;
    cout<<"Wechselwarm: ";
    if(!m_wechselwarm){
        cout<<"nein"<<endl;
    } else cout<<"ja"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
}

void Reptil::serialize(ofstream& ausgabe)
{
    Tier::serialize(ausgabe);
    ausgabe.write((char*)&m_optimaleTemperatur, sizeof(m_optimaleTemperatur));
    ausgabe.write((char*)&m_giftig, sizeof(m_giftig));
    ausgabe.write((char*)&m_wechselwarm, sizeof(m_wechselwarm));

}



void Reptil::deserialize(ifstream&eingabe)
{
    Tier::deserialize(eingabe);
    eingabe.read((char*)&m_giftig, sizeof(m_giftig));
    eingabe.read((char*)&m_optimaleTemperatur, sizeof(m_optimaleTemperatur));
    eingabe.read((char*)&m_wechselwarm, sizeof(m_wechselwarm));

}




