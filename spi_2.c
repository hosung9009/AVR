#include "spi_2.h"
#include <avr/io.h>


/*������������� SPI*/
void SPI_Init(void)
{
  /*��������� ������ �����-������
  ��� ������, ����� MISO ������*/
  SPI_DDRX |= (1<<SPI_MOSI)|(1<<SPI_SCK)|(1<<SPI_SS);
  SPI_DDRX &= ~(1<<SPI_MISO);
  
  SPI_PORTX |= (1<<SPI_MOSI)|(1<<SPI_SCK)|(1<<SPI_SS)|(1<<SPI_MISO);
   
  /*���������� spi,������� ��� ������,������, ����� 0*/
  SPCR = (0<<SPIE)|(1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(0<<SPR1)|(0<<SPR0);
  SPSR = (1<<SPI2X);
}

/*�������� ���� ������ �� SPI*/
void SPI_WriteByte(unsigned char data)
{
   SPDR = data; 
   while(!(SPSR & (1<<SPIF)));
}

/*�������� ���� ������ �� SPI*/
unsigned char SPI_ReadByte(void)
{  
   SPDR = 0xff;
   while(!(SPSR & (1<<SPIF)));
   return SPDR; 
}

/*�������� � �������� ���� ������ �� SPI*/
unsigned char SPI_WriteReadByte(unsigned char data)
{  
   SPDR = data;
   while(!(SPSR & (1<<SPIF)));
   return SPDR; 
}

/*��������� ��������� ���� ������ �� SPI*/
void SPI_WriteArray(unsigned char num, unsigned char *data)
{
   while(num--){
      SPDR = *data++;
      while(!(SPSR & (1<<SPIF)));
   }
}

/*��������� � �������� ��������� ���� ������ �� SPI*/
void SPI_WriteReadArray(unsigned char num, unsigned char *data)
{
   while(num--){
      SPDR = *data;
      while(!(SPSR & (1<<SPIF)));
      *data++ = SPDR; 
   }
}
