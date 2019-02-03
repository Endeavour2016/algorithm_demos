/**
 * Dijstra最短路径算法
 * @author: zlm
 * @date: 2018-4-6 14:35
 * @description: 用于求解给定图中，源顶点到其他顶点的最短路径
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;

const int N = 6; // 节点个数
/**
 * [求源节点1到其他各个节点的距离]
 * @param w [点与点之间的权重]
 * @param d [距离数组，下标从1开始，为了便于表述]
 * @param s [表示几何S和U，1表示在 S 中，0表示在U中]
 */
void dijstra(int w[N+1][N+1], int *d, int *s) {
	// 从 U 中选择顶点(U中含有 N-1 个顶点，需要 N-1 次大循环)
	for (int i = 1; i <= N-1; i++) {
		
		// step1: 遍历 U 和 dis，选择权重最小的的顶点，放入几何 S 中（设置s[i]=1来实现
		int minWeight = INT_MAX;
        
        // 用于记录距离最小的点 k
        int k = 1;
        
        // 从dis[]中找出距离最小的点
		for (int j = 1; j <= N; j++) {
			if (s[j] == 0 && d[j] < minWeight) { // s[j]==0，表明在几何U中	
				k = j;
				minWeight = d[j];
			}
		}
		
		// 找到了k，将其放入到几何S中
		s[k] = 1;

		// step2: 以 k 为中间点，更新 v 到 U 中顶点的距离dis[]
		for (int j = 1; j <= N; j++) {
			// 若j与顶点k邻接，有权重
			// 则判断v-k-j2的距离和v-j2的距离哪个更小，更新dis[j2]
			if (s[j] == 0 && w[k][j] < INT_MAX) {
				if (d[j] > d[k] + w[k][j])
					d[j] = d[k] + w[k][j];
			}

		}
	}
}

int main()
{	// 假设图中含有 N 个节点
	// 有效数据从下标 1 开始
	int dis[N+1] = {0, 0, 7, 9, INT_MAX, INT_MAX, 14};
	int weight[N+1][N+1] = {
		0,      0,        0,        0,        0,        0,        0,
		0,      0,        7,        9,        INT_MAX,  INT_MAX,  14,
		0,      7,        0,        10,       15,       INT_MAX,  INT_MAX,
		0,      9,        10,       0,        11,       INT_MAX,  2,
		0,      INT_MAX,  15,       11,       0, 		6, 		 INT_MAX,
		0,      INT_MAX,  INT_MAX,  INT_MAX,  6, 		0, 		 9,
		0,      14,       INT_MAX,  2,        INT_MAX, 	9, 		 0
	};
	int s[N+1] = {0, 1, 0, 0, 0, 0, 0}; //初始只有节点 1 在中

	cout << "shortest path from V to Other Node is: "<< endl;

	dijstra(weight, dis, s);
	for (int i = 1; i <= N; i++)
		cout << dis[i] << "  ";

	cout << endl;

	return 0;
}

