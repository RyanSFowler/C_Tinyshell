#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	void mars(int n);
	int m;
	scanf("%d", &m);
	mars(m);
}
void mars(int n)
{
	int i = 0;
	while(i<n)
	{
		printf("HELLO MARS\n");
		i++;
	}
}
