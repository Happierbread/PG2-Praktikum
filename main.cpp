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
    string s_bezeichung;
    bool s_gefaehrdet,s_raubtier;
    int s_anzahl,s_zeichen;

    vector<Tier*> Tierliste;

    do{

        int menuNummer=0;
        cout<<"1.Tier anlegen"<<endl;
        cout<<"2.Alle Tiere anzeigen"<<endl;
        cout<<"3.Binaer speichern"<<endl;
        cout<<"4.Binaer laden"<<endl;
        cout<<"5.Binaere Testdatei erzeugen"<<endl;
        cout<<"6.Beenden"<<endl;
        cout<<"Waehlen sie eine Nummer (1-6)"<<endl;
        cin>>menuNummer;
        switch(menuNummer){
        case 1:{

            int animaltype=0;
            cout<<"Welches Tier wollen Sie erstellen?"<<endl;
            cout<<"1.Sauegietier "<<endl;
            cout<<"2.Vogel "<<endl;
            cout<<"3.Reptil"<<endl;
            cin>>animaltype;
            bool gefaehrdetValidierung=false;
            int raubtierWaehler,gefaehrdetWaehler;


            cout<<"Bezeichnung fuer das Tier: "<<endl;
            cin>>s_bezeichung;
            cout<<"Anzahl der Tiere: "<<endl;
            cin>>s_anzahl;
            do{
                cout<<"Gefaehrdet?"<<endl;
                cout<<"1. ja"<<endl;
                cout<<"2. nein"<<endl;
                cin>>gefaehrdetWaehler;
                if(gefaehrdetWaehler==1){
                    s_gefaehrdet=true;
                    gefaehrdetValidierung=true;
                }
                else if(gefaehrdetWaehler==2){
                    s_gefaehrdet= false;
                    gefaehrdetValidierung=true;
                } else{
                    cout<<"Waehlen sie ein passendes Nummer!"<<endl;
                }
            } while(!gefaehrdetValidierung);

            cout<<"raubtier?"<<endl;
            cout<<"1. ja"<<endl;
            cout<<"2. nein"<<endl;
            cin>>raubtierWaehler;
            if(raubtierWaehler==1){
                s_raubtier=true;
            }
            else if(raubtierWaehler==2){
                s_raubtier= false;
            } else{
                cout<<"Waehlen sie ein passendes Nummer!"<<endl;
            }


            switch(animaltype){
            case 1:{
                s_zeichen=1;
                bool s_rudelTier;
                int s_tragzeit;
                double s_durchschnittsgewicht;

                int rudeltierWahl;
                bool rudeltierValidierung=false;
                do{
                    cout<<"Ist es ein Rudeltier?"<<endl;
                    cout<<"1. ja"<<endl;
                    cout<<"2. nein"<<endl;
                    cin>>rudeltierWahl;
                    if(rudeltierWahl==1){
                        s_rudelTier=true;
                        rudeltierValidierung=true;
                    }
                    else if(rudeltierWahl==2){
                        s_rudelTier=false;
                        rudeltierValidierung=true;
                    } else{
                        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
                    }
                } while(!rudeltierValidierung);
                cout<<"wie viele Tragzeit? (in Wochen) "<<endl;
                cin>>s_tragzeit;
                cout<<"wie viel ist der Gewicht durchschnittlich? (in kg)"<<endl;
                cin>>s_durchschnittsgewicht;


                Tier* tier= new Saeugetier(s_rudelTier,s_tragzeit,s_durchschnittsgewicht,s_bezeichung,s_gefaehrdet,s_raubtier,s_anzahl,s_zeichen);
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            case 2:{
                s_zeichen=2;
                bool s_zugvogel;
                double s_flugreichweite,s_fluegelspannweite;

                int zugvogelAusWahl;
                bool zugvogelValidierung=false;
                do{
                    cout<<"Ist es ein Zugvogel?"<<endl;
                    cout<<"1. ja"<<endl;
                    cout<<"2. nein"<<endl;
                    cin>>zugvogelAusWahl;
                    if(zugvogelAusWahl==1){
                        s_zugvogel=true;
                        zugvogelValidierung=true;
                    }
                    else if(zugvogelAusWahl==2){
                        s_zugvogel= false;
                        zugvogelValidierung=true;
                    } else{
                        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
                    }
                } while(!zugvogelValidierung);
                cout<<"wie viele Flugreichweite? (in kilometern)"<<endl;
                cin>>s_flugreichweite;
                cout<<"wie viel Fluegelspannweite? (in metern) "<<endl;
                cin>>s_fluegelspannweite;


                Tier* tier=new Vogel(s_zugvogel,s_flugreichweite,s_fluegelspannweite,s_bezeichung,s_gefaehrdet,s_raubtier,s_anzahl,s_zeichen);
                Tierliste.push_back(tier);
                cout<<"Tier erfolgreich hinzugefeugt!"<<endl;
                break;

            }
            case 3:{
                s_zeichen=3;
                bool s_giftig,s_wechselwarm;
                double s_optimaleTemperatur;


                int giftigAuswahl,wechselwarmAuswahl;
                bool giftigValidierung=false;
                bool wechselwarmValidierung=false;
                do{
                    cout<<"Ist es giftig?"<<endl;
                    cout<<"1. ja"<<endl;
                    cout<<"2. nein"<<endl;
                    cin>>giftigAuswahl;
                    if(giftigAuswahl==1){
                        s_giftig=true;
                        giftigValidierung=true;
                    }
                    else if(giftigAuswahl==2){
                        s_giftig= false;
                        giftigValidierung=true;
                    } else{
                        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
                    }
                } while(!giftigValidierung);

                do{
                    cout<<"Wechselwarmestier?"<<endl;
                    cout<<"1. ja"<<endl;
                    cout<<"2. nein"<<endl;
                    cin>>wechselwarmAuswahl;
                    if(wechselwarmAuswahl==1){
                        s_wechselwarm=true;
                        wechselwarmValidierung=true;
                    }
                    else if(wechselwarmAuswahl==2){
                        s_wechselwarm= false;
                        wechselwarmValidierung=true;
                    } else{
                        cout<<"Waehlen sie ein passendes Nummer!"<<endl;
                    }
                } while(!wechselwarmValidierung);
                cout<<"wie viel ist die Optimaletemperatur? (in Celcius) "<<endl;
                cin>>s_optimaleTemperatur;
                Tier* tier= new Reptil(s_giftig,s_optimaleTemperatur,s_wechselwarm,s_bezeichung,s_gefaehrdet,s_raubtier,s_anzahl,s_zeichen);
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
            Tier* tier= new Reptil(false,20,false,"Test",false,true,10,3);
            tier->serialize(testdatei);
            cout<<"Testdatei erfolgreich erstellt!"<<endl;
            testdatei.close();
            break;
        }
        case 6:{
            for(auto a : Tierliste){
                delete a;
            }
            Tierliste.clear();
            end=true;
            break;
        }
        default:{
            cout<<"Waehlen sie ein passendes Nummer!"<<endl;
            break;
        }
        }


    }while(!end);
}
