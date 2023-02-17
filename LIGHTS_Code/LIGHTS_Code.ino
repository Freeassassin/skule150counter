#include <stdbool.h>
#include <Wire.h>
#include "RTClib.h"
#include <time.h>

int hundredOne=13;
int fourFiveCommon=12; // pin for the common segments of 4 and 5
int fourA=11; // pin for final segment of 4
int fiveA=10; // pin for final two segments of 5
int nineZeroCommonA=22; // pin for common segments of 0 and 9 A
int nineZeroCommonB=23; // pin for common segments of 0 and 9 B
int nineA=24; // pin for final segment of 9
int zeroOnes=25; // pin for final segment of 0
int threeZeroCommonA = 26;  // pin for common segments 3 and 0
int threeZeroCommonB = 27;  // pin for common segments 3 and 0
int threeA = 28; // pin for final segment of 3
int zeroHundreds = 29; // pin for final segment of 0
int tens1=2;
int tens2=3;
int tens3=4;
int tens4=5;
int tens5=6;
int tens6=7;
int tens7=8;
int ones1=9;
int ones2=37;
int ones3=36;
int ones4=32;
int ones5=34;
int ones6=33;
int ones7=35;

bool isItOneFifty = false;


RTC_DS1307 rtc;
const bool FORMAT_12=false;//if 12 hours set to true, for 24 hours set to false


double diff_time;
int day, ones, tens;
DateTime day150 = DateTime(2023, 3, 29, 0, 0, 0);



// the setup function runs once when you press reset or power the board
void setup() {
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
  // rtc.adjust(DateTime(2023, 2, 16, 22, 28, 10));
  pinMode(tens1, OUTPUT);
  pinMode(tens2, OUTPUT);
  pinMode(tens3, OUTPUT);
  pinMode(tens4, OUTPUT);
  pinMode(tens5, OUTPUT);
  pinMode(tens6, OUTPUT);
  pinMode(tens7, OUTPUT);



  pinMode(ones1, OUTPUT);
  pinMode(ones2, OUTPUT);
  pinMode(ones3, OUTPUT);
  pinMode(ones4, OUTPUT);
  pinMode(ones5, OUTPUT);
  pinMode(ones6, OUTPUT);
  pinMode(ones7, OUTPUT);


  pinMode(hundredOne, OUTPUT);
  pinMode(fourFiveCommon, OUTPUT);
  pinMode(fourA, OUTPUT);
  pinMode(fiveA, OUTPUT);
  pinMode(nineZeroCommonA, OUTPUT);
  pinMode(nineZeroCommonB, OUTPUT);
  pinMode(nineA, OUTPUT);
  pinMode(zeroOnes, OUTPUT);
  pinMode(threeZeroCommonA, OUTPUT);
  pinMode(threeZeroCommonB, OUTPUT);
  pinMode(threeA, OUTPUT);
  pinMode(zeroHundreds, OUTPUT);


  digitalWrite(hundredOne,HIGH);
  digitalWrite(nineZeroCommonA,HIGH);
  digitalWrite(nineZeroCommonB,HIGH);


  digitalWrite(nineA,HIGH);


  digitalWrite(fourFiveCommon,HIGH);
  digitalWrite(fourA,HIGH);


  digitalWrite(threeZeroCommonA,HIGH);
  digitalWrite(threeZeroCommonB,HIGH);

  digitalWrite(threeA,HIGH);

}

// the loop function runs over and over again forever
void loop() {
  if (isItOneFifty) {

    digitalWrite(fiveA,HIGH);
    digitalWrite(fourA,LOW);
    digitalWrite(zeroOnes,HIGH);
    digitalWrite(nineA,LOW);

    digitalWrite(zeroHundreds,HIGH);
    digitalWrite(threeA,LOW);
    
  }else {
  digitalWrite(zeroOnes,LOW);  
  digitalWrite(nineA,HIGH);

  digitalWrite(fiveA,LOW);
  digitalWrite(fourA,HIGH);

  digitalWrite(zeroHundreds,LOW);
  digitalWrite(threeA,HIGH);    
  }
  
    DateTime now = rtc.now();
    
    diff_time = difftime(day150.unixtime(),now.unixtime());

    day = 365-(diff_time/86400);
    if (day >= 365) {
      day -= 365;
      isItOneFifty = true;
    }
    ones = day % 10;
    if (isItOneFifty) {
      tens = (day - ones)/10;
    } else{    
      tens = (day -300 -ones)/10;
      }

    onesDecoder(ones);
    tensDecoder(tens);
    Serial.println(day);
    Serial.println(ones);  
    Serial.println(tens);    
   
    delay(1000); 
}


