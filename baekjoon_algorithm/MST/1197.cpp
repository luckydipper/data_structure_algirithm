#include <bits/stdc++.h>
using namespace std;
int V, E;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>  > pq;

struct DISJOINT_SET{
    int n;
    vector<int> parent;
    DISJOINT_SET(int n): n(n), parent(n+1){
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int find(int node){
        if( parent[node] == node )
            return node;
        else
            return parent[node] = find(parent[node]);
    }
    void merge(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) // 아나.,.. != 와 != caution
            parent[root_a] = root_b;
    }
};

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> V >> E;
    while(E--){
        int from, to, weight;
        cin >> from >> to >> weight;
        // cout << "wtf?" << "\n";
        //pair<int,pair<int,int>> edge = ;
        pq.push({weight,{from,to}});
    }

    int result = 0;
    DISJOINT_SET union_set(V);
    while(!pq.empty()){
        //cout << pq.top().second.first << " -> " << pq.top().second.second << " // weight : " << pq.top().first << " \n";
        auto edge = pq.top();
        //cycle 존재?
        if(union_set.find(edge.second.first) == union_set.find(edge.second.second)) ;
        else{
            // cout << union_set.find(edge.second.first) << " == " << union_set.find(edge.second.second) << " ? \n";
            // for(int i : union_set.parent)
            //     cout << i << " ";
            // cout << "\n";
            union_set.merge(edge.second.first,edge.second.second);
            result += edge.first;
        }
        pq.pop();
    }
    cout << result;
    return 0;
}