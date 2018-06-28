#include "aplicadorRectas.h"

void
AplicadorRectas::aplicar_rectas(matrix &imagen, vector<Recta> &rectas, vector<float> &velocidades, matrix &destino) {
    for (unsigned int i = 0; i < rectas.size(); ++i) {
        aplicar(i, rectas[i], imagen, destino, velocidades);
    }
}

void AplicadorRectas::aplicar(unsigned int posicion, Recta &recta, matrix &imagen, matrix &destino,
                              vector<float> &velocidades) {
    float velocidad = 0;

    Punto origen = recta.second;
    auto i = (float) origen.first;
    auto j = (float) origen.second;

    while (i < imagen.dame_filas() && 0 <= i && 0 <= j && j < imagen.dame_columnas()) {
        u_int i_destino = posicion;
        u_int j_destino = (imagen.dame_columnas() * (unsigned int) i) + (unsigned int) j;

        velocidad = velocidad + imagen.dame_elem_matrix((unsigned int) i, (unsigned int) j);
        destino.agregar_elemento(i_destino, j_destino, 1);
        dame_proximo_punto(recta, i, j);
    }

    velocidades[posicion] = velocidad;
}

void AplicadorRectas::dame_proximo_punto(Recta &recta, float &i, float &j) {
    float m = recta.first;
    (m >= 0) ? i++ : i--;
    j = j + abs(m);
}

