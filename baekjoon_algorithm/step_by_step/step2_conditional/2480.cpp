#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int X, Y, Z;
    vector<int> x_y_z(3);
    for(int& elm : x_y_z)
        cin >> elm;
    sort(x_y_z.begin(), x_y_z.end());

    int count_same = 1;
    if(x_y_z[0] == x_y_z[1])
        count_same++;
    if(x_y_z[1] == x_y_z[2])
        count_same++;

    if(count_same == 3)
        cout << 10000 + x_y_z[0]*1000;
    else if(count_same == 2){
        cout << 1000 + x_y_z[1]*100;
    }
    else
        cout << x_y_z[2] * 100;
}