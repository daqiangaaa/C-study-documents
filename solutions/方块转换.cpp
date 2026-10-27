// 洛谷 P1205 [USACO1.2] 方块转换 Transformations
//
// 题意：给 n×n 的 @ / - 图案（1 <= n <= 10），再给一个目标图案。
//       判断从原图变成目标图需要哪种变换，输出编号最小的那个 1~7：
//         1 = 顺时针 90°
//         2 = 顺时针 180°
//         3 = 顺时针 270°（就是逆时针 90°）
//         4 = 左右镜像
//         5 = 先左右镜像，再顺时针转 90° / 180° / 270°
//         6 = 不改变
//         7 = 以上都不是
//
// 核心：只要记住两条公式，其余 5 种全由它们拼出来。
//     顺时针 90°：dst[i][j] = src[n-1-j][i]
//     左右镜像  ：dst[i][j] = src[i][n-1-j]
//   90° 那条怎么来的：旧位置 (i, j) 转完落在 (j, n-1-i)，
//   反过来读就是「新图的 (i, j) 从旧图的 (n-1-j, i) 搬过来」。
//
// 两个关键点（都是踩过坑才记住的）：
//   1. 函数必须带 (src, dst) 两个参数。如果函数里写死「从 a 读、往 b 写」，
//      那么连转三次算的还是同一个结果，180° / 270° 一次都生成不出来。
//   2. 6 号（不改变）必须放到最后判断。图案本身对称时（比如 n=1、全 @，
//      或者自带 90° 旋转对称的图），好几种变换会同时成立；
//      题目要的是「最小序号」，所以按 1→2→3→4→5→6 的顺序试，
//      第一个命中的就是答案，顺序本身就保证了最小。

#include <bits/stdc++.h>
using namespace std;

char a[12][12];        // 原图
char b[12][12];        // 工作区
char jieguo[12][12];   // 目标图
int n;

// 顺时针旋转 90°：src 转完存进 dst
void rot90(char src[12][12],char dst[12][12]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dst[i][j]=src[n-1-j][i];
        }
    }
}

// 左右镜像：src 翻完存进 dst
void mirror(char src[12][12],char dst[12][12]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dst[i][j]=src[i][n-1-j];
        }
    }
}

// 两张图完全一样吗
bool check(char x[12][12],char y[12][12]){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i][j]!=y[i][j])return false;
        }
    }
    return true;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>jieguo[i][j];
        }
    }

    // c、d 用来存「转两次」「转三次」的结果，t 存镜像结果
    char c[12][12],d[12][12],t[12][12];

    // 1 / 2 / 3：连续转三次，每次都是在上一次的基础上转
    rot90(a,b);if(check(b,jieguo)){puts("1");return 0;}
    rot90(b,c);if(check(c,jieguo)){puts("2");return 0;}
    rot90(c,d);if(check(d,jieguo)){puts("3");return 0;}

    // 4：只镜像
    mirror(a,t);if(check(t,jieguo)){puts("4");return 0;}

    // 5：先镜像（结果在 t），再转 1 / 2 / 3 次
    rot90(t,b);if(check(b,jieguo)){puts("5");return 0;}
    rot90(b,c);if(check(c,jieguo)){puts("5");return 0;}
    rot90(c,d);if(check(d,jieguo)){puts("5");return 0;}

    // 6：原封不动 —— 必须放最后！
    if(check(a,jieguo)){puts("6");return 0;}

    // 7：都不是
    cout<<"7"<<'\n';
    return 0;
}