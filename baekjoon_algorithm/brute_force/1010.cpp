#include <iostream>
using namespace std;
int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    while(a--){
        cin >> N >> M;
        if(N == 0 || M == 0){
            cout << 0 << "\n";
            continue;
        }
        //double double c = 1,p = 1;
        long double result = 1;
        for(int i = 1; i <= N; i++) {
            result *= (M-N+i);
            result /= i;
        }
        //cout << c << " " << p << "\n";
        cout << (int)result << "\n";
    }
}