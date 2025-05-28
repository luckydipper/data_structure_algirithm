#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
map< int, pair<int,int> > pq;
int arr[100000][100000];
int row_sum[100000];

//pick 하고 인접한 것 고치고, pick하고 인접한 것 고치고
#include <iostream>
#include <vector>

using namespace std;

int calc_weight(int i, int j, int N, int M, int mat[][(int)1e5],int row_sum[(int)1e5]) {
    int result = mat[i][j];

    if (i > 0) result -= row_sum[i-1];
    if (i < N-1) result -= row_sum[i+1];
    if (j > 0) result -= mat[i][j-1];
    if (j < M-1) result -= mat[i][j+1];

    return result;
}

int main() {
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;

        // 배열 입력 및 행 합 계산
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j];
                row_sum[i] += arr[i][j];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j <M; j++){
                pq[calc_weight(i,j,N,M, arr,row_sum)] = make_pair(i,j);
            }
        }
        for(int i = 0; i < 8; i++){
            //a = pq.top();

        }
    }
}
