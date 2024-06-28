#include <LiquidCrystal.h>
// LCD setup
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Variables
int kondisi;
int PBMERAH, PBKUNING, PBHIJAU, PBPUTIH;
int waktu = 0;
int jeda;
int buzzer = 11;

void blinking()
{
  digitalWrite(52, HIGH);
  digitalWrite(50, HIGH);
  digitalWrite(48, HIGH);

  digitalWrite(52, LOW);
  digitalWrite(50, LOW);
  digitalWrite(48, LOW);

  digitalWrite(52, HIGH);
  digitalWrite(50, HIGH);
  digitalWrite(48, HIGH);


  digitalWrite(52, LOW);
  digitalWrite(50, LOW);
  digitalWrite(48, LOW);
}


void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set button pins as input
  pinMode(8, INPUT);// PB MERAH
  pinMode(9, INPUT);// PB KUNING
  pinMode(10, INPUT);//PB HIJAU
  pinMode (46, INPUT);
  pinMode(52, OUTPUT); // MERAH
  pinMode(50, OUTPUT); // KUNING
  pinMode(48, OUTPUT); // HIJAU

  pinMode(buzzer, OUTPUT);



  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("SelamatDatang!");
  Serial.begin(9600);
}

void loop() {
  // Read button states
  while (kondisi == 0)
  {
    Serial.println(kondisi);


    delay(1000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Stopwatch");
    lcd.setCursor(0, 1);
    lcd.print("Time : ");






    PBMERAH = digitalRead(8);
    if (PBMERAH == 1)
    {
      kondisi = 1;
    }
  }

  while (kondisi == 1)
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(52, LOW);
    digitalWrite(48, HIGH);

    Serial.println(kondisi);
    lcd.setCursor(0, 0);
    lcd.print("Stopwatch");
    lcd.setCursor(0, 1);
    lcd.print("Time : ");
    lcd.setCursor(10, 1);
    lcd.print("s");

    lcd.setCursor(7, 1);
    lcd.print(waktu);
    for (jeda = 0; jeda <= 1000; jeda++)
    {
      PBKUNING = digitalRead(9);
      if (PBKUNING == 1)
      {
        kondisi = 2;
      }
      delay(1);
    }

    waktu++;
  }

  while (kondisi == 2)
  {

    digitalWrite(48, LOW);
    digitalWrite(50, HIGH);
    digitalWrite(buzzer, LOW);
    Serial.println(kondisi);

    PBMERAH = digitalRead(8);
    if (PBMERAH == 1)
    {
      kondisi = 1;
      digitalWrite(50, LOW);
      digitalWrite(48, HIGH);
      digitalWrite(buzzer, HIGH);
    }
    
    PBHIJAU = digitalRead(10);
    if (PBHIJAU == 1)
    {
      kondisi = 0;
      waktu = 0;
      lcd.clear();
      digitalWrite(52, HIGH);
      digitalWrite(50, LOW);
      digitalWrite(48, LOW);
      digitalWrite(buzzer, LOW);
    }

    PBPUTIH = digitalRead(46);
    if (PBPUTIH == 1)
    {
      kondisi = 3 ;
      waktu--;
    }


   
  }
}
