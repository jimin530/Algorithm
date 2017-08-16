//
//  9012.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 16..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/9012
//

#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <string.h>

std::stack<char> ps;
char value[51];

int main(void) {
    
    int num = 0;
    int length = 0;
    bool isVPS  = false;
    
    scanf("%d", &num);
    
    while(num--) {
        scanf("%s", value);
        length = (int)strlen(value);
        
        for(int i = 0 ; i < length ; i++) {
            if (value[i] == '(') {
                ps.push(value[i]);
                isVPS = false;
            }
            else {
                if(ps.size() == 0) {
                    isVPS = false;
                    break;
                }
                if(ps.top() == '(') {
                    ps.pop();
                    if(ps.size() == 0) {
                        isVPS = true;
                    }
                }
            }
        }
        if(isVPS) {
            printf("YES\n");
            while( !ps.empty() ) ps.pop();
            isVPS = false;
        }
        else {
            printf("NO\n");
            while( !ps.empty() ) ps.pop();
            isVPS = false;
        }
        
    }
    
    return 0;
}
