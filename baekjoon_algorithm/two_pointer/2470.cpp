#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100001];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    int* first_ptr = arr+0;
    int* last_ptr = arr + N-1;
    int closer_to_zero = 2100000001; // infi
    int sol_first;
    int sol_last;
    // for(int i = 0; i< N; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";

    while(first_ptr != last_ptr){
        int sum_liquid = *first_ptr + *last_ptr;
        if(closer_to_zero > abs(sum_liquid)){
            closer_to_zero = abs(sum_liquid);
            sol_first = *first_ptr;
            sol_last = *last_ptr;
        }
        // cout << "sum liquid : " << sum_liquid << "\n";
        if(sum_liquid > 0){
            last_ptr--;
        }else if(sum_liquid < 0){
            first_ptr++;
        }else{
            cout << *first_ptr << " " << *last_ptr;
            return 0;
        }
    }
    cout << sol_first <<" " << sol_last;

}