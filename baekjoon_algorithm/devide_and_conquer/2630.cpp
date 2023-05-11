//sol. dfs recursion 돌면서 N^2 으로 count 전체가 black인지 wight인지 판단. -> D&C처리 
// Q. 그럼 overlapping sub problem,이 너무 많이 일어나지 않나?

#include<bits/stdc++.h>
using namespace std;
int N;
bool arr[129][129];
int num_whight, num_blue;

struct SQUARE{
    int row, col, size, state;
    SQUARE(int row, int col, int size):row(row), col(col), size(size), state(-1){;}
};
void merge(SQUARE &origin, SQUARE& a, SQUARE& b, SQUARE& c, SQUARE& d){
    if(a.state == b.state &&
       a.state == c.state &&
       a.state == d.state &&
       b.state == c.state &&
       b.state == d.state &&
       c.state == d.state && a.state != -1){ //array로 저장했으면 편했을 듯.
    origin.state = a.state;
    if(origin.size == N){ // 이거 넣으니깐 3%에서 터지네.. 
        if(origin.state)
            num_blue++;
        else
            num_whight++;
    }
    return;
    }
    else{
        // 
        if(a.state == -1 || b.state == -1 ||
           c.state == -1 || d.state == -1){
            
        }
        auto state_arr = {a.state, b.state, c.state, d.state};

        for(auto sq: state_arr){
            if(sq == -1)
                continue;
            else if(sq == 1)
                num_blue++;
            else
                num_whight++;
        }
        // num_blue += a.state + b.state + c.state + d.state;
        // num_whight += 4 - num_blue;
        //cout << "a : " << a.state << "b : " << b.state << "c : " << c.state << "d : " << d.state << "\n";
        //cout << num_blue << " : " <<num_whight << "\n";
        
        origin.state = -1;
        return;
    }
}
//devide 가 끝나고 나면 a, b, c ,d 의 state는 정해져야 해. un defined 라도
void devide(SQUARE& s){
    if(s.size == 1){
        s.state = arr[s.row][s.col];
        return;
    }
    SQUARE a(s.row,            s.col,            s.size/2);
    SQUARE b(s.row,            s.col + s.size/2, s.size/2);
    SQUARE c(s.row + s.size/2, s.col,            s.size/2);
    SQUARE d(s.row + s.size/2, s.col + s.size/2, s.size/2);
    devide(a);
    devide(b);
    devide(c);
    devide(d);
    
    merge(s,a,b,c,d);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];
    
    SQUARE s(1,1,N);
    devide(s);

    cout << num_whight << "\n" << num_blue;
}