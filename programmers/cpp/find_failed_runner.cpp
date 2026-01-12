/*https://school.programmers.co.kr/learn/courses/30/lessons/42576*/

#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hash;
    
    string answer = "";
    
    for(int i = 0; i < participant.size(); i++){
        auto it = hash.find(participant[i]);
        if(it == hash.end()){
            hash[participant[i]] = 1;
        }else{
            hash[participant[i]]++;
        }
    }
    
    for(int i = 0; i < completion.size(); i++){
        hash[completion[i]]--;
    }
    
    for(auto it = hash.begin(); it != hash.end(); it++){
        if(it->second != 0){
            answer = it->first;
            break;
        }
    }
    
    
    return answer;
}