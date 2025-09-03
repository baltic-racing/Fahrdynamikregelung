/*
 * Fahrdynamikregelung_TY25.h
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

#ifndef RTW_HEADER_Fahrdynamikregelung_TY25_h_
#define RTW_HEADER_Fahrdynamikregelung_TY25_h_
#ifndef Fahrdynamikregelung_TY25_COMMON_INCLUDES_
#define Fahrdynamikregelung_TY25_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rtican_ds1401.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                           /* Fahrdynamikregelung_TY25_COMMON_INCLUDES_ */

#include "Fahrdynamikregelung_TY25_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Constant;                     /* '<Root>/Constant' */
  real_T SFunction1_o1;                /* '<S3>/S-Function1' */
  real_T SFunction1_o2;                /* '<S3>/S-Function1' */
  real_T SFunction1_o3;                /* '<S3>/S-Function1' */
  real_T SFunction1_o4;                /* '<S3>/S-Function1' */
  real_T SFunction1_o5;                /* '<S3>/S-Function1' */
} B_Fahrdynamikregelung_TY25_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T SFunction1_IWORK[2];           /* '<S1>/S-Function1' */
} DW_Fahrdynamikregelung_TY25_T;

/* Parameters (default storage) */
struct P_Fahrdynamikregelung_TY25_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Fahrdynamikregelung_T_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Fahrdynamikregelung_TY25_T Fahrdynamikregelung_TY25_P;

/* Block signals (default storage) */
extern B_Fahrdynamikregelung_TY25_T Fahrdynamikregelung_TY25_B;

/* Block states (default storage) */
extern DW_Fahrdynamikregelung_TY25_T Fahrdynamikregelung_TY25_DW;

/* Model entry point functions */
extern void Fahrdynamikregelung_TY25_initialize(void);
extern void Fahrdynamikregelung_TY25_output(void);
extern void Fahrdynamikregelung_TY25_update(void);
extern void Fahrdynamikregelung_TY25_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Fahrdynamikregelung__T *const Fahrdynamikregelung_TY25_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Fahrdynamikregelung_TY25'
 * '<S1>'   : 'Fahrdynamikregelung_TY25/CAN_TYPE1_SETUP_M1_C1'
 * '<S2>'   : 'Fahrdynamikregelung_TY25/RTI Data'
 * '<S3>'   : 'Fahrdynamikregelung_TY25/VCU0'
 * '<S4>'   : 'Fahrdynamikregelung_TY25/RTI Data/RTI Data Store'
 * '<S5>'   : 'Fahrdynamikregelung_TY25/RTI Data/RTI Data Store/RTI Data Store'
 * '<S6>'   : 'Fahrdynamikregelung_TY25/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                              /* RTW_HEADER_Fahrdynamikregelung_TY25_h_ */
