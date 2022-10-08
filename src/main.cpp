#include <iostream>
#include <container.hpp>
using namespace std;

int main(int argc, char *argv[]) {
  Container a = Container();
  a.loadInfo(argv[1]);
  cout << "Hello World!";
  return 0;
}