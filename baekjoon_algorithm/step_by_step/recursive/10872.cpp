#include <iostream>

using namespace std;

int factorial(int N)
{
    if(N == 0)
        return 1;
    
    return N * factorial(N-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; 
    cout << factorial(N);
}