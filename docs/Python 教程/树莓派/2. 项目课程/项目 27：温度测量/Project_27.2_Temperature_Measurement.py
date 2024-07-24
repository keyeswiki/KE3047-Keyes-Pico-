from machine import ADC, Pin
import time
import machine

# 初始化声音传感器引脚26 (ADC功能)
# 选择ADC0 (GPIO26)
sensor_temp = ADC(26)
conversion_factor = 3.3 / (65535)

led_red = machine.Pin(19, machine.Pin.OUT) # 从引脚19创建红色led对象，设置引脚19为输出 

led_yellow = machine.Pin(21, machine.Pin.OUT) # 从引脚21创建黄色led对象，设置引脚21为输出

led_green = machine.Pin(22, machine.Pin.OUT)  # 从引脚22创建绿色led对象，设置引脚22输出

while True:
    reading = sensor_temp.read_u16() * conversion_factor 
    temperature = reading * 102.4
    print(temperature)
    time.sleep(0.2)
    if temperature <28:
        led_red.value(1)  # 设置红色led灯亮
        led_yellow.value(0) # 设置黄色led关闭 
        led_green.value(0)  # 设置绿色led关闭
    elif temperature >28 and temperature <31:
        led_red.value(0)  # 设置红色led关闭
        led_yellow.value(1) # 设置黄色led灯亮 
        led_green.value(0)  # 设置绿色led关闭
    else:
        led_red.value(0)  # 设置红色led关闭
        led_yellow.value(0) # 设置黄色led关闭 
        led_green.value(1)  # 设置绿色led灯亮