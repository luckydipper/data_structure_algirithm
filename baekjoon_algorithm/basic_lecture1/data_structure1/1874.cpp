#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Max_num;
    cin >> Max_num;

    stack<int> origin;
    for(int i = Max_num; i >= 1 ; i--)
        origin.push(i);
    
    stack<int> keep_order;
    string print_result;

    while(!origin.empty() || !keep_order.empty())
    {
        int print_var;
        cin >> print_var;

        if (print_var >= origin.top())
        {
            while(origin.top() == print_var)
            {
                keep_order.push(origin.top());
                origin.pop();
                print_result += "+\n";
                cout<<'+';
            }
            keep_order.pop();
            cout<<'-';
            print_result += "-/n";
        }
        else if (print_var <= keep_order.top())
        {
            while(keep_order.top() == print_var)
            {
                print_result += "-n";
                cout<<'-';
                keep_order.pop();
            }
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << print_result;
}