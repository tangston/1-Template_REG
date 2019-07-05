/*���ڿ����ڴ�����Լ�дͷ�ļ��⣬����stm32f10x.h������ʲô���Ǹ�ʲô��*/
/*���ļ�������ӼĴ�����ַ���ṹ�嶨��*/

/*���»������ں˼����˽�б�̣����еĵ�ַ����ͬARM��cortex-M3�ֲ��ﻮ�ֹ涨����*/

/*  SystemInit ��Ҫ�������Լ�ʵ�֣�������Ҫ��дһ�����и����Ƶĺ�����������ʼ��
*   STM32 оƬ��ʱ�ӣ�һ�������ʼ�� AHB��APB �ȸ����ߵ�ʱ�ӣ���Ҫ����һϵ�е���
*   �� STM32 ���ܴﵽ�ȶ����е�״̬��
*   STM32 �ϵ�󣬻�ִ�� SystemInit ���������� STM32 ��ʱ��
*/
#define uint32_t unsigned long int  

/*  �� AHB ����������������� APB2 �� APB1 ���ߣ���������� STM32 ���ָ�����
*   ��ɫ���衣���Ǿ���˵�� GPIO�����ڡ�I2C��SPI ��Щ����͹�����������������
*   ���������ѧϰ STM32 ���ص㣬����Ҫѧ������Щ����ȥ�����ⲿ�ĸ����豸��
*   ARM�淶����������Ƭ�����߱�׼��       1. AHB(Advanced High performance Bus)ϵͳ����,AHB����ͨ�����߾�����ϵͳ��������������DMA���ʴ洢�������߼ܹ�      
*   2.APB(Advanced Peripheral Bus)��Χ�豸����,����AHB/APB����AHB��2��APB���߼��ṩͬ�����ӡ�APB1�����ٶ�����36MHz��APB2������ȫ��(���72MHz)��
*/



/*Ƭ�ϵ���Χ�豸�Ļ���ַ����APB1���������ַ-------------------------*/
#define APB1_base ((unsigned int) 0x40000000)//�����ⷨ�뵼�幫˾���Ĺٷ�STM32F10x�ο��ֲ��еĴ洢��ӳ��_Ƕ��ʽSRAM���ֱ���֪��ַ����
/* ��ʱ��ƫ������ 0x40000000��ƫ������ζ����Ե�ַ�������߼��������۵���ʽ�ԣ�������ҳ����ȫ���޶���SRAM�е���Χ�豸��
*  ������ַ�ҵ����������۵Ķ��������޶��뻮�ֵ������װ����������һ����֪�� ƫ�Ƶ�ַ��ζ�Ÿ�ǰ���µĸ�ģ��ĳ�ʼ��ַ
*  ʹ�û���ַ+ƫ��������ʽ������Ϊ�����ŷ���������֪�Ĺ���
*/


/*APB2 ���߻���ַ----------------------------- */
#define APB2_base       (APB1_base + 0x10000 )
/* ��ʱ��ƫ������ 0x10000 */


/* AHB���ţ�SRAM���ⲿRAM�������������ⲿRAM�����豸#1���豸#2��AHB-APB�Ž�����������������APB��
*
*
*
*    AHB�Ҹ������裬ֻ���� CM3 �ڲ��� AHB ����
*   �����ǣ�NVIC(Nested Vectored Interrupt Controller��Ƕ�����жϿ�������,
*   FPB(Flash Patch Breakpoint�����ַ���ؼ��ϵ㵥Ԫ),
*   DWT(Data Watchpoint and Tracer ���ݹ۲�����ٵ�Ԫ) 
*   ITM(instrumentation trace macrocell�������ٵ�Ԫ)��*/

/* AHB���߻���ַ */
#define AHB_base        (APB1_base + 0x20000)
/* ��ʱ��ƫ������ 0x20000*/


/*GPIOB�������ַ-------------------------------------------------------------------------------*/
#define GPIOB_base            (APB2_base + + 0x0C00)//0x4001 0C00
/* ������ַ��ѯSTM32F10x�����ֲ�洢��ӳ��õ�
*   GPIO:General Purpose Input/Output Port ͨ����������˿�
*   GPIO����ARM���ֵĵ�ַ�У�APB2����ĵ�ַ�飬GPIO���� �˿�A��G��GPIOA...GPIOG��
*   6��13�ţ���ûҪ�������ַ���估��ԭ��ͼ��ֻ��ֱ�ӷ���ѧУ���Ĵ��룬����ѧϰ��
*/


