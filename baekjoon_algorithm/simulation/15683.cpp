#include <bits/stdc++.h>
using namespace std;
int N, M;
int scanning_place[9][9];
vector<pair<int,int>> position_of_camera[6];

enum D{
    l,
    r,
    u,
    d,
};
const vector<D> FOUR_DIRECTION{D::l, D::r, D::u, D::d};

void printPlace(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            cout << scanning_place[i][j] <<" ";
        cout << "\n";
    }
}

int countInvisable(){
    int result = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(scanning_place[i][j] == 0) 
                result++;
                
    return result;
}

//if occupied -1 
int occupySeenPlace(D direction, int x, int y, int with){
    int count_oc = 0;
    if(direction == D::l){
        while(--y >= 1 ){
            if(scanning_place[x][y] == 6) break;
            if(scanning_place[x][y] > 0) continue; // overlab 되지 않게
            count_oc++;
            scanning_place[x][y] = with;
        }
    }
    else if(direction == D::r){
        while(++y <= M ){
            if(scanning_place[x][y] == 6) break;
            if(scanning_place[x][y] > 0) continue;
            count_oc++;
            scanning_place[x][y] = with;
        }
    }
    else if(direction == D::d){
        while(++x <= N ){
            if(scanning_place[x][y] == 6) break;
            if(scanning_place[x][y] > 0) continue;
            count_oc++;
            scanning_place[x][y] = with;
        }
    }
    else if(direction == D::u){
        while(--x >= 1){
            if(scanning_place[x][y] == 6) break;
            if(scanning_place[x][y] > 0) continue;
            count_oc++;
            scanning_place[x][y] = with;
        }
    }
    return count_oc;
}

void occupyByCamera(int camera_num, int x, int y, D direction, int with){
    //camera1
    occupySeenPlace(direction, x, y, with);
    if(camera_num == 2){
        if(direction == D::r || direction == D::l){
            occupySeenPlace(D::r, x, y, with);
            occupySeenPlace(D::l, x, y, with);
        }
        else if(direction == D::u || direction == D::d){
            occupySeenPlace(D::u, x, y, with);
            occupySeenPlace(D::d, x, y, with);
        }
    }
    else if(camera_num == 3){
        if(direction == D::r)
            occupySeenPlace(D::u, x, y, with);
        else if(direction == D::u)
            occupySeenPlace(D::l, x, y, with);
        else if(direction == D::l)
            occupySeenPlace(D::d, x, y, with);
        else if(direction == D::d)
            occupySeenPlace(D::r, x, y, with);
    }
    else if(camera_num == 4){
        if(direction == D::r){
            occupySeenPlace(D::u, x, y, with);
            occupySeenPlace(D::l, x, y, with);
        }else if(direction == D::u){
            occupySeenPlace(D::l, x, y, with);
            occupySeenPlace(D::d, x, y, with);
        }else if(direction == D::l){
            occupySeenPlace(D::d, x, y, with);
            occupySeenPlace(D::r, x, y, with);
        }else if(direction == D::d){
            occupySeenPlace(D::r, x, y, with);
            occupySeenPlace(D::u, x, y, with);
        }
    }
}

vector<int> chosen;
vector<vector<int>> all_case;

void Homogenious(int n, int m){
    if(chosen.size() == m){
        all_case.push_back(chosen);
        return;
    }
    int smallest = chosen.empty() ? 0 : chosen.back();
    for(int i = smallest; i < n; i++){
        chosen.push_back(i);
        Homogenious(n, m);
        chosen.pop_back();
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int the_num_camera = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int occupied;
            cin >> occupied;
            if(!occupied) continue;
            scanning_place[i][j] = occupied;
            if(occupied == 6) continue;
            the_num_camera++;
            position_of_camera[occupied].push_back({i,j});
        }
    }
    
    Homogenious(5, the_num_camera);

    //x, y, kind
    vector<tuple<int,int,int>> camera_array;
    for(int kind = 1; kind <= 5; kind++){
        for(auto& cam_xy : position_of_camera[kind]){
            camera_array.push_back(make_tuple(cam_xy.first, cam_xy.second, kind));
        }
    }

    int min_invisable = N * M;
    // camera를 graph에서 vec<<x,y>, 종류> 로  
    for(const vector<int> &direction_set : all_case){
        
        for(int i = 0; i < direction_set.size(); i++) // cammera array size와 direction_set의 크기가 같다.
            occupyByCamera(get<2> (camera_array[i]), get<0>(camera_array[i]),get<1>(camera_array[i]), FOUR_DIRECTION[direction_set[i]], -1);

        int invisable_temp = countInvisable();
        if(min_invisable > invisable_temp)
            min_invisable = invisable_temp;

        for(int i = 0; i < direction_set.size(); i++) // cammera array size와 direction_set의 크기가 같다.
            occupyByCamera(get<2> (camera_array[i]), get<0>(camera_array[i]),get<1>(camera_array[i]), FOUR_DIRECTION[direction_set[i]], 0);

    }

    cout << min_invisable;
    return 0;
}