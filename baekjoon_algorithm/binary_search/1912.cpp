#include<bits/stdc++.h>
using namespace std;
int N;
int arr[ 100000];
int psum[100000];
int main(){
    cin>> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    partial_sum(arr, arr+N, psum);
    sort(psum, psum+N);
    for(int i =0; i< N; i++)
        cout << psum[i] << " ";
    cout << "\n";
    cout << psum[N-1] - psum[0];
}