//*************************************************************************************
/* 
 * 文件名 : RFID mfrc522 控制 舵机
 * 描述 : RFID 控制舵机模拟开门
 * 作者 : www.keyes-robot.com
*/
#include <Servo.h>
#include <Wire.h>
#include <MFRC522_I2C.h>
MFRC522 mfrc522(0x28);
Servo myservo;
String rfid_str = "";

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mfrc522.PCD_Init();
  myservo.attach(2);//舵机连接到GP2
  myservo.write(0);//初始角度是0度
  delay(500);
}

void loop() {
   if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  rfid_str = ""; //设置字符串为空
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfid_str = rfid_str + String(mfrc522.uid.uidByte[i], HEX);  //转化为字符串
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println(rfid_str); 
  if (rfid_str == "93adf720" || rfid_str == "39b646c2") {
    myservo.write(180);            // 舵机旋转180°
    delay(500);
    Serial.println("  open the door!");
    }
}
//*************************************************************************************
