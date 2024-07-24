//**********************************************************************************
/*  
 * 文件名  : RFID
 * 描述 : RFID 读取 UID
 * 作者  : www.keyes-robot.com
*/
#include <Wire.h>
#include "MFRC522_I2C.h"
// IIC引脚默认为Raspberry Pi Pico的GPIO4和GPIO5
// 0x28是SDA的i2c地址，如果不匹配，请检查你的地址与i2c.
MFRC522 mfrc522(0x28);   // 创建 MFRC522.
String rfid_str = "";

void setup() {
  Serial.begin(115200);           // 初始化与PC机的串行通信
  Wire.begin();                   // 初始化 I2C
  mfrc522.PCD_Init();             // 初始化 MFRC522
}

void loop() {
  // 
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  rfid_str = "";//数字字符串为空
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfid_str = rfid_str + String(mfrc522.uid.uidByte[i], HEX);  //转化为字符串
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println(rfid_str);
}
//**********************************************************************************
