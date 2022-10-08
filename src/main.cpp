#include <iostream>
#include <container.hpp>
using namespace std;

int main(int argc, char *argv[]) {
  Container a = Container();
  a.loadInfo(argv[1]);
  a.imprimir();
  cout << "Hello World!";
  return 0;
}