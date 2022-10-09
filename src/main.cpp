#include <iostream>
#include <container.hpp>
#include "shortestPath.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  Container a = Container();
  a.loadInfo(argv[1]);
  // a.imprimir();
  bool* visited = new bool[5]{false};
  list<int> b = Dijkstra(0,4,a.numCidades,a.matrizAdjacente[0], visited);
  // list<int>::iterator it;
  // for (it = b.begin(); it != b.end(); ++it){
  //   cout<<*it<<" -> ";
  // }
  cout << "\nHello World!";
  return 0;
}