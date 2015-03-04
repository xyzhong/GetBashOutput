/*************************************************************************
    > File Name: GetBashOutput.c
    > Author: Alleria
    > Mail: cxgAlleria@gmail.com 
    > Created Time: Wednesday, March 04, 2015 PM09:37:49 HKT
 ************************************************************************/


#include "GetBashOutput.h"

enum State GetLine(FILE * fp, PString string)
{
	if(NULL == fp)
	{
		return Error;
	}
	int size = 128;
	do
	{
		if(NULL != (*string))
		{
			free(*string);
		}
		*string = MALLOC(char, size);
		memset(*string, 0, size);
		rewind(fp);
		if(NULL == fgets(*string, size, fp))
		{
			return Error;
		}
		size = size * 2;
	}while(strrchr(*string, '\n') == NULL);
	memset(*string + strlen(*string) - strlen(strrchr(*string, '\n')), 0, 1);
	return Done;
}

enum State getSingleOut(CString cmd, PString result)
{
	FILE * fs = NULL;
	if(NULL == (fs = popen(cmd, "r")))
	{
		return Error;
	}
	else
	{
		char headC = EOF;
		if(EOF != (headC = fgetc(fs)))
		{
			ungetc(headC, fs);
			if(Error == GetLine(fs, result))
			{
				return Error;
			}
		}
		pclose(fs);
		return Done;
	}
}

enum State getMultiOuts(CString cmd, PList list)
{
	FILE * fs = NULL;
	if(NULL == (fs = popen(cmd, "r")))
	{
		return Error;
	}
	else
	{
		char headC = EOF;
		String result = NULL;
		int size = 0;
		while(EOF != (headC = fgetc(fs)))
		{
			ungetc(headC, fs);
			if(Error == GetLine(fs, &result))
			{
				return Error;
			}
			size = size + 1;
		}
		pclose(fs);
		fs = popen(cmd, "r");
		if(list != NULL)
		{
			removeList(list);
		}
		if(0 != initList(list, size))
		{
			return Error;
		}
		while(EOF != (headC = fgetc(fs)))
		{
			ungetc(headC, fs);
			GetLine(fs, &result);
			if(1 != insertList(list, result))
			{
				return Error;
			}
		}
		pclose(fs);
		return Done;
	}
}