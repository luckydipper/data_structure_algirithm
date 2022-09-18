// 2022 9 17
// BOJ 9093
// O(N * M)
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void print_buff(stack<char>& buffer)
{
    while(!buffer.empty())
    {
        cout << buffer.top();
        buffer.pop();
    };
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int T;
    cin >> T;
    cin.ignore();
    
    stack<char> buff;
    string sentence;

    for(int i = 0; i<T; i++)
    {
        getline(cin, sentence);
        for(const char &character: sentence)
        {
            if (character == ' ')
            {
                print_buff(buff);
                cout << ' ';
                continue;
            }
            buff.push(character);
        }
        print_buff(buff);
        cout << '\n';
    }
}