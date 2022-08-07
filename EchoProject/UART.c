 
 #include "uart.h"
 #include "avr/io.h"

 void SWUART_init(uint32_t baudrate)
{
	uint16 ubrr_value = 0;


	UCSRA = (1<<U2X);

	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) | (1<<USBS) | (1<<UPM1); 
	

	ubrr_value = (uint16)(((F_CPU / (baudrate * 8UL))) - 1);


	UBRRH = ubrr_value>>8;
	UBRRL = ubrr_value;
}

void SWUART_send(uint8_t data)
{

	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	UDR = data;

}

void SWUART_recieve(uint8_t *data)
{
	
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
    *data = UDR;		
}