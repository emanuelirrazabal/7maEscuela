/* Copyright 2016, XXXX
 *
 *  * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "ejercicio.h"
#define OK "Mensaje RECIBIDO"
#define KO "Mensaje NO RECIBIDO"
/* <= own header */



/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */


uint8_t loQueEscuche = 0;
uint8_t respuestaAmigo = 0;

int main(void)
{
   /* inicializaciones */



	init_UART_RS232_EDUCIAA();
	timerInit(1000,&EscucharMicrofono);


    while(1){

    	if(loQueEscuche)
    	{
    		HablarAmigo();

    	}


    }
    

}

void EscucharMicrofono()
{
	//escuchar desde el microfono y convertir a instruccion de salida.
	//Falta codificaciónn de Adrian
	loQueEscuche = 1;
}

void EscucharAmigo()
{
	//escuchar desde el RS232
	respuestaAmigo = readByte_UART_RS232_EDUCIAA();
	if(respuestaAmigo == loQueEscuche)
		sendString_UART_USB_EDUCIAA(OK,16);
	else
	{
		sendString_UART_USB_EDUCIAA(KO,16);
		sendString_UART_USB_EDUCIAA("\n\r",2);
		sendString_UART_USB_EDUCIAA("Enviado: ",9);
		sendString_UART_USB_EDUCIAA(Itoa(loQueEscuche,10),2);
		sendString_UART_USB_EDUCIAA("\n\r",2);
		sendString_UART_USB_EDUCIAA("Recibido: ",10);
		sendString_UART_USB_EDUCIAA(Itoa(respuestaAmigo,10),2);
		sendString_UART_USB_EDUCIAA("============",12);
	}
}

void HablarAmigo()
{
	writeByte_UART_RS232_EDUCIAA(loQueEscuche);
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

