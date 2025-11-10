#include "stm32f4xx.h"

void delay(volatile uint32_t s) {
    for (; s > 0; s--);
}

int main(void) {
    // Enable GPIOC clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Set PC13 as output
    GPIOC->MODER &= ~(0x3 << (13 * 2)); // Clear mode bits
    GPIOC->MODER |=  (0x1 << (13 * 2)); // Set as general purpose output

    while (1) {
        // Toggle PC13
        GPIOC->ODR ^= (1 << 13);
        delay(1000000);
    }
}
