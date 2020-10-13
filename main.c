 //*****************************************************************************
//
// Copyright (C) 2017 Universitat Oberta de Cataluya
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  Redistributions of source code must retain the above copyright
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the
//  documentation and/or other materials provided with the
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>

// Include DriverLib (MSP432 Peripheral Driver Library)
#include "driverlib.h"

#define TIMER_PERIOD    2343

// Timer_A UpMode Configuration
Timer_A_UpModeConfig upConfig =
{
     TIMER_A_CLOCKSOURCE_SMCLK,
     TIMER_A_CLOCKSOURCE_DIVIDER_64,
     TIMER_PERIOD,
     TIMER_A_TAIE_INTERRUPT_DISABLE,
     TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
     TIMER_A_DO_CLEAR
};


static uint_fast16_t freqs[5] =
{
     23437,
     4687,
     2343,
     1406,
     1171
};

volatile int8_t freqPointer = 2;

void setupPort(void)
{
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);

    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN4);

    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN4);

    MAP_Interrupt_enableInterrupt(INT_PORT1);
    MAP_Interrupt_enableInterrupt(INT_PORT4);

    MAP_Interrupt_enableMaster();
}

void setupGpios(void)
{
    //Set Led1 red and Led2 blue as output
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);
    //Turn on the led1 and led2
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN2);
    ROM_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void setupSystick(void)
{
    MAP_SysTick_enableModule();
    //wait 0.1 secs to turn on led1
    MAP_SysTick_setPeriod(100000);
    //wait 0.9 secs to turn off led1
    MAP_SysTick_setPeriod(900000);
    MAP_SysTick_enableInterrupt();
    MAP_Interrupt_enableMaster();
}


void setupTimer(void)
{
    MAP_Timer_A_configureUpMode(TIMER_A0_BASE, &upConfig);
    MAP_Interrupt_enableSleepOnIsrExit();
    MAP_Interrupt_enableInterrupt(INT_TA0_0);
    MAP_Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
    MAP_Interrupt_enableMaster();
}

int main(void)
{
    setupGpios();
    setupSystick();
    setupPort();
    setupTimer();

    while (1)
    {
       MAP_PCM_gotoLPM0();
    }
}

void SysTick_Handler(void)
{
  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

void TA0_0_IRQHandler(void)
{
  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN2);
  MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

void PORT1_IRQHandler(void)
{
    MAP_Interrupt_disableMaster();
    uint32_t status;
    int8_t freqNewVal;

    status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, status);

    if(status & GPIO_PIN1) {
        freqNewVal = freqPointer +1;
    } else {
        freqNewVal = freqPointer -1;
    }

    if (freqNewVal <= 4 && freqNewVal >= 0) {
        freqPointer          = freqNewVal;
        upConfig.timerPeriod = freqs[freqPointer];
        setupTimer();
    }

    MAP_Interrupt_enableMaster();
}

