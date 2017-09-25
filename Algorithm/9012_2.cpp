//
//  9012_2.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 18..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/9012
//

#include <stdio.h>
#include <stack>
#include <stdlib.h>

int main(void) {
    
    int n = 0;
    
    scanf("%d", &n);
    
    while(n--) {
        std::stack<char> vps;
        char value[51];
        bool isVps = false;
        scanf("%s", value);
        int length = (int)strlen(value);
        
        for(int i = 0 ; i < length ; i++) {
            if (value[i] == '(') {
                vps.push(value[i]);
                isVps = false;
            }
            else {
                if(vps.size() == 0) {
                    isVps = false;
                    break;
                }
                if(vps.top() == '(') {
                    vps.pop();
                    if(vps.size() == 0) {
                        isVps = true;
                    }
                }
            }
        }
        
        if(isVps)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    
    return 0;
}
