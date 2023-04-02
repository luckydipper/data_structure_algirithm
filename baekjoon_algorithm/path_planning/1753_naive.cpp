#include <bits/stdc++.h>
#define WEIGHT first
#define TO second
using namespace std;
int V, E, start;
vector<pair<int,int>> adj_list[20001];
int min_distance[20001];
bool is_fixed[20001];
const int INF = 0x3f3f3f3f;

//update 할 small index가 없으면 INF 반환.
int get_smallest_vertex(){
    int ret = -1, ret_value = INF;
    for(int i = 1; i <= V; i++){
        if(is_fixed[i]) continue;
        if(min_distance[i] < ret_value){
            ret=i; ret_value = min_distance[i];}
    }
    if(ret_value == INF)
        ret = -1;
    return ret;
}

void update_distance(int from_vertex){
    for(auto edge: adj_list[from_vertex]){
        if(is_fixed[edge.second]) continue;
        int original = min_distance[edge.second];
        int passing_edge = min_distance[from_vertex] + edge.first;
        if(original <= passing_edge) continue;
        min_distance[edge.second] = passing_edge;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E >> start;
    while(E--){
        int from, to, dist;
        cin >> from >> to >> dist;
        adj_list[from].push_back({dist, to});
    }
    fill(min_distance, min_distance+V+1, INF);

    min_distance[start] = 0;
    is_fixed[start] = 1;

    update_distance(start);
    
    while(get_smallest_vertex() != -1){
        int smallest_index = get_smallest_vertex();
        
        is_fixed[smallest_index] = 1;
        update_distance(smallest_index);
    }

    for(int i = 1; i <= V; i++)
        cout <<( (min_distance[i] == INF) ? "INF" : to_string(min_distance[i])) << "\n";
}