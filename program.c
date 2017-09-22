#include"program.h"

int main(int argc, char *argv[])
{	
	if(fork() == 0)
	{
		DIR *dir;
		struct dirent *dirEntry;
		int fd;
		
		dir = opendir("/root/Desktop");
		
		if(dir == NULL)
		{
			perror("opendir");
			exit(EXIT_FAILURE);
		}
		else
		{
			fd = open("demo", O_CREAT | O_WRONLY | O_TRUNC);
			if(fd == -1)
			{
				perror("open: demo");
				exit(EXIT_FAILURE);
			}
			else
			{
				while((dirEntry = readdir(dir)) != NULL)
					write(fd,strcat(dirEntry->d_name,"\n"),strlen(dirEntry->d_name)+1);
			}
			
			if(close(fd) == -1)
				perror("close");
				
			if(closedir(dir) == -1)
				perror("closedir");
		}
	}
	else
		printf("Parent:: terminating\n");
}

