//
//  35170.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 6..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  사천성 시뮬레이터 (1/2)
/*  https://edu.goorm.io/learn/exam/6245/%EC%99%84%EB%A3%8C-2%EC%B0%A8-2015%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-19%EC%9D%BC/quiz/35170/%EC%82%AC%EC%B2%9C%EC%84%B1-%EC%8B%9C%EB%AE%AC%EB%A0%88%EC%9D%B4%ED%84%B0-1-2
 */
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int a[11][11];

void bfs(int x1, int y1, int x2, int y2) {
    bool check[11][11];
    int cnt = 0;
    int flag = -1; // 왼쪽 0, 오른쪽 1, 위쪽 2, 아래쪽 3
    
    queue<pair<int, int>> q;
    q.push(make_pair(x1, y1));
    check[x1][y1] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            // 범위 안에 있으면
            if (0 <= nx && nx < 10 && 0 <= ny && ny < 10) {
                // 무늬가 없고 간 적이 없으면
                if(a[nx][ny] == 0 && check[nx][ny] == false) {
                    
                    // 방향이 꺾이면
                    if(flag != k) {
                        cnt++;
                        q.push(make_pair(nx, ny));
                        check[nx][ny] = true;
                        
                        if(cnt > 3) {
                            printf("NO\n");
                            return;
                        }
                        
                        if(nx == x2 && ny == y2) {
                            printf("YES\n");
                            return;
                        }
                    }
                    // 방향이 그대로면
                    else {
                        q.push(make_pair(nx, ny));
                        check[nx][ny] = true;
                        
                        if(cnt > 3) {
                            printf("NO\n");
                            return;
                        }
                        
                        if(nx == x2 && ny == y2) {
                            printf("YES\n");
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    
    string s = "abc def";
    char c = s[2];
    cout << c;
    
    return 0;
}






















