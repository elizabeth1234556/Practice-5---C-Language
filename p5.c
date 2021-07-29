
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#define OUTPUT 1
#define INPUT 0
#define ON 1
#define OFF 0
////////
#define PDDRA (int *)0x400FF014
#define PDORA (int *)0x400FF000

#define PDDRB (int *)0x400FF054
#define PDORB (int *)0x400FF040

#define PDDRC (int *)0x400FF094
#define PDORC (int *)0x400FF080

#define PDDRD (int *)0x400FF0D4
#define PDORD (int *)0x400FF0C0

#define PDDRE (int *)0x400FF114
#define PDORE (int *)0x400FF100
///////
	void pinMode(unsigned char puerto, int bit, unsigned char mode);
	void digitalWrite(unsigned char puerto, int bit, unsigned char data);

int main(void) {


   PRINTF("Practica5\n");


   	pinMode('B',18, OUTPUT);		//rojo	configurar
   	pinMode('B',19, OUTPUT);		//verde	configurar
   	pinMode('D',1, OUTPUT);		//azul	configurar


   	digitalWrite('B',18,ON);		//rojo apagar
   	digitalWrite('B',19,ON);		//verde apagar
   	digitalWrite('D',1,ON);		//azul apagar


   	digitalWrite('B',18,OFF);		//rojo prender
   	digitalWrite('B',19,OFF);		//verde prender
   	digitalWrite('D',1,OFF);	//azul prender


    return 0 ;
}
void pinMode(unsigned char puerto, int bit, unsigned char mode){

int *p2Pcr;					//apuntador a PCRn
int *p2Pddr;				//apuntador a PDDR


int *p2SCGC5; 				//apuntador a clock
p2SCGC5 = (int *)0x40048038;

		switch (puerto){
				case 'A':
					*p2SCGC5 = 0x200;
					p2Pcr = (int *) (0x40049000 + (bit*4));
					*p2Pcr = 0x100;
					p2Pddr =  PDDRA;
						if(mode == 1 ){
							*p2Pddr =  (1<<bit);
						}else{
							*p2Pddr = 0;
						}
				break;

				case 'B':
					*p2SCGC5 = 0x400;							//prende el reloj de puerto B
					p2Pcr =  (int *)(0x4004A000 + (bit*4));		//direccion inicial de B
					*p2Pcr = 0x100;   							// se configura como gpio(uso general)
					p2Pddr =  PDDRB;
						if(mode == 1 ){
							*p2Pddr =  (1<<bit);

						}else{
							*p2Pddr = 0;
						}
				break;

				case 'C':
					*p2SCGC5 = 0x800;
					p2Pcr = (int *)(0x4004B000 + (bit*4));
					*p2Pcr = 0x100;
					p2Pddr =  PDDRC;
						if(mode == 1 ){
							*p2Pddr =  (1<<bit);
						}else{
							*p2Pddr = 0;
						}
				break;

				case 'D':
					*p2SCGC5 = 0x1000;
					p2Pcr = (int *)(0x4004C000 + (bit*4));
					*p2Pcr = 0x100;
					p2Pddr =  PDDRD;
						if(mode == 1 ){
							*p2Pddr =  (1<<bit);
						}else{
							*p2Pddr = 0;
						}
				break;

				case 'E':
					*p2SCGC5 = 0x2000;
					p2Pcr = (int *)(0x4004D000 + (bit*4));
					*p2Pcr = 0x100;
					p2Pddr =  PDDRE;
						if(mode == 1 ){
							*p2Pddr =  (1<<bit);
						}else{
							*p2Pddr = 0;
						}
				break;
		}
}

void digitalWrite(unsigned char puerto, int bit, unsigned char data){
int *p2Pdor;

	switch (puerto){
			case 'A':
				p2Pdor = PDORA;
					if(data == 0 ){
						*p2Pdor = 0;
					}else{
						*p2Pdor = (1<<bit);
					}

			break;

			case 'B':
				p2Pdor = PDORB;
					if(data == 0 ){
						*p2Pdor = 0;
					}else{
					*	p2Pdor =  (1<<bit);
					}
			break;

			case 'C':
				p2Pdor = PDORC;
					if(data == 0 ){
						*p2Pdor = 0;
					}else{
						*p2Pdor =  (1<<bit);
					}
			break;

			case 'D':
				p2Pdor = PDORD;
					if(data == 0 ){
						*p2Pdor = 0;
					}else{
						*p2Pdor =  (1<<bit);
					}
			break;

			case 'E':
				p2Pdor = PDORE;
					if(data == 0 ){
						*p2Pdor = 0;
					}else{
						*p2Pdor =  (1<<bit);
					}
			break;
	}
}
