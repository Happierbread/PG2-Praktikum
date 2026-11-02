#include "tier.h"
#include <iostream>
using namespace std;

int Tier::getanzahl() const
{
    return m_anzahl;
}

Tier::Tier()
{
    bool gefaehrdet=false;
    int rb,gf;
    cout<<"Bezeichnung fuer das Tier: "<<endl;
    cin>>m_bezeichung;
    do{
    cout<<"gefaehrdet?"<<endl;
    cout<<"1. ja"<<endl;
    cout<<"2. nein"<<endl;
    cin>>gf;
    if(gf==1){
        m_gefaehrdet=true;
        gefaehrdet=true;
    }
    else if(gf==2){
        m_gefaehrdet= false;
        gefaehrdet=true;
    } else{
        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
    }
    } while(gefaehrdet==false);

    cout<<"raubtier?"<<endl;
    cout<<"1. ja"<<endl;
    cout<<"2. nein"<<endl;
    cin>>rb;
    if(rb==1){
        m_raubtier=true;
    }
    else if(rb==2){
        m_raubtier= false;
    } else{
        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
    }


}

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




