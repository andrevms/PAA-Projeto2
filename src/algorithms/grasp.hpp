#ifndef GRASP_H
#define GRASP_H

#include "container.hpp"
#include <vector>

void grasp(Container container, int numIteractions);
void initGreedySolution(Container container);
void localSearch2opt(int* path);
void outputGRASP();
void deleteGRASP();
int somaValoresDoArray(int* array, int inicio, int fim);
int selectNodeFromIntervalo(int valRecebido, int* array, int size, int* bonus);
#endif
