#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
int random(double start, double end)//��ȡ���������
{
    return (int)(start+(end-start)*rand()/(RAND_MAX+1.0));
}

char getSignala()//��ȡ������������
{
    int a;
    char signal1[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    a = rand()%4;
    return signal1[a];
}
char getSignalb()//��ȡ������������
{
    int b;
    char signal2[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    b = rand()%4;
    return signal2[b];
}
int getResult(int num1,int num2,int num3,char signal1,char signal2)//������㺯��
{
    int i=0,res;
    if(signal1=='+')
    {
        if(signal2=='+')
        {
            res=num1+num2+num3;
        }
        if(signal2=='-')
        {
            res=num1+num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3+num1;
        }
        if(signal2=='/')
        {
            res=num2/num3+num1;
        }
    }
    if(signal1=='-')
    {
        if(signal2=='+')
        {
            res=num1-num2+num3;
        }
        if(signal2=='-')
        {
            res=num1-num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3-num1;
        }
        if(signal2=='/')
        {
            res=num2/num3-num1;
        }
    }
    if(signal1=='*')
    {
        if(signal2=='+')
        {
            res=num1*num2+num3;
        }
        if(signal2=='-')
        {
            res=num1*num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3*num1;
        }
        if(signal2=='/')
        {
            res=num2/num3*num1;
        }
    }
    if(signal1=='/')
    {
        if(signal2=='+')
        {
            res=num1/num2+num3;
        }
        if(signal2=='-')
        {
            res=num1/num2-num3;
        }
        if(signal2=='*')
        {
            res=num2*num3/num1;
        }
        if(signal2=='/')
        {
            res=num2/num3/num1;
        }
    }
    return res;
}

int takeTest()//��Ŀ���ɺ���
{
    int get;
    int num1,num2,num3,a;
    char signal1,signal2;

    srand((unsigned)time(NULL));
    signal1=getSignala();
    srand((unsigned)time(NULL));
    signal2=getSignalb();
    num1=random(1,100);
    num2=random(0,100);
    num3=random(1,100);
if(signal1=='-')
    {
        if(num1<num2)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    if(signal1=='/')
    {
        if(num2==0)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    printf("%d%c%d%c%d=",num1,signal1,num2,signal2,num3);
    scanf("%d",&get);
    fflush(stdin);   //������뻺����
    if(getResult(num1,num2,num3,signal1,signal2)==get)
        {
        printf("�ش���ȷ!\n");
        a=1;
        }
    else
    {
        printf("I�ش����!\n");
        printf("��ȷ����: %d\n",getResult(num1,num2,num3,signal1,signal2));
        a=0;
    }
    return a;
}

int main()
{
         int n,a,right=0,i=0;
         double percent;
         printf("��ѡ��������Ŀ:");
         scanf("%d",&n);
         for(i;i<n;i++)
         {
                   a=takeTest();
                   right=right+a;
         }
         printf("�ش����!\n");
         printf("�ش���ȷ����:%d\n",right);
         percent=((double)right*100.00)/(double)n;
         printf("��ȷ��:%0.2f %%\n",percent);
}

