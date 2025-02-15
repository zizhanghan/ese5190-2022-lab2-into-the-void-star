/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "ws2812.h"


#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#define IS_RGBW true
#define NUM_PIXELS 150

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 12
#endif
int main() {
    stdio_init_all();
    gpio_init(11);
    gpio_set_dir(11, GPIO_OUT);
    gpio_put(11, 1);
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
      while (true) {
        printf("Hello, world!\n");
        sleep_ms(500);
        set_neopixel_color(0x00337788);
        sleep_ms(500);
        printf("see you!\n");
        set_neopixel_color(0);
	 sleep_ms(500);

    }
    return 0;
}
