//
//  10825.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 31..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/10825
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

struct Student {
    std::string name;
    int kor, eng, math;
};

bool cmp(const Student &u, const Student &v) {
    if(u.kor > v.kor) {
        return true;
    }
    else if(u.kor == v.kor) {
        if(u.eng < v.eng) {
            return true;
        }
        else if(u.eng == v.eng) {
            if(u.math > v.math) {
                return true;
            }
            else if(u.math == v.math) {
                return u.name < v.name;
            }
        }
    }
    return false;
}

bool cmp2(const Student &u, const Student &v) {
    return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}

int main(void) {
    
    int n = 0;
    cin >> n;
    
    std::vector<Student> a(n);
    
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }
    
    std::sort(a.begin(), a.end(), cmp2);
    
    for(int i = 0 ; i < n ; i++) {
        cout << a[i].name << '\n';
    }
    
    return 0;
}
