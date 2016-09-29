/*
 *Hello
 *This is the first Trial of my First Ever Project
 *It's an alarm clock that supports multiple alarms in a day
 *and holds different alarms for different days
 *it displays current day, date and time and also next alarm time on a 16*2 LCD screen
 *It also shows the message"Alarm ringing" when the cuurent time matches the alarm time
 *For the purposes of this demo all this information might not fit on the LCD so I will comment out the information that will not fit
 *I will also use a buzzer to simulate the ringing of the sounder because a sounder is expensive and my funds are limited
 *For the final project I will use a bigger LCD, probably a 20*4 LCD.
 *Welcome to My First Ever Project!
 */
 
//First we include the libraries 
#include <LiquidCrystal.h>
#include "RTClib.h"
#include <Wire.h> //this is because we communicate via I2C

//Next we initialise all our pins
int alarmPin = 9;
LiquidCrystal lcd(12,11,5,4,3,2); //we have given our screen the name "lcd"
RTC_DS3231 timer;                //we have given our rtc the name "timer"

//Now I will declare my variables
int yr;
int mnth;
int dt;
int dy;
int alarmday;
int hr;
int alarmhr;
int alarmhour [12];
int mnte ;
int alarmmnte ;
int alarmminute [12];
char* actualDay;
int rounds;
int scnd;
int shortyr;
char* shortDay ;
int km ;



char daysoftheWeek [7][12] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; //a 7*12 array for 7 days against 12 months
char shortdaysoftheWeek [7][12] = {"Sun","Mon","Tue","Wed","Thurs","Fri","Sat"};//we initialize short days so that it fits on the LCD



void setup() {
//we begin our processes
  timer.begin();
  lcd.begin(16,2); 
  pinMode(alarmPin,OUTPUT);
  Serial.begin(9600); //This is for debugging purposes

}

//I like to declare my functions before I go into loop


void powerLoss(){
  if(timer.lostPower()){
    Serial.println ("Lost Power.Resetting the time");
    lcd.clear();
    lcd.print("Resetting");
    timer.adjust(DateTime(F(__DATE__), F(__TIME__)));
   //This sets an explicit Date and Time
   //F() is a pre-written macro that accesses the flash memory
   //so when you put the date and time parameters, it calculates lost hours since the program was compiled
   //It then uses this data to calculate the current date and time 
   delay(1000);
   lcd.clear();
   delay(1000);
    }
  }

  
