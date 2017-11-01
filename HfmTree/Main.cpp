#include<iostream> 
#include<string> 
#include<sstream>
#include<fstream>
#include"HfmTree.h"
#include "stdlib.h"
using namespace std;
int *weightArray;
string s;
string *codeArray;
HfmTree<int> p;
void Input(HfmTree<int>& p)
{
	cout << "��������Ҫ������ַ���ɵ��ַ���: ";
	cin >> s;
	weightArray = new int[s.length()];
	codeArray = new string[s.length()];
	for (int i = 0; i < s.length(); i++) {
		cout << "�������" << (i + 1) << "���ַ���Ȩֵ��" << endl;
		cin >> weightArray[i];
	}
	p = CreateHfmTree(weightArray, s.length());
}
void Encode() {
	if (codeArray == NULL) {
		cout << "��δ���룡" << endl;
		return;
	}
	string encodeString;
	ofstream foutt("D://textfile.txt");
	if (!foutt)
	{
		cout << "���ܴ� textfile.txt!" << endl;
		return;
	}
	ofstream foutc("D://codefile.txt");
	if (!foutc)
	{
		cout << "���ܴ� codefile.txt!" << endl;
		return;
	}
	cout << "��������Ҫ������ַ���: ";
	cin >> encodeString;
	foutt << encodeString;
	cout << "\n�����������ֵΪ��";
	for (int i = 0; i < encodeString.length(); i++)
		for (int j = 0; j < s.length(); j++)
			if (s[j] == encodeString[i])						//�����ַ�����Ӧ�Ĺ��������벢���
			{
				cout << codeArray[j];
				foutc << codeArray[j];
				break;
			}
	foutt.close();
	foutc.close();
	cout << endl;
}
/*��ӡ�ļ�*/
void Print()
{
	char c;
	ifstream foutt("D://textfile.txt");
	if (!foutt)
	{
		cout << "���ܴ� textfile.txt!" << endl;
		return;
	}
	cout << endl << "----------------------textfile.txt----------------------" << endl;
	while (!foutt.eof())
	{
		foutt >> c;
		cout << c;
		c = ' ';       //��Ϊeof()�������ļ���ȡ����ʱ�����һ��0�������������c�ÿջᵼ���ļ����һ���ַ������һ��
	}
	cout << endl << "--------------------------------------------------------" << endl;
	foutt.close();
	ifstream foutc("D://codefile.txt");
	if (!foutc)
	{
		cout << "���ܴ� codefile.txt!" << endl;
		return;
	}
	cout << endl << "----------------------codefile.txt----------------------" << endl;
	while (!foutc.eof())
	{
		foutc >> c;
		cout << c;
		c = ' ';		 //��Ϊeof()�������ļ���ȡ����ʱ�����һ��0�������������c�ÿջᵼ���ļ����һ���ַ������һ��
	}
	cout << endl << "--------------------------------------------------------" << endl;
	foutc.close();
	ifstream foutr("D://result.txt");
	if (!foutr)
	{
		cout << "���ܴ� result.txt!" << endl;
		return;
	}
	cout << endl << "----------------------result.txt------------------------" << endl;
	while (!foutr.eof())
	{
		foutr >> c;
		cout << c;
		c = ' ';		 //��Ϊeof()�������ļ���ȡ����ʱ�����һ��0�������������c�ÿջᵼ���ļ����һ���ַ������һ��
	}
	cout << endl << "--------------------------------------------------------" << endl;
	foutr.close();
}
int Findchar(int x)			//����Ȩֵ���Ҷ�Ӧ���ַ�
{
	for (int i = 0; i < s.length(); i++)
		if (x == weightArray[i])
			return i;
}
void main()
{
	system("color f0");
	bool flag = true;
	while (flag) {
		cout << "��������������Ӧ���ַ���" << endl;
		cout << "---------------------B��������--------------------------" << endl;
		cout << "---------------------T��������--------------------------" << endl;
		cout << "---------------------E�������ɱ���----------------------" << endl;
		cout << "---------------------C��������--------------------------" << endl;
		cout << "---------------------D��������--------------------------" << endl;
		cout << "---------------------P������ӡ--------------------------" << endl;
		cout << "---------------------X�����˳�--------------------------" << endl;
		char c;
		cin >> c;
		cout << endl;
		switch (c) {
		case 'B':
			Input(p);
			break;
		case 'T':
			if (p != NULL) {
				cout << "ǰ�������";
				p.PreOrder(Visit);
				cout << endl;
				cout << "���������";
				p.InOrder(Visit);
				cout << endl;
			}
			else cout << "��δ������" << endl;
			cout << endl;
			break;
		case 'E':
			p.CreateCode();
			cout << endl;
			break;
		case 'C':
			Encode();
			cout << endl;
			break;
		case 'D':
			p.Decode();
			cout << endl;
			break;
		case 'P':
			Print();
			cout << endl;
			break;
		case 'X':
			flag = false;
			break;
		}
	}
}
