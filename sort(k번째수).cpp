#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> cop;
    for(int i = 0; i < commands.size(); i++){        
        cop.clear();
        cout<<commands[i][0]  << " " << commands[i][1] << endl;
      
        cop.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        //혹은 copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], cop.begin());
        //을 사용해도 괜찮음
      
        cout << "ans : " << cop[commands[i][2]] << endl;
        sort(cop.begin(), cop.end());
        answer.push_back(cop[commands[i][2] - 1]);
    }
    return answer;
}
