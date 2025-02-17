from machine import Pin
import time

# 从引脚16创建继电器，设置引脚16为输出 
relay = Pin(16, Pin.OUT)
 
# 继电器断开，继电器上COM、NO连接，COM、NC断开.
def relay_on():
    relay(1)
 
# 继电器闭合，继电器上的COM和NO断开，COM和NC连接.
def relay_off():
    relay(0)
 
# 循环，继电器开启一秒，关闭一秒
while True:
    relay_on()
    time.sleep(1)
    relay_off()
    time.sleep(1)