/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.
  Fecha de revisión: 01/07/24
*/
/********************************
 Parpadeo de un led cada segundo 
 ********************************/



int ledPin=8;                        //Asignación pin 8 para led

void setup()
{
  pinMode(ledPin, OUTPUT);          //Se declara al "ledPin" como pin de salida
}

void loop()
{
  digitalWrite(ledPin, HIGH);       // Encendido del Led (HIGH marca el nivel de voltaje)
  delay(1000);                      //Permanecerá en este estado 1000 ms (1s)
  digitalWrite(ledPin, LOW);        //Apagado del Led (LOW marca el nivel de voltaje bajo)
  delay(1000);                      //Permanecerá en este estado 1000 ms (1s)
}
