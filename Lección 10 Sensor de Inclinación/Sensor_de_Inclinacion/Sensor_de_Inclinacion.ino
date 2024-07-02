/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
El led encendera o apagara por la inclinacion del sensor
**************************/

const int LedPin = 8;      //Pin 8 que se conectará con el Led
void setup()
{
  pinMode(LedPin, OUTPUT);
}
void loop() 
{
  int i;
  while (1)                              //While para tener una instrucción bucle sin fin
  {
    i = analogRead(5);                    //La variable i tendrá lectura de los valores provenientes del pin 5 analógico
    if (i > 512)                         //rango ajustable de o a 1023, 512 tendremos una sensibilidad media en el sensor
    {
      digitalWrite(LedPin, LOW);          //El led apagará, en posición vertical del sensor
    }
    else
    {
      digitalWrite(LedPin, HIGH);          //El led se encenderá, en posición horizontal del sensor
    }
  }
}
