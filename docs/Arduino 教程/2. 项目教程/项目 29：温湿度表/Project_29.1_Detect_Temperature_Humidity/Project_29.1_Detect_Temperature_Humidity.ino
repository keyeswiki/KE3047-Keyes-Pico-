//**********************************************************************
/*
 * 文件名 : 温湿度传感器
 * 描述 : 使用温湿度传感器测量温度和湿度。将结果打印到串口.
 * 作者 : www.keyes-robot.com
*/
//在使用dht11之前，我们需要包含一个头文件. 
//申请一个DHT对象，定义控制DHT的引脚为GPIO22.
#include <dht.h>

dht DHT;

#define DHT11_PIN 22

void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);//Read11()用于读取DHT11数据，并将返回值赋给变量chk.
//如果read11()函数的返回值不等于DHTLIB_OK，这意味着数据读取失败; 
//如果两者相等，则调用humuduty()和temperature()，获取当前环境的温湿度数据，并通过串口打印出来. 
  if(chk == DHTLIB_OK){
    Serial.println("humidity: " + String(DHT.humidity) + "%, temperature: " + String(DHT.temperature) + "C");
  }else{
    Serial.println("DHT11 Reading data error!");
  }
  delay(1000);
}
//********************************************************************************
