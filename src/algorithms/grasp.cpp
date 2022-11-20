#include "grasp.hpp"

int *bestPath = nullptr;
int valBestPath = 999999999;
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
            //std::cout << "init Path : ";
            //for (size_t i = 0; i < sizePathGreedy; i++){std::cout << pathGreedy[i] << " ";}std::cout << " \n";
            //std::cout << "size " << sizePathGreedy << " valPath " << valPathGreedy << " bonus " << bonusPathGreedy << "\n";
        
        localSearch2opt(pathGreedy, sizePathGreedy ,container);
            //std::cout << "after 2opt : ";
            //for (size_t i = 0; i < sizePathGreedy; i++){std::cout << pathGreedy[i] << " ";}std::cout << " \n";
            //std::cout << "size " << sizePathGreedy << " valPath " << valPathGreedy << " bonus " << bonusPathGreedy << "\n\n";
        
        if (valBestPath > valPathGreedy)
        {
            delete[] bestPath;

            bestPath = new int[sizePathGreedy];
            for (size_t i = 0; i < sizePathGreedy; i++)
            {
                bestPath[i] = pathGreedy[i];
            }
            sizeBestPath = sizePathGreedy;
            valBestPath = valPathGreedy;
            bestBonus = bonusPathGreedy;
        }
    }

    std::cout << "Gbest : ";
            for (size_t i = 0; i < sizeBestPath; i++){std::cout << bestPath[i] << " ";}std::cout << " \n";
            std::cout << "size " << sizeBestPath << " valPath " << valBestPath << " bonus " << bestBonus << "\n\n";
}

void initGreedySolution(Container container)
{
    //inicia o caminho com tamanho maximo
    int* path = new int[container.numCidades+1];
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

    while (bonus <= container.cotaMinima)
    {
        int numNodePossiveis = container.numCidades - valSize;
        int randMax = somaValoresDoArray(bonusArray, 0, numNodePossiveis);
        int randNumber = rand()%randMax;
        int posicao = selectNodeFromIntervalo(randNumber, arrayNodesPossiveis, numNodePossiveis, bonusArray);

        /*
        std::cout << "NumNodePossiveis : " << numNodePossiveis << "\n";
        std::cout << "MAXRAND : " << randMax << "\n";
        std::cout << "randNumber : " << randNumber << "\n";
        std::cout << "posicao : " << posicao << "\n";
        for (size_t i = 0; i < numNodePossiveis; i++){std::cout << bonusArray[i] << " ";}std::cout << " \n";
        for (size_t i = 0; i < numNodePossiveis; i++){std::cout << arrayNodesPossiveis[i] << " ";}std::cout << " \n";
        */

        path[valSize] = arrayNodesPossiveis[posicao];
        bonus += bonusArray[posicao];
        arrayNodesPossiveis[posicao] = arrayNodesPossiveis[numNodePossiveis-1];
        bonusArray[posicao] = bonusArray[numNodePossiveis-1];
        valSize++;
        
        /*
        std::cout << "Bonus : " << bonus << "\n";
        for (size_t i = 0; i < valSize; i++){std::cout << path[i] << " ";}std::cout << " \n";
        std::cout << " \n";
        std::cout << " \n";*/
        
    }

    path[valSize] = 0;
    valSize++;
    //for (size_t i = 0; i < valSize+1; i++){std::cout << path[i] << " ";}std::cout << " \n";
    //std::cout << "valSize : " <<  valSize<< "\n";
    
    if (pathGreedy != nullptr) { delete[] pathGreedy; }
    pathGreedy = path;
    valPathGreedy = valPath(path, valSize,container);
    sizePathGreedy = valSize;
    bonusPathGreedy = bonus;

    delete[] bonusArray;
    delete[] arrayNodesPossiveis;
}

void localSearch2opt(int *path, int size, Container container)
{ 
    int* oldPath = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        oldPath[i]= path[i];
    }
    
    int numNodeSwap = size-1;

    int improvement = 0;
    do 
    {
        improvement = 0;

        for (int i = 1; i < size; i++) {
            for (int j = i + 1; j < numNodeSwap; j++) {
                //Nova rota
                int* newRoute = swap2opt(oldPath, size, i, j);
                //Valor do path
                int newRouteTotalValue = valPath(newRoute, size, container);
                int newRouteBonus = valPathBonus(newRoute, size, container);

                //Condição de melhoria
                if(newRouteTotalValue < valPathGreedy)
                { 
                    delete[] oldPath;
                    oldPath = new int[size];
                    for (size_t i = 0; i < size; i++)
                    {
                        oldPath[i] = newRoute[i];
                    }
                    
                    delete[] newRoute;

                    valPathGreedy = newRouteTotalValue;
                    improvement = 1;
                    
                    break;
                }

                delete[] newRoute;
                    
            }

            if(improvement == 1){
                break;
            }
        }
    } while(improvement == 1);


    delete[] pathGreedy;
    pathGreedy = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        pathGreedy[i] = oldPath[i];
    }
    delete[] oldPath;
    
}

int* swap2opt(int* path, int pathSize, int swapBegin, int swapEnd) {
    int* newPath = new int[pathSize];

    for (size_t i = 0; i < swapBegin; i++)
    {
        newPath[i] = path[i];
    }
    for (size_t i = swapBegin, y = 0; i <= swapEnd; i++, y++)
    {
        newPath[i] = path[swapEnd - y];
        //printf("s%d ", newRoute[i]);
    }

    for (size_t i = swapEnd+1; i < pathSize; i++)
    {
        newPath[i] = path[i];
    }

    return newPath;
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

int valPath(int* array, int size, Container container) {
    int val = 0;
    for (size_t i = 1; i < size; i++)
    {
        val += container.matrizAdjacente[array[i-1]][array[i]];
    }
    return val;
}

int valPathBonus(int* array, int size, Container container) {
    int bonus = 0;
    for (size_t i = 0; i < size; i++)
    {
        bonus += container.bonus[array[i]];
    }
    return bonus;
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
    
    /*std::cout <<"Intervalos\n";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arrayIntervalos[i]<< " ";
    }

    std::cout <<"\n";*/


    int posicao = 0;
    while(valRecebido > arrayIntervalos[posicao]) {
        posicao++;
    }
    
    delete[] arrayIntervalos;
    return posicao;
}