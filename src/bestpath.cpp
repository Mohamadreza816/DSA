#include "../header/bestpath.hpp"
// constructor
bestpath::bestpath(float **graph, float **dis, int size)
{
    this->costpath = graph;
    this->distance = dis;
    this->g_size = size;
    this->store = new int[size];
}
// distructor
bestpath::~bestpath()
{
    delete[] costpath;
    delete[] distance;
}
int bestpath::minimumdis(float distance[], bool shortpath[])
{
    // Initialize min value
    int min = INT_MAX;
    int min_index = 0;

    for (int v = 0; v < g_size; v++)
        if (shortpath[v] == false && distance[v] <= min)
        {
            min = distance[v];
            min_index = v;
        }
    return min_index;
}
// dijkstra algorithm for find shortes path in graph
float bestpath::dijkstra(int check)
{
    float temp[g_size][g_size]; // an temp var
    
    switch (check)
    {
    case 0:
        // initialize temp 2D array
        //for find best distance
        for (size_t i = 0; i < g_size; i++)
        {
            for (size_t j = 0; j < g_size; j++)
            {
                temp[i][j] = costpath[i][j];
                
            }
        }
        break;
    case 1:
        // initialize temp 2D array
        //for find shortest distance
        for (size_t i = 0; i < g_size; i++)
        {
            for (size_t j = 0; j < g_size; j++)
            {
                temp[i][j] = distance[i][j];
            }
        }
        break;
    }

    
    float distance[g_size]; // this array store shortest path from source vertex

    bool shortpath[g_size]; // shortpath[i] will be true if vertex i is included in shortest distance from source to i

    // initialize all distances as INFINITE and shortpath[] as false
    for (int i = 0; i < g_size; i++)
        distance[i] = INT_MAX, shortpath[i] = false;

    // distance of source vertex from itself is always 0
    int src = 0;
    distance[src] = 0;

    // find shortest path for all vertices
    for (int count = 0; count < g_size - 1; count++)
    {

        // call find mindis function
        int u = minimumdis(distance, shortpath);
        
        // mark the picked vertex as processed
        shortpath[u] = true;

        // update distance value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < g_size; v++)
        {
            
            if (!shortpath[v] && temp[u][v] && distance[u] != INT_MAX && distance[u] + temp[u][v] < distance[v])
            {
                distance[v] = distance[u] + temp[u][v];
                store[v] = u;
            }
        }
    }
    
    return distance[15]; // return distination node
}
void bestpath::showpath(int check)
{
    float finalpath = 0;
    switch (check)
    {
    case 0 :
    
        finalpath = dijkstra(0);
        cout << "cost of best path: " << finalpath << endl;
        cout << "your path is : ";
        nodepath();
        break;
    case 1:
        finalpath = dijkstra(1);
        cout << "shortestpath is: " << finalpath << endl;
        cout << "your path is : ";
        nodepath();
    default:
        break;
    }
}
int bestpath::nodepath()
{
    
    int node[g_size];
    //initialize node array with a flag
    for (int i = 0; i < g_size; i++)
    {
        node[i] = -5;
    }
    
    int destney = 15; //a var for keep destney node
    int temp = destney;
    
    int src = 0;
    int i = 0;
    while (destney != src)
    {
        node[i] = store[destney];
        destney = store[destney]; 
        ++i;
    }
    for (int i = g_size ; i > 0  ; i--)
    {
        if (node[i - 1] == -5)
        {
            continue;
        }
        cout << node[i - 1] << "-->";
    }
    cout << temp << endl;
    
    return 0;
}