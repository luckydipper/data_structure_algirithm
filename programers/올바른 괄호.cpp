#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cnt_o, cnt_c;
bool solution(string s)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool answer = true;
    for(const char a : s){
        if(a == '(')
            cnt_o++;
        else if(a == ')')
            cnt_c++;

        if(cnt_o - cnt_c < 0)
            return false;
    }
    if(cnt_o - cnt_c != 0)
        return false;
    
    return answer;
}