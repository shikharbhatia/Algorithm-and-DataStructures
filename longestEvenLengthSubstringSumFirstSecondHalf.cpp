#include <bits/stdc++.h>    //bruyte force approach

using namespace std;

int main(){
    int i;
    int j;
    int k;

    int len;
    string s;
    int t;
cin >> t;

while(t--){
        int mxlen = 0;
  //  s.erase(s.begin(), s.end());
    cin >> s;
    int n = s.length();
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j=j+2){
            len = j-i+1;
            int lsum = 0;
            int rsum = 0;

            for(k = 0; k < len/2; k++){
                lsum += (s[i+k]-'0');
                rsum += (s[i+k+len/2]-'0');
            }

            if(lsum == rsum && mxlen < len){
                mxlen = len;
            }
        }
    }

    cout<<mxlen<<endl;
}
return 0;
}
