#include <bits/stdc++.h>

using namespace std;

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int main(){
    string str, sol;
    cin >> str;

    int t;

    stack<char>s;

    int len = str.length();
    int i;

    for(i = 0; i < len; i++){
        if(isOperand(str[i]) > 0){
            sol += str[i];
       //     cout<<sol<<endl;
        }
        else{
            if(s.empty())
                s.push(str[i]);

            else if(!s.empty()){
                while(precedence(str[i]) < precedence(s.top())){
                    sol += (s.top());
                    s.pop();
                }
                s.push(str[i]);
            }
        }
    }
    while(!s.empty()){
        sol += (s.top());
        s.pop();
    }
    cout<<sol<<endl;

    return 0;
}
