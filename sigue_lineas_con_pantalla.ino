#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //librerias para la pantala OLED

#define SCREEN_I2C_ADDR 0x3C // or 0x3C
#define OLED_RST_PIN -1      // Reset pin (-1 if not available)

#define FRAME_DELAY (42)
#define FRAME_WIDTH (64)
#define FRAME_HEIGHT (64)
#define FRAME_COUNT (sizeof(frames) / sizeof(frames[0]))

#define SCREEN_WIDTH 128 // Ancho de la pantalla OLED en píxeles
#define SCREEN_HEIGHT 64 // Alto de la pantalla OLED en píxeles

#define FRAME_DELAY (42)
#define FRAME_WIDTH (64)
#define FRAME_HEIGHT (64)
#define FRAME_COUNT (sizeof(frames) / sizeof(frames[0]))

// Declara una instancia del objeto de la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int IN1 = 2;
int IN2 = 4;
int ENA = 3;

int IN3 = 7;
int IN4 = 6;
int ENB = 5; //los 2 motores

int sensor1 = 8;
int sensor2 = 9; //sensores

//SCL = A5;
//SDA = A4;
#define time = 20;
int duty = 170;
int duty2 = 215;
int duty3 = 215;
int duty4 = 170;

unsigned long previousMillis = 0;
const long interval = 1000;
int contador;
int currentImage = 0;  

int valorSensor1 = 0; // valor obtenido del sensor // value obtained from the sensor
int valorSensor2 = 0; //valor del segundo sensor

void motor_apagado() { //motores se apagan

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  delay(20);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB, 0);
  delay(20);
}

void motor_atras(){ //motores se van para atras

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, duty);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB, duty4);
}

void motor_avanza(){ //motores avanzan

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, duty);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB, duty4);
}

void motor_derecha(){ //motores a la derecha

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, duty2);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB, duty2);
}

void motor_izquierda(){ //motores a la izquierda

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, duty2);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, duty2);
}