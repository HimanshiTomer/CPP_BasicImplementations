/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: Prepare a time class to store time at a given instance. 
         Include following methods: 
         a) Methods to increment time and decrement time taking into account 
            the hour minute scale,  
         b) Create or initialize object of type time using constructors. 
         c) To find addition of two times using T1=T2+T3 or T1=27+T3 
         (in this case const. should be treated as seconds). Use friend function for this. 
         d) Overload the operator > to compare two times resulting in True or False. 
         e) To print the time in format HH: MM: SS
Date: 01-10-2024
*/

#include <iostream>
#include <ctime>

using namespace std;

class Time{
public:
   int hour, min, sec;
   Time(){
      time_t currentTime = time(0);
      tm *localTime = localtime(&currentTime);
      hour = localTime->tm_hour;
      min = localTime->tm_min;
      sec = localTime->tm_sec;
   }
   Time(int h, int m, int s){
      hour = h; min = m; sec = s;
   }
   Time(Time &t){
      hour = t.hour;
      min = t.min; 
      sec = t.sec;
   }
   void increement(){
      sec++;
      if (sec>=60){
         min += sec / 60; 
         sec %= 60;
      }
      if (min >= 60) {
         hour += min / 60;
         min %= 60;
      }
      if (hour >= 24) 
         hour %= 24;
      if (sec<0){
         min--;
         sec += 60;
      }
      if (min < 0) {
         hour -= 1;
         min += 60;
      }
      if (hour < 0)
         hour += 24;
   }
   void decreement(){
      sec--;
      if (sec>=60){
         min += sec / 60; 
         sec %= 60;
      }
      if (min >= 60) {
         hour += min / 60;
         min %= 60;
      }
      if (hour >= 24) 
         hour %= 24;
      if (sec<0){
         min--;
         sec += 60;
      }
      if (min < 0) {
         hour -= 1;
         min += 60;
      }
      if (hour < 0)
         hour += 24;
   }
   friend Time operator+(Time &t1, Time &t2);
   friend Time operator+(int s, Time &t);
   bool operator>(Time &t){
      if (hour > t.hour) 
         return true;
      if ((hour == t.hour) && (min > t.min)) 
         return true;
      if ((hour == t.hour) && (min == t.min) && (sec > t.sec)) 
         return true;
      return false;
   }
   void output(){
      cout << "Time in HH: MM: SS is " << hour << ": " << min << ": " << sec << endl;
   }
};

Time operator+(Time &t1, Time &t2){
   Time t;
   t.hour = t1.hour + t2.hour;
   t.min = t1.min + t2.min;
   t.sec = t1.sec + t2.sec;
   return t;
}

Time operator+(int s, Time &t1){
   Time t;
   t.hour = t1.hour;
   t.min = t1.min;
   t.sec = t1.sec + s;
   if (t.sec>=60){ t.min += t.sec / 60; t.sec %= 60; }
   if (t.min >= 60) { t.hour += t.min / 60; t.min %= 60; }
   if (t.hour >= 24) t.hour %= 24;
   if (t.sec<0){ t.min--;  t.sec += 60; }
   if (t.min < 0) { t.hour -= 1;  t.min += 60; }
   if (t.hour < 0) t.hour += 24;
   return t;
}

int main(){
   Time t1, t2(0, 0, 9);
   t1.output(); t2.output();

   t1.increement(); t1.output();

   t2.decreement();  t2.output();

   Time t3 = t1 + t2;
   t3.output();

   Time t4 = 27 + t2;
   t4.output();

   if (t1 > t2)
      cout << "t1 > t2" << endl; 
   else
      cout << "t1 < t2" << endl;
}