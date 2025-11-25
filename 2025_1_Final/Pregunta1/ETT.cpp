#include "ETT.h"

#include <iostream>
#include <numeric>
#include <ostream>
#include <ranges>

ETT::ETT(vector<vector<int>> R, int cantidad_slots) {
    this->R = R;
    this->numero_estudiantes = R.size();
    this->numero_examenes = R[0].size();

    this->slots_disponible = vector<int>(cantidad_slots);
    iota(this->slots_disponible.begin(), this->slots_disponible.end(), 0);

    this->conflictos.assign(this->numero_examenes, vector<int>(this->numero_examenes, SIN_CONFLICTO));
    for (int e1=0; e1<this->numero_examenes; e1++) {
        for (int e2=0; e2<this->numero_examenes; e2++) {
            if (e1==e2)
                continue;
            if (this->conflictos[e1][e2]==CON_CONFLICTO)
                continue;
            for (int s=0; s<this->numero_estudiantes; s++) {
                if (this->R[s][e1]==TIENE_EXAMEN && this->R[s][e2]==TIENE_EXAMEN) {
                    this->conflictos[e1][e2] = CON_CONFLICTO;
                    this->conflictos[e2][e1] = CON_CONFLICTO;
                }
            }
        }

    }
}

ETT::ETT() {
    this->numero_estudiantes = 0;
    this->numero_examenes = 0;
}

int ETT::grado(int examen) {
    int cantidad = 0;
    for (int i=0; i<this->numero_examenes; i++) {
        if (this->conflictos[examen][i]==CON_CONFLICTO)
            cantidad++;
    }
    return cantidad;
}

void ETT::imprimir(const vector<int> &solucion) {
    cout << "Solución: " << endl;
    for (int i=0; i<solucion.size(); i++) {
        cout <<"\t"<<"Examen e" <<i << " : slot " << solucion[i] << endl;
    }
}

int ETT::get_numero_examenes() const {
    return numero_examenes;
}

void ETT::set_numero_examenes(int numero_examenes) {
    this->numero_examenes = numero_examenes;
}

int ETT::get_numero_estudiantes() const {
    return numero_estudiantes;
}

void ETT::set_numero_estudiantes(int numero_estudiantes) {
    this->numero_estudiantes = numero_estudiantes;
}

vector<vector<int>> ETT::get_r() const {
    return R;
}

void ETT::set_r(const vector<vector<int>> &r) {
    R = r;
}

vector<vector<int>> ETT::get_conflictos() const {
    return conflictos;
}

void ETT::set_conflictos(const vector<vector<int>> &conflictos) {
    this->conflictos = conflictos;
}

vector<int> ETT::get_slots_disponible() const {
    return slots_disponible;
}

void ETT::set_slots_disponible(const vector<int> &slots_disponible) {
    this->slots_disponible = slots_disponible;
}
