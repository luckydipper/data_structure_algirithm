#include <iostream>
using namespace std;

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    Y += Z;

    X += Y/60;
    Y %= 60;

    X %= 24;

    cout << X <<" "<< Y;
}