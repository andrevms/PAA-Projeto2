#include <iostream>
#include <container.hpp>
#include <climits>
#include <chrono>
#include <ctime>
#include "shortestPath.hpp"
#include "shortestPathTest.hpp"
#include "backtraking.hpp"
#include "grasp.hpp"
#include "container.hpp"

using namespace std;

int main(int argc, char *argv[])
{

  srand (time(NULL));
  auto start = chrono::steady_clock::now();
  Container a = Container();
  a.loadInfo(argv[1]);
  //a.imprimir();

  //backtraking(a);
  grasp(a, 200);

  auto end = chrono::steady_clock::now();
  //printOutput(a);

   cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
 
    //cout << "Elapsed time in microseconds: "
        //<< chrono::duration_cast<chrono::microseconds>(end - start).count()
        //<< " µs" << endl;
 
    //cout << "Elapsed time in milliseconds: "
        //<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
        //<< " ms" << endl;
 
    //cout << "Elapsed time in seconds: "
        //<< chrono::duration_cast<chrono::seconds>(end - start).count()
        //<< " sec\n";

  deleteGRASP();
  for (size_t i = 0; i < a.numCidades; i++)
  {
    delete[] a.matrizAdjacente[i];
  }
  delete[] a.matrizAdjacente;
  delete[] a.bonus;
  
  //ShortestPathTest a = ShortestPathTest();
  //a.shortestPathComMatriz5x5();
}


/*
 Container a = Container();
  a.loadInfo(argv[1]);
  // a.imprimir();

  bool *visited = new bool[a.numCidades];
  int *orderedNodes = new int[a.numCidades];
  int quota = 0;
  int used_car;
  int *best_run;
  int best_run_size;
  int best_run_cost;
  for (int i = 0; i < a.numCidades; i++)
  {
    visited[i] = false;
    orderedNodes[i] = i;
  }
  // ordenando as cidades por bonus com insertion sort
  for (int i = 1; i < a.numCidades; i++)
  {
    int j = i - 1;
    while (j >= 0 && a.bonus[orderedNodes[j]] < a.bonus[i])
    {
      orderedNodes[j + 1] = orderedNodes[j];
      j--;
    }
    orderedNodes[j + 1] = i;
  }
  // definindo node inicial como o com maior bonus
  int start = orderedNodes[0];

  // quota+=a.bonus[start];
  visited[start] = true;
  // solution[0]=start;
  // visited_counter++;

  while (quota < a.cotaMinima)
  {
    int target;
    // procurando o proximo node de maior bonus para definir como alvo
    for (int j = 1; j < a.numCidades; j++)
    {
      if (!visited[orderedNodes[j]])
      {
        target = orderedNodes[j];
        break;
      }
    }
    
    
//
    cout << "OrderedNodes ";
    for (size_t i = 0; i < a.numCidades; i++)
    {
      cout << orderedNodes[i] << ' ';
    }
    cout << '\n'; 
//
    for (int i = 0; i < a.numCarros; i++)
    {
//    

      cout << "Olhando o carro i --> " << i << " ";
      cout << "Visited ";
      for (size_t i = 0; i < a.numCidades; i++)
      {
        cout << visited[i] << ' ';
      }
      cout << '\n';
//
      // encontrando o caminho mais proximo ao alvo na matriz i
      int *current_run = Dijkstra(start, target, a.numCidades, a.matrizAdjacente[i], visited);
      int path_size = sizeof(current_run) / sizeof(int);

      int current_run_cost = 0;
      // calculando o custo da corrida na matriz i
      for (int j = 0; j < path_size - 1; j++)
      {
        current_run_cost += a.matrizAdjacente[i][current_run[j]][current_run[j + 1]];
        //cout << i << ' ' << j << ' ' << a.matrizAdjacente[i][current_run[j]][current_run[j + 1]] << "\n";
      }
      // se a corrida nessa matriz for melhor que nas outras, ou nao houver corrida registrada,
      // definir a melhor corrida como o resultado
      if (i == 0 || best_run_cost > current_run_cost)
      {
        used_car = i;
        best_run = current_run;
        best_run_size = path_size;
        best_run_cost = current_run_cost;
      }
      //-v
    }

    cout << "Carro usado " << used_car << " ";
      cout << "best_run ";
      for (size_t i = 0; i < best_run_size; i++)
      {
        cout << best_run[i] << ' ';
      }
      cout << '\n';
      cout << "Custo " << best_run_cost << " \n";
    //---IMPLEMENTAR
    // estando definida a melhor corrida, adiciona-la à solução e marcar seus vértices como visitados

    // melhor corrida
    //for (int n = 0; n < best_run_size; n++)
     // cout << best_run[n] << " ";
    //cout << "   " << best_run_size << "   " << best_run_cost << "\n";

    for (int i = 0; i < best_run_size; i++)
    {
      quota += a.bonus[best_run[i]];
      visited[best_run[i]] = true;
    }
    start = best_run[best_run_size-1];
    delete[] best_run;
    best_run_size = INT_MAX;
    best_run_cost = INT_MAX;

    cout << "Quota --> " << quota << "\n";
  }
  

  return 0;
*/