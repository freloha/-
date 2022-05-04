#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int count = 0;
    int index = 0;
    while(index != progresses.size()){
        for(int i = index; i < progresses.size(); i++){
            progresses[i] += speeds[i];
            if(progresses[index] >= 100){
                index++;
                count++;
            }
        }
        if(count > 0){
            answer.push_back(count);
            count = 0;
        }
    }   
    return answer;
}
