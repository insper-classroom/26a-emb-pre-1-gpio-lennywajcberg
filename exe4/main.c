#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int RED_LED = 5;
const int PRP_LED = 8;
const int BLU_LED = 11;
const int YEL_LED = 15;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(RED_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);
  gpio_init(PRP_LED);
  gpio_set_dir(PRP_LED, GPIO_OUT);
  gpio_init(BLU_LED);
  gpio_set_dir(BLU_LED, GPIO_OUT);
  gpio_init(YEL_LED);
  gpio_set_dir(YEL_LED, GPIO_OUT);

  while (true) {
    if (gpio_get(BTN_PIN) == 0) {
      gpio_put(RED_LED, 1);
      sleep_ms(300);
      gpio_put(RED_LED, 0);
      gpio_put(PRP_LED, 1);
      sleep_ms(300);
      gpio_put(PRP_LED, 0);
      gpio_put(BLU_LED, 1);
      sleep_ms(300);
      gpio_put(BLU_LED, 0);
      gpio_put(YEL_LED, 1);
      sleep_ms(300);
      gpio_put(YEL_LED, 0);
}
}
}