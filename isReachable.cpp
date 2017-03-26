#include <bits/stdc++.h>
#define V 4

using namespace std;

vector<list<int> >adj(V);

void addEdge(int u, int v){
    adj[u].push_back(v);
}

bool isReachable(int u, int v){
    if(u == v)
        return true;

    list<int>::iterator it;

    queue<int>q;

    vector<bool>visited(V, false);

    visited[u] = true;
    q.push(u);

    while(!q.empty()){
        int i = q.front();
        q.pop();

        for(it = adj[i].begin(); it != adj[i].end(); it++){
            if(*it == v)
                return true;
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    return false;
}
int main(){
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    int u = 3;
    int v = 1;

    cout<<isReachable(u, v)<<endl;

    return 0;
}
