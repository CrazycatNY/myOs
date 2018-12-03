#include <system.h>

/*
    This will keep track of how many ticks that the system has been running for
 */
int timer_ticks = 0;

/*
    Handlers the timer. In this case, it`s very simple: We increment the
    'timer_ticks' varibale every time the timer fires. By default, the timer
    fires 18.222 times per second. Why 18.222Hz? Some engineer at IBM must`ve
    been smoking something funky
 */
void timer_handler(struct regs *r)
{
    /*
        Increment our 'tick count' 
    */
    timer_ticks++;

    /*
        Every 18 clocks (appeoximately 1 second), we will display a message on
        the screen
     */
    if(timer_ticks % 18 == 0)
    {
        puts("One second has passed\n");
    }
}

/*
    Set up the system clock by installing the timer handler into IRQ0
 */
void timer_install()
{
    /*
       Install 'timer_handler' to IRQ 
     */
    irq_install_handler(0, timer_handler);
}

/*
    This will continuously loop until the given time has been reached
 */
void timer_wait(int ticks)
{
    unsigned long eticks;

    eticks = timer_ticks +ticks;
    while(timer_ticks < eticks);
}
