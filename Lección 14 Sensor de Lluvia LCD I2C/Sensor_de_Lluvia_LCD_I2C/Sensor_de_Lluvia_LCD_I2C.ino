/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
El sensor detectará la humedad y por el pin analógico se obtendran los valores entre 0-1023, los cuales
tendremos que manipular para registrar un porcentaje de humedad, que posteriormente
se visualizarán en la pantalla LCD.

Se requiere de la libreria LiquidCrystal_I2C y Wire
**************************/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define pin_on 7                    //pin 7 a pin del Sensor (+)
#define pin_signal A3               //pin analógico A3 a pin del Sensor(S)
float valor = 0;                    //Variable con valor 0
LiquidCrystal_I2C lcd(0x27, 16, 2); //Crear el objeto lcd dirección 0x27 y 16 columnas x 2 filas
void setup() {
  pinMode(pin_on, OUTPUT);          //configuración del pin 7 como salida
  digitalWrite(pin_on, LOW);        // El estado del sensor comienza en bajo -apagado
  lcd.init();                       //Inicializar el LCD
  lcd.backlight();                  //Encender la luz de fondo.
  lcd.print("Display I2C");         //Escribimos el Mensaje en el LCD
  delay(1000);
  lcd.clear();                     //limpiamos la pantalla para agregar nuevo mensaje
}
void loop() {
  digitalWrite(pin_on, HIGH);           //El estado del sensor es activado-ON
  delay(10);                            //espera 10 milisegundos
  valor = analogRead(pin_signal);       // la variable valor ahora tiene el dato registrado por el sensor
  float vneto = ((valor / 570) * 100);  //realizamos cálculo para obtener el porcentaje de los valor analógico 0 a 570 aprox
  digitalWrite(pin_on, LOW);             // el sensor se apagará y actualiza la inf
  lcd.setCursor(0, 0);                   //colocamos el cursor en la posición columna, fila (0,0)
  lcd.print("ADC:");                     //escribimos mensaje donde daremos a conocer el valor crudo de entrada del pin analógico
  lcd.print(valor);                      //impresión del valor
  lcd.setCursor(0, 1);                  //colocamos el cursor en la posición columna, fila (0,1)
  lcd.print("Humedad:");                //escribimos mensaje
  lcd.print(vneto);                     //impresión del valor en porcentaje
  lcd.print("%");                       //escribimos mensaje
  delay(1000);                           //esperamos 1 min para nueva medición
}
