#include <bits/stdc++.h>

using namespace std;

void utility(string buff, string s, int i, int j, int n){
    if(i == n){
        buff[j] = '\0';
        cout<<buff<<endl;
        return;
    }
    buff[j] = s[i];
    utility(buff, s, i+1, j+1, n);

    buff[j] = ' ';
    buff[j+1] = s[i];
    utility(buff, s, i+1, j+2, n);

}
void printpattern(string s){
    string buff;
    buff.resize(2*s.length());  //Important step otherwise next assignment would make the size of buffer equal to n, 2n size is required for accomodating spaces.

    buff[0] = s[0];

    utility(buff, s, 1,1, s.length());

}
int main(){
    string s;

    cin >> s;

    printpattern(s);

    return 0;
}
