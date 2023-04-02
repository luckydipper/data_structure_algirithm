#include <bits/stdc++.h>
using namespace std;

#define WEIGHT first
#define POINTING second 

int V, E, start;
vector<pair<int, int>> adj[20001];
int shortest_distance[20001];  // 최단 거리 distance 예약어임
// bool fixed[20001]; 필요 없어. 왜냐면 원래보다 크면 반영하지 않을 거야.

// 이정도 길이이면 auto 쓰는 것이 좋지 않을까? 
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
const int INF = 0x3f3f3f3f;

int main(){
    cin >> V >> E >> start;
    fill(shortest_distance, shortest_distance+V+1, INF);

    //initialization
    while(E--){
        int from, to, w;
        cin >> from >> to >> w;
        adj[from].push_back({w, to});
    }
    
    shortest_distance[start] = 0;
    //start가 시작임.
    pq.push({shortest_distance[start], start});

    while(!pq.empty()){
        auto here = pq.top(); pq.pop();
        // priority queue에 넣기 전에 최단 shortest_distance가 update됨. 
        // 그러므로 shortest_distance[here.POINTING] < here.WEIGHT는 물론
        // != 임. bidirected graph에서 다시 돌아오는 노드는 weight가 더 커져서 무시.
        if(shortest_distance[here.POINTING] != here.WEIGHT) continue;
        // shortest_distance[here.POINTING] == here.weight일 것임.

        // here에 연결된 edge들을 가져온다.  
        for(auto there: adj[here.POINTING]){
            if(shortest_distance[there.POINTING] <= shortest_distance[here.POINTING] + there.WEIGHT) continue;
            shortest_distance[there.POINTING] = shortest_distance[here.POINTING] + there.WEIGHT;
            // 거쳐 가는 것이 weight가 더 적은 경우
            pq.push({shortest_distance[there.POINTING], there.POINTING});
            
        }
    }

    for(int i = 1; i <= V; i++)
        cout << (shortest_distance[i] == INF ? "INF" : to_string(shortest_distance[i])) << "\n";
}