#include <bits/stdc++.h>
#define V 7

using namespace std;

vector< list <int> > adjList(V);

void addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
void vertexCover()
{
    bool visited[V];
    int u, v;
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int>::iterator it;

    for(u = 0; u < V; u++)
    {

        if(!visited[u])
        {
            for(it = adjList[u].begin(); it != adjList[u].end(); it++)
            {
                v = *it;
                if(!visited[v])
                {
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }
    for(u = 0; u < V; u++){
        if(visited[u])
            cout<<u<<" ";
    }
}
int main()
{

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);

    vertexCover();
}
