
#include "unity.h"
#include "trabajofinal.h"
#include "mock_sapi.h"

#define TEC2 37
#define receivedByte  2

void setUp(void) {      //función de inicialización, que se llama antes de cada prueba;
    uartConfig_Ignore();            //ignora uartconfig
    adcConfig_Ignore();             //ignora adcConfig
    gpioRead_IgnoreAndReturn(TEC2); //ignora gpioRead       
    uartReadByte_IgnoreAndReturn(receivedByte); //ignora uartReadByte
    uartWriteString_Ignore();       //ignora uartWriteString
    uartWriteByte_Ignore();         //ignora uartWriteByte
}

void tearDown(void) { //llamado después de cada prueba;
}

/*
Testeo la configuracion inicial de las variables
*/
void test_inicio(void) {
    inicio();
    TEST_ASSERT_EQUAL_HEX8(0X00, tempo);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X00, bancont);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX16(0X0000, i);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X00, tarea);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X00, bantrigger);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X05, mili);  //compara si son iguales
}

/*
Testeo si el algoritmo de conversion a 8bits funciona correctamente con el valor 0x0000
*/
void test_procesamiento(void) {
    int i;
    tarea=2;
    for(i=0;i<256;i++){
        muestra16[i]=0;
    }
    procesamiento();
    TEST_ASSERT_EQUAL_HEX8(0X00, datos8[3]);  //compara si son iguales
}

/*
Testeo si el algoritmo de conversion a 8bits funciona correctamente con el valor 0x03fc
*/
void test_procesamiento_256(void) {
    int i;
    tarea=2;
    for(i=0;i<256;i++){
        muestra16[i]=1020;
    }
    procesamiento();
    TEST_ASSERT_EQUAL_HEX8(0Xff, datos8[3]);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X03,tarea);  //compara si son iguales
}

/*
Testeo si el algoritmo de conversion a ascii funciona correctamente con el valor de entrada de 2
*/
void test_char(void) {
    static char uartBuff[10];
    itoa(2, uartBuff, 10);
    TEST_ASSERT_EQUAL_CHAR('2',uartBuff[0]);  //compara si son iguales
}

/*
Testeo si el trigger ocurre con dos valores creciente y en la ventana de paso
*/
void test_trigger(void) {
    int j;
    tarea=1;
    bantrigger=0;
    for(j=0;j<256;j++){
        adcRead[j]=0;
    }
    adcRead[10]=492;
    adcRead[11]=500;
    lecturaADC();
    TEST_ASSERT_EQUAL_HEX8(0x01,bantrigger);  //compara si son iguales
}