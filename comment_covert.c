#define _CRT_SECURE_NO_WARNINGS 1

#include"comment_covert.h"

enum STATE state = NULL_STATE;

void Do_C_State(FILE *fRead, FILE *fWrite)
{
	char first = 0;
	char second = 0;
	char third = 0;
	first = fgetc(fRead);
	switch (first)
	{
	case'*':
		second = fgetc(fRead);
		switch (second)
		{
		case'/':
			third = fgetc(fRead);
			if (third != '\n')
				fputc('\n', fWrite);
			if (third == '/')
			{
				ungetc(third, fRead);
				state = NULL_STATE;
				break;
			}
				fputc(third, fWrite);
				state = NULL_STATE;
			break;
		case'*':
			third = fgetc(fRead);
			fputc(first, fWrite);
			if (third == '/')
			{
				state=NULL_STATE;
			}
			break;
		default:
			fputc(first, fWrite);
			fputc(second, fWrite);
			break;

		}
		break;
		
	case'\n':
		fputc(first, fWrite);
		fputc('/', fWrite);
		fputc('/', fWrite);
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		
		fputc(first, fWrite);
		break;

	}

}

void Do_CPP_State(FILE *fRead, FILE *fWrite)
{
	char first = 0;
	first = fgetc(fRead);
	switch (first)
	{
	case '\n':
		fputc(first, fWrite);
		state = NULL_STATE;
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, fWrite);
		break;
	}
}

void Do_Null_state(FILE *fRead, FILE *fWrite)
{
	char first = 0;
	char second = 0;
	first = fgetc(fRead);
	switch (first)
	{
	case'/':
		second = fgetc(fRead);
		if (second == '*')
		{
			fputc('/', fWrite);
			fputc('/', fWrite);
			state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, fWrite);
			fputc(second, fWrite);
			state = CPP_STATE;
		}
		else
		{
			fputc(first, fWrite);
			fputc(second, fWrite);
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, fWrite);
		break;
	}
}

void CommentConvert(FILE *fRead, FILE *fWrite)
{
	
	while (state!=END_STATE)
	{
		switch (state)
		{
		case NULL_STATE:
			Do_Null_state(fRead, fWrite);
			break;
		case C_STATE:
			Do_C_State(fRead, fWrite);
			break;
		case CPP_STATE:
			Do_CPP_State(fRead, fWrite);
			break;
		default:
			break;
		}
	}

}
