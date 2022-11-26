//size 원소의 수
//substr도 stl iterator 기반이라 begin end로 half open 형태를 따름
#include <iostream>
#include <set>
using namespace std;

void parse_string(set<string>& result, const string& str )
{
    for(int i = 0; i <= str.size(); i++)
    {
        for(int j = i; j <= str.size(); j++)
        {
            result.insert(str.substr(i,j-i));
        }
    }
}

int main()
{
    string str;
    cin >> str;
    
    set<string> result;
    parse_string(result, str);
    cout << result.size()-1;

    //for(const string& elem : result)
    //    cout << elem << '\n';
}