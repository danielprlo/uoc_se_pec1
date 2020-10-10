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

#define TIMER_PERIOD    23437  // Numero de ciclos de clock

// Timer_A UpMode Configuration
const Timer_A_UpModeConfig upConfig =
{
  TIMER_A_CLOCKSOURCE_SMCLK,          // SMCLK source = 3 MHz
  TIMER_A_CLOCKSOURCE_DIVIDER_64,     // SMCLK/64
  TIMER_PERIOD,                       // 0.5 seconds
  TIMER_A_TAIE_INTERRUPT_DISABLE,     // Disable Timer interrupt
  TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE, // Enable CCR0 interrupt
  TIMER_A_DO_CLEAR                    // Clear value
};


int main(void)
{
    //Set Led1 red and Led2 blue as output
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);
    //Turn on the led1 and led2
    ROM_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
    ROM_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);

    MAP_SysTick_enableModule();
    //wait 0.1 secs to turn on led1
    MAP_SysTick_setPeriod(100000);
    //wait 0.9 secs to turn off led1
    MAP_SysTick_setPeriod(900000);

    MAP_SysTick_enableInterrupt();
    MAP_Interrupt_enableMaster();


    // Configurar el Timer_A1 en Up Mode (incremental)
    MAP_Timer_A_configureUpMode(TIMER_A3_BASE, &upConfig);

    // Habilita el procesador para que duerma al acabar la ISR
    MAP_Interrupt_enableSleepOnIsrExit();

    // Habilita la interrupcion del Timer_A3
    MAP_Interrupt_enableInterrupt(INT_TA3_0);

    // Inicia el timer
    MAP_Timer_A_startCounter(TIMER_A3_BASE, TIMER_A_UP_MODE);


    while (1)
    {
       // Conmuta el microcontrolador a modo de bajo consumo LPM0
       MAP_PCM_gotoLPM0();
    }
}

void SysTick_Handler(void)
{
  // Conmuta el estado de la salida digital P1.0 (LED)
  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
}


