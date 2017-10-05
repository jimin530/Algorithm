//
//  35160.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 5..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  괄호 짝 맞추기 (1/2)
/*  https://edu.goorm.io/learn/exam/6245/%EC%99%84%EB%A3%8C-2%EC%B0%A8-2015%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-19%EC%9D%BC/quiz/35160/%EA%B4%84%ED%98%B8-%EC%A7%9D-%EB%A7%9E%EC%B6%94%EA%B8%B0-1-2
 */
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string tmp;
    getline(cin, tmp);
    while(n--) {
        stack<char> s;
        bool isVPS = false;
        string str;
        getline(cin, str);
        int length = (int)str.size();
        vector<char> v(str.begin(), str.end());
        
        for(int i = 0 ; i < length ; i++) {
            char c = v[i];
            if(!(c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')) {
                continue;
            } else {
                // 여는 괄호면
                if(c == '(' || c == '{' || c == '[') {
                    s.push(c);
                    isVPS = false;
                }
                // 닫는 괄호면
                else {
                    if(s.size() == 0) {
                        isVPS = false;
                        break;
                    }
                    
                    if(c == ')') {
                        // 정상
                        if(s.top() == '(') {
                            s.pop();
                            // 빼고 사이즈가 0이면 완전체
                            if(s.size() == 0) {
                                isVPS = true;
                            }
                        } else {
                            isVPS = false;
                            break;
                        }
                    }
                    else if(c == '}') {
                        // 정상
                        if(s.top() == '{') {
                            s.pop();
                            // 빼고 사이즈가 0이면 완전체
                            if(s.size() == 0) {
                                isVPS = true;
                            }
                        } else {
                            isVPS = false;
                            break;
                        }
                    }
                    else if(c == ']') {
                        // 정상
                        if(s.top() == '[') {
                            s.pop();
                            // 빼고 사이즈가 0이면 완전체
                            if(s.size() == 0) {
                                isVPS = true;
                            }
                        } else {
                            isVPS = false;
                            break;
                        }
                    }
                }
            }
        }
        if(isVPS) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}







