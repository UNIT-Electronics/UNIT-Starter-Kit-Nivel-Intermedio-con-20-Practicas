// Librería de comunicación Wire y para unos del display LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int LM35 = A0; //Pin de entrada Analógico de datos del LM35
//Crear el objeto lcd dirección 0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); //
void setup() {
  lcd.init(); // Inicializar el LCD
  lcd.backlight(); //Encender la luz de fondo.
  lcd.print("LM35 Y DISPLAY "); // Escribimos el Mensaje en el LCD.
  delay(1000);
  lcd.clear(); //limpiamos la pantalla para agregar nuevo mensaje
}
void loop() {
  // la variable temperatura guardará el valor ADC del sensor
  int temperatura = analogRead(LM35);
  //cálculo para convertir el valor ADC a mV, 10mV/°C
  float millivolts = (temperatura / 1023.0) * 5000;
  float celsius = millivolts / 10; //Conversión de voltaje a grados celsius
  lcd.setCursor(0, 0); //colocamos el cursor en la posición columna, fila (0,0)
  lcd.print("ADC:"); //escribimos mensaje donde daremos a conocer el valor crudo de
  entrada del pin //analógico
  lcd.print(temperatura); //impresión del valor del sensor sin conversión
  lcd.setCursor(0, 1); //colocamos el cursor en la posición columna, fila (0,1)
  lcd.print("Celsius: "); //escribimos mensaje
  lcd.print(celsius); //impresión del valor de temperatura en celsius
  delay(1000); // esperamos 1 min para nueva medición
}
