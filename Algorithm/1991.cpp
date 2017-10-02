//
//  1991.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 2..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  트리 순위
//  https://www.acmicpc.net/problem/1991
//

//#include <cstdio>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//char a[100][2];
//
//void preorder(char root) {
//    if(root == '.') return;
//    printf("%c", root);
//    preorder(a[x][0]);
//    preorder(a[x][1]);
//}
//void inorder(char root) {
//    if(x == '.') return;
//    inorder(a[x][0]);
//    printf("%c", root);
//    inorder(a[x][1]);
//}
//void postorder(char root) {
//    if(x == '.') return;
//    postorder(a[x][0]);
//    postorder(a[x][1]);
//    printf("%c", root);
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    char x, y, z;
//
//    for(int i = 1; i <= n ; i++) {
//        cin >> x >> y >> z;
//        a[x][0] = y;
//        a[x][1] = z;
//    }
//    preorder('A');
//    printf("\n");
//    inorder('A');
//    printf("\n");
//    postorder('A');
//    printf("\n");
//
//    return 0;
//}

/////ver 2.
#include <iostream>
using namespace std;
 
int n;
 
struct node {
        char left;
        char right;
};
 
struct node arr[100];
 
void preorder(char root) {
        if (root == '.')
                return;
        else {
                cout << root;
                preorder(arr[root].left);
                preorder(arr[root].right);
            }
}
 
void inorder(char root) {
        if (root == '.')
                return;
        else {
                inorder(arr[root].left);
                cout << root;
                inorder(arr[root].right);
            }
}
 
void postorder(char root) {
        if (root == '.')
                return;
        else {
                postorder(arr[root].left);
                postorder(arr[root].right);
                cout << root;
            }
}
 
int main() {
        std::ios::sync_with_stdio(false);
        cin >> n;
     
        char t1, t2, t3;
     
        for (int i = 1; i <= n; i++) {
                cin >> t1 >> t2 >> t3;
                arr[t1].left = t2; arr[t1].right = t3;
            }
     
        preorder('A');
        cout << "\n";
        inorder('A');
        cout << "\n";
        postorder('A');
        cout << "\n";
     
        return 0;
}
