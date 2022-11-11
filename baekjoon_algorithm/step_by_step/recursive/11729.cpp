#include <iostream>
#include <string>
using namespace std;

int count = 0;
string result;

void moves(int n, int from, int to, int sub)
{
    if(n == 1)
    {
        result.append (to_string(from) + string(" ") + to_string(to) + string("\n"));
        count++;
    }
    else
    {
        moves(n-1, from, sub, to);
        moves(1, from, to, sub);
        moves(n-1, sub, to, from);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    moves(N, 1, 3, 2);
    cout << count << '\n';
    cout << result;

}