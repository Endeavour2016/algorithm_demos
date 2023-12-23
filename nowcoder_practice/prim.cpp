/*
 * @Author: zlm 
 * @Date: 2018-7-26 20:32
 * @Last Modified by: zlm
 * @Last Modified time: 2021-10-24 00:33:23
 */


// 最小生成树算法 prim:用来求加权连通图的最小生成树算法
// 算法描述：
// 图G = (V,G), V是所有顶点的集合。现在设置两个新的集合(U,T),其中U是存放最小生成树-MST的顶点，T是MST的边。
// 1) 算法初始时，从V中任选一点（假设为v0）放入到集合U中 ，此时U = {v0}；
// 2) 从所有的ui∈U，vj∈V-U构成的边中选择权值最小的那个边（ui,vj），此时更新集合U和T，即将顶点vj加入U，将(ui,vj)放入T中；
// 3) 更新U和T后，不断重复步骤2，直到N个顶点全部放入到U中。此时T中包含了最小生成数的N-1条边。


#include  <iostream>
#include <climits>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

// 构造邻接矩阵
const int MAX = 100;
const int INF = INT_MAX;
class MatrixUDG {
private:
	char mVexs[MAX]; // 顶点集合
	int mVexNum;  // 顶点个数
	int mEdgNum;
	int mMatrix[MAX][MAX]; // 邻接矩阵

public:
	// 创建图
	MatrixUDG();

	// 创建图：用已提供的矩阵
	MatrixUDG(char vexs[], int vlen, int matrix[][9]);
	~MatrixUDG();

	// dfs
	void DFS();

	// 最小生成树的函数
	void prim(int start); 

	// 打印矩阵队列图
	void print();

private:
	char readChar();
	int getPosition(char ch);
	
	// v的第一个邻接点
	int firstVertex(int v); 

	// 返回顶点 v 相对于 w 的下一个邻接顶点的索引，失败则返回-1
	void DFS(int v0, int *visited);
	
	int nextVertex(int v, int w);  
};

// 成员函数的实现
MatrixUDG::MatrixUDG() {
	char c1, c2;
	int i, j, weight, p1, p2;

	// 输入"顶点数"和"边数"
	cout << "input vertex number: ";
	cin >> mVexNum;
	cout << "input edge number: ";
	cin >> mEdgNum;
	if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum >(mVexNum * (mVexNum - 1)))) {
		cout << "input error: invalid parameters!" << endl;
		return;
	}

	// 初始化"顶点"
	for (i = 0; i < mVexNum; i++) {
		cout << "vertex(" << i << "): ";
		mVexs[i] = readChar();
	}

	// 1. 初始化"边"的权值
	for (i = 0; i < mVexNum; i++) {
		for (j = 0; j < mVexNum; j++) {
			if (i == j)
				mMatrix[i][j] = 0;
			else
				mMatrix[i][j] = INF;
		}
	}
	// 2. 初始化"边"的权值: 根据用户的输入进行初始化
	for (i = 0; i < mEdgNum; i++) {
		// 读取边的起始顶点，结束顶点，权值
		cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();
		cin >> weight;

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1) {
			cout << "input error: invalid edge!" << endl;
			return;
		}

		mMatrix[p1][p2] = weight;
		mMatrix[p2][p1] = weight;
	}
}

/**
 * 创建图(用已提供的矩阵)
 * 参数说明：
 *    vexs  -- 顶点数组
 *    vlen  -- 顶点数组的长度
 *    matrix-- 矩阵(数据)
 */
MatrixUDG::MatrixUDG(char vexs[], int vlen, int matrix[][9]) {
	int i, j;

	// 初始化"顶点数"和"边数"
	mVexNum = vlen;
	// 初始化"顶点"
	for (i = 0; i < mVexNum; i++)
		mVexs[i] = vexs[i];

	// 初始化"边"
	for (i = 0; i < mVexNum; i++)
		for (j = 0; j < mVexNum; j++)
			mMatrix[i][j] = matrix[i][j];

	// 统计边的数目
	for (i = 0; i < mVexNum; i++)
		for (j = 0; j < mVexNum; j++)
			if (i != j && mMatrix[i][j] != INF)
				mEdgNum++;
	mEdgNum /= 2;
}

MatrixUDG::~MatrixUDG() {}

// 返回ch在mMatrix矩阵中的位置
int MatrixUDG::getPosition(char ch) {
	int i;
	for (i = 0; i<mVexNum; i++)
		if (mVexs[i] == ch)
			return i;
	return -1;
}

