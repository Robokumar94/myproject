
  char seg[]={0x3f,0x06,0x5B,0x4F,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int main (void)
{
  int x=0,z,y;
DDRB=0X03;
DDRD=0XFF;
while(1)
{

z=x%10;
y=x/10;

PORTB=0X01;
PORTD=seg[z];
_delay_ms(200);
PORTB=0X02;
PORTD=seg[y];
_delay_ms(200);
    if (!(PINB&(1<< 0)))
{
x++;
}
if(x==29)
{
x=00;
}
}
}