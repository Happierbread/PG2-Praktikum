#include "vogel.h"
#include <iostream>
using namespace std;

Vogel::Vogel(bool zugvogel, double flugreichweite, double fluegelspannweite, const string &bezeichung, bool gefaehrdet, bool raubtier) : Tier(bezeichung, gefaehrdet, raubtier),
    m_zugvogel(zugvogel),
    m_flugreichweite(flugreichweite),
    m_fluegelspannweite(fluegelspannweite)
{}

void Vogel::TiereAnzeigen()
{
cout<<"-------------------------------------------------------------"<<endl;
cout<<"Tier: Vogel"<<endl;
 Tier::TiereAnzeigen();
cout<<"Flugreichweite: "<<m_flugreichweite<<" km "<<endl;
cout<<"Flugelspannweite: "<<m_fluegelspannweite<<" meter"<<endl;
cout<<"Zugvogel: ";
if(!m_zugvogel){
    cout<<"nein"<<endl;
} else cout<<"ja"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
}

void Vogel::serialize(ofstream& ausgabe)
{
    Tier::serialize(ausgabe);
    ausgabe.write((char*)&m_fluegelspannweite, sizeof(m_fluegelspannweite));
    ausgabe.write((char*)&m_flugreichweite, sizeof(m_flugreichweite));
    ausgabe.write((char*)&m_zugvogel, sizeof(m_zugvogel));
    ausgabe.close();
}


void Vogel::deserialize(ifstream&eingabe){

}


