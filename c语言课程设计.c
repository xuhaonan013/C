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
//建立储存结构 
	void BuildStorageSpace(Node *List) {
		Node *p = List->next;
		FILE *fp;
		fp = fopen("C:\\Users\\xuhaonan\\ks.txt","w+");
		if (fp == NULL)
		{
			printf("文件打开出错!");
			exit(0);
		}
		fprintf(fp,"书号\t书名\t作者\t出版社\t数量\t单价\t金额\n");
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
//录入教材征订信息
	void inputInformation(Node *p,int i) 
	{
		printf("请输入第%d本书号：",i+1);
		scanf("%s",p->no); 
		printf("请输入第%d本书名：\n",i+1);
		scanf("%s",p->name); 
		printf("请输入第%d本书作者：\n",i+1);
		scanf("%s",p->author); 
		printf("请输入第%d本书出版商：\n",i+1);
		scanf("%s",p->publisher); 
		printf("请输入第%d本书数量：\n",i+1);
		scanf("%d",&p->number); 
		printf("请输入第%d本单价：\n",i+1);
		scanf("%f",&p->price); 
		printf("请输入第%d本金额：\n",i+1);
		scanf("%f",&p->total); 
	}
	//初始化链表
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
//创建链表
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
// 查找教材信息
 void searchIformation(Node *List) 
 {
 	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("链表为空无法查询！");
		return;
	}
	printf("请输入要查找的书名:");
    scanf("%s",&n);
	printf("\n");
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("未查询到该书");
			
		}
	} 
	printf("%s\n",p->author);
		
 }

 //修改教材的征订数量
void reviseInformation(Node *List)
{
	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("链表为空无修改！");
		return;
    }
    printf("请输入需要修改教材的名称：");
    scanf("%s",n);
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("暂无此书信息！");
			return;
		}
	} 
	printf("请输入修改后的数量");
	scanf("%s",p->number);
	printf("修改成功\n");
 } 
