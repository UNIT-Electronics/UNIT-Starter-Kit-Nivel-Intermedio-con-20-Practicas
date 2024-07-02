/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24
*/
/********************************
Se usará el buzzer pasivo para generar 8 notas básicas: Do (262Hz), Re (294Hz),
Mi (330Hz), Fa (349Hz), So (392Hz), La (440Hz), Si (494Hz) cada segundo
Se declaran las variables de las notas, con los valores de frecuencia
********************************/


int Do = 262, Re = 294, Mi = 330, Fa = 349, Sol = 392, La = 440, Si = 494, Do2 = 524;
int buzz = 12;              //Pin 12 para control del buzzer pasivo
int wait = 0;               //Variable para control de tiempo inicializada con valor 0
void setup()
{
  pinMode(buzz, OUTPUT);    //Inicialización del pin 12 como salida
}
void loop()
{
  wait = 500;               //Duración de cada una de las notas será de 500ms / .5 segundos
  tone(buzz, Do, wait);     //Generación de onda cuadrada en el pin 12, con valor de DO
  delay(1000);              //Espera 1s
  tone(buzz, Re, wait);     //Generación de onda cuadrada en el pin 12, con valor de RE
  delay(1000); 
  tone(buzz, Mi, wait);     //Generación de onda cuadrada en el pin 12, con valor de MI
  delay(1000);  
  tone(buzz, Fa, wait);    //Generación de onda cuadrada en el pin 12, con valor de FA
  delay(1000);  
  tone(buzz, Sol, wait);   //Generación de onda cuadrada en el pin 12, con valor de SOL
  delay(1000);  
  tone(buzz, La, wait);   //Generación de onda cuadrada en el pin 12, con valor de LA
  delay(1000);  
  tone(buzz, Si, wait);   //Generación de onda cuadrada en el pin 12, con valor de SI
  delay(1000);  
  tone(buzz, Do2, wait); //Generación de onda cuadrada en el pin 12, con valor de DO
  delay(1000);  
  noTone(buzz);          //Terminara la reproducción de sonido
}
