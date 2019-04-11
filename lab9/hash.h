#ifndef __HASH
#define __HASH

int hash(char* arr, int base, int t_size);
int collision_count(char* arr[], int num, int base, int t_size);
char** parser(char* f_name);
int prime_generator(int low, int high);
int isprime(int n);
void profiling(char** arr);
char** stop_parser();

extern int g_size;

#endif
