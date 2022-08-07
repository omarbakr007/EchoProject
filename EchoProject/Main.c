#include "uart.h"
#define OUTPUT 1
#define INPUT 0

int main()
{
uint8_t EchoNumber = 0;
DIO_init(PIN0, PORTA, OUTPUT);
DIO_init(PIN1, PORTA, INPUT);
SWUART_init(9600);
while(1)
{
    SWUART_recieve(&EchoNumber);
    SWUART_send(EchoNumber);
}



}