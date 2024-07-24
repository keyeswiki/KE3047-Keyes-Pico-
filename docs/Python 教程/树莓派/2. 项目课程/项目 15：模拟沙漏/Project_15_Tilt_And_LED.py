from machine import Pin
import time

led1 = Pin(19, Pin.OUT) # 从引脚19创建LED对象，设置引脚19为输出
led2 = Pin(18, Pin.OUT) # 从引脚18创建LED对象，设置引脚18为输出
led3 = Pin(17, Pin.OUT) # 从引脚17创建LED对象，设置引脚17为输出
led4 = Pin(16, Pin.OUT) # 从引脚16创建LED对象，设置引脚16为输出
Tilt_Sensor = Pin(22,Pin.IN) #从引脚22创建倾斜传感器对象，设置GP22为输入

while True:
    if(Tilt_Sensor.value() == 0) : #当倾斜传感器值为0时
        led1.value(1) # led1 开启
        time.sleep_ms(200)#延时
        led2.value(1) # led2 开启
        time.sleep_ms(200)
        led3.value(1) # led3 开启
        time.sleep_ms(200)
        led4.value(1) # led4 开启
        time.sleep_ms(200)
    else :           #当倾斜传感器值为1时
        led4.value(0) # led4 关闭
        time.sleep_ms(200)
        led3.value(0) # led3 关闭
        time.sleep_ms(200)
        led2.value(0) # led2 关闭
        time.sleep_ms(200)
        led1.value(0) # led1 关闭
        time.sleep_ms(200)
