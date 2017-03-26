#include <bits/stdc++.h>
#define V 6

using namespace std;

bool bfs(int R_graph[][V], int parent[], int s, int t){
    bool visited[V];
    int i;
    int v;

    queue<int> q;

    for(i = 0; i < V; i++)
        visited[i] = false;

    visited[s] = true;
    parent[s] = -1;
    q.push(s);

    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(v = 0; v < V; v++){
            if(!visited[v] && R_graph[u][v] > 0){
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    return (visited[t] == true);
}
int FordFulkerson(int graph[][V], int s, int t){
    int parent[V];
    int R_graph[V][V];
    int u,v;

    for(u = 0; u < V; u++)
        for(v = 0; v < V; v++)
            R_graph[u][v] = graph[u][v];

    int max_flow = 0;

    while(bfs(R_graph, parent, s, t)){
        int path_flow = INT_MAX;

        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, R_graph[u][v]);
        }

        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            R_graph[u][v] -= path_flow;
            R_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}
int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}};

    cout<<FordFulkerson(graph, 0, 5);

    return 0;
}
