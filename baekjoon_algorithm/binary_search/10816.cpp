// multiset -> uper_bound, lower_bound    
#include <bits/stdc++.h>
using namespace std;

multiset<int> dom;
int N, M;
int sangun_have[(int)5e+5 +1];
int how_much[(int)5e+5 +1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> sangun_have[i];
    
    sort(sangun_have, sangun_have+N);
    cin >> M;
    for(int i = 0; i < M; i++)
        cin >> how_much[i];
    
    for(int i = 0; i < M; i++){
        auto lb = lower_bound(sangun_have, sangun_have+N, how_much[i]);
        auto up = upper_bound(sangun_have, sangun_have+N, how_much[i]);
        int result = 0;
        while(lb < up){
            result++;
            lb++;
        }
        cout << result << " ";
    }
}