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

stack<int> stack_buffer;

bool comp_first(const vector<int>& l, const vector<int>& r){
    return l[0] < r[0];
}

int updateLowLinkValue(int here){
    visit_sequence[here] = ++start_sequence;
    stack_buffer.push(here);
    int low_link_value = visit_sequence[here];
    for(int there: graph[here]){
        if(visit_sequence[there] == 0)
            low_link_value = min(low_link_value, updateLowLinkValue(there)); // 3번 예시가 실현 되는 경우이다.
        else if(!finished[there])
            low_link_value = min(low_link_value, visit_sequence[there]);
    }

    // 부모 노드가 자기 자신인 경우
    if(low_link_value == visit_sequence[here]){
        vector<int> scc;
        while(1){
            int t = stack_buffer.top();
            stack_buffer.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == here) break;
        }
        SCC.push_back(scc);
    }
    return low_link_value;
}

void update_scc(){
    for(int i = 1; i <= V; i++)
        if(visit_sequence[i] == 0)
            updateLowLinkValue(i);
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

    update_scc();
    
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