/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : OW1.h
**     CDE edition : Community
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : OneWire
**     Version     : Component 01.109, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-05-14, 21:15, # CodeGen: 163
**     Abstract    :
**
This is a component implementing the 1-Wire protocol.
**     Settings    :
**          Component Name                                 : OW1
**          Data Pin I/O                                   : SDK_BitIO
**          Write Pin                                      : Disabled
**          Timer (LDD)                                    : Disabled
**          Timer (SDK)                                    : Enabled
**            Timer                                        : SDK_Timer
**          RTOS                                           : Disabled
**          Connection time settings                       : 
**            Connection Mode                              : Master - One slave
**            A: Write 1 Low time (us)                     : 6
**            B: Write 1 High time (us)                    : 64
**            C: Write 0 Low time (us)                     : 60
**            D: Write 0 High time (us)                    : 10
**            E: delay time before read (us)               : 3
**            F: After read delay time                     : 55
**            H: Reset time (us)                           : 480
**            I: Device response time (us)                 : 70
**            Total slot time (us)                         : 100
**          Buffers                                        : 
**            Output                                       : RBOutput
**            Input                                        : RBInput
**            Time                                         : RBTime
**            Program                                      : RBProgram
**          Debug                                          : Enabled
**            Debug Read Pin                               : SDK_BitIO
**          CriticalSection                                : CS1
**          SDK                                            : MCUC1
**     Contents    :
**         add_CRC      - void OW1_add_CRC(uint8_t bitValue);
**         i_run        - void OW1_i_run(void);
**         i_action     - void OW1_i_action(void);
**         i_reset      - void OW1_i_reset(void);
**         i_presence   - void OW1_i_presence(void);
**         i_send_low   - void OW1_i_send_low(void);
**         i_send_float - void OW1_i_send_float(void);
**         i_recv_float - void OW1_i_recv_float(void);
**         i_recv_get   - void OW1_i_recv_get(void);
**         i_recv_low   - void OW1_i_recv_low(void);
**         i_wait       - void OW1_i_wait(void);
**         CalcCRC      - uint8_t OW1_CalcCRC(uint8_t *data, uint8_t dataSize);
**         SendByte     - uint8_t OW1_SendByte(uint8_t data);
**         Receive      - uint8_t OW1_Receive(uint8_t counter);
**         SendReset    - uint8_t OW1_SendReset(void);
**         Count        - uint8_t OW1_Count(void);
**         Waitms       - uint8_t OW1_Waitms(uint8_t key, uint8_t time_ms);
**         ProgramEvent - uint8_t OW1_ProgramEvent(uint8_t key);
**         SendBytes    - uint8_t OW1_SendBytes(uint8_t *data, uint8_t count);
**         GetBytes     - uint8_t OW1_GetBytes(uint8_t *data, uint8_t count);
**         GetByte      - uint8_t OW1_GetByte(uint8_t *data);
**         GetError     - void OW1_GetError(void);
**         isBusy       - bool OW1_isBusy(void);
**         Deinit       - void OW1%.Init(void) OW1_Deinit(void);
**         Init         - void OW1%.Init(void) OW1_Init(void);
**
**     * Copyright (c) Original implementation: Omar Isa� Pinales Ayala, 2014, all rights reserved.
**      * Updated and maintained by Erich Styger, 2014-2017
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file OW1.h
** @version 01.00
** @brief
**
This is a component implementing the 1-Wire protocol.
*/         
/*!
**  @addtogroup OW1_module OW1 module documentation
**  @{
*/         

#ifndef __OW1_H
#define __OW1_H

/* MODULE OW1. */
#include "MCUC1.h" /* SDK and API used */
#include "OW1config.h" /* configuration */


typedef enum {
  OWERR_OK,
  OWERR_NO_DEVICE,
  OWERR_NO_RESPONSE,
  OWERR_BUSY,
  OWERR_CRC
} OW1_Error;


