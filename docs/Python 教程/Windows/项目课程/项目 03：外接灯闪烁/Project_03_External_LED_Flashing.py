from machine import Pin
import time

led = Pin(16, Pin.OUT)   # 从引脚16创建LED对象，设置引脚16为输出

try:
    while True:
        led.value(1)    # 设置led开启
        time.sleep(0.5) # 延时 0.5s
        led.value(0)    # 设置led关闭
        time.sleep(0.5) # 延时 0.5s
except:
    pass