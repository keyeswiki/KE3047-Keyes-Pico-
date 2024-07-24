//**********************************************************************************
/*  
 * 文件名 : 解码红外信号
 * 描述 : 解码红外遥控器，通过串口打印出来.
 * 作者 : www.keyes-robot.com
*/
#include "IR.h"
#define IR_Pin 16

void setup() {
  Serial.begin(115200);
  IR_Init(IR_Pin);
}

void loop() {
  if(flagCode){
    int irValue = IR_Decode(flagCode);
    Serial.println(irValue, HEX);
    IR_Release();
  }
}
//**********************************************************************************
