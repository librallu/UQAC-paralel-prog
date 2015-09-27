#include <stdio.h>

int add(int* t, int bi, int bs){
	if ( bi >= bs )
		return t[bi];
	else {
		int mid = (bi+bs)/2;
		//~ int first = spawn add(t, bi, mid);
		int first = add(t, bi, mid);
		int last = add(t, mid+1, bs);
		//sync;
		return first + last;
	}
} 

int main(){
	
	int t[] = {1,2,3,4,5};
	printf("result: %d\n", add(t, 0, 4));
	
	return 0;
}
