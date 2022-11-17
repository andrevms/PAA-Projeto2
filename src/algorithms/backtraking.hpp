#ifndef BACKTRAKING_H
#define BACKTRAKING_H

#include "container.hpp"
#include <vector>

void backtraking(Container container);
void backtraking(Container container, int* caminho);
bool accept(Container container, int *caminho, int size);
int* first(Container container, int* caminho, int size);
int* next(Container container, int* caminho);
void printOutput(Container container);
#endif
