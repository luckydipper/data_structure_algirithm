#include <iostream>
#include <string>
using namespace std;

string pal;
int main(){
    cin >> pal;
    int pal_size = pal.size();
    for(int i = 0; i< pal_size; i++){
        if(pal[i]!=pal[pal_size-1-i]){
            cout << 0; 
            return 0;
        }
    }
    cout << 1;
}