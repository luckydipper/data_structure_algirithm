#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

//void makeGraph()
//adj list 쓰기로 결정 matrix는 크기가 너무 큼.


int N, M;
vector<list<int>> adj;

vector<int> seen;
vector<int> result;

void dfs(int here){
    if(seen[here] == 1)
        return ;
    else{
        seen[here] = 1;
        list<int>::iterator i = adj[here].begin();
        while( i != adj[here].end()){
            dfs(*i);
            i++;
        }
    }
    result.push_back(here);
}

int main()
{
    cin >> N >> M;
    //list는 초기화 하지 않아도 되는가?
    vector<list<int>> adj(N+1);
    vector<int> find_root_node(N+1, 1);
    
    while(M--)
    {
        int tall, small;
        cin >> tall >> small;
        adj[tall].push_back(small);
        find_root_node[small] = 0;
    }

    // find indegree zero vertex

    int root_index = -1;
    for(int i = 1; i < find_root_node.size(); i++){
        if(find_root_node[i] == 1){
            root_index = i;
        }
    }

    //dfs
    vector<int> seen(N+1, 0);
    dfs(root_index);
    reverse(result.begin(), result.end());

    for(int i : result)
        cout << i << " ";
}