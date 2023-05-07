#include <bits/stdc++.h>
using namespace std;

int N;
double origin[1001];

int main(){
    cin >> N;
    double max_val = 0;
    for(int i = 0; i < N; i++){
        cin >> origin[i];
        if(max_val < origin[i])
            max_val = origin[i];
    }
    
    double sum_alter = 0;
    for(int i = 0; i < N; i++){
        sum_alter += origin[i]/max_val*100;
    }
    cout << sum_alter/N;
}