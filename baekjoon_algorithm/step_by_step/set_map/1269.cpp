#include <iostream>
#include <set>
using namespace std;

set<int> set_set(set<int>& A, int N)
{
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.insert(temp);    
    }
    return A;
}


int result = 0;
void A_in_B(const set<int>& A, const set<int>& B)
{
    for(set<int>::iterator i = A.begin(); i != A.end(); i++)
    {
        if(B.find(*i) == B.end())
        {
            result++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<int> A, B;
    A = set_set(A, N);
    B = set_set(B, M);

    A_in_B(A, B);
    A_in_B(B, A);
    cout << result;
}