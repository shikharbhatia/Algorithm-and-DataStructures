#include <bits/stdc++.h>
#define V 5

using namespace std;

vector< list<int> > adjList(V);

void addEdge(int u, int v){
    adjList[u].push_back(v);
}
void dfs(bool visited[], int s){
    visited[s] = true;

    list<int>::iterator it;

    for(it = adjList[s].begin(); it != adjList[s].end(); it++){
        if(!visited[*it])
            dfs(visited, *it);
    }
}

void dfsRev(vector< list<int> > adj, bool visited[], int s){
    visited[s] = true;

    list<int>::iterator it;

    for(it = adj[s].begin(); it != adj[s].end(); it++){
        if(!visited[*it])
            dfsRev(adj, visited, *it);
    }
}

bool isSc(){
    bool visited[V];
    int i;
    vector< list<int> > adjListRev(V);
    list<int>::iterator it;

    for(i = 0 ; i < V; i++){
        visited[i] = false;
    }

    dfs(visited, 0);

    for(i = 0; i < V; i++){
        if(visited[i] == false){
            return false;
        }
    }

    for(i = 0; i < V; i++){
        for(it = adjList[i].begin(); it != adjList[i].end(); it++){
            adjListRev[*it].push_back(i);
        }
    }

    for(i = 0; i < V; i++)
        visited[i] = false;

    dfsRev(adjListRev, visited, 0);

    for(i = 0; i < V; i++){
        if(visited[i] == false)
            return false;
    }
    return true;
}
int main(){

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0);
    addEdge(2, 4);
    addEdge(4, 2);

    if(isSc()){
        cout<<"yes";
    }
    else
        cout<<"no";

}
