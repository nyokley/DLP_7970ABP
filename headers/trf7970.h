#ifndef TRF7970_H
#define TRF7970_H

#include <stdbool.h>
#include <stdint.h>

extern _Bool IRQ_SHOULD_READ;
extern uint8_t IRQ_STAT;
void trf7970_init();

#endif
