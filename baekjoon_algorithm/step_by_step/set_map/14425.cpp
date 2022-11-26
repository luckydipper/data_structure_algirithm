#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<string> target;

    for(int i = 0;i < N; i++)
    {
        string str;
        cin >> str;
        target.insert(str);
    }

    int count_overlap = 0;
    for(int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        if( target.find(str) != target.end())
            count_overlap++;
    }
    cout << count_overlap;
}