/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
#include "stdint.h"                     //para agregar lo de uint16_t

uint8_t tempo;
uint8_t bancont;
uint16_t muestra16[300];
uint16_t adcRead[300];
uint8_t datos8[300];
uint16_t i;
uint8_t tarea;
uint8_t mili;
uint8_t bantrigger;

void inicio(void);
//void lecturateclado(void);
//void lecturaADC(void);
//void enviodatos(void);
void procesamiento(void);
char* itoa(int value, char* result, int base);
