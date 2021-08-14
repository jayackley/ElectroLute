#include <Adafruit_NeoPixel.h>

#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
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
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093

int BRIGHTNESS  = 50;


const int rightmostRed = 7;
const int rightGrey = 6;
const int rightBlue = 5;

const int rightGreen = 4;
const int rightYellow = 3; 
const int rightRed = 2;

const int leftRed = A0;
const int leftYellow = A1;
const int leftGreen = A2;
const int leftBlue = A3;
const int leftGreyUp = A4;
const int leftGreyDown = A5;

const int grey = 10;


const int num_LEDS = 6;

char key;

int octave = 2;

Adafruit_NeoPixel strip_a = Adafruit_NeoPixel(num_LEDS, 11, NEO_GRB + NEO_KHZ800); 
 

int noteLength = 90;

int rightmostRedState;
int rightGreyState;
int rightBlueState;
int rightGreenState;
int rightYellowState;
int rightRedState;

int leftRedState;
int leftYellowState;
int leftGreenState;
int leftBlueState;
int leftGreyUpState;
int leftGreyDownState;

int greyState;

void setup() {
  pinMode(rightmostRed, INPUT_PULLUP);
  pinMode(rightGrey, INPUT_PULLUP);
  pinMode(rightBlue, INPUT_PULLUP);
  pinMode(rightGreen, INPUT_PULLUP);
  pinMode(rightYellow, INPUT_PULLUP);
  pinMode(rightRed, INPUT_PULLUP);
  
  pinMode(leftRed, INPUT_PULLUP);
  pinMode(leftYellow, INPUT_PULLUP);
  pinMode(leftGreen, INPUT_PULLUP);
  pinMode(leftBlue, INPUT_PULLUP);
  pinMode(leftGreyUp, INPUT_PULLUP);
  pinMode(leftGreyDown, INPUT_PULLUP);

  pinMode(grey, INPUT_PULLUP);
  
  Serial.begin(9600);
  strip_a.begin();
  strip_a.show();
  strip_a.setBrightness(BRIGHTNESS);
  strip_a.begin();
  strip_a.show();
  strip_a.setBrightness(BRIGHTNESS);
}

