#include <iostream>
#include <vector>
using namespace std;

int bottom_up_count(int n)
{
    static vector<int> cache(n+1, 0);
    cache[1]= 1;
    cache[2]= 3;

    for(int i = 3; i <= n; i++)
      cache[i] = (cache[i-1] + cache[i-2] * 2) % 10007;
    
    result = cache[n];
    return cache[n]; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << bottom_up_count(n);
}
