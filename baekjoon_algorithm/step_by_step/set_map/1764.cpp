// 문제 꼼꼼히 읽기 사전순으로 출력임.
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    set<string> have_not_listened;

    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        have_not_listened.insert(temp);
    }

    int count_not_seen_listend = 0;
    
    set<string> orderd_result;
    // haven't seen
    for(int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;
        if(have_not_listened.find(temp) != have_not_listened.end())
        {
            count_not_seen_listend++;
            orderd_result.insert(temp);
        }
    }
    cout << count_not_seen_listend << '\n';
    for(set<string>::iterator i = orderd_result.begin(); i != orderd_result.end(); i++ )
        cout << *i << '\n';
}