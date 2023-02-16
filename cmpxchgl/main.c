#include<stdlib.h>
#include<stdio.h>

int main() { 
	int* ptr = (int*)malloc(sizeof(int));
	int ret , new , old; *ptr = ret = new = old = 0;
	new = 100;
	old = *ptr = 4; //设置 cmpxchgl 比较相等
	//old = old + 1; //设置 cmpxchgl 比较不相等
	/*
	比较old和(int* ptr)的值，如果相同，ZF标志被设置，同时new的值被写到(int* ptr )，
	否则，清ZF标志，并且把(int* ptr)的值写回 old。
	*/
	printf("=== before cmpxchgl ===\n");
	printf("*ptr = %d\n", *ptr);
	printf(" ret = %d\n", ret);
	printf(" new = %d\n", new);
	printf(" old = %d\n", old);
	asm volatile("cmpxchgl %2,%1"
			: "=a" (ret), "+m" (*ptr)
			: "r" (new), "0" (old)
			: "memory");

	printf("=== after  cmpxchgl ===\n");
	printf("*ptr = %d\n", *ptr);
	printf(" ret = %d\n", ret);
	printf(" new = %d\n", new);
	printf(" old = %d\n", old);
	return 0;
}