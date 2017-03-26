#include <bits/stdc++.h>
#define V 4

using namespace std;

vector< list< int> > adjList(V);

void addEdge(int u, int v)
{
    adjList[u].push_back(v);
}

bool isReachable(int u, int v)
{
    queue<int> q;
    bool visited[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;

    visited[u] = true;
    q.push(u);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        list <int>::iterator it;

        for(it = adjList[x].begin(); it != adjList[x].end(); it++)
        {
            if(*it == v)
            {
                return true;
            }
            else if(!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    return false;
}

int main()
{

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(2,0);
    addEdge(2,3);
    addEdge(3,3);

    int source = 1;
    int destination = 3;

    cout<<" 1 --> 3"<<endl;
    if(isReachable(1,3))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    cout<<" 3 --> 1"<<endl;
    if(isReachable(3, 1))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
