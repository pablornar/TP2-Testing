#include "build/test/mocks/mock_sapi.h"
#include "inc/trabajofinal.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"










void setUp(void) {

    uartConfig_CMockIgnore();

    adcConfig_CMockIgnore();

    gpioRead_CMockIgnoreAndReturn(12, 37);

    uartReadByte_CMockIgnoreAndReturn(13, 2);

    uartWriteString_CMockIgnore();

    uartWriteByte_CMockIgnore();

}



void tearDown(void) {

}









void test_inicio(void) {

    inicio();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((tempo)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((bancont)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((tarea)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((bantrigger)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X05)), (UNITY_INT)(UNITY_INT8 )((mili)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_HEX8);

}









void test_procesamiento(void) {

    int i;

    tarea=2;

    for(i=0;i<256;i++){

        muestra16[i]=0;

    }

    procesamiento();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((datos8[3])), (

   ((void *)0)

   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX8);

}









void test_procesamiento_256(void) {

    int i;

    tarea=2;

    for(i=0;i<256;i++){

        muestra16[i]=1020;

    }

    procesamiento();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0Xff)), (UNITY_INT)(UNITY_INT8 )((datos8[3])), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X03)), (UNITY_INT)(UNITY_INT8 )((tarea)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX8);

}









void test_char(void) {

    static char uartBuff[10];

    itoa(2, uartBuff, 10);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('2')), (UNITY_INT)(UNITY_INT8 )((uartBuff[0])), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_CHAR);

}









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

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x01)), (UNITY_INT)(UNITY_INT8 )((bantrigger)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_HEX8);

}
