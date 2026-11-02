#ifndef TIER_H
#define TIER_H
#include <vector>
#include <string>
#include<fstream>
using namespace std;

class Tier
{
private:
    string m_bezeichung;
    bool m_gefaehrdet;
    bool m_raubtier;
    int m_anzahl=0;
protected:
    virtual int zeichen;


public:
    Tier(const string &bezeichung, bool gefaehrdet, bool raubtier);
    virtual void TiereAnzeigen();
    virtual ~Tier()=default;
    virtual void serialize(ofstream& ausgabe)=0;
    virtual void deserialize(ifstream& eingabe)=0;
    int getanzahl() const;
};

#endif // TIER_H
