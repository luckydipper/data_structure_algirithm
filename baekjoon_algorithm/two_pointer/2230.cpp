// 수 고르기
#include<bits/stdc++.h>
using namespace std;
int N, M;
set<int> domain;

int main(){
    cin >> N >> M;
    //vector<int> domain; // list로 넣으면서 sorting?  // bst// avl tree 

    while(N--){
        int tmp; 
        cin >> tmp;
        domain.insert(tmp);
    }
    vector<int> p_sum;

    auto start = domain.begin(), end_ = domain.end();
 
    //numeric, 뒤에 multiplies<int>()도 가능.
    partial_sum(domain.begin(), domain.end(), p_sum.begin());

    int min_sub = 1000000001;
    for(int i : p_sum)
        cout << i <<" ";
    cout << "\n";
    for(int i = 0; i<p_sum.size()-1; i++){
        if( M <= p_sum[i+1] - p_sum[i] < min_sub)
            min_sub = p_sum[i] - p_sum[i+1];
    }
    cout << min_sub;
}