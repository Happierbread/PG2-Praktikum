#include "tier.h"
#include <iostream>
#include <fstream>
using namespace std;

Tier::Tier(const string &bezeichnung, bool gefaehrdet, bool raubtier, int anzahl, int zeichen) : m_bezeichnung(bezeichnung),
    m_gefaehrdet(gefaehrdet),
    m_raubtier(raubtier),
    m_anzahl(anzahl),
    zeichen(zeichen)
{}





void Tier:: TiereAnzeigen()
{

    cout<<"Bezeichnung: "<<m_bezeichnung<<endl;
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
    size_t length;
    eingabe.read((char*)&length, sizeof(length));
    m_bezeichnung.resize(length);
    eingabe.read(&m_bezeichnung[0], length);
    eingabe.read((char*)&m_anzahl, sizeof(m_anzahl));
    eingabe.read((char*)&m_gefaehrdet, sizeof(m_gefaehrdet));
    eingabe.read((char*)&m_raubtier, sizeof(m_raubtier));
}



void Tier::serialize(ofstream& ausgabe)

{
        ausgabe.write((char*)&zeichen, sizeof(zeichen));
        size_t length=m_bezeichnung.size();
        ausgabe.write((char*)&length, sizeof(length));
        ausgabe.write(m_bezeichnung.c_str(), length); // constant

        ausgabe.write((char*)&m_anzahl, sizeof(m_anzahl));

        ausgabe.write((char*)&m_gefaehrdet, sizeof(m_gefaehrdet));
        ausgabe.write((char*)&m_raubtier, sizeof(m_raubtier));
    }






