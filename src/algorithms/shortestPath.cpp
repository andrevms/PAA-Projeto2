#include "shortestPath.hpp"
#include <climits>

//current: o node em que se inicia a busca
//target: o node em que se quer chegar
//size: o tamanho da matriz
//mat: a matriz a ser usada (dimensoes = size*size)
//visited_in_earlier_runs: a lista com todos os nos visitados e nao visitados da matriz (tamanho = size)
int* Dijkstra(int start, int target, int size, int** mat, bool* visited_in_earlier_runs){
    int current=start;
    bool* visited_in_current_run = new bool[size];
    /*inicializando a lista de vértices visitados na iteração atual de
    dijkstra excluindo os visitados em execuções anteriores, dado que o
    algoritmo fará o percurso várias vezes e concatenará os caminhos*/
    for (int i = 0; i < size; i++){
        visited_in_current_run[i] = visited_in_earlier_runs[i];
    }
    int* distance_to_node = new int[size];
    int* predecessor = new int[size];
    for(int i=0;i<size;i++){
        distance_to_node[i] = INT_MAX;
        predecessor[i] = -1;
    }
    std::list<int> queue;
    visited_in_current_run[current] = true;
    distance_to_node[current] = 0;
    queue.push_back(current);
    while (!queue.empty())
    {
        //std::cout<<queue.front();
        current = queue.front();
        queue.pop_front();
        for(int i=0;i<size;i++){
            if (visited_in_earlier_runs[i]) continue;
            if (current!=start && current==i) continue;
            if (visited_in_current_run[i]){
                if (distance_to_node[current]+mat[current][i] < distance_to_node[i])
                {
                    distance_to_node[i] = distance_to_node[current] + mat[current][i];
                    predecessor[i] = current;
                }
            }else{
                if(distance_to_node[current] == INT_MAX){
                    distance_to_node[current] = mat[current][i];
                }else{
                    if (distance_to_node[current]+mat[current][i] < distance_to_node[i])
                    {
                        distance_to_node[i] = distance_to_node[current] + mat[current][i];
                        predecessor[i] = current;
                    }
                    visited_in_current_run[i] = true;
                    queue.push_back(i);
                }
            }
        }
    }
    int i=target;
    std::list<int> path;
    path.push_front(target);
    while (i != start)
    {
        path.push_front(predecessor[i]);
        i=predecessor[i];
    }
    int* result = new int[path.size()];
    // std::cout<<path.size()<<"\n";
    int path_size=path.size();
    for (int i = 0; i < path_size; i++)
    {
        result[i]=path.front();
        path.pop_front();
        // std::cout<<result[i]<<" ";
    }
    return result;
};