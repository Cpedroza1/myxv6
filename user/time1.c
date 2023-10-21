#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/date.h"
#include "kernel/pstat.h"

int 
main(int argc, char *argv[]){

	int startTime = uptime();
	int pid = fork();
	struct rusage ru;
	

	if(pid == 0){

		exec(argv[1], argv +1);

	}else if(pid > 0){

		wait2(&pid, &ru);
		int endTime = uptime();
		int totalTime = endTime - startTime;
		printf("Time: %d, cputime: %d \n", totalTime, ru.cputime);

	}else{
		printf("fork failed\n");
	}
	
	exit(0);
	}	