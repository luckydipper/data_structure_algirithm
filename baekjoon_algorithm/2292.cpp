//sqrt --> double 이라, 유효숫자 불가능 
#include <iostream>
#include <cmath>
using namespace std;
long long N;
long long layer;
int main(){
    cin >> N;

    for(layer = 0; 1+3*layer*(layer+1) < N; layer++){}
    cout << layer+1;
    // long double layer = -1/2 + sqrt( ( 4*N-1) / 12);
    // cout << sqrt( ( 4*N-1) / 12) << "\n\n" ;
    // cout << layer << " " << floor(layer);
    // if(layer - floor(layer) < 0.00000001)
    //     cout << floor(layer)+1;
    // else
    //     cout << floor(layer)+2;
}