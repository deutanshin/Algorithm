/*https://www.acmicpc.net/problem/2230*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    unsigned int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int idx1 = 0;
    int idx2 = 1;

    unsigned min = 2000000001;

    while(idx2 < N){
        // cout << "idx1: " << idx1 << " | idx2: " << idx2 << endl;
        // cout << "now: " << arr[idx2] - arr[idx1] << endl;
        if(arr[idx2] - arr[idx1] < M){
            idx2++;
        }
        else{
            if(arr[idx2] - arr[idx1] == M){
                min = M;
                break;
            }
            else{
                unsigned int now = arr[idx2] - arr[idx1];
                if(min > now){
                    min = now;
                }
                idx1++;
            }
        }
    }

    cout << min << endl;
    return 0;
}
