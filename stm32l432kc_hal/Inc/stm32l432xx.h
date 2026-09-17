/**
  ******************************************************************************
  * @file    stm32l432xx.hasd
  * @author  Fawad
  * @brief   CMSIS STM32L432xx Device Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  */
/** @addtogroup Memory_map
  * @{
  */
/*BASE MEMORY MAPPED ADDRESSES*/
#define CODE_BASE                           (0x00000000UL)                      /*CODE base*/
#define SRAM1_BASE                          (0x20000000UL)                      /*SRAM1 base*/
#define PERIPHERAL_BASE                     (0x40000000UL)                      /*PERIPHERAL base*/
#define QUADSPI_FLASHBANK_BASE              (0x90000000UL)                      /*QUADSPI_FLASHBANK base*/
#define QUADSPI_REGISTER_BASE               (0xA0001000UL)                      /*QUADSPI_REGISTER base*/
#define FPU_PERIPHERALS_BASE                (0xE0000000UL)                      /*FPU_PERIPHERALS base*/
/**
  * @}
  */

/** @addtogroup Code Area Registers
  * @{
  */
/*BASE MEMORY MAPPED ADDRESSES*/
#define BOOT_CONFIGURED_MEMORY              (CODE_BASE)                         /*Based on configuration either Flash or System Memory or SRAM */
#define FLASH_BASE                          (CODE_BASE + 0x8000000UL)           /*Flash of 256 KB starts*/
#define FLASH_END                           (0x0803FFFFUL)                      /*Flash End = FLASH_BASE + SIZE - 1 
                                                                                /* 256 KB = 256 *1024 = 202144 bytes or 0x40000 
                                                                                /* 0x08000000 + 0x40000 - 1 = 0x0803FFFF*/
#define SRAM_BASE                           (SRAM1_BASE)
#define SRAM2_BASE                          (CODE_BASE + 0x10000000UL)          /*Upto 16KB base address*/
#define SYSTEM_MEMORY_BASE                  (CODE_BASE + 0x1FFF0000UL)          /*System Memory base address*/
#define OTP_BASE                            (CODE_BASE + 0x1FFF7000UL)          /*OTP base address*/
#define OPTION_BYTE_BASE                    (CODE_BASE + 0x1FFF7800UL)          /*Option byte base address*/
/*Size of SRAM1 and SRAM2*/
#define SRAM1_SIZE_MAX                      (0x0000C000UL)                      /*!< maximum SRAM1 size (up to 48 KBytes) */
#define SRAM2_SIZE                          (0x00004000UL)                      /*!< SRAM2 size (16 KBytes) */
/**
  * @}
  */
  
/** @addtogroup Peripheral Area Registers
  * @{
  */
#define APB1PERIPH_BASE                     (PERIPHERAL_BASE)                   /*Advanced Peripheral Bus 1*/
#define APB2PERIPH_BASE                     (PERIPHERAL_BASE + 0x0010000UL)     /*Advanced Peripheral Bus 2*/
#define AHB1PERIPH_BASE                     (PERIPHERAL_BASE + 0x0020000UL)     /*Advanced High Performance Bus 1*/
#define AHB2PERIPH_BASE                     (PERIPHERAL_BASE + 0x0800000UL)     /*Advanced High Performance Bus 2*/
/**
  * @}
  */

/** @addtogroup APB1 Registers
  * @{
  */
