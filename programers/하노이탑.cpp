#include <string>
#include <vector>

using namespace std;

vector< vector<int> > answer;

void hanoi(int n, int from, int through, int to ){
    if(n == 1){
        answer.push_back({from,to});
        return;
    }
    hanoi(n-1, from, to, through);
    answer.push_back({from, to});
    hanoi(n-1, through, from, to);
}

vector<vector<int>> solution(int n) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    hanoi(n,1,2,3);
    return answer;
}