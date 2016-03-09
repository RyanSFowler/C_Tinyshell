#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
/* newcat: Concatenate files */
int main(int argc, char *argv[])
   {
   void filecopy(int ifp, int ofp); /* prototype for function */

   int fd;
   char *prog = argv[0]; /* program name for errors */
   if (argc == 1) /* no args; copy standard input */
   {
      filecopy(0,1);
   }
   else 
   {
      while (--argc > 0)
      {
         fd = open(*++argv , O_RDONLY,0);
         if ( fd == -1) {
            fprintf(stderr, "%s: can't open %s\n", prog, *argv);
            return(-1);
         } else {
            filecopy(fd, 1);
           close(fd);
         }
      }
   }
   return(0);
}
/* filecopy: copy file ifp to ofp */
void filecopy(int ifp, int ofp)
{
   int c;
   while (read(ifp,&c,ofp ) != 0)
      write(ofp,&c,ofp);
}