/*
 * Fahrdynamikregelung_TY25_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Fahrdynamikregelung_TY25".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Sep  3 15:44:41 2025
 *
 * Target selection: rti1401.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Fahrdynamikregelung_TY25_private_h_
#define RTW_HEADER_Fahrdynamikregelung_TY25_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Fahrdynamikregelung_TY25_types.h"

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C1;

/* ... definition of message variable for the RTICAN blocks */
#define CANTP1_M1_NUMMSG               1

extern can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* ... variable for taskqueue error checking                  */
extern Int32 rtican_type1_tq_error[CAN_TYPE1_NUM_MODULES]
  [CAN_TYPE1_NUM_TASKQUEUES];

/* Declaration of user indices (CAN_Type1_M1) */
#define CANTP1_M1_C1_RX_STD_0X300      0
#define RX_C1_STD_0X300                0
#undef RX_C1_STD_0X300

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;

#endif                      /* RTW_HEADER_Fahrdynamikregelung_TY25_private_h_ */
