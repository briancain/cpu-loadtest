#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_OF_CORES 4
#define MAX_PRIME 1316134912

void do_primes(int maxPrime)
{
    unsigned long i, num, primes = 0;
    for (num = 1; num <= maxPrime; ++num) {
        for (i = 2; (i <= num) && (num % i != 0); ++i);
        if (i == num)
            ++primes;
    }
    printf("Calculated %lu primes.\n", primes);
}

int main(int argc, char ** argv)
{
    int numCores, maxPrime;

    if (argc < 3) {
      printf("Not enough arguments. arg 1 = NUM_OF_CORES. arg 2 = MAX_PRIME\n");
      printf("Example: ./a.out 4 1000\n");
      printf("Switching to default values for Cores: %d and Max Prime: %d\n", NUM_OF_CORES, MAX_PRIME);

      numCores = NUM_OF_CORES;
      maxPrime = MAX_PRIME;
    }
    else {
      numCores = atoi(argv[1]);
      maxPrime = atoi(argv[2]);

      printf("Began CPU load test with %d cores and the max prime being %d\n",
        numCores, maxPrime);
    }

    time_t start, end;
    time_t run_time;
    unsigned long i;
    pid_t pids[numCores];

    /* start of test */
    start = time(NULL);
    for (i = 0; i < numCores; ++i) {
        if (!(pids[i] = fork())) {
            do_primes(maxPrime);
            exit(0);
        }
        if (pids[i] < 0) {
            perror("Fork");
            exit(1);
        }
    }
    for (i = 0; i < numCores; ++i) {
        waitpid(pids[i], NULL, 0);
    }
    end = time(NULL);
    run_time = (end - start);
    printf("This machine calculated all prime numbers under %d, %d times "
           "in %ld seconds\n", maxPrime, numCores, run_time);

    return 0;
}
