#include <bits/stdc++.h>
#define ll long long
#define MAXN 10007
#define MOD 1000000007
using namespace std;
ll dp[MAXN][12];
void solve() {
	int n,p;
	cin>>n>>p;
	assert(n<=10000);
	assert(n>=1);
	assert(p<=10);
	assert(p>=1);
	cout<<dp[n+1][p+1]%MOD<<"\n";
}
void pre() {
	for(int i=0;i<MAXN;i++) {
		dp[i][0] = 0;
	}
	for(int j=0;j<12;j++) {
		dp[0][j]=0;
	}
	for(int i=1;i<MAXN;i++) {
		dp[i][1] = 1;
	}
	for(int j=1;j<12;j++) {
		dp[1][j] = 1;
	}
	for(int p=1;p<12;p++) {
		for(int i=2;i<MAXN;i++) {
			for(int j=i-1;j>=0;j--) {
				if(i-j < p) {
					dp[i][p] += dp[j][p];
					dp[i][p] %= MOD;
				}
			}
		}
	}
	for(int i=0;i<20;i++) {
		for(int j=0;j<10;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	pre();
    int t;
    cin>>t;
    assert(t<=100);
    while(t--) solve();
}
