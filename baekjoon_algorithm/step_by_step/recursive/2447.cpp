#include <iostream>
// 문제를 나눠서
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j=0;j < N; j++){
            for(int n = 1; n <= N/3; n*=3){
                if((i/(n))%3 == 1 && (j/(n))%3 == 1)
                    cout << " ";
                else
                    cout << "*";
            }
        }
        cout << "\n";
    }
}