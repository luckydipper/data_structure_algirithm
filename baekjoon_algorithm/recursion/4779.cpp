// 출력하고 escape sequence 넣자
#include <bits/stdc++.h>

using namespace std;
int N;

// D&C 할 때는 index 값을 넘기자.
// string devide(const string& str){
//     int sz = str.size();
//     if(sz == 1)
//         return str;
//     else{
//         string empty(sz/3, ' ');
//         return devide(str.substr(0, sz/3)) + empty + devide(str.substr(sz*2/3, sz)); 
//     }
// }

void devide2(string& str, int begin, int end){
    if(begin +1 >= end)
        return;
    int offset = (end - begin)/3;
    //cout << "begin : " << begin <<" end : " <<  end << "\n";
    for(int i = 0; i < offset; i++)
        str[begin + offset + i]=' ';
    devide2(str, begin, begin + offset);
    devide2(str, begin + 2*offset, end);
    return;
}


void printCantoa(int n){
    int len = 1;
    for(int i = 0; i <N; i++)
        len *= 3;
    string a(len,'-');
    devide2(a,0,len);
    cout << a << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> N)
        printCantoa(N);
}