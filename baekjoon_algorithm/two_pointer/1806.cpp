#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, S;
int arr[100001];
int psum_arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    int min_result = 987654321;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    partial_sum(arr+1, arr+N+1,psum_arr+1);

    int i = 0;
    int* l;
    do{
        l = lower_bound(psum_arr+1, psum_arr+N+1, psum_arr[++i] + S);
        if(min_result > l - psum_arr - i)
            min_result = l - psum_arr -i;     
    }while(l != psum_arr+N+1);

    // 만드는 것이 불가능함.
    if( S > psum_arr[N])
        {cout<<0; return 0;}
    if(psum_arr[1] >= S)
        {cout << 1; return 0;}

    cout << min_result;

}