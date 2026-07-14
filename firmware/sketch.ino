#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

#define SENSOR_PIN 18 
#define BTN_UP 32
#define BTN_DOWN 33

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

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

const int MAXILINES = 6;
int lineaActual = 0;
bool pantallaApagada = false;

bool lastStateUp = HIGH;
bool lastStateDown = HIGH;

void dibujarTexto(){
  
  oled.clearDisplay();
  oled.setCursor(0, 0);

  for(int i = 0; i < MAXILINES; i++){
    int indice = lineaActual + i;
    if(indice < totalLines){
      oled.println(fanfiction[indice]);
    }
  }
 oled.display();
}

void setup() {
  Serial.begin(115200);

  pinMode(SENSOR_PIN, INPUT);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);

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

  int state = digitalRead(SENSOR_PIN);

  if (state == LOW){
    if(!pantallaApagada){
      oled.clearDisplay();
      oled.display();
      pantallaApagada = true;
    }
    delay(50);
    return;
  }
  else{
    if(pantallaApagada){
      pantallaApagada = false;
      dibujarTexto();
    }
  }

  bool up = digitalRead(BTN_UP);
  bool down = digitalRead(BTN_DOWN);

  if(lastStateUp == HIGH && up == LOW){
    if (lineaActual > 0){
      lineaActual--;
      dibujarTexto();
    }

    delay(50);
  }

  lastStateUp = up;

  if(lastStateDown == HIGH && down == LOW){
    if (lineaActual < (totalLines - MAXILINES)){
      lineaActual++;
      dibujarTexto();
    }

    delay(50);
  } 

  lastStateDown = down;

  delay(10);
}
