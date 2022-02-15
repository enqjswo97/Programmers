#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
long long calPriority(vector<string> num, string operation) {
    vector<string> :: iterator it;
    string temp = "";

    for(char &c : operation) {
        string findoper = "";
        findoper.push_back(c);
        
        while(1){
            it = find(num.begin(),num.end(),findoper);
            if(it != num.end()){
                if(findoper=="+")
                    temp = to_string(stoll(*(it-1)) + stoll(*(it+1)));
                else if(findoper=="*")
                    temp = to_string(stoll(*(it-1)) * stoll(*(it+1)));
                else if(findoper=="-")
                    temp = to_string(stoll(*(it-1)) - stoll(*(it+1)));

                it = num.erase(it-1); //it에 그다음꺼 가리키는 iterator대입됨
                it = num.erase(it); 
                it = num.erase(it); 


            } else break;
            num.insert(it,temp);
        }
    }
    return abs(stoll(num.front()));
}

long long solution(string expression) {
    vector<string> num;
    
    string number = "";
    string oper = "";
    
    for(char c : expression) {
        if(c >= '0' && c <= '9') {
            number.push_back(c);
        }else {
            num.push_back(number);
            number = "";
            oper.push_back(c);
            num.push_back(oper);
            oper.clear();
        }
    }
    num.push_back(number);
    
    vector<string> prio = {"*+-", "*-+", "+-*", "+*-", "-*+", "-+*"};
    long long answer = 0;
    
    for(string &p : prio) 
        answer = max(answer,calPriority(num, p));
    
        
    return answer;
}
