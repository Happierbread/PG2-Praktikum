#ifndef VOGEL_H
#define VOGEL_H

#include "tier.h"

class Vogel : public Tier
{
public:
    Vogel();
    void TiereAnzeigen();
    void serialize(ofstream& ausgabe);
    void deserialize(ifstream& eingabe);
private:
    bool m_zugvogel;
    double m_flugreichweite;
    double m_fluegelspannweite;

};

#endif // VOGEL_H
