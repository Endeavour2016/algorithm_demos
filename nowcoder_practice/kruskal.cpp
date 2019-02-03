/** 2018-7-27 
 * Kruskal 算法
 * 算法思想： 按照权值从小到大的顺序选择n-1条边，并保证这n-1条边不构成回路。 
 * 算法过程：
 * 1.将图各边按照权值进行排序
 * 2.将图遍历一次，找出权值最小的边（此次找出的边不能和已加入最小生成树集合的边构成环）,
 * 若符合条件，则加入最小生成树的集合中; 不符合条件则继续遍历图，寻找下一个最小权值的边。
 * 3.递归重复步骤1，直到找出n-1条边为止（设图有n个结点，则最小生成树的边数应为n-1条）;
 * 4.算法结束。得到的就是此图的最小生成树。
 */
#include  <iostream>
#include <climits>
#include <string>
#include <string.h>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <functional>
#include <algorithm>
using namespace std;

struct edge{
	int begin;
	int end;
	int weight;
};

int mycmp(edge a, edge b) {
	return a.weight < b.weight; // 意思是在调用sort进行比较时，若a.weight < b.weight，则a和b不用交换位置
}

// 把邻接矩阵中提取出边集数组
void getEdges(vector<vector<int>> &matrix, vector<edge> &edges) {
	int n = matrix.size();
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][j] != INT_MAX)
			{
				edges.push_back({ i, j, matrix[i][j]});
				index++;
			}
		}
}

int find(vector<int> &father, int x) // 查找 x 结点的根结点
{
	if (x == find(father, x))
		return x;
	else {
		father[x] = find(father, father[x]);
		return father[x];
	}
}

void kruskal_test(vector<int> vexs, vector<vector<int>> matrix)
{
	int vexNum = vexs.size();
	vector<edge> res;
	// edges存放的是一个三元组（begin, end, weight）
	// vector<int> vend(vexNum, 0); // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。

	// 获取边集数组
	vector<edge> edges;
	getEdges(matrix, edges);

	vector<int> father; // 记录 n 个节点的根结点，初始化为自身
	for (int i = 0; i < vexNum; i++) {
		father.push_back(i);
	}

	// 1. 对edges按权值排序
	sort(edges.begin(), edges.end(), mycmp);
	// 2. 依次选取较小的边
	int sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].begin;
		int v = edges[i].end;

		int uf = find(father, u);
		int vf = find(father, v);
		if (u != v) {
			sum += edges[i].weight;
			father[u] = v;
			res.push_back(edges[i]); // 保存当前的边
		}
	}

}

int main()
{
    system("pause");
	return 0;
}