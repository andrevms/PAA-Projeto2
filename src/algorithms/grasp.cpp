#include "grasp.hpp"

int *bestPath = nullptr;
int valBestPath = -1;
int sizeBestPath = -1;
int bestBonus = -1;

int *pathGreedy = nullptr;
int valPathGreedy = -1;
int sizePathGreedy = -1;
int bonusPathGreedy = -1;

void grasp(Container container, int numIteractions)
{
    for (size_t i = 0; i < numIteractions; i++)
    {
        initGreedySolution(container);
        //print path
            //for (size_t i = 0; i < sizePathGreedy; i++){std::cout << pathGreedy[i] << " ";}std::cout << " \n";
        
        localSearch2opt(pathGreedy);

        if (valBestPath > valPathGreedy)
        {
            delete[] bestPath;

            bestPath = new int[sizePathGreedy];
            for (size_t i = 0; i < sizePathGreedy; i++)
            {
                bestPath[i] = pathGreedy[i];
            }
            sizeBestPath = sizePathGreedy;
            bestBonus = bonusPathGreedy;
        }
    }
}

void initGreedySolution(Container container)
{
    //inicia o caminho com tamanho maximo
    int* path = new int[container.numCidades+1];
    int valPath = 0;
    int valSize = 0;
    int bonus = 0;

    //array com os bonus
    int* bonusArray = new int[container.numCidades-1];
    for (size_t i = 1; i < container.numCidades; i++) { bonusArray[i-1] = container.bonus[i]; }
    //print array 
        //for (size_t i = 0; i < container.numCidades-1; i++){std::cout << bonusArray[i] << " ";}std::cout << " \n";
        
    //array com entradas possiveis
    int* arrayNodesPossiveis = new int[container.numCidades-1];
    for (size_t i = 1; i < container.numCidades; i++) { arrayNodesPossiveis[i-1] = i; }
    //print path    
        //for (size_t i = 0; i < container.numCidades-1; i++){std::cout << arrayNodesPossiveis[i] << " ";}std::cout << " \n";
    

    //Iniciando path em zero
    path[0] = 0;
    valSize++; // Adicionando +1 ao size do path
    bonus += container.bonus[0]; // Adicionando o bonus do node 0;

    do
    {
        int numNodePossiveis = container.numCidades - valSize;
        std::cout << "NumNodePossiveis : " << numNodePossiveis << "\n";
        if (numNodePossiveis == 0)
        {
            break;
        }
          
        int randMax = somaValoresDoArray(bonusArray, 0, numNodePossiveis);
        std::cout << "MAXRAND : " << randMax << "\n";
        
        int randNumber = rand()%randMax;
        std::cout << "randNumber : " << randNumber << "\n";
        
        int posicao = selectNodeFromIntervalo(randNumber, arrayNodesPossiveis, numNodePossiveis, bonusArray);
        std::cout << "posicao : " << posicao << "\n";

        bonus += bonusArray[posicao];
        path[valSize] = arrayNodesPossiveis[posicao];
        arrayNodesPossiveis[posicao] = arrayNodesPossiveis[numNodePossiveis];
        bonusArray[posicao] = bonusArray[numNodePossiveis];
        valSize++;

        std::cout << "Bonus : " << bonus << "\n";
    } while (bonus <= container.cotaMinima);
    
    path[valSize+1] = 0;

    if (pathGreedy != nullptr) { delete[] pathGreedy; }
    pathGreedy = path;
    valPathGreedy = valPath;
    sizePathGreedy = valSize;
    bonusPathGreedy = bonus;

    delete[] bonusArray;
    delete[] arrayNodesPossiveis;
}

void localSearch2opt(int *path)
{
}

void outputGRASP()
{
     std::cout << "Melhor Caminho: valor [" << valBestPath << "] | Bonus ["
              << bestBonus << "] | Caminho : [ ";
    for (size_t i = 0; i < sizeBestPath; i++)
    {
        std::cout << bestPath[i] << " ";
    }
    std::cout << "]\n";
}

void deleteGRASP() {
    delete[] bestPath;
    delete[] pathGreedy;
}

int somaValoresDoArray(int* array, int inicio, int fim) {
    int val = 0;
    for (size_t i = inicio; i < fim; i++)
    {
        val+= array[i];
    }
    return val;
}

int selectNodeFromIntervalo(int valRecebido, int* array, int size, int* bonus) {
    int* arrayIntervalos = new int[size];
    arrayIntervalos[0] = bonus[0];
    for (size_t i = 1; i < size; i++)
    {
        arrayIntervalos[i] = arrayIntervalos[i-1] + bonus[i];
    }

    for (size_t i = 0; i < size; i++)
    {
        std::cout << arrayIntervalos[i]<< " ";
    }

    std::cout <<"\n";
    
    int posicao = 0;
    while(valRecebido > arrayIntervalos[posicao]) {
        posicao++;
    }
    
    return posicao;
}