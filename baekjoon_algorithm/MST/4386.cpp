// 어차피 다 연결해야 하는 것이면 adj list보다는 adj mat이 더 나을 듯.
#include <bits/stdc++.h>
using namespace std;
int n;
//distance 값들이 100^100t이 아님. 100^2임.
bool visited_vertex[101];
vector<pair<double,int>> adj_list[101]; //weight, to vertexes index

vector<pair<int,int>> vertexes; // from, to
priority_queue <pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>> > pq;

//auto를 쓰면 type conversion이나 type promotion overhead가 적어질듯.
// 왜냐면 template 기반이니깐. deduction 됨. generic programing
double getDist(const auto& p1, const auto& p2){
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}
double result;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    vertexes.resize(n+1);
    for(int i = 1; i <= n; i++){
        pair<double, double> node;
        cin >> node.first >> node.second;
        vertexes[i] = node;
    }

    for(int from = 1; from <= n; from++){
        for(int to = 1; to <= n; to++){
            adj_list[from].push_back( {getDist(vertexes[from],vertexes[to]), to} );
        }
    }
    
    pq.push({0,1});
    while(!pq.empty()){
        auto weight_to = pq.top();
        pq.pop();
        int here = weight_to.second;
        if(visited_vertex[here]) continue;
        visited_vertex[here] = true;
        // cout << weight_to.first << "\n";
        result += weight_to.first;

        for(const auto& there : adj_list[here]){
            //if(visited_vertex[there.second]) continue;  
            pq.push(there);
        }
    }


    // adj list가 다 연결 돼 있지 않았음.
    // for(int i =1; i <= n; i++){
    //     for(auto weight_to :adj_list[i]){
    //         cout << " from -> " << i << "to " << weight_to.second << " weight : " << weight_to.first << "\n";
    //     }
    // }
    cout << setprecision(3) << result;
}