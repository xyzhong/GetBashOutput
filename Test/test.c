/*************************************************************************
    > File Name: test.c
    > Author: Alleria
    > Mail: cxgAlleria@gmail.com 
    > Created Time: Wednesday, March 04, 2015 PM07:53:12 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MALLOC(T, LEN) (T *)malloc(sizeof(T) * LEN)

const int Length = 1024;
typedef char * String;
typedef const char * CString;
typedef char ** PString;
enum BOOL{Success=0, Failure=1};

enum BOOL getSingleOutput(CString, PString);

int main(int argc, char *argv[])
{
    //Codes
	if(argc < 2)
	{
		printf("Usage<Linux> : %s command[to be poccessed]\n", argv[0]);
	}
	else
	{
		int i;
		for(i = 1; i < argc; ++ i)
		{
			String pStr = NULL;
			enum BOOL result = getSingleOutput(argv[i], &pStr);
			if(result == Success)
			{
				printf("Process Command<%s>\nResult:[%s]\n", argv[i], pStr);
			}
			else
			{
				printf("Command<%s> is not supported!\n", argv[i]);
			}
			if(pStr)
			{
				free(pStr);
			}
		}
	}
    return 0;
}

enum BOOL getSingleOutput(CString cmd, PString result)
{
	FILE * fs = NULL;
	if(NULL == (fs = popen(cmd, "r")))
	{
		return Failure;
	}
	else
	{
		char headC = EOF;
		if(EOF != (headC = fgetc(fs)))
		{
			ungetc(headC, fs);
			int length = Length;//, i = 0;
			do
			{
				if(*result != NULL)
				{
					free(*result);
				}
				*result = MALLOC(char, length);
				memset(*result, 0, length);
				rewind(fs);
				fgets(*result, length, fs);
				length  = length * 2;
				//printf("%d %s\n", ++i, *result);
			}while(strrchr(*result, '\n') == NULL);
			memset(*result + strlen(*result) - strlen(strrchr(*result, '\n')), 0, 1);
		}
		pclose(fs);
		return Success;
	}
}
