void setup(){

Wire.begin();

  // Inicializa la pantalla OLED con la dirección I2C 0x3C (puedes cambiarla si es necesario)
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error al inicializar la pantalla OLED"));
    for(;;);
  }

  // Limpia el buffer de la pantalla
display.clearDisplay();

  // Establece el tamaño del texto
display.setTextSize(1);

  // Establece el color del texto (blanco)
display.setTextColor(SSD1306_WHITE);

Serial.begin(9600);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENB, OUTPUT);

pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
}

void loop(){

valorSensor1 = digitalRead(sensor1);
valorSensor2 = digitalRead(sensor2);

// Serial.print(valorSensor1);
// Serial.print(" :valor: ");
// Serial.print(valorSensor2);
// Serial.print(" / ");
// Serial.print(currentImage);
// Serial.println("");

if(valorSensor1 == 0 && valorSensor2 == 0) {
  motor_avanza();
  display.clearDisplay();
  display.drawBitmap(0, 0, cara1, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();
  }

if(valorSensor1 == 1 && valorSensor2 == 0) {
  motor_izquierda();
    //delay(duty3);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    if (currentImage == 0) {
      currentImage = 1;
    } 
    else {
      currentImage = 0;
    }

    display.clearDisplay();
    if (currentImage == 0) {
        display.clearDisplay();
        display.drawBitmap(0, 0, cara2, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
        display.display();
   }
    else {    
        display.clearDisplay();
        display.drawBitmap(0, 0, cara3, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
        display.display();
    }
 }
}
if(valorSensor1 == 0 && valorSensor2 == 1) {
  motor_derecha();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (currentImage == 0) {
      currentImage = 1;
    } 
    else {
      currentImage = 0;
    }

    display.clearDisplay();

      if (currentImage == 0) {
        display.clearDisplay();
        display.drawBitmap(0, 0, cara2, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
        display.display();
      }
      else {    
        display.clearDisplay();
        display.drawBitmap(0, 0, cara3, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
        display.display();
      }
 }
}

if(valorSensor1 == 1 && valorSensor2 == 1) {
  motor_apagado();   
  display.clearDisplay(); 
  display.drawBitmap(0, 0, cara1, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();
  }
}
