/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24
*/
/********************************
Demostracion del registro de desplazamiento IC 74HC59 para encender y
apagar 8 led´s utilizando 3 pines de la tarjeta UNO R3.
********************************/

int RCLKPin = 4;      //Pin 4-UNO R3 para el manejo del Reloj 74HC59 (Pin 12 RCLK del 74HCC595).
int SRCLKPin = 5;     //Pin 5-UNO R3 para el manejo del Reloj 74HC59 (Pin 11 SRCLK del 74HCC595).
int datoPin = 2;      //Pin 2-UNO R3 para entrada Serial del Dato (Pin 14 SER del 74HCC595).
/*Variable llamada leds con espacio de 8 bits, donde se guardará el patrón de encendido/apagado de leds*/
byte leds = 0;        
int nextLED = 0;      //Variable para detectar el byte en la variable leds
void setup()
{
  //Declaración de variables, como salidas digitales
  pinMode(RCLKPin, OUTPUT);
  pinMode(datoPin, OUTPUT);
  pinMode(SRCLKPin, OUTPUT);
  leds = 0;           //Inicialización del programa y de la variable tipo byte en 0
}
void loop()
{
  leds = 0;           //Limpieza del bucle de la variable byte en 0, para que el led encienda una vez
  if (nextLED == 7)   //Se comienza el corrimiento de los bits 0, si se llega a 7
  {
    nextLED = 0;      //Reiniciamos el avance en 0
  }
  else {
    nextLED++;         //De lo contrario seguirá avanzando hasta llegar a 8 bits
  }
  bitSet(leds, nextLED);           //Usará la función bitSet para el control de c/led dependiendo el avance del bit
  digitalWrite(RCLKPin, LOW);      // Pone en nivel bajo a latchPin durante la transmisión
  shiftOut(datoPin, SRCLKPin, MSBFIRST, leds);
  
  /*Función shiftOut para indicar que el pin saldrá el bit (dataPin, cambio del pin una vez que 
  dataPin tenga el valor adecuado(clockPin), dirección de desplazamiento (LSBFIRST o MSBFIRST) los 
  datos que se desplazaran*/

  digitalWrite(RCLKPin, HIGH);      // Devuelve el latchpin a nivel alto
  delay(1000);                      //Un segundo de tiempo para esta rutina
}
