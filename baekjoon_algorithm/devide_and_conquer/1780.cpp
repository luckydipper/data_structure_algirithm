#include<bits/stdc++.h>
using namespace std;
int N;
const int three_7tms = 3*3*3*3*3*3*3;
int arr[three_7tms+1][three_7tms+1]; // boundary carefull..
int cnt123[3];

// return 2, if there is no collored coherenty

// 함수가 2가지 역할을 하고 있어. 1. 어떤 값을 갖는지 그리고 2. 같은 값을 갖고 있는지 
int isFullyColloredBy(int y, int x, int size){
    int contents = arr[y][x];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(contents != arr[y+i][x+j])
                return 2;
    return contents;
}

void cntPeaceOfPaper(int y, int x, int size){
    if(isFullyColloredBy(y,x,size) != 2)
        cnt123[isFullyColloredBy(y,x,size)+1]++;
    else{
        cntPeaceOfPaper(y,x,size/3);
        cntPeaceOfPaper(y,x+size/3,size/3);
        cntPeaceOfPaper(y,x+size*2/3,size/3);
        cntPeaceOfPaper(y+size/3,x,size/3);
        cntPeaceOfPaper(y+size/3,x+size/3,size/3);
        cntPeaceOfPaper(y+size/3,x+size*2/3,size/3);
        cntPeaceOfPaper(y+size*2/3,x,size/3);
        cntPeaceOfPaper(y+size*2/3,x+size/3,size/3);
        cntPeaceOfPaper(y+size*2/3,x+size*2/3,size/3);
    }
}

int main(){
    cin >> N;
    string tmp;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <=N; j++)
            cin >> arr[i][j];

    cntPeaceOfPaper(1,1,N);
    for(int i = 0; i<3; i++)
        cout << cnt123[i] << "\n";
}