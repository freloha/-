#include <string>
#include <vector>

using namespace std;

int check[200];

void dfs(vector<vector<int>> com, int now, int n){
    check[now] = 1; // i번째 check
    
    for(int i = 0; i < n; i++){
        if(check[i] == 0 && com[now][i] == 1) // 체크는 안해봤으며 연결할 수 있는지
        {
            dfs(com, i, n);            
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(check[i] == 0){
            dfs(computers, i, n);
            answer++;
        }
    }
        
    return answer;
}
