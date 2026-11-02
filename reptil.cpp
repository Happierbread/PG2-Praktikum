#include "reptil.h"
#include <iostream>
using namespace std;
Reptil::Reptil() {
    int wahl1,wahl2;
    bool giftig=false;
    bool wechselwarm=false;
    do{
        cout<<"Ist es giftig?"<<endl;
        cout<<"1. ja"<<endl;
        cout<<"2. nein"<<endl;
        cin>>wahl1;
        if(wahl1==1){
            m_giftig=true;
            giftig=true;
        }
        else if(wahl1==2){
            m_giftig= false;
            giftig=true;
        } else{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
        }
    } while(giftig==false);

    do{
        cout<<"Wechselwarmestier?"<<endl;
        cout<<"1. ja"<<endl;
        cout<<"2. nein"<<endl;
        cin>>wahl2;
        if(wahl2==1){
            m_wechselwarm=true;
            wechselwarm=true;
        }
        else if(wahl2==2){
            m_wechselwarm= false;
            wechselwarm=true;
        } else{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
        }
    } while(wechselwarm==false);
    cout<<"wie viel ist die Optimaletemperatur? (in Celcius) "<<endl;
    cin>>m_optimaleTemperatur;
}

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

}
