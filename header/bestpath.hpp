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

// // implement Dijkstra's single source shortest path algorithm.

// // Number of vertices in the snappath
// #define V 15

// int minimumdis(float distance[], bool shortpath[]) // a function for find vertex with minimum distance value
// {
//     // Initialize min value
//     int min = INT_MAX;
//     int min_index = 0;

//     for (int v = 0; v < V; v++)
//         if (shortpath[v] == false && distance[v] <= min)
//         {
//             min = distance[v];
//             min_index = v;
//         }
//     return min_index;
// }

// // A utility function to print the constructed distance array
// void printSolution(float distance[], int n)
// {
//     printf("Vertex   Distance from Source\n");
//     for (int i = 0; i < V; i++)
//         printf("%d tt %f\n", i, distance[i]);
// }

// // implements dijkstra single source shortest path algorithm
// void dijkstra(float snappath[V][V], int src)
// {
//     float distance[V]; // this array store shortest path from source vertex

//     bool shortpath[V]; // shortpath[i] will be true if vertex i is included in shortest distance from source to i

//     // initialize all distances as INFINITE and shortpath[] as false
//     for (int i = 0; i < V; i++)
//         distance[i] = INT_MAX, shortpath[i] = false;

//     // distance of source vertex from itself is always 0
//     distance[src] = 0;

//     // find shortest path for all vertices
//     for (int count = 0; count < V - 1; count++)
//     {

//         // call find mindis function
//         int u = minimumdis(distance, shortpath);

//         // mark the picked vertex as processed
//         shortpath[u] = true;

//         // update distance value of the adjacent vertices of the picked vertex.
//         for (int v = 0; v < V; v++)

//             // Update distance[v] only if is not in shortpath, there is an edge from
//             // u to v, and total weight of path from src to  v through u is
//             // smaller than current value of distance[v]
//             // update amount of path
//             if (!shortpath[v] && snappath[u][v] && distance[u] != INT_MAX && distance[u] + snappath[u][v] < distance[v])
//                 distance[v] = distance[u] + snappath[u][v];
//     }
//     cout <<
//     // print the constructed distance array
//     // printSolution(distance, V);
// }

// // driver program to test above function
// int main()
// {
//     /* Let us create the example snappath discussed above */
//     float snappath[V][V] = {{0, 0.2, 0, 0, 0, 0, 0, 8, 0},
//                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
//                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
//                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
//                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
//                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
//                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
//                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
//                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};

//     dijkstra(snappath, 0);

//     return 0;
// }

#endif