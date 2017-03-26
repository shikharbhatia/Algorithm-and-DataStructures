#include <bits/stdc++.h>
#define V 4

using namespace std;

void transitiveClosure(int graph[][V]){
    int dist[V][V];
    int i,j,k;

    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(k = 0; k < V; k++){
        for(i = 0; i < V; i++){
            for(j = 0; j < V; j++){
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
            }
        }
    }
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
     int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };

    transitiveClosure(graph);

    return 0;
}
