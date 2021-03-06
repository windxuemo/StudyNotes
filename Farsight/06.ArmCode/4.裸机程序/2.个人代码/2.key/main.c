/*************************************************************************
	> File Name: main.c
	> Author: 杨玉春
	> Mail: www762268.@foxmail.come 
	> Created Time: 2016年08月28日 星期日 20时38分10秒
 ************************************************************************/
#include <exynos_4412.h>
#include <led.h>
#include <key.h>
#include <pwm.h> 

void mydelay_ms(int ms);
/**********************************************************************
 * @brief		mydelay_ms program body
 * @param[in]	int (ms)
 * @return 		None
 **********************************************************************/
void mydelay_ms(int ms)
{
	int i, j;
	while(ms--)
	{
		for (i = 0; i < 5; i++)
			for (j = 0; j < 514; j++);
	}
}


/*-------------------------MAIN FUNCTION------------------------------*/
/**********************************************************************
 * @brief		Main program body
 * @param[in]	None
 * @return 		int
 **********************************************************************/
int main(void)
{
	/*1.LED初始化*/
 	LED_Init();
	key_init();

	while(1)
	{
		LED_ON(2);
		mydelay_ms(500);
		LED_OFF(2);
		mydelay_ms(500);
	}
}
