
#ifndef __SPI_WRAPER__
#define __SPI_WRAPER__

/**************************/
/* Data Types Definitons  */
/**************************/
typedef struct _spi_cfg
{   
   uint32_t u32_speed;
   uint8_t  u8_mode;
   uint8_t  u8_bits;
} t_spi_wraper_cfg;

/**************************/
/* Function Declarations  */
/**************************/
int spi_wraper_init(t_spi_wraper_cfg const * const ps_spi_cfg);
int spi_wraper_transfer(uint8_t *ptr_tx_data, uint8_t *ptr_rx_data, uint32_t transfer_len);

#endif

