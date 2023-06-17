#include<bits/stdc++.h>
using namespace std;

struct MONITOR{
    int y_size, x_size;
    bool init_data[41][41];
    MONITOR(int y_size, int x_size): y_size(y_size), x_size(x_size){
        memset(init_data, 0, sizeof(init_data));
    };
};


//direction 0,1,2,3 .
struct STICKER{
    int y_size, x_size, y, x, direction;
    bool init_data[11][11];
    STICKER(int y_size, int x_size, int y, int x, int direction): y_size(y_size), x_size(x_size), x(x), y(y),direction(direction){};
    void print() const{
        for(int i = 1; i <= y_size; i++){
            for(int j = 1; j <= x_size; j++)
                cout << init_data[i][j] << " ";
            cout << "\n";
        }
    }
    void reset(int y_s, int x_s){
        y_size = y_s; x_size = x_s; direction = 0;
        x = 0; y = 0;
        memset(init_data, 0, sizeof(init_data));
    }
    bool rotatable(){
        direction++;
        if(direction >= 4)
            return false;
        
        // 좌표 i j를 다 바꾸면 중간 것이 두번 flip 돼서, 원상 복구 되는군.
        if(y_size >= x_size){
            swap(y_size, x_size);
            for(int i = 1; i <= y_size; i++)
                for(int j = i; j <= x_size; j++)
                    swap(init_data[i][j], init_data[j][i]);
        }
        else{
            for(int i = 1; i <= y_size; i++)
                for(int j = i; j <= x_size; j++)
                    swap(init_data[i][j], init_data[j][i]);
            swap(y_size, x_size);
        }
        
        
        int first_col = 1, last_col = x_size;
        while(first_col < last_col){
            for(int i = 1; i <= y_size; i++)
                swap(init_data[i][first_col], init_data[i][last_col]);
            first_col++;
            last_col--;
        }
        return true;
    }
};



bool isMovable(const MONITOR& mnt, STICKER& stc){
    if(stc.x + stc.x_size > mnt.x_size ||stc.y + stc.y_size > mnt.y_size)
        return false;

    if(++stc.x + stc.x_size > mnt.x_size){
        stc.x = 1; stc.y++;
        return true;}
    return true;
}



int N, M, K, R, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    
    MONITOR monitor(N, M);
    while(K--){
        cin >> R >> C;
        STICKER sticker(R, C, 0, 0, 0); // new 쓸까?
        sticker.reset();
        
        for(int i = 1; i <= R; i++)
            for(int j = 1; j <= C; j++)
                cin >> sticker.init_data[i][j];
        do{
            sticker.print();
            cout << "\n";
        }while(sticker.rotatable());
        
        do{
            
        }while(isMovable(monitor, sticker));
    }
    //함수 1개가 너무 많은 역할을 한다. 판정 하는 것 따로
    // alloc 하는 것 따로 만들자. 



}