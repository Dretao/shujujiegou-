#include<iostream>
using namespace std;
struct BstNode {
	int data;
	BstNode* left;//node*����˼��ָ��ڵ��ָ��
	BstNode* right;
};//���еĽڵ㽫��������Ӧ�ó���Ķ�̬�ڴ�������˵����
BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}//ʹ��new�ڶ��ϴ���һ���ڵ㣬Ȼ�󷵻��½ڵ�ĵ�ַ
BstNode* Insert(BstNode* root, int data)//���ڲ���ĺ��������Ǹ��ڵ�ĵ�ַ
{
	if (root == NULL) {//���ǿյ�//�����root����������еľֲ��������Բ���ֱ����
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);//��Ϊ�տ��ǵ�rootleft�ǿ����Իᴥ����һ����֧�����ݴ���rootleft
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
	else if (data <= root->data) return Search(root->left, data);//�ݹ飬����������
	else if (data > root->data) return Search(root->right, data);
}
int main()
{
	BstNode* root;//�洢���ڵ��λ��
	root = NULL;//������Ϊ����
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
