/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24
*/
/********************************
Uso del registro de desplazamiento IC 74HC59 y una fotoresistencia, 
para realizar el control de 8 led´s 
********************************/


int latchPin = 5; // Pin conectado al Pin 12 del 74HC595 (Latch)
int clockPin = 7; // Pin conectado al Pin 11 del 74HC595 (Clock)
int dataPin = 6; // Pin conectado al Pin 14 del 74HC595 (Data)
int i = 0; //Variable para realizar conteo
//Combinación de bit por led del display de 7 segmentos realizando una secuencia
//desde 0 a la letra C: A, B, C, D, E, F, G, PUNTO DECIMAL
const byte numeros[14] = {
  B11111101, // = 0.
  B01100000, // = 1
  B11011010, // = 2
  B11110010, // = 3
  B01100110, // = 4
  B10110110, // = 5
  B10111110, // = 6
  B11100000, // = 7
  B11111110, // = 8
  B11100110, // = 9
  B11101110, // = A
  B00111110, // = B
  B10011101, // = C
};
void setup() {
  Serial.begin(9600);
  //Declaración de variables, como de salida digital
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
  for (i = 0; i < 14; i++) { //repetición de la secuencia de encendido y apagado de byte del 1 al 14
    //anteriormente declarada en la función números
    digitalWrite(latchPin, LOW); //desactiva a Reloj de Registro de Desplazamiento
    //función shifOut que nos ayudará a controlar al 74HC para desplazar el bit
    //indicando por que pin sale el bit (dataPin),cambio del pin una vez
    // que dataPin tenga el valor adecuado(clockPin), dirección de desplazamiento
    //(LSBFIRST o MSBFIRST) los datos que se desplazaran(leds)byte
    shiftOut(dataPin, clockPin, LSBFIRST, numeros[i]);
    digitalWrite(latchPin, HIGH); //activado el Reloj de Registro de Desplazamiento
    delay(1000); //espera de 1 segundo entre cada secuencia
  }
}
