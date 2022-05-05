#include <string>
#include <vector>
#include <queue>
#include <iostream>

// 문제 설명도 부실하여 해석에 따라 다양한 풀이가 가능

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<pair<int,int>> bridge; // 다리에 있는 트럭들과 각 트럭들이 입장한 시간
    int time = 0, cur = 0;
    
    for(auto i : truck_weights){
        time++;        
        if(time == bridge.front().second + bridge_length){
            weight += bridge.front().first;
            bridge.pop();
        }
        while(i > weight){
            time = bridge.front().second + bridge_length;
            weight += bridge.front().first;
            bridge.pop();
            cout << "pop" << endl;
        }
        cout << i << " " << time << endl;        
        weight -= i;
        bridge.emplace(i, time);
    }
    answer = bridge.back().second + bridge_length;
    return answer;
}
