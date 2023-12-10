
#include "main.h"
#include "gpio.h"

/* USER CODE BEGIN PTD */
int n,m;
uint16_t a,b,c,d;
uint16_t x,i,mode;
/* USER CODE END PTD */

void SystemClock_Config(void);
/* USER CODE BEGIN 0 */
void batled(int n,int c){
if(n==2){
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
						HAL_Delay(c);
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
						HAL_Delay(20-c);		
			}
if(n==1){
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
						HAL_Delay(c);
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
						HAL_Delay(20-c);
			}
if(n==0){
			
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
						HAL_Delay(c);
						HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
						HAL_Delay(20-c);
			}
}
void tatled(int n){
	if(n==0) HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	if(n==1) HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
	if(n==0) {
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	}
}
void nut1(int i)
{
	
}
/* USER CODE END 0 */
int main(void)
{
 
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	c=10;
	mode=1;
  /* USER CODE END 2 */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1)x=1;
				if(x==1){
						i++;
						if(m==0) HAL_Delay(20);
						if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==0)x=0;
				}
				if(0<i&&i<30&&x==0){
						n++;
						if(n>=3)n=0;
						i=0;
				}
				if(i>=30&&x==0) {
							m++;
							if(m>=2)m=0;
							if(x==0)i=0;
					}
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0)a=1;
				if(a==1){
						b++;
						if(m==0) HAL_Delay(20);
						if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1) a=2;
					}
					if(0<b&&b<40&&a==2){
							if(mode==1) c=c+5;
							if(mode==0) c=c-5;
							b=0;
					}
						if(b>=40) {
							if(mode==1){
								if(c<20){
									c=c+5;
									b=0;
									}
								}
									if(mode==0){
									if(c>0){
									c=c-5;
									b=0;
									if(c>20) c=0;
									}
								}
						}
					if(b>40&&a==2)b=0;
					if(c>=20&&a==2) mode=0;
					if(c<=0&&a==2) {
						mode=1;
						m=0;
					}
					if(c>0&&a==1)	m=1;
					if(m==1&&c!=0) batled(n,c);
					if(m==0) tatled(n);
					
					
	}
  /* USER CODE END 3 */
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
 
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler(void)
{
  
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */

