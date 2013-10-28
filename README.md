# CPU Loadtest

A simple C program that finds primes. It can be used as a way to stress test n number of CPU's. Changing the #define at the top of the file will determine how many CPUs the program will use.

## Running from command line

There are a couple steps you need to do to run this program. Follow the commands below:

    $ gcc test.c
    $ ./a.out <num-of-cores> <max-prime-to-calculate>

Where <num-of-cores> is the number of cores that will be used (minus <>'s) and where <max-prime-to-calculate> will be the highest prime to calculate (minus <>'s).

## Source

Found on stackoverflow. Putting it up on my github for future reference.

- http://stackoverflow.com/questions/9244481/how-to-get-100-cpu-usage-from-a-c-program/9244508#9244508
