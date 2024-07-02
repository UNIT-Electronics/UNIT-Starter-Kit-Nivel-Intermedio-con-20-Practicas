/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24
*/
/********************************
Encendido y control de tono por medio de la tarjeta Uno R3
 ********************************/

int buzzer = 12;              // Pin 12 para el buzzer activo
void setup()
{
  pinMode(buzzer, OUTPUT);    //Declaración de pin de salida asignado al buzzer
}
void loop() {
  unsigned char i;            //Variable tipo carácter sin signo llamada "i" para simular una frecuencia
  for (i = 0; i < 80; i++) {   //Generación de frecuencia de pitidos
    digitalWrite(buzzer, HIGH); //El buzzer emitirá un pitido...
    delay(50); 
    digitalWrite(buzzer, LOW);  //El buzzer se apagará...
    delay(50); 
  }
  digitalWrite(buzzer, LOW);   //pausa de sonido...
  delay(5000);                 //por 5 segundos
}
