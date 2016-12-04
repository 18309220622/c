#pragma once
#include<assert.h>
#include<cstdio>
#include<cstdlib>

//void* Memmove(void* dst,void* src,size_t count)
//{
//	char* pdst=(char*)dst;
//	const char* psrc=(const char*)src;
//	assert(dst);
//	assert(src);
//	if(pdst>psrc && pdst<=psrc+count)
//	{
//		while(count--)
//		{
//			*(pdst+count)=*(psrc+count);
//		}
//	}
//	else   //pdst<psrc
//	{
//		while(count--)
//		{
//			*pdst++=*psrc++;
//		}
//	}
//	return dst;
//}
//
//int main()
//{
//	int a[]={1,2,3,4,5,6,7};
//	Memmove(a+2,a,2*sizeof(int));
//	for(int i=0;i<7;++i)
//	{
//		printf("%d",a[i]);  //1 2 1 2 5 6 7,3ºÍ4±»¸²¸Ç
//	}
//
//	/*char str[] = "be very useful......";
//	Memmove(str+8,str+3,11);
//	puts(str);*/
//	system("pause");
//	return 0;
//}
//
//
//void* Memmset(void* dst,int num,size_t count)
//{
//	char* pdst=(char*)dst;
//	assert(dst);
//	while(count--)
//	{
//		*pdst++=num;
//	}
//	return dst;
//}
//
//int main()
//{
//	int tmp[10];
//	Memmset(tmp,0,10*sizeof(int));
//	for(int i=0;i<10;++i)
//	{
//		printf("%d\n",tmp[i]);
//	}
//	system("pause");
//	return 0;
//}


void* Memcopy(void* dst,const void* src,size_t count)
{
	char* pdst=(char*)dst;
	const char* psrc=(const char*)src;
	assert(dst);
	assert(src);
	while(count--)
	{
		*pdst++=*psrc++;
	}
	return dst;
}
int main()
{
	int a[]={1,2,3,4,5,6};
	Memcopy(a,a+3,3*sizeof(int));
	for(int i=0;i<6;++i)
	{
		printf("%d",a[i]);   //4 5 6 4 5 6  
	}
	/*char str[] = "memmove can be very useful......";
	Memcopy(str+20,str+15,11);
	puts(str);*/
	system("pause");
	return 0;
}
