#include<bits/stdc++.h>
using namespace std;
string st;

int main(){
    cin >> st;
    vector<int> result('z'-'a' +1, -1); // 왜냐면 z a 둘다 포함
    for(int i = st.size()-1; i >=0 ; i--){
        result[st[i] - 'a'] = i;
    }
    for(int a: result)
        cout << a << " ";
}