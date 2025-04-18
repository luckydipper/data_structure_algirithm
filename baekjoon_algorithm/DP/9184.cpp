#include <iostream>
#include <vector>
using namespace std;

int a, b, c;
//!!CAUTION!! cache가 initalize되지 않았다. global은 elf의 bss에 포함된다. 그러므로 0이 된다.
int cache[21][21][21]; // 항상 cache의 경계값에 주의하자. 20이 아니다.

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a > 20 || b > 20 || c > 20)
        return w(20,20,20);
    else if(cache[a][b][c] != 0)
        return cache[a][b][c];
    else if(a < b && b < c){
        cache[a][b][c] = w(a,b,c-1) + w(a, b-1, c-1) - w(a,b-1,c);
        return cache[a][b][c];
    }
    else{
        cache[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) +w(a-1,b,c-1) -w(a-1,b-1,c-1);
        return cache[a][b][c];
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1)
            return 0;
        cout << "w(" << a << ", "<< b << ", " <<c <<") = " <<  w(a,b,c) << "\n";
    }
}   

    