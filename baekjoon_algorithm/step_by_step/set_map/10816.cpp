#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    multiset<int> having_cards;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        having_cards.insert(temp);
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        cout << having_cards.count(temp) << ' ';
    }
}