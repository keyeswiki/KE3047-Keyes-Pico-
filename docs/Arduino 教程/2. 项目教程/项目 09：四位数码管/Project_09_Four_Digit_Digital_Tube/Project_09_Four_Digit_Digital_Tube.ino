//**********************************************************************
/* 
 * 文件名  : 四位数码管
 * 描述 : 四位数管显示数字从1111到9999.
 * 作者 : www.keyes-robot.com
*/
#include "TM1650.h"
#define CLK 21    //用于TM1650的引脚定义，可以更改为其他端口 
#define DIO 20
TM1650 DigitalTube(CLK,DIO);

void setup(){
  //DigitalTube.setBrightness();  //亮度从0到7(默认为2)
  //DigitalTube.displayOnOFF();   // 0= off,1= on(默认是 1)
  for(char b=1;b<5;b++){
    DigitalTube.clearBit(b);      //要清除哪一部分
  }
  DigitalTube.displayDot(1,true); // 显示第一个数字
  DigitalTube.displayDot(2,true);
  DigitalTube.displayDot(3,true);
  DigitalTube.displayDot(4,true);
  DigitalTube.displayBit(3,0);    //显示哪个数字, 位= 1 - 4,数量= 0 - 9
}

void loop(){
  for(int num=0; num<10; num++){
    DigitalTube.displayBit(1,num);
    DigitalTube.displayBit(2,num);
    DigitalTube.displayBit(3,num);
    DigitalTube.displayBit(4,num);
    delay(1000);
  }  
 }
//**********************************************************************************
