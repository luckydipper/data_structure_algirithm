#include <list>
#include <iostream>
#include <string> 
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string sentence;
    string tnt;
    
    char tmp = 0;
    // while(cin >> tmp){
    //     sentence.push_back(tmp);
    // }
    // while(cin >> tmp){
    //     tnt.push_back(tmp);
    // }
    getline(cin, sentence);
    getline(cin, tnt);
    while(sentence.find(tnt) != string::npos){
        while(sentence.find(tnt) != string::npos){
            auto it = sentence.find(tnt);
            sentence.erase(it, tnt.size());
            //cout << sentence << "\n";
        }
    }
    if(sentence.empty())
        cout << "FRULA";
    else
        cout << sentence;
    return 0;
}