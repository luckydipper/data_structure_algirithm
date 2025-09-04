#include <iostream>
#include <string>
#include <vector>
#include <valarray>

// substr, splice, clear

using namespace std;
int C, N;
char board[5][5];
bool is_find_able[5][5];
vector<string> vocab;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1, 1, 0,-1,1,1,0,-1};

bool isFindable(char arr[][5],int i, int j, const string & sentense){
    if(i > =5 || j >= 5 || i < 0 || j < 0)
        return false;
    if(sentense.size() == 1){
        char charact = sentense[0];
        return is_find_able[i][j] = charact == board[i][j];
    }
    if(!is_find_able[i][j])
        return false;
    
    string a(1, sentense[0]);
    bool findable = isFindable(arr,i,j, a) ;

    string sub_sentense = sentense.substr(1, sentense.size()-1);
    for(int k = 0; k < 8; k++){
        findable = findable || isFindable(arr, i+dx[k], j+dy[k],sub_sentense);
    }
    return findable;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C;
    while(C--){
        
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                cin >> board[i][j];
        
        cin >> N;
        
        for(int i = 0; i < N; i++){
            string tmp_str;
            cin >> tmp_str;
            cout << tmp_str << " ";
            bool is_exist = true;
            for(int n = 0; n < 5; n++)
                for(int m = 0; m < 5; m++)
                    is_exist = is_exist && isFindable(board, n, m, tmp_str);
            if(is_exist)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
        vocab.clear();
    }
}