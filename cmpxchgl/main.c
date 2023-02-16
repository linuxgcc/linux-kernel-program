#include<stdlib.h>
#include<stdio.h>
void show_3d7950d4_bfd1_4257_8723_81cf84324e77(){}
int main() { 
	int ret = 0 ;
	int new = 0 ;
	int old = 0 ; 
	int* ptr = (int*)malloc(sizeof(int));
	
	*ptr = ret = new = old = 0;
	new = 100;
	old = *ptr = 4; //设置 cmpxchgl 比较相等
	//old = old + 1; //设置 cmpxchgl 比较不相等
	/*
	Intel语法: 目的操作数，源操作数   CMPXCHG EBX,ECX ；如果EAX与EBX相等，则ECX送EBX且ZF置1；否则EBX送EAX，且ZF清0
	AT&T语法：源操作数，目的操作数   cmpxchg %ecx, %ebx；如果EAX与EBX相等，则ECX送EBX且ZF置1；否则EBX送EAX，且ZF清0

	比较old和(int* ptr)的值，如果相同，ZF标志被设置，同时new的值被写到(int* ptr )，
	否则，清ZF标志，并且把(int* ptr)的值写回 old。
	*/
	printf("=== before cmpxchgl ===\n");
	printf("*ptr = %d\n", *ptr);
	printf(" ret = %d\n", ret);
	printf(" new = %d\n", new);
	printf(" old = %d\n", old);
	show_3d7950d4_bfd1_4257_8723_81cf84324e77();
	asm volatile("cmpxchgl %2,%1"
			: "=a" (ret), "+m" (*ptr)
			: "r" (new), "0" (old)
			: "memory");
	show_3d7950d4_bfd1_4257_8723_81cf84324e77();
	printf("=== after  cmpxchgl ===\n");
	printf("*ptr = %d\n", *ptr);
	printf(" ret = %d\n", ret);
	printf(" new = %d\n", new);
	printf(" old = %d\n", old);
	return 0;
}
