#include<bits/stdc++.h>
using namespace std;

int N;
int from_to[101][2];
int cache[101][2]; // 1~i 번째까지, 뺀 것 or 안 뺀 것;
int cache2[101];
const int INF = 2147483647;

bool isCrossed(int line1,int line2){
    return (from_to[line1][0] - from_to[line2][0]) * (from_to[line1][1] - from_to[line2][1]) < 0;
}

// int minExtractLine(int here, int is_extracted){ //1~here, 
//     if(is_extracted){ return 0;}
//     if(here == 1) return 1;
    
//     int& ret = cache[here][is_extracted];
//     if(ret != -1) return ret;

//     int num_crossed = 0;
//     for(int i = 1; i <= here; i++){
//         if(isCrossed(i,here)){// cache2를 infiity 로 보냈다가도 돌려 놔야 해.
//             //is_extracted[i] = 1; //back tracking마냥 inf 를 돌려놔야 하는데
//             cache[i][is_extracted] = 1;
//             num_crossed++;
//         }
//     }

//     if(num_crossed == 0) 
//         return ret = minExtractLine(here-1);
//     else                // here를 빼버림             here과 겹치는 것들을 빼버림
//         return ret = min( minExtractLine(here-1) + 1, minExtractLine(here-1) + num_crossed ); 
//     //fill(is_extracted,is_extracted+101, 0);
// }


// 1 ~ here까지 고려할 때, 겹치지 않기 위한 최소 전선 갯수.
//bool is_extracted[101];

int minExtractLine(int here){ //1~here, 
    //if(extraced_indexs.find(here)){ is_extracted[here] = 1; return 0;}
    if(here == 1) return 1;
    
    int& ret = cache2[here];
    if(ret != -1) return ret;

    int num_crossed = 0;
    for(int i = 1; i <= here; i++){
        if(isCrossed(i,here)){// cache2를 infiity 로 보냈다가도 돌려 놔야 해.
            //is_extracted[i] = 1; //back tracking마냥 inf 를 돌려놔야 하는데
            num_crossed++;
        }
    }

    if(num_crossed == 0) 
        return ret = minExtractLine(here-1);
    else                // here를 빼버림             here과 겹치는 것들을 빼버림
        return ret = min( minExtractLine(here-1) + 1, minExtractLine(here-1) + num_crossed ); 
    //fill(is_extracted,is_extracted+101, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> from_to[i][0] >> from_to[i][1];
    //sort(from_to+1, from_to)
    memset(cache2,-1,sizeof(cache2));
    //cout << min(minExtractLine(1,0), minExtractLine(1,1));
    cout << minExtractLine(N);
}