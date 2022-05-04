#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int bookSize = phone_book.size();
    
    /*
    string을 정렬하면 a~z순으로, 짧은~긴 순으로 정렬이 됨
    이를 이용하여 단일 for문으로 연산처리
    */
    sort(phone_book.begin(), phone_book.end());
    
    string pre;
    int preSize;
    string com;
    
    for(int i = 0; i < phone_book.size() - 1; i++){        
        if(phone_book[i].compare(phone_book[i+1].substr(0,phone_book[i].length())) == 0){
            cout << i << " : " << phone_book[i];
            cout << ", " << i + 1 << " : " << phone_book[i+1] << endl;
            answer = false;
            break;
        }
    }
    
    return answer;
}
