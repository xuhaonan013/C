#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
	{
		char no[12];
		char name[40];
		char author[40];
		char publisher[40];
		int number;
		float price;
		float total;
		struct node* next;
	}Node;
void caculateInformation(Node *List);
void deleteInformation(Node *List);
void reviseInformation(Node *List);
void searchIformation(Node *List);
Node *creaList(Node *List,int n);
Node *resetList(Node *List);
void inputInformation(Node *p,int i);
void BuildStorageSpace(Node *List);
Node *resetList(Node *List) ;
void sortNumber(Node *List);
Node *resetList(Node *List) ;
void main1();
void main2();
void main3();
//��������ṹ 
	void BuildStorageSpace(Node *List) {
		Node *p = List->next;
		FILE *fp;
		fp = fopen("C:\\Users\\xuhaonan\\ks.txt","w+");
		if (fp == NULL)
		{
			printf("�ļ��򿪳���!");
			exit(0);
		}
		fprintf(fp,"���\t����\t����\t������\t����\t����\t���\n");
		while(p==NULL) {
			fprintf(fp,"%s\t",p->no);
			fprintf(fp,"%s\t",p->name);
			fprintf(fp,"%s\t",p->author);
			fprintf(fp,"%s\t",p->publisher);
			fprintf(fp,"%d\t",p->number);
			fprintf(fp,"%f\t",p->price);
			fprintf(fp,"%f\t",p->total);
			fprintf(fp,"\n");
			p=p->next;
			fclose(fp);
		}
	}
//¼��̲�������Ϣ
	void inputInformation(Node *p,int i) 
	{
		printf("�������%d����ţ�",i+1);
		scanf("%s",p->no); 
		printf("�������%d��������\n",i+1);
		scanf("%s",p->name); 
		printf("�������%d�������ߣ�\n",i+1);
		scanf("%s",p->author); 
		printf("�������%d��������̣�\n",i+1);
		scanf("%s",p->publisher); 
		printf("�������%d����������\n",i+1);
		scanf("%d",&p->number); 
		printf("�������%d�����ۣ�\n",i+1);
		scanf("%f",&p->price); 
		printf("�������%d����\n",i+1);
		scanf("%f",&p->total); 
	}
	//��ʼ������
	Node *resetList(Node *List) 
	{
		Node *head = NULL;
		head=(Node*)malloc(sizeof(Node));
		if(!head)
		  return 0;
		head->next=NULL;
		List = head;
	    return List;
	}
//��������
Node *creaList(Node *List,int n)
{
	int i;
	Node *p = NULL;
	for(i=0;i<n;i++)
	{
		p=(Node*)malloc(sizeof(Node));
		inputInformation(p,i);
		p->next=List->next;
		List->next=p;
	}
	return List;
 } 
// ���ҽ̲���Ϣ
 void searchIformation(Node *List) 
 {
 	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("����Ϊ���޷���ѯ��");
		return;
	}
	printf("������Ҫ���ҵ�����:");
    scanf("%s",&n);
	printf("\n");
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("δ��ѯ������");
			
		}
	} 
	printf("%s\n",p->author);
		
 }

 //�޸Ľ̲ĵ���������
void reviseInformation(Node *List)
{
	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("����Ϊ�����޸ģ�");
		return;
    }
    printf("��������Ҫ�޸Ľ̲ĵ����ƣ�");
    scanf("%s",n);
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("���޴�����Ϣ��");
			return;
		}
	} 
	printf("�������޸ĺ������");
	scanf("%s",p->number);
	printf("�޸ĳɹ�\n");
 } 
