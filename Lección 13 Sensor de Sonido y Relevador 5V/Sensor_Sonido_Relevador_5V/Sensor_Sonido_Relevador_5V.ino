/* Derechos de autor © UNIT Electronics
  Fecha de revisión: 01/07/24*/

/********************************
Detectaremos un sonido con el KY-037 para poder activar la conmutación del relevador.
Si los flancos de subida son igual a 4 activará al relevador para poder hacer la
conmutación de nivel BAJO a ALTO y poder mandar una señal al led y encenderlo, cuando
la detección de sonido sea igual a 8 flancos daremos la orden para apagar el led. 
**************************/


int AUDIO = 4;        //Pin 4 para la salida digital del KY
int flanco = 0;       //Variable de apoyo para saber la lectura del sensor
int rele = 8;         //Salida al relé en el Pin 8 del Arduino que activará a su vez el foco
void setup()
{
  Serial.begin(9600);      //Inicialización del puerto serial a 9600 baudios
  pinMode( AUDIO, INPUT) ; //pin del KY como entrada de datos
  pinMode( rele, OUTPUT) ; //pin 13 reley como pin de salida
}
void loop()
/*Si se detecta un sonido el KY(dependiente a la sensibilidad determinada por el usuario)*/
{ if (digitalRead(AUDIO) == HIGH ) 
  {
    flanco = flanco + 1;                         // Se realiza un contador +1 por cada vez que el sensor detecte //un flanco ALTO
    Serial.print("Número de Flancos: ");         //Escribe el número de flancos detectados dependiendo //el sonido censado...
    Serial.println(flanco, DEC) ;                // escribiendo el valor en forma decimal
    if (flanco == 4) {                            //Si el contador llega a 4, que es el valor anteriormente calibrado //a nuestro sistema
      Serial.println(flanco);                     //Escribe el valor del flanco=4 y...
      digitalWrite(rele, HIGH);                   //...se mantendrá encendido el led hasta que…
    } else if (flanco == 8) {                     //El contador esperara un nuevo sonido para desactivar el led y eso es cuando se llega al valor de flanco = 8
      Serial.println(flanco);                     //Escribe el valor del flanco=8 y...
      digitalWrite(rele, LOW);                    //...se apagará el led y ..
      flanco = 0;                                 //Se reiniciará el valor del flanco para que no se quede ningún valor guardado en flanco
    }
  }
}
