#ifndef GRASP_H
#define GRASP_H

#include "container.hpp"
#include <vector>

void grasp(Container container, int numIteractions);
void initGreedySolution(Container container);
void localSearch2opt(int* path, int size, Container container);
void outputGRASP();
void deleteGRASP();
int somaValoresDoArray(int* array, int inicio, int fim);
int selectNodeFromIntervalo(int valRecebido, int* array, int size, int* bonus);
int valPath(int* array, int size, Container container);
int valPathBonus(int* array, int size, Container container);
int* swap2opt(int* path, int pathSize, int swapBegin, int swapEnd);

#endif
