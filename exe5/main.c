#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN1 = 26;
const int BTN2 = 28;

int main() {
  stdio_init_all();

  gpio_init(BTN1); gpio_set_dir(BTN1, GPIO_IN); gpio_pull_up(BTN1);
  gpio_init(BTN2); gpio_set_dir(BTN2, GPIO_IN); gpio_pull_up(BTN2);

  int cnt1 = 0, cnt2 = 0;

  while (1) {
    if (gpio_get(BTN1) == 0) {
      sleep_ms(20);
      if (gpio_get(BTN1) == 0) {
        printf("Botao 1: %d\n", ++cnt1);
        while (gpio_get(BTN1) == 0) { }
        sleep_ms(20);
      }
    }

    if (gpio_get(BTN2) == 0) {
      sleep_ms(20);
      if (gpio_get(BTN2) == 0) {
        printf("Botao 2: %d\n", ++cnt2);
        while (gpio_get(BTN2) == 0) { }
        sleep_ms(20);
      }
    }
  }
}