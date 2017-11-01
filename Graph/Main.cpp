enum ResultCode { Underflow, Duplicate, Failure, Success, NotPresent };
#include<iostream>
#include"Seqqueue.h"
#include"MGraph.h"
#include"LGraph.h"
#include<stdlib.h>
using namespace std;
const int INFTY = 2147483640;
int main()      //������  
{
	system("color f0");
	int n, g;
	cout << "������Ԫ�صĸ���: ";
	cin >> n;
	MGraph<int>A(n, INFTY);
	LGraph<int>B(n);
	cout << "������ߵ�����: ";
	cin >> g;
	int *a = new int[g];
	int *b = new int[g];
	int *w = new int[g];
	for (int i = 0; i<g; i++)
	{
		cout << "������߼�Ȩֵ: ";
		cin >> a[i] >> b[i] >> w[i];
		while (A.Insert(a[i], b[i], w[i]) == Duplicate)
		{
			cout << "�Ѵ��ڸñߣ�" << endl << "������߼�Ȩֵ:" ;
			cin >> a[i] >> b[i] >> w[i];
		}
			B.Insert(a[i], b[i], w[i]);
			cout << "����ɹ���"<<endl;
	}
	cout << "��ͼ��������ȱ���Ϊ:" << endl;
	A.DFS();
	cout << endl;
	cout << "��ͼ�Ĺ�����ȱ���Ϊ:" << endl;
	A.BFS();
	cout << endl;
	cout << "������Ҫ�����ı�: ";
	int c, d;
	cin >> c >> d;
	if (A.Exist(c, d))
		cout << "�ڽӾ����иñߴ���!" << endl;
	else
		cout << "�ڽӾ����иñ߲�����!" << endl;
	if (B.Exist(c, d))
		cout << "�ڽӱ��иñߴ���!" << endl;
	else
		cout << "�ڽӱ��иñ߲�����!" << endl;
	cout << "������Ҫɾ���ı�: ";
	int e, f;
	cin >> e >> f;
	if (A.Remove(e, f) == Success)
		cout << "�ڽӾ�����ɾ���ñ߳ɹ�!" << endl;
	else if (A.Remove(e, f) == NotPresent)
		cout << "�ڽӾ����иñ߲�����!" << endl;
	else
		cout << "�������!" << endl;
	if (B.Remove(e, f) == Success)
		cout << "�ڽӱ���ɾ���ñ߳ɹ�!" << endl;
	else if (B.Remove(e, f) == NotPresent)
		cout << "�ڽӱ��иñ߲�����!" << endl;
	else
		cout << "�ڽӱ����������!" << endl;
	cout << "ɾ���ñߺ��ͼ��������ȱ���Ϊ:" << endl;
	A.DFS();
	cout << endl;
	cout << "ɾ���ñߺ��ͼ�Ĺ�����ȱ���Ϊ:" << endl;
	A.BFS();
	cout << endl;
	return 0;
}
