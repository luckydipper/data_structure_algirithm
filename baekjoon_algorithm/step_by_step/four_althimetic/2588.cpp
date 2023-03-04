// 자릿수 계산은 string으로 받아서 stoi로 하는게 빠른가?
#include <iostream>
#include <cmath>
using namespace std;

int getNPlaceValue(int num,int N){
    return num / (int)pow(10,N-1) % 10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B; 
    int ret_val = 0;
    for(int i = 1; i <= 3; i++){
        int val = A * getNPlaceValue(B,i);
        cout << val << "\n";
        ret_val += val*(int)pow(10,i-1);
    }
    cout << ret_val << "\n";
}
