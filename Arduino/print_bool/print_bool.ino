/* 
 *  Prints 0 and 1 at a   0.2 Hz (5 s) 
 */

 
     /* 
      *  Helper Function To Write Int  
      *  
      *  uePrintInt(int) 
      */
      void uePrintInt(int lVal) { 
        byte lBuffer[] = {
          byte(lVal & 0xff),
          byte(lVal >> 8 & 0xff),
          byte(lVal >> 16 & 0xff),
          byte(lVal >> 24 & 0xff)
        };
        Serial.write(lBuffer, 4);
      }
      
void setup() {
  Serial.begin(9600);
}

void loop() { 
    /* 
     *  Test to see serial.write vs serial.print times
     *  Serial.write prints binary data
     *  Serial.print prints string?
     */
     
//    uint32_t start_t = 0;
//    uint32_t end_t =0; 
//    while (1) { 
//      start_t = micros();
//      Serial.write(0);
//      end_t = micros();
//      Serial.print("\nThe time Serial.write() took was: ");
//      Serial.print(end_t - start_t); 
//      Serial.println(" micros(econds)");
//  
//      delay(2500); 
//      
//      start_t = micros();
//      Serial.print(0);
//      end_t = micros();
//      Serial.print("\nThe time Serial.print() took was: ");
//      Serial.print(end_t - start_t);
//      Serial.println(" micros(econds)");
//  
//      delay(2500); 
//    }
    /* *****************************************************
     *  Actual Code
     * *****************************************************
     */

     byte mbyte = byte(0 & 0xff); 
     Serial.write(mbyte);
     delay(1000);
     
     mbyte = byte(1 & 0xff); 
     Serial.write(mbyte);
     delay(1000);
     
//      uePrintInt(10);
//      delay(1000);
//      uePrintInt(1010);
//      delay(1000);
}

