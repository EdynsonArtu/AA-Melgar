#include "AlgoritmoGRASP.h"

AlgoritmoGRASP::AlgoritmoGRASP(ETT eet, double alpha) {
    this->eet = eet;
    this->alpha = alpha;
}

vector<int> AlgoritmoGRASP::construccion() {
    vector<int> asignacion(this->eet.get_numero_examenes(), -1);

    vector<int> examenes_pendientes;
    examenes_pendientes = this->construir_candidatos_no_elegidos();

    while (!examenes_pendientes.empty()) {
        int smin, smax;
        this->construir_puntajes_de_candidatos(examenes_pendientes, smin, smax);
        vector<int> RCL = this->formacion_de_la_RCL(examenes_pendientes, smin, smax);
        int elegido = this->eleccion_de_item_aleatorio(RCL);
        int slot = this->encontrar_slot(elegido, asignacion);
        asignacion[elegido] = slot;
        this->retirar_elegido_de_los_no_elegidos(elegido, examenes_pendientes);

    }
    return asignacion;
}
