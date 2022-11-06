// TODO : static variable 사용법
// struct로 calling counter 쓰는 것도 좋을 듯.
#include <iostream>
#include <string>

static int count = 0;

using namespace std;

int check_left_right(const string &s, const int &l, const int &r)
{
    ++count;
    if(s[l] != s[r])
        return 0;
    else if(l >= r)
        return 1;
    else return check_left_right(s, l+1, r-1);
}

void IsPalindrome(const string &s)
{
    cout << check_left_right(s, 0, s.length()-1) << ' ' << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();

   
    while(T--)
    {
        string s; // effective c++에선 밖에 만드는 것이 성능은 더 좋다고 함. 소멸자 호출 안 되니깐 캡슐화는 안 됨.
        count = 0;
        getline(cin, s);        
        IsPalindrome(s);
    }
}