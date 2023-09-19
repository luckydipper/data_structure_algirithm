#include <bits/stdc++.h>

using namespace std;
int arr[] = {1,4,26,132,5,12,13,2,4,3,3,5,1};

void merge(int arr[], int begin, int end){
    int size = end - begin;
    int mid = begin + (size)/2;
    int tmp[size];
    //fill(tmp, tmp+size, 0);
    int ptr_l = begin, ptr_r = mid;

    for(int i = 0; i < size; i++){
        if(ptr_l == mid){
            tmp[i] = arr[ptr_r];
            ptr_r++;
        }
        else if (ptr_r == end){
            tmp[i] = arr[ptr_l];
            ptr_l++;
        }
        else{
            if(arr[ptr_l] < arr[ptr_r]){
                tmp[i] = arr[ptr_l];
                ptr_l++;
            }
            else{
                tmp[i] = arr[ptr_r];
                ptr_r++;
            }
        }
    }
    
    
    for(int i = 0; i < size; i++)
        arr[begin+i] = tmp[i];
}

void implement_merge_sort(int arr[], int begin, int end){
    if(begin+1 >= end)
        return;
    int mid = begin + (end - begin)/2;
    implement_merge_sort(arr, begin, mid);
    implement_merge_sort(arr, mid, end);
    merge(arr, begin, end);
}

void merge_sort(int arr[], int size){
    implement_merge_sort(arr, 0, size);
    return ;
}

int main(){
    merge_sort(arr, sizeof(arr)/sizeof(int));
    for(int a: arr)
        cout << a <<", ";
}