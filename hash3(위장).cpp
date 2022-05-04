#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> cloth;
    
    for(int i = 0; i < clothes.size(); i++){
        if(cloth.find(clothes[i][1]) == cloth.end()){
            cloth.insert({clothes[i][1], 1});
            //cout << "test " << cloth.at(clothes[i][1]) << endl;
        }
        else{
            int enter = cloth.at(clothes[i][1]) + 1;
            cloth.erase(clothes[i][1]);
            
            cloth.insert({clothes[i][1], enter});
            //cout << "test " << cloth.at(clothes[i][1]) << endl;
        }
    }
    
    unordered_map<string, int>::iterator iter;
    for(iter = cloth.begin(); iter != cloth.end(); iter++){
        //cout << iter->second << endl;
        answer = answer * (iter->second + 1);
    }
    
    return answer - 1;
}
