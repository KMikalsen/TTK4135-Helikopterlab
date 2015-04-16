/*
 * helikopter04day4OptMedFeed.c
 *
 * Real-Time Workshop code generation for Simulink model "helikopter04day4OptMedFeed.mdl".
 *
 * Model version              : 1.90
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 16 12:35:18 2015
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "helikopter04day4OptMedFeed.h"
#include "helikopter04day4OptMedFeed_private.h"
#include <stdio.h>
#include "helikopter04day4OptMedFeed_dt.h"

/* Block signals (auto storage) */
BlockIO_helikopter04day4OptMedF helikopter04day4OptMedFeed_B;

/* Continuous states */
ContinuousStates_helikopter04da helikopter04day4OptMedFeed_X;

/* Block states (auto storage) */
D_Work_helikopter04day4OptMedFe helikopter04day4OptMedFee_DWork;

/* Real-time model */
RT_MODEL_helikopter04day4OptMed helikopter04day4OptMedFeed_M_;
RT_MODEL_helikopter04day4OptMed *helikopter04day4OptMedFeed_M =
  &helikopter04day4OptMedFeed_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  helikopter04day4OptMedFeed_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter04day4OptMedFeed_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_HILReadEncoder_o2;
  real_T rtb_HILReadEncoder_o3;
  real_T rtb_Sum_c[6];
  real_T rtb_Saturation_i;
  real_T rtb_Gain[6];
  real_T rtb_Gain1[2];
  real_T rtb_Sum;
  real_T rtb_Gain1_a;
  int32_T tmp;
  int32_T tmp_0;
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* set solver stop time */
    if (!(helikopter04day4OptMedFeed_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter04day4OptMedFeed_M->solverInfo,
                            ((helikopter04day4OptMedFeed_M->Timing.clockTickH0 +
        1) * helikopter04day4OptMedFeed_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter04day4OptMedFeed_M->solverInfo,
                            ((helikopter04day4OptMedFeed_M->Timing.clockTick0 +
        1) * helikopter04day4OptMedFeed_M->Timing.stepSize0 +
        helikopter04day4OptMedFeed_M->Timing.clockTickH0 *
        helikopter04day4OptMedFeed_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter04day4OptMedFeed_M)) {
    helikopter04day4OptMedFeed_M->Timing.t[0] = rtsiGetT
      (&helikopter04day4OptMedFeed_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04day4OptMedFeed_B.VandringLavpass =
    helikopter04day4OptMedFeed_P.VandringLavpass_C*
    helikopter04day4OptMedFeed_X.VandringLavpass_CSTATE;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  helikopter04day4OptMedFeed_B.Add1 =
    helikopter04day4OptMedFeed_P.Constant1_Value +
    helikopter04day4OptMedFeed_B.VandringLavpass;
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder' */

    /* S-Function Block: helikopter04day4OptMedFeed/Heli 3D/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card,
         helikopter04day4OptMedFeed_P.HILReadEncoder_Channels, 3,
         &helikopter04day4OptMedFee_DWork.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder_o1 =
          helikopter04day4OptMedFee_DWork.HILReadEncoder_Buffer[0];
        rtb_HILReadEncoder_o2 =
          helikopter04day4OptMedFee_DWork.HILReadEncoder_Buffer[1];
        rtb_HILReadEncoder_o3 =
          helikopter04day4OptMedFee_DWork.HILReadEncoder_Buffer[2];
      }
    }

    /* Gain: '<S2>/Kalibrer -Vandring' */
    helikopter04day4OptMedFeed_B.KalibrerVandring =
      helikopter04day4OptMedFeed_P.KalibrerVandring_Gain * rtb_HILReadEncoder_o1;
  }

  /* TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04day4OptMedFeed_B.VandringDeriv =
    helikopter04day4OptMedFeed_P.VandringDeriv_D*
    helikopter04day4OptMedFeed_B.KalibrerVandring;
  helikopter04day4OptMedFeed_B.VandringDeriv +=
    helikopter04day4OptMedFeed_P.VandringDeriv_C*
    helikopter04day4OptMedFeed_X.VandringDeriv_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* Gain: '<S2>/Kalibrer-Pitch' */
    helikopter04day4OptMedFeed_B.KalibrerPitch =
      helikopter04day4OptMedFeed_P.KalibrerPitch_Gain * rtb_HILReadEncoder_o2;
  }

  /* TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04day4OptMedFeed_B.TransferFcn4 =
    helikopter04day4OptMedFeed_P.TransferFcn4_D*
    helikopter04day4OptMedFeed_B.KalibrerPitch;
  helikopter04day4OptMedFeed_B.TransferFcn4 +=
    helikopter04day4OptMedFeed_P.TransferFcn4_C*
    helikopter04day4OptMedFeed_X.TransferFcn4_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* Gain: '<S2>/Kalibrer-Elev' */
    helikopter04day4OptMedFeed_B.KalibrerElev =
      helikopter04day4OptMedFeed_P.KalibrerElev_Gain * rtb_HILReadEncoder_o3;

    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Constant'
     */
    helikopter04day4OptMedFeed_B.Add = helikopter04day4OptMedFeed_B.KalibrerElev
      + helikopter04day4OptMedFeed_P.Constant_Value;
  }

  /* TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04day4OptMedFeed_B.TransferFcn5 =
    helikopter04day4OptMedFeed_P.TransferFcn5_D*
    helikopter04day4OptMedFeed_B.KalibrerElev;
  helikopter04day4OptMedFeed_B.TransferFcn5 +=
    helikopter04day4OptMedFeed_P.TransferFcn5_C*
    helikopter04day4OptMedFeed_X.TransferFcn5_CSTATE;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1' */
  rtb_Sum_c[0] = helikopter04day4OptMedFeed_B.Add1;
  rtb_Sum_c[1] = helikopter04day4OptMedFeed_B.VandringDeriv;
  rtb_Sum_c[2] = helikopter04day4OptMedFeed_B.KalibrerPitch;
  rtb_Sum_c[3] = helikopter04day4OptMedFeed_B.TransferFcn4;
  rtb_Sum_c[4] = helikopter04day4OptMedFeed_B.Add;
  rtb_Sum_c[5] = helikopter04day4OptMedFeed_B.TransferFcn5;

  /* Gain: '<Root>/Gain' */
  for (tmp = 0; tmp < 6; tmp++) {
    rtb_Gain[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      rtb_Gain[tmp] += helikopter04day4OptMedFeed_P.Gain_Gain[6 * tmp_0 + tmp] *
        rtb_Sum_c[tmp_0];
    }
  }

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helikopter04day4OptMedFee_DWork.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter04day4OptMedFee_DWork.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter04day4OptMedFee_DWork.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helikopter04day4OptMedFeed_M->Timing.t[0];

    /* get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helikopter04day4OptMedFee_DWork.FromWorkspace1_IWORK.PrevIndex =
      currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T i1;
            real_T *y0 = rtb_Sum_c;
            for (i1=0; i1 < 6; i1++) {
              y0[i1] = pDataValues[currTimeIndex];
              pDataValues += 81;
            }
          }
        } else {
          {
            int_T i1;
            real_T *y0 = rtb_Sum_c;
            for (i1=0; i1 < 6; i1++) {
              y0[i1] = pDataValues[currTimeIndex + 1];
              pDataValues += 81;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T i1;
          real_T *y0 = rtb_Sum_c;
          for (i1=0; i1 < 6; i1++) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            y0[i1] = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 81;
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum' */
  for (tmp = 0; tmp < 6; tmp++) {
    rtb_Sum_c[tmp] = rtb_Gain[tmp] - rtb_Sum_c[tmp];
  }

  /* Gain: '<Root>/Gain1' */
  for (tmp = 0; tmp < 2; tmp++) {
    rtb_Gain1[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      rtb_Gain1[tmp] += helikopter04day4OptMedFeed_P.Gain1_Gain[(tmp_0 << 1) +
        tmp] * rtb_Sum_c[tmp_0];
    }
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      helikopter04day4OptMedFee_DWork.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter04day4OptMedFee_DWork.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter04day4OptMedFee_DWork.FromWorkspace2_IWORK.PrevIndex;
    real_T t = helikopter04day4OptMedFeed_M->Timing.t[0];

    /* get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helikopter04day4OptMedFee_DWork.FromWorkspace2_IWORK.PrevIndex =
      currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Saturation_i = pDataValues[currTimeIndex];
        } else {
          rtb_Saturation_i = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Saturation_i = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* Sum: '<Root>/Sum2' */
  helikopter04day4OptMedFeed_B.Sum2 = rtb_Saturation_i - rtb_Gain1[1];
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter04day4OptMedFee_DWork.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter04day4OptMedFee_DWork.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter04day4OptMedFee_DWork.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter04day4OptMedFeed_M->Timing.t[0];

    /* get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helikopter04day4OptMedFee_DWork.FromWorkspace_IWORK.PrevIndex =
      currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Saturation_i = pDataValues[currTimeIndex];
        } else {
          rtb_Saturation_i = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Saturation_i = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* Sum: '<Root>/Sum1' */
  helikopter04day4OptMedFeed_B.Sum1 = rtb_Saturation_i - rtb_Gain1[0];
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* Integrator: '<S1>/Integrator'
   *
   * Regarding '<S1>/Integrator':
   *  Limited Integrator
   */
  if (helikopter04day4OptMedFeed_X.Integrator_CSTATE >=
      helikopter04day4OptMedFeed_P.Integrator_UpperSat ) {
    helikopter04day4OptMedFeed_X.Integrator_CSTATE =
      helikopter04day4OptMedFeed_P.Integrator_UpperSat;
  } else if (helikopter04day4OptMedFeed_X.Integrator_CSTATE <=
             helikopter04day4OptMedFeed_P.Integrator_LowerSat ) {
    helikopter04day4OptMedFeed_X.Integrator_CSTATE =
      helikopter04day4OptMedFeed_P.Integrator_LowerSat;
  }

  rtb_Saturation_i = helikopter04day4OptMedFeed_X.Integrator_CSTATE;

  /* Sum: '<S1>/Sum' */
  rtb_Sum = helikopter04day4OptMedFeed_B.Sum2 - rtb_Gain[4];

  /* Gain: '<S1>/K_ei' */
  helikopter04day4OptMedFeed_B.K_ei = helikopter04day4OptMedFeed_P.K_ei_Gain *
    rtb_Sum;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/K_ed'
   *  Gain: '<S1>/K_ep'
   */
  rtb_Saturation_i = (helikopter04day4OptMedFeed_P.K_ep_Gain * rtb_Sum +
                      rtb_Saturation_i) + helikopter04day4OptMedFeed_P.K_ed_Gain
    * rtb_Gain[5];

  /* Saturate: '<S1>/Saturation' */
  rtb_Saturation_i = rt_SATURATE(rtb_Saturation_i,
    helikopter04day4OptMedFeed_P.Saturation_LowerSat,
    helikopter04day4OptMedFeed_P.Saturation_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/K_pd'
   *  Gain: '<S3>/K_pp'
   *  Saturate: '<S3>/Saturation'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Sum = (rt_SATURATE(helikopter04day4OptMedFeed_B.Sum1,
              helikopter04day4OptMedFeed_P.Saturation_LowerSat_b,
              helikopter04day4OptMedFeed_P.Saturation_UpperSat_p) - rtb_Gain[2])
    * helikopter04day4OptMedFeed_P.K_pp_Gain -
    helikopter04day4OptMedFeed_P.K_pd_Gain * rtb_Gain[3];

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Gain1_a = (rtb_Saturation_i - rtb_Sum) *
    helikopter04day4OptMedFeed_P.Gain2_Gain;

  /* Saturate: '<S2>/Sat B' */
  helikopter04day4OptMedFeed_B.SatB = rt_SATURATE(rtb_Gain1_a,
    helikopter04day4OptMedFeed_P.SatB_LowerSat,
    helikopter04day4OptMedFeed_P.SatB_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Gain1_a = (rtb_Sum + rtb_Saturation_i) *
    helikopter04day4OptMedFeed_P.Gain1_Gain_e;

  /* Saturate: '<S2>/Sat' */
  helikopter04day4OptMedFeed_B.Sat = rt_SATURATE(rtb_Gain1_a,
    helikopter04day4OptMedFeed_P.Sat_LowerSat,
    helikopter04day4OptMedFeed_P.Sat_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   */
  helikopter04day4OptMedFeed_B.Add_f = helikopter04day4OptMedFeed_B.SatB -
    helikopter04day4OptMedFeed_P.Constant_Value_p;
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: helikopter04day4OptMedFeed/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter04day4OptMedFee_DWork.HILWriteAnalog_Buffer[0] =
        helikopter04day4OptMedFeed_B.Add_f;
      helikopter04day4OptMedFee_DWork.HILWriteAnalog_Buffer[1] =
        helikopter04day4OptMedFeed_B.Sat;
      result = hil_write_analog
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card,
         helikopter04day4OptMedFeed_P.HILWriteAnalog_Channels, 2,
         &helikopter04day4OptMedFee_DWork.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
      }
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void helikopter04day4OptMedFeed_update(int_T tid)
{
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter04day4OptMedFeed_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helikopter04day4OptMedFeed_M->Timing.clockTick0)) {
    ++helikopter04day4OptMedFeed_M->Timing.clockTickH0;
  }

  helikopter04day4OptMedFeed_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter04day4OptMedFeed_M->solverInfo);
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helikopter04day4OptMedFeed_M->Timing.clockTick1)) {
      ++helikopter04day4OptMedFeed_M->Timing.clockTickH1;
    }

    helikopter04day4OptMedFeed_M->Timing.t[1] =
      helikopter04day4OptMedFeed_M->Timing.clockTick1 *
      helikopter04day4OptMedFeed_M->Timing.stepSize1 +
      helikopter04day4OptMedFeed_M->Timing.clockTickH1 *
      helikopter04day4OptMedFeed_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void helikopter04day4OptMedFeed_derivatives(void)
{
  /* Derivatives for TransferFcn: '<S2>/Vandring Lavpass' */
  {
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->VandringLavpass_CSTATE =
      helikopter04day4OptMedFeed_B.KalibrerVandring;
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->VandringLavpass_CSTATE +=
      (helikopter04day4OptMedFeed_P.VandringLavpass_A)*
      helikopter04day4OptMedFeed_X.VandringLavpass_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Vandring Deriv' */
  {
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->VandringDeriv_CSTATE =
      helikopter04day4OptMedFeed_B.KalibrerVandring;
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->VandringDeriv_CSTATE +=
      (helikopter04day4OptMedFeed_P.VandringDeriv_A)*
      helikopter04day4OptMedFeed_X.VandringDeriv_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn4' */
  {
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->TransferFcn4_CSTATE =
      helikopter04day4OptMedFeed_B.KalibrerPitch;
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->TransferFcn4_CSTATE +=
      (helikopter04day4OptMedFeed_P.TransferFcn4_A)*
      helikopter04day4OptMedFeed_X.TransferFcn4_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn5' */
  {
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->TransferFcn5_CSTATE =
      helikopter04day4OptMedFeed_B.KalibrerElev;
    ((StateDerivatives_helikopter04da *)
      helikopter04day4OptMedFeed_M->ModelData.derivs)->TransferFcn5_CSTATE +=
      (helikopter04day4OptMedFeed_P.TransferFcn5_A)*
      helikopter04day4OptMedFeed_X.TransferFcn5_CSTATE;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter04day4OptMedFeed_X.Integrator_CSTATE <=
            helikopter04day4OptMedFeed_P.Integrator_LowerSat );
    usat = ( helikopter04day4OptMedFeed_X.Integrator_CSTATE >=
            helikopter04day4OptMedFeed_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter04day4OptMedFeed_B.K_ei > 0)) ||
        (usat && (helikopter04day4OptMedFeed_B.K_ei < 0)) ) {
      ((StateDerivatives_helikopter04da *)
        helikopter04day4OptMedFeed_M->ModelData.derivs)->Integrator_CSTATE =
        helikopter04day4OptMedFeed_B.K_ei;
    } else {
      /* in saturation */
      ((StateDerivatives_helikopter04da *)
        helikopter04day4OptMedFeed_M->ModelData.derivs)->Integrator_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void helikopter04day4OptMedFeed_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter04day4OptMedFeed_P.Integrator_UpperSat = rtInf;
  helikopter04day4OptMedFeed_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter04day4OptMedFeed_M, 0,
                sizeof(RT_MODEL_helikopter04day4OptMed));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter04day4OptMedFeed_M->solverInfo,
                          &helikopter04day4OptMedFeed_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter04day4OptMedFeed_M->solverInfo, &rtmGetTPtr
                (helikopter04day4OptMedFeed_M));
    rtsiSetStepSizePtr(&helikopter04day4OptMedFeed_M->solverInfo,
                       &helikopter04day4OptMedFeed_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter04day4OptMedFeed_M->solverInfo,
                 &helikopter04day4OptMedFeed_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter04day4OptMedFeed_M->solverInfo,
                         &helikopter04day4OptMedFeed_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter04day4OptMedFeed_M->solverInfo,
      &helikopter04day4OptMedFeed_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter04day4OptMedFeed_M->solverInfo,
                          (&rtmGetErrorStatus(helikopter04day4OptMedFeed_M)));
    rtsiSetRTModelPtr(&helikopter04day4OptMedFeed_M->solverInfo,
                      helikopter04day4OptMedFeed_M);
  }

  rtsiSetSimTimeStep(&helikopter04day4OptMedFeed_M->solverInfo, MAJOR_TIME_STEP);
  helikopter04day4OptMedFeed_M->ModelData.intgData.f[0] =
    helikopter04day4OptMedFeed_M->ModelData.odeF[0];
  helikopter04day4OptMedFeed_M->ModelData.contStates = ((real_T *)
    &helikopter04day4OptMedFeed_X);
  rtsiSetSolverData(&helikopter04day4OptMedFeed_M->solverInfo, (void *)
                    &helikopter04day4OptMedFeed_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter04day4OptMedFeed_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helikopter04day4OptMedFeed_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter04day4OptMedFeed_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter04day4OptMedFeed_M->Timing.sampleTimes =
      (&helikopter04day4OptMedFeed_M->Timing.sampleTimesArray[0]);
    helikopter04day4OptMedFeed_M->Timing.offsetTimes =
      (&helikopter04day4OptMedFeed_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter04day4OptMedFeed_M->Timing.sampleTimes[0] = (0.0);
    helikopter04day4OptMedFeed_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    helikopter04day4OptMedFeed_M->Timing.offsetTimes[0] = (0.0);
    helikopter04day4OptMedFeed_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter04day4OptMedFeed_M,
             &helikopter04day4OptMedFeed_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter04day4OptMedFeed_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter04day4OptMedFeed_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter04day4OptMedFeed_M, -1);
  helikopter04day4OptMedFeed_M->Timing.stepSize0 = 0.001;
  helikopter04day4OptMedFeed_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  helikopter04day4OptMedFeed_M->Sizes.checksums[0] = (2371935453U);
  helikopter04day4OptMedFeed_M->Sizes.checksums[1] = (3952617480U);
  helikopter04day4OptMedFeed_M->Sizes.checksums[2] = (1313753260U);
  helikopter04day4OptMedFeed_M->Sizes.checksums[3] = (3883039318U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter04day4OptMedFeed_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter04day4OptMedFeed_M->extModeInfo,
      &helikopter04day4OptMedFeed_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter04day4OptMedFeed_M->extModeInfo,
                        helikopter04day4OptMedFeed_M->Sizes.checksums);
    rteiSetTPtr(helikopter04day4OptMedFeed_M->extModeInfo, rtmGetTPtr
                (helikopter04day4OptMedFeed_M));
  }

  helikopter04day4OptMedFeed_M->solverInfoPtr =
    (&helikopter04day4OptMedFeed_M->solverInfo);
  helikopter04day4OptMedFeed_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&helikopter04day4OptMedFeed_M->solverInfo, 0.001);
  rtsiSetSolverMode(&helikopter04day4OptMedFeed_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter04day4OptMedFeed_M->ModelData.blockIO = ((void *)
    &helikopter04day4OptMedFeed_B);

  {
    helikopter04day4OptMedFeed_B.VandringLavpass = 0.0;
    helikopter04day4OptMedFeed_B.Add1 = 0.0;
    helikopter04day4OptMedFeed_B.KalibrerVandring = 0.0;
    helikopter04day4OptMedFeed_B.VandringDeriv = 0.0;
    helikopter04day4OptMedFeed_B.KalibrerPitch = 0.0;
    helikopter04day4OptMedFeed_B.TransferFcn4 = 0.0;
    helikopter04day4OptMedFeed_B.KalibrerElev = 0.0;
    helikopter04day4OptMedFeed_B.Add = 0.0;
    helikopter04day4OptMedFeed_B.TransferFcn5 = 0.0;
    helikopter04day4OptMedFeed_B.Sum2 = 0.0;
    helikopter04day4OptMedFeed_B.Sum1 = 0.0;
    helikopter04day4OptMedFeed_B.K_ei = 0.0;
    helikopter04day4OptMedFeed_B.SatB = 0.0;
    helikopter04day4OptMedFeed_B.Sat = 0.0;
    helikopter04day4OptMedFeed_B.Add_f = 0.0;
  }

  /* parameters */
  helikopter04day4OptMedFeed_M->ModelData.defaultParam = ((real_T *)
    &helikopter04day4OptMedFeed_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter04day4OptMedFeed_X;
    helikopter04day4OptMedFeed_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter04day4OptMedFeed_X, 0,
                  sizeof(ContinuousStates_helikopter04da));
  }

  /* states (dwork) */
  helikopter04day4OptMedFeed_M->Work.dwork = ((void *)
    &helikopter04day4OptMedFee_DWork);
  (void) memset((void *)&helikopter04day4OptMedFee_DWork, 0,
                sizeof(D_Work_helikopter04day4OptMedFe));

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      helikopter04day4OptMedFee_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      helikopter04day4OptMedFee_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[0] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[1] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[2] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[3] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[0] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[1] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[2] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[3] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[0] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[1] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[2] = 0.0;
  helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[3] = 0.0;
  helikopter04day4OptMedFee_DWork.HILWriteAnalog_Buffer[0] = 0.0;
  helikopter04day4OptMedFee_DWork.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter04day4OptMedFeed_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void helikopter04day4OptMedFeed_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter04day4OptMedFeed/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    hil_task_delete_all(helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    hil_monitor_stop_all(helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    hil_monitor_delete_all(helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    is_switching = false;
    if ((helikopter04day4OptMedFeed_P.HILInitialize_AOTerminate && !is_switching)
        || (helikopter04day4OptMedFeed_P.HILInitialize_AOExit && is_switching))
    {
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[0] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOFinal;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[1] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOFinal;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[2] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOFinal;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[3] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOFinal;
      result = hil_write_analog
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card,
         &helikopter04day4OptMedFeed_P.HILInitialize_AOChannels[0], 4U,
         &helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
      }
    }

    hil_close(helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    helikopter04day4OptMedFee_DWork.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  helikopter04day4OptMedFeed_output(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter04day4OptMedFeed_update(tid);
}

void MdlInitializeSizes(void)
{
  helikopter04day4OptMedFeed_M->Sizes.numContStates = (5);/* Number of continuous states */
  helikopter04day4OptMedFeed_M->Sizes.numY = (0);/* Number of model outputs */
  helikopter04day4OptMedFeed_M->Sizes.numU = (0);/* Number of model inputs */
  helikopter04day4OptMedFeed_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter04day4OptMedFeed_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter04day4OptMedFeed_M->Sizes.numBlocks = (59);/* Number of blocks */
  helikopter04day4OptMedFeed_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  helikopter04day4OptMedFeed_M->Sizes.numBlockPrms = (162);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04day4OptMedFeed_X.VandringLavpass_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04day4OptMedFeed_X.VandringDeriv_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04day4OptMedFeed_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04day4OptMedFeed_X.TransferFcn5_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  helikopter04day4OptMedFeed_X.Integrator_CSTATE =
    helikopter04day4OptMedFeed_P.Integrator_IC;
}

void MdlStart(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter04day4OptMedFeed/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("sensoray_model_626", "0",
                      &helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((helikopter04day4OptMedFeed_P.HILInitialize_CKPStart && !is_switching) ||
        (helikopter04day4OptMedFeed_P.HILInitialize_CKPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_ClockModes =
          &helikopter04day4OptMedFee_DWork.HILInitialize_ClockModes[0];
        for (i1=0; i1 < 6; i1++) {
          dw_ClockModes[i1] = helikopter04day4OptMedFeed_P.HILInitialize_CKModes;
        }
      }

      result = hil_set_clock_mode
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card, (t_clock *)
         &helikopter04day4OptMedFeed_P.HILInitialize_CKChannels[0], 6U,
         (t_clock_mode *)
         &helikopter04day4OptMedFee_DWork.HILInitialize_ClockModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear
      (helikopter04day4OptMedFee_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
      return;
    }

    if ((helikopter04day4OptMedFeed_P.HILInitialize_AIPStart && !is_switching) ||
        (helikopter04day4OptMedFeed_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &helikopter04day4OptMedFee_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 16; i1++) {
          dw_AIMinimums[i1] = helikopter04day4OptMedFeed_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &helikopter04day4OptMedFee_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 16; i1++) {
          dw_AIMaximums[i1] = helikopter04day4OptMedFeed_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card,
         &helikopter04day4OptMedFeed_P.HILInitialize_AIChannels[0], 16U,
         &helikopter04day4OptMedFee_DWork.HILInitialize_AIMinimums[0],
         &helikopter04day4OptMedFee_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter04day4OptMedFeed_P.HILInitialize_AOPStart && !is_switching) ||
        (helikopter04day4OptMedFeed_P.HILInitialize_AOPEnter && is_switching)) {
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[0] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOLow;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[1] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOLow;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[2] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOLow;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[3] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOLow;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[0] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOHigh;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[1] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOHigh;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[2] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOHigh;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[3] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card,
         &helikopter04day4OptMedFeed_P.HILInitialize_AOChannels[0], 4U,
         &helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums[0],
         &helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter04day4OptMedFeed_P.HILInitialize_AOStart && !is_switching) ||
        (helikopter04day4OptMedFeed_P.HILInitialize_AOEnter && is_switching)) {
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[0] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOInitial;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[1] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOInitial;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[2] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOInitial;
      helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[3] =
        helikopter04day4OptMedFeed_P.HILInitialize_AOInitial;
      result = hil_write_analog
        (helikopter04day4OptMedFee_DWork.HILInitialize_Card,
         &helikopter04day4OptMedFeed_P.HILInitialize_AOChannels[0], 4U,
         &helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day4OptMedFeed_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues[] = { 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1420658357705586E+000,
      3.1372960764364395E+000, 3.1272833755874361E+000, 3.1120277332235489E+000,
      3.0915291493447770E+000, 3.0657876239511204E+000, 3.0348031570425800E+000,
      2.9985757486191553E+000, 2.9571053986808455E+000, 2.9103921072276524E+000,
      2.8584358742595746E+000, 2.8012366997766120E+000, 2.7387945837787657E+000,
      2.6711095262660347E+000, 2.5981815272384194E+000, 2.5200105866959204E+000,
      2.4365967046385362E+000, 2.3479398810662682E+000, 2.2590311453837866E+000,
      2.1695127457206413E+000, 2.0795551947017499E+000, 1.9899874662456161E+000,
      1.9010971357181066E+000, 1.8124264926948563E+000, 1.7230686904137238E+000,
      1.6332405728997879E+000, 1.5439307732091105E+000, 1.4554558150131542E+000,
      1.3670668137172457E+000, 1.2775818116854425E+000, 1.1875819363396805E+000,
      1.0988681704540972E+000, 1.0116524106498290E+000, 9.2351533324164514E-001,
      8.3222718981554422E-001, 7.3990568326970696E-001, 6.5250874812389459E-001,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -1.0055507802131083E-031, -3.4156076414445871E-031,
      1.8927287230617092E-003, -1.9079037336475601E-002,
      -4.0050803396012913E-002, -6.1022569455550221E-002,
      -8.1994335515087530E-002, -1.0296610157462484E-001,
      -1.2393786763416215E-001, -1.4490963369369947E-001,
      -1.6588139975323676E-001, -1.8685316581277406E-001,
      -2.0782493187231135E-001, -2.2879669793184867E-001,
      -2.4976846399138597E-001, -2.7074023005092329E-001,
      -2.9171199611046061E-001, -3.1268376216999794E-001,
      -3.3365552822953526E-001, -3.5462729428907258E-001,
      -3.5563494272992718E-001, -3.5807359865257993E-001,
      -3.5983020407556515E-001, -3.5827091382453602E-001,
      -3.5556132211003755E-001, -3.5468257209300080E-001,
      -3.5743120912453052E-001, -3.5931247005574346E-001,
      -3.5723919876270882E-001, -3.5389983278382531E-001,
      -3.5355600518363423E-001, -3.5794000812721261E-001,
      -3.5999950138304754E-001, -3.5485506354233243E-001,
      -3.4886303921707257E-001, -3.5254830963273570E-001,
      -3.6515257370440385E-001, -3.6928602618334877E-001,
      -3.4958774058324971E-001, -3.2861597452371238E-001, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.9577433189579138E-032,
      -4.9278326932927573E-002, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      2.6234731209427334E-002, 6.3491868839508622E-002, 4.5734275214037612E-002,
      -4.0597056428267123E-002, -7.0545844597221033E-002,
      -2.2878783475006281E-002, 7.1562412832499936E-002, 4.8979756097584232E-002,
      -5.3978860971448446E-002, -8.6942395099242661E-002,
      -8.9517576842038597E-003, 1.1414014470024375E-001, 5.3620141513479144E-002,
      -1.3393852310266696E-001, -1.5600594532774048E-001,
      9.5948224469023763E-002, 3.2815957094362924E-001, 1.0761691315682934E-001,
      -5.1285667406665814E-001, -5.4601250123737877E-001,
      5.4601250123737877E-001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, -1.9711330773171029E-001, 2.3811633126812253E+000,
      1.0487103161662942E-017, -6.6847068140979119E-017, 9.8418739454240545E-017,
      -1.9711686339121793E-016, -9.3250224957105450E-017,
      1.5763495499767343E-016, 1.1049177267307258E-016, 2.0470711114559932E-016,
      1.8684943809199517E-016, 9.7614037589861498E-017, 2.6025947610191272E-017,
      -8.4098126710003214E-017, -1.3105859770133933E-019,
      1.0751117420418302E-016, 1.0687184256250819E-016, -1.9575264490897878E-016,
      -2.0791110801118058E+000, 1.4902855052032518E-001,
      -7.1030374501884069E-002, -3.4532532656921894E-001,
      -1.1979515267581567E-001, 1.9066824448885902E-001, 3.7776478523002482E-001,
      -9.0330626939662831E-002, -4.1183446827613068E-001,
      -1.3185413651117683E-001, 3.1196254966015519E-001, 4.9236760953779046E-001,
      -2.4208001274705843E-001, -7.5023465846458448E-001,
      -8.8269688900294019E-002, 1.0078166791870569E+000, 9.2884538589842192E-001,
      -8.8217063114719962E-001, -2.4818943488939498E+000,
      -1.3262330868288263E-001, 4.3681000098990301E+000, 3.5359785811884006E+000,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -8.0994163342117898E-032, -6.3163204129496932E-004,
      -1.8621701119911757E-003, -3.6352527049782583E-003,
      -5.8689881678455269E-003, -8.4532496360558151E-003,
      -1.1246518111965137E-002, -1.4072738694045225E-002,
      -1.6718757987515261E-002, -1.9184897917657168E-002,
      -2.0802919040763274E-002, -2.0873941157127762E-002,
      -2.0736965807386425E-002, -2.0694657213709357E-002,
      -2.0776721796566287E-002, -2.0998049772459920E-002,
      -2.1286623792529678E-002, -2.1171874684958025E-002,
      -4.8342999240505802E-003, 2.9994639149368750E-002, 7.9667452203690689E-002,
      1.2089756579676783E-001, 1.5321737728460905E-001, 1.7655129390173310E-001,
      1.9116879526310546E-001, 1.9763057102210160E-001, 1.9673062357003410E-001,
      1.8943700947608821E-001, 1.7683360480224256E-001, 1.6006493844631689E-001,
      1.4028576365135748E-001, 1.1861664892761273E-001, 9.6106482271569815E-002,
      7.3702411002348256E-002, 5.2227395635790055E-002, 3.2365249308373346E-002,
      1.4652771109098994E-002, -5.2163345165181000E-004,
      -1.2913616776056973E-002, -2.2413725639079927E-002, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.5265281651798773E-003,
      -4.9221522827848250E-003, -7.0923303719483298E-003,
      -8.9349418514690759E-003, -1.0337045872841155E-002,
      -1.1173073903637285E-002, -1.1304882328320361E-002,
      -1.0584077173880133E-002, -9.8645597205676283E-003,
      -6.4720844924244210E-003, -2.8408846545795538E-004,
      5.4790139896534096E-004, 1.6923437470826270E-004, -3.2825833142770467E-004,
      -8.8531190357454901E-004, -1.1542960802790243E-003,
      4.5899643028661096E-004, 6.5350299043629781E-002, 1.3931575629367732E-001,
      1.9869125221728776E-001, 1.6492045437230859E-001, 1.2927924595136486E-001,
      9.3335666468496170E-002, 5.8470005445489422E-002, 2.5847103035984548E-002,
      -3.5997898082700194E-003, -2.9174456375783517E-002,
      -5.0413618695382668E-002, -6.7074665423702676E-002,
      -7.9116699179837546E-002, -8.6676458894979047E-002,
      -9.0040666624171636E-002, -8.9616285076886210E-002,
      -8.5900061466232844E-002, -7.9448585309666822E-002,
      -7.0849912797097403E-002, -6.0697618243003217E-002,
      -4.9567933297620659E-002, -3.8000435452091814E-002,
      -2.8824839117432263E-002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter04day4OptMedFee_DWork.FromWorkspace1_PWORK.TimePtr = (void *)
      pTimeValues;
    helikopter04day4OptMedFee_DWork.FromWorkspace1_PWORK.DataPtr = (void *)
      pDataValues;
    helikopter04day4OptMedFee_DWork.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace2' */
  {
    static real_T pTimeValues[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -1.6918532500069510E-002, -1.8821133353427732E-002,
      -2.0578285017633299E-002, -2.2002516294629931E-002,
      -2.2852676674120539E-002, -2.2838080101035847E-002,
      -2.1626267089636241E-002, -1.8855120620545132E-002,
      -2.0897078438149273E-002, -4.8525512109671102E-003,
      1.5132834595359374E-002, -1.5544115880060119E-002,
      -2.2806938887394566E-002, -2.3882196353868144E-002,
      -2.4785970510309011E-002, -2.3551778745264526E-002,
      -1.1464594182880646E-002, 4.1375354774941620E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 2.2413725639079920E-002, 2.2413725639079923E-002,
      2.2413725639079920E-002, 2.2413725639079927E-002, 2.2413725639079927E-002,
      2.2413725639079923E-002, 2.2413725639079927E-002, 2.2413725639079923E-002,
      2.2413725639079920E-002, 2.2413725639079923E-002, 2.2413725639079923E-002,
      2.2413725639079927E-002, 2.2413725639079923E-002, 2.2413725639079923E-002,
      2.2413725639079923E-002, 2.2413725639079923E-002, 2.2413725639079923E-002,
      2.2413725639079927E-002, 2.2413725639079927E-002, 6.7289654736572592E-003,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter04day4OptMedFee_DWork.FromWorkspace2_PWORK.TimePtr = (void *)
      pTimeValues;
    helikopter04day4OptMedFee_DWork.FromWorkspace2_PWORK.DataPtr = (void *)
      pDataValues;
    helikopter04day4OptMedFee_DWork.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -2.2300825049472488E-002, 2.6382266981915470E-001, 1.8071142087453137E-002,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737866E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      5.4601250123737877E-001, 5.4601250123737877E-001, 5.4601250123737877E-001,
      3.1078793426343559E-001, 5.0406701528002473E-001, 2.2413725639079927E-002,
      2.2413725639079927E-002, 2.2413725639079930E-002, -2.2413725639079923E-002,
      -2.2413725639079920E-002, -2.2413725639079920E-002,
      2.2413725639079923E-002, 2.2413725639079927E-002, -2.2413725639079920E-002,
      -2.2413725639079927E-002, -2.2413725639079923E-002,
      2.2413725639079927E-002, 2.2413725639079923E-002, -2.2413725639079923E-002,
      -2.2413725639079923E-002, 2.2413725639079923E-002, 2.2413725639079923E-002,
      2.2413725639079923E-002, -2.2413725639079923E-002,
      -2.2413666459160805E-002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter04day4OptMedFee_DWork.FromWorkspace_PWORK.TimePtr = (void *)
      pTimeValues;
    helikopter04day4OptMedFee_DWork.FromWorkspace_PWORK.DataPtr = (void *)
      pDataValues;
    helikopter04day4OptMedFee_DWork.FromWorkspace_IWORK.PrevIndex = 0;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  helikopter04day4OptMedFeed_terminate();
}

RT_MODEL_helikopter04day4OptMed *helikopter04day4OptMedFeed(void)
{
  helikopter04day4OptMedFeed_initialize(1);
  return helikopter04day4OptMedFeed_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
