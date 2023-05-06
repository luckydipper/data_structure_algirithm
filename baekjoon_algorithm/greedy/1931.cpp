#include <bits/stdc++.h>
using namespace std;
int N;// 10만  

pair<int,int> begin_end[100001];


bool sort_second(const pair<int,int> &a, const pair<int,int> &b){
    if (a.second < b.second)
        return a.second < b.second;
    else if(a.second == b.second)
        return a.first < b.first;
    else
        return false;
}
int result = 0;

int main(){
    cin >> N;

    for(int i =0; i < N; i ++){
        int tmp1, tmp2;
        cin>> tmp1 >> tmp2;
        //length_begin_end[i] = {tmp2- tmp1 ,{tmp1, tmp2}}; //왜 이렇게 쓰면 안 되는가? 
        begin_end[i] = {tmp1, tmp2};
    }

    sort(begin_end, begin_end + N, sort_second);
    int picked_begin, picked_end;
    tie(picked_begin, picked_end) = begin_end[0];
    result++;

    for(int i =1; i < N; i ++){
        int back_begin, back_end;
        tie(back_begin, back_end) = begin_end[i];
        if(picked_end <= back_begin){
            tie(picked_begin, picked_end) = begin_end[i];
            result++;
        }
    }
    cout << result;
}