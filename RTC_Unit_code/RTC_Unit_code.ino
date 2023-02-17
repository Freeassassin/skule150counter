#include <Wire.h>
#include "RTClib.h"
#include <time.h>

RTC_DS1307 rtc;
const bool FORMAT_12=false;//if 12 hours set to true, for 24 hours set to false


double diff_time;

DateTime day150 = DateTime(2023, 2, 17, 0, 0, 0);

void setup () {
  
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
}

void loop () {
    DateTime now = rtc.now();
    
    diff_time = difftime(day150.unixtime(),now.unixtime());
    Serial.print(365-(diff_time/86400));

    Serial.println();
   
    delay(1000);
}