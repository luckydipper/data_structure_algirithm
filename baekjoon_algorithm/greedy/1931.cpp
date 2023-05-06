#include <bits/stdc++.h>
using namespace std;
int N;// 10만  
//N^2은 안 돼 is_free인지 check 하면서 해야
// 시간안에 가능 할 듯 한데
bool picked[100001];
pair<int,pair<int,int>> length_begin_end[100001];

bool is_free(int begin_i, int end_i){
    for(int i = begin_i; i< end_i; i++)
        if(picked[i]) return false;
    
    return true;
}

struct DISJOINT_SET{
    vector<int> parent, rank;
    int n;
    DISJOINT_SET(int n) : n(n), parent(n+1), rank(n+1){
        for(int i = 1; i<= n; i++)
            parent[i] = i;
    }
    int find(int a){
        if(parent[a] == a)
            return a;
        else
            return parent[a] = find(parent[a]);
    }
    void merge(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(rank[root_a] < rank[root_b])
            swap(a,b);
        parent[b] = root_a;
        if(rank[root_a] == rank[root_b])
            rank[root_a]++;
    }
};

int main(){
    cin >> N;
    int result = 0;

    DISJOINT_SET ds(N);
    for(int i =0; i < N; i ++){
        int tmp1, tmp2;
        cin>> tmp1 >> tmp2;
        //length_begin_end[i] = {tmp2- tmp1 ,{tmp1, tmp2}}; //왜 이렇게 쓰면 안 되는가? 
        length_begin_end[i].first = tmp2 - tmp1;
        length_begin_end[i].second.first = tmp1;
        length_begin_end[i].second.second = tmp2;
    }

    sort(length_begin_end, length_begin_end + N);

    for(int i =0; i < N; i ++){
        int begin_i, end_i;

        begin_i = length_begin_end[i].second.first;
        end_i = length_begin_end[i].second.second;

        for(int i = begin_i; i < end_i; i++){
            
        }
        if(is_free(begin_i, end_i)){
            for(int j = begin_i; j < end_i; j++){
                picked[j] = true;
            }
            result++;
        }

    }
    cout << result;
}