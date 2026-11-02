#include <iostream>
#include <fstream>
#include <tier.h>
#include <vogel.h>
#include <reptil.h>
#include<saeugetier.h>
using namespace std;

int main()
{
    bool end=false;

    vector<Tier*> Tierliste;

    do{

        int menu=0;
        cout<<"1.Tier anlegen"<<endl;
        cout<<"2.Alle Tiere anzeigen"<<endl;
        cout<<"3.Binaer speichern"<<endl;
        cout<<"4.Binaer laden"<<endl;
        cout<<"5.Binaere Testdatei erzeugen"<<endl;
        cout<<"6.Beenden"<<endl;
        cout<<"Waehlen sie eine Nummer (1-6)"<<endl;
        cin>>menu;
        switch(menu){
        case 1:{

            int animalnummer=0;
            cout<<"Welches Tier wollen Sie erstellen?"<<endl;
            cout<<"1.Sauegietier "<<endl;
            cout<<"2.Vogel "<<endl;
            cout<<"3.Reptil"<<endl;
            cin>>animalnummer;


            switch(animalnummer){
            case 1:{
                Tier* tier= new Saeugetier();
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            case 2:{
                Tier* tier=new Vogel();
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            case 3:{
                Tier* tier= new Reptil();
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            default:{
                cout<<"waehlen sie ein passendes Nummer!"<<endl;
                break;
            }
            }
            break;
        }




        case 2:{
            if(!Tierliste.empty()){
                for(auto a:Tierliste){
                a->TiereAnzeigen();
            }
            }else{
                cout<<"Es ist leer!"<<endl;
            }
            break;
        }

        case 3:{


            if(Tierliste.empty()){
                cout<<"Es ist leer"<<endl;
            } else{
                string dateiname;
                cout<<"Wie wird die Datei heissen? "<<endl;
                cin>>dateiname;
                ofstream ausgabe;
                ausgabe.open(dateiname,ios::out|ios::binary);
                for(auto a:Tierliste){
                    a->serialize(ausgabe);
                }

            }
            cout<<"Datei erfolgreich gespeichert!"<<endl;
            break;

        }
        case 4:{
            /*if(Tierliste.empty()){
                cout<<"Es ist leer!"<<endl;

            }else {
                for(auto a: Tierliste){
                    a->deserialize();
                }
            }
*/

        }
        case 5:
        {}
        case 6:{
            end=true;
            break;
        }
        default:{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
            break;
        }
        }


    }while(end==false);
}
