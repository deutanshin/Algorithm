#include <iostream>
#include <vector>

using namespace std;


int solution(int n, vector<int>& dp){
    if(dp[n]!= 0) return dp[n];

    return dp[3] + solution(n-3, dp);
}

int main(){
    int t;
    cin >> t;

    vector<int> dp(10001, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;

    

    while(t--){
        int n;
        cin >> n;
        cout << solution(n, dp) << "\n";
    }




    return 0;
}