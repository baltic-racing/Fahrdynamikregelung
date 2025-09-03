/*********************** dSPACE target specific file *************************

   Header file Fahrdynamikregelung_TY25_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1401 22.2 (02-Nov-2022)
   Wed Sep  3 15:44:41 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Fahrdynamikregelung_TY25_trc_ptr_h_
#define RTI_HEADER_Fahrdynamikregelung_TY25_trc_ptr_h_

/* Include the model header file. */
#include "Fahrdynamikregelung_TY25.h"
#include "Fahrdynamikregelung_TY25_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_Fahrdynamikregelung_TY25_real_T_0;
EXTERN_C volatile real_T *p_1_Fahrdynamikregelung_TY25_real_T_0;
EXTERN_C volatile int_T *p_2_Fahrdynamikregelung_TY25_int_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Fahrdynamikregelung_TY25_rti_init_trc_pointers(void);

#endif                      /* RTI_HEADER_Fahrdynamikregelung_TY25_trc_ptr_h_ */
