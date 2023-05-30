// Dijikstra's single source shortest path algorithm

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Define number of vertices in the graph
#define vertices 6

// Find the vertex with minimum distance value from the set of vertices
// that are not yest included in the shortest path tree
int min_distance(int distance[], bool spt_set[]){

    // Define minimum value
    int minimum = INT_MAX, min_index;

    for (int i=0; i<vertices; i++){
        if (spt_set[i] == false && distance[i]<=minimum){
            minimum = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

// Generate the distance array
void print_solution(int distance[], int source){
    for (int i=0; i<vertices; i++){
        printf("The shortest time between %d and %d is: %d \n", source, i, distance[i]);
    }
}

// Implement Dijkstra's single source shortest path algorithm
// using adjacency matrix representation
void dijkstra(int graph[vertices][vertices], int source){
    // The output array
    int distance[vertices];

    bool spt_set[vertices];

    //Initialize all distances as infinite and stp_set[] as false
    for (int i=0; i<vertices; i++){
        distance[i] = INT_MAX;
        spt_set[i] = false;
    }

    distance[source] = 0;

    // Find shortest path for given vertices
    for (int count=0; count<vertices-1; count++){
        // Declare the minimum distance vertex from the set of vertices that not yet processed
        int s = min_distance(distance, spt_set);

        // Mark picked vertex as proccessed
        spt_set[s] = true;

        // Update distance values of the adjacent vertices of the picked vertex
        for (int vertex=0; vertex<vertices; vertex++){
            if (!spt_set[vertex] && graph[s][vertex] && distance[s]!=INT_MAX && distance[s]+graph[s][vertex]<distance[vertex]){
                    distance[vertex] = distance[s] + graph[s][vertex];
            }
        }
    }
    // Display the solution
    print_solution(distance, source);
}

int main(){
    // Introduce the adjacency matrix of the undirected graph
    int graph[vertices][vertices] = {{0, 10, 0, 0, 15, 5},
    {10, 0, 10, 30, 0, 0},
    {0, 10, 0, 12, 5, 0},
    {0, 30, 12, 0, 0, 20},
    {15, 0, 5, 0, 0, 0},
    {5, 0, 0, 20, 0, 0}};

// Calling the function
dijkstra(graph, 5);

return 0;
}
