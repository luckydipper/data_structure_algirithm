#include <iostream>
#include <vector>
using namespace std;
// 10 5 4 2 1 
// 10 9 3 1
// recursive relation을 적어야함.
// D[N] = 1 + D[N/3]
// D[N] = 1 + D[N/2]
// D[N] = 1 + D[N-1]
// gridy인가?
// D[N] : N을 1까지 만드는데 걸리는 최소 횟수 
// D[N] = min(D[N/3], D[N/2], D[N-1])


int count_call(int N, vector<int>& cache)
{
    if(cache[N] != 0)
    {
        return cache[N];
    }
    if(N <= 1)
    {
        return 0;
    }
    else
    {
    int out = count_call(N-1, cache) + 1;
    
    if(N % 3 == 0) 
    {
        int devided_3 = count_call(N/3, cache) + 1;
        if(devided_3 < out) out = devided_3;
    }

    if(N % 2 == 0)
    {
        int devided_2 = count_call(N/2, cache) + 1;
        if(devided_2 < out) out = devided_2;
    }

    cache[N] = out;
    return out;
    }
}

int bottom_up_to_1(int n, vector<int> & cache)
{
    cache[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        cache[i] = cache[i-1] + 1;
        
        if( i % 3 == 0  && cache[i/3] < cache[i])
            cache[i] = cache[i/3] + 1;
        
        if( i % 2 ==0 && cache[i/2] < cache[i])
            cache[i] = cache[i/2] + 1;
    }
    return cache[n];
}

// int go(int n)
// {
//     if( n == 1 ) return 0;
//     if( d[n] > 0) return d[n];
//     d[n] = go(n-1) + 1;
//     if(n%2 == 0)
//     {
//         int temp = go(n/2) + 1;
//         if(d[n] > temp) d[n] = temp;
//     }
//     if(n%3 == 0)
//     {
//         int temp = go(n/3) + 1;
//         if(d[n] > temp) d[n] = temp;
//     }
//     return d[n];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> cache(N+1, 0);
    
    cout << count_call(N, cache) << '\n';
    return 0;
}