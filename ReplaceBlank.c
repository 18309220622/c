#include<stdlib.h>  
#include<stdio.h>  

//void ReplaceBlack1(char arr[],int len)  
//{  
//    int count=0;      //��¼�ո���  
//    int oldlen=len;   //���arr[oldlen]ָ���ַ�����ĩβ  
//    int newlen=0;  
//    char *ptr=arr;  
//    if(arr==NULL || len<=0)  
//    {  
//        return;  
//    }  
//    while(*ptr++)            //ͳ�Ƴ��ո���  
//    {  
//        if(*ptr==' ')  
//        {  
//            count++;  
//        }    
//    }  
//    newlen=oldlen+2*count;    //��ò���%20����ܳ���  
//    while(oldlen<newlen)  
//    {  
//        if(arr[oldlen]!=' ')     
//        {  
//            //ԭ�ַ�����û�пո�ʱ�ַ�����ƶ�  
//            arr[newlen--]=arr[oldlen--];    
//        }  
//        else  
//        {   
//            //��ֹ�ڴ渲��  
//            arr[newlen--]='0';  
//            arr[newlen--]='2';  
//            arr[newlen--]='%';  
//            oldlen--;  
//        }  
//    }  
//}  


void RepalceBlack2(char *str,int len)
{
	//len�а���һ���ո�ĳ���
	int i=0;
	if(str==NULL || len<0)
		return ;

	for(;i<len;i++)
	{
		if(str[i]==' ')
		{
			int j=len;
			//��ֹԽ�磬j��������Ҫ����Ų����
			while(j>=i)
			{
				//�����ո������Ų
			    str[j+2]=str[j];
			    j--;
			}
			str[i]='%';
			str[i+1]='2';
			str[i+2]='0';
			len+=2;
		}
	}
}
int main()  
{  
    char str[20]="We are happy.";  
    int len=0;  
    len=sizeof(str)/sizeof(str[0])-1;
	//RepalceBlack1(str,len);  
    RepalceBlack2(str,len);  
    printf("%s\n",str);
    system("pause");  
    return 0;  
}  