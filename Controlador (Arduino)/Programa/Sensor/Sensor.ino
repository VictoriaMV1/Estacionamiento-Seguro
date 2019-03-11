#include <NewPing.h>

/*Pines del arduino que se van a conectar al sensor*/
#define Pin_Trigger 12
#define Pin_Echo 11
#define Distancia_Maxima 200

/*Pines a leds*/
const int Rojo = 8;
const int Amarillo = 9;
const int Verde = 10;

/*Se crea el objeto*/
NewPing Sensor(Pin_Trigger, Pin_Echo, Distancia_Maxima);

void setup() {
  Serial.begin(9600);
  pinMode(Rojo, OUTPUT); /*Declarando que el pin 'Rojo' será de salida*/
  pinMode(Amarillo, OUTPUT);
  pinMode(Verde, OUTPUT);
}

void loop() {
  delay(1000); /*Tiempo de espera entre mediciones*/
  int medicion = Sensor.ping_median(); /*Se toma la medición de tiempo de viaje de sonido*/
  int distancia = (medicion / US_ROUNDTRIP_CM); /*Cálculo de distancia en cm*/
  Serial.print("Distancia: ");
  Serial.print(distancia); 
  Serial.println("cm");

  digitalWrite(Rojo, LOW);
  digitalWrite(Amarillo, LOW);
  digitalWrite(Verde, LOW);
  
  if(distancia > 100){
    digitalWrite(Verde, HIGH);
  }
  else if(distancia > 30){
    digitalWrite(Amarillo, HIGH);
  }
  else{
    digitalWrite(Rojo, HIGH);
  }
}
