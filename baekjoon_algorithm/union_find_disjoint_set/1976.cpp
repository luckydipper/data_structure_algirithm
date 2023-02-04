#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> parent, tree_height, connected_elem;
int merge(int node1, int node2);

void initialize(){
    cin >> N >> M;
    parent.resize(N+1);
    for(int i = 0; i < parent.size(); i++)
        parent[i] = i;

    tree_height.resize(N+1);
    fill(tree_height.begin(),tree_height.end(),1);
    
    connected_elem.resize(M);
}

int find_root(int node){
    if(parent[node] == node)
        return node;
    return parent[node] = find_root(parent[node]);
}

int merge(int node1, int node2){
    int root1 = find_root(node1);
    int root2 = find_root(node2);
    if(tree_height[root1] < tree_height[root2])
        swap(node1,node2);
    if(tree_height[root1] == tree_height[root2])
        tree_height[root1]++;
    //always root1 tree_height is higher than root2
    parent[root2] = root1;
    
    return 0;
}

int find(int n1, int n2){
    if(find_root(n1) == find_root(n2))
        return 1;
    else
        return 0;
}

void printYesNo(int yes){
    if(yes)
        cout << "YES \n";
    else
        cout << "NO \n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initialize();
    
    // get diagonized part
    int tmp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <N; j++){
            cin >> tmp;
            if(i < j && tmp ==1)
                merge(i+1, j+1);
        }
    }

    for(int &elem: connected_elem){
        cin>> tmp;
        elem = tmp;
    }

    int first_val = connected_elem[0];
    for(int i = 1; i<connected_elem.size();i++){
        if(!find(first_val, connected_elem[i])){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}