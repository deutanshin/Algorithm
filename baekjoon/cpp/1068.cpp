/*https://www.acmicpc.net/problem/1068*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int idx;
    int par_idx;
    vector<node*> childs;
};

int DFS(node* root, int del_num){
    if(root->idx == del_num) return 0;

    if(root->childs.size() == 0) return 1;

    int sum = 0;

    for(int i = 0; i < root->childs.size(); i++){
        sum += DFS(root->childs[i], del_num);
    }

    return sum;
}


int main(){
    int n;
    cin >> n;
    vector<node*> arr(n);
    for(int i = 0; i < n; i++){
        node* new_node = new node;
        new_node->idx = i;
        cin >> new_node->par_idx;
        arr[i] = new_node;
    }

    node* root;

    for(int i = 0; i < n; i++){       
        if(arr[i]->par_idx == -1){
            root = arr[i];
        }
        else{
            arr[arr[i]->par_idx]->childs.push_back(arr[i]);
        }
    }

    int del_num;
    cin >> del_num;



    int answer =  DFS(root, del_num);

    if(arr[del_num]->par_idx != -1){
        if(arr[arr[del_num]->par_idx]->childs.size() == 1){
            answer++;
        }
    }

    cout << answer;
    return 0;
}