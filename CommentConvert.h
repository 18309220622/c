#ifndef _CommentConvert_  
#define _CommentConvert_  


#include<stdio.h>  
#include<stdlib.h>  

#define INPUTFILENAME "input.c"  
#define OUTPUTFILENAME "output.c"  

enum State  
{  
	NUL_State,  
	C_State,  
	CPP_State,  
	END_State  
};  
void CommentConvert(FILE *pfRead,FILE *pfWrite);  
void Do_NUL_State(FILE *pfRead,FILE *pfWrite);  
void Do_C_State(FILE *pfRead,FILE *pfWrite);  
void Do_Cpp_State(FILE *pfRead,FILE *pfWrite);  

#endif  