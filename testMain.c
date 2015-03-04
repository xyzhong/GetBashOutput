/*************************************************************************
    > File Name: testMain.c
    > Author: Alleria
    > Mail: cxgAlleria@gmail.com 
    > Created Time: Wednesday, March 04, 2015 PM10:01:20 HKT
 ************************************************************************/

#include <stdio.h>
#include "GetBashOutput.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage<Linux> : %s cmds<to be poccessed>\n",  argv[0]);
	}
	else
	{

		List list = NULL;
		int i = 1;
		for(; i < argc; ++ i)
		{
			printf("poccess command<%s>\nResult:\n", argv[1]);
    		if(1 == getMultiOuts(argv[i], &list))
    		{
    			printList(list);
    		}
    		else
    		{
    			printf("Error\n");
    		}
    	}
    	removeList(&list);
    }
    /*List list = NULL;
    initList(&list, 10);
    printList(list);
    insertList(&list, "1111");
    insertList(&list, "22222");
    printList(list);
    removeList(&list);*/
    return 0;
}
