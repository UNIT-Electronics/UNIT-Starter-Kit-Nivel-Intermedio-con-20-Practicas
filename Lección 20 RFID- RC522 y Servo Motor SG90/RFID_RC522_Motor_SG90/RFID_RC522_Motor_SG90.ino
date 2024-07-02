/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
 Realizaremos el control de un motor de pasos por medio de la comunicación IR, 
en donde tendremos un receptor infrarrojo y emitiremos por medio de un
control remoto señales para que el motor realice 3 acciones.
Librería SPI,MFRC522 y Servo, para poder utilizar el RDFI-RC522, ServoMotor SG90 y protocolo de comunicación SPI
*************************/


#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define RST_PIN 5                   //Pin del RDFI-RC522 a Pin 5
#define SS_PIN 10                   //Pin del RDFI-RC522 a Pin 10
Servo sg90;
MFRC522 mfrc522(SS_PIN, RST_PIN);   //Creando instancia para RFID
byte i;                             //variable , elemento de matriz de lectura de datos por el lector
/*matriz para guardar valores arrojados por el detector, Valor hexadecimal al usar el llavero <previamente comprobado>, 
puede variar.Valor hexadecimal al usar la tarjeta <previamente comprobado>, puede variar*/

byte datoUID[4];                   
byte llavero[4] = {0xBC, 0x73, 0x9F, 0x63};
byte tag[4] = {0x33, 0xF0, 0x20, 0x0D};
void setup() {
  Serial.begin(9600);               //Inicializa comunicación serial
  SPI.begin();                      //Iniciación de comunicación por bus SPI
  sg90.attach(3);                   //Pin para la señal al servo-Pin 3
  sg90.write(0);                    //Siempre que se inicie el programa el servo tendrá un valor de 0°
  mfrc522.PCD_Init();               //inicialización de MFRC522
  Serial.println(F("Coloque tarjeta para realizar escaner")); //mensaje para usuario
}
void loop() {
  //Reinicia el ciclo si no hay detección de tarjeta
  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;
  //Lee el valor del ID presentado
  if ( ! mfrc522.PICC_ReadCardSerial())
    return;
  Serial.println("UID:");
  //Se guarda los datos del ID
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    //limitando la lectura de los valores en la matriz hexadecimal a 10 dígitos
    if (mfrc522.uid.uidByte[i] < 0x10) {
      Serial.print("0");
    } else {
      Serial.print("");
    }
    //imprime en Monitor Serial, el valor leído por el detector
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    datoUID[i] = mfrc522.uid.uidByte[i];        //Se guardan los valores en la variable dato UID
  }
  mfrc522.PICC_HaltA();
  if (datoUID[i] != llavero[i]) {               //Si la lectura corresponde a los valores de la matriz tarjeta[]
    Serial.println("Tarjeta");
    for (int j = 0; j <= 180; j++) {            //sentido antihorario abre
      sg90.write(j);                            //se dará el valor del ángulo de 0 a 180 incrementando
      delay(5);                                 //realiza el movimiento más rápido 5 milisegundo
    }
  }
  }
  
