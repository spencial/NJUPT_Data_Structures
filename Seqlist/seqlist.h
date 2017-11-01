#include "linearlist.h"
using namespace std;
template <class T>
class SeqList:public LinearList<T>
{ 
	public:
    SeqList(int mSize);
    ~SeqList() { delete [] elements; }
    bool IsEmpty() const;
    int Length() const;
    bool Find(int i,T& x) const;
    int Search(T x) const;
    bool Insert(int i,T x);
    bool Delete(int i);
    bool Update(int i,T x);
    void Output(ostream& out)const;
	void Reverse();
	bool DeleteX(const T& x); 
	int n;
  private:
    int maxLength;  	//˳������󳤶�
    T *elements;   	 //��̬һά�����ָ��
};

template <class T>
SeqList<T>::SeqList(int mSize)
{ 
    maxLength=mSize;
    elements=new T[maxLength];                            //��̬����˳���Ĵ洢�ռ�
    n=0;
}
template <class T>
bool SeqList<T>::IsEmpty() const
{ 
return n==0;
}
template <class T>
int SeqList<T>::Length() const
{ 
return n;
}
template<class T>
bool SeqList<T>::Find(int i,T& x) const
{ 
if (i<0 || i>n-1){                               //��i����Խ����
		   cout<<"Out of Bounds"<<endl; return false;
    }
    x=elements[i];                                     //ͨ�����ò���x�����±�Ϊi��Ԫ��
    return true;
}
template<class T>
int SeqList<T>::Search(T x) const
{ 
	     for(int j=0;j<n;j++)
         if (elements[j]==x) return j;                 //��ͷ��ʼ����ֵΪx��Ԫ��
   return -1;
}
template<class T>
bool SeqList<T>::Insert(int i,T x)
{  
if (i<-1 || i>n-1) { 
		    cout<<"Out Of Bounds"<<endl; return false;
     }
     if (n== maxLength){                                 //��������
		    cout<<"OverFlow"<<endl; return false;
     }
     for (int j=n-1;j>i;j--) elements[j+1]=elements[j];  //�Ӻ���ǰ�������Ԫ��
	     elements[i+1]=x;                                 //��x�����±�Ϊi��Ԫ�غ���
     n++; return true;
}
template <class T>
bool SeqList<T>::Delete(int i)
{ 
    if (!n) {                                            //��������
		    cout<<"UnderFlow"<<endl; return false;
    }
    if (i<0 || i>n-1) {	
		    cout<<"Out Of Bounds"<<endl; return false;
    }
    for (int j=i+1;j<n;j++) elements[j-1]=elements[j];    //��ǰ�������ǰ��Ԫ��
    n--; return true;
}
template <class T>
bool SeqList<T>::Update(int i,T x)
{ 
    if (i<0 || i>n-1) { 
        cout<<"Out Of Bounds"<<endl; return false;
    }
    elements[i]=x;                                        //���±�Ϊi��Ԫ��ֵ�޸�Ϊx
    return true;
}
template <class T>
void SeqList<T>::Output(ostream& out)const
{
    for (int i=0; i<n; i++) out<<elements[i]<<" ";
	    out<<endl;
}

template<class T>
void SeqList<T>::Reverse()
{
	T e;			//��������e�����ڴ����ʱ����
	for (int i=1;i<=n/2;i++)    //������±�Ϊ�㵽�±꡾n/2������
		{
		e=elements[i-1];
		elements[i-1]=elements[n-i];
		elements[n-i]=e;	//������ʱ����e����±�Ϊi-1��n-iԪ�صĻ���
	}
}

template<class T>
bool SeqList<T>::DeleteX(const T& x)
{
	bool flag=false; 		//����bool��Ԫ�����ڼ�¼�Ƿ�ɾ��Ԫ��x�ɹ�
	for(int i=0;i<n;i++)
	{                           //��������
		if(x==elements[i])
		{         //�������ĳһ��Ԫ��ֵ�뺯�����������ֵ��ȣ���ɾ��Ԫ��
			Delete(i);
			flag=true;
			i--;                  //����©������ʱ�临�Ӷ�ΪO(n)
		}
	}
	return flag;
}
