#ifndef TIER_H
#define TIER_H
#include <vector>
#include <string>
#include<fstream>
using namespace std;

class Tier
{
private:
    string m_bezeichnung;
    bool m_gefaehrdet;
    bool m_raubtier;
    int m_anzahl=0;
protected:
    int zeichen;


public:
    Tier(const string &bezeichnung, bool gefaehrdet, bool raubtier, int anzahl, int zeichen);
    virtual void TiereAnzeigen();
    virtual ~Tier();
    virtual void serialize(ofstream& ausgabe)=0;
    virtual void deserialize(ifstream& eingabe)=0;
    void setZeichen(int newZeichen);
};

#endif // TIER_H
