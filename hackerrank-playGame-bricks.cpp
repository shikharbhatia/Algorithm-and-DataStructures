  #include <cmath>
  #include <cstdio>
  #include <vector>
  #include <iostream>
  #include <algorithm>
  #include <cstring>
  using namespace std;

  #define MAX_N 100008

 int T, N;
 long long score[MAX_N];
 long long sum[MAX_N];
 long long best[MAX_N];

 int main() {
     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     cin >> T;
     while (T--) {
         cin >> N;
         memset(sum, 0, sizeof(sum));
         memset(best, 0, sizeof(best));
         for (int i = 1; i <= N; i++)
             cin >> score[i];
         for (int i = N; i >= 1; i--)
             sum[i] = score[i] + sum[i + 1];
         best[N] = sum[N];
         best[N - 1] = sum[N - 1];
         best[N - 2] = sum[N - 2];
         for (int i = N - 3; i >= 1; i--)
            for (int j = 1; j <= 3; j++)
                 best[i] = max(best[i], sum[i] - best[i + j]);
         cout << best[1] << endl;
     }
     return 0;
 }
