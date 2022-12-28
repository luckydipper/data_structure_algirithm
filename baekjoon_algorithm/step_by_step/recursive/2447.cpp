#include <iostream>
// 문제를 나눠서
using namespace std;

void star(int i, int j, int n){
    if((i/n)%3 == 1 && (j/n)%3 == 1)
        cout << " ";
    else if(n == 1)
        cout << "*"; // n == 1을 맨 앞으로 빼면, n 이 1일때 무조건 star가 찍혀서 망함
    else
        star(i, j, n/3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    // i,j좌표에 뭐가 들어가는지 찾아서 출력
    for(int i = 0; i < N; i++){
        for(int j=0;j < N; j++){
            star(i, j, N);
        }
        cout << "\n";
    }
}