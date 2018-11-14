#include <system.h>

/* you will need to code these up yourself! */
unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
	/* Add code here to copy 'count' bytes of data from 'src' 
	 * to 'dest', finally return 'dest'*/
}


unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
	/*
		Add code here to set 'count' bytes in 'dest' to 'val'.
		Again,return 'dest'
	*/
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
	/*
		Same as above, but this time, we are working with a 16-bit
		'val' and dest pointer. Your code can be an exact copy of
		the above, provided that your local variables if any, are
		unsigned short
	*/
}


int strlen(const char *str)
{
	/*
		This loops through character array 'str', returning how
		many characters it needs to check before it finds a 0.
		In simple words, it returns the length in bytes of a string
	*/
}


/*
	We will use this later on for reading from the I/O ports to get
	data from devices such as the keyboard. We are using what is called
	'inline assembly' int hese routines to actually do the work
*/
unsigned char inportb(unsigned short _port)
{
	unsigned char rv;
	__asm__ __volatile__("inb %1, %0":"=a"(rv):"dN"(_port));
}


/*
	This is a very simple main() function. All it does is sit in an
	infinite loop. This will be like our 'idle' loop
*/
void main()
{
	/*
		You would add commands after here
	*/

	/*
		and leave this loop in. there is an endless loop in 'start.asm'
		also. if you accidentally delete this next line
	*/
	for(;;);
}