void timeFunction(){
   DateTime now = timer.now();
   yr = now.year();
   shortyr = yr-2000;
   mnth = now.month();
   dt = now.day();  //date
   dy = now.dayOfTheWeek();
   actualDay = daysoftheWeek[dy]; //char* is a char array of 20 characters
   hr = now.hour();
   mnte = now.minute();
   scnd = now.second();
   shortDay = shortdaysoftheWeek[dy];

  }

 
 void lcdUI(){
  //First we show the time
  lcd.setCursor(3,0);
  
  if(hr<10){
  lcd.print("0");
  lcd.print(hr);
    }
  else{
  lcd.print(hr);
    }
  lcd.print(":");
  
  if(mnte<10){
  lcd.print("0");
  lcd.print(mnte);
  }

  else{
   lcd.print(mnte); 
    }
  lcd.print(":");

  if(scnd<10){
  lcd.print("0");
  lcd.print(scnd);
  }
  else{
  lcd.print(scnd);
    }
  
  lcd.setCursor(1,1); //Shift cursor to line 2 so that we show day and date
  lcd.print(shortDay);
  lcd.print("-");
  
  if(dt<10){
  lcd.print("0");
  lcd.print(dt);//take 1 or 2 columns
  }
  else{
    lcd.print(dt);
    }
  lcd.print("/");   //takes 1 column
  
  if(mnth<10){
  lcd.print("0");
  lcd.print(mnth); //takes 1 or 2 columns
    }
  else{
    lcd.print(mnth);
    }
  lcd.print("/"); //takes 1 column
  lcd.print(shortyr); //takes 2 columns
           
  
  lcd.setCursor(0,0);
  }
 //The purpose of the if functions above is to make sure that no number appears as single digit

 void Alarm (){
 
 
  
  if (dy==1){ //Monday
    alarmday=1;
    
    alarmhour[0] = 8;   alarmminute [0] = 0;
    alarmhour[1] = 8;   alarmminute [1] = 40;
    alarmhour[2] = 9;   alarmminute [2] = 0;
    alarmhour[3] = 9;   alarmminute [3] = 40;
    alarmhour[4] = 10;  alarmminute [4] = 0;
    alarmhour[5] = 10;  alarmminute [5] = 20;
    alarmhour[6] = 10;  alarmminute [6] = 50;
    alarmhour[7] = 11;  alarmminute [7] = 10;
    alarmhour[8] = 12;  alarmminute [8] = 0;
    alarmhour[9] = 14;  alarmminute [9] = 30;
    alarmhour[10]=15;   alarmminute[10] = 10;
    alarmhour[11]=16;   alarmminute[11] = 10;
   
    }
    else if (dy==2){ //Tuesday
      alarmday =2;
      
    alarmhour[0] = 8;   alarmminute [0] = 0;
    alarmhour[1] = 8;   alarmminute [1] = 40;
    alarmhour[2] = 9;   alarmminute [2] = 0;
    alarmhour[3] = 9;   alarmminute [3] = 40;
    alarmhour[4] = 10;  alarmminute [4] = 0;
    alarmhour[5] = 10;  alarmminute [5] = 20;
    alarmhour[6] = 10;  alarmminute [6] = 50;
    alarmhour[7] = 11;  alarmminute [7] = 10;
    alarmhour[8] = 12;  alarmminute [8] = 0;
    alarmhour[9] = 14;  alarmminute [9] = 30;
    alarmhour[10]=15;   alarmminute[10] = 10;
    alarmhour[11]=17;   alarmminute[11] = 03;
      }

  else if (dy==3){ //Wednesday
    alarmday = 3;
    
    alarmhour[0] = 8;   alarmminute [0] = 0;
    alarmhour[1] = 8;   alarmminute [1] = 40;
    alarmhour[2] = 9;   alarmminute [2] = 0;
    alarmhour[3] = 9;   alarmminute [3] = 40;
    alarmhour[4] = 13;  alarmminute [4] = 57;
    alarmhour[5] = 13;  alarmminute [5] = 59;
    alarmhour[6] = 14;  alarmminute [6] = 00;
    alarmhour[7] = 14;  alarmminute [7] = 01;
    alarmhour[8] = 12;  alarmminute [8] = 0;
    alarmhour[9] = 14;  alarmminute [9] = 30;
    alarmhour[10]= 15;  alarmminute[10] = 10;
    alarmhour[11]= 16;  alarmminute[11] = 10;
    }

    else if(dy==4){ //Thursday
    alarmday = 4;
    
    alarmhour[0] = 8;   alarmminute [0] = 0;
    alarmhour[1] = 8;   alarmminute [1] = 40;
    alarmhour[2] = 9;   alarmminute [2] = 0;
    alarmhour[3] = 9;   alarmminute [3] = 40;
    alarmhour[4] = 10;  alarmminute [4] = 0;
    alarmhour[5] = 10;  alarmminute [5] = 20;
    alarmhour[6] = 10;  alarmminute [6] = 50;
    alarmhour[7] = 11;  alarmminute [7] = 10;
    alarmhour[8] = 12;  alarmminute [8] = 0;
    alarmhour[9] = 14;  alarmminute [9] = 30;
    alarmhour[10]=15;   alarmminute[10] = 10;
    alarmhour[11]=16;   alarmminute[11] = 10;
      }
      else if(dy==5){ //Friday
    alarmday = 5;
        
    alarmhour[0] = 8;   alarmminute [0] = 0;
    alarmhour[1] = 8;   alarmminute [1] = 40;
    alarmhour[2] = 9;   alarmminute [2] = 0;
    alarmhour[3] = 9;   alarmminute [3] = 40;
    alarmhour[4] = 10;  alarmminute [4] = 0;
    alarmhour[5] = 10;  alarmminute [5] = 20;
    alarmhour[6] = 10;  alarmminute [6] = 50;
    alarmhour[7] = 11;  alarmminute [7] = 10;
    alarmhour[8] = 12;  alarmminute [8] = 0;
    alarmhour[9] = 14;  alarmminute [9] = 30;
    alarmhour[10]=15;   alarmminute[10] = 10;
    alarmhour[11]=16;   alarmminute[11] = 10;
        }


        else if(dy==6){ //Saturday
    alarmday = 6;   

    alarmhour[0] = 8;   alarmminute [0] = 0;
    alarmhour[1] = 8;   alarmminute [1] = 40;
    alarmhour[2] = 9;   alarmminute [2] = 0;
    alarmhour[3] = 9;   alarmminute [3] = 40;
    alarmhour[4] = 10;  alarmminute [4] = 0;
    alarmhour[5] = 10;  alarmminute [5] = 20;
    alarmhour[6] = 10;  alarmminute [6] = 50;
    alarmhour[7] = 11;  alarmminute [7] = 10;
    alarmhour[8] = 12;  alarmminute [8] = 0;
    alarmhour[9] = 14;  alarmminute [9] = 30;
    alarmhour[10]=15;   alarmminute[10] = 10;
    alarmhour[11]=16;   alarmminute[11] = 10;
          }
          else{}
       
       
       for(km=0;km<12;km++){
        Serial.println(km);
       if(dy == alarmday && alarmhour[km] == hr && alarmminute[km] == mnte){
        delay(30);
       ringAlarm();
        }
        else {}
        }
        }

  void ringAlarm(){
    
    if(rounds <=7){
    
    Serial.println("Ringing Alarm");
    lcd.print("Ringing Alarm");
    digitalWrite(alarmPin,HIGH);
    delay(70);
    digitalWrite(alarmPin,LOW);
    delay(70);
    digitalWrite(alarmPin,HIGH);
    delay(70);
    digitalWrite(alarmPin,LOW);
    delay(70);
    digitalWrite(alarmPin,HIGH);
    delay(70);
    digitalWrite(alarmPin,LOW);
    delay(70);
    digitalWrite(alarmPin,HIGH);
    delay(70);
    digitalWrite(alarmPin,LOW);
    delay(700);
    lcd.clear();
    rounds++;
  }
  
   else{
    lcdUI();
    }
  }


void loop() {
  powerLoss();
  timeFunction();
  lcdUI();
  Alarm();
  

}

//Now I want to set multiple Alarms.
//Different alarms for in one day
//Different alarms each day of the week
//Though it will take up memory
//I will declare 3 NEW arrays for testing purposes
//For the day object,hour object and minute object.

