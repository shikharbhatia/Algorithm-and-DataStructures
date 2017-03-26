#include <bits/stdc++.h>
#define V 5

using namespace std;

bool isSafe(int v, bool graph[][V], int path[], int pos){
    if(graph[ path[pos-1] ][v] == 0)
        return false;

    for(int i = 0; i < pos; i++){
        if(path[i] == v)
            return false;
    }
    return true;
}
bool hamCycleUtil(bool graph[V][V], int path[], int pos){
    int v;
    if(pos == V){
        if(graph[ path[pos-1] ][ path[0] ])
            return true;
        else
            return false;
    }

    for(v = 1; v < V; v++){
        if(isSafe(v, graph, path, pos)){
            path[pos] = v;

            if(hamCycleUtil(graph, path, pos+1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle(bool graph[][V]){
    int path[V];
    int i;
    path[0] = 0;

    for(i = 1; i < V; i++)
        path[i] = -1;

    if(hamCycleUtil(graph, path, 1) == false){
        cout<<"D.N.E";
        return false;
    }

    for(i = 0; i < V; i++)
        cout<<path[i]<<" ";
    cout<<path[0];
    return true;
}

int main(){

    bool graph[][V] ={{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0},
                    };
    hamCycle(graph);
}
