//
//  33663.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 9..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  경로 추정하기
/*  https://edu.goorm.io/learn/exam/6404/%EC%83%81%EC%8B%9C-%EC%9D%91%EC%8B%9C-1%EC%B0%A8-%EB%AA%A8%EC%9D%98-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8/quiz/33663/%EA%B2%BD%EB%A1%9C-%EC%B6%94%EC%A0%95%ED%95%98%EA%B8%B0
 */
//
/////////////////////////////////////////bfs array
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int dx[] = {0,1,0,-1,0,1,0,-1};
int dy[] = {1,0,-1,0,1,0,-1,0};
int map[101][101];
bool check[101][101];
int new_map[101][101];
int r, c;
int cnt = 1;

void bfs() {
    //queue< tuple<int, int, int> > q;
    queue< pair< pair<int, int>, int > > q;
    check[0][0] = true;
    //q.push(make_tuple(0, 0, 0));
    q.push( make_pair(make_pair(0, 0), 0) );
    new_map[0][0] = cnt++;
    
    while(!q.empty()) {
//        int x = get<0>(q.front());
//        int y = get<1>(q.front());
//        int dir = get<2>(q.front());
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        
        q.pop();
        
        for(int k = dir ; k < (dir + 4) ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(0 <= nx && nx < r && 0 <= ny && ny < c && check[nx][ny] == false) {
                check[nx][ny] = true;
                // q.push(make_tuple(nx, ny, k%4));
                q.push( make_pair(make_pair(nx, ny), k%4) );
                new_map[nx][ny] = cnt++;
                
                break;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int z = 1 ; z <= n ; z++) {
        scanf("%d %d", &r, &c);
        for(int i = 0 ; i < r ; i ++) {
            for(int j = 0 ; j < c ; j ++) {
                map[i][j] = 1;
                new_map[i][j] = 0;
                check[i][j] = false;
            }
        }
        
        bfs();
        
        printf("Case #%d\n", z);
        for(int i = 0 ; i < r ; i ++) {
            for(int j = 0 ; j < c ; j ++) {
                printf("%d ", new_map[i][j]);
            }
            printf("\n");
        }
        cnt = 1;
    }
    
    return 0;
}
