#ifndef __SYSTEM_H
#define __SYSTEM_H

/*
    This defines what the stack locks like after an ISR was running
 */
struct regs
{
    unsigned int gs, fs, es, ds;    /* pushed the regs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; /* pushed by pusha */
    unsigned int int_no, err_code;  /* our 'push byte #' and ecodes do this*/
    unsigned int eip, cs, eflags, useresp, ss; /*pushed by the processor
                                                 automatically*/
};

extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);

extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);

extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);

extern int strlen(const char *str);

extern unsigned char inportb(unsigned short _port);

extern void outportb(unsigned short _port, unsigned char _data);

extern void cls();

extern void putch(unsigned char c);

extern void puts(unsigned char *text);

extern void settextcolor(unsigned char forecolor, unsigned char backcolor);

extern void init_video(void);

extern void gdt_install(void);

extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

extern void idt_install();

extern void isrs_install();

extern void irq_install();

extern void irq_install_handler();

extern void irq_unstall_handler();

extern void timer_install();

#endif
