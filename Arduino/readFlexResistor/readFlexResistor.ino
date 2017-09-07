
int anlgVal = 0;

void uePrintInt(int lVal) { 
  byte lBuffer[] = {
    byte(lVal & 0xff),
    byte(lVal >> 8 & 0xff),
    byte(lVal >> 16 & 0xff),
    byte(lVal >> 24 & 0x00) //needs to be 0 for some reason
  };
  Serial.write(lBuffer, 4);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  anlgVal = analogRead(A0);
  uePrintInt(anlgVal);
  delay(100);
}
