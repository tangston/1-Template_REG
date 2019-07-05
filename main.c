

#if	0

#inlcude<reg52.h>

void main (void){
	
	P0=0XFE;	//bus ops when it is C51
	
	LED=0;	//bit ops
}


#endif





#include	"stm32f10x.h"
void temp_delay(void);



void temp_delay(void){

    int i=0xffff;
    for(;i>=0;i--){
        ;
    }
}

int main	(void){
	
   /*�������߼�֪ʶ��֪����������������Ҫ���������ṩ��������Ҳ�����׻�˵��ʱ��/����,����͵����ʱûȥ�˽⣬̫����*/
    RCC_APB2ENR |=  1<<0;	//ʹ��AFIO
    RCC_APB2ENR |=  1<<6;  ////ʹ��PORTEʱ��	 
    RCC_APB2ENR |=  1<<3;  //ʹ��PORTBʱ��
    AFIO->MAPR |= 0x02000000; 
    
  /*��ʼ��GPIOE������Ĵ���.���Ĳο��ֲ�8.2.4 �˿�������ݼĴ���(GPIOx_ODR) (x=A..E)
  * ODR32λ��31~16Ϊ������ʼ�ն�Ϊ0��0~16������ʹ�õĲ���
  * ������������Դ���֪��LED L0��L7��GPIOE->ODR��bit0-bit7���������Ǿ��ܿ���LED��������
  * 
  */
  /*��������LED��,���������Ƚ�͵����ʵ����ֻҪ�������ODR��8λ��16λ���ɣ�����λ����1*/
 // GPIOE_ODR &=  ~(0xff<<8);
  
  //GPIOBout(3) //PB3 ��ʾλ��ѡ��
  
  /*���ö˿ڵ�ģʽλmode������λconfiguration������Ϊͨ���������push-pull 
  *  bin 0011 0011 0011 0011 0011 0011 0011 0011��GPIOE->CRL��8��led����Ϊͨ���������+50MHZ
  *  һ��LED�������Ҫ����2λ��config+2λ��mode����STM32���Ĳο��ֲ�8.2 GPIO�Ĵ���������
  *  ��16λcrl����ǰ�˸�ODR����16λͬ��
  *  �����ܹ�32λֻ������16��ODR������16��ODR����Ӧ������������
  */
    GPIOB_CRL &=    0x0;
    GPIOB_CRL |=    0x00003000;///���ø��ù���Ķ˿�B,PortB3,P3�������������orLED����P0-2������ܵĶ�ѡ
  	GPIOB_ODR |=    0x00000008; //PortB3 ����λ����ߵ�ƽ
  
    GPIOE_CRH &=    0x0;
    GPIOE_CRH |=    0x44444444;//PortE����������и�λ+MAX50MHZ
  
  /*����LED�����ŵ�ƽ�ߵ�
  * bin01010101=0x99
  * 10101010
  */

  while(1){
  //������ 
    GPIOE_ODR = 0xff00;
    temp_delay();
    GPIOE_ODR = 0x00ff;
  
  }
}



void SystemInit(void)
{
	//��ֹ����������
	;
}





