#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    cout << A+B << "\n" << A-B << '\n' << A*B << '\n' << A/B << '\n' << A%B;
}