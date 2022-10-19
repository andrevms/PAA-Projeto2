
#include "shortestPathTest.hpp"

ShortestPathTest::ShortestPathTest(){}
ShortestPathTest::~ShortestPathTest(){}

void ShortestPathTest::shortestPathComMatriz5x5() {

    int start = 0;
    int target = 4;
    int size = 5;
    bool nodesVisitados[5] = {0,0,0,0,0};

    int** matrizAdjacente = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
      matrizAdjacente[i] = new int [size];
    }

    for (size_t i = 0; i < size; i++)
    {
      for (size_t j = 0; j < size; j++)
      {
        matrizAdjacente[i][j] = i+j;
        std::cout << matrizAdjacente[i][j] << ' ';
      }
      std::cout << '\n';
    }
/*  
    matrizAdjacente
    0 1 2 3 4 
    1 2 3 4 5
    2 3 4 5 6
    3 4 5 6 7
    4 5 6 7 8
*/
    int* dijkstra = Dijkstra(start, target, size, matrizAdjacente, nodesVisitados);
    int valorEsperado[2] = {0,4};

    std::cout << "Dijkstra ";
    for (size_t i = 0; i < (sizeof(dijkstra)/sizeof(int)); i++)
    {
        std::cout << dijkstra[i] << " ";
    }
    
    _ASSERT_EXPR(dijkstra[0] == valorEsperado[1], " Teste1");
    assert(dijkstra[0] == valorEsperado[0]);
    assert(dijkstra[1] == valorEsperado[1]);
}