void loop() {

  
  
  // read the state of the pushbutton value:
  rightmostRedState = digitalRead(rightmostRed);
  rightGreyState = digitalRead(rightGrey);
  rightBlueState = digitalRead(rightBlue);
  rightGreenState = digitalRead(rightGreen);
  rightYellowState = digitalRead(rightYellow);
  rightRedState = digitalRead(rightRed);

  leftRedState = digitalRead(leftRed);
  leftYellowState = digitalRead(leftYellow);
  leftGreenState = digitalRead(leftGreen);
  leftBlueState = digitalRead(leftBlue);
  leftGreyUpState = digitalRead(leftGreyUp);
  leftGreyDownState = digitalRead(leftGreyDown);

  greyState = digitalRead(grey);

  // check if the pushbutton is pressed. If it is, the buttonState is LOW:

  if (greyState == LOW)
  {
    Serial.println("middlegreyPressed");
    //delay(500);
  }
  
  if (leftGreyUpState == LOW and leftGreyDownState == LOW)
  {
      octave = 4;
      Serial.println(octave);
      
  }
  else if (leftGreyUpState == LOW)
  {
    octave = 3;
    Serial.println(octave);
  }
  
  else if (leftGreyDownState == LOW)
  {
    octave = 1;
    Serial.println(octave);
  }

  else if (leftGreyUpState == HIGH and leftGreyDownState == HIGH)
  {
      octave = 2;
      Serial.println(octave);
      
    
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
    strip_a.setBrightness(BRIGHTNESS);
  }

  if (greyState == LOW && rightBlueState == LOW && BRIGHTNESS < 255)
  {
    BRIGHTNESS = BRIGHTNESS + 5;
    strip_a.setBrightness(BRIGHTNESS);
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

  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Play Highest High Notes

if (octave == 4){
//Root Note 
  if (rightRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(5, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F5);
    strip_a.setPixelColor(5, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(5, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(5, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(5, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(5, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(5, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(5, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(5, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(5, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C6);
    strip_a.setPixelColor(5, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Second note in pentatonic scale
 if (rightYellowState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_D5);
    
    strip_a.setPixelColor(4, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(4, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(4, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_C6);
    strip_a.setPixelColor(4, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_F5);
    strip_a.setPixelColor(4, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(4, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(4, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(4, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_FS5);
    strip_a.setPixelColor(4, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(4, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(4, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

 

//Third note in pentatonic scale
  
  if (rightGreenState == LOW) 
  {
    Serial.println("pressedrightgreen");
    if (key == 'C')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(3, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(3, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(3, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(3, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(3, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(3, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_CS6);
    strip_a.setPixelColor(3, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_FS5);
    strip_a.setPixelColor(3, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_GS5);
    strip_a.setPixelColor(3, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(3, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(3, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fourth note in pentatonic scale

  if (rightBlueState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(2, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_C6);
    strip_a.setPixelColor(2, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(2, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(2, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(2, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(2, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(2, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(2, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(2, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_FS6);
    strip_a.setPixelColor(2, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_G6);
    strip_a.setPixelColor(2, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fifth Note in pentatonic Scale

  if (rightGreyState == LOW) 
  {
    Serial.println("pressedrightgrey");
    if (key == 'C')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(1, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(1, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(1, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_G6);
    strip_a.setPixelColor(1, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_C6);
    strip_a.setPixelColor(1, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(1, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_FS6);
    strip_a.setPixelColor(1, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(1, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_CS6);
    strip_a.setPixelColor(1, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_A6);
    strip_a.setPixelColor(1, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_A6);
    strip_a.setPixelColor(1, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Octave

  if (rightmostRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C6);
    strip_a.setPixelColor(0, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F6);
    strip_a.setPixelColor(0, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G6);
    strip_a.setPixelColor(0, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A6);
    strip_a.setPixelColor(0, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(0, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(0, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A6);
    strip_a.setPixelColor(0, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D6);
    strip_a.setPixelColor(0, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E6);
    strip_a.setPixelColor(0, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B6);
    strip_a.setPixelColor(0, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C7);
    strip_a.setPixelColor(0, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    noTone(9);
    strip_a.clear();
    strip_a.clear();
  } 

}
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Play Medium High Notes

if (octave == 3){
//Root Note 
  if (rightRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(5, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F4);
    strip_a.setPixelColor(5, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(5, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(5, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(5, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(5, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(5, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(5, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(5, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(5, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(5, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Second note in pentatonic scale
 if (rightYellowState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_D4);
    
    strip_a.setPixelColor(4, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(4, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(4, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(4, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_F4);
    strip_a.setPixelColor(4, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(4, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(4, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(4, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_FS4);
    strip_a.setPixelColor(4, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(4, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(4, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

 

//Third note in pentatonic scale
  
  if (rightGreenState == LOW) 
  {
    Serial.println("pressedrightgreen");
    if (key == 'C')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(3, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(3, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(3, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(3, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(3, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(3, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_CS5);
    strip_a.setPixelColor(3, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_FS4);
    strip_a.setPixelColor(3, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_GS4);
    strip_a.setPixelColor(3, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(3, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(3, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fourth note in pentatonic scale

  if (rightBlueState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(2, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(2, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(2, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(2, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(2, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(2, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(2, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(2, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(2, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_FS5);
    strip_a.setPixelColor(2, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(2, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fifth Note in pentatonic Scale

  if (rightGreyState == LOW) 
  {
    Serial.println("pressedrightgrey");
    if (key == 'C')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(1, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(1, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(1, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(1, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(1, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(1, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_FS5);
    strip_a.setPixelColor(1, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(1, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_CS5);
    strip_a.setPixelColor(1, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(1, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(1, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Octave

  if (rightmostRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(0, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F5);
    strip_a.setPixelColor(0, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G5);
    strip_a.setPixelColor(0, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(0, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(0, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(0, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A5);
    strip_a.setPixelColor(0, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D5);
    strip_a.setPixelColor(0, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E5);
    strip_a.setPixelColor(0, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B5);
    strip_a.setPixelColor(0, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C6);
    strip_a.setPixelColor(0, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    noTone(9);
    strip_a.clear();
    strip_a.clear();
  } 

}
//////////////////////////////////////////////MiddleNotes~~~~~~~~~~~~~~~~~~~~~~~~~~
if (octave == 2){
//Root Note 
  if (rightRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C3);
    strip_a.setPixelColor(5, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F3);
    strip_a.setPixelColor(5, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(5, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(5, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(5, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(5, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(5, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(5, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(5, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(5, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(5, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Second note in pentatonic scale
 if (rightYellowState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_D3);
    
    strip_a.setPixelColor(4, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(4, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(4, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(4, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_F3);
    strip_a.setPixelColor(4, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(4, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(4, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(4, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_FS3);
    strip_a.setPixelColor(4, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(4, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(4, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

 

//Third note in pentatonic scale
  
  if (rightGreenState == LOW) 
  {
    Serial.println("pressedrightgreen");
    if (key == 'C')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(3, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(3, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(3, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(3, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(3, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(3, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_CS4);
    strip_a.setPixelColor(3, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_FS3);
    strip_a.setPixelColor(3, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_GS3);
    strip_a.setPixelColor(3, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(3, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(3, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fourth note in pentatonic scale

  if (rightBlueState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(2, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(2, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(2, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(2, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(2, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(2, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(2, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(2, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(2, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_FS4);
    strip_a.setPixelColor(2, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(2, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fifth Note in pentatonic Scale

  if (rightGreyState == LOW) 
  {
    Serial.println("pressedrightgrey");
    if (key == 'C')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(1, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(1, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(1, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(1, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(1, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(1, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_FS4);
    strip_a.setPixelColor(1, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(1, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_CS4);
    strip_a.setPixelColor(1, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(1, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(1, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Octave

  if (rightmostRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(0, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F4);
    strip_a.setPixelColor(0, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G4);
    strip_a.setPixelColor(0, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(0, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(0, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(0, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A4);
    strip_a.setPixelColor(0, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D4);
    strip_a.setPixelColor(0, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E4);
    strip_a.setPixelColor(0, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B4);
    strip_a.setPixelColor(0, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C5);
    strip_a.setPixelColor(0, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    noTone(9);
    strip_a.clear();
    strip_a.clear();
  } 

}



//////////////////////////////////////////////LowNotes~~~~~~~~~~~~~~~~~~~~~~~~~~
if (octave == 1){
//Root Note 
  if (rightRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C2);
    strip_a.setPixelColor(5, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F2);
    strip_a.setPixelColor(5, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G2);
    strip_a.setPixelColor(5, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(5, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D2);
    strip_a.setPixelColor(5, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E2);
    strip_a.setPixelColor(5, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(5, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D2);
    strip_a.setPixelColor(5, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E2);
    strip_a.setPixelColor(5, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B2);
    strip_a.setPixelColor(5, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C3);
    strip_a.setPixelColor(5, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Second note in pentatonic scale
 if (rightYellowState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_D2);
    
    strip_a.setPixelColor(4, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_G2);
    strip_a.setPixelColor(4, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(4, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_C3);
    strip_a.setPixelColor(4, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_F2);
    strip_a.setPixelColor(4, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_G2);
    strip_a.setPixelColor(4, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_B2);
    strip_a.setPixelColor(4, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_E2);
    strip_a.setPixelColor(4, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_FS2);
    strip_a.setPixelColor(4, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(4, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(4, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

 

//Third note in pentatonic scale
  
  if (rightGreenState == LOW) 
  {
    Serial.println("pressedrightgreen");
    if (key == 'C')
    {
    tone(8,NOTE_E2);
    strip_a.setPixelColor(3, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(3, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_B2);
    strip_a.setPixelColor(3, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(3, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_G2);
    strip_a.setPixelColor(3, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(3, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_CS3);
    strip_a.setPixelColor(3, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_FS2);
    strip_a.setPixelColor(3, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_GS2);
    strip_a.setPixelColor(3, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(3, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(3, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fourth note in pentatonic scale

  if (rightBlueState == LOW) 
  {
    Serial.println("pressedrightblue");
    if (key == 'C')
    {
    tone(8,NOTE_G2);
    strip_a.setPixelColor(2, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_C3);
    strip_a.setPixelColor(2, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(2, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(2, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(2, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_B2);
    strip_a.setPixelColor(2, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(2, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(2, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_B2);
    strip_a.setPixelColor(2, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_FS3);
    strip_a.setPixelColor(2, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(2, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Fifth Note in pentatonic Scale

  if (rightGreyState == LOW) 
  {
    Serial.println("pressedrightgrey");
    if (key == 'C')
    {
    tone(8,NOTE_A2);
    strip_a.setPixelColor(1, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(1, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(1, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(1, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_C3);
    strip_a.setPixelColor(1, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(1, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_FS3);
    strip_a.setPixelColor(1, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_B2);
    strip_a.setPixelColor(1, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_CS3);
    strip_a.setPixelColor(1, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(1, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(1, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    strip_a.clear();
    strip_a.clear();
  } 

//Octave

  if (rightmostRedState == LOW) 
  {
    Serial.println("pressedrightred");
    if (key == 'C')
    {
    tone(8,NOTE_C3);
    strip_a.setPixelColor(0, 255, 0, 0);
    }
    else if (key == 'F')
    {
    tone(8,NOTE_F3);
    strip_a.setPixelColor(0, 255, 255, 0);
    }
    else if (key == 'G')
    {
    tone(8,NOTE_G3);
    strip_a.setPixelColor(0, 0, 255, 0);
    }
    else if (key == 'a')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(0, 0, 0, 255);
    }
    else if (key == 'd')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(0, 0, 255, 255);  
    }
    else if (key == 'e')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(0, 255, 0, 255);  
    }
    else if (key == 'A')
    {
    tone(8,NOTE_A3);
    strip_a.setPixelColor(0, 128, 0, 255);  
    }
    else if (key == 'D')
    {
    tone(8,NOTE_D3);
    strip_a.setPixelColor(0, 0, 128, 255);  
    }
    else if (key == 'E')
    {
    tone(8,NOTE_E3);
    strip_a.setPixelColor(0, 255, 0, 128);  
    }
    else if (key == 'b')
    {
    tone(8,NOTE_B3);
    strip_a.setPixelColor(0, 255, 128, 128);  
    }
    else if (key == 'X')
    {
    tone(8,NOTE_C4);
    strip_a.setPixelColor(0, 255, 255, 255);  
    }
    strip_a.show();
    strip_a.show();
    delay(noteLength);
    noTone(8);
    noTone(9);
    strip_a.clear();
    strip_a.clear();
  } 

}

  noTone(8);
  strip_a.fill((0,0,0));
  strip_a.show();
  strip_a.fill((0,0,0));
  strip_a.show();
  
}
