//**********************************************************************************
/*  
 * 文件名 : 测距仪表
 * 描述 : 四个led由超声波测距控制.
 * 作者 : www.keyes-robot.com
*/
const int TrigPin = 27;    // 定义TrigPin
const int EchoPin = 26;    // 定义EchoPin.
const int PIN_LED1 = 19;    // 定义PIN_LED1
const int PIN_LED2 = 18;    // 定义PIN_LED2
const int PIN_LED3 = 17;    // 定义PIN_LED3
const int PIN_LED4 = 16;    // 定义PIN_LED4
int duration = 0;    // 将持续时间的初始值定义为0
int distance = 0;   // 定义距离的初始值为0
void setup() 
{
  pinMode(TrigPin , OUTPUT); // 设置trigPin为输出模式
  pinMode(EchoPin , INPUT); // 设置echoPin为输入模式
  pinMode(PIN_LED1 , OUTPUT);  // 设置PIN_LED1为输出模式
  pinMode(PIN_LED2 , OUTPUT);  // 设置PIN_LED2为输出模式
  pinMode(PIN_LED3 , OUTPUT);  // 设置PIN_LED3为输出模式
  pinMode(PIN_LED4 , OUTPUT);  // 设置PIN_LED4为输出模式
  Serial.begin(115200);  // 设置波特率为115200.
}
void loop()
{
// 使trigPin高电平输出持续10μs触发HC_SR04 
  digitalWrite(TrigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin , LOW);
// 等待HC-SR04回到高电平，测量这个等待时间
  duration = pulseIn(EchoPin , HIGH);
// 根据时间计算距离
  distance = (duration/2) / 28.5 ;
  Serial.print("Distance: ");
  Serial.print(distance); //串口打印距离值
  Serial.println("cm");
  if ( distance <= 7 )
  {
    digitalWrite(PIN_LED1, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED1, LOW);
  }
  if ( distance <= 14 )
  {
    digitalWrite(PIN_LED2, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED2, LOW);
  }
  if ( distance <= 21 )
  {
    digitalWrite(PIN_LED3, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED3, LOW);
  }
  if ( distance <= 28 )
  {
    digitalWrite(PIN_LED4, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED4, LOW);
  }
}     
//**********************************************************************************
