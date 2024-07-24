//**********************************************************************************
/*  
 * 文件名 : 读取摇杆的值
 * 描述 : 从摇杆传感器读取数据.
 * 作者 : www.keyes-robot.com
*/
int xyzPins[] = {27, 26, 28};   //x, y, z引脚
void setup() {
  Serial.begin(115200);
  pinMode(xyzPins[0], INPUT); //x 轴. 
  pinMode(xyzPins[1], INPUT); //y 轴. 
  pinMode(xyzPins[2], INPUT_PULLUP);   //z 轴是一个按钮.
}

// 在loop()中，使用analogRead()读取X轴和Y轴的值，使用digitalRead()读取Z轴的值，然后显示它们.
void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.println("X,Y,Z: " + String(xVal) + ", " +  String(yVal) + ", " + String(zVal));
  delay(500);
}
//**********************************************************************************
