#include<bits/stdc++.h>
using namespace std;

int N;
pair<int,int> from_to[101];
int cache[101]; // 1~i 번째까지, 뺀 것 or 안 뺀 것;

bool is_acrossed(int here,int there){//from_to[there].first > from_to[here].first 자명 
    return from_to[there].second < from_to[here].second;
}
int LIS(int here){
    int &ret = cache[here];
    if(ret != -1) return ret;

    ret = 1;
    for(int there = here+1; there <= N; there++){
        if(is_acrossed(here, there)) continue;
        ret = max(ret, LIS(there)+1);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> from_to[i].first >> from_to[i].second;
    memset(cache, -1, sizeof(cache));
    sort(from_to+1,from_to+N+1);
    //for(int i = 1; i <= N; i++)
    //    cout << from_to[i].first << " " << from_to[i].second << "\n";
    //from_to[0].first = from_to[0].second = -2147483647;
    cout << N + 1 - LIS(0);
}