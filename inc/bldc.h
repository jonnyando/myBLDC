#ifndef __BLDC_H__
#define __BLDC_H__

#include <stdint.h>
#include "drv8323.h"
#include "math.h"

typedef struct
{
    uint16_t angle;
    drv8323_TypeDef drv;
    SPI_TypeDef* spi;
    TIM_TypeDef* tim;
    GPIO_TypeDef* enable_port;
    GPIO_TypeDef* cal_port;
    GPIO_TypeDef* nfault_port;
    uint8_t  enable_pin;
    uint8_t  cal_pin;
    uint8_t  nfault_pin;
    uint16_t ADC_samples[6];
    uint16_t ADC_voltage_A;
    uint16_t ADC_voltage_B;
    uint16_t ADC_voltage_C;
    uint16_t ADC_current_A;
    uint16_t ADC_current_B;
    uint16_t ADC_current_C;
    // float real_voltage_A;
    // float real_voltage_B;
    // float real_voltage_C;
    // float real_current_A;
    // float real_current_B;
    // float real_current_C;
    uint16_t target_speed;
    uint32_t duty_cycle_a;
    uint32_t duty_cycle_b;
    uint32_t duty_cycle_c;
    uint8_t  fault;
    /* add FOC stuff here */
} motor_TypeDef;

typedef struct
{
    uint32_t d;
    uint32_t q;
} park_TypeDef;

typedef struct
{
    uint32_t alpha;
    uint32_t beta;
} clarke_TypeDef;

void motor_init_drv(motor_TypeDef* m);
void motor_update(motor_TypeDef* m);
void update_foc_params(motor_TypeDef* m);
void motor_enable(motor_TypeDef *m);

#endif /* __BLDC_H__ */