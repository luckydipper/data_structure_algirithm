#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> map(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int m;
            cin >> m;
            map[i][j] = m;
        }
    }
    
    vector<int> mutabled {0,2,3};

    stl_call_by_ref
    for(int elem:mutabled)
        cout << elem;
}

//can stl call by reference get r-value??
void stl_call_by_ref(vector<int> & mutable_vec){
    mutable_vec.push_back(1);
    mutable_vec.push_back(1);
    mutable_vec.push_back(2);
    mutable_vec.push_back(1);
}