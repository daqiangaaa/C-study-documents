/* 打分题（去掉一个最高分、一个最低分，求剩下的平均分）
 * 输入: 第一行 n，第二行 n 个 0~10 的整数
 * 输出: 剩下的 n-2 个分数的平均数，保留 2 位小数
 *
 * 思路: 这题根本不用排序。
 *   去掉一个最高分、一个最低分 —— 两头各扔掉一个，
 *   顺序对答案毫无影响，所以只需要知道:
 *     sum = 所有分数之和
 *     mx  = 最高分
 *     mn  = 最低分
 *   剩下的和就是 sum - mx - mn。
 * 复杂度 O(n)，一个数组都不用开。
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0, mx = -1, mn = 11;   // 分数范围 0~10，所以 mx 从 -1、mn 从 11 起步
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (x > mx) mx = x;
        if (x < mn) mn = x;
    }

    /* 两个 int 相除是整数除法，必须把分母转成 double */
    printf("%.2f\n", (sum - mx - mn) / (double)(n - 2));
    return 0;
}