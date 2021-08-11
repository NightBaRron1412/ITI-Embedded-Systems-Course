/** @file Lab7.h
 * 
 * @brief A header file provides some Bit Operations as functions like macros
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Aug 10, 2021       
 *
 */ 

#ifndef LAB7_H
#define LAB7_H

#define Set_Bit    (Var, BitNo) (Var |= 1 << BitNo)
#define Clr_BIt    (Var, BitNo) (Var &= ~(1 << BitNo)
#define Toggle_Bit (Var, BitNo) (Var ^= 1 << BitNo)

#endif /* LAB7_H */

/*** end of file ***/