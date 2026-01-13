/*https://www.acmicpc.net/problem/2170*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> lines(N);
    while(N--){
        int x, y;
        cin >> x >> y;

        lines.push_back(make_pair(x, y));
    }

    sort(lines.begin(), lines.end());

    int last_end = -1000000001;
    int total = 0;

    for(int i = 0; i < lines.size(); i++){
        if(lines[i].first <= last_end){
            if(lines[i].second <= last_end) continue;
            else{
                total += (lines[i].second - last_end);
                last_end = lines[i].second;
            }
        }
        else{
            total += (lines[i].second - lines[i].first);
            last_end = lines[i].second;
        }

    }



    cout << total;
    return 0;
}