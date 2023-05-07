#include <string>
#include <iostream>
using namespace std;
int T;

int main(){
    cin >> T;
    while(T--){
        string tmp;
        cin >>tmp;
        cout << tmp[0] << tmp[tmp.size()-1] << "\n";
    }
}