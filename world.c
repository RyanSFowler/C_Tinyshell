#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
	void world (int n);
	int m;
	scanf("%d", &m);
	world(m);
}
void world(int n)
{
	int i = 0;
	while(i<n)
	{
		printf("hello world\n");
		i++;
	}
}