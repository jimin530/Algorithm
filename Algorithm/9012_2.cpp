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

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <stack>
using namespace std;

int main() {
    //std::ios_base::sync_with_stdio(false);
    int n = 0;
    
    scanf("%d", &n);
    std::string s;
    getline(std::cin, s);
    
    while(n--) {
        std::stack<char> vps;
        std::string s;
        bool isVps = false;
        getline(std::cin, s);
        
        for(int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '(') {
                vps.push(s[i]);
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
