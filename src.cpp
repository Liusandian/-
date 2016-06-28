#define _CRT_SECURE_NO_WARNING
#include<string>
#include<iostream>
#include<malloc.h>
using namespace std;

int main()
{
	unsigned int Continumax(char** pOutputstr,  char* intputstr);
	char *str;
    char **p = new char *[128];
	str=(char *)malloc(128);
	cin.get(str,128,'\n');
	p[0]="";
    int n=Continumax(p,str);
	if(p[0]!="")
		cout<<*p<<','<<n<<endl;
	else cout<<0<<endl;
	return 0;
}

unsigned int Continumax(char** pOutputstr,  char* intputstr)
{
////////////////////求字符串内连续最长的数字个数
	char *p1=intputstr,*p2,temp[128]={0};
    p2=new char[128];
    for(int j=0;j<128;j++)
		p2[j]=0;
    unsigned int n,result=0,con=0;
    n=strlen(p1);
    if(n<1) 
	{
        p2="";
		return 0;
	}
    for (int i = 0; i <= n; ++i)
    {
            if (p1[i]>='0'&&p1[i]<='9')
           {
                temp[con++]=p1[i];
				if(result<con)
				{
					result=con;
                    for(int k=0;k<con;k++)
						p2[k]=temp[k];
				}
            }
            else
            {
				con=0;
            }
    }
	if(result==0) 
		p2="";
    *pOutputstr=p2;
    return result; 
}

