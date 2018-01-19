/*
 * IncFile1.h
 *
 * Created: 12/8/2017 10:53:52 AM
 *  Author: Amr
 */ 


#ifndef STDMACROS_H_
#define STDMACROS_H_

#include <avr/io.h>
#include <stdint.h>

#define F_CPU 12000000UL //frequency maktoba 3al crystalah
#include <util/delay.h> //delay function
#include <avr/interrupt.h>

#define SETBIT(REG,BIT) (REG |= (1<<BIT))
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^=(1<<BIT))
#define READBIT(REG,BIT) ((REG>>BIT)&1)
#endif /* INCFILE1_H_ */