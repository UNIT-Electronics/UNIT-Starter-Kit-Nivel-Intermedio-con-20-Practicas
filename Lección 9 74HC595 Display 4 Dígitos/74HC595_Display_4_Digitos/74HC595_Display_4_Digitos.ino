/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24
*/
/********************************
Control del display 4 dígitos 7 segmentos de forma que pueda mostrar y cambiar caracteres como HALO a 0000 o EEEE, por ejemplo. Utilizando el IC
74HC595 y la tarjeta UNO R3. 
********************************/

int latch = 9;                //Pin 9 al 12 (STCP) del 74HC595
int clockPin = 10;            //Pin 10 al 11 (SHCP) del 74HC595
int data = 8;                 //Pin 8 al 14 (DS) del 74HC595
//Matriz de codificación del display de 7 segmentos - hexadecimal
unsigned char table[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};
void setup() {                //inicializa pines de salida
  pinMode(latch, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(data, OUTPUT);
}
//Función Display en donde controlaremos el Latch del dato
void Display(unsigned char num) {
  digitalWrite(latch, LOW);
  shiftOut(data, clockPin, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
}
//impresión de los valores de la matriz dependiendo del orden que fueron agregados los datos
void loop() {
  Display(1);               //Se llama a la Función Display para mostrar el primer elemento de la matriz
  delay(2000);              //2 segundos de espera para comenzar cada instrucción
  Display(2);
  delay(2000);
  Display(3);
  delay(2000);
  Display(4);
  delay(2000);
  Display(5);
  delay(2000);
  Display(6);
  delay(2000);
  Display(7);
  delay(2000);
  Display(8);
  delay(2000);
  Display(9);
  delay(2000);
  Display(10);
  delay(2000);
  Display(11);
  delay(2000);
  Display(12);
  delay(2000);
  Display(13);
  delay(2000);
  Display(14);
  delay(2000);
  Display(15);
  delay(2000);
}