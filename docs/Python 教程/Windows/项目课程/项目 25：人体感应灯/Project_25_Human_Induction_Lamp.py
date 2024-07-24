from machine import Pin, ADC
import time
 
human = Pin(2, Pin.IN) # 人体红外传感器引脚
 
light = ADC(26)  # 将光敏传感器引脚初始化为GP26 (ADC功能)
 
led1 = Pin(16, Pin.OUT) #从引脚16创建外部LED对象，设置引脚16为输出 

led2 = Pin(25, Pin.OUT) #从引脚25创建Pico板上的内置LED，设置引脚25为输出  
 
# 关闭外接LED灯
def led1_off():
    led1.value(0)
 
# 打开外接LED灯
def led1_on():
    led1.value(1)
    
# 打开Pico板上的内置LED
def led2_on():
    led2.value(1)
 
# 关闭Pico板上的内置LED灯
def led2_off():
    led2.value(0)
 
# 读取光敏传感器的模拟值，量程[0,1023]
# 光照强度越强，数值越小.
def get_value():
    return int(light.read_u16() * 1024 / 65536)
 
 
def detect_someone():
    if human.value() == 1:
        return True
    return False
 
abc = 0
 
while True:
    val = get_value()
#     print('val=', val)
 
    if val >= 500:
        led2_on()
        if detect_someone() == True:
            abc += 1
            led1_on()
            print("value=", abc)
            time.sleep(1)
        else:
            if abc != 0:
                abc = 0
                led1_off()
    else:
        led2_off()
        led1_off()
 
    time.sleep(0.1)