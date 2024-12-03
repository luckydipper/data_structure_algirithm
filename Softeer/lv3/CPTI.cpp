// 알고리즘: brute force 
// STL , bitset bitmap shift xor XAND
// bin2dec에서 int 가 30자리이면 int overflow다. string으로 받아서 type casting 
// 문제 잘 읽기 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bin2dec(int a){
    int result = 0, order = 0;
    while(a != 0){
        if(a%10)
            result += pow(2, order);
        a = a/10;
        order++;
    }
    return result;
}

int main(int argc, char** argv)
{
    int N, M;
    cin >> N >> M;
    bitset<30> humans[30001];
    for(int i = 0; i < N; i++ ){
        string tmp;
        cin >> tmp;
        humans[i] = bitset<30>(tmp);
    }

    int result = 0;
    for(int i = 0; i < N; i++ )
        for(int j = i+1; j < N; j++){
            int same_cnt = (humans[i] ^ humans[j]).count() ; // 다른 성격의 수
            if( same_cnt <= 2)
                result++;
            }
    cout << result;
    return 0;
}