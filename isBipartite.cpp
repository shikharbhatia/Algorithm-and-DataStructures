#include <bits/stdc++.h>
#define V 4
using namespace std;

bool isBipartite(int G[][V], int src){
    int color[V];
    int i;
    queue<int> q;

    for(i = 0; i < V; i++)
        color[i] = -1;

    color[src] = 0;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(i = 0; i < V; i++){
            if(G[u][i] && color[i] == -1){
                color[i] = 1 - color[u];
                q.push(i);
            }
            else if(G[u][i] && color[i] == color[u]){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int G[][V] = {{0, 1, 0, 1},
                  {1, 1, 1, 1},
                  {0, 1, 0, 1},
                  {1, 0, 1, 0}};

    int s = 0;

    bool ans = isBipartite(G, 0);

    if(ans){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}
