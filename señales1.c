#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signum) 
{
		if( signum == SIGINT ){
	    	printf("El usuario presiono CTRL+C.\n");
	    	sleep(3);

	}
	}




	int main() 
	{

	    
	    while (1) {
	    
	    printf("El pid del proceso es: %d\n", getpid());
	    signal(SIGINT, signal_handler);
	    
	    }
	    

	    return 0;
}
