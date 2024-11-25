
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL1 13 
#define PIN_NEO_PIXEL2 12  
#define PIN_NEO_PIXEL3 11  
#define PIN_NEO_PIXEL4 10  

#define NUM_PIXELS 20    // The number of LEDs (pixels) on NeoPixel


Adafruit_NeoPixel strip1(NUM_PIXELS, PIN_NEO_PIXEL1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_PIXELS, PIN_NEO_PIXEL2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(NUM_PIXELS, PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(NUM_PIXELS, PIN_NEO_PIXEL4, NEO_GRB + NEO_KHZ800);


//encoder pins
#define enc_A 9
#define enc_B 8

#define enc_C 7
#define enc_D 6

#define enc_E 5
#define enc_F 4

#define enc_G 3
#define enc_H 2

#define GPin 14
#define WPin 15

int lastClk1 = HIGH;
int lastClk2 = HIGH;
int lastClk3 = HIGH;
int lastClk4 = HIGH;


int pixCTRL1 = 0;
int pixTarget1 = 10; //aka pixel 11
int pixCTRL2 = 0;
int pixTarget2 = 10;
int pixCTRL3 = 0;
int pixTarget3 = 10;
int pixCTRL4 = 0;
int pixTarget4 = 10;

int counter4 = 0;

int maxWait = 500;

int speed = 50;

bool gameComplete = false;
long unsigned currentTime;
long unsigned startingTime1;
unsigned long waitTime1 = 1000;
long unsigned startingTime2;
unsigned long waitTime2 = 1000;
long unsigned startingTime3;
unsigned long waitTime3 = 1000;
long unsigned startingTime4;
unsigned long waitTime4 = 1000;

void setup() {
  strip1.begin();  
  strip2.begin(); 
  strip3.begin(); 
  strip4.begin(); 

  Serial.begin(9600);
  pinMode(enc_A, INPUT_PULLUP); //clk1
  pinMode(enc_B, INPUT_PULLUP); //dt1
  pinMode(enc_C, INPUT_PULLUP); //clk2
  pinMode(enc_D, INPUT_PULLUP); //dt2
  pinMode(enc_E, INPUT_PULLUP); //clk3
  pinMode(enc_F, INPUT_PULLUP); //dt3
  pinMode(enc_G, INPUT_PULLUP); //clk4
  pinMode(enc_H, INPUT_PULLUP); //dt4
  pinMode(GPin, OUTPUT);
  pinMode(WPin, OUTPUT);

}

void loop() {
currentTime = millis();

/*
if (pixCTRL1 == pixTarget1)
{
  digitalWrite(GPin, HIGH);
}
else
{
  digitalWrite(GPin, LOW);
}
/*
if (pixCTRL2 == pixTarget2) 
{
  digitalWrite(RPin, HIGH);
}
else
{
  digitalWrite(RPin, LOW);
}
if (pixCTRL3 == pixTarget3)
{
  digitalWrite(BPin, HIGH);
}
else
{
  digitalWrite(BPin, LOW);
}

if (pixCTRL4 == pixTarget4)
{
  digitalWrite(WPin, HIGH);
}
else
{
  digitalWrite(WPin, LOW);
}
*/

if (gameComplete == false)
{

  if (pixCTRL1 == -1) {pixCTRL1 = NUM_PIXELS-1;} if (pixCTRL1 == NUM_PIXELS) {pixCTRL1 = 0;}
  if (pixCTRL2 == -1) {pixCTRL2 = NUM_PIXELS-1;} if (pixCTRL2 == NUM_PIXELS) {pixCTRL2 = 0;}
  if (pixCTRL3 == -1) {pixCTRL3 = NUM_PIXELS-1;} if (pixCTRL3 == NUM_PIXELS) {pixCTRL3 = 0;}
  if (pixCTRL4 == -1) {pixCTRL4 = NUM_PIXELS-1;} if (pixCTRL4 == NUM_PIXELS) {pixCTRL4 = 0;}





  if (currentTime - startingTime1 >= waitTime1) //resistive pixel timing
  {
    if (pixCTRL1 != 0) //don't move if it's already farthest away
    {
    if (pixCTRL1 > pixTarget1) {pixCTRL1++; } //move away from center
    else if (pixCTRL1 < pixTarget1) {pixCTRL1--;} //move away from center
    else 
    {
      if (random(0,2) == 1) {pixCTRL1++;} //on center, choose random direction
      else {pixCTRL1--;}
    }
    startingTime1 = currentTime; //reset time counter
    waitTime1 += speed; //make wait longer, moving away from target
    }
  }

  if (currentTime - startingTime2 >= waitTime2) //resistive pixel timing
  {
    if (pixCTRL2 != 0) //don't move if it's already farthest away
    {
    if (pixCTRL2 > pixTarget2) {pixCTRL2++; } //move away from center
    else if (pixCTRL2 < pixTarget2) {pixCTRL2--;} //move away from center
    else 
    {
      if (random(0,2) == 2) {pixCTRL2++;} //on center, choose random direction
      else {pixCTRL2--;}
    }
    startingTime2 = currentTime; //reset time counter
    waitTime2 += speed; //make wait longer, moving away from target

    }
  }

    if (currentTime - startingTime3 >= waitTime3) //resistive pixel timing
  {
    if (pixCTRL3 != 0) //don't move if it's already farthest away
    {
    if (pixCTRL3 > pixTarget3) {pixCTRL3++; } //move away from center
    else if (pixCTRL3 < pixTarget3) {pixCTRL3--;} //move away from center
    else 
    {
      if (random(0,2) == 2) {pixCTRL3++;} //on center, choose random direction
      else {pixCTRL3--;}
    }
    startingTime3 = currentTime; //reset time counter
    waitTime3 += speed; //make wait longer, moving away from target

    }
  }

  if (currentTime - startingTime4 >= waitTime4) //resistive pixel timing
  {
    if (pixCTRL4 != 0) //don't move if it's already farthest away
    {
    if (pixCTRL4 > pixTarget4) {pixCTRL4++; } //move away from center
    else if (pixCTRL4 < pixTarget4) {pixCTRL4--;} //move away from center
    else 
    {
      if (random(0,2) == 1) {pixCTRL4++;} //on center, choose random direction
      else {pixCTRL4--;}
    }
    startingTime4 = currentTime; //reset time counter
    waitTime4 += speed; //make wait longer, moving away from target
    Serial.print(pixCTRL4);
    Serial.print(waitTime4);
    Serial.println(": auto");
    }
  }

//game win condition
  if ((pixCTRL1 == pixTarget1 || pixCTRL1 == pixTarget1-1 || pixCTRL1 == pixTarget1+1) && (pixCTRL2 == pixTarget2 || pixCTRL2 == pixTarget2-1 || pixCTRL2 == pixTarget2+1) && (pixCTRL3 == pixTarget3|| pixCTRL3 == pixTarget3-1 || pixCTRL3 == pixTarget3+1) && (pixCTRL4 == pixTarget4 || pixCTRL4 == pixTarget4-1 || pixCTRL4 == pixTarget4+1)) {gameComplete = true;}

  /* ENCODER 1 */
    int newClk1 = digitalRead(enc_A); //take in the new value
    if (newClk1 != lastClk1)  // There was a change on the CLK pin
    {
      startingTime1 = currentTime; //new time for resistance
      lastClk1 = newClk1;
      int B_val = digitalRead(enc_B);
      if (newClk1 == LOW && B_val == HIGH) //CW
      {
        pixCTRL1++; if (pixCTRL1 ==  NUM_PIXELS) {pixCTRL1 = 0;}
        waitTime1 = maxWait + (abs(pixTarget1 - pixCTRL1)*speed);
      }
      if (newClk1 == LOW && B_val == LOW) //CCW
      {
        pixCTRL1--; if (pixCTRL1 == -1) {pixCTRL1 = NUM_PIXELS-1;}
        waitTime1 = maxWait + (abs(pixTarget1 - pixCTRL1)*speed);
      }
    }


    /* ENCODER 2 */
    int newClk2 = digitalRead(enc_C);
    if (newClk2 != lastClk2) // There was a change on the CLK pin
    {
      startingTime2 = currentTime;
      lastClk2 = newClk2;
      int D_val = digitalRead(enc_D);
      if (newClk2 == LOW && D_val == HIGH) //CW
      { 
        pixCTRL2++;  if (pixCTRL2 ==  NUM_PIXELS) {pixCTRL2 = 0;}
        waitTime2 = maxWait + (abs(pixTarget2 - pixCTRL2)*speed);
      }
      if (newClk2 == LOW && D_val == LOW) //CCW
      {  
        pixCTRL2--; if (pixCTRL2 == -1) {pixCTRL2 = NUM_PIXELS-1;}
        waitTime2 = maxWait + (abs(pixTarget2 - pixCTRL2)*speed);
      }
    }


      /* ENCODER 3 */
    int newClk3 = digitalRead(enc_E);
    if (newClk3 != lastClk3)  // There was a change on the CLK pin
    {
      startingTime3 = currentTime;
      lastClk3 = newClk3;
      int F_val = digitalRead(enc_F);
      if (newClk3 == LOW && F_val == HIGH) //CW
      {
        pixCTRL3++; if (pixCTRL3 ==  NUM_PIXELS) {pixCTRL3 = 0;}
        waitTime3 = maxWait + (abs(pixTarget3 - pixCTRL3)*speed);
      }
      if (newClk3 == LOW && F_val == LOW) //CCW
      {
        pixCTRL3--; if (pixCTRL3 == -1) {pixCTRL3 = NUM_PIXELS-1;}
        waitTime3 = maxWait + (abs(pixTarget3 - pixCTRL3)*speed);
      }
    }

      /* ENCODER 4 */
    int newClk4 = digitalRead(enc_G);
    if (newClk4 != lastClk4)  // There was a change on the CLK pin
    {
      startingTime4 = currentTime;
      lastClk4 = newClk4;
      int H_val = digitalRead(enc_H);
      if (newClk4 == LOW && H_val == HIGH) //turning CW
      {
        //CWcounter4++;
        //if (CWcounter4 == countTarget4)
        pixCTRL4++;  if (pixCTRL4 ==  NUM_PIXELS) {pixCTRL4 = 0;}
        waitTime4 = maxWait + (abs(pixTarget4 - pixCTRL4)*speed);
      }
      if (newClk4 == LOW && H_val == LOW) //CCW
      {
        pixCTRL4--; if (pixCTRL4 == -1) {pixCTRL4 = NUM_PIXELS-1;}
        waitTime4 = maxWait + (abs(pixTarget4 - pixCTRL4)*speed);
      }
    }
  //end encoder reads

  //Light LEDS
    strip1.clear(); strip2.clear(); strip3.clear(); strip4.clear();

    strip1.setPixelColor(pixTarget1, strip1.Color(0,10,0));
    strip1.setPixelColor(pixCTRL1, strip1.Color(0, 200, 0));
    strip1.setPixelColor(pixCTRL1-1, strip1.Color(0, 15, 0));
    strip1.setPixelColor(pixCTRL1+1, strip1.Color(0, 15, 0));
    
    strip2.setPixelColor(pixTarget2, strip2.Color(10,0,0));
    strip2.setPixelColor(pixCTRL2, strip2.Color(200, 0, 0));
    strip2.setPixelColor(pixCTRL2-1, strip2.Color(15, 0, 0));
    strip2.setPixelColor(pixCTRL2+1, strip2.Color(15, 0, 0));
    
    strip3.setPixelColor(pixTarget3, strip3.Color(0,0,10));
    strip3.setPixelColor(pixCTRL3, strip3.Color(0, 0, 200));
    strip3.setPixelColor(pixCTRL3-1, strip1.Color(0, 0, 15));
    strip3.setPixelColor(pixCTRL3+1, strip1.Color(0, 0, 15));
    
    strip4.setPixelColor(pixTarget4, strip4.Color(7,7,7));
    strip4.setPixelColor(pixCTRL4, strip4.Color(180, 180, 180));
    strip4.setPixelColor(pixCTRL4-1, strip4.Color(10, 10, 10));
    strip4.setPixelColor(pixCTRL4+1, strip4.Color(10, 10, 10));


    strip1.show(); strip2.show(); strip3.show(); strip4.show();
} //end game
else
{
   for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           
    strip1.setPixelColor(pixel, strip1.Color(0, 255, 0)); 
    strip2.setPixelColor(pixel, strip2.Color(255, 0, 0)); 
    strip3.setPixelColor(pixel, strip3.Color(0, 0, 255)); 
    strip4.setPixelColor(pixel, strip4.Color(255, 255, 255)); 
  }
    strip1.show(); strip2.show(); strip3.show(); strip4.show();
} //end game complete

       
}//end loop





/*

      // ENCODER 4 
    int newClk4 = digitalRead(enc_G);
    if (newClk4 != lastClk4)  // There was a change on the CLK pin
    {
      startingTime4 = currentTime;
      lastClk4 = newClk4;
      int H_val = digitalRead(enc_H);
      if (newClk4 == LOW && H_val == HIGH) //turning CW
      {
        pixCTRL4++; 
        if (pixCTRL4 > pixTarget4)// && pixCTRL4 != 0) //left side
        {
          waitTime4 += speed; //make wait longer, moving away from target
          //Serial.print(pixCTRL4);
          //Serial.print(waitTime4);
          //Serial.println(": add, left, CW");
        }
        else if (pixCTRL4 <= pixTarget4)// && pixCTRL4 != 0) //right side
        {
          waitTime4 -= speed;
           //Serial.print(pixCTRL4);
          //Serial.print(waitTime4);
          //Serial.println(": sub, right, CW");
          //Serial.println("subtracted!");
        }
        /*else 
        {
          waitTime4 -= speed;  
          Serial.print(pixCTRL4);
          Serial.print(waitTime4);
          Serial.println(": sub, zero"); 
          }
        if (pixCTRL4 == 16) {pixCTRL4 = 0;}
        
      }
      if (newClk4 == LOW && H_val == LOW) //CCW
      {
        pixCTRL4--; if (pixCTRL4 == -1) {pixCTRL4 = 15;}
        if (pixCTRL4 < pixTarget4) //&& pixCTRL4 != 0) //right side
        {
          waitTime4 += speed; //make wait longer, moving away from target
          // Serial.print(pixCTRL4);
          //Serial.print(waitTime4);
          //Serial.println(": add, right, CCW");
        }
        else if (pixCTRL4 >= pixTarget4) //&& pixCTRL4 != 0) //right side
        {
          waitTime4 -= speed;
           //Serial.print(pixCTRL4);
          //Serial.print(waitTime4);
          //Serial.println(": sub, left, CCW");
        }   
      }
*/