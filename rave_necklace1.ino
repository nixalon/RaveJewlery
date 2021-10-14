#include <Adafruit_NeoPixel.h>
#include <IRremote.h>

#define LED_PIN 7
#define LED_COUNT 24

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  strip.begin();
  strip.show();
}

int pixel;

void one(){  
  strip.setPixelColor(pixel, 255, 0, 0);
  strip.show();
  strip.clear();
  pixel++;
  if(pixel == 24){
    pixel = 0;
  }
}

void two(){
  strip.setPixelColor(pixel, 0, 255, 0);
  strip.show();
  delay(200);
  strip.clear();
  pixel++;
  if(pixel == 24){
    pixel = 0;
  }
}

void three(){
  strip.setPixelColor(pixel, 0, 0, 255);
  strip.show();
  delay(200); 
  strip.clear();
  pixel++;
  if(pixel == 24){
    pixel = 0;
  }
}

void four(){
  
  if (pixel%3 == 0){
    strip.clear();
    strip.setPixelColor(pixel, 255, 192, 203);
    strip.setPixelColor((pixel + 1), 255, 192, 203);
    delay(200); 
  }
  strip.show();
  pixel++;
  if(pixel == 24){
    pixel = 0;
  }
}

void five(){
  
  if (pixel%3 == 0){
    strip.clear();
    strip.setPixelColor(pixel, 255, 255, 0);
    strip.setPixelColor((pixel + 1), 255, 255, 0);
    delay(200); 
  }
  strip.show();
  pixel++;
  if(pixel == 24){
    pixel = 0;
  }
}

void six(){
  
  if (pixel%3 == 0){
    strip.clear();
    strip.setPixelColor(pixel, 255, 0, 255);
    strip.setPixelColor((pixel + 1), 255, 0, 255);
    delay(200); 
  }
  strip.show();
  pixel++;
  if(pixel == 24){
    pixel = 0;
  }
}

void seven(){
  while(pixel < 24){
    if (pixel % 2 == 0){
      strip.setPixelColor(pixel, 0, 0, 0);
      delay(200); 
    }
    if (pixel % 2 == 1){
      strip.setPixelColor(pixel, 0, 0, 0);
      delay(200); 
    }
     
    strip.show();
    strip.clear();
    pixel++;
  } 
  
  if(pixel == 24){
    pixel = 0;
  }
  
}

int count;

void eight(){

  if (count == 0){
    if(pixel < 4 || (8 < pixel && pixel < 16) || pixel > 20 ){
      strip.setPixelColor(pixel, 255, 0, 0);
      strip.show();
      strip.clear();
    }
  pixel++;
  }
  if (count == 1){
    if(pixel < 4 || (8 < pixel && pixel < 16) || pixel > 20 ){
      strip.setPixelColor(pixel, 0, 255, 0);
      strip.show();
      strip.clear();
    }
  pixel++;
  }  
  if (count == 2){
    if(pixel < 4 || (8 < pixel && pixel < 16) || pixel > 20 ){
      strip.setPixelColor(pixel, 0, 0, 255);
      strip.show();
      strip.clear();
    }
  pixel++;
  }
    if(pixel == 24){
    pixel = 0;
    count++;
  }
  if (count > 2){
    count = 0;
  }
}

int r = 5;
int g = 5;
int b = 5; 

void nine(){
  strip.clear();
  
  r += 5;
  if (r >= 255){
    r = 0;
    g += 5;
  }
  if (g >= 255){
    g = 0;
    b += 5;
  }
  if (b >= 255){
    b = 0;
    r += 5;
  }
  
  strip.setPixelColor(pixel, r, g, b);
  strip.show();
  pixel++;
  
  if(pixel == 24){
    pixel = 0;
  }
}

void off(){
  strip.clear();
  strip.show();
}

int selectedButton;	

void loop(){
  if (irrecv.decode(&results)) {
  	Serial.println(results.value, HEX);
    irrecv.resume();
    if(results.value == 0xFD08F7){
      selectedButton = 1;
    }
    if(results.value == 0xFD8877){
      selectedButton = 2;
    }
    if(results.value == 0xFD48B7){
      selectedButton = 3;
    }
    if(results.value == 0xFD28D7){
      selectedButton = 4;
    }
    if(results.value == 0xFDA857){
      selectedButton = 5;
    }
    if(results.value == 0xFD6897){
      selectedButton = 6;
    }
    if(results.value == 0xFD18E7){
      selectedButton = 7;
    }
    if(results.value == 0xFD9867){
      selectedButton = 8;
    }
    if(results.value == 0xFD58A7){
      selectedButton = 9;
    }
    if(results.value == 0xFD00FF){
      selectedButton = 0;
    }
  }
  
  if (selectedButton == 1){
    one();
  }
  if (selectedButton == 2){
    two();
  }
  if (selectedButton == 3){
    three();
  }
  if (selectedButton == 4){
    four();
  }
  if (selectedButton == 5){
    five();
  }
  if (selectedButton == 6){
    six();
  }
  if (selectedButton == 7){
    seven();
  }
  if (selectedButton == 8){
    eight();
  }
  if (selectedButton == 9){
    nine();
  }
  if (selectedButton == 0){
    off();
  }
  
  delay(100);
}