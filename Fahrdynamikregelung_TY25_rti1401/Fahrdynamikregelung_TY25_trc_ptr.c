/***************************************************************************

   Source file Fahrdynamikregelung_TY25_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1401 22.2 (02-Nov-2022)
   Wed Sep  3 15:44:41 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Fahrdynamikregelung_TY25_trc_ptr.h"
#include "Fahrdynamikregelung_TY25.h"
#include "Fahrdynamikregelung_TY25_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_Fahrdynamikregelung_TY25_real_T_0 = NULL;
volatile real_T *p_1_Fahrdynamikregelung_TY25_real_T_0 = NULL;
volatile int_T *p_2_Fahrdynamikregelung_TY25_int_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Fahrdynamikregelung_TY25_real_T_0 = &Fahrdynamikregelung_TY25_B.Constant;
  p_1_Fahrdynamikregelung_TY25_real_T_0 =
    &Fahrdynamikregelung_TY25_P.Constant_Value;
  p_2_Fahrdynamikregelung_TY25_int_T_0 =
    &Fahrdynamikregelung_TY25_DW.SFunction1_IWORK[0];
}

void Fahrdynamikregelung_TY25_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
