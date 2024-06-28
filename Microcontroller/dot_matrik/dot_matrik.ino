int ANIMDELAY = 100; // animation delay, default value is 100

int INTENSITYMIN = 0; // minimum brightness, valid range [0,15]

int INTENSITYMAX = 8; // maximum brightness, valid range [0,15]

int DIN_PIN = 8; // data in pin

int CS_PIN = 9; // load (CS) pin

int CLK_PIN = 10; // clock pin

// MAX7219 registers

byte MAXREG_DECODEMODE = 0x09;

byte MAXREG_INTENSITY = 0x0a;

byte MAXREG_SCANLIMIT = 0x0b;

byte MAXREG_SHUTDOWN = 0x0c;

byte MAXREG_DISPTEST = 0x0f;

const unsigned char snowflake[] =
{
B00011000,
B00011000,
B11111111,
B11111111,
B00011000,
B00011000,
B00011000,
B00011000


};

void setup ()

{

  pinMode(DIN_PIN, OUTPUT);

  pinMode(CLK_PIN, OUTPUT);

  pinMode(CS_PIN, OUTPUT);

  // initialization of the MAX7219

  setRegistry(MAXREG_SCANLIMIT, 0x07);

  setRegistry(MAXREG_DECODEMODE, 0x00); // using an led matrix (not digits)

  setRegistry(MAXREG_SHUTDOWN, 0x01); // not in shutdown mode

  setRegistry(MAXREG_DISPTEST, 0x00); // no display test

  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);

  // draw snowflakeh

  setRegistry(1, snowflake[0]);

  setRegistry(2, snowflake[1]);

  setRegistry(3, snowflake[2]);

  setRegistry(4, snowflake[3]);

  setRegistry(5, snowflake[4]);

  setRegistry(6, snowflake[5]);

  setRegistry(7, snowflake[6]);

  setRegistry(8, snowflake[7]);

}

void loop ()

{

  // second beat

  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);

  delay(ANIMDELAY);

  // switch off

  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);

  delay(ANIMDELAY);

  // second beat

  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);

  delay(ANIMDELAY);

  // switch off

  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);

  delay(ANIMDELAY * 6);

}

void setRegistry(byte reg, byte value)

{

  digitalWrite(CS_PIN, LOW);

  putByte(reg); // specify register

  putByte(value); // send data

  digitalWrite(CS_PIN, LOW);

  digitalWrite(CS_PIN, HIGH);

}

void putByte(byte data)

{

  byte i = 8;

  byte mask;

  while (i > 0)

  {

    mask = 0x01 << (i - 1); // get bitmask

    digitalWrite( CLK_PIN, LOW); // tick

    if (data & mask) // choose bit

      digitalWrite(DIN_PIN, HIGH); // send 1

    else

      digitalWrite(DIN_PIN, LOW); // send 0

    digitalWrite(CLK_PIN, HIGH); // tock

    --i; // move to lesser bit

  }
}
