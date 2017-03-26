#include <bits/stdc++.h>

using namespace std;

void BFS(int adjMatrix[][4], int m, int s){
    bool visited[m];
    memset(visited, 0, sizeof(visited));
    queue<int>q;
    visited[s] = 1;
    q.push(s);

    while(!q.empty()){
        s = q.front();
        q.pop();

        cout<<s<<" ";

        for(int j = 0; j < m; j++){
            if(adjMatrix[s][j] == 1 && !visited[j]){
                visited[j] = true;
                q.push(j);
            }
        }
    }
}
void DFS_util(int adjMatrix[][4], int m, int s, bool visited[]){
    visited[s] = true;
  //  cout<<s<<" ";

    for(int j = 0; j < m; j++){
        if(adjMatrix[s][j] == 1 && !visited[j])
            DFS_util(adjMatrix, m, j, visited);
    }
}
void DFS(int adjMatrix[][4], int m, int s){
    bool visited[m];
    memset(visited, 0, sizeof(visited));

    DFS_util(adjMatrix, m, s, visited);
}

int findMother(int adjMatrix[4][4], int m){
    int i;
    bool visited[m];

    memset(visited, 0, sizeof(visited));

    int v = 0;

    for(i = 0; i < m; i++){
        if(!visited[i]){
            DFS_util(adjMatrix,m,i,visited);
            v = i;
        }
    }
    memset(visited, 0, sizeof(visited));
    DFS_util(adjMatrix, m, v, visited);

    for(i = 0; i < m; i++){
        if(!visited[i])
            return -1;
    }
    return v;
}
int main(){
    int adjMatrix[4][4] = {{0,1,1,0},
                         {0,0,1,0},
                         {1,0,0,1},
                         {0,0,0,1}};

    BFS(adjMatrix, 4, 2);
    cout<<endl;

    DFS(adjMatrix, 4, 2);
    cout<<endl;

    cout<<findMother(adjMatrix, 4)<<endl;

    return 0;
}