/*
** ===================================================================
**     Method      :  OW1_GetError (component OneWire)
**     Description :
**         Returns the error
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
OW1_Error OW1_GetError(void);
/*
** ===================================================================
**     Method      :  OW1_i_recv_low (component OneWire)
**     Description :
**         receive a bit from the low state
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_recv_low(void);
/*
** ===================================================================
**     Method      :  OW1_i_wait (component OneWire)
**     Description :
**         wait instruction
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_wait(void);
/*
** ===================================================================
**     Method      :  OW1_i_presence (component OneWire)
**     Description :
**         presence instruction
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_presence(void);
/*
** ===================================================================
**     Method      :  OW1_i_action (component OneWire)
**     Description :
**         action instruction
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_action(void);
/*
** ===================================================================
**     Method      :  OW1_i_run (component OneWire)
**     Description :
**         Instruction run
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_run(void);
/*
** ===================================================================
**     Method      :  OW1_i_recv_get (component OneWire)
**     Description :
**         instruction to get a bit
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_recv_get(void);
/*
** ===================================================================
**     Method      :  OW1_i_recv_float (component OneWire)
**     Description :
**         start receiving a byte in floating mode
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_recv_float(void);
/*
** ===================================================================
**     Method      :  OW1_i_send_float (component OneWire)
**     Description :
**         using data pin in input mode
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_send_float(void);
/*
** ===================================================================
**     Method      :  OW1_i_send_low (component OneWire)
**     Description :
**         sending a low signal
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_send_low(void);
/*
** ===================================================================
**     Method      :  OW1_i_reset (component OneWire)
**     Description :
**         reset instruction
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_i_reset(void);
/*
** ===================================================================
**     Method      :  OW1_Waitms (component OneWire)
**     Description :
**         Programs a pause between instruccions.
**     Parameters  :
**         NAME            - DESCRIPTION
**         key             - Key to identify the source of the event.
**         time_ms         - Value of time to wait.
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_Waitms(uint8_t key, uint8_t time_ms);
/*
** ===================================================================
**     Method      :  OW1_ProgramEvent (component OneWire)
**     Description :
**         Used to add a program event
**     Parameters  :
**         NAME            - DESCRIPTION
**         key             - Key to identificate the event, applies
**                           only if OnProgramEvent is enabled. (Valid
**                           range 0 - 31)
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_ProgramEvent(uint8_t key);
/*
** ===================================================================
**     Method      :  OW1_Count (component OneWire)
**     Description :
**         Returns the number of elements stored on input buffer that
**         are ready to read.
**     Parameters  : None
**     Returns     :
**         ---             - number of elements
** ===================================================================
*/
uint8_t OW1_Count(void);
/*
** ===================================================================
**     Method      :  OW1_Receive (component OneWire)
**     Description :
**         Programs a read operation after the master send all in
**         output buffer. Don't use a SendReset while the data is
**         coming.
**     Parameters  :
**         NAME            - DESCRIPTION
**         counter         - Number of bytes to receive from
**                           slave
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_Receive(uint8_t counter);
/*
** ===================================================================
**     Method      :  OW1_SendByte (component OneWire)
**     Description :
**         Sends a single byte
**     Parameters  :
**         NAME            - DESCRIPTION
**         data            - Variable to save the byte.
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_SendByte(uint8_t data);
/*
** ===================================================================
**     Method      :  OW1_SendBytes (component OneWire)
**     Description :
**         Sends multiple bytes
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Array of bytes to add to output stream.
**         count           - Number of bytes to add to output
**                           stream. (Valid range 0 - 31)
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_SendBytes(uint8_t *data, uint8_t count);
/*
** ===================================================================
**     Method      :  OW1_SendReset (component OneWire)
**     Description :
**         Sends a reset to the bus
**     Parameters  : None
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_SendReset(void);
/*
** ===================================================================
**     Method      :  OW1_add_CRC (component OneWire)
**     Description :
**         Adds a bit to CRC accumulator.
**     Parameters  :
**         NAME            - DESCRIPTION
**         bitValue        - Bit to add to CRC accumulator
**     Returns     : Nothing
** ===================================================================
*/
void OW1_add_CRC(uint8_t bitValue);
/*
** ===================================================================
**     Method      :  OW1_GetByte (component OneWire)
**     Description :
**         Get a single byte from the bus
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Pointer to were to store the data
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_GetByte(uint8_t *data);
/*
** ===================================================================
**     Method      :  OW1_GetBytes (component OneWire)
**     Description :
**         Gets multiple bytes from the bus
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Pointer to where to store the data
**         count           - Number of bytes
**     Returns     :
**         ---             - error code
** ===================================================================
*/
uint8_t OW1_GetBytes(uint8_t *data, uint8_t count);
/*
** ===================================================================
**     Method      :  OW1_Init (component OneWire)
**     Description :
**         Initializes this device.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void OW1_Init(void);


bool OW1_isBusy(void);
/*
** ===================================================================
**     Method      :  OW1_isBusy (component OneWire)
**     Description :
**         Returns TRUE if the bus is busy, FALSE otherwise
**     Parameters  : None
**     Returns     :
**         ---             - TRUE if device is busy
** ===================================================================
*/

void OW1_Deinit(void);
/*
** ===================================================================
**     Method      :  OW1_Deinit (component OneWire)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t OW1_CalcCRC(uint8_t *data, uint8_t dataSize);
/*
** ===================================================================
**     Method      :  OW1_CalcCRC (component OneWire)
**     Description :
**         Calculates the CRC over a number of bytes
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Pointer to data
**         dataSize        - number of data bytes
**     Returns     :
**         ---             - calculated CRC
** ===================================================================
*/

void Timer1_OnCounterRestart(void);

/* END OW1. */

#endif
/* ifndef __OW1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
