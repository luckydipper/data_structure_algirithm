#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;
int T, result;
vector< pair<int,int> > arr;

// 0 3 // 1 2 1
// 1 5 // 1 2 2
// 45 50 // 1 2 2 1
//0[1]
// 1[0,1,2] 
// -1[0,1,2]

// 1 에 +2나 +1로 도착 [,1,2]
    // -1[,2,] //2
        // 0[1]//-3[,2,] -4[3] 
            //-5[1,2,3] 
    // 0[,1,] //1

// BFS, DFS, DP
// Brute Force로 다 찾으면 되는가? 언제 stop? BFS하다가 한개씩 depth 늘려가면서 찾자 

queue< pair<int,int> > q;

void print_queue(std::queue< pair<int,int> > q_)
{
  while (!q_.empty())
  {
    std::cout << q_.front().first <<", " << q_.front().second  << "||";
    q.pop();
  }
  std::cout << std::endl;
}

int it = 0;

void shortestChance(int i, int momentum, int y){
    q.push(make_pair(i, momentum));

    while(!q.empty() && it <3){
        result++;
        it++;
        queue< pair<int,int> > spare_q;
        spare_q = q;
        while(!q.empty()) q.pop();

        while(!spare_q.empty()){
            auto interest_elem = spare_q.back();
            if(interest_elem.first == y && interest_elem.second == 1 || interest_elem.second == -1 )
                break;
            spare_q.pop();
            
            q.push(make_pair(interest_elem.first + (momentum+1), momentum+1));
            q.push(make_pair(interest_elem.first + (momentum), momentum));
            q.push(make_pair(interest_elem.first + (momentum-1), momentum-1));
        }
    print_queue(q);
    cout << "\n\n============================\n";
    }
}
int main(){
    cin >> T;
    while(T--){
        int from, to;
        cin >> from >> to;
        shortestChance(from+1,1,to);
        cout << result <<"\n";
        result = 0;
    }
}