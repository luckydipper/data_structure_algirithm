#include <iostream>
using namespace std;
long long H, W, N, M;
long long row_density, col_density;

int main(){
    cin >> H >> W >> N >> M;
    if(H < W){
        swap(H,W);
        swap(N,M);
    }
    N++; M++;

    if(H%N == 0)
        row_density = H/N;
    else
        row_density = H/N + 1;
    
    if(W%M == 0)
        col_density = W/M;
    else
        col_density = W/M + 1;
    cout << row_density * col_density;
}