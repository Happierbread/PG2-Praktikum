#ifndef REPTIL_H
#define REPTIL_H

#include "tier.h"

class Reptil : public Tier
{
public:
    Reptil();
    void TiereAnzeigen();
    void serialize(ofstream& ausgabe);
    void deserialize(ifstream&);
private:
    bool m_giftig;
    double m_optimaleTemperatur;
    bool m_wechselwarm;
};

#endif // REPTIL_H