/* ��������������GPIOB�Ĵ�����ַ�����۷�Χ*/
/* CRL  configuration register low�˿ڵ����üĴ��� */
#define GPIOB_CRL			*(unsigned int*)(GPIOE_base+0x00)

/* CRH  configuration register high�˿ڸ����üĴ��� */
#define GPIOB_CRH			*(unsigned int*)(GPIOE_base+0x04)

/* IDR:input data register �����豸�Ĵ���*/
#define GPIOB_IDR			*(unsigned int*)(GPIOE_base+0x08)

/* ODR:output data register ����豸�Ĵ���*/
#define GPIOB_ODR			*(unsigned int*)(GPIOE_base+0x12)

/* BSRR:bit set/reset register��λ/��λ�Ĵ��� */
#define GPIOB_BSRR	  *(unsigned int*)(GPIOE_base+0x10)

/* BRR:bit reset register��λ�Ĵ��� */
#define GPIOB_BRR			*(unsigned int*)(GPIOE_base+0x14)

/* LCKR:lock register�����Ĵ��� */
#define GPIOB_LCKR		*(unsigned int*)(GPIOE_base+0x18)



/*GPIOE�������ַ-------------------------------------------------------------------------------*/
#define GPIOE_base            (APB2_base + + 0x1800)//0x4001 1800
/* ������ַ��ѯSTM32F10x�����ֲ�洢��ӳ��õ�
*   GPIO:General Purpose Input/Output Port ͨ����������˿�
*   GPIO����ARM���ֵĵ�ַ�У�APB2����ĵ�ַ�飬GPIO���� �˿�A��G��GPIOA...GPIOG��
*   6��13�ţ���ûҪ�������ַ���估��ԭ��ͼ��ֻ��ֱ�ӷ���ѧУ���Ĵ��룬����ѧϰ��
*/


/* ��������������GPIOE�Ĵ�����ַ�����۷�Χ */
/* CRL  configuration register low�˿ڵ����üĴ��� */
#define GPIOE_CRL			*(unsigned int*)(GPIOE_base+0x00)

/* CRH  configuration register high�˿ڸ����üĴ��� */
#define GPIOE_CRH			*(unsigned int*)(GPIOE_base+0x04)

/* IDR:input data register �����豸�Ĵ���*/
#define GPIOE_IDR			*(unsigned int*)(GPIOE_base+0x08)

/* ODR:output data register ����豸�Ĵ���*/
#define GPIOE_ODR			*(unsigned int*)(GPIOE_base+0x12)

/* BSRR:bit set/reset register��λ/��λ�Ĵ��� */
#define GPIOE_BSRR	  *(unsigned int*)(GPIOE_base+0x10)

/* BRR:bit reset register��λ�Ĵ��� */
#define GPIOE_BRR			*(unsigned int*)(GPIOE_base+0x14)

/* LCKR:lock register�����Ĵ��� */
#define GPIOE_LCKR		*(unsigned int*)(GPIOE_base+0x18)

/*Ϊʲô����ȫ��32Ϊ��int�أ���Ϊÿ��I/O�˿�λ�������ɱ�̣�Ȼ��I/0�˿ڼĴ������밴32λ�ֱ�����(��������ֻ��ֽڷ���)��*/




/*RCC�������ַ-----------------------*/
/* RCC(Reset Clock Controller)  ��λ��ʱ�ӿ���*/
#define RCC_BASE      (AHB_base + 0x1000)


/*RCC��AHB1ʱ��ʹ��enable�Ĵ�����ַ....ǿ��ת����ָ��*/
#define RCC_APB2ENR		 *(unsigned int*)(RCC_BASE+0x18)



typedef struct
{
  uint32_t EVCR;
  uint32_t MAPR;
  uint32_t EXTICR[4];
} AFIO_TypeDef;


#define AFIO                ((AFIO_TypeDef *) AFIO_BASE)

/*���ù��ܿ�*/
#define AFIO_BASE             (APB2_base + 0x0000)
































