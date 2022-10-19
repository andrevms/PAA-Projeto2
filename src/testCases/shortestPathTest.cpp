
#include "shortestPathTest.hpp"

ShortestPathTest::ShortestPathTest(){}
ShortestPathTest::~ShortestPathTest(){}

void ShortestPathTest::toStringVetor(int* vetor, int size) {
  for (size_t i = 0; i < size; i++)
  {
        std::cout << vetor[i] << " ";
  }
}

void ShortestPathTest::shortestPathComMatriz5x5() {
  std::cout << "Teste00 shortestPathComMatriz5x5\n";
    
    int size = 5;
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
    int start = 0;
    int target = 4;
    bool nodesVisitados[] = {0,0,0,0,0};

    int* dijkstra = Dijkstra(start, target, size, matrizAdjacente, nodesVisitados);
    int sizeVetorEsperado = 2;
    int valorEsperado[] = {0,4};

    std::cout << "Dijkstra Recebido ";
    toStringVetor(dijkstra, (sizeof(dijkstra)/sizeof(int)));
   
    std::cout << "\nValor esperado ";
    toStringVetor(valorEsperado, sizeVetorEsperado);

    
    // Asserts
    bool flag = false;
    std::cout << "\n";
    for (size_t i = 0; i < sizeVetorEsperado; i++)
    {
      if (! (dijkstra[i] == valorEsperado[i])) { 
        std::cout << "Erro dijkstra[" << i << "] != valorEsperado[i]\n";
        flag = true;
      }
    }
    
    assert(flag == false);
    
}
