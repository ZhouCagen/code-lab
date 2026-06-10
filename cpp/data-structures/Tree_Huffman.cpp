//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <iomanip>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct HuffmanTreeNode
//{
//	int weight;
//	HuffmanTreeNode* leftChild, * rightChild;
//
//	HuffmanTreeNode(int w) :weight(w), leftChild(nullptr), rightChild(nullptr) {}
//};
//
//void throwError(const string& message) 
//{
//	throw runtime_error(message);
//}
//
//HuffmanTreeNode* findSecondMinNode(vector <HuffmanTreeNode*>forest, HuffmanTreeNode* exclude)//exclude 排除
//{
//	HuffmanTreeNode* secondMin = nullptr;
//	for (HuffmanTreeNode* node : forest)
//	{
//		if (node != exclude && (secondMin == nullptr || node->weight < secondMin->weight))
//		{
//			secondMin = node;
//		}
//	}
//	if (secondMin == nullptr)
//	{
//		throwError("Error: secondMinNode is nullptr");
//	}
//	return secondMin;
//}
//
//HuffmanTreeNode* createHuffmanTree(const vector<int>& weights)
//{
//	vector<HuffmanTreeNode* > forest;
//	forest.reserve(weights.size());
//	/*
//		reserve ：reservr是 vector 的一个成员函数，用于请求改变容器的容量（capacity）。
//		容量是容器在不分配新内存的情况下可以包含的元素数量。调用 reserve(n) 会请求容器至少能够容纳 n 个元素。
//		如果当前的容量小于 n，则可能会分配新的内存块来存储元素，并可能移动现有元素到新的内存位置（尽管这通常不会发生，除非当前的内存块不足以容纳新的容量）。
//		如果当前的容量已经大于或等于 n，则 reserve 调用不会改变容器，也不会分配新的内存。
//		使用 reserve 的主要目的是减少因动态内存分配而导致的性能开销，特别是在你预先知道将要向容器中添加大量元素时。
//	*/
//
//	for (int weight : weights)
//	{
//		HuffmanTreeNode* temp = new HuffmanTreeNode(weight);
//		forest.push_back(temp);
//	}
//
//	while (forest.size() > 1)
//	{
//		/*
//			lambda表达式为程序员提供了一种定义匿名函数对象（也称为闭包）的便捷方式。
//			[capture](parameters) mutable -> return_type
//			{
//				 函数体
//			}
//			capture：捕获列表，明确了lambda表达式外部哪些变量（按值或引用）能够在lambda函数体内被访问。
//			parameters：参数列表，定义了lambda表达式的输入参数，类似于普通函数的参数列表。
//			mutable：一个可选的关键字，当被指定时，它允许在lambda函数体内修改按值捕获的变量。
//			return_type：返回类型，能够明确指定lambda表达式的返回类型。但在很多情况下，编译器能够自动推断出返回类型，因此这个部分是可选的。
//			函数体：包含了lambda表达式的具体实现逻辑。
//			eg：auto add = [](int a, int b) { return a + b; };
//
//			min_element是一个算法函数，用于在指定范围内查找具有最小值的元素。这个函数定义在<algorithm>头文件中。
//			eg：auto minIt = std::min_element(numbers.begin(), numbers.end());
//			min_element还接受一个可选的比较函数或函数对象作为第三个参数，允许用户自定义元素之间的比较方式。
//			eg：auto minIt = std::min_element(vec.begin(), vec.end(),
//					[](const MyStruct& a, const MyStruct& b) {
//						 return a.value < b.value;
//					});
//		*/
// 
//		auto min1 = min_element(forest.begin(), forest.end(), 
//			[](HuffmanTreeNode* a, HuffmanTreeNode* b) {return a->weight < b->weight; });
//
//		/* 由于min_element返回的是一个迭代器，因此你需要通过解引用这个迭代器来访问实际的对象（在这个例子中是Htree类型的节点）： */
//		HuffmanTreeNode* minNode = *min1;
//		forest.erase(min1);
//
//		HuffmanTreeNode* secondMinNode = findSecondMinNode(forest, minNode);
//		if (secondMinNode != nullptr)
//		{
//			auto it = find(forest.begin(), forest.end(), secondMinNode);
//			/* end() 方法通常返回一个迭代器，指向容器末尾元素的“下一个位置”，这个位置并不包含任何有效的元素。*/
//			if (it != forest.end()) // 判断是否forest中存在secondMinNode
//			{
//				forest.erase(it);
//			}
//			HuffmanTreeNode* newNode = new HuffmanTreeNode(minNode->weight + secondMinNode->weight);
//			newNode->leftChild = minNode;
//			newNode->rightChild = secondMinNode;
//
//			if (forest.empty()) 
//			{
//				return newNode; // Return the new root if forest is empty
//			}
//
//			forest.push_back(newNode); // Add the new node back to the forest for the next iteration
//
//		}
//		else
//		{
//			cerr << "Error: secondMinNode is nullptr" << endl;
//			exit(EXIT_FAILURE);
//		}
//
//	}
//	// If forest size is 1, return the last remaining node
//	return forest.front();
//}
//
//int getWPL(HuffmanTreeNode* root, int len)
//{
//	if (root == nullptr)
//	{
//		return 0;
//	}
//	else
//	{
//		if (root->leftChild == nullptr && root->rightChild == nullptr) // 叶子节点
//		{
//			return root->weight * len;
//		}
//		else
//		{
//			int leftWPL = getWPL(root->leftChild, len + 1);
//			int rightWPL = getWPL(root->rightChild, len + 1);
//			return leftWPL + rightWPL;
//		}
//	}
//}
//
//int directlyGetWPL(const vector<int>& weights)
//{
//	/* priority_queue 是 C++ 标准模板库（STL）中的一个容器适配器，它提供了队列的功能，但是其中的元素是根据优先级进行排序的，而不是按照它们被加入队列的顺序。 */
//	priority_queue<int, vector<int>, greater<int>>huffman;
//	for (int i = 0; i < weights.size(); i++)
//	{
//		huffman.push(weights[i]);
//	}
//
//	int res = 0;
//
//	for (int i = 0; i < weights.size() - 1; i++)
//	{
//		int x = huffman.top();
//		huffman.pop();
//
//		int y = huffman.top();
//		huffman.pop();
//
//		int temp = x + y;
//		res += temp;
//		huffman.push(temp);
//	}
//
//	return res;
//}
//
//void getHuffmanCoding(HuffmanTreeNode* root, string path, vector<pair<int, string>>& codingVector, const vector<int>& weights)
//{
//	if (root == nullptr)
//	{
//		return;
//	}
//	if (root->leftChild == nullptr && root->rightChild == nullptr)
//	{
//		int index = static_cast<int>(find(weights.begin(), weights.end(), root->weight) - weights.begin());
//		codingVector.emplace_back(index, path);
//	}
//	else
//	{
//		getHuffmanCoding(root->leftChild, path + "0", codingVector, weights);
//		getHuffmanCoding(root->rightChild, path + "1", codingVector, weights);
//	}
//}
//
//
//void freeHuffmanTree(HuffmanTreeNode* root)
//{
//	if (root != nullptr)
//	{
//		freeHuffmanTree(root->leftChild);
//		freeHuffmanTree(root->rightChild);
//
//		delete root;
//	}
//}
//
//int main()
//{
//	vector<int> weights = { 5, 9, 12, 13, 16, 45 }; // 示例权重
//
//	int directWPL = directlyGetWPL(weights);
//	cout << "Direct Weighted Path Length (WPL):" << directWPL << endl << endl;
//
//	HuffmanTreeNode* root = createHuffmanTree(weights);
//
//	 //计算 WPL
//	int wpl = getWPL(root, 0);
//	cout << "Weighted Path Length (WPL): " << wpl << endl << endl;
//
//	vector<pair<int, string>>codingVector;
//
//	getHuffmanCoding(root, "", codingVector, weights);
//
//	for (const auto& pair : codingVector)
//	{
//		cout << "index of weights：" << pair.first << setw(4) << "" << "weights：" << setw(4) << weights[pair.first] << setw(4) << "" << "Huffman code：" << pair.second << endl;
//	}
//
//	 //释放霍夫曼树的内存
//	freeHuffmanTree(root);
//
//	return 0;
//}
//