#define TIM2_BASE                           (APB1PERIPH_BASE + 0x0000UL)        /*TIMx Register*/
#define TIM6_BASE                           (APB1PERIPH_BASE + 0x1000UL)        /*TIMx Register*/
#define TIM7_BASE                           (APB1PERIPH_BASE + 0x1400UL)        /*TIMx Register*/
#define RTC_BASE                            (APB1PERIPH_BASE + 0x2800UL)        /*RTC Register*/
#define WWDG_BASE                           (APB1PERIPH_BASE + 0x2C00UL)        /*WWDG Register*/
#define IWDG_BASE                           (APB1PERIPH_BASE + 0x3000UL)        /*IWDG Register*/
#define SPI2_BASE                           (APB1PERIPH_BASE + 0x3800UL)        /*SPI2 Register*/
#define SPI3_BASE                           (APB1PERIPH_BASE + 0x3C00UL)        /*SPI3 Register*/
#define USART2_BASE                         (APB1PERIPH_BASE + 0x4400UL)        /*USART2 Register*/
#define USART3_BASE                         (APB1PERIPH_BASE + 0x4800UL)        /*USART3 Register*/
#define I2C1_BASE                           (APB1PERIPH_BASE + 0x5400UL)        /*I2C1 Register*/
#define I2C2_BASE                           (APB1PERIPH_BASE + 0x5800UL)        /*I2C2 Register*/
#define I2C3_BASE                           (APB1PERIPH_BASE + 0x5C00UL)        /*I2C3 Register*/
#define CRS_BASE                            (APB1PERIPH_BASE + 0x6000UL)        /*CRS Register*/
#define CAN1_BASE                           (APB1PERIPH_BASE + 0x6400UL)        /*CAN1 Register*/
#define USBFS_BASE                          (APB1PERIPH_BASE + 0x6800UL)        /*USBFS Register - !< USB_IP Peripheral Registers base address*/
#define USB_SRAM_BASE                       (APB1PERIPH_BASE + 0x6800UL)        /*USB_SRAM Register - !< < USB_IP Packet Memory Area base address */
#define PWR_BASE                            (APB1PERIPH_BASE + 0x7000UL)        /*PWR Register*/
#define DAC1_BASE                           (APB1PERIPH_BASE + 0x7400UL)        /*DAC1 Register*/
#define OPAMP_BASE                          (APB1PERIPH_BASE + 0x7800UL)        /*OPAMP Register*/
#define LPTIM1_BASE                         (APB1PERIPH_BASE + 0x7C00UL)        /*LPTIM1 Register*/
#define LPUART1_BASE                        (APB1PERIPH_BASE + 0x8000UL)        /*LPUART1 Register*/
#define SWPMI1_BASE                         (APB1PERIPH_BASE + 0x8800UL)        /*SWMPI1 Register*/
#define LPTIM2_BASE                         (APB1PERIPH_BASE + 0x9400UL)        /*LPTIM2 Register*/
/**
  * @}
  */


/** @addtogroup APB2 Registers
  * @{
  */
#define SYSCFG_BASE                         (APB2PERIPH_BASE + 0x0000UL)        /*SYSCFG Register*/
#define VREFBUF_BASE                        (APB2PERIPH_BASE + 0x0030UL)        /*VREFBUF Register*/
#define COMP_BASE                           (APB2PERIPH_BASE + 0x0200UL)        /*COMP Register*/
#define EXTI_BASE                           (APB2PERIPH_BASE + 0x0400UL)        /*EXTI Register*/
#define FIREWALL_BASE                       (APB2PERIPH_BASE + 0x1C00UL)        /*FIREWALL Register*/
#define TIM1_BASE                           (APB2PERIPH_BASE + 0x2C00UL)        /*TIM1 Register*/
#define SPI1_BASE                           (APB2PERIPH_BASE + 0x3000UL)        /*SPI1 Register*/
#define USART1_BASE                         (APB2PERIPH_BASE + 0x3800UL)        /*USART1 Register*/
#define TIM15_BASE                          (APB2PERIPH_BASE + 0x4000UL)        /*TIM15 Register*/
#define TIM16_BASE                          (APB2PERIPH_BASE + 0x4400UL)        /*TIM16 Register*/
#define SAI1_BASE                           (APB2PERIPH_BASE + 0x5400UL)        /*SAI1 Register*/
#define DFSDM1_BASE                         (APB2PERIPH_BASE + 0x6000UL)        /*DFSDM1 Register*/


/**
  * @}
  */

/** @addtogroup AHB1 Registers
  * @{
  */
#define DMA1_BASE                           (AHB1PERIPH_BASE + 0x0000UL)        /*DMA1 Register*/
#define DMA2_BASE                           (AHB1PERIPH_BASE + 0x0400UL)        /*DMA2 Register*/
#define RCC_BASE                            (AHB1PERIPH_BASE + 0x1000UL)        /*RCC Register*/
#define FLASH_R_BASE                        (AHB1PERIPH_BASE + 0x2000UL)        /*FLASH_R_BASE Register*/
#define CRC_BASE                            (AHB1PERIPH_BASE + 0x3000UL)        /*CRC Register*/
#define TSC_BASE                            (AHB1PERIPH_BASE + 0x4000UL)        /*TSC Register*/
/**
  * @}
  */


/** @addtogroup AHB2 Registers
  * @{
  */
#define GPIOA_BASE                          (AHB2PERIPH_BASE + 0x0000UL)        /*GPIOA Register*/
#define GPIOB_BASE                          (AHB2PERIPH_BASE + 0x0400UL)        /*GPIOB Register*/
#define GPIOC_BASE                          (AHB2PERIPH_BASE + 0x0800UL)        /*GPIOC Register*/
#define GPIOH_BASE                          (AHB2PERIPH_BASE + 0x1C00UL)        /*GPIOH Register*/
#define ADC_BASE                            (AHB2PERIPH_BASE + 0x08040000UL)        /*ADC Register*/
#define RNG_BASE                            (AHB2PERIPH_BASE + 0x08060800UL)        /*RNG Register*/
/**
  * @}
  */
