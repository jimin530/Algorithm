//
//  1158.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 19..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/1158
//

#include <stdio.h>
#include <queue>

std::queue<int> round;

int main(void) {
    
    int total = 0;
    int count = 0;
    int reset_count = 1;
    int print_count = 1;
    
    scanf("%d", &total);
    scanf("%d", &count);
    
    for(int i = 1 ; i <= total ; i++ ) {
        round.push(i);
    }
    
    while(!round.empty()) {
        
        if(count == reset_count) {
            if(print_count == 1) {
                printf("<");
            }
            printf("%d", round.front());
            if(print_count != total) {
                printf(", ");
            }
            if(print_count == total) {
                printf(">");
            }
            round.pop();
            reset_count = 1;
            print_count++;
        }
        else {
            round.push(round.front());
            round.pop();
            reset_count++;
        }
    }
    
    return 0;
}
