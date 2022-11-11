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

int count_call(int N)
{
    while(cache[N] == 0)
    {
        if(N % 3 == 0)
            cache[N] = cache[N/3] + 1;
        else if(N % 2 == 0)
            cache[N] = cache[N/2] + 1;
        else 
            cache[N] = cache[N-1] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> cache(N+1, 0);
    
    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;



    return cache[N]
}