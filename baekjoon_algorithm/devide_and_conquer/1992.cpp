#include <bits/stdc++.h>

using namespace std;
int N;
int gray_img[65][65];


// y, x 값 cachiing 해 놓으면 최적화 가능할 듯.
bool isFullyGray(int y, int x, int size){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(!gray_img[y+i][x+j]) // there is white pixel
                return false;
    return true;
}

bool isFullyWhite(int y, int x, int size){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(gray_img[y+i][x+j]) // there is white pixel
                return false;
    return true;
}

void compressImg(int y, int x, int size){
    if(isFullyGray(y,x,size))
        cout << 1;
    else if(isFullyWhite(y,x,size))
        cout << 0;
    else{
        cout << "(";
        compressImg(y, x, size/2);
        compressImg(y, x+size/2, size/2); 
        compressImg(y+size/2, x, size/2);
        compressImg(y+size/2, x+size/2, size/2);
        cout << ")";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    string tmp;
    for(int y = 1; y <= N; y++){
        cin >> tmp;
        for(int x = 1; x <= N; x++){
            gray_img[y][x] = tmp[x-1] - '0';
        }
    }

    compressImg(1,1,N);

}