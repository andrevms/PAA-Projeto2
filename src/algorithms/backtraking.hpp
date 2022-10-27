#ifndef BACKTRAKING_H
#define BACKTRAKING_H

#include "container.hpp"
#include <vector>

void backtraking(Container container);
void backtraking(Container container, int* caminho);
bool reject(Container container, int* caminho);
bool accept(Container container, int *caminho);
int* first(Container container, int* caminho);
int* next(Container container, int* caminho);
int* output();
#endif
