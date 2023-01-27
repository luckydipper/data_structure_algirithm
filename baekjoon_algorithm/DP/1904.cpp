#include <iostream>
using namespace std;

int cache[1000001];

int main(){
    int N;
    cin >>N;
    cache[1] =1;
    cache[2] =2;
    for(int i = 3; i <= N; i++)
        cache[i] = (cache[i-1] +cache[i-2])%15746;
    cout << cache[N];
}