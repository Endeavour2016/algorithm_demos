#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

/**
 * DFS: 深度优先遍历算法
 * 算法步骤：1、从某一个顶点v出发，访问此顶点；
 * 2、依次从顶点 v 的还未被访问的邻接点出发，再次进行深度优先搜索，
 * 直到所有和顶点 v 有路径相通的顶点都被访问到。
 * 3、若图中尚有顶点未被访问，则选择其中一个未被访问的顶点作为起点，重复深度优先搜索的过程。
 */

/**
 * [DFS 递归]
 * @param G [description]
 * @param i [description]
 */
const int NumOfVertexes = 10;

void DFS(Graph G, int v, bool *visited) {
	// 1 访问顶点v
	visited[v] = true;

	// 2 从 v 的邻接点开始，递归调用深度优先搜索
	for (int j = 0; j < NumOfVertexes; j++) // NumOfVertexes:节点的个数
		if (G.arc[v][j] == 1 && !visited[j]) //arc:邻接矩阵
			DFS(G, j, visited);
}

/**
 * [DFS_no_recusion 非递归版本_借助“栈”来实现]
 * @param G       [图的结构体]
 * @param v       [初始节点]
 * @param visited [标记数组：为1表示已经访问过]
 */
void DFS_no_recusion(Graph G, int v, bool visited[])
{
	// 1、栈初始化; visited[] = {0}
	// 2、访问顶点v
	visited[v] = true;
	//3、顶点入栈
	stack<int> s;
	s.push(v);

	//3、循环，直到栈为空
	while (!s.empty()) {
		int x = s.top(); // 取栈顶元素
		s.pop(); //出栈

		// 找到 x 的未被访问的邻接点w
		for (int w = 0; w < NumOfVertexes; w++) {
			if (G.arc[x][w] == 1 && !visited[w]) {
				visited[w] = 1; //访问w
				s.push(w); // w 入栈
				break; // 找到x的第一个邻接点后，跳出for循环，开始外循环，保证搜索纵向进行
			}
		}
	}
}

/**
 * [BFS 广度优先搜索：使用队列，非递归]
 * @param G       [description]
 * @param v       [description]
 * @param visited [description]
 */
void BFS(Graph G, int v, bool visited[]) // 如果数组的引用，形式为int (&a)[]
{
	//1 初始队列queue:visited[] = {0}
	//2 访问顶点v, visited[v] = 1
	//3 顶点入队：q.Enqueue(v)
	//4: 循环
	visited[v] = true;
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		// 取出队头并删除
		v = q.front(); 
		q.pop();
		//访问v的所有未被访问的邻接点
		for (int j = 0; j < NumOfVertexes; j++)
			if (G.arc[v][j] == 1 && !visited[j]) {
				visited[j] = 1;
				// print j
				q.push(j);
			}
	}
}
