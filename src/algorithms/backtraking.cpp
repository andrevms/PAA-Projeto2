#include "backtraking.hpp"

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

    std::cout << "Caminho : ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << caminho[i] << " ";
    }
       std::cout << "\n";
    if (accept(container, caminho, size))
    {
        //std::cout << " Caminho Aceito\n\n";
    }else {
        //std::cout << " Caminho Rejeitado\n\n";
    }

    if (size == container.numCidades)
    {
        //std::cout << "Caminho terminado - Size Atual igual o numCidades - Mudar de folha --> size : " << size << "\n";
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

    int cotaDoCaminho = 0;
    for (size_t i = 0; i < size; i++)
    {
        cotaDoCaminho += container.bonus[i];
    }

    if (cotaDoCaminho >= container.cotaMinima)
    {
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

    //Caso seja o root
    if(size == 0) {
        entradas[0] = 0;
        return entradas;
    }

    
    //Caso em que ja exista entradas no caminho
    //Cria array auxiliar com entradas, colocando 1 como valor existente no array
    for (size_t i = 0; i < size; i++)
    {
        entradas[caminho[i]] = 1;
    }

    //Proxima entrada recebe o valor do primeiro numero disponivel varendo da esquerda para direita
    for (size_t i = 0; i < container.numCidades; i++)
    {
        if (entradas[i] == -1)
        {
            int *novoCaminho = new int[container.numCidades];
            for (size_t j = 0; j < container.numCidades; j++){ novoCaminho[j] = caminho[j]; }
            novoCaminho[size] = i;
            return novoCaminho;
        }
    }

    //Se não encontrar nenhuma entrada a direita retorna nullptr
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

    if(size == 0 ) {
        std::cerr << "ERRO NEXT --> SIZE = 0";
        exit(-1);
    }

    //Como é caixeiro viajante sempre se inicia no 0
    if(size == 1) {
        return nullptr;
    }

    //Caso em que não tem mais next
    if(size == container.numCidades ) {
        return nullptr;
    }

    //Caso em que não tem mais next
    if(caminho[size-1] == container.numCidades-1) {
        return nullptr;
    }

    //Com mais de 1 elemento
    //Troca a ultima cidade pela proxima cidade a direita disponivel
    int *entradas = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        entradas[i] = -1;
    }

    for (size_t i = 0; i < size; i++)
    {
        entradas[caminho[i]] = 1;
    }

    //ultimoElemento é a ultima cidade que foi selecionada
    int ultimoElemento = caminho[size-1];

    while (entradas[ultimoElemento] != -1 && ultimoElemento < container.numCidades)
    {
        ultimoElemento++;
    }

    if (ultimoElemento == container.numCidades)
    {
        return nullptr;
    }
    

    //Cria novo caminho com ultimoElemento encontrado como ultimo Valor
    int *novoCaminho = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        novoCaminho[i] = caminho[i];
    }

    novoCaminho[size-1] = ultimoElemento;

    return novoCaminho;
}
