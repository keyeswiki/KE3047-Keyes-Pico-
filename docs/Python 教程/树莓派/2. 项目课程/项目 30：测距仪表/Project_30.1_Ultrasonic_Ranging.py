from machine import Pin
import time

#定义超声波测距模块的控制引脚. 
Trig = Pin(27, Pin.OUT, 0)
Echo = Pin(26, Pin.IN, 0)

distance = 0 # 定义初始距离为0.
soundVelocity = 340 #设定声速.

# getDistance()函数是驱动超声模块来测量距离,Trig引脚保持高电平10us，启动超声波模块.
# Echo.value()用于读取超声波模块的Echo引脚状态,
# 然后利用time模块的timestamp函数计算Echo的持续时间，根据时间计算测量的距离并返回值.
def getDistance():
    Trig.value(1)
    time.sleep_us(10)
    Trig.value(0)
    while not Echo.value():
        pass
    pingStart = time.ticks_us()
    while Echo.value():
        pass
    pingStop = time.ticks_us()
    distanceTime = time.ticks_diff(pingStop, pingStart) // 2
    distance = int(soundVelocity * distanceTime // 10000)
    return distance

# 延时2秒，等待超声模块稳定,每500毫秒打印一次超声波模块得到的数据. 
time.sleep(2)
while True:
    time.sleep_ms(500)
    distance = getDistance()
    print("Distance: ", distance, "cm")