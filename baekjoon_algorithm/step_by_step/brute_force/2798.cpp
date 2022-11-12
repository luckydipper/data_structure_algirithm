#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int MAX_N = 100;

    vector<int> domain(MAX_N+1);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        domain[i] = a;
    }
    
    int result = 0;

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                int pick_3 = domain[i] + domain[j] + domain[k];
                if(M >= pick_3 && (M-result) > (M-pick_3))
                    result= pick_3;
            }
        }
    }
    cout << result;
}