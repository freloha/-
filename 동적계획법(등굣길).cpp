#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX = 101;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int map[MAX][MAX] = {0,};
    
    for(int i = 0; i < puddles.size(); i++){
        int a = puddles[i][0];
        int b = puddles[i][1];
        cout << "a : " << a << ", b : " << b << endl;
        map[b][a] = 1;
    }
    
    map[1][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 1){
                map[i][j] = 0;
            }
            else{
                map[i][j] = (map[i-1][j] + map[i][j-1])%1000000007;
            }
            //cout << "i, j : " << i << ", " << j << ", map : " << map[i][j] << endl;
        }
    }
    
    answer = map[n][m];
    
    return answer;
}
