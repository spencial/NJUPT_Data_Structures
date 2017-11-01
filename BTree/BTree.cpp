#include"BTree.h"
#include "stdlib.h"
int main() {
	system("color f0");
	BinaryTree<char> a, b, x, y, z, A;
	y.MakeTree('E', a, b);
	z.MakeTree('F', a, b);
	x.MakeTree('C', y, z);
	y.MakeTree('D', a, b);
	z.MakeTree('B', y, x);
	cout << "z�����������";
	z.PreOrder(Visit);
	cout << endl;
	cout << "z�����������";
	z.InOrder(Visit);
	cout << endl;
	cout << "��z���Ƹ�A" << endl;
	A.Copy(z);												//���ƶ�����
	cout << "A�����������";
	A.PreOrder(Visit);
	cout << endl;
	cout << "A�����������";
	A.InOrder(Visit);
	cout << endl;
	cout << "A�Ĳ�α�����";
	A.LevelOrder(Visit);
	cout << endl;
	cout << "A��Ҷ�ӽ����Ϊ" << A.LeafNum() << endl;
	cout << "A�ĸ߶�Ϊ" << A.Height() << endl;
	cout << "����A�������н�����������" << endl;
	A.Exchange();
	cout << "A�����������";
	A.PreOrder(Visit);
	cout << endl;
	cout << "A�����������";
	A.InOrder(Visit);
	cout << endl;
	cout << "A�Ĳ�α�����";
	A.LevelOrder(Visit);
	cout << endl;
	return 0;
}