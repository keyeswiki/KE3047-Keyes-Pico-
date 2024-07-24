# 导入红外解码器库.
from irrecvdata import irGetCMD

# 将红外解码器与GP16相关联.
recvPin = irGetCMD(16)

#获取红外键值时，在“Shell”中打印出来. 
try:
    while True:
        irValue = recvPin.ir_read() #调用ir_read()读取按下的键的值，并将其赋给IRValue.
        if irValue:
            print(irValue)
except:
    pass