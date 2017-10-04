//
//  10799.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 17..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/10799
//

#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    std::stack<char> pipe;
    char value[111111] = {0};
    int count = 0;
    bool before_laser = false;
    int length = 0;
    
    scanf("%s", value);
    length = (int)strlen(value);
    
    for(int i = 0 ; i < length ; i++)  {
        if (value[i] == '(') {
            pipe.push(value[i]);
            before_laser = false;
        }
        else if (value[i] == ')') {
            if(before_laser) {
                pipe.pop();
                count = count + 1;
            }
            // 바로 전에 레이저가 아니었으면
            else {
                pipe.pop();
                count = count + (int)pipe.size();
                before_laser = true;
            }
        }
        else {
            break;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
