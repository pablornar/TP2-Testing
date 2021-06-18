
#include "unity.h"
#include "trabajofinal.h"


void setUp(void) {      //función de inicialización, que se llama antes de cada prueba;
   
}

void tearDown(void) { //llamado después de cada prueba;
}

void test_inicio(void) {
    inicio();
    TEST_ASSERT_EQUAL_HEX8(0X00, tempo);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X00, bancont);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX16(0X0000, i);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X00, tarea);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X00, bantrigger);  //compara si son iguales
    TEST_ASSERT_EQUAL_HEX8(0X05, mili);  //compara si son iguales
}