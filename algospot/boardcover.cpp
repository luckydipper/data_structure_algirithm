//memset은 cstring안에 정의 됨.
// data 랑 로직을 분리해야 함. check_x,y에 중복 되더라도,자기 자신 넣을 것
// Order is important!. 
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int C, H,W;
vector<int> check_x_method[] =  { {1,0}, {1,0}, {0,-1}, {-1,0} };
vector<int> check_y_method[] =  { {0,1}, {0,-1}, {-1,0}, {0,1} };
char arr[11][21];

// bool isOutOfBound{}; //{0,1,2,3}
bool isComplete(char arr[11][21],int H, int W){
    for(int i = 0; i < H; i++)
        for(int j =0; j < W; j++)
            if(arr[i][j] == '.')
                return false;
    return true;
}

bool isFillable(char arr[11][21],int H, int W, int i, int j, int method){
    if(arr[i][j] != '.')
        return false;
    for(int n = 0; n < 2; n++){
        int place_holder_x = i + check_x_method[method][n];
        int place_holder_y = j + check_y_method[method][n];
        if(place_holder_x < 0 || place_holder_x >= H || place_holder_y < 0 || place_holder_y >= W)
            return false;
        if(arr[place_holder_x][place_holder_y] != '.')
            return false;
    }
    return true;
}
void Fill(char arr[11][21],int H, int W, int i, int j, int method){
    arr[i][j] = 'O';
    for(int n = 0; n < 2; n++){
        int place_holder_x = i + check_x_method[method][n];
        int place_holder_y = j + check_y_method[method][n];
        arr[place_holder_x][place_holder_y] = 'O';
    }
}
void Extract(char arr[11][21],int H, int W, int i, int j, int method){
    arr[i][j] = '.';
    for(int n = 0; n < 2; n++){
        int place_holder_x = i + check_x_method[method][n];
        int place_holder_y = j + check_y_method[method][n];
        arr[place_holder_x][place_holder_y] = '.';
    }
}

void printArr(char arr[11][21]){
    for(int i = 0; i <11; i++){
        for(int j =0; j <21; j++)
            cout << arr[i][j];
        cout << "\n";
    }
    cout << "\n\n\n\n";
}
int result = 0;
void cntMethod(char arr[11][21],int H, int W){
    if(isComplete(arr, H, W)){
        result++;
        printArr(arr);
        return;
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            for(int method = 0; method < 4; method++){
                if(isFillable(arr,H,W,i,j,method)){
                    Fill(arr,H,W,i,j,method);
                    cntMethod(arr,H,W);
                    Extract(arr,H,W,i,j,method);
                }
            }
        }
    }
    return;
}

int main(){
    cin >> C;
    while(C--){
        result = 0;
        cin >> H >> W;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++)
                cin >> arr[i][j];
        }
        cntMethod(arr,H,W);
        cout << result << "\n";
    }
}