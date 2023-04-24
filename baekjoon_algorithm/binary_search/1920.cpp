#include <bits/stdc++.h>
using namespace std;
int N, M;
set<int> dom;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while(N--){
        int tmp;
        cin >> tmp;
        dom.insert(tmp);
    }
    cin >> M;
    while(M--){
        int tmp;
        cin >> tmp;
        // cout << ((dom.find(tmp) == dom.end()) ? 0 : 1 )<< "\n";
    }
}

void b_search(int b, int e, int t){
    int mid = (b+e)/2;
    if(t == mid){
        cout << "1\n";
        return;
    }
    else if( t > mid)
        b_search(mid, e, t);
    else
        b_search(b, mid, t);
    cout << "0\n";
    return;
}