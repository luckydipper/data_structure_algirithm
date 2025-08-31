#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int x_1, y_1, r_1, x_2, y_2, r_2;
int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
        if(r_1 > r_2)
            swap(r_1, r_2);
        double dx = abs(x_1-x_2), dy = abs(y_1 - y_2);

        double l2 = sqrt( dx*dx +  dy*dy);
        if(x_1==x_2 && y_1==y_2 && r_1==r_2)
            cout << -1 << "\n";
        else if(r_1+r_2 < l2 || r_2 - r_1 > l2)
            cout << 0 << "\n";
        else if(r_1+r_2 == l2 || r_2 - r_1 == l2)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}