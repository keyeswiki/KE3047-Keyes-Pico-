//**********************************************************************
/*
 * 文件名 : 步进电机
 * 描述 : 使用ULN2003驱动步进电机.
 * 作者 : www.keyes-robot.com
*/
// 连接步进电机驱动器的端口
int outPorts[] = {21, 20, 19, 18};

void setup() {
  // set pins to output
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
}

void loop()
{
  // 旋转一圈
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  // 向另一个方向旋转一圈
  moveSteps(false, 32 * 64, 3);
  delay(1000);
}

//建议:在3 ~ 20毫秒范围内电机转动精确
void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // 旋转一步
    delay(constrain(ms,3,20));        // 控制速度
  }
}

void moveOneStep(bool dir) {
  // 定义一个变量，用四位低位表示端口的状态
  static byte out = 0x01;
  // 根据旋转方向确定移动方向
  if (dir) {  // 循环左移
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else {      // 循环右移
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // 向每个端口输出信号
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms){
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}
void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}
//********************************************************************************
