#include <bits/stdc++.h>
using namespace std;

vector<int> dial{3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

int main(){
    string tmp;
    cin >> tmp;
    int result = 0;

    for(char a : tmp)
        result += dial[a - 'A'];
    
    cout << result;
}