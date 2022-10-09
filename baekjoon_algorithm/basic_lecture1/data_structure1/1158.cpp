// 22.10.09 last modified 
// TODO : pass iterator as a function parameter
// problem : free() error

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// 왜 function template으로 구현해야 하는가?
//template<typename Iterator, Cd>
//void nextIterator(list<int>& ls, list<int>::iterator& i)
//{
//    if(i == ls.end())
//    {
//        i = ls.begin();
//        cout << *i << "  ";
//    }
//    else
//    {
//        ++i;
//        cout << *i << "  ";
//    }
//}
//tmeplate<typename T, typename U>
list<int>::iterator nextIterator(list<int>& ls, list<int>::iterator& i)
{
    if(i == ls.end())
    {
        return ls.begin();
    }
    else
    {
        return ++i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int k;
    
    cin >> N;
    cin >> k;
    list<int> circle;

    for(int i=1; i<=N; i++)
        circle.push_back(i);

    list<int>::iterator i = circle.begin();
    int a = 1;

    vector<int> result(N);

    while( !circle.empty() )
    {
        i = nextIterator(circle, i);
        
        if(++a % 3 == 0)
        {
            list<int>::iterator dumy{i};
            result.push_back(*i);

            dumy = nextIterator(circle, dumy);
            
            circle.erase(i);
            i = dumy;
        }
    }

    
    cout << "<";
    for(int i = 1; i < N; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[N];
    cout << ">";
    return 0;
}