#include <list>
#include <iostream>
#include <string> 
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    list<char> sentence;
    list<char> tnt;
    
    char tmp = 0;
    while(cin >> tmp){
        sentence.push_back(tmp);
    }
    while(cin >> tmp){
        tnt.push_back(tmp);
    }

    list<char>::iterator suspect_start, suspect_end;
    suspect_start = suspect_end = sentence.begin();
    
    for(int i = 0; i < sentence.size(); i++)
        suspect_end++;
    
    return 0;
}