#include "vogel.h"
#include <iostream>
using namespace std;
Vogel::Vogel()
{
    int wahl;
    bool zugvogel=false;
    do{
        cout<<"Ist es ein Zugvogel?"<<endl;
        cout<<"1. ja"<<endl;
        cout<<"2. nein"<<endl;
        cin>>wahl;
        if(wahl==1){
            m_zugvogel=true;
            zugvogel=true;
        }
        else if(wahl==2){
            m_zugvogel= false;
            zugvogel=true;
        } else{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
        }
    } while(zugvogel==false);
    cout<<"wie viele Flugreichweite? (in kilometern)"<<endl;
    cin>>m_flugreichweite;
    cout<<"wie viel Fluegelspannweite? (in metern) "<<endl;
    cin>>m_fluegelspannweite;
}

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
}


void Vogel::deserialize(ifstream&eingabe){

}
