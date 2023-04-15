#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int A[101][101];
int B[101][101];
int C[101][101];

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int temp;
            cin >> temp;
            A[i][j] = temp;
        }
    }
    cin >> M >> K;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < K; j++){
            int temp;
            cin >> temp;
            B[i][j] = temp;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int result = 0;
            for(int k = 0; k < M; k++){
                result += (A[i][k] * B[k][j]);
            }
            C[i][j] = result;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            cout << C[i][j] <<" ";
        }
        cout << "\n";
    }
}