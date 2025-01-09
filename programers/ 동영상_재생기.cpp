// 구현임. 단위 통일 시키기
#include <string>
#include <vector>
#include <bits/stdc++.h>
//chrono && regex
// second로 변환해서 하기 

using namespace std;

int str2time(const string& str){//substr
    string m, s;
    for(int i = 0; i<2; i++){
        m.push_back(str[i]);
        s.push_back(str[3+i]);
    }
    return 60*stoi(m) + stoi(s);
}

bool isInOP(int op_start, int op_end, int here){
    return op_start <= here && here <= op_end;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int end_s = str2time(video_len), pos_s = str2time(pos); 
    int op_start_s = str2time(op_start), op_end_s = str2time(op_end);
    
    if(isInOP(op_start_s, op_end_s, pos_s))
        pos_s = op_end_s;
    
    for(const string& cmd: commands){
        if(cmd == string("next"))
            pos_s += 10;
        if(cmd == string("prev"))
            pos_s -= 10;
        if(isInOP(op_start_s, op_end_s, pos_s))
            pos_s = op_end_s;
        if(pos_s < 0)
            pos_s = 0;
        if(pos_s > end_s)
            pos_s = end_s;
    }
    if(isInOP(op_start_s, op_end_s, pos_s)) 
        pos_s = op_end_s;// 모든 cmd가 끝나고도 OP 안에 있으면 스킵 돼야 함

    int m = pos_s/60, s = pos_s%60;
    string result_m, result_s;
    
    if(m/10<=0)
        result_m = string("0")+to_string(m);
    else
        result_m = to_string(m);
    
    if(s/10<=0)
        result_s = string("0")+to_string(s);
    else
        result_s = to_string(s);
    
    string answer = result_m + string(":") + result_s;
    return answer;
}
