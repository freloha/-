#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int max(queue<int> a){
    int max = 0;
    for(int i = 0; i < a.size(); i++){
        if(a.front() > max)
            max = a.front();
        a.push(a.front());
        a.pop();
    }
    return max;
}

int solution(vector<int> priorities, int location) {
    queue<int> priority;
    queue<int> loc;
    
    int answer = 0;
    int pos = 0;
    
    for(auto i : priorities){
        priority.push(i);
        loc.push(pos);
        //cout << "p : " << i << ", l : " << pos << endl;
        pos++;
    }
    //cout << "werwer" << endl;
    int max1 = max(priority);
    //cout << "max : " << max1 << ", priority front : " << priority.front() << ", answer : " << answer << endl;
    
    while(true){
        cout << "max : " << max1 << ", priority front : " << priority.front() << ", answer : " << answer << endl;
        if(max1 == priority.front()){
            answer++;
            if(loc.front() == location){
                break;
            }
            priority.pop();
            loc.pop();            
            max1 = max(priority);
        }
        else{
            int p = priority.front();
            int l = loc.front();
            priority.pop();
            loc.pop();
            priority.push(p);
            loc.push(l);
        }
    }
    
    return answer;
}
