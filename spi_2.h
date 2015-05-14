#ifndef SPI_H
#define SPI_H

#include <avr/io.h>

#define SPI_PORTX   PORTB
#define SPI_DDRX    DDRB

#define SPI_MISO   6 
#define SPI_MOSI   5
#define SPI_SCK    7
#define SPI_SS     4

/*_______________ ������� ____________________*/


/*��������� SPI ����������*/
#define SPI_DisableSS_m(ss)  do{SPI_PORTX |= (1<<(ss)); }while(0)

/*��������� SPI ����������*/
#define SPI_EnableSS_m(ss)   do{SPI_PORTX &= ~(1<<(ss)); }while(0)

/*������ SPI ����������*/
#define SPI_StatSS_m(ss)    (!(SPI_PORTX & (1<<(ss))))

/*�������� ���� ������ �� SPI*/
#define SPI_WriteByte_m(data)  do{ SPDR = data; while(!(SPSR & (1<<SPIF))); }while(0)

/*��������� ���� ������ �� SPI*/
#define SPI_ReadByte_m(data)  do{ SPDR = 0xff; while(!(SPSR & (1<<SPIF))); data = SPDR;}while(0)


/* ______________ ������������ ������� _____________*/


/*�������� ���� ������ �� SPI*/
inline static unsigned char SPI_ReadByte_i(void){
   SPDR = 0xff;
   while(!(SPSR & (1<<SPIF)));
   return SPDR;   
}

/*  _________________ ������� ________________ */

/*������������� SPI ������*/
void SPI_Init(void); 

/*��������� ���� ������ �� SPI*/
void SPI_WriteByte(unsigned char data); 

/*�������� ���� ������ �� SPI*/
unsigned char SPI_ReadByte(void);

/*��������� � �������� ���� ������ �� SPI*/
unsigned char SPI_WriteReadByte(unsigned char data);

/*��������� ��������� ���� ������ �� SPI*/
void SPI_WriteArray(unsigned char num, unsigned char *data);

/*��������� � �������� ��������� ���� ������ �� SPI*/
void SPI_WriteReadArray(unsigned char num, unsigned char *data);


#endif //SPI_H
