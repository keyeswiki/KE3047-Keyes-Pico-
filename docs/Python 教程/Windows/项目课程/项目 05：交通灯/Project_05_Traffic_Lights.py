from machine import Pin
import time

led_red = machine.Pin(16, machine.Pin.OUT)  # 从引脚16创建红色led对象，设置引脚16为输出
led_yellow = machine.Pin(17, machine.Pin.OUT)  # 从引脚17创建黄色led对象，设置引脚17为输出
led_green = machine.Pin(18, machine.Pin.OUT) # 创建绿色led对象从引脚18，设置引脚18输出

while True:
    led_red.value(1)  # 设置红色led灯亮
    time.sleep(5)   # 延时 5s
    led_red.value(0) # 设置红色led关闭 
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_green.value(1)
    time.sleep(5) 
    led_green.value(0) 