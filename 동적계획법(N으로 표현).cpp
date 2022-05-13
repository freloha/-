#include <string>
#include <vector>
#include <unordered_set> // unordered_set은 중복 허용X, unordered_multiset은 중복 허용

using namespace std;

int makeN(int n, int index){ // index가 1이면 n, 2이면 nn
    int answer = n;
    for(int i = 1; i < index; i++)
        answer = answer * 10 + n;
    return answer;
}

int solution(int N, int number) {
    int answer = 0;
    
    vector<unordered_set<int>> DP(9);
    
    for(int k = 1; k <=8; k++){
        DP[k].insert(makeN(N, k));
    for(int i = 0; i <k; i++){        
        for(int j = 0; j < k; j++){
            if(i+j != k) continue; // 두 합이 8이 아니면 계산 하면 안됨
            for(int a : DP[i]){
                for(int b : DP[j]){
                    DP[k].insert(a+b);
                    DP[k].insert(a*b);
                    if(a/b > 0)
                        DP[k].insert(a / b);
                    if(a-b > 0)
                        DP[k].insert(a - b);
                }
            }
        }
        if(DP[k].find(number) != DP[k].end())
            return k;
    }
    }
    
    return -1;
}
