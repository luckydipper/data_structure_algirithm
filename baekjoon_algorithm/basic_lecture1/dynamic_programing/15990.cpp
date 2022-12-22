#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    vector<vector<int>> cache(T+1, vector<int> (3,-1));
    cache[1][1] = 1;
    cache[1][2] = 0;
    cache[1][3] = 0;

    cache[2][1] = 0;
    cache[2][2] = 1;
    cache[2][3] = 0;

    cache[3][1]
}