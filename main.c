

#if	0

#inlcude<reg52.h>

void main (void){
	
	P0=0XFE;	//bus ops
	
	LED=0;	//bit ops
}


#endif





#include	"stm32f10x.h"
void temp_delay(void);



void temp_delay(void){

    int i=0xfffff;
    for(;i!=0;i--){
        ;
    }
}

int main	(void){
	
   /*由数字逻辑知识可知，触发器的启动需要方波振动来提供驱动力，也就是俗话说的时钟/节拍,这里偷懒暂时没去了解，太困了*/
    RCC_APB2ENR |=  1<<0;	//使能AFIO
    RCC_APB2ENR |=  1<<6;  ////使能PORTE时钟	 
    RCC_APB2ENR |=  1<<3;  //使能PORTB时钟
    
    
    
    
  /*初始化GPIOE的输出寄存器.中文参考手册8.2.4 端口输出数据寄存器(GPIOx_ODR) (x=A..E)
  * ODR32位中31~16为保留，始终读为0。0~16是我们使用的部分
  * 查阅宁晓兰的源码可知，LED L0到L7是GPIOE->ODR的bit0-bit7，这样我们就能控制LED的明灭了
  * 
  */
  /*首先清零LED灯,这里做法比较偷懒，实际上只要做到清空ODR的8位到16位即可，其他位与上1*/
 // GPIOE_ODR &=  ~(0xff<<8);
  
  //GPIOBout(3) //PB3 显示位置选择
  
  /*设置端口的模式位mode与配置位configuration。设置为通用推挽输出push-pull 
  *  bin 0011 0011 0011 0011 0011 0011 0011 0011是GPIOE->CRL将8个led配置为通用推挽输出+50MHZ
  *  一个LED的输出，要配置2位的config+2位的mode（见STM32中文参考手册8.2 GPIO寄存器描述）
  *  低16位crl配置前八个ODR。高16位同理。
  *  所以总共32位只能配置16个ODR，另外16个ODR理所应当保留了下来
  */
    GPIOB_CRL &=    0xFFFF0000;
    GPIOB_CRL |=    0x00003333;///配置复用管理的端口B,PortB 0-3,P3决定是数码管亮orLED亮，P0-2是数码管的段选
  	GPIOB_ODR |=    0x000000FF; //PortB低0到15输出高电平
  
    GPIOE_CRH &=    0X00000000;
    GPIOE_CRH |=    0x33333333;//PortE推挽输出所有位+MAX50MHZ
  
  
  /*配置LED灯引脚电平高低
  * bin01010101=0x99
  * 10101010
  */
 
  while(1){
  //主程序 
  GPIOE_ODR &= ~(0xff<<8);//清除LED灯、即
  GPIOE_ODR |= 0x99<<8;
  temp_delay();
  GPIOE_ODR &= (0x1<<3);
  GPIOE_ODR |= 0x99<<9;
  
  }
}



void SystemInit(void)
{
	//防止编译器报错
	;
}





