void LCD_Command(unsigned char c)
{
  unsigned char temp;  
  PORTB &=(~(1<<0));//rs=0
  temp = c&0xF0;
  temp = temp >> 4;
  PORTB &=~(0x0F<<2);
  PORTB |= temp<<2;
  
  PORTB |= (1<<1);//en=1
  _delay_ms(50); 
  PORTB &=(~(1<<1));//en=0
  _delay_ms(50);

  temp = c&0x0F;
  PORTB &=~(0x0F<<2);
  PORTB |= temp<<2;

   PORTB |= (1<<1);//en=1
  _delay_ms(50); 
  PORTB &=(~(1<<1));//en=0
  _delay_ms(50);
}
void lcddata(unsigned char d)
{
  unsigned char temp;
  PORTB |= (1<<0);//rs=1
  temp = d&0xF0;
  temp = temp >> 4;
  PORTB &=~(0x0F<<2);
  PORTB |= temp<<2;
  
  PORTB |= (1<<1);//en=1
  _delay_ms(50); 
  PORTB &=(~(1<<1));//en=0
  _delay_ms(50);

  temp = d&0x0F;
  PORTB &=~(0x0F<<2);
  PORTB |= temp<<2;

   PORTB |= (1<<1);//en=1
  _delay_ms(50); 
  PORTB &=(~(1<<1));//en=0
  _delay_ms(50);
}
int main()
{
DDRB=0XFF;
LCD_Command(0x33);
LCD_Command(0x32);
LCD_Command(0x28);
LCD_Command(0x01);
LCD_Command(0x0e);
LCD_Command(0x80);
char msg[2];
int i;
  while(1)
  {
 TCNT0 = 0x00; // clear count
TCCR0B = 0x06; // start counter
_delay_ms(5000); // delay for 5 seS
TCCR0B = 0x00; // stop counter
itoa(TCNT0,msg,10);
for(i=0;msg[i]!='\0';i++)
  {
    lcddata(msg[i]);
    _delay_ms(30);
  }
msg[i]='\0';  
//_delay_ms(3000);
//LCD_Command(0x01);

LCD_Command(0x01);
}}