//
//  11652.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 31..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/11652
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    int n = 0;
    cin >> n;
    
    std::vector<long long int> a(n);
    
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    long long int result = a[0];
    int max = 1;
    int sub_max = 1;
    
    for(int i = 1 ; i < n ; i++) {
        if(a[i-1] == a[i]) {
            sub_max++;
        }
        else {
            sub_max = 1;
        }
        if(sub_max > max) {
            max = sub_max;
            result = a[i];
        }
    }
    
    cout << result;
    
    return 0;
}
