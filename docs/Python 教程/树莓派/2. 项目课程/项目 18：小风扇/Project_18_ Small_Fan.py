from machine import Pin
import time

motor1a = Pin(17, Pin.OUT) # 从引脚17创建motor1a对象，设置引脚17为输出
motor1b = Pin(16, Pin.OUT) # 从引脚16创建motor1b对象，设置引脚16为输出

def forward():
    motor1a.high() # 设置motor1a高电平
    motor1b.low() # 设置motor1b低电平
def backward():
    motor1a.low()
    motor1b.high()
def stop():
    motor1a.low()
    motor1b.low()

def test():
    forward() # 电机正转
    time.sleep(5) #延时
    stop() # 电机不转
    time.sleep(2)
    backward()# 电机反转 
    time.sleep(5)
    stop()
    time.sleep(2)
    
for i in range(5):
    test() 