/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
Para cada dirección que tome el mando del joystick(arriba,abajo,derecha e izquierda), encenderá un led correspondiente. En 
caso de presionar el Joystick el buzzer activo emitirá un sonido.
**************************/

int SW_pin = 3;         // Pin 3 a SW(pushbutton) del joystick
int X_pin = A0;         // Pin Analogo A0 al pin VRX del joystick
int Y_pin = A1;         // Pin Análogo A 1 al pin VRY del joystick
int buzz = 5;           // PinPWM 5 al Buzzer +
int ledG = 6;           // PinPWM 6 al Led verde +
int ledR = 9;           // PinPWM 9 al Led rojo +
int ledW = 10;          // PinPWM 10 al Led ROJO+
int ledY = 11;          // PinPWM 11 al Led amarillo +
void setup() {
  //Declaración de variables, como de salida digital
  pinMode(SW_pin, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledY, OUTPUT);
  digitalWrite(SW_pin, HIGH); //lectura de botón del joystick por default estado:1=no
  Serial.begin(9600);         //presionado,0=presionado
  /*Velocidad de Puerto Serial,útil para ver la lectura de valores en el Monitor Serial*/
}
void loop() {
  //impresión de valores del joystick dependiendo el eje que sea manipulado
  Serial.print("Switch: ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(50);
  //Dependiendo los valores que el joystick, habrá condiciones para controlar los leds y buzzer
  if (digitalRead(SW_pin) == LOW) { //si es presionado el botón del joystick dará un valor 0
    digitalWrite(buzz, HIGH);      //por lo tanto el buzz emitirá un pitido
  } else {
    digitalWrite(buzz, LOW);        //de lo contrario estará en silencio
  }
  if (analogRead(X_pin) == 0) {    //inicialmente el eje x está en un valor de 523(aprox), si se
    //va a la extrema derecha..
    digitalWrite(ledG, HIGH);       //dará un valor 0 encendiendo el led verde
  } else {
    digitalWrite(ledG, LOW);
  } if (analogRead(X_pin) >= 600) { //cuando sea mayor a 600 , indica que se está moviendo
    //a la izquierda..
    digitalWrite(ledR, HIGH);       //el led rojo encenderá
  } else {
    digitalWrite(ledR, LOW);
  }
  if (analogRead(Y_pin) == 0) {     //inicialmente el eje y está en un valor de 523(aprox), si se
    //mueve hacia arriba..
    digitalWrite(ledW, HIGH);       //enciende el led ROJO
  } else {
    digitalWrite(ledW, LOW);
  }
  if (analogRead(Y_pin) >= 600) {   //cuando sea mayor a 600 , indica que se está moviendo
    //hacia arriba...
    digitalWrite(ledY, HIGH);      //se encendera el led amarillo
  } else {
    digitalWrite(ledY, LOW);
  }
}
