#include<stdio.h>

void p(int n);
void g();
void h();
void d();

int bits = 10;
int count = 0;
int main(void)
{
	p(0);
	g();
	h();
	d();

}

void p(int n)
{
	count++;
	printf("pilani: %u\n, %d", &n, count);
	p(n + 1);
}

void g()
{
	int goa = 1;
	printf("goa: %u\n", &goa);
}

void h()
{
	int hyd = 2;
	printf("hyd: %u\n", &hyd);
}

void d()
{
	int dub = 3;
	printf("dub: %u\n", &dub);

}
