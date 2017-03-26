#include <bits/stdc++.h>
#define V 5

using namespace std;

vector< list< int> > adjList(V);

void addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
void graphColoring(){
    int result[V];
    bool available[V];

//INITIALISATION...

    result[0] = 0;

    for(int i = 1; i < V; i++){
        result[i] = -1;
    }

    for(int i = 0; i < V; i++){
        available[i] = false;
    }
// COLORING...
    int u;
    int cr;

    for(u = 1; u < V; u++){
        list<int>::iterator it;

        //flaging adj vertices colors as unavailabe

        for(it = adjList[u].begin(); it != adjList[u].end(); it++){
            if(result[*it] != -1){
                available[result[*it]] = true;
            }
        }

        //finding the available color
        for(cr = 0; cr < V; cr++){
            if(available[cr] == false)
                break;
        }

        result[u] = cr;     //coloring the vertex...

        //reseting the values...

        for(it = adjList[u].begin(); it != adjList[u].end(); it++){
            if(result[*it] != -1)
                available[result[*it]] = false;
        }
    }

    for(int i = 0; i < V; i++){
        cout<<"vertex = "<<i<<" color = "<<result[i]<<endl;
    }
}
int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(4, 3);

    graphColoring();

    return 0;
}
