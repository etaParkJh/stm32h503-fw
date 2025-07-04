#include "hw.h"
#include "lcd/st7701.h"



extern uint32_t _fw_flash_begin;
extern uint32_t _sdram_buf_size;
extern uint32_t _sdram_buf_used;

volatile const firm_ver_t firm_ver __attribute__((section(".version"))) = 
{
  .magic_number = VERSION_MAGIC_NUMBER,
  .version_str  = _DEF_FIRMWATRE_VERSION,
  .name_str     = _DEF_BOARD_NAME,
  .firm_addr    = (uint32_t)&_fw_flash_begin
};




bool hwInit(void)
{
  bspInit();

  #ifdef _USE_HW_CLI
  cliInit();
  #endif

  ledInit();
//  buttonInit();
//  i2cInit();
////  spiInit();
//  uartInit();
//  for (int i=0; i<HW_UART_MAX_CH; i++)
//  {
//    uartOpen(i, 115200);
//  }
//
//  logOpen(HW_LOG_CH, 115200);
//  logPrintf("\r\n[ Firmware Begin... ]\r\n");
//  logPrintf("Booting..Name \t\t: %s\r\n", _DEF_BOARD_NAME);
//  logPrintf("Booting..Ver  \t\t: %s\r\n", _DEF_FIRMWATRE_VERSION);
//  logPrintf("Booting..Clock\t\t: %d Mhz\r\n", (int)HAL_RCC_GetSysClockFreq()/1000000);
//  logPrintf("\n");
//
//  rtcInit();
////  resetInit();
////  faultInit();
//  eepromInit();
//  sdramInit();
////  qspiInit();
////  spiFlashInit();
////  flashInit();
////  fsInit();
////  nvsInit();
//
//  pwmInit();
////  fatfsInit();
////  usbInit();
////  usbBegin(USB_CDC_MODE);
////  cdcInit();
////  touchInit();
////  lcdInit();
//
////  logPrintf("[  ] SDRAM SIZE : %d\n", (uint32_t)&_sdram_buf_size);
////  logPrintf("[  ] SDRAM USED : %d\n", (uint32_t)&_sdram_buf_used);
  return true;
}
