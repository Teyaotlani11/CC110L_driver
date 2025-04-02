#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <unistd.h>
#include "spi_wraper.h"

static const uint8_t mode = 0;
static const uint32_t speed = 4000000;
static const uint8_t bits = 8;


static int spi_dscptr;

int spi_wraper_init(void)
{
    spi_dscptr = open("/dev/spidev0.0", O_RDWR);
    if (spi_dscptr < 0)
    {
        printf("Error opening SPI dev");
        return -1;
    }

    if (ioctl(spi_dscptr, SPI_IOC_WR_MODE, &mode) < 0)
    {
        printf("Error setting SPI mode");
        close(spi_dscptr);
        return -1;
    }

    
    if (ioctl(spi_dscptr, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0)
    {
        printf("Error setting SPI speed");
        close(spi_dscptr);
        return -1;
    }

    
    if (ioctl(spi_dscptr, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0)
    {
        printf("Error setting SPI bits");
        close(spi_dscptr);
        return -1;
    }

    return 0;
}

int spi_wraper_transfer(uint8_t *ptr_tx_data, uint8_t *ptr_rx_data, uint32_t transfer_len)
{
    #define SINGLE_TRANSFER 1
    int ret_val = -1;

    struct spi_ioc_transfer spi_trsfr = 
    {
        .rx_buf = (unsigned long)ptr_rx_data,
        .tx_buf = (unsigned long)ptr_tx_data,
        .len = transfer_len
    };

    if ( (ptr_tx_data != NULL) && (ptr_rx_data != NULL) && (spi_dscptr >= 0) )
    {
        ret_val = ioctl (spi_dscptr, SPI_IOC_MESSAGE(SINGLE_TRANSFER), &spi_trsfr);
    }

    return ret_val;
}

