//Name: Taller 5
//Authors: Kevin Gutierrez Gomez, Gonzalo García Hernandez, Duvan Cardona Gutiérrez y Juan Pablo Castaño Duque
//Date: 04/09/2017
//Description: Sistema de monitoreo de temperatura por medio de displays 7 segmentos y LED RGB.

//Etiquetado de pines de entrada y salida
#define LV 3  //LED verde del led RGB conectado al pin PWM 3
#define LA 2  //LED azul del led RGB conectado al pin PWM 2
#define LR 1  //LED rojo del led RGB conectado al pin PWM 1

//Pines que representan el display de 7 segmentos
#define pA 2
#define pB 3
#define pC 4
#define pD 5
#define pE 6
#define pF 7
#define pG 8

//Pin del sensor de temperatura conectado a la placa
#define sensorTemp 9

void int2seg(unsigned int num)  //Función que toma un numero entero y lo convierte a BCD
{
  switch (num)
  {
    case 0:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, LOW);
      break;

    case 1:
      digitalWrite(pA, LOW);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, LOW);
      digitalWrite(pG, LOW);
      break;

    case 2:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, LOW);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, LOW);
      digitalWrite(pG, HIGH);
      break;

    case 3:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, LOW);
      digitalWrite(pF, LOW);
      digitalWrite(pG, HIGH);
      break;

    case 4:
      digitalWrite(pA, LOW);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;

    case 5:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, LOW);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, LOW);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;

    case 6:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;

    case 7:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, LOW);
      digitalWrite(pG, LOW);
      break;

    case 8:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;

    case 9:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, HIGH);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;
  }
}

//Configuracion
void setup() {
  
  //Decir si el pin es de entrada o salida
  
  //Pines de salida
  pinMode(LV, OUTPUT);  //Led verde del RGB como salida
  pinMode(LA, OUTPUT);  //Led azul del RGB como salida
  pinMode(LR, OUTPUT);  //Led rojo del RGB como salida
  pinMode(pA, OUTPUT);  //LEDs del displays 7 segmentos como salida (pA, pB, ...)
  pinMode(pB, OUTPUT);
  pinMode(pC, OUTPUT);
  pinMode(pD, OUTPUT);
  pinMode(pE, OUTPUT);
  pinMode(pF, OUTPUT);
  pinMode(pG, OUTPUT);

  //Pines de entrada
  pinMode(sensorTemp, INPUT); //Sensor de temperatura como entrada

  //Limpieza de salidas digitales
  digitalWrite(LV, LOW);  //Apago LED verde
  digitalWrite(LA, LOW);  //Apago LED azul
  digitalWrite(LR, LOW);  //Apago LED rojo
  digitalWrite(pA, LOW);  //Apago todos los LEDs del display 7 segmentos
  digitalWrite(pB, LOW);
  digitalWrite(pC, LOW);
  digitalWrite(pD, LOW);
  digitalWrite(pE, LOW);
  digitalWrite(pF, LOW);
  digitalWrite(pG, LOW);

  //Comunicaciones
  Serial.begin(9600); //Inicio comm seriales con el PC a 9600 bauds

}

//Ejecucion
void loop() {

  //Lee el valor de temperatura
  int value = analogRead(sensorTemp);

  //Convierte el valor leido en milivoltios
  float millivolts = (value / 1023.0) * 5000;

  //Convierte la temperatura de milivoltios a celsius
  int celsius = millivolts / 10;  

  //Obtiene el segundo dígito de la temperatura dada en celsius
  int ultimoDigito = celsius % 10;

  //Activa el display con el número correspondiente (Segundo dígito de la temperatura)
  int2seg(ultimoDigito);

  //Condición en la cual se determina que color encender con el LED RGB
  /*
   * Amarillo si temperatura <= 28
   * Naranja si temperatura > 30 y temperatura <= 32
   * Rojo si temperatura > 32
   */ 
  if(celsius <= 28){

    analogWrite(LR, 255);
    analogWrite(LV, 201);
    analogWrite(LA, 14);
    
  }else if(celsius > 30 && celsius <= 32){

    analogWrite(LR, 255);
    analogWrite(LV, 128);
    analogWrite(LA, 0);
    
  }else if(celsius > 32){

    analogWrite(LR, 255);
    analogWrite(LV, 0);
    analogWrite(LA, 0);
    
  }

  //Detiene la ejecución tres segundos
  delay(3000);
  
}

