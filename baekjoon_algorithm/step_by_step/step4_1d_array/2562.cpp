#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;

int main(){
    int max_v, index = 1;
    cin >> max_v;
    for(int i = index; i < 9; i++){
        int tmp;
        cin >> tmp;
        if(tmp > max_v){
            max_v = tmp;
            index = i+1;
        }
    }

    cout << max_v <<" " << index;
}