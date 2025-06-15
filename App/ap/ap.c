#include "ap.h"

bool isKeepLoop(void);

void apInit (void)
{
	#ifdef _USE_HW_CLI
  cliOpen(_DEF_UART1, 115200);
  #endif


}


void apMain (void)
{
	uint32_t pre_time;

	pre_time = millis ();
	while (isKeepLoop())
	{
		if (millis () - pre_time >= 500)
		{
			pre_time = millis ();
			ledToggle (_DEF_LED1);
		}
	}
}

bool isKeepLoop(void)
{
  bool ret = true;

#ifdef _USE_HW_CLI
  cliMain();
#endif

  return ret;
}

