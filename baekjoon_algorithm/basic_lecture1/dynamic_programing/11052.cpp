// 자연수의 조합 중복 조합으로 풀 수 있을 듯? 
// brute force algorithm까지 사용하면?
// 안 돼 1000의 1000승이야.
// greedy 같기도 해. 큰 것만 고르면 되는 것 아닌가?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int get_max_price(const vector<int>& price_index, vector<int>& cache, int index)
// {
//     if(index == 1)
//         return price_index[1];
//     else if(cache[index] != 0)
//         return cache[index];
//     else
//     {
//         int max_val = price_index[index];
//         for(int i = 1; i <= n/2; i++ )
//         {
//             if(max_val < cache)
//             cache[index - i] = 
//         }
//     }
// }

// price index와 max price cache의 arry는 다르다.

//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    cin >> N;
//    vector<int> price_index(N+1);
//    for(int i = 1; i <= N; i++)
//    {
//        int x;
//        cin >> x;
//        price_index[i] = x;
//    }
//
//    vector<int> max_price_cache(N+1);
//    max_price_cache[1] = price_index[1];
//    
//    for(int i = 2; i <= N; i++)
//    {
//        int max_price = max_price_cache[i-1] + max_price_cache[1];
//        if(max_price < price_index[i])
//            max_price_cache[i] = price_index[i];
//    }
//    
//    cout << max_price_cache[N];
//}


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
        for(int j = 1; j <= i; j++)
        {
            cache[i] = max(cache[i], cache[i-j] + prices[j]);
        }
    }
    cout << cache[N];
}