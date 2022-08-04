#ifndef bestpath_HPP
#define bestpath_HPP
using namespace std;
#include <stdio.h>
#include <iostream>
#include <limits.h>

class bestpath
{
private:
    float** costpath; // best way that include both items trafic and distance
    float** distance; // find distance of best way
    int* store;       // store nodes for find path(store previous node)
    int g_size = 0;
    float dijkstra(int check);  //algorithm for find best path
    int minimumdis(float [], bool[]); 

public:
    bestpath(float **graph,float **dis, int size); //constructor
    ~bestpath();//distructor
    void showpath(int check);
    int nodepath();

};
#endif