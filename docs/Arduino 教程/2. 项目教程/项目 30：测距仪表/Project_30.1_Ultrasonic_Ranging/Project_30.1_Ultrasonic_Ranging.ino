//**********************************************************************************
/*  
 * 文件名 : 测距仪表
 * 描述 : 使用超声波模块测量距离.
 * 作者 : www.keyes-robot.com
*/
const int TrigPin = 27; // 定义TrigPin
const int EchoPin = 26; // 定义EchoPin.
int duration = 0; // 将持续时间的初始值定义为0
int distance = 0;//定义距离的初始值为0
void setup() 
{
  pinMode(TrigPin , OUTPUT); // 设置trigPin为输出模式
  pinMode(EchoPin , INPUT); // 设置echoPin为输入模式
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
  delay(100); //等待100ms之间的pings(大约20pings /秒).
}
//**********************************************************************************
