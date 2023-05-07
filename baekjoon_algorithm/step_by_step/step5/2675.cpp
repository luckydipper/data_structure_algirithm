#include <bits/stdc++.h>
using namespace std;
int T;

int main(){
    cin >> T;
    int R;
    string st;
    

    while(T--){
        cin >> R >> st;
        for(char s : st)
            for(int i =0; i < R; i++)
                cout << s;
        
        cout << "\n";
    }
}