#include <string>
#include <vector>
#include <iostream>

/*
문제 설명이 너무 애매함..
*/

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int first = 0;
    
    for(int i = 0; i < prices.size(); i++){
        int count = 0;
        for(int j = i + 1; j < prices.size(); j++){
            count++;
            if(prices[i] > prices[j]){
                break;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}
