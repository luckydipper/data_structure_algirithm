#include<bits/stdc++.h>
using namespace std;
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int min_s = 987654321, max_s = -987654321;
    while(N--){
        int tmp;
        cin >> tmp;
        if(tmp < min_s)
            min_s = tmp;
        if(tmp > max_s)
            max_s = tmp;
    }
    cout << min_s << " " << max_s;
    return 0;
}