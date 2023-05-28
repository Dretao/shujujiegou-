#include<iostream>
using namespace std;
struct BstNode {
	int data;
	BstNode* left;//node*的意思是指向节点的指针
	BstNode* right;
};//所有的节点将被创建在应用程序的动态内存区或者说堆区
BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}//使用new在堆上创建一个节点，然后返回新节点的地址
BstNode* Insert(BstNode* root, int data)//用于插入的函数参数是根节点的地址
{
	if (root == NULL) {//树是空的//这里的root是这个函数中的局部变量所以不能直接用
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);//因为刚开是的rootleft是空所以会触发第一个分支将数据存入rootleft
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}
bool Search(BstNode* root, int data)
{
	if (root == NULL) return false;
	if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);//递归，二叉搜索树
	else if (data > root->data) return Search(root->right, data);
}
int main()
{
	BstNode* root;//存储根节点的位置
	root = NULL;//将树设为空树
	root=Insert(root, 15);
	root=Insert(root, 10);
	root=Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int number;
	cout << "Enter number be searched\n";
	cin >> number;
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";
}
