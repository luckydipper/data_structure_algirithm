#include <iostream>
using namespace std;
bool redundant[43];
int main(){
    for(int i = 0; i< 10;i++){
        int tmp;
        cin >>tmp;
        redundant[tmp %42] = true;
    }
    int result = 0;
    for(int i = 0; i<= 42;i++){
        if(redundant[i])
            result++;
    }
    cout << result;
}