#include "CommentConvert.h"  
enum State state=NUL_State;  
void CommentConvert(FILE *pfRead,FILE *pfWrite)  
{  
	while(state!=END_State)  
	{  
		switch (state)  
		{  
		case NUL_State:  
			Do_NUL_State(pfRead,pfWrite);  
			break;  
		case C_State:  
			Do_C_State(pfRead,pfWrite);  
			break;  
		case CPP_State:  
			Do_Cpp_State(pfRead,pfWrite);  
			break;  
		case END_State:  
			break;  
		}  
	}  
}  
void Do_NUL_State(FILE *pfRead,FILE *pfWrite)  
{  
	int first=0;  
	int second=0;  
	first=fgetc(pfRead);               //fgetc�����ķ���ֵΪint��  
	switch(first)  
	{  
	case '/':  
		second=fgetc(pfRead);  
		if(second=='*')  
		{  
			fputc('/',pfWrite);  
			fputc('/',pfWrite);  
			state= C_State;  
		}  
		else if(second=='/')  
		{  
			fputc(first,pfWrite);  
			fputc(second,pfWrite);  
			state= CPP_State;  
		}  
		else  
		{  
			fputc(first,pfWrite);  
			fputc(second,pfWrite);  
		}  
		break;  
	case EOF:  
		state=END_State;  
		break;  
	default:  
		fputc(first,pfWrite);  
		break;  
	}  

}  
void Do_C_State(FILE *pfRead,FILE *pfWrite)  
{  
	int first=0;  
	int second=0;  
	int third=0;  
	first=fgetc(pfRead);  
	switch(first)  
	{  
	case '*':  
		second=fgetc(pfRead);  
		switch(second)  
		{  
		case '/':  
			third=fgetc(pfRead);  
			if(third!='\n')                  
			{  
				fputc('\n',pfWrite);  
			}  
			if(third=='/')     
			{  
				ungetc(third,pfRead);      //���������ַ�����input.c��  
				state= NUL_State;  
				break;  
			}  
			fputc(third,pfWrite);      //���������ַ�д��output.c��  
			state= NUL_State;  
			break;  
		case '*':           
			third=fgetc(pfRead);  
			fputc(first,pfWrite);         //����һ��*ֱ��д��output.c��  
			if(third=='/')  
			{  
				state= NUL_State;  
			}  
			break;  
		default:  
			fputc(first,pfWrite);  
			fputc(second,pfWrite);  
			break;  
		}  
		break;  
	case '\n':  
		fputc(first,pfWrite);  
		fputc('/',pfWrite);  
		fputc('/',pfWrite);  
		break;  
	case EOF:  
		state=END_State;  
		break;  
	default:  
		fputc(first,pfWrite);  
		break;  
	}  
}  
void Do_Cpp_State(FILE *pfRead,FILE *pfWrite)  
{  
	int first=0;  
	first=fgetc(pfRead);  
	switch(first)  
	{  
	case '\n':  
		fputc(first,pfWrite);  
		state= NUL_State;  
		break;  
	case EOF:  
		state=END_State;  
		break;  
	default:  
		fputc(first,pfWrite);  
		break;  
	}  
}  