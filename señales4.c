#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signum) 
{		
		if (signum == SIGALRM){
		printf("Alarma recibida \n");
		execl("/bin/ls","exit",NULL);
		}
		

	}


	int main() 
	{
		
        pid_t pidB, pidC;
        int status;
        
        signal(SIGALRM,signal_handler); 
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
		 
		pidB = fork(); 
		
		    if (pidB == 0) 
		    {	
		    	sleep(1);
		    	kill(pidC, SIGKILL);
			pause();
			return 0;
		    }	
		    
		    	   
		pidC = fork();
		
		    if (pidC == 0) 
		    {
			while (1){
			printf("Esperando una señal\n");
			} 
			return 0;
		    } 
  
	    alarm(5);
	    pause();
	    waitpid(pidB, &status, 0);    
	    return 0;
}
