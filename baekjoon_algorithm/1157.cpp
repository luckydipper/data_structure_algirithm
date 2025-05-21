//transform tolower 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

string str;

map<char, int> cnt;
int main(){
    cin >> str;
    for(char& c: str){
        c = toupper(c);
        cnt[c]++;
    }
    int biggest= -9;
    string rst; 
    for(const auto& elem: cnt){
        if(elem.second == biggest){
            rst = string("?");
        }
        if(elem.second > biggest){
            rst = elem.first;
            biggest = elem.second;
        }   
    }
    cout << rst;
}