//删除某本教材的相关信息
void deleteInformation(Node *List)
{
	char n[40];
	Node *p=List->next,*q=NULL;
	if(p==NULL)
	{
		printf("链表为空无法删除！");
		return;
	}
	printf("请输入要删除的书名");
    scanf("%s",n);
	for(q=List;(strcmp(n,p->name)!=0)&&p;p=p->next)
		q=p;
	if(p==NULL)
	{
		printf("暂无此书信息！");
		return;
	}
	q->next=p->next;
	free(p);
	printf("删除成功\n");
 } 
 //计算征订总数、金额
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
	 printf("共有%d本书：",sum);
	 printf("总金额为%f元：",total);
  } 
  //排序（冒泡排序法） 
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
 	  		swap(p,pnext);//通过数据的大小比较来交换节点顺序 
			}
			//p和pnext同时向后移动一个节点
			p=p->next;
			pnext=pnext->next; 
		}
		//该次循环结束找到最大值
		end=p;
	}	
	for(Node* p=List->next;p;p = p->next)
	{
		printf("%s:%d本\n",p->name,p->number);
		 }	 
   } 
   //交换函数
   void swap(Node *pre,Node *next)
   {
   	Node *t=0;
   	t=pre;
   	pre=next;
   	next=t;
	} 
  //系统界面
  void systemUI()
  {
  		printf("\t\t              *  欢迎使用教材征订系统  * \n");
	printf("\t\t____________________________________________________\n");
	printf("\n\t\t||\t1.录入教材征订的相关信息\t           ||\n");
	printf("\t\t||\t2.查找某本教材的相关信息\t           ||\n");
	printf("\t\t||\t3.修改某本教材的征订数量\t           ||\n");
	printf("\t\t||\t4.删除某本教材的相关信息	\t   ||\n");
	printf("\t\t||\t5.统计教材的征订总数，计算征订总金额\t   ||\n");
	printf("\t\t||\t6.对每本教材的征订数量进行排名	\t   ||\n");
	printf("\t\t||\t0.退出	\t                           ||\n");
	printf("\t\t___________________________________________________\n");
	printf("\n请输入您想执行的步骤序号\n");

  } 
  void main1()
{
	int z[100][100];
	int a, m, i, j;
	printf("输入起始数a和行数m：\n");
	scanf("%d%d", &a, &m);
	z[0][0] = a++;
	for (j = 1; j < m; ++j)//J列 
	{
		for (i = 0; i < j; ++i)//i递增 
			z[i][j] = a++;
		for (i = j; i >= 0; --i)//i==j时转折 ，j递减 
			z[j][i] = a++;
	}
	printf("层叠方阵：\n");
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < m; ++j)
			printf("%3d ", z[i][j]);
		printf("\n");
	}
}

 void fun5(int x, int y)
{
	if (x < 0 && y < 0)//如果是负数则取相反数
	{
		x = -x;
		y = -y;
	}
	int i;
	for (i = 2; i < y || i < x; ++i)
	{
		if (x % i == 0 && y % i == 0)//循环寻找分子分母的公约数
		{
			x /= i;
			y /= i;
			-i;
		}
	}
	printf("%d/%d\n", x, y);
}
void fun1(int a1, int b1, int a2, int b2)//计算两分数相加调用fun5（）化简
{
	int x, y;
	y = b1 * b2;                         //分母计算
	x = a1 * b2 + a2 * b1;               //分子计算
	printf("%d/%d + %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);//化简
}
void fun2(int a1, int b1, int a2, int b2)//计算两分数相减调用fun5（）化简
{
	int x, y;
	y = b1 * b2;
	x = a1 * b2 - a2 * b1;
	printf("%d/%d - %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);
}
void fun3(int a1, int b1, int a2, int b2)//计算两分数相乘调用fun5（）化简
{
	int x, y;
	y = b1 * b2;//分母计算
	x = a1 * a2; //分子计算
	printf("%d/%d * %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);//化简
}
void fun4(int a1, int b1, int a2, int b2) //计算两分数相除调用fun5（）化简
{
	int x, y;
	y = b1 * a2;//分母计算
	x = a1 * b2;//分子计算
	printf("%d/%d / %d/%d = ", a1, b1, a2, b2);
	fun5(x, y);//化简
}
void main2()
{
	int a1, a2, b1, b2;
	printf("输入两个分数的分子和分母，用空格分开，例：2/4 3/4,输入2 4 3 4\n");
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);//输入两个分数
	fun1(a1, b1, a2, b2);//两分数相加
	fun2(a1, b1, a2, b2);//两分数相减
	fun3(a1, b1, a2, b2);//两分数相乘
	fun4(a1, b1, a2, b2);//两分数相除
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
	 	printf("根据提示输入数字:\n");
	 	scanf("%d",&s);
		 switch(s)
		 {
		 	case 1:printf("需要录入书本数");
			 scanf("%d",&n);
			 List = creaList(List,n);
			 printf("\n");
			 getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break;
			 case 2: 
			 searchIformation(List);
			  printf("\n");
			  getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break;
			  case 3:reviseInformation(List);
			 printf("\n");
			 getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break;
			 case 4:deleteInformation(List);
			 printf("\n");
			 getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break;
			 case 5: caculateInformation(List);
			  printf("\n");
			  getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break; 
			 case 6: sortNumber(List);;
			  printf("\n");
			  getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break; 
			     default:printf("输入有误\n");
			     printf("\n");
			     getchar();
			 printf("输入任意键返回");
			 getchar();
			 system("cls");break;
			 case 0:exit(0);
		  } 
	  } 

 }
void main()
{
	int s; 
	printf("请输入需要实现的题目的题号:\n");
		printf("1.层叠方阵\n");
	printf("2.分数计算\n");
	printf("3.教材征订管理系统\n");
		printf("0.退出\n");
		while(1)
		{
			scanf("%d",&s);
			switch(s)
			{
				case 1:main1();break; 
				case 2:main2();break;
				case 3:main3(); break;
				default:printf("输入有误\n");
				 case 0:exit(0);
			} 
		} 

 } 

