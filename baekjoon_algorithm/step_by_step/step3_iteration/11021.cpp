#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int a, b;
        cin >> a >> b;
        cout <<"Case #" << i <<": "<<a <<" + "<<b<<" = " <<a + b << "\n";
    }
}