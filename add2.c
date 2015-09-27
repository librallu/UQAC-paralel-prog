#include <stdio.h>
#include <math.h>

int add_thread(int* t, int bi, int bs){
	int i, res=0;
	for ( i = bi ; i <= bs ; i++ )
		res += t[i];
	return res;
}

int add(int* t, int len){
	
	int nb_threads = sqrt(len);
	int res_threads[nb_threads]; int res_main = 0;
	int step = len/nb_threads;
	int i, pos = 0;
	
	// section 1
	// spawning threads
	// parallel for ( i = 0 ; i < nb_threads ; i++){
	for ( i = 0 ; i < nb_threads ; i++){
		res_threads[i] = add_thread(t, pos, pos+step-1);
		printf("res thread: %d\n", res_threads[i]);
		pos += step;
	}
	
	// section 2
	// main thread coup
	for ( i = pos ; i < len ; i++ ){
		res_main += t[i];
	}
	
	// section 3
	// sync
	// computing result 
	for ( i = 0; i < nb_threads; i++ )
		res_main += res_threads[i];
	
	return res_main;
} 

int main(){
	
	int t[] = {1,2,3,4,5,6,7,8};
	printf("result: %d\n", add(t, 8));
	
	return 0;
}
