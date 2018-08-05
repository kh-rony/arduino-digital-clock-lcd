#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 4, 5, 6, 7);

int hour = 7;
int minute = 34;
int second = 0;

int tempHour = 12;
int tempMinute = 0;
int tempSecond = 0;

void setup()
{
  lcd.begin(32, 1);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  show();
}

void loop()
{
  delay(1000);
  calculateUpdatedTime();
  show();

  if( digitalRead(8) == LOW )
  {
    delay(100);
    lcd.clear();
    lcd.write("Set Hour: ");
    printDigit(tempHour);

    
    while(1)
    {
      if( digitalRead(8) == LOW )
      {
        delay(100);
        break;
      }
      if( digitalRead(10) == LOW )//increment
      {
        delay(100);
        tempHour++;
        if( tempHour == 13 )
        {
          tempHour = 1;
        }
        lcd.clear();
        lcd.write("Set Hour: ");
        printDigit(tempHour);

        hour = tempHour;
      }
      if( digitalRead(9) == LOW )//decrement
      {
        delay(100);
        tempHour--;
        if( tempHour == 0 )
        {
          tempHour = 12;
        }
        lcd.clear();
        lcd.write("Set Hour: ");
        printDigit(tempHour);

        hour = tempHour;
      }
    }


    lcd.clear();
    lcd.write("Set Minute: ");
    printDigit(tempMinute);


    while(1)
    {
      if( digitalRead(8) == LOW )
      {
        delay(100);
        break;
      }
      if( digitalRead(10) == LOW )//increment
      {
        delay(100);
        tempMinute++;
        if( tempMinute == 60 )
        {
          tempMinute = 0;
        }
        lcd.clear();
        lcd.write("Set Minute: ");
        printDigit(tempMinute);

        minute = tempMinute;
      }
      if( digitalRead(9) == LOW )//decrement
      {
        delay(100);
        tempMinute--;
        if( tempMinute == -1 )
        {
          tempMinute = 59;
        }
        lcd.clear();
        lcd.write("Set Minute: ");
        printDigit(tempMinute);

        minute = tempMinute;
      }
    }


    lcd.clear();
    lcd.write("Set Second: ");
    printDigit(tempSecond);


    while(1)
    {
      if( digitalRead(8) == LOW )
      {
        delay(100);
        break;
      }
      if( digitalRead(10) == LOW )//increment
      {
        delay(100);
        tempSecond++;
        if( tempSecond == 60 )
        {
          tempSecond = 0;
        }
        lcd.clear();
        lcd.write("Set Second: ");
        printDigit(tempSecond);

        second = tempSecond;
      }
      if( digitalRead(9) == LOW )//decrement
      {
        delay(100);
        tempSecond--;
        if( tempSecond == -1 )
        {
          tempSecond = 59;
        }
        lcd.clear();
        lcd.write("Set Second: ");
        printDigit(tempSecond);

        second = tempSecond;
      }
    }


  }
}


void calculateUpdatedTime()
{
  second++;

  if( second == 60 )
  {
    second = 0;
    minute++;

    if( minute == 60 )
    {
      minute = 0;
      hour++;

      if( hour == 13 )
      {
        hour = 1;
      }
    }
  }
}

void printDigit(int number)
{
  if( number < 10 )
  {
    lcd.write("0");
    lcd.print(number);
  }
  else
  {
    lcd.print(number);
  }
}

void show()
{
  lcd.clear();

  printDigit(hour);
  lcd.write(":");

  printDigit(minute);
  lcd.write(":");

  printDigit(second);
}