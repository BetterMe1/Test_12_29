/*
date：2018/12/29
author:BetterMe1
program:小Q的歌单
compiler:Visual Studio 2013
*/

/*题目:
小 Q 的歌单
【 题目描述】小 Q 有 X 首长度为 A 的不同的歌和 Y 首长度为 B 的不同的歌，现在小 Q 想用这些歌组成一个
总长度正好为 K 的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，
请问有多少种组成歌单的方法。
输入描述 ：
每个输入包含一个测试用例。
每个测试用例的第一行包含一个整数，表示歌单的总长度 K(1<=K<=1000)。
接下来的一行包含四个正整数，分别表示歌的第一种长度 A(A<=10)和数量 X(X<=100)以及歌的第二种长度
B(B<=10)和数量 Y(Y<=100)。保证 A 不等于 B。
输出描述 ：
输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对 1000000007 取模的结果。
输入示例 ：
5
2 3 3 3
输出示例 ：
9
*/
/*分析：
由于不考虑歌单内歌曲的先后顺序，因此首先想到的可能就是组合的方法，
先计算出组成长度为 K的歌单需要第一种长度的歌曲和第二种长度的歌曲各多少首。
若第一种长度的歌曲为i首，第二种长度的歌曲为j首时满足条件，
此时在计算在X首歌中选出i首有多少种选法，在Y首歌中选出j首有多少种选法。
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//计算组合的函数
int C(int max, int min){
	int d = 1;//分母
	int n = 1;//分子
	if (min == 0){
		return 1;
	}
	for (int i = max; i > max - min; i--){
		n = i*n;
	}
	for (int j = min; j > 0; j--){
		d = j*d;
	}
	return n / d;
}
int main(){
	int k = 0;
	int a, x, b, y = 0;
	int sum = 0;
	long mod = 1000000007;
	scanf("%d ", &k);
	scanf("%d %d %d %d", &a, &x, &b, &y);
	if (1 <= k && k <= 1000 && a <= 10 && x <= 100 && b <= 10 && y <= 100 && a != b){
		for (int i = 0; i <= x; i++){
			for (int j = 0; j <= y; j++){
				if (a*i + b*j == k){
					sum = sum + C(x, i) * C(y, j);
				}
			}
		}
		printf("%d\n", sum % mod);
	}
	else{
		printf("输入有误！\n");
	}
	system("pause");
	return 0;
}
