/*************************************************************************
    > File Name: tackle.c
    > Author: Alleria
    > Mail: cxgAlleria@gmail.com 
    > Created Time: Wednesday, March 04, 2015 PM09:38:33 HKT
 ************************************************************************/

#include "tackle.h"

int initList(PList list, Size size)
{
	if(NULL == ((*list) = MALLOC(struct LIST, 1)))
	{
		return 1;
	}
	if(NULL == ((*list)->listHeader = MALLOC(String, size)))
	{
		free(*list);
		return 1;
	}
	memset((*list)->listHeader, 0, sizeof(String) * size);
	(*list)->size = 0;
	(*list)->MAX = size;
	return 0;
}

int insertList(PList list, CString string)
{
	if((NULL == (*list)) || ((*list)->MAX <= (*list)->size) || (NULL == ((*list)->listHeader[(*list)->size] = MALLOC(char, strlen(string)))))
	{
		return -1;
	}
	if(NULL == (strcpy((*list)->listHeader[(*list)->size], string)))
	{
		free((*list)->listHeader[(*list)->size]);
		return 0;
	}
	(*list)->size = (*list)->size + 1;
	return 1;
}

int printList(List list)
{
	printf("Show List Contents\nSize:%d/Capacity:%d\n", list->size, list->MAX);
	int i = 0;
	for(; i < list->size; ++ i)
	{
		printf("\t\tLine %d : %s\n", i, list->listHeader[i]);
	}
	printf("End\n");
}

void removeList(PList list)
{
	if(*list)
	{
		int i;
		for(i = 0; i < (*list)->size; ++ i)
		{
			if((*list)->listHeader[i])
			{
				free((*list)->listHeader[i]);
			}
		}
		free(*list);
	}
}