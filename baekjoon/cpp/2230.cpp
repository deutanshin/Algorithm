/*https://www.acmicpc.net/problem/2230*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    unsigned int N, M;
    cin >> N >> M;

    vector<unsigned int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int idx_left = 0;
    int idx_right = N-1;

    unsigned int sub = arr[idx_right] - arr[idx_left];
    
    while(idx_left + 1 < idx_right){
        unsigned int left_move = arr[idx_right] - arr[idx_left + 1];
        unsigned int right_move = arr[idx_right - 1] - arr[idx_left];

        if(left_move < M && right_move < M){
            break;
        }
        if(right_move < M){
            idx_left++;
            sub = left_move;
            continue;
        }
        else if(left_move < M){
            idx_right--;
            sub = right_move;
            continue;
        }
        else{
            if(left_move < right_move){
                idx_left++;
                sub = left_move;
                continue;
            }
            else{
                idx_right--;
                sub = right_move;
                continue;
            }
        }
    }
    

    cout << sub;

    return 0;
}
