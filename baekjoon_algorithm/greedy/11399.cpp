//scheduling pq쓰는 것 아닌가?

#include<bits/stdc++.h>
using namespace std;

bool less_(pair<int,int> a, pair<int,int> b){
    return 0;
}
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> pq;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        auto a = pq.top();
        result += a*i;
        pq.pop();
    }
    cout << result;
}