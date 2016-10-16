#include "CommentConvert.h"  
int main()  
{  
	FILE *pfRead=NULL;  
	FILE *pfWrite=NULL;  
	printf("转换开始：\n");  
	pfRead=fopen(INPUTFILENAME,"r");  
	if(NULL==pfRead)  
	{  
		perror("fopen file for read" );  
		exit(EXIT_FAILURE);  
	}  
	pfWrite=fopen(OUTPUTFILENAME,"w");  
	if(NULL==pfRead)  
	{  
		fclose(pfRead);  
		perror("fopen file for write" );  
		exit(EXIT_FAILURE);  
	}  
	CommentConvert(pfRead,pfWrite);  
	printf("转换结束！");  
	fclose(pfRead);  
	fclose(pfWrite);  
	system("pause");  
	return 0;  
}  
