#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsVPS(const string &sentense)
{
    stack<char> buff{};
    for(const char &PS: sentense)
    {
        if(PS == '(')
            buff.push(PS);
        else if(PS == ')')
        {
            if(buff.empty())
            {
                return false;
            }
            buff.pop();
        }
    }

    if(buff.empty())
        return true;
    else
        return false;
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T_case;
    cin >> T_case;
    cin.ignore();
    
    string sentense;
    for(int i = 0; i < T_case; i++)
    {
        getline(cin, sentense);
        if(IsVPS(sentense))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}