/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24
*/
/********************************
Control del encendido y apagado de un led por medio de push button
 ********************************/


int ledPin = 10;          //Pin 10 para el Led
int onApin = 9;           //Pin 9 para el push button que nos ayudará a encender el Led
int offBpin = 8;          //Pin 8 para el push button que nos ayudará a apagar el Led
byte leds = 0;           /*Se declara una variable leds para controlar en estado, actual del led (on/off)
                          Tipo byte (números que representan 8 bits)*/

void setup()
{
  pinMode(ledPin, OUTPUT); //Declaración del pin de salida a ledPin 
  /*Declaración de los push button en modo PULL UP ()*/
  pinMode(onApin, INPUT_PULLUP);
  pinMode(offBpin, INPUT_PULLUP);
}

void loop()
{
/*Realizaremos lectura onApin / offBpin y realizando acciones dependiendo el estado en que se encuentre*/
 
if (digitalRead(onApin) == LOW)
{
  digitalWrite(ledPin, HIGH);     //El led se encenderá
}
if (digitalRead(offBpin) == LOW)  //Si se presiona el botón del pin 8
{
  digitalWrite(ledPin, LOW);      //El led se apagará
}
}
