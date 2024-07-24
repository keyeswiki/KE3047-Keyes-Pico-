//**********************************************************************
/* 
 * 文件名 : 74HC595N 控制 8 个灯
 * 描述 : 使用74HC575N驱动8个led显示流动光.
 * 作者 : www.keyes-robot.com
*/
int dataPin = 18;   // 引脚接74HC595的DS(GP14)  
int latchPin = 20;  // 引脚连接到ST_CP的74HC595(GP12)
int clockPin = 21;  // 引脚连接到74HC595的SH_CP(GP11)          

void setup() { // 将引脚设置为输出
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // 定义一个单字节变量，用这8位表示LED条形图中8个LED的状态.
  // 这个变量被赋值给0x01，也就是二进制的00000001，这表示只有一个LED灯亮着.
  byte x = 0x01;    // 0b 0000 0001
  for (int j = 0; j < 8; j++) { // 让led从右到左点亮
    writeTo595(LSBFIRST, x);
    x <<= 1; // 使变量向左移动一位，然后明亮的LED向左移动一步.
    delay(100);
  }
  delay(100);
  x = 0x80;       //0b 1000 0000
  for (int j = 0; j < 8; j++) { // 让led从左到右点亮
    writeTo595(LSBFIRST, x);
    x >>= 1;    
    delay(100);
  }
  delay(100);
}
void writeTo595(BitOrder order, byte _data ) {
  // 输出低电平到latchPin
  digitalWrite(latchPin, LOW);
  // 发送串行数据到74HC595
  shiftOut(dataPin, clockPin, order, _data);
  // 输出高电平到latchPin, 74HC595将数据更新到并行输出端口.
  digitalWrite(latchPin, HIGH);
}
//**********************************************************************************
