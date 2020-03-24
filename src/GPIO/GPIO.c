#include "stm32f10x.h"											//包含STM32F1系列微控制器的头文件
#define KEY_ON 0
#define KEY_OFF 1  


void delay_ms(unsigned short int Number);		//延时子函数
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;			//声明用于GPIO初始化的结构体
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOE, ENABLE);	//使能GPIOE与GPIOA的时钟
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;	//对P0引脚进行设置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//输出模式选择推挽输出        
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	//输出频率最高为2MHz
  GPIO_Init(GPIOE, &GPIO_InitStructure);		//根据上述配置的参数初始化外设GPIOE
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;	//对P0引脚进行设置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//输入模式选择Floating Input       
  GPIO_Init(GPIOE, &GPIO_InitStructure);		//根据上述配置的参数初始化外设GPIOA

	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == KEY_ON )  
	  {	 
	  	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == KEY_ON);   //等待按键释放
			if (KEY_ON == 0)
				GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			else
				GPIO_SetBits(GPIOA,GPIO_Pin_0);
	   }
		
		 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == KEY_OFF )  
	  {	 
	  	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == KEY_OFF);   //等待按键释放
			if (KEY_OFF == 1)
				GPIO_SetBits(GPIOA, GPIO_Pin_0);
			else
				GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	   }	 
  
	}
}
void delay_ms(unsigned short int Number)
{
    unsigned int i;
     while(Number--){
      i=12000; while(i--);
    }
}

