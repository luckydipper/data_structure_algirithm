#include <iostream>
#include <vector>
using namespace std;

int top_down_count(int n)
{
    static vector<int> cache2(n+1, 0);
    if( n == 1)
        return 1;
    if( n == 2)
        return 2;
    return top_down_count(n-1) + top_down_count(n-2);
}

int bottom_up_count(int n)
{
    static vector<int> cache(n+1, 0);

    cache[1] = 1;
    cache[2] = 2;
    for (int i=3; i <= n; i++)
    {
        cache[i] = (cache[i-2] + cache[i-1])% 10007;
    }
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