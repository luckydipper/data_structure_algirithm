#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    map<string, string> dictionary;
    for(int i = 1; i <= N; i++)
    {
        string p_name;
        cin >> p_name;
        pair<string, string> str_int_elem(p_name, to_string(i));
        pair<string, string> int_str_elem(to_string(i), p_name);
        dictionary.insert(str_int_elem);
        dictionary.insert(int_str_elem);
    }

    for(int i = 0; i < M; i++)
    {
        string a;
        cin >> a;
        map<string,string>::iterator iter = dictionary.find(a);
        cout << iter -> second << '\n';
    }
}