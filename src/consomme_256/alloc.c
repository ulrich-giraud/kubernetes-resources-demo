#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
 
int* g;
bool quit;

void sig_handler(int signo)
{
    printf ("Freeing memory\n");
    fflush(stdout);
    free(g);
    quit = true;
}

int main ( int argc , char * argv[] ) 
{
    quit = false;
    if (signal(SIGINT, sig_handler) == SIG_ERR)
      printf("\ncan't catch SIGINT\n");
    if (signal(SIGTERM, sig_handler) == SIG_ERR)
      printf("\ncan't catch SIGTERM\n");


    // This pointer will hold the
    // base address of the block created
    size_t u = 268435456;
 
    
    printf("allocate %lu bytes\n", u);
    fflush(stdout);
 
    // Dynamically allocate memory using malloc()
    g = (int*)malloc(u);
    printf("allocated %lu bytes\n", u);
    fflush(stdout);
 
    g[0] = 1;

    for (long unsigned int i = 0; i < (u / sizeof(int)) ; i++) {
        g[i] = 42;
    }
    printf ("reservation done\n");
    fflush(stdout);
    while(! quit) {
        sleep(10);
    }
 
    return 0;
}