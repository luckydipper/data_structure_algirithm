#include <iostream>
#include <string>
#include <algorithm>

ios_base::sync_with_stdio = false
cin::tie(nullprtr);

using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    while (cin >> s){
        reverse(s.begin(),s.end());
        cout << s << ' ';
    }
}