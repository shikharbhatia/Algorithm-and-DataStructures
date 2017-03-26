#include <bits/stdc++.h>

using namespace std;

void BFS(vector<list<int> >adjList, int s){
    queue<int> q;
    bool visited[5];
    int temp;
    vector<list<int> >::iterator i;
    list<int> li;
    list<int>::iterator it;

    for(int i = 0 ; i < 5; i++){
        visited[i] = false;
    }
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp<<" ";

        for(it = adjList[temp].begin(); it != adjList[temp].end(); it++){
            if(!visited[*it]){
                q.push(*it);
                visited[*it] = true;
            }
        }
    }
}
int main()
{
    vector<list<int> > adjList(5);

    adjList[0].push_back(1);
    adjList[0].push_back(4);

    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);

    adjList[2].push_back(1);
    adjList[2].push_back(3);

    adjList[3].push_back(1);
    adjList[3].push_back(4);
    adjList[3].push_back(2);

    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[4].push_back(3);

    BFS(adjList, 2);

    return 0;
}
