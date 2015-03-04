/*************************************************************************
    > File Name: tackle.h
    > Author: Alleria
    > Mail: cxgAlleria@gmail.com 
    > Created Time: Wednesday, March 04, 2015 PM09:37:56 HKT
 ************************************************************************/

#ifndef _TACKLE_H_
#define _TACKLE_H_

#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC(TYPE, LENGTH) (TYPE *)malloc(sizeof(TYPE) * LENGTH)

typedef int Length, Size;
typedef char * String;
typedef const char * CString;
typedef char ** PString;

typedef struct LIST
{
    String * listHeader;
    Size size;
    Size MAX;
}* List, ** PList;

int initList(PList, Size);
int insertList(PList, CString);
int printList(List);
void removeList(PList);


#endif //_TACKLE_H_

