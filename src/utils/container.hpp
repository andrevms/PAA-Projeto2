#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include<sstream>
#include<ctype.h>

using namespace std;

class Container { 
  public:
    string fileName;             
    int numCidades;
    int numCarros;
    int cotaMinima;
    int*** matrizAdjacente;
    int* bonus;
    Container();
    ~Container();
    void loadInfo(string caminho);
    void imprimir();
};

#endif