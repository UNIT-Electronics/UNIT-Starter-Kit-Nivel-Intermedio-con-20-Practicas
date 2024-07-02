/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
 Realizaremos el control de un motor de pasos por medio de la comunicación IR, 
en donde tendremos un receptor infrarrojo y emitiremos por medio de un
control remoto señales para que el motor realice 3 acciones.
Librería Stepper y IRremote
**************************/


#include <Stepper.h>
#include <IRremote.h>

#define PASOS 32                  //# de pasos por revolución en el eje
int AVANCE;                       //2048 = 1 revolución
int IR = 7;                       //Pin 7 donde recibirá la información del IR
/*Declaración de objetos para el motor e IR
Declaración de pines que tendrán conexión al motor*/
Stepper small_stepper(PASOS, 11, 10, 9, 8);
IRrecv irrecv(IR);                //creación de instancia 'irrecv'
decode_results datos;             //creación de instancia 'decode_datos'
void setup()
{
  Serial.begin(9600);             //Iniciando puerto serial en 9600 bauds
  irrecv.enableIRIn();            //Se habilita recepción de datos IR
}
void loop()
{
  Serial.println(datos.value, HEX);      //Impresión de valor recibido por IR
  delay(2000);                           //espera de 2 seg
  if (irrecv.decode(&datos))            //se ha recibido
  {
    switch (datos.value)                //operación switch/case para realizar una acción
    { 
/*Si se presiona el botón VOL+
Velocidad a la que rotara el motor
Rotara el motor en sentido de las manecillas del reloj*/
      case 0xFFA857:                     
        small_stepper.setSpeed(500);    
        AVANCE = 2048;                  
        small_stepper.step(AVANCE);
        delay(2000);
        break;
      case 0xFFE01F:                    
      /*Si se presiona el botón VOL-
      Velocidad a la que rotara el motor girara el motor en
      sentido contrario de las manecillas del reloj*/
        AVANCE = -2048;
        small_stepper.step(AVANCE);
        delay(2000);
        break;
/*Si se presiona el botón "0" cero
se apagaran todos los motores*/
      case 0xFF6897:                      
        digitalWrite(8, LOW);             
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);
        break;
    }
    irrecv.resume();             //recepción de nuevo valor IR
  }
}
