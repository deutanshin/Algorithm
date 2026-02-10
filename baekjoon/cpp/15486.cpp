/*https://www.acmicpc.net/problem/15486*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int retire(int idx, vector<int>& day, vector<int>& cost, vector<int>& memo){
    if(idx >= day.size()) return 0;
    if(memo[idx] != -1) return memo[idx];

    int result = retire(idx + 1, day, cost, memo);

    if(idx + day[idx] <= day.size()){
        result =  max(result, cost[idx] + retire(idx + day[idx], day, cost, memo));
    }
    
    memo[idx] = result;

    return memo[idx];
}

int main(){
    int N;
    cin >> N;

    vector<int> day(N);
    vector<int> cost(N);
    vector<int> memo(N);

    for(int i = 0; i < N; i++){
        cin >> day[i];
        cin >> cost[i];
        memo[i] = -1;
    }

    cout << retire(0, day, cost, memo);

    return 0;
}