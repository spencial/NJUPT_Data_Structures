enum ResultCode { Underflow, Duplicate, Failure, Success, NotPresent, OutOfBounds };
#include<iostream>
#include<string.h>  
#include<stdlib.h>
const int INF = 100000000;
#include"MGraph.h"
using namespace std;
int main()
{
	system("color f0");
	int n, m;
	cout << "��������и���:";
	cin >> n;
	cout << "�����뺽������:";
	cin >> m;
	MGraph<int>A(n, INF);
	int c, f;
	cout << "������ÿ�����ߵ������յ�: " << endl;
	for (int i = 0; i<m; i++)
	{
		cout << "����" << i + 1 << ": ";
		cin >> c >> f;
		while (A.Insert(c, f, 1) == Duplicate)
		{
			cout << "�ظ����ߣ������������������ߣ�";
			cin >> c >> f;
		}
	}
	char s;
	do {
		int v, w;
		cout << "��������������յ�:";
		cin >> v >> w;
		while (v<0 || w<0 || w>n - 1 || v>n - 1||w==v)
		{
			cout << "�������!����������:";
			cin >> v >> w;
		}
		int *b = new int[n];
		int *d = new int[n];
		int *path = new int[n];
		A.Dijkstra(v, d, path);
		int e = n - 1;
		for (int j = 0; j<n; j++)
			b[j] = -2;
		if (w != v)
		{
			int j = w;
			while (path[j] != -1)
			{
				b[e] = path[j];
				e--;
				j = path[j];
			}
			if (e == n - 1 || d[j] == INF)
				cout << "��·������·!" << endl;
			else
			{
				cout << "��" << v << "��" << w << "�Ļ��˴�����С����·����Ϊ:";
				for (int k = 0; k<n; k++)
				{
					if (b[k] != -2)
						cout << b[k] << ",";
				}
				cout << w << endl;
			}
		}
		if (w == v)
			cout << "��" << v << "��" << w << "��·������˷ɻ�!" << endl;
		delete[]b;
		delete[]d;
		delete[]path;
		cout << "�����Ƿ������ѯ·��?������Y/N:";
		cin >> s;
		while (s != 'Y'&&s != 'y'&&s != 'n'&&s != 'N')
		{
			cout << "�������!����������:";
			cin >> s;
		}
	} while (s == 'Y' || s == 'y');
	return 0;
}
