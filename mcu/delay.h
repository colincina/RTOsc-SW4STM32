/************************************************************************//**
 * \file	heivs/delay.h
 * \brief	simple delays
 * \author	marc dot pignat at hevs dot ch
 ***************************************************************************/

/************************************************************************//**
 * \defgroup delay Delays
 * @{
 * \ingroup time
 * \brief Provides a simple way to delay (active wait)
 ***************************************************************************/

#ifndef HEIVS_DELAY_H
#define HEIVS_DELAY_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

/************************************************************************//**
 * \brief Wait for at least that time
 *
 * \param ms The millisecond time to wait
 ***************************************************************************/
void delay_wait_ms(uint32_t ms);

/************************************************************************//**
 * \brief Wait for at least that time
 *
 * \param us The microsecond time to wait
 ***************************************************************************/
void delay_wait_us(uint32_t us);

#ifdef __cplusplus
	}
#endif

/************************************************************************//**
 * @}
 ***************************************************************************/
#endif /* HEIVS_DELAY_H */
