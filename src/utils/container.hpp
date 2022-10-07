#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>

using namespace std;

class Container { 
  public:            
    const int numCarros;
    const int numCidades;
    int*** matrizAdjacente;
    int* bonus;
    int* penalidade;
    Container loadInfo(std::string txt);
    void run();
};


#endif