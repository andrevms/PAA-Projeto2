#include "backtraking.hpp"

void backtraking(Container container) {

    int *caminho = new int[container.numCidades];
    for (size_t i = 0; i < container.numCidades; i++)
    {
        caminho[i] = -1;
    }
    
    std::cout <<"numCidades "<< container.numCidades <<"\nSizeofCaminho " << (sizeof(caminho)) << "\n";
   backtraking(container, caminho);
}

void backtraking(Container container,int *caminho) {

    std::cout << "It 1 \n " << (sizeof(caminho)/sizeof(int)) << " " << caminho[1] << "\n";

    if (reject(container, caminho)) {
        std::cout << "Caminho Rejeitado ";
        for (size_t i = 0; i < (sizeof(caminho)/sizeof(int)); i++)
        {
            std::cout << caminho[i] << " ";
            
        }
        std::cout << "\n";
        return;
    }

    if( accept(container, caminho)) {
        std::cout << "Caminho Aceito ";
        for (size_t i = 0; i < (sizeof(caminho)/sizeof(int)); i++)
        {
            std::cout << caminho[i] << " ";
            
        }
        std::cout << "\n";
    }


    int *s = new int[container.numCidades];
    s = first(container, caminho);

    while (s != NULL )
    {
        backtraking(container, s);
        s = next(container, s);
    }
    

}
/*
s ← first(P, c)
    while s ≠ NULL do
        backtrack(P, s)
        s ← next(P, s)
*/

bool reject(Container container, int* caminho) {
    int cotaDoCaminho = 0;
    for (size_t i = 0; i < (sizeof(caminho)/sizeof(int)); i++)
    {
        cotaDoCaminho += container.bonus[i];
    }
    
    if ( cotaDoCaminho >= container.cotaMinima) {
        return false;
    }

    return true;
}

bool accept(Container container, int* caminho) {

    int cotaDoCaminho = 0;
    for (size_t i = 0; i < (sizeof(caminho)/sizeof(int)); i++)
    {
        cotaDoCaminho += container.bonus[i];
    }
    
    if ( cotaDoCaminho >= container.cotaMinima) {
        return true;
    }

    return false;
}


int* first(Container container, int* caminho) {


    int numEntradas = container.numCidades;
    int* entradas = new int [numEntradas];

    for (size_t i = 0; i < numEntradas; i++)
    {
        entradas[i] = 0;
    }
    
    int proximaEntrada = 0;
    for (size_t i = 0; i < (sizeof(caminho)/sizeof(int)); i++)
    {
        entradas[caminho[i]] = 1; 
    }

   for (size_t i = 0; i < numEntradas; i++)
    {
        if(entradas[i] == 0){
            proximaEntrada = i;
            break;
        }
    }
    

    caminho[(sizeof(caminho)/sizeof(int))+ 1 ] = proximaEntrada;
    
    return caminho;
}


int* next(Container container, int* caminho) {

    int numEntradas = container.numCidades;
    int* entradas = new int [numEntradas];

    for (size_t i = 0; i < numEntradas; i++)
    {
        entradas[i] = 0;
    }
    
    int proximaEntrada = 0;
    for (size_t i = 0; i < (sizeof(caminho)/sizeof(int)); i++)
    {
        entradas[caminho[i]] = 1; 
    }

    int i = caminho[(sizeof(caminho)/sizeof(int)) -1];
    while(entradas[caminho[i]] != 0 ){
        i++;
    }   

    if( i >= numEntradas){
        return NULL;
    }
    caminho[(sizeof(caminho)/sizeof(int))+ 1 ] = i;
    
    return caminho;
}
