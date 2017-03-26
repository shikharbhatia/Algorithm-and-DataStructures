#include <bits/stdc++.h>

using namespace std;

bool isOperand(char s){
    if(s >= '0' && s <= '9')
        return 1;
    return 0;
}
int postfix(string str){
    stack<int>s;
    int i;
    int n = str.length();
    int a, b;
    int ans = 0;
    for(i = 0; i < n; i++){
        if(isOperand(str[i]))
            s.push((int)(str[i]-'0'));
        else if(str[i] == '+'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            ans = (a+b);
            s.push(ans);
        }
        else if(str[i] == '-'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            ans = (b-a);
            s.push(ans);
        }
        else if(str[i] == '*'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            ans = (a*b);
            s.push(ans);
        }
        else if(str[i] == '/'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            ans = (b/a);
            s.push(ans);
        }
    }
    return ans;
}
int main(){
    string s;
    cin >> s;

    int ans = postfix(s);

    cout<<ans<<endl;
}
