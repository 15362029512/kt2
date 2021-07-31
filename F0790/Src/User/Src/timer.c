/* Includes ------------------------------------------------------------------*/
#include "timer.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/ 
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/* global variables ----------------------------------------------------------*/
uint16_t g_timer0_10ms_cnt = TIMER0_10MS_CNT;
uint16_t g_timer0_5ms_cnt = TIMER0_5MS_CNT;

uint16_t g_timer0_20ms_cnt = TIMER0_20MS_CNT;
uint16_t g_timer0_200ms_cnt = TIMER0_200MS_CNT;
uint16_t g_timer0_2s_cnt = TIMER0_2S_CNT;

uint8_t flag_50ms = 0;
uint8_t flag_10ms = 0;
uint8_t flag_20ms = 0;
uint8_t flag_100ms = 0;
uint8_t flag_200ms = 0;
uint8_t flag_2s = 0;



/*------------------------------------------------------------------------------------------------------------------------------------------*/
/***@函数名称：   timer_init
    @函数功能：   timer_init
    @入口参数：   无
    @出口参数：   无
    @备注说明：   时钟为系统时钟 12 分频 timer0 1ms中断一次用于基本定时
                   timer1 100us中断一次用于语音IC双线通信
*/
/*------------------------------------------------------------------------------------------------------------------------------------------*/
void timer_init(void)
{ 
    TMOD=(TMOD&0xCC)|0x21;                                      //定时器0：模式1 ，16位定时器     --定时器1：模式2 ，8位定时器    
#if (SYSCLK_SRC == IRCH)
    TL0 = 0xcc;                             
    TH0 = 0xfe;                             // 1ms
#elif  (SYSCLK_SRC == PLL)
    TL0 = 0xcc;                             
    TH0 = 0xf8;                             // 1ms
#endif
	TR0 = 1;																	//开启定时器0
	ET0 = 1;			//定时器0 允许中断

    ET1 = 1;																	//定时器1 允许中断
}






