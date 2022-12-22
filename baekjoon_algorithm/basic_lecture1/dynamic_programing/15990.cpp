#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    const int MAX_n = 100001;
    vector<int> start_with_1(MAX_n, -1);
    vector<int> start_with_2(MAX_n, -1);
    vector<int> start_with_3(MAX_n, -1);
    vector<int> cache(MAX_n, -1);
    start_with_1[1] = 1;
    start_with_1[2] = 0;
    start_with_1[3] = 1;

    start_with_2[1] = 0;
    start_with_2[2] = 1;
    start_with_2[3] = 1;

    start_with_3[1] = 0;
    start_with_3[2] = 0;
    start_with_3[3] = 1;
    
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 3;

    while(T--)
    {
        int x;
        cin >> x;
  
        if(cache[x] != -1){
            cout << cache[x] << '\n';
            continue;
        }
        else{
        for(int i = 4; i <= x; i++){                                  
            start_with_1[i] = (start_with_2[i-1] + start_with_3[i-1])%1000000009;
            start_with_2[i] = (start_with_1[i-2] + start_with_3[i-2])%1000000009;
            start_with_3[i] = (start_with_1[i-3] + start_with_2[i-3])%1000000009;
            cache[i] = ((start_with_1[i] + start_with_2[i])%1000000009 +start_with_3[i])%1000000009;
        }
        cout << cache[x] << '\n';
        }
    }
}