#ifndef _ALLOC
#define _ALLOC

extern int count;
void* myalloc(int size_in_bytes);
void myfree(void* ptr, int size);

#endif
