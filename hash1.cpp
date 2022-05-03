#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

/*
개요 : unordered_multiset을 통하여 중복되는 값들을 받아온다.
이후 중복값을 하나씩 제거하기 위하여 iterator를 사용하여 제거한다.
multiset을 사용하면 검색 속도가 O(1)이기 때문에 빠르게 검색 및 삭제가 가능하다.
*/

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> c1; // unordered_multiset은 중복 허용
    string answer;
    
    for(auto i : participant){
        c1.insert(i);
    }
    
    /*
    unordered_multiset<string>::const_iterator it1 = c1.begin();
    for (unordered_multiset<string>::const_iterator iter = c1.begin(); iter != c1.end(); ++iter)
   {
       cout << "[" << *iter << "] ";
   }
    cout << endl;
    */
    
    for(auto i : completion){
        unordered_multiset<string>::iterator it3 = c1.find(i);
        if(c1.find(i) != c1.end()){ // unordered_set에서 해당 값을 찾지 못할 경우, end를 가리킨다
            c1.erase(it3);
        }
    }
    
    /*
    unordered_multiset<string>::const_iterator it2 = c1.begin();
    for (unordered_multiset<string>::const_iterator iter = c1.begin(); iter != c1.end(); ++iter)
   {
       cout << "[" << *iter << "] ";
   }
    */
    
    
    
    for(auto i : participant){
        unordered_multiset<string>::iterator it4 = c1.find(i);
        if(c1.find(i) != c1.end()){ // unordered_set에 해당 값이 있으면
            answer += i;
            c1.erase(it4);
        }
    }
    
    return answer;
}
