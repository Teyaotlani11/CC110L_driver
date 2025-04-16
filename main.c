#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "spi_wraper.h"

int main (void)
{
    uint8_t tx_transfer[2];
    uint8_t rx_transfer[2];
    t_spi_wraper_cfg s_spi_cfg;
    s_spi_cfg.u8_mode = 0;
    s_spi_cfg.u32_speed = 4000000;
    s_spi_cfg.u8_bits = 8;

    tx_transfer[0] = 0x31 | 0xC0;
    tx_transfer[1] = 0;

    spi_wraper_init(&s_spi_cfg);

    spi_wraper_transfer(tx_transfer, rx_transfer, 2);

    printf("status     : %x\n", rx_transfer[0]); 
    printf("part number: %x\n", rx_transfer[1]);

    sleep(3);

    return 0;
}

