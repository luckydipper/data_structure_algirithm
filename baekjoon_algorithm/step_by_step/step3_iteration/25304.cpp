#include <iostream>
using namespace std;

int main(){
    long long X, N, sum_ = 0;
    cin >> X >> N;
    while(N--){
        int a, b;
        cin >> a >> b;
        sum_ += a*b;
    }
    if(X == sum_)
        cout << "Yes";
    else
        cout << "No";
}