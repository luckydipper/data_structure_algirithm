#include <iostream>
using namespace std;

int main(){
    int A;
    cin >> A;
    if(89 < A && A <= 100)
        cout << "A";
    else if(79 < A && A <= 89)
        cout << "B";
    else if(69 < A && A <= 79)
        cout << "C";
    else if(59 < A && A <= 69)
        cout << "D";
    else
        cout << "F";
}