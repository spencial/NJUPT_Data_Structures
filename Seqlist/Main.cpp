#include "seqlist.h"
#include "stdlib.h"
const int SIZE=10;
int  main()
{
	system("color f0");
	SeqList<int> Seq(SIZE);
	for(int i=0;i<10;i++)
		Seq.Insert(i-1,i/3);
	cout<<"����ǰ��˳���:"<<endl;
	Seq.Output(cout);
 	Seq.Reverse(); 
	cout<<"���ú��˳���:"<<endl;
	Seq.Output(cout);
	cout<<"������Ҫɾ������:"<<endl;
	int x;
	cin>>x;
	if(Seq.DeleteX(x)==true)
	{
		cout<<"ɾ����Ľ����"<<endl;
		Seq.Output(cout);
	} 
	else
	cout<<"��ɾ����Ԫ�ز�����"<<endl; 
    return 0;
}

