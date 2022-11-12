// TODO string으로 한 다음에 한글자씩 빼내는 것이 더 효과 좋지 않을까?
// type casting 해서 더 많이 걸릴려나?
// 문제 꼼꼼히 읽기

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int sum_of_10_coefficient(int n)
{
    vector<int> e0_to_e6(7);
    for(int i = 0; i < 7; i++)
        e0_to_e6[i] = pow(10, i);
    
    int result = 0;
    for(int i = 0; i < 7; i++)
    {
        int coefficient = n / e0_to_e6[6-i];

        if ( coefficient != 0)
        {
            result += coefficient;
            n = n - coefficient * e0_to_e6[6-i];
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    for(int i = 0; i < n; i++)
    {    
        int component = i + sum_of_10_coefficient(i);

        if(component == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}