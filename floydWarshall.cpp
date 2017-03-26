#include <bits/stdc++.h>
#define INF 9999
using namespace std;

void floydWarshall(int graph[][4]){
    int dp[4][4];
    int i, j, k;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            dp[i][j] = graph[i][j];
        }
    }

    for(k = 0; k < 4; k++){
        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                if(dp[i][j] > (dp[i][k] + dp[k][j]))
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(dp[i][j] == 9999){
                cout<<"INF"<<" ";
            }
            else
                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main() {
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[4][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print the solution
    floydWarshall(graph);
    return 0;
}
