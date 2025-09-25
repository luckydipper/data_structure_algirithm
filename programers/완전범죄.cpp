// 가방문제랑 비슷한듯
// Greedy 는 DP에 포함이니..
// DP로 최적화 
// 디버깅하는데 시간을 많이 썼다. min(foo, foo) 뿐 아니라, foo를 부를 수 있는 조건을 if 로 감싸자
// base case는 바로 return하자
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int cache[41][121][121];

int least_clue_after_idx(int idx, int n_current, int m_current, const vector<vector<int>>&info, int n, int m){
    if(info.size() == idx)
        return n_current;
    
    int& ret = cache[idx][n_current][m_current];
    // cout << idx << ", " << n_current << ", " << m_current <<", " << ret <<"\n";
    
    if(ret != 200)
        return ret;

    int a = info[idx][0];
    int b = info[idx][1];
    int select_a, select_b;
    select_a = select_b = 999999;
    if(n_current + a >= n && m_current + b >= m)
        return ret = 999999;
    if(n_current + a < n)
        select_a = least_clue_after_idx(idx+1,n_current + a, m_current,     info, n, m);
    if(m_current + b < m)
        select_b = least_clue_after_idx(idx+1,n_current    , m_current + b, info, n, m);
    // cout << "select_a" << select_a << "select_b" << select_b << "\n";
    return min(select_a, select_b);
    
}


int solution(vector<vector<int>> info, int n, int m) {
    for(int i = 0; i < 40; i++)
        for(int j = 0; j < 120; j++)
            for(int k = 0; k < 120; k++)
                cache[i][j][k] = 200;
    int answer = least_clue_after_idx(0,0,0,info,n,m);
    if(answer == 999999)
        return -1;
    return answer;
}