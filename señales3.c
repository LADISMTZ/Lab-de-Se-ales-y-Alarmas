#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signum) 
{		
		if (signum == SIGALRM){
		printf("Alarma recibida \n");
		}
		
		if (signum == SIGUSR1){
		printf("Recibi señal SIGUSR1\n");
	    	printf("Mi ID es %d\n",getpid());
	    	printf("El ID de mi padre es %d\n",getppid());
		}

		if( signum == SIGUSR2 ){
	    	printf("Recibi señal SIGUSR2\n");
	    	printf("Mi ID es %d\n",getpid());
	    	printf("El ID de mi padre es %d\n",getppid());
	    	}
	}
	int main() 
	{	
        pid_t pidA, pidC;
        int status;
        signal(SIGALRM,signal_handler); 
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
		pidA = fork(); 
		
		    if (pidA == 0) 
		    {
			pause();
			kill(pidC, SIGUSR2);
			waitpid(pidC, &status, 0);
			return 0;
		    }		   
		pidC = fork();
		
		    if (pidC == 0) 
		    {
			pause();
			return 0;
		    } 
	    alarm(3);
	    pause();
	    kill(pidA, SIGUSR1);
	waitpid(pidC, &status, 0);    
	    waitpid(pidA, &status, 0);
	    printf("MIs dos hijos han terminado");
	    return 0;
}
