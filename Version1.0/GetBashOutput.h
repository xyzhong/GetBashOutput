/*************************************************************************
    > File Name: GetBashOutput.h
    > Author: Alleria
    > Mail: cxgAlleria@gmail.com 
    > Created Time: Wednesday, March 04, 2015 PM09:37:45 HKT
 ************************************************************************/

#ifndef _GETBASHOUTPUT_H_
#define _GETBASHOUTPUT_H_

#include "tackle.h"

enum State{Error=0, Done=1};

enum State GetLine(FILE *, PString);
enum State getSingleOut(CString, PString);
enum State getMultiOuts(CString, PList);

#endif //_GETBASHOUTPUT_H_

