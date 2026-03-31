/*https://www.acmicpc.net/problem/2011*/

#include <iostream>
#include <string>
#include <vector>

#define mod 1000000

using namespace std;

bool flag;

bool check(string str, int idx){
    if(idx >= str.size() || idx < 0){
        return false;
    }
    return true;
}

int solution(string str, int idx, vector<int>& dp){
    if(idx == str.size()){
        return 1; 
    }
    if(idx > str.size()){
        return 0;
    }
    if(str[idx] == '0'){
        if(idx == 0) {
            flag = false;
        }
        if(str[idx - 1] > '2'){
            flag = false; 
        } 
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }

    if(str[idx] == '1'){
        if(check(str, idx + 1) && str[idx + 1] == '0'){
            dp[idx] = solution(str, idx + 2, dp) % mod;
            return dp[idx];
        }
        dp[idx] = (solution(str, idx + 1, dp) + solution(str, idx + 2, dp)) % mod;
        return dp[idx];
    }
    else if(str[idx] == '2'){
        if(check(str, idx + 1) && str[idx + 1] == '0'){
            dp[idx] = solution(str, idx + 2, dp) % mod;
            return dp[idx];
        }

        if(check(str, idx + 1) && str[idx + 1] <= '6'){
            dp[idx] = (solution(str, idx + 1, dp) + solution(str, idx + 2, dp)) % mod;
            return dp[idx];
        }        
        else{
            dp[idx] = solution(str, idx + 1, dp) % mod;
            return dp[idx];        
        }
    }
    else{
        dp[idx] = solution(str, idx + 1, dp) % mod;
        return dp[idx];
    }
}

int main(){
    string str;
    cin >> str;
    int size = str.size();
    vector<int> dp(size, -1); 
    flag = true;
    int ans = solution(str, 0, dp);

    if(flag){
        cout << ans;
    }
    else{
        cout << 0;
    }

    return 0;
}