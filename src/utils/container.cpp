#include "container.hpp"

Container::Container() {}
Container::~Container() {}
void Container::loadInfo(string caminho)
{

  ifstream myfile;
  myfile.open(caminho);
  if (myfile.is_open())
  {
    string line;

    getline(myfile, line);
    stringstream stream(line);

    int numAuxCidades;
    stream >> numAuxCidades;
    numCidades = numAuxCidades;

    stream >> cotaMinima;

    bonus = new int[numAuxCidades];

    getline(myfile, line);
    getline(myfile, line);
    stringstream stream2(line);
    for (size_t i = 0; i < numAuxCidades; i++)
    {
      stream2 >> bonus[i];
    }

    matrizAdjacente = new int *[numAuxCidades];
    for (size_t i = 0; i < numAuxCidades; i++)
    {
      matrizAdjacente[i] = new int[numAuxCidades];
    }

    getline(myfile, line);

    for (size_t i = 0; i < numAuxCidades; i++)
    {
      getline(myfile, line);
      stringstream stream2(line);
      for (size_t j = 0; j < numAuxCidades; j++)
      {
        stream2 >> matrizAdjacente[i][j];
      }
    }
  }
  else
    cout << "Unable to open file";
}

void Container::imprimir()
{
  cout << numCidades << ' ' << ' ' << cotaMinima << '\n';

  for (size_t i = 0; i < numCidades; i++)
  {
    cout << bonus[i] << " ";
  }

  cout << '\n';

  for (size_t i = 0; i < numCidades; i++)
  {
    for (size_t j = 0; j < numCidades; j++)
    {
      cout << matrizAdjacente[i][j] << ' ';
    }

    cout << '\n';
  }
  cout << '\n';
}