// 22.10.08
// string은 array based임. array는 delete와 add new element 연산이 느림
#include <iostream>
#include <list>
#include <stack>
#include <string>
using namespace std;


void useStack()
{
    stack<char> l, r;
    string original_string;
    cin >> original_string;

    int num_iterate;
    cin >> num_iterate;

    for( int i = 0; i < original_string.length(); i++)
    {
        l.push(original_string[i]);
    }

    while(num_iterate--)
    {
        char command;
        cin >> command;
        
        if(command == 'P')
        {
            cin >> command;
            l.push(command);
        }
        else if(command == 'B')
        {
            if(l.empty())
                continue;
            l.pop();
        }
        else if (command == 'D')
        {
            if(r.empty())
                continue;
                
            l.push(r.top());
            r.pop();

        }
        else if( command == 'L')
        {
            if(l.empty())
                continue;
            r.push(l.top());
            l.pop();
        }
    }

    while(!l.empty())
    {
        r.push(l.top());
        l.pop();
    }
    while(!r.empty())
    {
        cout << r.top();
        r.pop();
    }
}

// caution 미완성
void useList()
{
    string original_string;
    cin >> original_string;

    int num_iterate;
    cin >> num_iterate;
    list<int> lt;

    for(const char& c_ : original_string)
    {
        lt.push_back(lt);
    }
    list<int>::iterator iter;
    iter = lt.end()

    while(num_iterate--)
    {
        char command;
        cin >> command;
        
        if(command == 'P')
        {
            cin >> command;
            lt.insert(iter, command);
        }
        else if(command == 'B')
        {
            if(iter == lt.begin())
                continue;
            lt.erase(iter);
        }
        else if (command == 'D')
        {
            if(r.empty())
                continue;
                
            l.push(r.top());
            r.pop();

        }
        else if( command == 'L')
        {
            if(l.empty())
                continue;
            r.push(l.top());
            l.pop();
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    useStack();
    return 0;
}