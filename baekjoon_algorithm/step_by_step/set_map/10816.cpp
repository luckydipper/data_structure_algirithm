#include <iostream>
#include <set>
#include <unordered_map> // hash table based map
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    unordered_map<int, int> having_cards;

    for(int i = 0; i < N; i++)
    {
        int card_number;
        cin >> card_number;

        bool success_insertion = having_cards.insert(pair<int,int>(card_number, 1)).second;
        if(!success_insertion)
            having_cards[card_number]++;
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int card_number;
        cin >> card_number;
        if(having_cards.find(card_number) == having_cards.end())
            cout << "0 ";
        else
            cout << having_cards.find(card_number)->second << ' ';
    }
}