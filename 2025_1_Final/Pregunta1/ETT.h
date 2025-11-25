#ifndef PREGUNTA1_ETT_H
#define PREGUNTA1_ETT_H
#include <vector>
#define CON_CONFLICTO 1
#define SIN_CONFLICTO 0
#define TIENE_EXAMEN 1

using namespace std;

class ETT {
private:
    int numero_examenes;
    int numero_estudiantes;
    vector<vector<int>> R;
    vector<vector<int>> conflictos;
    vector<int> slots_disponible;
public:
    ETT(vector<vector<int>> R, int cantidad_slots);

    ETT();

    int grado(int examen);

    void imprimir(const vector<int> &solucion);

    int get_numero_examenes() const;

    void set_numero_examenes(int numero_examenes);

    int get_numero_estudiantes() const;

    void set_numero_estudiantes(int numero_estudiantes);

    vector<vector<int>> get_r() const;

    void set_r(const vector<vector<int>> &r);

    vector<vector<int>> get_conflictos() const;

    void set_conflictos(const vector<vector<int>> &conflictos);

    vector<int> get_slots_disponible() const;

    void set_slots_disponible(const vector<int> &slots_disponible);
};


#endif //PREGUNTA1_ETT_H