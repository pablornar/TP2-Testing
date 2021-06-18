/*============================================================================
 * Autor: Narvaez Pablo
 * Licencia:
 * Fecha:17/06/2021
 *===========================================================================*/

//#include "sapi.h"        // <= Biblioteca sAPI
#include "trabajofinal.h"         // <= Su propia cabecera


// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
//int main(void) {
	/* ------------- INICIALIZACIONES ------------- */
	//boardConfig();	//inicializacion de placa
	//inicio();		//inicializacion

	/* Variable de Retardo no bloqueante */
	//delay_t Tm;
	//delay_t Ttarea;

	/* Inicializar Retardo no bloqueante con tiempo en milisegundos
	 (500ms = 0,5s) */
	//delayConfig(&Ttarea, 1);

	/* ------------- REPETIR POR SIEMPRE ------------- */
	//while (1) {
		//lecturateclado();
		//if (delayRead(&Ttarea)) { /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
		//	if (tempo == 1) {
				//delayConfig(&Ttarea, mili);
			//	tempo = 0;
		//	}
			//lecturaADC();
		//}
		//procesamiento();
		//enviodatos();
	//}
//	return 0;
//}


void inicio() {
	/* Inicializar UART_USB a 115200 baudios */
	//uartConfig(UART_USB, 230400);
	//uartConfig(UART_232, 230400);
	/* Inicializar AnalogIO */
	//adcConfig(ADC_ENABLE); /* ADC */

	/*Inicializacion de variables  */
	tempo = 0;
	bancont = 0;
	i = 0;
	tarea = 0;
	mili = 5;
	bantrigger = 0;
}

void lecturaADC() {
	if (tarea == 1) {
		if (bantrigger == 0) {
			muestra16[0] = adcRead[0];
			for (i = 1; i < 256; i++) {
				if ((i > 0) && (bantrigger == 0)) {
					muestra16[i] = adcRead[i];
					if (((muestra16[i] < 540) && (muestra16[i] > 482)) && (muestra16[i] > muestra16[i - 1])) {
						bantrigger = 1;
						muestra16[0] = muestra16[i];
						i = 255;
					}
				}
			}
			i = 1;
			
		}
		
		//bantrigger=1;
		if (bantrigger == 1) {
			//Leo la Entrada Analogica AI0 - ADC0 CH1 
			muestra16[i] = adcRead[i];
			i = i + 1;
			if (i == 256) {
				i = 0;
				bantrigger = 0;
				tarea = 2;
			}
		}
		
	}
}

/*
void lecturateclado() {
	if (tarea == 0) {
		if ((!gpioRead(TEC2)) == 1) {
			tempo = 1;
			mili = mili + 1;
			if (mili > 20) {
				mili = 20;
			}
		} else if ((!gpioRead(TEC3)) == 1) {
			tempo = 1;
			mili = mili - 1;
			if (mili < 2) {
				mili = 1;
			}
		}

		if (uartReadByte(UART_USB, &receivedByte)) {
			switch (receivedByte) {
			case 'a':
				tempo = 1;
				mili = mili + 1;
				if (mili > 20) {
					mili = 20;
				}
				break;
			case 'b':
				tempo = 1;
				mili = mili - 1;
				if (mili < 2) {
					mili = 1;
				}
				break;
			}
		}

		tarea = 1;
	}
}
*/

void procesamiento() {
	if (tarea == 2) {
		for (i = 0; i < 256; i++) {
			datos8[i] = (muestra16[i] * 256) / 1024;
		}
		i = 0;
		tarea = 3;
	}
}


/** FUNCION PARA CONVERTIR A ASCII CON BASE 10
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */
 
char* itoa(int value, char* result, int base) {
   // check that the base if valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}
/*
void enviodatos() {
	static char uartBuff[10];
	if (tarea == 3) {
		// Conversión de muestra entera a ascii con base decimal 
		itoa(muestra16[i], uartBuff, 10); // 10 significa decimal 
		uartWriteString(UART_USB, uartBuff);
		uartWriteByte(UART_232, datos8[i]);
		uartWriteString(UART_USB, "\r\n");
		i = i + 1;
		if (i == 256) {
			i = 0;
			tarea = 0;
		}
	}
}
*/