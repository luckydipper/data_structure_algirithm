#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DisjointSet{
    int num_people;
    vector<int> parent;

}

int C, F;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> C;
    while(C--){
        cin >> F;
        DisjointSet a{};
        while(F--){
            string f1, f2;
            cin >> f1 >> f2;
        }
    }
}