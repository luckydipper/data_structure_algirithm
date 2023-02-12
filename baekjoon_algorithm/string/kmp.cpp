#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string domain_1{"aabcbaabaacabcaabc"};
const string target_1{"aab"};

vector<int> getPartialMatchTable(const string& s);

vector<int> getPartialMatchTable(const string& s){
    // 조사하는 string은 s1[0:i]까지 slicinjg 한 string이다.
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++){
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}


// i 는 전체 문자열에서 domain[0:i]까지의 문자열을 조사한다.
// 그 안에서 substring target[0:j]까지의 문자열이 존재 하는지 찾는다.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string domain, target;
    vector<int> starting_index(0);

    domain = domain_1;
    target = target_1;
    vector<int> partial_match_table = getPartialMatchTable(target);

    int j = 0;
    for(int i = 0; i < domain.size(); i++){
        while(j > 0 && domain[i] != target[j]) j = partial_match_table[j-1];
        if(domain[i] == target[j]) j++;
        if(j == target.size()){
            starting_index.push_back(i-j+1);
        }
    }

    for(int a : partial_match_table)
        cout << a << ", ";

    cout << "\n";
    for(int b : starting_index)
        cout << b << ", ";

    // eol print 됨.
    cout << (target[3] == *target.end());
}