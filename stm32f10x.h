/*本节课属于带大家自己写头文件库，明白stm32f10x.h到底有什么，是干什么的*/
/*本文件用于添加寄存器地址及结构体定义*/

/*以下还属于内核级别的私有编程，所有的地址都是同ARM在cortex-M3手册里划分规定死的*/

/*  SystemInit 需要由我们自己实现，即我们要编写一个具有该名称的函数，用来初始化
*   STM32 芯片的时钟，一般包括初始化 AHB、APB 等各总线的时钟，需要经过一系列的配
*   置 STM32 才能达到稳定运行的状态。
*   STM32 上电后，会执行 SystemInit 函数来配置 STM32 的时钟
*/
#define uint32_t unsigned long int  

/*  从 AHB 总线延伸出来的两条 APB2 和 APB1 总线，上面挂载着 STM32 各种各样的
*   特色外设。我们经常说的 GPIO、串口、I2C、SPI 这些外设就挂载在这两条总线上
*   这个是我们学习 STM32 的重点，就是要学会编程这些外设去驱动外部的各种设备。
*   ARM规范的两个外设片上总线标准：       1. AHB(Advanced High performance Bus)系统总线,AHB外设通过总线矩阵与系统总线相连，允许DMA访问存储器和总线架构      
*   2.APB(Advanced Peripheral Bus)外围设备总线,两个AHB/APB桥在AHB和2个APB总线间提供同步连接。APB1操作速度限于36MHz，APB2操作于全速(最高72MHz)。
*/



/*片上的外围设备的基地址，即APB1总线外设地址-------------------------*/
#define APB1_base ((unsigned int) 0x40000000)//查找意法半导体公司给的官方STM32F10x参考手册中的存储器映像_嵌入式SRAM部分表格可知地址在哪
/* 此时的偏移量是 0x40000000，偏移量意味着相对地址，根据逻辑的三段论的形式性，我们这页内容全部限定在SRAM中的外围设备上
*  当基地址找到后，所有讨论的东西都被限定与划分得明明白白清清楚楚，一看就知道 偏移地址意味着该前提下的该模块的初始地址
*  使用基地址+偏移量的形式，是因为这样才符合人类认知的规律
*/


/*APB2 总线基地址----------------------------- */
#define APB2_base       (APB1_base + 0x10000 )
/* 此时的偏移量是 0x10000 */


/* AHB挂着：SRAM、外部RAM控制器（它挂外部RAM）、设备#1、设备#2、AHB-APB桥接器（它挂外设总线APB）
*
*
*
*    AHB挂高速外设，只用于 CM3 内部的 AHB 外设
*   它们是：NVIC(Nested Vectored Interrupt Controller内嵌向量中断控制器）,
*   FPB(Flash Patch Breakpoint闪存地址重载及断点单元),
*   DWT(Data Watchpoint and Tracer 数据观测与跟踪单元) 
*   ITM(instrumentation trace macrocell测量跟踪单元)。*/

/* AHB总线基地址 */
#define AHB_base        (APB1_base + 0x20000)
/* 此时的偏移量是 0x20000*/


/*GPIOB外设基地址-------------------------------------------------------------------------------*/
#define GPIOB_base            (APB2_base + + 0x0C00)//0x4001 0C00
/* 上述地址查询STM32F10x中文手册存储器映像得到
*   GPIO:General Purpose Input/Output Port 通用输入输出端口
*   GPIO是在ARM划分的地址中，APB2里面的地址块，GPIO共有 端口A到G（GPIOA...GPIOG）
*   6月13号，还没要到外设地址分配及其原理图，只能直接翻阅学校给的代码，慢速学习了
*/


/* 以下区块限制在GPIOB寄存器地址的讨论范围*/
/* CRL  configuration register low端口低配置寄存器 */
#define GPIOB_CRL			*(unsigned int*)(GPIOE_base+0x00)

/* CRH  configuration register high端口高配置寄存器 */
#define GPIOB_CRH			*(unsigned int*)(GPIOE_base+0x04)

/* IDR:input data register 输入设备寄存器*/
#define GPIOB_IDR			*(unsigned int*)(GPIOE_base+0x08)

/* ODR:output data register 输出设备寄存器*/
#define GPIOB_ODR			*(unsigned int*)(GPIOE_base+0x12)

/* BSRR:bit set/reset register置位/复位寄存器 */
#define GPIOB_BSRR	  *(unsigned int*)(GPIOE_base+0x10)

/* BRR:bit reset register复位寄存器 */
#define GPIOB_BRR			*(unsigned int*)(GPIOE_base+0x14)

/* LCKR:lock register锁定寄存器 */
#define GPIOB_LCKR		*(unsigned int*)(GPIOE_base+0x18)



/*GPIOE外设基地址-------------------------------------------------------------------------------*/
#define GPIOE_base            (APB2_base + + 0x1800)//0x4001 1800
/* 上述地址查询STM32F10x中文手册存储器映像得到
*   GPIO:General Purpose Input/Output Port 通用输入输出端口
*   GPIO是在ARM划分的地址中，APB2里面的地址块，GPIO共有 端口A到G（GPIOA...GPIOG）
*   6月13号，还没要到外设地址分配及其原理图，只能直接翻阅学校给的代码，慢速学习了
*/


/* 以下区块限制在GPIOE寄存器地址的讨论范围 */
/* CRL  configuration register low端口低配置寄存器 */
#define GPIOE_CRL			*(unsigned int*)(GPIOE_base+0x00)

/* CRH  configuration register high端口高配置寄存器 */
#define GPIOE_CRH			*(unsigned int*)(GPIOE_base+0x04)

/* IDR:input data register 输入设备寄存器*/
#define GPIOE_IDR			*(unsigned int*)(GPIOE_base+0x08)

/* ODR:output data register 输出设备寄存器*/
#define GPIOE_ODR			*(unsigned int*)(GPIOE_base+0x12)

/* BSRR:bit set/reset register置位/复位寄存器 */
#define GPIOE_BSRR	  *(unsigned int*)(GPIOE_base+0x10)

/* BRR:bit reset register复位寄存器 */
#define GPIOE_BRR			*(unsigned int*)(GPIOE_base+0x14)

/* LCKR:lock register锁定寄存器 */
#define GPIOE_LCKR		*(unsigned int*)(GPIOE_base+0x18)

/*为什么上面全是32为的int呢？因为每个I/O端口位可以自由编程，然而I/0端口寄存器必须按32位字被访问(不允许半字或字节访问)。*/




/*RCC外设基地址-----------------------*/
/* RCC(Reset Clock Controller)  复位与时钟控制*/
#define RCC_BASE      (AHB_base + 0x1000)


/*RCC的AHB1时钟使能enable寄存器地址....强制转换成指针*/
#define RCC_APB2ENR		 *(unsigned int*)(RCC_BASE+0x18)



typedef struct
{
  uint32_t EVCR;
  uint32_t MAPR;
  uint32_t EXTICR[4];
} AFIO_TypeDef;


#define AFIO                ((AFIO_TypeDef *) AFIO_BASE)

/*复用功能口*/
#define AFIO_BASE             (APB2_base + 0x0000)
































