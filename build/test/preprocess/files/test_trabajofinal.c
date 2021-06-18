#include "inc/trabajofinal.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"






void setUp(void) {



}



void tearDown(void) {

}



void test_inicio(void) {

    inicio();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((tempo)), (

   ((void *)0)

   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((bancont)), (

   ((void *)0)

   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((tarea)), (

   ((void *)0)

   ), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X00)), (UNITY_INT)(UNITY_INT8 )((bantrigger)), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X05)), (UNITY_INT)(UNITY_INT8 )((mili)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_HEX8);

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

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX8);

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

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0X03)), (UNITY_INT)(UNITY_INT8 )((tarea)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX8);

}



void test_char(void) {

    static char uartBuff[10];

    itoa(1, uartBuff, 10);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('1')), (UNITY_INT)(UNITY_INT8 )((uartBuff[0])), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_CHAR);

}
