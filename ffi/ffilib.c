// Simple C library which demonstrates how the FFI is called and can call back:
//
// Compile on *nix-like systems using:
//    gcc -shared -o ffilib.so ffilib.c
//
#include <stdio.h>

int * callme5(int *p)
{
	printf("callme5 got %p (%d)\n", p, *p);
	*p += 100;
	return p;
}

int callme1( int x, char * y)
{
	printf("callme1 got [%d] [%s]\n", x,y);
	return x+10;
}

int callme2( int x, int (*cb)(int) )
{
	printf("callme2 got [%d] [%p]\n", x, (void*)cb);
	return cb(x);
}


// This is a kind of stupid and contrived example, to demonstrate how to use ptr types
// and ptr:unpack_orig --- since it modifies the ptr 'b' points to:
void callme3 ( unsigned char ** b, int len)
{
	for (int ix=0; ix<len; ix++)
	{
		**b += 1;
		++*b;
	}
}

#include <stdarg.h>
char * callme4 ( const char *fmt, ...)
{
	static char buf[128];

	va_list args;
	va_start(args,fmt);
	vsnprintf(buf, 127, fmt, args);
	va_end(args);
	return buf;
}
