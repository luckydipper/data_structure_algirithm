// D&C 까진 접근. 
// 5로 나눠지는 부분들은 D&C로 처리 
// 나머지 부분은 1개씩 1인지 비교하는 전략 
// 5진수 전략도 가능
// ref.
// https://allmymight.tistory.com/188
//https://raoneli-coding.tistory.com/124
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// // 0 1             0~4               // 1
// // 1 11011                        // 4
// // 2 110 11 11011 00000 11 011 11011  // 16 (5 14)
// // 3 // 64

// //대칭 
// // 5 단위로 나눠서 이전 단계가 뭐였는지 추론한 후, 1 5 25 125 625
// // 2 66 -> 5 65

// // 해당 숫자 뭔지 몇 layer index
// // 5 구간 숫자 합 
// // index 1 빼
// // 중간에 있는 5 offset 계산 

// long long fiveIndentCount1(long long l, long long r, int layer){
//     cout << l << " " << r<< "\n";
//     if (layer == 0)
//         return 1; 
//     if (layer == 1){
//         long long result = r - l;
//         if(l <= 2 && r >= 2 )
//             result--;
//         return result + 1;
//     }
//     return 4*fiveIndentCount1(l/5, r/5, --layer) ;
// }

// bool isOne(long long i, int layer){
//     if(layer == 0)
//         return true;
    
//     if(layer == 1){
//         if (i == 2)
//             return false;
//         else
//             return true;
//     }
//     return isOne(i/5, --layer);
// }

bool isOne(long long i){
    if(i%5 == 2)
        return false;
    if(i <= 4)
        return true;
    return isOne(i/5);
}

int solution(int n, long long l, long long r) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int result = 0;
    for(long long i = l-1; i <= r-1; i++)
        if(isOne(i))
            result++;
    
//     l--; r--;
//     long long ll = l-(l%5)+5, _ll = l%5;
//     long long rr = r - r%5, rr_ = r%5;

//     int result = fiveIndentCount1(ll, rr, n);
//     cout << "five Indent " << result << "\n";
    // cout << ll <<" " << rr <<" " << _ll << " " << rr_ <<"\n";
    // _ll = (5 - _ll)%5;
    // for(int i = 0; i < _ll; i++){
    //     if(isOne(ll-1-i, n))
    //         result++;
    // }
    // for(int i = 0; i < rr_; i++){
    //     if(isOne(rr+1+i, n))
    //         result++;
    // }
    //cout << result; //fiveIndentCount1(5, 14, n);
    int answer = result;
    return answer;
}