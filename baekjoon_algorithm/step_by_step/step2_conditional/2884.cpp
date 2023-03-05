#include <iostream>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;

    Y -= 45;

    if(Y < 0){
        X -= 1;
        Y += 60;
    }
    if(X < 0)
        X = 23;
    cout << X <<" "<< Y;
}