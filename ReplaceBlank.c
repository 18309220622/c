#include<stdlib.h>  
#include<stdio.h>  

//void ReplaceBlack1(char arr[],int len)  
//{  
//    int count=0;      //记录空格数  
//    int oldlen=len;   //起初arr[oldlen]指向字符串的末尾  
//    int newlen=0;  
//    char *ptr=arr;  
//    if(arr==NULL || len<=0)  
//    {  
//        return;  
//    }  
//    while(*ptr++)            //统计出空格数  
//    {  
//        if(*ptr==' ')  
//        {  
//            count++;  
//        }    
//    }  
//    newlen=oldlen+2*count;    //求得插入%20后的总长度  
//    while(oldlen<newlen)  
//    {  
//        if(arr[oldlen]!=' ')     
//        {  
//            //原字符串中没有空格时字符向后移动  
//            arr[newlen--]=arr[oldlen--];    
//        }  
//        else  
//        {   
//            //防止内存覆盖  
//            arr[newlen--]='0';  
//            arr[newlen--]='2';  
//            arr[newlen--]='%';  
//            oldlen--;  
//        }  
//    }  
//}  


void RepalceBlack2(char *str,int len)
{
	//len中包含一个空格的长度
	int i=0;
	if(str==NULL || len<0)
		return ;

	for(;i<len;i++)
	{
		if(str[i]==' ')
		{
			int j=len;
			//防止越界，j用来控制要往后挪几次
			while(j>=i)
			{
				//遇见空格就往后挪
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