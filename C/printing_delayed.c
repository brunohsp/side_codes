#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BILLION  1000000000L;

int main(int argc, char const *argv[])
{
  char * ptr_end;
  char * ptr_end2;
  struct timespec start_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    double elapsed_time;
    double sleep_time = strtod(argv[2], &ptr_end) / strtod(argv[1], &ptr_end2); // secs / n_chars
    double aux = sleep_time;

    while (1) {
        struct timespec current_time;
        clock_gettime(CLOCK_MONOTONIC, &current_time);

        elapsed_time = (current_time.tv_sec - start_time.tv_sec) +
                       (current_time.tv_nsec - start_time.tv_nsec) / 1.0e9;

        if (elapsed_time >= aux) {
            aux += sleep_time;
            printf("*");
            fflush(stdout);
        }

        if (elapsed_time > (double) strtod(argv[2], &ptr_end))
            break;

    }

    printf("\n");

    return 0;
}