void onesDecoder(int ones){
  switch(ones) {
    case 0:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, HIGH);
      digitalWrite(ones6, HIGH);
      digitalWrite(ones7, LOW);
    break;

    case 1:
      digitalWrite(ones1, LOW);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, LOW);
      digitalWrite(ones5, LOW);
      digitalWrite(ones6, LOW);
      digitalWrite(ones7, LOW);
      break;

    case 2:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, LOW);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, HIGH);
      digitalWrite(ones6, LOW);
      digitalWrite(ones7, HIGH);
    break;

    case 3:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, LOW);
      digitalWrite(ones6, LOW);
      digitalWrite(ones7, HIGH);
      break;

    case 4:
      digitalWrite(ones1, LOW);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, LOW);
      digitalWrite(ones5, LOW);
      digitalWrite(ones6, HIGH);
      digitalWrite(ones7, HIGH);
    break;

    case 5:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, LOW);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, LOW);
      digitalWrite(ones6, HIGH);
      digitalWrite(ones7, HIGH);
      break;

    case 6:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, LOW);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, HIGH);
      digitalWrite(ones6, HIGH);
      digitalWrite(ones7, HIGH);
    break;

    case 7:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, LOW);
      digitalWrite(ones5, LOW);
      digitalWrite(ones6, LOW);
      digitalWrite(ones7, LOW);
      break;

    case 8:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, HIGH);
      digitalWrite(ones6, HIGH);
      digitalWrite(ones7, HIGH);
    break;

    case 9:
      digitalWrite(ones1, HIGH);
      digitalWrite(ones2, HIGH);
      digitalWrite(ones3, HIGH);
      digitalWrite(ones4, HIGH);
      digitalWrite(ones5, LOW);
      digitalWrite(ones6, HIGH);
      digitalWrite(ones7, HIGH);
      break;


  }
}

void tensDecoder(int tens){

  switch(tens) {
    case 0:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, HIGH);
      digitalWrite(tens6, HIGH);
      digitalWrite(tens7, LOW);
    break;

    case 1:
      digitalWrite(tens1, LOW);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, LOW);
      digitalWrite(tens5, LOW);
      digitalWrite(tens6, LOW);
      digitalWrite(tens7, LOW);
      break;

    case 2:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, LOW);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, HIGH);
      digitalWrite(tens6, LOW);
      digitalWrite(tens7, HIGH);
    break;

    case 3:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, LOW);
      digitalWrite(tens6, LOW);
      digitalWrite(tens7, HIGH);
      break;

    case 4:
      digitalWrite(tens1, LOW);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, LOW);
      digitalWrite(tens5, LOW);
      digitalWrite(tens6, HIGH);
      digitalWrite(tens7, HIGH);
    break;

    case 5:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, LOW);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, LOW);
      digitalWrite(tens6, HIGH);
      digitalWrite(tens7, HIGH);
      break;

    case 6:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, LOW);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, HIGH);
      digitalWrite(tens6, HIGH);
      digitalWrite(tens7, HIGH);
    break;

    case 7:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, LOW);
      digitalWrite(tens5, LOW);
      digitalWrite(tens6, LOW);
      digitalWrite(tens7, LOW);
      break;

    case 8:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, HIGH);
      digitalWrite(tens6, HIGH);
      digitalWrite(tens7, HIGH);
    break;

    case 9:
      digitalWrite(tens1, HIGH);
      digitalWrite(tens2, HIGH);
      digitalWrite(tens3, HIGH);
      digitalWrite(tens4, HIGH);
      digitalWrite(tens5, LOW);
      digitalWrite(tens6, HIGH);
      digitalWrite(tens7, HIGH);
      break;

  }

}