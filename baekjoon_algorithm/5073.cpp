#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a,b,c;


int main(){
    while(cin >> a >> b >>c ){
        int arr[] = {a,b,c};
        sort(arr, arr+3);
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            return 0;
        else if(arr[0] + arr[1] <= arr[2])
            cout << "Invalid\n";
        else if(arr[0] == arr[1] && arr[1] == arr[2])
            cout << "Equilateral\n";
        else if(arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[0])
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}