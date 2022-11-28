#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<int> prices(N+1);
    for(int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        prices[i] = x;
    }

    vector<int> cache(N+1);

    for(int i = 1; i <= N; i++)
    {
        cache[i] = cache[i-1]+prices[1];
        for(int j = 1; j <= i; j++)
        {
            cache[i] = min(cache[i], cache[i-j]+prices[j]);
        }
    }
    cout << cache[N];
} 