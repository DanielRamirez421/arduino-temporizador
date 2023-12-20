# Temporizador para encender un relé

Este proyecto de Arduino implementa un temporizador que enciende un relé en un rango de tiempo especificado. El intervalo de hora es configurable y se puede simular el tiempo para que corra más rápido.

## Configuración

El código utiliza las siguientes variables para configurar el temporizador:

String `startTime` = "18:00:00";
String `endTime`   = "23:59:00";

## Simulación del tiempo

El código incluye una bandera llamada `isTimeSimulated` que permite habilitar la simulación del tiempo. Si esta bandera está activada, el tiempo avanzará siendo cada minuto un milisegundo, permitiendo simular intervalos de encedido y apagado del relé

## Consideraciones

No olvidar instalar las librerías:
- `https://github.com/JChristensen/DS3232RTC`
- `https://github.com/janelia-arduino/Streaming`

Para configurar el reloj a la hora actual y para compilar y subir el código del temporizador al arduino.
