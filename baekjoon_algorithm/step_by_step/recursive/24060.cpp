#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//begin end 보단 first last 표현이 더 직관적인 듯.

void printVector(const vector<int>& vec )
{
    for(const int a: vec)
        cout << a << " ";
}
int N, K;
static int COUNT_NUM_CALL;
vector<int> tmp;


//이렇게 써 놓으면 1st argument에 temporal r-value가 들어가면 오류
// 나지 않나?
void merge(vector<int>& unsorted, int begin, int mid, int end){
    int i = begin, j = mid+1, t = 0;
    while(i <= mid && j <= end){
        COUNT_NUM_CALL++;
        if(unsorted[i] <= unsorted[j]){
            if(COUNT_NUM_CALL == K){
                cout << unsorted[i];
            }
            tmp[t++] = unsorted[i++];
        }
        else{
            if(COUNT_NUM_CALL == K){
                cout << unsorted[j];
            }
            tmp[t++] = unsorted[j++];
        }
    }
    while(i <= mid){
        COUNT_NUM_CALL++;
        if(COUNT_NUM_CALL == K){
            cout << unsorted[i];
        }
        tmp[t++] = unsorted[i++];
        
    }
    while(j <= end){
        COUNT_NUM_CALL++;    
        if(COUNT_NUM_CALL == K){
            cout << unsorted[i];
        }        
        tmp[t++] = unsorted[j++];
    }

    i = begin;
    t = 0;
    while(i <= end)
        unsorted[i++] = tmp[t++] ;
}

void merge_sort(vector<int>& unsorted,int begin, int end){
    if(begin < end){
        int mid = (begin+end) / 2;
        merge_sort(unsorted, begin, mid);
        merge_sort(unsorted, mid+1, end);
        merge(unsorted,begin,mid,end);
    }
}


int main(){
    cin >> N >> K;
    vector<int> A(N);
    tmp.resize(N);
    fill(tmp.begin(), tmp.end(), -1);
    COUNT_NUM_CALL = 0;

    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        A[i] = t;
    }
    
    merge_sort(A,0,A.size()-1);
    if(COUNT_NUM_CALL < K)
        cout << -1;
}