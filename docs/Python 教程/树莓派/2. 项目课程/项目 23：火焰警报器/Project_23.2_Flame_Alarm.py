from machine import ADC, Pin
import time

adc = ADC(26) # 将火焰传感器初始化到引脚26 (ADC功能)

led = Pin(16, Pin.OUT) # 从引脚16创建LED对象，设置引脚16为输出

buzzer = Pin(17, Pin.OUT) # 从引脚17创建蜂鸣器对象，设置引脚17为输出  

# 读取火焰传感器的模拟值并返回[0,1023]
def get_value():
    return int(adc.read_u16() * 1024 / 65536)
 
# 如果火焰传感器检测到火焰，当模拟值大于500时，蜂鸣器会发出蜂鸣声,LED闪烁
# 否则，蜂鸣器不响，LED熄灭 
while True:
    value = get_value()
    if value >500:
        buzzer.value(1)  # 设置蜂鸣器开启
        led.value(1)     # 设置led开启
        time.sleep(0.5)  # 延时 0.5s
        led.value(0)     # 设置led关闭
        time.sleep(0.5)  # 延时 0.5s
    else:
        buzzer.value(0)  # 设置蜂鸣器关闭
        led.value(0)     # 设置led关闭
