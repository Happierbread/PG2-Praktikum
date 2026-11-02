#ifndef SAEUGETIER_H
#define SAEUGETIER_H

#include "tier.h"

class Saeugetier : public Tier
{
public:
    Saeugetier();
    void TiereAnzeigen();
    void serialize(ofstream& ausgabe);
    void deserialize(ifstream&);
private:
    bool m_rudelTier;
    int m_tragzeit;
    double m_durschnittsgewicht;
};

#endif // SAEUGETIER_H
