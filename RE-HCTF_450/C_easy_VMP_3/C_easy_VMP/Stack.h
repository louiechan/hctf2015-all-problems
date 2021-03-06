#include <Windows.h>
#include <stdio.h>
#pragma once
class VM_STACK
{
	struct VM_Stack
	{
		int capacity;
		int TopOfStack;
		PDWORD vmStack;
	};
	typedef struct VM_Stack *Stack;
protected:
	Stack S;
	
	//BOOL StartVM(PBYTE vmCode, PDWORD vmData);
	
public:
	VM_STACK(int MaxSize);//CreateStack
	void Stack_Push(DWORD xxx);
	void Stack_Pop(PDWORD xxx);
#ifdef _DEBUG
	void Debug_PrintStack()
	{
		printf("\n");
		for (int i = 0; i <= S->TopOfStack; i++)
			printf("Stack :  %d   ( %d )\n",i,S->vmStack[i]);
		printf("\n");
	}
#endif
	~VM_STACK()
	{
		free(S->vmStack);
		free(S);
	}
private:
	
	void Error(char* xxx);

};
