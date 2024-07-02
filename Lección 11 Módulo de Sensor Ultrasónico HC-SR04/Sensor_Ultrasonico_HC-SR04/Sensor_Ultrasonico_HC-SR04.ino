/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
Deteccion de objetos a 50 cm, cuando los objetos y/o personas se
encuentren en un rango menor a esta distancia se activará el buzzer, emitiendo un pitido.
**************************/

int trig = 2;       // pin 2 a Trigger del sensor
int echo = 3;       // pin 3 a echo del sensor
int buzz = 9;       // pin 9 al buzzer
void setup() {
  Serial.begin (9600);      //Se inicia el puerto Serial
                            // Configuración de pines de salida
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  pinMode (buzz, OUTPUT);
}
void loop() {

  //Declaramos dos variables auxiliares para el cálculo de la distancia respecto al tiempo
  long tiempo;
  long distancia;
  digitalWrite(trig, LOW);       //El pin Trigger apagado empieza en el ciclo apagado
  delayMicroseconds(10);         //Pasan 10 microsegundos después...
  digitalWrite(trig, HIGH);      //El pin Trigger se enciende
  delayMicroseconds(10);         //Pasan 10 microsegundos después...
  digitalWrite(trig, LOW);       //El pin Trigger se apagará
  tiempo = pulseIn(echo, HIGH); //La variable tiempo guardará el valor que tarda en llegar
                                //al receptor de eco, ancho del pulso
  distancia = tiempo / 58;      //Hacemos la relación de la distancia en cm
                                //Programación del buzzer
  if (distancia <= 50) {        //Si la distancia es menor a 50 cm el buzzer se encenderá
    digitalWrite(buzz, HIGH);
    delay(500);
  } else {
    digitalWrite(buzz, LOW);
  }
  //Mostrará la distancia en el monitor serial (9600)
  Serial.print (distancia);
  Serial.println ("cm");
  delay (50);                   //se actualizará la información cada 50 ms
}
