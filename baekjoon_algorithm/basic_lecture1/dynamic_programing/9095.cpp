#include <iostream>
#include <vector>
using namespace std;

int bottom_up_count(int n)
{
    static vector<int> cache(n+1, 0);
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for (int i =4 ; i <=n ; i++)
    {
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    }
    return cache[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << bottom_up_count(N) << '\n';
    }
}