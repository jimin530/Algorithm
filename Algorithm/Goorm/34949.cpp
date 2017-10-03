//
//  34949.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 3..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  가장 가까운 두 점
/*  https://edu.goorm.io/learn/exam/6161/%EC%99%84%EB%A3%8C-1%EC%B0%A8-2016%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-18%EC%9D%BC/quiz/34949/%EA%B0%80%EC%9E%A5-%EA%B0%80%EA%B9%8C%EC%9A%B4-%EB%91%90-%EC%A0%90
*/
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int main() {
    int n;
    scanf("%d", &n);
    
    while(n--) {
        int value;
        scanf("%d", &value);
        a.push_back(value);
    }
    
    sort(a.begin(), a.end());
    
    int first = a[0];
    int second = a[1];
    int dist = second - first;
    for(int i = 1 ; i < a.size() - 1 ; i++) {
        if(a[i+1] - a[i] < dist) {
            first = a[i];
            second = a[i+1];
            dist = second - first;
        }
    }
    
    printf("%d %d", first, second);
    
    return 0;
}
