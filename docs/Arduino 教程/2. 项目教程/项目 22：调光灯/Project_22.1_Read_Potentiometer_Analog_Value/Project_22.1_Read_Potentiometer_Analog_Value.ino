//**********************************************************************************
/*  
 * 文件名 : 读取电位器模拟值
 * 描述 : ADC的基本用法
 * 作者  : www.keyes-robot.com
*/
#define PIN_ANALOG_IN  26  //电位计的引脚

void setup() {
  Serial.begin(115200);
}

//在loop()函数中，调用analogRead来获取ADC0的ADC值，并将其赋给adcVal. 
//通过公式计算测量到的电压值，并通过串口监视器打印这些数据.
void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  double voltage = adcVal / 1023.0 * 3.3;
  Serial.println("ADC Value: " + String(adcVal) + " --- Voltage Value: " + String(voltage) + "V");
  delay(500);
}
//**********************************************************************************
