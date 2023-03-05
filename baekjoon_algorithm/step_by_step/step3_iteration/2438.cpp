#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        for(int j = 0; j< T-i-1; j++)
            cout<<" ";
        for(int k=0; k <i+1; k++)
            cout <<"*";
        cout << "\n";
    }
}