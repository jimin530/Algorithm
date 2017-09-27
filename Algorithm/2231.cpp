//
//  2231.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 27..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//  순열 사이클
//  https://www.acmicpc.net/problem/10451
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>

int z = 0;
int check[1000000] = {0, };

int calc(int value) {
    std::string s = std::to_string(value);
    int length = (int)s.size();
    int sum = 0;
    while(length--) {
        int x = (int)pow(10, length);
        sum += (int)pow( (int)(value/x), z );
        value = value - (x * (int)(value/x));
    }
    return sum;
}

int dfs(int node, int count) {
    if(check[node] != 0) {
        return check[node] - 1;
    }
    check[node] = count;
    int calcResult = calc(node);
    return dfs(calcResult, count+1);
}

int main(void) {
    int value = 0;
    scanf("%d %d", &value, &z);
    
    int result = dfs(value, 1);
    printf("%d", result);
    
    return 0;
}
