//**********************************************************************************
/*  
 * 文件名 : 红外控制声音和LED
 * 描述 : 红外遥控控制RGB和无源蜂鸣器.
 * 作者 : www.keyes-robot.com
*/
#include "IR.h"

#define irPin 16
#define R_Pin 19
#define G_Pin 18
#define B_Pin 17
#define buzzerPin 15

void setup() {
  Serial.begin(115200);
  IR_Init(irPin);
  pinMode(R_Pin, OUTPUT);
  pinMode(G_Pin, OUTPUT);
  pinMode(B_Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if(flagCode){
    int irValue = IR_Decode(flagCode);
    Serial.println(irValue, HEX);
    handleControl(irValue);
    IR_Release();
  }
}

void handleControl(unsigned long value) {

  // 处理命令
  if (value == 0xFF6897) // 接收数字“1”
  { 
      analogWrite(R_Pin, 255); //共阴极LED，高电平点亮LED.
      analogWrite(G_Pin, 0);
      analogWrite(B_Pin, 0);
      tone(buzzerPin, 262);//DO音响1秒
      delay(1000);
  }
   else if (value == 0xFF9867) // 接收数字“2”
   { 
      analogWrite(R_Pin, 0); 
      analogWrite(G_Pin, 255); //共阴极LED，高电平点亮LED.
      analogWrite(B_Pin, 0);
      tone(buzzerPin, 294);//Re音响750毫秒
      delay(750);
   }
    else if (value == 0xFFB04F) // 接收数字“3”
   { 
      analogWrite(R_Pin, 0); 
      analogWrite(G_Pin, 0);
      analogWrite(B_Pin, 255); //共阴极LED，高电平点亮LED.
      tone(buzzerPin, 330);//Mi音响625毫秒
      delay(625);
    }
    else if (value == 0xFF30CF) // 接收数字 '4'
   {  
      analogWrite(R_Pin, 255); 
      analogWrite(G_Pin, 255);
      analogWrite(B_Pin, 0);
      tone(buzzerPin, 349);//Fa 音响500毫秒
      delay(500);
    }
    else if (value == 0xFF18E7) // 接收数字 '5'
   {  
      analogWrite(R_Pin, 255); 
      analogWrite(G_Pin, 0);
      analogWrite(B_Pin, 255);
      tone(buzzerPin, 392);//So音响375毫秒
      delay(375);
    }
    else if (value == 0xFF7A85)  // 接收数字 '6'
   {  
      analogWrite(R_Pin, 0); 
      analogWrite(G_Pin, 255);
      analogWrite(B_Pin, 255);
      tone(buzzerPin, 440);//La音响250毫秒
      delay(250);
    }
    else if (value == 0xFF10EF)  // 接收数字 '7'
   {   
      analogWrite(R_Pin, 255); 
      analogWrite(G_Pin, 255);
      analogWrite(B_Pin, 255);
      tone(buzzerPin, 494);//Si音响125毫秒
      delay(125);
    }
    else{
      analogWrite(R_Pin, 0); 
      analogWrite(G_Pin, 0);
      analogWrite(B_Pin, 0);
      noTone(buzzerPin);//Si音响125毫秒
      delay(1000);
      }
  }
//**********************************************************************************
