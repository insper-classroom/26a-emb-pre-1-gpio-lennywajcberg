#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN1 = 26;
const int BTN2 = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN1); gpio_set_dir(BTN1, GPIO_IN); gpio_pull_up(BTN1);
  gpio_init(BTN2); gpio_set_dir(BTN2, GPIO_IN); gpio_pull_up(BTN2);

  int cnt1 = 0, cnt2 = 0;
  int last1 = 1;   // pull-up: solto = 1
  int last2 = 1;

  while (1) {
    int now1 = gpio_get(BTN1);
    int now2 = gpio_get(BTN2);

    // Botão 1: borda de descida (1 -> 0)
    if (last1 == 1 && now1 == 0) {
      sleep_ms(20);                 // debounce
      if (gpio_get(BTN1) == 0) {    // confirma
        printf("Botao 1: %d\n", ++cnt1);
      }
    }

    // Botão 2: borda de descida (1 -> 0)
    if (last2 == 1 && now2 == 0) {
      sleep_ms(20);
      if (gpio_get(BTN2) == 0) {
        printf("Botao 2: %d\n", ++cnt2);
      }
    }

    last1 = now1;
    last2 = now2;

    sleep_ms(1); // deixa a simulação "respirar"
  }
}