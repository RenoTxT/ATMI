#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4;
const byte COLS = 4;
int count = 0;
int password = 113;
int ask;
char key;
int choice;
int amount;
int pos;
int balance = 10000;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Servo servo;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int GetNumber()
{
  int num = 0;
  char key = keypad.getKey();
  while (key != '#')
  {
    switch (key)
    {
      case NO_KEY:
        break;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        lcd.print(key);
        num = num * 10 + (key - '0');
        break;

      case '*':
        num = 0;
        lcd.clear();
        break;
    }

    key = keypad.getKey();
  }

  return num;
}

void setup()
{
  Serial.begin(9600);
  servo.attach(8);
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("ATM Eqxinus");
  delay(3000);
  lcd.clear();
}

void loop()
{
  while (ask == 0 )
  {
    lcd.setCursor(0, 0);
    lcd.print("Enter PIN :");
    delay(100);
    lcd.setCursor(0, 1);
    int pin = GetNumber();

    // checking pin length
    // password validation
    if (pin == password)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome User :");
      lcd.setCursor(0, 1);
      lcd.print("Reno");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1. Tarik Tunai");
      lcd.setCursor(0, 1);
      lcd.print("2. Keluar");
      delay(1000);
      lcd.setCursor(0, 0);
      delay(1000);
      int take = 0;
      while (take <= 1)
      {
        char key = keypad.getKey();
        if (key)
        {
          if (key != NO_KEY)
          {
            //--------------------1-WITHDRAW-----------------------------//
            if (key == '1')
            {
              int amount;

              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Options");
              lcd.clear();
              delay(1000);
              lcd.setCursor(0, 0);
              lcd.print("1- #1000");
              lcd.setCursor(0, 1);
              lcd.print("2- #2000");
              delay(500);
              lcd.setCursor(0, 0);
              lcd.print("3- #5000");
              lcd.setCursor(0, 1);
              lcd.print("4- #10000");
              delay(500);
              lcd.setCursor(0, 0);
              lcd.print("5- #20000");
              lcd.setCursor(0, 1);
              lcd.print("6- Other");
              delay(1000);

              //added next 2 lines to make sure comp knows to take ip
              lcd.setCursor(0, 0);
              delay(2000);
              int i = 0;

              while (i <= 1)
              {
                char key = keypad.getKey();
                if (key)
                {
                  if (key != NO_KEY)
                  {
                    int wit_cash;
                    //changed key>0 to key>'0'
                    if ((key > '0') && (key <= '5'))
                    {
                      switch (key) {
                        case '1':
                          wit_cash = 1000;
                          break;
                        case '2':
                          wit_cash = 2000;
                          break;
                        case '3':
                          wit_cash = 5000;
                          break;
                        case '4':
                          wit_cash = 10000;
                          break;
                        case '5':
                          wit_cash = 20000;
                          break;
                      }
                      //added amount entered to be printed on screen
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Nominal: ");
                      delay(2000);
                      lcd.setCursor(0, 1);
                      lcd.print(wit_cash);
                      delay(1000);
                      //
                    }

                    else if (key == '6')
                    {
                      lcd.clear();
                      lcd.setCursor(0, 0);
                      lcd.print("Masukan Nominal");
                      lcd.setCursor(0, 1);
                      wit_cash = GetNumber();

                      lcd.setCursor(0, 0);
                      lcd.print("Nominal : ");
                      lcd.setCursor(0, 1);
                      lcd.print(wit_cash);
                      delay(2000);
                      lcd.clear();
                    }
                    //
                    lcd.clear();
                    if (wit_cash > balance) {
                      lcd.setCursor(0, 0);
                      lcd.print("Saldo");\
                      lcd.setCursor(0, 1);
                      lcd.print("Tidak Cukup");

                    }
                    else
                    {
                      for (pos = 0; pos <= 180; pos++)
                      {
                        servo.write(pos);
                        delay(15);
                      }
                      delay(1000);
                      balance = balance - wit_cash;
                      lcd.setCursor(0, 0);
                      lcd.print("Saldo :");
                      delay(3000);
                      lcd.setCursor(0, 1);
                      lcd.print(balance);
                      break;

                    }
                  }
                }
              }
              delay(3000);
              lcd.clear();
              break;
            }
          }


          if (key != NO_KEY)
          {

            if (key != NO_KEY)
            {
              //--------------------4-EXIT-----------------------------//
              if (key == '2')
              {
                lcd.clear();
                lcd.setCursor(0, 0);
                delay(1000);
                lcd.print("Ambil Kartu");
                delay(1000);
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Terima Kasih");
                delay(2000);
                break;
              }
            }//no key 4
          }// if(key)
        }//while(take<=1)
      }//checking pin
    }
    else
    {
      lcd.clear();
      lcd.print("Incorrect pin");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      count = 0;
    }
    //}//if(count=3)
    //}//if(key)
  }//while(ask=1)
}//void loop