//ɾ��ĳ���̲ĵ������Ϣ
void deleteInformation(Node *List)
{
	char n[40];
	Node *p=List->next,*q=NULL;
	if(p==NULL)
	{
		printf("����Ϊ���޷�ɾ����");
		return;
	}
	printf("������Ҫɾ��������");
    scanf("%s",n);
	for(q=List;(strcmp(n,p->name)!=0)&&p;p=p->next)
		q=p;
	if(p==NULL)
	{
		printf("���޴�����Ϣ��");
		return;
	}
	q->next=p->next;
	free(p);
	printf("ɾ���ɹ�\n");
 } 
 //�����������������
 void caculateInformation(Node *List)
 {
 	Node *p;
 	int sum = 0;
 	float total = 0; 
 	p=List->next;
 	while(p!=NULL)
 	{
 		sum+=p->number;
 		total+=(p->number)*(p->price);
 		p=p->next;
 		
	 }
	 printf("����%d���飺",sum);
	 printf("�ܽ��Ϊ%fԪ��",total);
  } 
  //����ð�����򷨣� 
  void sortNumber(Node *List)
  {
  	Node *head;
  	head = List->next;
  	if(head==NULL)
  	  return NULL;
  	  Node *end=NULL;
  	  while(end!=head)
  	  {
  	  	Node *p=head;
  	  	Node*pnext=p->next;
  	  	while(pnext!=end && pnext)
  	  	{
  	  		if(p->number<pnext->number)
				{ 
 	  		swap(p,pnext);//ͨ�����ݵĴ�С�Ƚ��������ڵ�˳�� 
			}
			//p��pnextͬʱ����ƶ�һ���ڵ�
			p=p->next;
			pnext=pnext->next; 
		}
		//�ô�ѭ�������ҵ����ֵ
		end=p;
	}	
	for(Node* p=List->next;p;p = p->next)
	{
		printf("%s:%d��\n",p->name,p->number);
		 }	 
   } 
   //��������
   void swap(Node *pre,Node *next)
   {
   	Node *t=0;
   	t=pre;
   	pre=next;
   	next=t;
	} 
  //ϵͳ����
  void systemUI()
  {
  		printf("\t\t              *  ��ӭʹ�ý̲�����ϵͳ  * \n");
	printf("\t\t____________________________________________________\n");
	printf("\n\t\t||\t1.¼��̲������������Ϣ\t           ||\n");
	printf("\t\t||\t2.����ĳ���̲ĵ������Ϣ\t           ||\n");
	printf("\t\t||\t3.�޸�ĳ���̲ĵ���������\t           ||\n");
	printf("\t\t||\t4.ɾ��ĳ���̲ĵ������Ϣ	\t   ||\n");
	printf("\t\t||\t5.ͳ�ƽ̲ĵ��������������������ܽ��\t   ||\n");
	printf("\t\t||\t6.��ÿ���̲ĵ�����������������	\t   ||\n");
	printf("\t\t||\t0.�˳�	\t                           ||\n");
	printf("\t\t___________________________________________________\n");
	printf("\n����������ִ�еĲ������\n");

  } 
  void main1()
{
	int z[100][100];
	int a, m, i, j;
	printf("������ʼ��a������m��\n");
	scanf("%d%d", &a, &m);
	z[0][0] = a++;
	for (j = 1; j < m; ++j)//J�� 
	{
		for (i = 0; i < j; ++i)//i���� 
			z[i][j] = a++;
		for (i = j; i >= 0; --i)//i==jʱת�� ��j�ݼ� 
			z[j][i] = a++;
	}
	printf("�������\n");
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < m; ++j)
			printf("%3d ", z[i][j]);
		printf("\n");
	}
}

 void fun5(int x, int y)
{
	if (x < 0 && y < 0)//����Ǹ�����ȡ�෴��
	{
		x = -x;
		y = -y;
	}
	int i;
	for (i = 2; i < y || i < x; ++i)
	{
		if (x % i == 0 && y % i == 0)//ѭ��Ѱ�ҷ��ӷ�ĸ�Ĺ�Լ��
		{
			x /= i;
			y /= i;
			-i;
		}
	}
	printf("%d/%d\n", x, y);
}
void fun1(int a1, int b1, int a2, int b2)//������������ӵ���fun5��������
{
	int x, y;
	y = b1 * b2;                         //��ĸ����
	x = a1 * b2 + a2 * b1;               //���Ӽ���
	printf("%d/%d + %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);//����
}
void fun2(int a1, int b1, int a2, int b2)//�����������������fun5��������
{
	int x, y;
	y = b1 * b2;
	x = a1 * b2 - a2 * b1;
	printf("%d/%d - %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);
}
void fun3(int a1, int b1, int a2, int b2)//������������˵���fun5��������
{
	int x, y;
	y = b1 * b2;//��ĸ����
	x = a1 * a2; //���Ӽ���
	printf("%d/%d * %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);//����
}
void fun4(int a1, int b1, int a2, int b2) //�����������������fun5��������
{
	int x, y;
	y = b1 * a2;//��ĸ����
	x = a1 * b2;//���Ӽ���
	printf("%d/%d / %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);//����
}
void main2()
{
	int a1, a2, b1, b2;
	printf("�������������ķ��Ӻͷ�ĸ���ÿո�ֿ�������2/4 3/4,����2 4 3 4\n");
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);//������������
	fun1(a1, b1, a2, b2);//���������
	fun2(a1, b1, a2, b2);//���������
	fun3(a1, b1, a2, b2);//���������
	fun4(a1, b1, a2, b2);//���������
}
 void main3()
 {
 	int n,s;
 	char c;
 	Node *List = NULL;
 	List=resetList(List);
 	while(1)
	 {
	 	systemUI();
	 	printf("������ʾ��������:\n");
	 	scanf("%d",&s);
		 switch(s)
		 {
		 	case 1:printf("��Ҫ¼���鱾��");
			 scanf("%d",&n);
			 List = creaList(List,n);
			 printf("\n");
			 getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break;
			 case 2: 
			 searchIformation(List);
			  printf("\n");
			  getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break;
			  case 3:reviseInformation(List);
			 printf("\n");
			 getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break;
			 case 4:deleteInformation(List);
			 printf("\n");
			 getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break;
			 case 5: caculateInformation(List);
			  printf("\n");
			  getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break; 
			 case 6: sortNumber(List);;
			  printf("\n");
			  getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break; 
			     default:printf("��������\n");
			     printf("\n");
			     getchar();
			 printf("�������������");
			 getchar();
			 system("cls");break;
			 case 0:exit(0);
		  } 
	  } 

 }
void main()
{
	int s; 
	printf("��������Ҫʵ�ֵ���Ŀ�����:\n");
		printf("1.�������\n");
	printf("2.��������\n");
	printf("3.�̲���������ϵͳ\n");
		printf("0.�˳�\n");
		while(1)
		{
			scanf("%d",&s);
			switch(s)
			{
				case 1:main1();break; 
				case 2:main2();break;
				case 3:main3(); break;
				default:printf("��������\n");
				 case 0:exit(0);
			} 
		} 

 } 

