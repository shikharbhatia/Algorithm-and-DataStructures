#include <bits/stdc++.h>
#define V 5

using namespace std;

int findMin(int key[], bool mstSet[]){
    int mn = INT_MAX;
    int min_index;
    for(int i = 0; i < V; i++){
        if(mstSet[i] == false && key[i] < mn){
            mn = key[i];
            min_index = i;
        }
    }
    return min_index;
}
int printMST(int parent[], int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
void primsMST(int adjMatrix[V][V]){
    int key[V];
    bool mstSet[V];
    int parent[V];
    int c;
    int v;

    for(int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    for(c = 0; c < V-1; c++){
        int u = findMin(key, mstSet);
        mstSet[u] = true;

        for(int v = 0; v < V; v++){
            if(adjMatrix[u][v] && mstSet[v] == false && key[v] > adjMatrix[u][v]){
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

printMST(parent, adjMatrix);
}
int main()
{
    int adjMatrix[][V] = { {0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0},
                       };
    primsMST(adjMatrix);
}
