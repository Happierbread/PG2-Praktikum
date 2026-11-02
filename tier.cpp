#include "tier.h"
#include <iostream>
#include <fstream>
using namespace std;

int Tier::getanzahl() const
{
    return m_anzahl;
}


int Tier::getZeichen() const
{
    return zeichen;
}

void Tier::setZeichen(int newZeichen)
{
    zeichen = newZeichen;
}

Tier::Tier(const string &bezeichung, bool gefaehrdet, bool raubtier, int anzahl, int zeichen) : m_bezeichung(bezeichung),
    m_gefaehrdet(gefaehrdet),
    m_raubtier(raubtier),
    m_anzahl(anzahl),
    zeichen(zeichen)
{}





void Tier:: TiereAnzeigen()
{

    cout<<"Bezeichnung: "<<m_bezeichung<<endl;
    cout<<"Anzahl des Tiers: "<<m_anzahl<<endl;
    cout<<"Zeichen: "<<zeichen<<endl;
    cout<<"Gefaehrdet: ";
    if(!m_gefaehrdet){
        cout<<"nein"<<endl;
    } else cout<<"ja"<<endl;
    cout<<"Raubtier: ";
    if(!m_raubtier){
        cout<<"nein"<<endl;
    }
        else cout<<"ja"<<endl;
    }

Tier::~Tier()=default;

void Tier::deserialize(ifstream&eingabe)

{
    size_t laenge;
    eingabe.read((char*)&laenge, sizeof(laenge));
    m_bezeichung.resize(laenge);
    eingabe.read(&m_bezeichung[0], laenge);
    eingabe.read((char*)&m_anzahl, sizeof(m_anzahl));
    eingabe.read((char*)&m_gefaehrdet, sizeof(m_gefaehrdet));
    eingabe.read((char*)&m_raubtier, sizeof(m_raubtier));
}



void Tier::serialize(ofstream& ausgabe)

{
    ausgabe.write((char*)&zeichen, sizeof(zeichen));
        size_t length=m_bezeichung.size();
        ausgabe.write((char*)&length, sizeof(length));
        ausgabe.write(m_bezeichung.c_str(), length);

        ausgabe.write((char*)&m_anzahl, sizeof(m_anzahl));

        ausgabe.write((char*)&m_gefaehrdet, sizeof(m_gefaehrdet));
        ausgabe.write((char*)&m_raubtier, sizeof(m_raubtier));
    }






