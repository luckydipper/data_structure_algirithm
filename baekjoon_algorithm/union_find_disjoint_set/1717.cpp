#include <iostream>
#include <vector>
using namespace std;
// get low link value 
vector<int> parent;

void initialize_parent(){
    for(int i = 0; i < parent.size(); i++)
        parent[i] = i;
}
//get 보다는 synchronize low link value
// sync_low_link_value는 해당 node보다 작은 node값만 보장하기 때문에 union find를 하기전에 sync를 다시 해줘야 한다.
int synchronize_low_link_value(int index){
    if(parent[index] == index)
        return index;
    else
        return parent[index] = synchronize_low_link_value(parent[index]);
}
void union_(int a, int b){
    a = synchronize_low_link_value(a);
    b = synchronize_low_link_value(b);
    if(a < b)
        parent[b] = parent[a]; //parent[a] 와 a를 넣는것은 다르다.
    else
        parent[a] = parent[b];
}
int union_find(int a, int b){
    a = synchronize_low_link_value(a);
    b = synchronize_low_link_value(b);

    if(parent[a] == parent[b])
        return 1;
    else
        return 0;
}
void print_YES_NO(int one){
    if(one)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    parent.resize(n+1);
    initialize_parent();

    while(m--){
        int check, s1, s2;
        cin >> check >> s1 >> s2;
        if(check)
            print_YES_NO(union_find(s1,s2));
        else
            union_(s1,s2);
    }

}