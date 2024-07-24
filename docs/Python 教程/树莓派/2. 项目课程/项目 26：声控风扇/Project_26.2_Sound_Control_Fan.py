from machine import ADC, Pin
import time
 
# 板载LED灯初始化
led = Pin(25, Pin.OUT)
 
# 初始化声音传感器引脚28 (ADC功能)
adc = ADC(28)
 
# 电机引脚初始化
motor1a = Pin(17, Pin.OUT) 
motor1b = Pin(16, Pin.OUT) 

# 读取声音传感器的当前模拟值并返回[0,1023]
def get_value():
    return int(adc.read_u16() * 1024 / 65536)
 
# 如果声音传感器检测到声音,当模拟值大于600时，Pico板上的内置LED会闪烁，电机会旋转
# 否则，电机不转动，LED熄灭    
while True:
    value = get_value()
    if value >600:
        led.value(1)    # 设置led开启 
        motor1a.high()  # 设置motor1a高电平
        motor1b.low()   # 设置motor1b低电平
        time.sleep(5)   # 延时 
    else:
        motor1a.low()  # 设置motor1a低电平
        motor1b.low()  # 设置motor1b低电平 
        led.value(0)    # 设置led关闭