#include <bits/stdc++.h>
#define V 4

using namespace std;

bool dfs(int arr[V][V], int v, vector<int>&white, vector<int>&gray,vector<int>&black){
    vector<int>::iterator it;
    it = find(white.begin(), white.end(), v);
    white.erase(it);
    gray.push_back(v);

    for(int j = 0; j < V; j++){
        if(arr[v][j] == 1){
            if(find(black.begin(), black.end(), j) != black.end())
                continue;
            if(find(gray.begin(), gray.end(), j) != gray.end())
                return true;
            if(dfs(arr, j, white, gray, black))
                return true;
        }
    }
    it = find(gray.begin(), gray.end(), v);
    black.push_back(v);
    gray.erase(it);
    return false;
}

bool hascycle(int arr[V][V]){
    vector<int>white;
    vector<int>gray;
    vector<int>black;

    int i,j;

    for(i = 0; i < V; i++){
        white.push_back(i);
    }
    int k = 0;
    while(white.size() > 0 && k < V){
        int curr = white[k];
        if(dfs(arr,curr, white, gray, black))
            return true;
    }
    return false;
}
int main(){
    int arr[V][V] = {{0,1,1,0},
                     {0,0,1,0},
                     {0,0,0,1},
                     {0,0,0,0}};

    bool ans = hascycle(arr);

    cout<<ans;

    return 0;
}
