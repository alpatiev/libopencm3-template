#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main(void) {
	rcc_periph_clock_enable(RCC_GPIOC);

	gpio_set_mode (
		GPIOC,
		GPIO_MODE_OUTPUT_2_MHZ,
		GPIO_CNF_OUTPUT_PUSHPULL,
		GPIO13
	);

	while (1) {
		// 1 * 10^7 - const
		// 1 * 10^6 - around second
		// 1 * 10^5 - 100ms

		for (int i = 0; i < 100000; i++) {
			__asm__("nop");
		}

		gpio_toggle(GPIOC, GPIO13);
	}

	return 0;
}
