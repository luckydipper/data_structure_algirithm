#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int,int> count_elem;
    
    while(N--){
        int a;
        cin >> a;
        auto found_elem = count_elem.find(a);
        if( found_elem == count_elem.end())
            count_elem.insert({a,1});
        else
            found_elem->second++;
    }
    int b;
    cin >> b;
    cout << count_elem[b];
    
}