#include "splash.h"


#ifdef SPLASH_NCURSES
#if defined __linux__ || __unix__
unsigned int splash_max(){
	FILE *fp;
	char path[10];
	unsigned int ret = 0;
	/* Open the command for reading. */
  	fp = popen("tput colors", "r");
  	if (fp == NULL) {
  	  printf("Failed to run command\n" );
  	  exit(1);
  	}

  	/* Read the output a line at a time - output it. */
  	while (fgets(path, sizeof(path), fp) != NULL) {
  	  ret = atoi(path);
  	}

  	/* close */
  	pclose(fp);

	return ret;
}
#endif

#endif
