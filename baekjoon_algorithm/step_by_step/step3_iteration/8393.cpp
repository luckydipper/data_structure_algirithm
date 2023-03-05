#include <iostream>
using namespace std;

int main(){
    int X, sum_ = 0;
    cin >> X;
    for(int i = 1; i <=X; i++)
        sum_ += i;
    cout << sum_;
}