#include <Adafruit_NeoPixel.h>

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047


int BRIGHTNESS  = 50;


const int rightBlue = 5;
const int rightGreen = 4;
const int rightYellow = 3; 
const int rightRed = 2;

const int leftRed = A0;
const int leftYellow = A1;
const int leftGreen = A2;
const int leftBlue = A3;
const int grey = A5;


const int LEDsPin = 11;
const int num_LEDS = 4;

char key;

Adafruit_NeoPixel strip(num_LEDS, LEDsPin,NEO_GRB + NEO_KHZ400); 

int noteLength = 90;

int rightBlueState;
int rightGreenState;
int rightYellowState;
int rightRedState;

int leftRedState;
int leftYellowState;
int leftGreenState;
int leftBlueState;

int greyState;

void setup() {
  pinMode(rightBlue, INPUT_PULLUP);
  pinMode(rightGreen, INPUT_PULLUP);
  pinMode(rightYellow, INPUT_PULLUP);
  pinMode(rightRed, INPUT_PULLUP);
  
  pinMode(leftRed, INPUT_PULLUP);
  pinMode(leftYellow, INPUT_PULLUP);
  pinMode(leftGreen, INPUT_PULLUP);
  pinMode(leftBlue, INPUT_PULLUP);

  pinMode(grey, INPUT_PULLUP);
  
  Serial.begin(9600);
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
}

void loop() {

  
  
  // read the state of the pushbutton value:
  rightBlueState = digitalRead(rightBlue);
  rightGreenState = digitalRead(rightGreen);
  rightYellowState = digitalRead(rightYellow);
  rightRedState = digitalRead(rightRed);

  leftRedState = digitalRead(leftRed);
  leftYellowState = digitalRead(leftYellow);
  leftGreenState = digitalRead(leftGreen);
  leftBlueState = digitalRead(leftBlue);

  greyState = digitalRead(grey);

  // check if the pushbutton is pressed. If it is, the buttonState is LOW:

  if (greyState == LOW)
  {
    Serial.println("Pressed Grey");
    delay(20);
  }

  if (greyState == LOW && rightRedState == LOW && noteLength > 10)
  {
    noteLength = noteLength - 10;
    Serial.println(noteLength);
  }

  if (greyState == LOW && rightYellowState == LOW)
  {
    noteLength = noteLength + 10;
    Serial.println(noteLength);
  }

    if (greyState == LOW && rightGreenState == LOW && BRIGHTNESS > 0)
  {
    BRIGHTNESS = BRIGHTNESS - 5;
    strip.setBrightness(BRIGHTNESS);
  }

  if (greyState == LOW && rightBlueState == LOW && BRIGHTNESS < 255)
  {
    BRIGHTNESS = BRIGHTNESS + 5;
    strip.setBrightness(BRIGHTNESS);
  }
  

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Set Key

  if (leftRedState == LOW && leftYellowState == HIGH && leftGreenState == HIGH && leftBlueState == HIGH)
  {
    Serial.println("Pressed Left Red");
    key = 'C';
    Serial.println(key);
  }

  else if (leftYellowState == LOW && leftRedState == HIGH && leftGreenState == HIGH && leftBlueState == HIGH)
  {
    Serial.println("Pressed Left Yellow");
    key = 'F';
    Serial.println(key);
  }

  else if (leftGreenState == LOW && leftYellowState == HIGH && leftRedState == HIGH && leftBlueState == HIGH)
  {
    Serial.println("Pressed Left Green");
    key = 'G';
    Serial.println(key);
  }

  else if (leftBlueState == LOW && leftYellowState == HIGH && leftGreenState == HIGH && leftRedState == HIGH)
  {
    Serial.println("Pressed Left Blue");
    key = 'a';
    Serial.println(key);
  }


  else if (leftRedState == LOW && leftYellowState == LOW && leftGreenState == HIGH && leftBlueState == HIGH)
  {
    Serial.println("Pressed Left Red & Yellow");
    key = 'D';
    Serial.println(key);
  }
  

  else if (leftRedState == LOW && leftGreenState == LOW && leftYellowState == HIGH && leftBlueState == HIGH)
  {
    Serial.println("Pressed Left Red & Green");
    key = 'E';
    Serial.println(key);
  }

  
  else if (leftBlueState == LOW && leftYellowState == LOW && leftGreenState == HIGH && leftRedState == HIGH)
  {
    Serial.println("Pressed Left Blue & Yellow");
    key = 'd';
    Serial.println(key);
  }
  
  else if (leftBlueState == LOW && leftGreenState == LOW && leftRedState == HIGH && leftYellowState == HIGH)
  {
    Serial.println("Pressed Left Blue & Green");
    key = 'e';
    Serial.println(key);
  }
  
  else if (leftRedState == LOW && leftBlueState == LOW && leftGreenState == HIGH && leftYellowState == HIGH)
  {
    Serial.println("Pressed Left Red & Blue");
    key = 'A';
    Serial.println(key);
  }

  else if (leftRedState == LOW && leftYellowState == LOW && leftGreenState == LOW && leftBlueState == HIGH)
  {
    Serial.println("Pressed Left Red & Yellow & Green");
    key = 'b';
    Serial.println(key);
  }

  else if (leftRedState == LOW && leftYellowState == LOW && leftGreenState == LOW && leftBlueState == LOW)
  {
    Serial.println("Pressed Left Red & Yellow & Green & Blue");
    key = 'X';
    Serial.println(key);
  }

  

  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Play Note


//Root Note
  
  if (rightBlueState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_C4);
    strip.setPixelColor(3, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F4);
    strip.setPixelColor(3, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G4);
    strip.setPixelColor(3, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A4);
    strip.setPixelColor(3, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D4);
    strip.setPixelColor(3, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E4);
    strip.setPixelColor(3, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A4);
    strip.setPixelColor(3, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D4);
    strip.setPixelColor(3, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E4);
    strip.setPixelColor(3, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B4);
    strip.setPixelColor(3, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C5);
    strip.setPixelColor(3, 255, 255, 255);  
    }
    strip.show();
    delay(noteLength);
    noTone(8);
    strip.clear();
  } 

 //Fifth

  if (rightYellowState == LOW) 
  {
    Serial.println("pressedrightyellow");
    if (key == 'C')
    {
    tone(8,NOTE_G4);
    strip.setPixelColor(1, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_C5);
    strip.setPixelColor(1, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_D5);
    strip.setPixelColor(1, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_E5);
    strip.setPixelColor(1, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_A4);
    strip.setPixelColor(1, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_B4);
    strip.setPixelColor(1, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_E5);
    strip.setPixelColor(1, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_A4);
    strip.setPixelColor(1, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_B4);
    strip.setPixelColor(1, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_FS5);
    strip.setPixelColor(1, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_G5);
    strip.setPixelColor(1, 255, 255, 255);  
    }
    strip.show();
    delay(noteLength);
    noTone(8);
    strip.clear();
  } 

