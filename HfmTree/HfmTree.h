#include"Stack.h"
#include"BTree.h" 
#include"Prioqueue.h"
using namespace std;
template <class T>
class HfmTree :public BinaryTree<T>
{
public:
	operator T()const { return weight; }                //��������ת������� 
	T getW() { return weight; }
	void putW(const T& x) { weight = x; }
	void SetNull() { root = NULL; }
	void CreateCode();
	void Decode();      //����
private:
	T weight;
};

template <class T>
HfmTree<T> CreateHfmTree(T w[], int n)
{
	PrioQueue < HfmTree<T> > pq(n);        //����һ��Ԫ������ΪHfmTree<T>������Ȩ����
	HfmTree<T> x, y, z, zero;
	for (int i = 0; i<n; i++) {
		z.MakeTree(w[i], x, y);
		z.putW(w[i]); //��������ֻ��һ�����Ĺ�����������
		pq.Append(z);                      //�������������������Ȩ����
		z.SetNull();                       //��z�óɿ���
	}
	for (int i = 1; i<n; i++) {
		pq.Serve(x);
		pq.Serve(y);           //ȡ����С�ʹ�СȨֵ������������x��y
		z.MakeTree(x.getW() + y.getW(), x, y); //����һ���¹�����������
		z.putW(x.getW() + y.getW());
		pq.Append(z);                      //�¹����������������Ȩ����
		z.SetNull();                       //��z�óɿ���
	}
	pq.Serve(z);                           //�Ӷ�����ȡ��������ϵĹ�����������
	return z;                              //���ع�����ɵĹ�����������
}
template<class T>
void HfmTree<T>::CreateCode()
{
	SeqStack<int> A(Size() + 1);
	BTNode<int>* t = root;
	int n = 1;
	int i = 1;
	while (n <= Size())
	{
		if (t->lChild != NULL)							//�ж������Ƿ�Ϊ��
		{
			A.Push(0);									//0��ջ
			t = t->lChild;
			n++;
		}
		else if (t->rChild != NULL)						//�ж��Һ����Ƿ�Ϊ��
		{
			A.Push(1);									//1��ջ
			t = t->rChild;
			n++;
		}
		else											//���Һ��Ӷ�Ϊ��ΪҶ�ӽ��
		{
			A.Output(codeArray[Findchar(t->element)]); //���Ҷ�ӽ���ӦԪ�صĶ���������
			i++;
			if (i>s.length()) break;
			while (t->parent->rChild == t)				//�ж�Ҷ�ӽ���Ƿ�Ϊ˫�׽����Һ���
			{
				t = t->parent;
				A.Pop();								//ָ��ָ��˫�׽�㣬����Ԫ�س�ջ
			}
			t = t->parent->rChild;						//ָ��ָ��˫�׽����Һ��ӣ�1��ջ
			A.Pop();
			A.Push(1);
			n++;
		}
	}
	for (int j = 0; j < s.length(); j++)
	{
		cout << s[j] << "�ı���Ϊ" << codeArray[j] << endl;
	}
}
template <class T>
void HfmTree<T>::Decode() {
	if (codeArray == NULL) {
		cout << "��δ���룡" << endl;
		return;
	}
	ofstream foutr("D://result.txt");
	if (!foutr)
	{
		cout << "���ܴ� result.txt!" << endl;
		return;
	}
	ifstream foutc("D://codefile.txt");
	if (!foutc)
	{
		cout << "���ܴ� codefile.txt!" << endl;
		return;
	}
	BTNode<T>* searchNode = root;
	char c, ch;
	while (!foutc.eof())
	{
		foutc.get(ch);
		if (ch == '0')
			searchNode = searchNode->lChild;
		else if (ch == '1')
			searchNode = searchNode->rChild;
		if (searchNode->lChild == NULL && searchNode->rChild == NULL)
		{
			c = s[Findchar(searchNode->element)];
			cout << c;
			foutr << c;
			foutr.flush();
			searchNode = root;
		}
	}
	cout << endl << endl;
	foutr.close();
	foutc.close();
}

