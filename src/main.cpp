#include <Arduino.h>

// 板载 LED 通常连接在 PC13
#define LED_PIN PC13

void setup() {
    // 初始化串口通信
    Serial.begin(115200);
    Serial.println("STM32F103 LED Blink Test");
    
    // 配置 LED 引脚为推挽输出模式
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // 注意：PC13 是低电平点亮
    digitalWrite(LED_PIN, LOW);    // LED 开
    Serial.println("LED ON");
    delay(1000);
    
    digitalWrite(LED_PIN, HIGH);   // LED 关
    Serial.println("LED OFF");
    delay(1000);
}

// 如果需要更精确的定时，可以使用定时器中断
// 取消注释下面的代码来使用定时器
/*
void timerInit() {
    // 设置定时器中断
    HardwareTimer *timer = new HardwareTimer(TIM1);
    timer->setOverflow(1, HERTZ_FORMAT); // 1Hz = 1秒
    timer->attachInterrupt(timerCallback);
    timer->resume();
}

void timerCallback() {
    static bool ledState = false;
    digitalWrite(LED_PIN, ledState);
    ledState = !ledState;
}
*/