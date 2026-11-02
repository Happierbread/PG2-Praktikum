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
    string m_bezeichung;
    bool m_gefaehrdet,m_raubtier;
    int m_anzahl,m_zeichen;

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
            bool gefaehrdet=false;
            int rb,gf;
            cout<<"Bezeichnung fuer das Tier: "<<endl;
            cin>>m_bezeichung;
            cout<<"Anzahl der Tiere: "<<endl;
            cin>>m_anzahl;
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


            switch(animalnummer){
            case 1:{
                m_zeichen=1;
                bool m_rudelTier;
                int m_tragzeit;
                double m_durchschnittsgewicht;

                int wahl;
                bool rudeltier=false;
                do{
                    cout<<"Ist es ein Rudeltier?"<<endl;
                    cout<<"1. ja"<<endl;
                    cout<<"2. nein"<<endl;
                    cin>>wahl;
                    if(wahl==1){
                        m_rudelTier=true;
                        rudeltier=true;
                    }
                    else if(wahl==2){
                        m_rudelTier=false;
                        rudeltier=true;
                    } else{
                        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
                    }
                } while(rudeltier==false);
                cout<<"wie viele Tragzeit? (in Wochen) "<<endl;
                cin>>m_tragzeit;
                cout<<"wie viel ist der Gewicht durchschnittlich? (in kg)"<<endl;
                cin>>m_durchschnittsgewicht;


                Tier* tier= new Saeugetier(m_rudelTier,m_tragzeit,m_durchschnittsgewicht,m_bezeichung,m_gefaehrdet,m_raubtier,m_anzahl,m_zeichen);
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            case 2:{
                m_zeichen=2;
                bool m_zugvogel;
                double m_flugreichweite,m_fluegelspannweite;

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


                Tier* tier=new Vogel(m_zugvogel,m_flugreichweite,m_fluegelspannweite,m_bezeichung,m_gefaehrdet,m_raubtier,m_anzahl,m_zeichen);
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            case 3:{
                m_zeichen=3;
                bool m_giftig,m_wechselwarm;
                double m_optimaleTemperatur;


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
                Tier* tier= new Reptil(m_giftig,m_optimaleTemperatur,m_wechselwarm,m_bezeichung,m_gefaehrdet,m_raubtier,m_anzahl,m_zeichen);
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
                cout<<"Wie wird die Datei genannt werden? "<<endl;
                cin>>dateiname;
                ofstream ausgabe;
                ausgabe.open(dateiname,ios::out|ios::binary);
                for(auto a:Tierliste){
                    a->serialize(ausgabe);
                }
                ausgabe.close();
                cout<<"Datei erfolgreich gespeichert!"<<endl;
                break;

            }


        }
        case 4:{
                string dateiname;
            cout<<"Dateiname: "<<endl;
                cin>>dateiname;
                ifstream eingabe;
                eingabe.open(dateiname,ios::in|ios::binary);
                if(!eingabe){
                    cerr<<"Existiert nicht!"<<endl;
                    break;
                }
                else{
                int zeichen;
                while(eingabe.read((char*)&zeichen, sizeof(zeichen))){
                    Tier* tier=nullptr;
                    if(zeichen==1){
                        tier=new Saeugetier(false,0,0,"",false,false,0,1);
                        cout<<"neues Saeugetier ist geladen!"<<endl;
                    } else if(zeichen==2){
                        tier=new Vogel(false,0,0,"",false,false,0,2);
                        cout<<"neue Vogel ist geladen!"<<endl;
                    } else if(zeichen==3){
                        tier=new Reptil(false,0,false,"",false,false,0,3);
                        cout<<"neue Reptil ist geladen!"<<endl;
                    } else {
                        break;
                    }
                    tier->deserialize(eingabe);
                    Tierliste.push_back(tier);
                }
                eingabe.close();
                cout<<"Datei erfolgreich geladen!"<<endl;
                break;
                }

                }
            \


        case 5:
        {
            ofstream testdatei;
            testdatei.open("testdatei.txt",ios::out|ios::binary);
            Tier* tier= new Reptil(false,72,false,"Test",false,true,10,3);
            tier->serialize(testdatei);
            cout<<"Testdatei erfolgreich erstellt!"<<endl;
            testdatei.close();
        }
        case 6:{


            break;
        }
        default:{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
            break;
        }
        }


    }while(end==false);
}
