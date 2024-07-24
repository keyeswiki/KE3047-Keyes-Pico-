#导入time和my74HC595模块.
from my74HC595 import Chip74HC595
import time

#创建Chip74HC595对象并配置引脚
chip = Chip74HC595(18, 20, 21)
#Chip74HC595() == Chip74HC595(18, 20, 21)

#第一个for循环使LED条从左到右分别显示
#而第二个for循环使其从右到左分别显示.
while True:
    x = 0x01
    for count in range(8):
        chip.shiftOut(1, x)
        x = x<<1;
        time.sleep_ms(300)
    x = 0x01
    for count in range(8):
        chip.shiftOut(0, x)
        x = x<<1
        time.sleep_ms(300)