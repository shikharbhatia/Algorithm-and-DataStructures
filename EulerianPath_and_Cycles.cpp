#include <bits/stdc++.h>
#define V 5

using namespace std;

vector< list<int> > adjList(V);

void addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void DFS(int u, bool visited[]){
    visited[u] = true;

    list <int>::iterator it;

    for(it = adjList[u].begin(); it != adjList[u].end(); it++){
        if(!visited[*it])
            DFS(*it, visited);
    }
}
bool isConnected(){
    bool visited[V];
    int i;

    for(i = 0; i < V; i++)
        visited[i] = false;

    for(i = 0; i < V; i++){
        if(adjList[i].size() > 0)
            break;
    }
    if(i == V)
        return true;
    DFS(i, visited);

    for(i = 0; i < V; i++){
        if(adjList[i].size() > 0 && visited[i] == false){
            return false;
        }
    }
    return true;
}

int isEulerian(){
    int i;
    if(isConnected() == false){
        return 0;
    }

    int odd = 0;

    for(i = 0; i < V; i++){
        if(adjList[i].size() & 1)
            odd++;
    }

    if(odd > 2)
        return 0;

    if(odd == 2)
        return 1;
    else if(odd == 0)
        return 2;
}
int main()
{
    addEdge(1,0);
    addEdge(0,2);
    addEdge(2,1);
    addEdge(0,3);
    addEdge(3,4);

    if(isEulerian() == 0)
        cout<<"no";
    else if(isEulerian() == 1)
        cout<<"Eulerian Path";
    else if(isEulerian() == 2)
        cout<<"Eulerian Cycle";

    return 0;
}
