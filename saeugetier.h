#ifndef SAEUGETIER_H
#define SAEUGETIER_H

#include "tier.h"

class Saeugetier : public Tier
{
public:
    Saeugetier(bool rudelTier, int tragzeit, double durschnittsgewicht, const string &bezeichung, bool gefaehrdet, bool raubtier, int anzahl, int zeichen);
    void TiereAnzeigen();
    void serialize(ofstream& ausgabe);
    void deserialize(ifstream&);
private:
    bool m_rudelTier;
    int m_tragzeit;
    double m_durschnittsgewicht;
};

#endif // SAEUGETIER_H
