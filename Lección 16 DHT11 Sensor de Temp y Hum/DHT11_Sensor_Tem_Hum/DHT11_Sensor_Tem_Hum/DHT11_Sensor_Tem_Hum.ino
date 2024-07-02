/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
El sensor DHT detectara temperatura y humedad ambiental, los datos directamente se presentaran en  
la pantalla LCD 16X2. Librería del sensor DHT y para el display LCD
**************************/


#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTTYPE 11              //Definimos el modelo DHT11
#define DHTPIN 8                //Se define el pin para conectar el sensor
float h, t;                     //variables para guardar el dato de humedad y temperatura del sensor
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); //Crear el objeto lcd dirección 0x27 y 16 columnas x 2 filas
void setup() {
  dht.begin();                      //Se inicia la dht, con la definición de modelo y pin
  lcd.init();                       // Inicializar el LCD
  lcd.backlight();                  //Encender la luz de fondo.
  lcd.print("DHT11 Y DISPLAY ");    //Escribimos el Mensaje en el LCD.
  delay(1000);                      //limpiamos la pantalla para agregar nuevo mensaje
  lcd.clear();
}
void loop() {
  h = dht.readHumidity();           //se guarda en la variable h el valor de humedad
  t = dht.readTemperature();        //se guarda en la variable t el valor de temperatura
  lcd.setCursor(0, 0);               //colocamos el cursor en la posición columna, fila (0,0)
  lcd.print("Humedad: ");            //se visualiza el texto
  lcd.print(h);                       //se visualiza el dato de humedad
  lcd.setCursor(0, 1);                //colocamos el cursor en la posición columna, fila (0,1)
  lcd.print("Temp: ");                //se visualiza el texto
  lcd.print(t);                        //impresión del valor de temperatura
  lcd.print("C");                     //escribimos mensaje
  delay(1000);                        // esperamos 1 min para nueva medición
}