//Third
  
  if (rightGreenState == LOW) 
  {
    Serial.println("pressedrightgreen");
    if (key == 'C')
    {
    tone(8,NOTE_E4);
    strip.setPixelColor(2, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_A4);
    strip.setPixelColor(2, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_B4);
    strip.setPixelColor(2, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_C5);
    strip.setPixelColor(2, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_F4);
    strip.setPixelColor(2, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_G4);
    strip.setPixelColor(2, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_CS5);
    strip.setPixelColor(2, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_FS4);
    strip.setPixelColor(2, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_GS4);
    strip.setPixelColor(2, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_DS5);
    strip.setPixelColor(2, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_E5);
    strip.setPixelColor(2, 255, 255, 255);  
    }
    strip.show();
    delay(noteLength);
    noTone(8);
    strip.clear();
  } 



//Octave

  if (rightRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C5);
    strip.setPixelColor(0, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F5);
    strip.setPixelColor(0, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G5);
    strip.setPixelColor(0, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A5);
    strip.setPixelColor(0, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D5);
    strip.setPixelColor(0, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E5);
    strip.setPixelColor(0, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A5);
    strip.setPixelColor(0, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D5);
    strip.setPixelColor(0, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E5);
    strip.setPixelColor(0, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B5);
    strip.setPixelColor(0, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C6);
    strip.setPixelColor(0, 255, 255, 255);  
    }
    strip.show();
    delay(noteLength);
    noTone(8);
    strip.clear();
  } 
  
  if (rightRedState == HIGH && rightYellowState == HIGH && rightGreenState == HIGH && rightBlueState == HIGH)
  {
    noTone(8);
    strip.fill((0,0,0));
    strip.show();
  }
  
}
