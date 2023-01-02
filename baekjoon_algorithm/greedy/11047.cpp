#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    stack<int> stk;
    while(N--){
        int temp;
        cin >> temp;
        stk.push(temp);
    }

    int count = 0;
    while(K != 0){
        int devider = stk.top();
        if(K - devider < 0){
            stk.pop();
        }
        else if(K - devider >= 0){
            K -= devider;
            count++;
        }
    }
    cout << count;
}