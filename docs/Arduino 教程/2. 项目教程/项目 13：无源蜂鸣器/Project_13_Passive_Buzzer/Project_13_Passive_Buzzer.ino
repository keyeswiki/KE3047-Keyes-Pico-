//**********************************************************************
/*
 * 文件名 : 无源蜂鸣器
 * 描述 : 无源蜂鸣器发出警报.
 * 作者 : www.keyes-robot.com
*/
#define PIN_BUZZER 16   //蜂鸣器引脚定义

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
    alert();
}

void alert() {
  float sinVal;         // 定义一个变量来保存sinVal
  int toneVal;          // 定义一个变量来保存声音频率
  for (int x = 0; x < 360; x += 10) {     // X从0-360
    sinVal = sin(x * (PI / 180));       // 计算sinx
    toneVal = 2000 + sinVal * 500;      // 根据sinx计算声音的频率
    freq(PIN_BUZZER, toneVal, 10);
  }
}

void freq(int PIN, int freqs, int times) {
  if (freqs == 0) {
    digitalWrite(PIN, LOW);
  }
  else {
    for (int i = 0; i < times * freqs / 1000; i ++) {
      digitalWrite(PIN, HIGH);
      delayMicroseconds(1000000 / freqs / 2);
      digitalWrite(PIN, LOW);
      delayMicroseconds(1000000 / freqs / 2);
    }
  }
}
//**********************************************************************
