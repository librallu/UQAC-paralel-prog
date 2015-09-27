#include <stdio.h>
#include <math.h>

int addThread(int* t, int bi, int bs){
	int i, res=0;
	for ( i = bi ; i <= bs ; i++ )
		res += t[i];
	return res;
}

int add(int* t, int len){
	
	// section 1
	int nbThreads = sqrt(len);
	int resThreads[nbThreads]; int resMain = 0;
	int step = len/nbThreads;
	int i, pos = 0;
	
	// spawning threads
	// parallel for ( i = 0 ; i < nbThreads ; i++){
	for ( i = 0 ; i < nbThreads ; i++){
		resThreads[i] = addThread(t, pos, pos+step-1);
		printf("res thread: %d\n", resThreads[i]);
		pos += step;
	}
	
	// section 2
	// main thread computation
	for ( i = pos ; i < len ; i++ ){
		resMain += t[i];
	}
	
	// section 3
	// sync
	// computing result 
	for ( i = 0; i < nbThreads; i++ )
		resMain += resThreads[i];
	
	return resMain;
} 

int main(){
	
	int t[] = {1,2,3,4,5,6,7,8};
	printf("result: %d\n", add(t, 8));
	
	return 0;
}
