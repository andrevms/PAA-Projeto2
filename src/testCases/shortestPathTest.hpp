#ifndef SHORTESTPATHTEST_H
#define SHORTESTPATHTEST_H

#include <iostream>
#include <climits>
#include <cassert>
#include <assert.h>
#include "shortestPath.hpp"



class ShortestPathTest { 
  public:            
    ShortestPathTest();
    ~ShortestPathTest();
    void shortestPathComMatriz5x5();
    void toStringVetor(int* vetor, int size);
};

#endif