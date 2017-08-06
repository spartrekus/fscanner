
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  //define getcwd
#include <time.h>
#include "../lib/libtime.c"


int main( int argc, char *argv[])
{

     printf( "\n" );
     printf("****************************\n");
     printf("** 2017, PC SCANNER       **\n" );
     printf("****************************\n");
     printf( "\n" );

     char mytimestamp[PATH_MAX];
     char cwd[PATH_MAX];
     char cmdi[PATH_MAX];
     strncpy( mytimestamp,  strtimestamp() , PATH_MAX );

     char str[PATH_MAX];
     int i;
     printf("Enter your filename of new scanning file: ");
     scanf("%[^\t\n]s",str); 
     i = strlen(str); 
     printf("Text:%s, Length:%d\n",str,i);

     strncpy( cmdi, " scanimage --mode color >> " , PATH_MAX );
     strncat( cmdi , " \"" , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , mytimestamp , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , "-pcscan" , PATH_MAX - strlen(cmdi) - 1);
     if ( i >= 1 )
       strncat( cmdi , "-" , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , str , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , ".ppm\" "  , PATH_MAX - strlen(cmdi) - 1);

     printf( "<PATH: %s>\n" , getcwd( cwd, PATH_MAX ));
     printf( "<CMD: %s>\n" , cmdi );

     char c;
     printf("Do you want to continue (y/n)? ");
     scanf(" %c",&c); c = toupper(c);
     if  (  ( c == 'Y' ) || ( c == '1' )  )
     {
       printf( "Yes\n");
       printf( "<Running %s>\n", cmdi );
       system( cmdi );
     }
     else  printf( "No\n");

    return 0;
}



