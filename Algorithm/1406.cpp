//
//  1406.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 17..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/1406
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// 커서 기준 왼쪽
// std::stack<char> left;
// 커서 기준 오른쪽
// std::stack<char> right;

int main(void) {
    stack<char> left, right;

    int num = 0;
    char value[600001] = { 0 };
    int length = 0;
    
    scanf("%s", value);
    length = (int)strlen(value);
    
    for(int i = 0 ; i < length ; i ++) {
        left.push(value[i]);
    }
    
    scanf("%d", &num);
    
    while(num--) {
        char order;
        
        // scanf("%c", &order);
        cin >> order;
        
        if (order == 'L') {
            if(!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (order == 'D') {
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (order == 'B') {
            if(!left.empty()) {
                left.pop();
            }
        }
        else if (order == 'P') {
            char add_value;
            // scanf("%c", &add_value);
            cin >> add_value;
            left.push(add_value);
        }
    }
    
    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()) {
        printf("%c", right.top());
        right.pop();
    }
    
    return 0;
}
