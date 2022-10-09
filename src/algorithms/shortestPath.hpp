#ifndef DIJSKTRA
#define DIJSKTRA

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

std::list<int> Dijkstra(int start, int target, int size, int** mat, bool* visited_in_earlier_runs);

#endif