#include<iostream.h> 
class Term
{  
public:
     Term(int c,int e);
     Term(int c,int e,Term* nxt);
     Term* InsertAfter(int c,int e);            //��thisָ��ָʾ�Ľ�������½��
 private:
     int coef;
     int exp;
     Term *link;
	  friend ostream & operator<<(ostream &,const Term &); //����"<<"���������ʽ��һ��
     friend class Polynominal;
};    
class Polynominal
{
public:
	Polynominal();
	~Polynominal();
	void AddTerms(istream& in);
	void OutPut(ostream& out) const;
	void PolyAdd(Polynominal& r);
	void PolyMul(Polynominal& r);
private:
	Term* theList;
	friend ostream& operator<<(ostream& out,const Polynominal& r);
	friend istream& operator>>(istream& in,Polynominal& r);
	friend Polynominal& operator+(Polynominal& a,Polynominal& b);
	friend Polynominal& operator*(Polynominal& a,Polynominal& b);
};
Term::Term(int c,int e):coef(c),exp(e)
{
link=0;
}
Term::Term(int c,int e,Term *nxt):coef(c),exp(e)
{
link=nxt;
}
Term* Term::InsertAfter(int c,int e)
{	                                     //Ϊ����������Ĵ洢��Ԫ������Term������
link=new Term(c,e,link);              //c,e��this->link��ֵ�����½�����Ӧ�� 
return link;
}
ostream &operator <<(ostream & out, const Term& val)   
{ //����"<<"���������ʽ��һ���coef X^exp��ʾcoef Xexp
      if(val.coef==0) return out;  
	   out<<val.coef;
      switch(val.exp){  
case 0:break;
          case 1:out<<"X"; break;
          default:out<<"X^"<<val.exp; break;
	   }
	   return out;
}


Polynominal::Polynominal()                           //��������ʽ�Ŀյĵ�ѭ������
{  
	theList=new Term(0,-1);	                     //�����ͷ���Ĵ洢��Ԫ
	theList->link=theList;                           //����ѭ������
}
Polynominal::~Polynominal()                           //��������ʽ�ĵ�ѭ������
{
	Term* p=theList->link;
	while(p!=theList){
	theList->link=p->link;                        //ɾ��p���
 	 delete p;                                     //�ͷ�p֮�洢�ռ�
 	 p=theList->link;                              //pָ����1����ɾ�����
	}
	delete theList;                                    //�ͷű�ͷ���Ĵ洢��Ԫ
}

void Polynominal:: AddTerms(istream & in)         //���������������쵥ѭ������
{
  Term* q=theList;
  int c,e;
  for(;;){ 	  
	   cout<<"Input a term(coef,exp):\n"<<endl;
      cin>>c>>e;
	     if (e<0) break;                          //�������ָ��С��0ʱ��������̽���
      q=q->InsertAfter(c,e);                   //��c,e�����β���q֮��
  }
}
void Polynominal:: OutPut(ostream& out)const
{
   int first=1;  Term *p=theList->link;
   cout<<"The polynominal is:\n"<<endl;
   for ( ; p!=theList ; p=p->link){
      if (!first && (p->coef>0)) out<<"+";      //�ڷǵ�һ�����ϵ��ǰ���+��
first=0;                                       
      out<<*p;                                  //����Term�������ص�"<<"����
   }
   cout<<"\n"<<endl;
}

void Polynominal::PolyAdd(Polynominal& r)     
{											//������ʽr�ӵ�����ʽthis��
     Term* q,*q1=theList,*p;                 //q1ָ���ͷ���
	p=r.theList->link;                       //pָ���һ��Ҫ����Ľ��
     q=q1->link;                           //q1��q��ǰ����p��q��ָ��������ǰ���бȽϵ���
     while (p->exp>=0){                       //��r�ĵ�ѭ���������,ֱ��ȫ����㶼������  
        while (p->exp<q->exp){                //����q->exp�����
         q1=q;  q=q->link;	           
}
	   if (p->exp==q->exp) {                    //��ָ�����ʱ��ϵ�����
		  q->coef=q->coef+p->coef;
		  if (q->coef==0){                   //����Ӻ�ϵ��Ϊ0����ɾ��q
                q1->link=q->link; delete(q);
                q=q1->link;                    //����qָ��
		  }
		  else {
			   q1=q; q=q->link;             //����Ӻ�ϵ����Ϊ0�����ƶ�q1��q
		  }
	   }
	   else{                                   //p->exp>q->exp����� 
          q1=q1->InsertAfter(p->coef,p->exp);   //��p��ϵ����ָ�������½�㣬����q1
        }
        p=p->link;
    }
}

void Polynominal::PolyMul(Polynominal& r)
{											//������ʽr�����ʽthis��� 
	Polynominal result;						//����result�Ķ���ʽ�����ڴ洢��˺�Ľ�� 
	Term *p=theList,*q;						//pָ���ͷ�ڵ� 
    p=p->link;								//pָ��this�ĵ�һ���ڵ� 
    for(;p->exp>=0;p=p->link)				//��pָ���this���б���	
    {
        q=r.theList;						//qָ�����˵�r����ʽ�ı�ͷ�ڵ� 
        q=q->link;							//qָ��r�ĵ�һ���ڵ� 
        Polynominal temp;					//����temp����ʽ�����ڴ����м����ʽ 
        Term* t=temp.theList;
        for(;q->exp>=0;q=q->link)			//��r����ʽ���б��� 
        {
            t=t->InsertAfter(p->coef*q->coef,p->exp+q->exp);//��r��this��ĳһ����˴���temp 
        }
        result.PolyAdd(temp);				//��temp�ӵ�result�������ʽ�� 
    }
    cout<<result;							//��ӡ�������ʽ 
}
ostream& operator<<(ostream &out,const Polynominal &r)
{
	r.OutPut(out);
	return out;
}

istream& operator>>(istream &in,Polynominal &r)
{
	r.AddTerms(in);
	return in;
}

Polynominal& operator+(Polynominal &a,Polynominal &b)
{
	a.PolyAdd(b);
	return a;
}

Polynominal& operator*(Polynominal &a,Polynominal &b)
{
	a.PolyMul(b);
	return a;
}
