#include "backtraking.hpp"

int *caminhoIdeal = nullptr;
int valorDoMelhorCaminho = -1;
int sizeMelhorCaminho = -1;
int melhorBonus = -1;

void backtraking(Container container)
{
    int *caminho = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        caminho[i] = -1;
    }

    backtraking(container, caminho);
}

void backtraking(Container container, int *caminho)
{
    int size = 0;
    for (size_t i = 0; i < container.numCidades; i++)
    {
        if (caminho[i] != -1)
        {
            size++;
        }
    }

    if (accept(container, caminho, size))
    {
        // std::cout << " Caminho Aceito\n\n";
    }
    else
    {
        // std::cout << " Caminho Rejeitado\n\n";
    }

    if (size == container.numCidades)
    {
        // std::cout << "Caminho terminado - Size Atual igual o numCidades - Mudar de folha --> size : " << size << "\n";
        return;
    }

    int *s = first(container, caminho, size);

    while (s != nullptr)
    {
        backtraking(container, s);
        s = next(container, s);
    }
}

bool accept(Container container, int *caminho, int size)
{
    if (size == 0 || size == 1)
    {
        return false;
    }

    int cotaDoCaminho = 0;
    int valorDoCaminho = 0;
    for (size_t i = 1; i < size; i++)
    {
        valorDoCaminho += container.matrizAdjacente[caminho[i - 1]][caminho[i]];
        // So soma o bonus quando sai da cidade
        cotaDoCaminho += container.bonus[caminho[i - 1]];
    }

    // Voltar para o node Inicial
    valorDoCaminho += container.matrizAdjacente[caminho[size - 1]][caminho[0]];
    // adicionando o ultimo bonus da cidade que vai para o inicio
    cotaDoCaminho += container.bonus[caminho[size - 1]];

    if (cotaDoCaminho >= container.cotaMinima)
    {
        if (valorDoMelhorCaminho < 0 || valorDoMelhorCaminho > valorDoCaminho)
        {
            valorDoMelhorCaminho = valorDoCaminho;

            if (caminhoIdeal != nullptr)
            {
                delete[] caminhoIdeal;
            }

            caminhoIdeal = new int[size + 1];
            for (size_t i = 0; i < size; i++)
            {
                caminhoIdeal[i] = caminho[i];
            }
            caminhoIdeal[size] = 0;
            sizeMelhorCaminho = size + 1;
            melhorBonus = cotaDoCaminho;
        }

        return true;
    }

    return false;
}

int *first(Container container, int *caminho, int size)
{
    int *entradas = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        entradas[i] = -1;
    }

    // Caso seja o root
    if (size == 0)
    {
        entradas[0] = 0;
        delete[] caminho;
        return entradas;
    }

    // Caso em que ja exista entradas no caminho
    // Cria array auxiliar com entradas, colocando 1 como valor existente no array
    for (size_t i = 0; i < size; i++)
    {
        entradas[caminho[i]] = 1;
    }

    // Proxima entrada recebe o valor do primeiro numero disponivel varendo da esquerda para direita
    int flag = -1;
    for (size_t i = 0; i < container.numCidades; i++)
    {
        if (entradas[i] == -1)
        {
            flag = i;
            break;
        }
    }

    delete[] entradas;

    if (flag != -1)
    {
        int *novoCaminho = new int[container.numCidades];
        for (size_t j = 0; j < container.numCidades; j++)
        {
            novoCaminho[j] = caminho[j];
        }
        novoCaminho[size] = flag;

        caminho = nullptr;
        delete caminho;
        return novoCaminho;
    }

    // Se não encontrar nenhuma entrada a direita retorna nullptr
    delete[] caminho;
    return nullptr;
}

int *next(Container container, int *caminho)
{
    int size = 0;
    for (size_t i = 0; i < container.numCidades; i++)
    {
        if (caminho[i] != -1)
        {
            size++;
        }
    }

    if (size == 0)
    {
        std::cerr << "ERRO NEXT --> SIZE = 0";
        exit(-1);
    }

    // Como é caixeiro viajante sempre se inicia no 0
    if (size == 1)
    {
        delete[] caminho;
        return nullptr;
    }

    // Caso em que não tem mais next
    if (size == container.numCidades)
    {
        delete[] caminho;
        return nullptr;
    }

    // Caso em que não tem mais next
    if (caminho[size - 1] == container.numCidades - 1)
    {
        delete[] caminho;
        return nullptr;
    }

    // Com mais de 1 elemento
    // Troca a ultima cidade pela proxima cidade a direita disponivel
    int *entradas = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        entradas[i] = -1;
    }

    for (size_t i = 0; i < size; i++)
    {
        entradas[caminho[i]] = 1;
    }

    // ultimoElemento é a ultima cidade que foi selecionada
    int ultimoElemento = caminho[size - 1];

    while (ultimoElemento < container.numCidades && entradas[ultimoElemento] != -1)
    {
        ultimoElemento++;
    }

    if (ultimoElemento == container.numCidades)
    {
        delete[] entradas;
        delete[] caminho;
        return nullptr;
    }

    // Cria novo caminho com ultimoElemento encontrado como ultimo Valor
    int *novoCaminho = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        novoCaminho[i] = caminho[i];
    }

    novoCaminho[size - 1] = ultimoElemento;

    delete[] entradas;
    delete[] caminho;
    return novoCaminho;
}

void printOutput(Container container)
{
    std::cout << "Melhor Caminho: valor [" << valorDoMelhorCaminho << "] | Bonus ["
              << melhorBonus << "] | Caminho : [ ";
    for (size_t i = 0; i < sizeMelhorCaminho; i++)
    {
        std::cout << caminhoIdeal[i] << " ";
    }
    std::cout << "]\n";
}