// 读取一个输入字符
char MatrixUDG::readChar() {
	char ch;

	do {
		cin >> ch;
	} while (!((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')));

	return ch;
}

// 返回顶点v的第一个邻接顶点的索引，失败则返回-1
int MatrixUDG::firstVertex(int v) {
	int i;

	if (v<0 || v>(mVexNum - 1))
		return -1;

	for (i = 0; i < mVexNum; i++)
		if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
			return i;

	return -1;
}


// 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
int MatrixUDG::nextVertex(int v, int w) {
	int i;
	if (v<0 || v>(mVexNum - 1) || w<0 || w>(mVexNum - 1))
		return -1;
	for (i = w + 1; i < mVexNum; i++)
		if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
			return i;

	return -1;
}

/*
* 深度优先搜索遍历图的递归实现
*/
void MatrixUDG::DFS(int i, int *visited) {
	int w;
	visited[i] = 1;
	cout << mVexs[i] << " ";

	// 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w)) {
		if (!visited[w])
			DFS(w, visited);
	}
}

void MatrixUDG::DFS() {
	int visited[MAX];
	memset(visited, 0, sizeof(visited));
	cout << "DFS: ";
	for (int i = 0; i < mVexNum; i++) {
		//printf("\n== LOOP(%d)\n", i);
		if (!visited[i])
			DFS(i, visited);
	}
	cout << endl;
}

/*
* 打印矩阵队列图
*/
void MatrixUDG::print() {
	int i, j;
	cout << "Martix Graph:" << endl;
	for (i = 0; i < mVexNum; i++) {
		for (j = 0; j < mVexNum; j++)
			cout << setw(10) << mMatrix[i][j] << " ";
		cout << endl;
	}
}

/**
 * prim最小生成树
 * start -- 从图中的第start个元素开始，生成最小树
 */
void MatrixUDG::prim(int start) {
	int index = 0;         // prim最小树的索引，即prims数组的索引
	char prims[MAX];     // prim最小树的结果数组
	int weights[MAX];    // 顶点间边的权值(点 start~i 的距离)

	// prim最小生成树中第一个数是"图中第start个顶点"，因为是从start开始的。
	prims[index++] = mVexs[start];

	// 初始化"顶点的权值数组"，
	// 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
	for (int i = 0; i < mVexNum; i++)
		weights[i] = mMatrix[start][i];

	// 将第start个顶点的权值初始化为0。
	// 可以理解为"第start个顶点到它自身的距离为0"。
	weights[start] = 0;

	for (int i = 0; i < mVexNum; i++) {
		// 由于从start开始的，因此不需要再对第start个顶点进行处理。
		if (start == i)
			continue;

		int j = 0;
		int k = 0;
		int min = INF;
		// 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
		while (j < mVexNum) {
			// 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
			if (weights[j] != 0 && weights[j] < min) {
				min = weights[j];
				k = j;
			}
			j++;
		}

		// 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。
		// 将第k个顶点加入到最小生成树的结果数组中
		prims[index++] = mVexs[k];
		
		// 将"第k个顶点的权值"标记为0，意味着第k个顶点已经排序过了(或者说已经加入了最小树结果中)。
		weights[k] = 0;

		// 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
		// 假设k个顶点之前，U = {v0}，则w[j]表示的是v0-vj的距离，加入k之后，w中应该保存(v0,vj)和(vk,vj)的较小值
		// 这是为了下次循环中，从w中取出权值最小的那个，然后重复此过程
		for (j = 0; j < mVexNum; j++) {
			// 当第j个节点没有被处理，并且需要更新时才被更新。
			if (weights[j] != 0 && mMatrix[k][j] < weights[j])
				weights[j] = mMatrix[k][j];
		}
	} // 结束最外层循环，此时已经求出 MST

	// 计算最小生成树的权值
	int sum = 0;
	for (int i = 1; i < index; i++) {
		int min = INF;
		// 获取prims[i]在mMatrix中的位置
		int n = getPosition(prims[i]);
		// 在vexs[0...i]中，找出到j的权值最小的顶点。
		for (int j = 0; j < i; j++)
		{
			int m = getPosition(prims[j]);
			if (mMatrix[m][n]<min)
				min = mMatrix[m][n];
		}
		sum += min;
	}
	// 打印最小生成树
	cout << "PRIM(" << mVexs[start] << ")=" << sum << ": ";
	for (int i = 0; i < index; i++)
		cout << prims[i] << " ";
	cout << endl;
}

int main()
{
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int matrix[][9] = {
		/*A*//*B*//*C*//*D*//*E*//*F*//*G*/
		/*A*/{ 0,  12, INF, INF, INF,  16,  14 },
		/*B*/{ 12,   0,  10, INF, INF,   7, INF },
		/*C*/{ INF,  10,   0,   3,   5,   6, INF },
		/*D*/{ INF, INF,   3,   0,   4, INF, INF },
		/*E*/{ INF, INF,   5,   4,   0,   2,   8 },
		/*F*/{ 16,   7,   6, INF,   2,   0,   9 },
		/*G*/{ 14, INF, INF, INF,   8,   9,   0 } };
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	MatrixUDG* pG;

	// 自定义"图"(输入矩阵队列)
	//pG = new MatrixUDG();
	// 采用已有的"图"
	pG = new MatrixUDG(vexs, vlen, matrix);

	//pG->print();   // 打印图
	//pG->DFS();     // 深度优先遍历
	//pG->BFS();     // 广度优先遍历
	pG->prim(0);     // prim算法生成最小生成树

	return 0;
}