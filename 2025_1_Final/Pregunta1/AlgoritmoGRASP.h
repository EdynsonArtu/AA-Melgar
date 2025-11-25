#ifndef PREGUNTA1_ALGORITMOGRASP_H
#define PREGUNTA1_ALGORITMOGRASP_H
#include "ETT.h"

class AlgoritmoGRASP {
private:
    ETT eet;
    double alpha;
public:
    AlgoritmoGRASP(ETT eet, double alpha);

    vector<int> construccion();
};


#endif //PREGUNTA1_ALGORITMOGRASP_H