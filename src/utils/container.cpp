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

    fileName = caminho;
    getline(myfile, line);
    stringstream stream(line);

    int numAuxCidades;
    stream >> numAuxCidades;
    numCidades = numAuxCidades;

    int numAuxCarros;
    stream >> numAuxCarros;
    numCarros = numAuxCarros;
    stream >> cotaMinima;

    bonus = new int[numAuxCidades];

    getline(myfile, line);
    getline(myfile, line);
    stringstream stream2(line);
    for (size_t i = 0; i < numAuxCidades; i++)
    {
      stream2 >> bonus[i];
    }

    matrizAdjacente = new int **[numAuxCarros];
    for (size_t i = 0; i < numAuxCarros; i++)
    {
      matrizAdjacente[i] = new int *[numAuxCidades];
    }
    for (size_t i = 0; i < numAuxCarros; i++)
    {
      for (size_t j = 0; j < numAuxCidades; j++)
      {
        matrizAdjacente[i][j] = new int[numAuxCidades];
      }
    }

    for (size_t w = 0; w < numAuxCarros; w++)
    {
      getline(myfile, line);

      for (size_t i = 0; i < numAuxCidades; i++)
      {
        getline(myfile, line);
        stringstream stream2(line);
        for (size_t j = 0; j < numAuxCidades; j++)
        {
          stream2 >> matrizAdjacente[w][i][j];
        }
      }
    }
  }
  else
    cout << "Unable to open file";
}
void Container::imprimir()
{
  cout << numCidades << ' ' << numCarros << ' ' << cotaMinima << '\n'
       << bonus[0] << ' '
       << bonus[1] << ' '
       << bonus[2] << ' '
       << bonus[3] << ' '
       << bonus[4] << '\n'
       << '\n';

   for (size_t w = 0; w < numCarros; w++)
   {
      for (size_t i = 0; i < numCidades; i++)
      {
        for (size_t j = 0; j < numCidades; j++)
        {
          cout << matrizAdjacente[w][i][j] << ' ';
        }
        cout << '\n';
      }
      cout << '\n';
    }
}