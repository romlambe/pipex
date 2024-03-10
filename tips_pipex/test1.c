#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	pid_t pid;
	char	buffer[13];

	if (pipe(fd) == -1) //creation d'un tube unidirectionnel communiquant entre les processus
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork(); //lancement d'un second processus (enfant), dédoublement du processus parent
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) //enfant
	{
		close(fd[0]); //fermer l'extremité de lecture du tube(pas besoin de lire à partir du tube)
		write(fd[1],"Hello Parent !", 14);// ecriture dans l'extremité d'écriture du tube
		close(fd[1]); // fermer l'extremité d'écriture du tube
		exit(EXIT_SUCCESS);
	}
	else //parent
	{
		close(fd[1]); //fermer l'extremité d'ecriture car pas besoin d'écrire à partir du tube
		read(fd[0], buffer, 13); // utilisé pour lire les data à l'extremité de lecture du tube
		// le contenu lu est maintenant stocké dans le buffer (Hello Parent !)
		close(fd[0]); // fermer l'extremité de lecture du tube
		printf("Message from child: '%s'", buffer);
		wait(NULL); // attendre que le processus enfant soit terminé avant que lui se termine
		exit(EXIT_SUCCESS);
	}
}


