
#ifndef __COMMENT_CONVERT_H
#define __COMMENT_CONVERT_H

#include<stdio.h>
#include<stdlib.h>


#define READFILENAME "input.c"

#define WRITEFILENAME "output.c"

static enum STATE
{
	NULL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};




void CommentConvert(FILE *fRead, FILE *fWrite);

void Do_C_State(FILE *fRead, FILE *fWrite);

void Do_CPP_State(FILE *fRead, FILE *fWrite);

void Do_Null_state(FILE *fRead, FILE *fWrite);








#endif //!__COMMENT_CONVERT_H