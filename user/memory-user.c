#include "kernel/types.h"
#include "user/user.h"

static unsigned long int next = 1;

int rand(void) // RAND_MAX assumed to be 32767
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: memory-user <start> <limit> <increment>, where <start> is initial mebibytes to allocate which is then incremented up to limit mebibytes\n");
        exit(-1);
    }
    uint start = atoi(argv[1]);
    uint limit = atoi(argv[2]);
    uint increment = atoi(argv[3]);
    uint i;
    uint j;
    int *array;
    for (i=start; i<=limit; i+=increment) {
	printf("allocating %p mebibytes\n", i); 
	array = (int *) malloc(i*1024*1024);
	printf("malloc returned %p\n", array);
        if (!array) {
            printf("malloc failed\n");
	    exit(-1);
        }
	for (j = 0; j <= i*1024*1024/4; j++)
	    array[rand()] = j;
	    
	sleep(50);
	printf("freeing %p mebibytes\n", i); 
	free(array);
	sleep(50);
    }

    exit(0);
}
