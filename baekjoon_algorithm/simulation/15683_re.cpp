#include <bits/stdc++.h>
using namespace std;
int N, M;
int scanning_place[9][9];

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
int occupySeenPlace(const D& direction, int x, int y, int with){
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

void occupyByCamera(int camera_num, int x, int y, const D& direction, int with){
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
    else if(camera_num == 5){
        occupySeenPlace(D::u, x, y, with);
        occupySeenPlace(D::l, x, y, with);
        occupySeenPlace(D::d, x, y, with);
        occupySeenPlace(D::r, x, y, with);
    }
}

// permutation with repeat 
vector<int> chosen;
vector<vector<int>> all_case;
int min_invisable = 8 * 8;
vector<tuple<int,int,int>> camera_array;

void generate_all_case(int the_num_camera){
    if(chosen.size() == the_num_camera){
        for(int i = 0; i < chosen.size(); i++)
            occupyByCamera(get<2> (camera_array[i]), get<0>(camera_array[i]),get<1>(camera_array[i]), FOUR_DIRECTION[chosen[i]], -1);
        int invisable_temp = countInvisable();

        if(min_invisable > invisable_temp)
            min_invisable = invisable_temp;

        for(int i = 0; i < chosen.size(); i++) // cammera array size와 direction_set의 크기가 같다.
            occupyByCamera(get<2> (camera_array[i]), get<0>(camera_array[i]),get<1>(camera_array[i]), FOUR_DIRECTION[chosen[i]], 0);
        return;
    }
    for(int i = 0; i < the_num_camera; i++){
        chosen.push_back(i);
        generate_all_case(the_num_camera);
        chosen.pop_back();   
    }
}


void repeatable_permutation_by_bit_mask(int the_num_camera){
    // 4진수 
    min_invisable = countInvisable(); // for 1 1 0 case
    for(int i = 0; i < 4*((pow(4,the_num_camera)-1)/3); i++){
        for(int j = 0; j < the_num_camera; j++){
            int d = (int)(i/pow(4,j)) % 4;
            occupyByCamera(get<2> (camera_array[j]), get<0>(camera_array[j]),get<1>(camera_array[j]), FOUR_DIRECTION[d], -1);
        }

        int invisable_temp = countInvisable();

        if(min_invisable > invisable_temp)
            min_invisable = invisable_temp;

        for(int j = 0; j < the_num_camera; j++){
            int d = (int)(i/pow(4,j)) % 4;
            occupyByCamera(get<2> (camera_array[j]), get<0>(camera_array[j]),get<1>(camera_array[j]), FOUR_DIRECTION[d], 0);
        }
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
            camera_array.push_back(make_tuple(i, j, occupied));
        }
    }
    
    //generate_all_case(the_num_camera);
    repeatable_permutation_by_bit_mask(the_num_camera);
    
    cout << min_invisable;
    return 0;
}