//#include <stdexcept>		//定义了一组标准异常类
//#include <iostream>
//#include <sstream>
//#include <vector>
//#include <limits>
//
//using namespace std;
//
//template<class T>
//class edge
//{
//public:
//	virtual ~edge() {};
//	virtual int sourceVertex() const = 0;			// 源顶点索引
//	virtual int destinationVertex() const = 0;	    // 目标顶点索引	
//	virtual T getWeight() const = 0;				// 边的权重，如果图是无权重的，这个成员可以不被使用或被设置为默认值
//};
//
//template<class T>
//class weightedEdge :public edge<T>
//{
//public:
//	weightedEdge() {}
//	weightedEdge(int sourcevertex, int destinationvertex, T theweight = T()) :sourcevertex(sourcevertex), destinationvertex(destinationvertex), weight(theweight) {}
//	int sourceVertex() const { return sourcevertex; }
//	int destinationVertex() const { return destinationvertex; }
//	T getWeight() const { return weight; }
//
//private:
//	int sourcevertex;
//	int destinationvertex;
//	T weight;
//};
//
//template<class T>
//class vertexIterator	// 提供遍历与给定顶点相连的所有顶点或边的方法。
//{
//public:
//	virtual ~vertexIterator() {}
//	virtual int next() = 0;
//	virtual int next(T&) = 0;
//};
//
//template<class T>
//class graph
//{
//public:
//	virtual ~graph() {}
//
//	// ADT 方法
//	virtual int numberOfVertices() const = 0;		// 返回图中顶点的数量
//	virtual int numberOfEdges() const = 0;			// 返回图中边的数量
//	virtual bool existsEdge(int, int) const = 0;	// 检查图中是否存在从第一个参数指定的顶点到第二个参数指定的顶点的边
//	virtual void insertEdge(edge<T>*) = 0;			// 向图中插入一条边
//	virtual void eraseEdge(int, int) = 0;			// 从图中删除从第一个参数指定的顶点到第二个参数指定的顶点的边
//	virtual int degree(int) const = 0;				// 返回指定顶点的度（即与该顶点相连的边的数量）
//	virtual int inDegree(int) const = 0;			// 如果图是有向的，返回指定顶点的入度（即指向该顶点的边的数量）
//	virtual int outDegree(int) const = 0;			// 如果图是有向的，返回指定顶点的出度（即从该顶点出发的边的数量）
//
//	// 其他方法
//	virtual bool directed() const = 0;				// 返回一个布尔值，指示图是否是有向的
//	virtual bool weighted() const = 0;				// 返回一个布尔值，指示图是否是加权的（即边是否有权重）
//	virtual vertexIterator<T>* iterator(int) = 0;	// 返回一个指向顶点迭代器的指针，该迭代器可用于遍历与指定顶点相连的所有顶点或边。
//
//};
//template<class T>
//class adjacencyWeightDirectedGraph :public graph<T>			//加权有向图的邻接表（Adjacency List）
//{
//protected:
//	int vertices;								// 顶点个数
//	int edges;									// 边的个数
//	vector<vector<T>> adjacencyList;			// 邻接数组
//	T noEdge;									// 表示不存的边
//
//public:
//	adjacencyWeightDirectedGraph(int numberOfVertices = 0, T theNoEdge = T()) : vertices(numberOfVertices), edges(0), noEdge(theNoEdge)
//	{
//		if (numberOfVertices < 0)
//		{
//			throw invalid_argument("Number of vertices must be >= 0");
//		}
//
//		// resize 函数用于调整容器（如 std::vector）的大小，使其包含指定数量的元素。
//		adjacencyList.resize(numberOfVertices + 1, std::vector<T>(numberOfVertices + 1, noEdge));
//	}
//
//	~adjacencyWeightDirectedGraph() {}	// vector 会自动处理内存释放
//
//	int numberOfVertices() const { return vertices; }
//	int numberOfEdges() const { return edges; }
//	bool directed() const { return true; }
//	bool weighted() const { return true; }
//	bool existsEdge(int i, int j) const
//	{
//		if (i < 1 || j < 1 || i > vertices || j > vertices || adjacencyList[i][j] == noEdge)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//	void insertEdge(edge<T>* theEdge)  // 插入边；如果该边已经存在，则用theEdge->weight() 修改边的权
//	{
//		int v1 = theEdge->sourceVertex();
//		int v2 = theEdge->destinationVertex();
//		if (v1 < 1 || v2 < 1 || v1 > vertices || v2 > vertices || v1 == v2)
//		{
//			ostringstream s;
//			if (v1 < 1 || v2 < 1)
//			{
//				s << "(" << v1 << "," << v2 << ") has a vertex number less than 1";
//			}
//			else if (v1 > vertices || v2 > vertices)
//			{
//				s << "(" << v1 << "," << v2 << ") has a vertex number greater than " << vertices;
//			}
//			else if (v1 == v2)
//			{
//				s << "(" << v1 << "," << v2 << ") is a loop (same source and destination vertex)";
//			}
//			throw invalid_argument(s.str());
//		}
//
//		if (adjacencyList[v1][v2] == noEdge)
//		{
//			edges++;
//		}
//
//		adjacencyList[v1][v2] = theEdge->getWeight();
//	}
//
//	void eraseEdge(int i, int j)	//删除边(i，j)
//	{
//		if (i >= 1 && j >= 1 && i <= vertices && j <= vertices && adjacencyList[i][j] != noEdge)
//		{
//			adjacencyList[i][j] = noEdge;
//			edges--;
//		}
//	}
//
//	void checkVertex(int theVertex) const
//	{
//		if (theVertex < 1 || theVertex > vertices)
//		{
//			ostringstream s;
//			if (theVertex < 1)
//			{
//				s << theVertex << " has a vertex number less than 1";
//			}
//			else if (theVertex > vertices);
//			{
//				s << theVertex << " has a vertex number greater than " << vertices;
//			}
//
//			throw invalid_argument(s.str());
//		}
//	}
//
//	int degree(int theVertex) const
//	{
//		outDegree(theVertex);
//	}
//
//	int outDegree(int theVertex) const
//	{
//		checkVertex(theVertex);
//
//		int sum = 0;
//		for (int j = 1; j <= vertices; j++)
//		{
//			if (adjacencyList[theVertex][j] != noEdge)
//			{
//				sum++;
//			}
//		}
//
//		return sum;
//	}
//
//	int inDegree(int theVertex)const
//	{
//		checkVertex(theVertex);
//
//		int sum = 0;
//		for (int i = 1; i <= vertices; i++)
//		{
//			if (adjacencyList[i][theVertex] != noEdge)
//			{
//				sum++;
//			}
//		}
//
//		return sum;
//	}
//
//	class myIterator :public vertexIterator<T>
//	{
//	protected:
//		vector<vector<T>>& adjList;       // 邻接矩阵的行（实际上，这是邻接表的一个二维表示）
//		T noEdge;                         // 表示不存在的边
//		int vertices;                     // 顶点数
//		int currentVertex = 1;            // 当前顶点索引
//		int currentNeighbor = 1;          // 当前邻居索引（用于遍历当前顶点的所有邻接顶点）
//
//	public:
//		myIterator(vector<vector<T>>& theAdjList, T theNoEdge, int numberOfVertices)
//			: adjList(theAdjList), noEdge(theNoEdge), vertices(numberOfVertices) {}
//
//		~myIterator() {}
//
//		int next()
//		{
//			// 寻找下一个有邻接顶点的顶点
//			while (currentVertex <= vertices)
//			{
//				// 从当前顶点的第一个邻居开始寻找
//				currentNeighbor = 1;
//				while (currentNeighbor <= vertices)
//				{
//					if (adjList[currentVertex][currentNeighbor] != noEdge)
//					{
//						// 找到邻接顶点，移动到下一个顶点并返回当前邻接顶点
//						int nextVertex = currentNeighbor;
//						currentNeighbor++;  // 准备查找下一个可能的邻接顶点
//						currentVertex++;    // 准备查找下一个顶点
//						return nextVertex;
//					}
//					currentNeighbor++;
//				}
//				// 当前顶点没有更多邻接顶点，移动到下一个顶点
//				currentVertex++;
//			}
//
//			// 所有顶点都已遍历完
//			return 0;
//		}
//
//		int next(T& theWeight)
//		{
//			// 寻找下一个有邻接顶点的顶点，并设置边的权重
//			while (currentVertex <= vertices)
//			{
//				currentNeighbor = 1;
//				while (currentNeighbor <= vertices)
//				{
//					if (adjList[currentVertex][currentNeighbor] != noEdge)
//					{
//						int nextVertex = currentNeighbor;
//						theWeight = adjList[currentVertex][nextVertex];
//						currentNeighbor++;  // 准备查找下一个可能的邻接顶点
//						currentVertex++;    // 准备查找下一个顶点
//						return nextVertex;
//					}
//					currentNeighbor++;
//				}
//				currentVertex++;
//			}
//
//			// 所有顶点都已遍历完
//			return 0;
//		}
//
//		myIterator* iterator(int theVertex)		//返回顶点theVertex的迭代器
//		{
//			checkVertex(theVertex);
//			return new myIterator(adjacencyList, noEdge, vertices);
//		}
//	};
//
//};
//
//template<class T>
//class adjacencyWeightGraph : public adjacencyWeightDirectedGraph<T>
//{
//public:
//	adjacencyWGraph(int numberOfVertices = 0, T theNoEdge = 0)
//		: adjacencyWDigraph<T>(numberOfVertices, theNoEdge) {}
//	void insertEdge(edge<T>* theEdge)
//	{
//		int v1 = theEdge->sourceVertex();
//		int v2 = theEdge->destinationVertex();
//		if (v1 < 1 || v2 < 1 || v1 > this->vertices || v2 > this->vertices || v1 == v2)
//		{
//			ostringstream s;
//			if (v1 < 1 || v2 < 1)
//			{
//				s << "(" << v1 << "," << v2 << ") has a vertex number less than 1";
//			}
//			else if (v1 > this->vertices || v2 > this->vertices)
//			{
//				s << "(" << v1 << "," << v2 << ") has a vertex number greater than " << this->vertices;
//			}
//			else if (v1 == v2)
//			{
//				s << "(" << v1 << "," << v2 << ") is a loop (same source and destination vertex)";
//			}
//			throw invalid_argument(s.str());
//		}
//
//		if (this->adjacencyList[v1][v2] == this->noEdge)
//		{
//			this->edges++;
//		}
//
//		this->adjacencyList[v1][v2] = theEdge->getWeight();
//		this->adjacencyList[v2][v1] = theEdge->getWeight();
//	}
//	bool directed() const { return false; }
//
//	void eraseEdge(int i, int j)
//	{
//		if (i >= 1 && j >= 1 && i <= this->vertices && j <= this->vertices && this->adjacencyList[i][j] != this->noEdge)
//		{
//			this->adjacencyList[i][j] = this->noEdge;
//			this->adjacencyList[j][i] = this->noEdge;
//			this->edges--;
//		}
//	}
//
//	int degree(int theVertex) const
//	{
//		this->checkVertex(theVertex);
//		int sum = 0;
//		for (int j = 1; j <= this->vertices; j++)
//		{
//			if (this->adjacencyList[theVertex][j] != this->noEdge)
//			{
//				sum++;
//			}
//		}
//
//		return sum;
//	}
//
//	int outDegree(int theVertex) const
//	{
//		return degree(theVertex);
//	}
//
//	int inDegree(int theVertex) const
//	{
//		return degree(theVertex);
//	}
//};