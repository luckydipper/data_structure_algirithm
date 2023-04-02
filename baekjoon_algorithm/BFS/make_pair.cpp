#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main(){
    pair<string, int> p1{"string", 2};
    cout << p1.first << " " << p1.second;

    auto p3 = make_pair("like_this", 3.14);
    cout << p3.first << " " << p3.second << " ";
}
