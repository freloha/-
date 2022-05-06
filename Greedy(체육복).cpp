#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    /*
    정렬을 해야 아래 lost[i] - 1과 lost[i] + 1의 조건문을 올바르게 성립시키기 위해서는 정렬이 필수
    */
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j]){
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i = i - 1;
                cout<< "i, j, answer : " << i << " " << j << " " << answer << endl;
                break;
            }
        }
    }
    
    for(int i = 0; i < lost.size(); i++){        
        for(int j = 0; j < reserve.size(); j++){              
            if(lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]){
                lost.erase(lost.begin() + i);
                i--;
                reserve.erase(reserve.begin() + j);
                //cout<< "i, j, answer : " << i << " " << j << " " << answer << endl;
                break;
            }
        }
    }
    
    return n - lost.size();
}
