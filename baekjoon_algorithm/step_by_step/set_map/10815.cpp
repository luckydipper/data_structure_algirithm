#include <iostream>
#include <set> 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    set<int> having_card;
    for(int i = 0; i < N; i++)
    {
        int dummy;
        cin >> dummy;
        having_card.insert(dummy);
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int dummy;
        cin >> dummy;
        
        if(having_card.find(dummy) == having_card.end())
            cout << "0 ";
        else
            cout << "1 ";
    }
}