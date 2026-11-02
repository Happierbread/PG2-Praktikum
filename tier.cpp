#include "tier.h"
#include <iostream>
using namespace std;

int Tier::getanzahl() const
{
    return m_anzahl;
}

Tier::Tier(const string &bezeichung, bool gefaehrdet, bool raubtier) : m_bezeichung(bezeichung),
    m_gefaehrdet(gefaehrdet),
    m_raubtier(raubtier)
{}




void Tier:: TiereAnzeigen()
{

    cout<<"Bezeichnung: "<<m_bezeichung<<endl;
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

void Tier::deserialize(ifstream&eingabe)
{
    if(!eingabe){
        cerr<<"Fehlermeldung!"<<endl;
    }
    else{
        eingabe.write((char*)&m_bezeichung, sizeof(m_bezeichung));
        eingabe.write((char*)&m_gefaehrdet, sizeof(m_gefaehrdet));
        eingabe.write((char*)&m_raubtier, sizeof(m_raubtier));
    }

}

void Tier::serialize(ofstream& ausgabe)
{

    if(!ausgabe){
        cerr<<"Fehlermeldung!"<<endl;
    }
    else{
        ausgabe.write((char*)&m_bezeichung, sizeof(m_bezeichung));
        ausgabe.write((char*)&m_anzahl, sizeof(m_anzahl));
        ausgabe.write((char*)&m_gefaehrdet, sizeof(m_gefaehrdet));
        ausgabe.write((char*)&m_raubtier, sizeof(m_raubtier));
    }
}





