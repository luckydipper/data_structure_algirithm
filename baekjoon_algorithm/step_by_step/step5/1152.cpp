// 반례 ' ' 한개 생각
#include <iostream>
#include <string>
using namespace std;

int result;
int main(){
    std::string st;
    //get_line(st);
    std::getline(std::cin, st);
    

    for(int i = 1; i < st.size()-1; i++)
        if(st[i] == ' ')
            result++;
    if(st == " "){
        cout << 0;
        return 0;
    }
    std::cout << result+1;
}