#include <string>
#include <vector>

using namespace std;

int answer = 0;

void get_answer(vector<int> num, int target, int sum, int index){
    if(num.size() == index){
        if(sum == target)
            answer++;
        return;
    }
    get_answer(num, target, sum + num[index], index + 1);
    get_answer(num, target, sum - num[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    get_answer(numbers, target, 0, 0);
    return answer;
}
