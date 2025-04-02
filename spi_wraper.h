
#ifndef __SPI_WRAPER__
#define __SPI_WRAPER__

int spi_wraper_init(void);
int spi_wraper_transfer(uint8_t *ptr_tx_data, uint8_t *ptr_rx_data, uint32_t transfer_len);

#endif

