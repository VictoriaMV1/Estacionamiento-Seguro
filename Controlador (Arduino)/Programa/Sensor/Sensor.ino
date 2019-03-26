#include <NewPing.h>

/*Pines del arduino que se van a conectar al sensor*/
#define Pin_Trigger_A 13
#define Pin_Echo_A 12

#define Pin_Trigger_B 5
#define Pin_Echo_B 4

#define Distancia_Maxima 450

/*Pines a leds*/
const int Rojo_A = 9;
const int Amarillo_A = 10;
const int Verde_A = 11;

const int Rojo_B = 6;
const int Amarillo_B = 7;
const int Verde_B = 8;

/*Se crea el objeto*/
NewPing Sensor_A(Pin_Trigger_A, Pin_Echo_A, Distancia_Maxima);
NewPing Sensor_B(Pin_Trigger_B, Pin_Echo_B, Distancia_Maxima);

void setup() {
  Serial.begin(9600);
  
  pinMode(Rojo_A, OUTPUT); /*Declarando que el pin 'Rojo' será de salida*/
  pinMode(Amarillo_A, OUTPUT);
  pinMode(Verde_A, OUTPUT);

  pinMode(Rojo_B, OUTPUT);
  pinMode(Amarillo_B, OUTPUT);
  pinMode(Verde_B, OUTPUT);
}

void loop() {
  //delay(350); /*Tiempo de espera entre mediciones*/
  int medicion_A = Sensor_A.ping_median(); /*Se toma la medición de tiempo de viaje de sonido*/
  int distancia_A = (medicion_A / US_ROUNDTRIP_CM); /*Cálculo de distancia en cm*/

  int medicion_B = Sensor_B.ping_median();
  int distancia_B = (medicion_B / US_ROUNDTRIP_CM);

  int distancia2_A = distancia_A * 10;
  int distancia2_B = distancia_B * 10;
  
  Serial.print(distancia2_A); 
  Serial.print(",");
  Serial.print(distancia2_B);
  Serial.print("+");

  digitalWrite(Rojo_A, LOW);
  digitalWrite(Amarillo_A, LOW);
  digitalWrite(Verde_A, LOW);

  digitalWrite(Rojo_B, LOW);
  digitalWrite(Amarillo_B, LOW);
  digitalWrite(Verde_B, LOW);
  
  if(distancia_A > 20){
    digitalWrite(Verde_A, HIGH);
  }
  else if(distancia_A > 10){
    digitalWrite(Amarillo_A, HIGH);
  }
  else{
    digitalWrite(Rojo_A, HIGH);
  }

    if(distancia_B > 20){
    digitalWrite(Verde_B, HIGH);
  }
  else if(distancia_B > 10){
    digitalWrite(Amarillo_B, HIGH);
  }
  else{
    digitalWrite(Rojo_B, HIGH);
  }
}
