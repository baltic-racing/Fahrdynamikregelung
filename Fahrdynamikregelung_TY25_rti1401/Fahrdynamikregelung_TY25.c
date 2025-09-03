/*
 * Fahrdynamikregelung_TY25.c
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

#include "Fahrdynamikregelung_TY25_trc_ptr.h"
#include "Fahrdynamikregelung_TY25.h"
#include "Fahrdynamikregelung_TY25_private.h"
#include <string.h>

/* Block signals (default storage) */
B_Fahrdynamikregelung_TY25_T Fahrdynamikregelung_TY25_B;

/* Block states (default storage) */
DW_Fahrdynamikregelung_TY25_T Fahrdynamikregelung_TY25_DW;

/* Real-time model */
static RT_MODEL_Fahrdynamikregelung__T Fahrdynamikregelung_TY25_M_;
RT_MODEL_Fahrdynamikregelung__T *const Fahrdynamikregelung_TY25_M =
  &Fahrdynamikregelung_TY25_M_;

/* Model output function */
void Fahrdynamikregelung_TY25_output(void)
{
  /* Constant: '<Root>/Constant' */
  Fahrdynamikregelung_TY25_B.Constant =
    Fahrdynamikregelung_TY25_P.Constant_Value;

  /* S-Function (rti_commonblock): '<S3>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE RTICAN RX Message Block: "VCU0" Id:768 */
  {
    UInt32 *CAN_Msg;

    /* ... Read status and timestamp info (previous message) */
    can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]);

    /* Convert timestamp */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->processed) {
      can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->timestamp =
        rtk_dsts_time_to_simtime_convert
        (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->timestamp);
    }

    /* Messages with timestamp zero have been received in pause/stop state
       and must not be handled.
     */
    if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->timestamp > 0.0) {
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->processed) {
        Fahrdynamikregelung_TY25_B.SFunction1_o3 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->processed;
        Fahrdynamikregelung_TY25_B.SFunction1_o4 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->timestamp;
        Fahrdynamikregelung_TY25_B.SFunction1_o5 = (real_T)
          can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->deltatime;
        CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->data;

        /* ... Decode CAN Message */
        {
          rtican_Signal_t CAN_Sgn;

          /* ...... "APPS1" (0|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          Fahrdynamikregelung_TY25_B.SFunction1_o1 = 0.1 * ( ((real_T)
            CAN_Sgn.UnsignedSgn) );

          /* ...... "APPS2" (16|16, standard signal, unsigned int, little endian) */
          CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
          CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[3];
          CAN_Sgn.UnsignedSgn &= 0x0000FFFF;
          Fahrdynamikregelung_TY25_B.SFunction1_o2 = 0.1 * ( ((real_T)
            CAN_Sgn.UnsignedSgn) );
        }
      }
    }

    if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300]->processed) {
      /* ... set RX status to 0 because no new message has arrived */
      Fahrdynamikregelung_TY25_B.SFunction1_o3 = 0.0;
    }
  }

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void Fahrdynamikregelung_TY25_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Fahrdynamikregelung_TY25_M->Timing.clockTick0)) {
    ++Fahrdynamikregelung_TY25_M->Timing.clockTickH0;
  }

  Fahrdynamikregelung_TY25_M->Timing.taskTime0 =
    Fahrdynamikregelung_TY25_M->Timing.clockTick0 *
    Fahrdynamikregelung_TY25_M->Timing.stepSize0 +
    Fahrdynamikregelung_TY25_M->Timing.clockTickH0 *
    Fahrdynamikregelung_TY25_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Fahrdynamikregelung_TY25_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Fahrdynamikregelung_TY25_M, 0,
                sizeof(RT_MODEL_Fahrdynamikregelung__T));
  Fahrdynamikregelung_TY25_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &Fahrdynamikregelung_TY25_B), 0,
                sizeof(B_Fahrdynamikregelung_TY25_T));

  /* states (dwork) */
  (void) memset((void *)&Fahrdynamikregelung_TY25_DW, 0,
                sizeof(DW_Fahrdynamikregelung_TY25_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Fahrdynamikregelung_TY25_rti_init_trc_pointers();
  }
}

/* Model terminate function */
void Fahrdynamikregelung_TY25_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "VCU0" Id:768 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X300])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }
}
