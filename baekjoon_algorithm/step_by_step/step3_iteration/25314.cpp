#include <iostream>
using namespace std;

int main(){
    int N, num_long =0;
    cin >> N;
    num_long = N/4;
    for(int i = 0 ; i<num_long; i++)
        cout << "long ";
    cout << "int";
}