#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

#define SENSOR_PIN 18
#define BTN_UP 32
#define BTN_DOWN 33
#define BTN_SWITCH 27

#define AO_PHOTO 34
#define DIG_PHOTO 26
#define DHT11_PIN 4

#define BUZZER 15

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht11(DHT11_PIN, DHT11);

const int totalLines = 10;
const char* fanfiction[totalLines] = {
  "hello world, ",
  "it once said this ",
  "then it exploded... ",
  "sad very sad ",
  "then it revived ",
  "and then it found ",
  "its true love ",
  "... for more fanfics ",
  "like this dont forget ",
  "to share like and susc-",

};

const int MAXILINES = 5;
int lineaActual = 0;
bool modoPanic = false;

bool lastStateUp = HIGH;
bool lastStateDown = HIGH;
bool lastStateSwitch = HIGH;

void dibujarTexto();
void dibujarPanic();
void beep();


void setup() {
  Serial.begin(115200);

  //button
  
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SWITCH, INPUT_PULLUP);

  //led y buzzer
  pinMode(BUZZER, OUTPUT);

  //sensores
  pinMode(SENSOR_PIN, INPUT);
  pinMode(AO_PHOTO, INPUT);

  dht11.begin();


  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  oled.setCursor(0, 0);
  oled.setTextSize(1);      
  oled.setTextColor(WHITE); 

  dibujarTexto();
  
  delay(2000);
}

void loop() {

  bool buttonSwitch = digitalRead(BTN_SWITCH);
  int state = digitalRead(SENSOR_PIN);

  if (state == HIGH || (lastStateSwitch == HIGH && buttonSwitch == LOW)) {
    if (!modoPanic) {
      modoPanic = true;
      dibujarPanic();
      beep();
    }

  } else {
    if (modoPanic) {
      modoPanic = false;
      dibujarTexto();
    }
    delay(50);
  }
  lastStateSwitch = buttonSwitch;

// luces
  if (modoPanic){
    delay(20);
    return;
  }

  //botones
  bool up = digitalRead(BTN_UP);
  bool down = digitalRead(BTN_DOWN);

  if(lastStateUp == HIGH && up == LOW){
    if (lineaActual > 0){
      lineaActual--;
      dibujarTexto();
      beep();
    }

    delay(50);
  }

  lastStateUp = up;

  if(lastStateDown == HIGH && down == LOW){
    if (lineaActual < (totalLines - MAXILINES)){
      lineaActual++;
      dibujarTexto();
      beep();
    }

    delay(50);
  } 

  lastStateDown = down;

  delay(10);
}

void dibujarTexto(){
  oled.clearDisplay();
  oled.setCursor(0, 0);

  for(int i = 0; i < MAXILINES; i++){
    int indice = lineaActual + i;
    if(indice < totalLines){
      oled.println(fanfiction[indice]);
    }
  }

  int luz = analogRead(AO_PHOTO);

  oled.setCursor(0, 50);
  if (luz > 500){
    oled.println("Too much light");
  } else {
    oled.println("Light is ok!");
  }

 oled.display();
}

void dibujarPanic(){
  float tempC = dht11.readTemperature();

  oled.clearDisplay();
  oled.setCursor(0, 10);
  oled.println("--------------------");
  oled.println("Nothing to see here!");
  oled.println("--------------------");
  oled.println("Temp: ");
  oled.println(tempC);
  oled.println("C");

  oled.display();
}

void beep(){
  digitalWrite(BUZZER, HIGH);
  delay(30);
  digitalWrite(BUZZER, LOW);
}
