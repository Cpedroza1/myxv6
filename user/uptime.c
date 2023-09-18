#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/date.h"

int 
main(int argc, char *argv[]){

	int clockTicks = uptime();
	printf("Up %d clock ticks\n", clockTicks);
	exit(0);
}