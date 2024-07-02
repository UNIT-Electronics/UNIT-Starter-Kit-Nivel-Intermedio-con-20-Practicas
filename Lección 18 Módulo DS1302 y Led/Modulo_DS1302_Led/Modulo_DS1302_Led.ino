/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
El programa es para encender el led en determinada hora y fecha; y se desactiva también con una fecha
predeterminada. Para fines didácticos sólo se maneja en el código la hora, para que puedas modificarla al
momento que realices la práctica prescindiendo del día que realices este programa.
Librería ThreeWire y RtcDS1302
**************************/


#include <ThreeWire.h>
#include <RtcDS1302.h>
#define countof(a) (sizeof(a) / sizeof(a[0])) //Definir datos de hora y fecha

ThreeWire myWire(4, 5, 2);                    //Pines asociados a la conexión del módulo con la tarjeta UNO R3: IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
bool alarma = true;                           //variable bool para activar o desactivar alarma
int led = 9;                                //lED Pin 9

void setup ()                               //Definición de variables de salida y comienzo de monitor serial y variable RTC
{
  Serial.begin(57600);
  Rtc.Begin();
  pinMode(led, OUTPUT);
}
void loop ()
{
  //Variable now guardará el valor de la fecha y hora actual
  RtcDateTime now = Rtc.GetDateTime(); 
  infoTiempo(now);
  //La variable ejecutará proceso en la función
  infoTiempo; 
  analogWrite(led, LOW); //El led siempre tendrá un valor bajo al iniciar el programa
}
//función infoTiempo que realizará la impresión de datos de hora y fecha
void infoTiempo(const RtcDateTime& dt)
{
  char datestring[20];
  snprintf_P(datestring, countof(datestring), PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  //configuración de activación de alarma a las 14hr y 47 min
  if (dt.Hour() == 14 && dt.Minute() == 47) {
    if (alarma = true) {
      Serial.println("Alarma");
      analogWrite(led, HIGH);
      alarma = false; //desactiva alarma
    }
  }
  Serial.println(datestring);
  delay(1000);
  //configuración desactivación de alarma a las 14hr y 49 min
  if (dt.Hour() == 14 && dt.Minute() == 49) analogWrite(led, LOW);
  alarma = true;
}