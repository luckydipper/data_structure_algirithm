// tarjan algorithm
// directed graph에서 scc가 유일 한가?
// cycle하면 scc인 것 인정. 그 역은 성립 하는가? 
#include <bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>> SCC;
vector<int> graph[10001];
int visit_sequence[10001];
int start_sequence = 0;

bool finished[10001];

stack<int> buffer_scc;

bool comp_first(const vector<int>& l, const vector<int>& r){
    return l[0] < r[0];
}

int dfs(int i){
    visit_sequence[i] = ++start_sequence;
    buffer_scc.push(i);
    int parent = visit_sequence[i];
    for(int adj_vertex: graph[i]){
        if(visit_sequence[adj_vertex] == 0)
            parent = min(parent, dfs(adj_vertex)); // 4번째 공리 만족
        else if(!finished[adj_vertex])
            parent = min(parent, visit_sequence[adj_vertex]); // finished 
    }

    // 부모 노드가 자기 자신인 경우
    if(parent == visit_sequence[i]){
        vector<int> scc;
        while(1){
            int t = buffer_scc.top();
            buffer_scc.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == i) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}

void scc(){
    for(int i = 1; i <= V; i++)
        if(visit_sequence[i] == 0)
            dfs(i);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    while(E--){
        int t1, t2;
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
    }

    scc();
    
    if(!SCC.empty())
        cout << SCC.size() << "\n";

    for(auto &scc : SCC)
        sort(scc.begin(), scc.end());
    sort(SCC.begin(),SCC.end(), comp_first);
    
    for(auto scc_ : SCC){
        for(int elem: scc_){
            cout << elem << " ";
        }
        cout << "-1 \n";
    }
}