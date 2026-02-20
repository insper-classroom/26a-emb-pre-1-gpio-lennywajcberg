#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_RED = 28;
const int LED_RED = 4;
const int BTN_GREEN = 26;
const int LED_GREEN = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_RED);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_pull_up(BTN_RED);

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_init(BTN_GREEN);
  gpio_set_dir(BTN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_GREEN);
  
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);
  while (1) {
    if (!gpio_get(BTN_RED)) {
      gpio_put(LED_RED, 1);
      while (!gpio_get(BTN_GREEN)) { }
    }
    else {
      gpio_put(LED_RED, 0);
    }

    if (!gpio_get(BTN_GREEN)) {
      gpio_put(LED_GREEN, 1);
      while (!gpio_get(BTN_GREEN)) { }
    }
    else {
      gpio_put(LED_GREEN, 0);
    }
  }
  return 0;
}
