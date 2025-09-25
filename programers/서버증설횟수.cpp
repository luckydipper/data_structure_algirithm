#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> req_computers;

void downScalingWindow(vector<int>& vec,int added_computing_power, int from, int duration){
    for(int i = 0; i < duration; i++)
        if(from+i < vec.size()){
            if(vec[from+i] - added_computing_power >= 0)
                vec[from+i] -= added_computing_power;
            else
                vec[from+i] = 0;
        }
        
}
void printVec(vector<int>& vec){
    for(int a: vec)
        cout << a << ", ";
    cout << "\n";
}

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for(int i = 0; i < players.size(); i++){
        req_computers.push_back(players[i]/m);
    }
    int ret = req_computers[0];
    //printVec(req_computers);
    downScalingWindow(req_computers,ret,0,k);
    //printVec(req_computers);
    for(int i = 0; i < req_computers.size() -1 ; i++){
        if(req_computers[i] < req_computers[i+1]){
            int num_up_scaled_com = req_computers[i+1] - req_computers[i];
            ret += num_up_scaled_com;
            downScalingWindow(req_computers, num_up_scaled_com, i+1, k);
            //cout << "i: " << i <<", " << k <<"\n";
            //printVec(req_computers);
        }
    }
    answer = ret;
    return answer;
}