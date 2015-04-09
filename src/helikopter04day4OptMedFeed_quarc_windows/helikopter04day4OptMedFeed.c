/*
 * helikopter04day4OptMedFeed.c
 *
 * Real-Time Workshop code generation for Simulink model "helikopter04day4OptMedFeed.mdl".
 *
 * Model version              : 1.85
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 09 13:04:18 2015
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
  real_T rtb_VandringDeriv;
  real_T rtb_Gain2;
  real_T rtb_Saturation_i;
  real_T rtb_Sum[6];
  real_T rtb_Gain1_a;
  real_T rtb_Gain[6];
  real_T rtb_K_ed;
  real_T rtb_Gain1[2];
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

    /* Gain: '<S2>/Kalibrer-Elev' */
    helikopter04day4OptMedFeed_B.KalibrerElev =
      helikopter04day4OptMedFeed_P.KalibrerElev_Gain * rtb_HILReadEncoder_o3;

    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Constant'
     */
    helikopter04day4OptMedFeed_B.Add = helikopter04day4OptMedFeed_B.KalibrerElev
      + helikopter04day4OptMedFeed_P.Constant_Value;
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
    /* Gain: '<S2>/Kalibrer-Pitch' */
    helikopter04day4OptMedFeed_B.KalibrerPitch =
      helikopter04day4OptMedFeed_P.KalibrerPitch_Gain * rtb_HILReadEncoder_o2;
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
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
    /* Gain: '<S2>/Kalibrer -Vandring' */
    helikopter04day4OptMedFeed_B.KalibrerVandring =
      helikopter04day4OptMedFeed_P.KalibrerVandring_Gain * rtb_HILReadEncoder_o1;
  }

  /* TransferFcn: '<S2>/Vandring Deriv' */
  rtb_VandringDeriv = helikopter04day4OptMedFeed_P.VandringDeriv_D*
    helikopter04day4OptMedFeed_B.KalibrerVandring;
  rtb_VandringDeriv += helikopter04day4OptMedFeed_P.VandringDeriv_C*
    helikopter04day4OptMedFeed_X.VandringDeriv_CSTATE;

  /* TransferFcn: '<S2>/Transfer Fcn4' */
  rtb_Gain2 = helikopter04day4OptMedFeed_P.TransferFcn4_D*
    helikopter04day4OptMedFeed_B.KalibrerPitch;
  rtb_Gain2 += helikopter04day4OptMedFeed_P.TransferFcn4_C*
    helikopter04day4OptMedFeed_X.TransferFcn4_CSTATE;

  /* TransferFcn: '<S2>/Transfer Fcn5' */
  rtb_Gain1_a = helikopter04day4OptMedFeed_P.TransferFcn5_D*
    helikopter04day4OptMedFeed_B.KalibrerElev;
  rtb_Gain1_a += helikopter04day4OptMedFeed_P.TransferFcn5_C*
    helikopter04day4OptMedFeed_X.TransferFcn5_CSTATE;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1' */
  rtb_Sum[0] = helikopter04day4OptMedFeed_B.Add1;
  rtb_Sum[1] = rtb_VandringDeriv;
  rtb_Sum[2] = helikopter04day4OptMedFeed_B.KalibrerPitch;
  rtb_Sum[3] = rtb_Gain2;
  rtb_Sum[4] = helikopter04day4OptMedFeed_B.Add;
  rtb_Sum[5] = rtb_Gain1_a;

  /* Gain: '<Root>/Gain' */
  for (tmp = 0; tmp < 6; tmp++) {
    rtb_Gain[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      rtb_Gain[tmp] += helikopter04day4OptMedFeed_P.Gain_Gain[6 * tmp_0 + tmp] *
        rtb_Sum[tmp_0];
    }
  }

  /* Gain: '<S1>/K_ed' */
  rtb_K_ed = helikopter04day4OptMedFeed_P.K_ed_Gain * rtb_Gain[5];

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
            real_T *y0 = rtb_Sum;
            for (i1=0; i1 < 6; i1++) {
              y0[i1] = pDataValues[currTimeIndex];
              pDataValues += 81;
            }
          }
        } else {
          {
            int_T i1;
            real_T *y0 = rtb_Sum;
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
          real_T *y0 = rtb_Sum;
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
    rtb_Sum[tmp] = rtb_Gain[tmp] - rtb_Sum[tmp];
  }

  /* Gain: '<Root>/Gain1' */
  for (tmp = 0; tmp < 2; tmp++) {
    rtb_Gain1[tmp] = 0.0;
    for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
      rtb_Gain1[tmp] += helikopter04day4OptMedFeed_P.Gain1_Gain[(tmp_0 << 1) +
        tmp] * rtb_Sum[tmp_0];
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
          rtb_Gain1_a = pDataValues[currTimeIndex];
        } else {
          rtb_Gain1_a = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Gain1_a = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  rtb_Gain1_a = (rtb_Gain1_a - rtb_Gain1[1]) - rtb_Gain[4];

  /* Gain: '<S1>/K_ei' */
  helikopter04day4OptMedFeed_B.K_ei = helikopter04day4OptMedFeed_P.K_ei_Gain *
    rtb_Gain1_a;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/K_ep'
   */
  rtb_Saturation_i = (helikopter04day4OptMedFeed_P.K_ep_Gain * rtb_Gain1_a +
                      rtb_Saturation_i) + rtb_K_ed;

  /* Saturate: '<S1>/Saturation' */
  rtb_Saturation_i = rt_SATURATE(rtb_Saturation_i,
    helikopter04day4OptMedFeed_P.Saturation_LowerSat,
    helikopter04day4OptMedFeed_P.Saturation_UpperSat);

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
          rtb_Gain1_a = pDataValues[currTimeIndex];
        } else {
          rtb_Gain1_a = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Gain1_a = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* Sum: '<Root>/Sum1' */
  rtb_Gain1_a -= rtb_Gain1[0];

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/K_pd'
   *  Gain: '<S3>/K_pp'
   *  Saturate: '<S3>/Saturation'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Gain1_a = (rt_SATURATE(rtb_Gain1_a,
    helikopter04day4OptMedFeed_P.Saturation_LowerSat_b,
    helikopter04day4OptMedFeed_P.Saturation_UpperSat_p) - rtb_Gain[2]) *
    helikopter04day4OptMedFeed_P.K_pp_Gain -
    helikopter04day4OptMedFeed_P.K_pd_Gain * rtb_Gain[3];

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Gain2 = (rtb_Saturation_i - rtb_Gain1_a) *
    helikopter04day4OptMedFeed_P.Gain2_Gain;

  /* Saturate: '<S2>/Sat B' */
  helikopter04day4OptMedFeed_B.SatB = rt_SATURATE(rtb_Gain2,
    helikopter04day4OptMedFeed_P.SatB_LowerSat,
    helikopter04day4OptMedFeed_P.SatB_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04day4OptMedFeed_M)) {
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Gain1_a = (rtb_Gain1_a + rtb_Saturation_i) *
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
  helikopter04day4OptMedFeed_M->Sizes.checksums[0] = (1707859134U);
  helikopter04day4OptMedFeed_M->Sizes.checksums[1] = (4028747310U);
  helikopter04day4OptMedFeed_M->Sizes.checksums[2] = (2665382907U);
  helikopter04day4OptMedFeed_M->Sizes.checksums[3] = (40797463U);

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
    helikopter04day4OptMedFeed_B.KalibrerElev = 0.0;
    helikopter04day4OptMedFeed_B.Add = 0.0;
    helikopter04day4OptMedFeed_B.VandringLavpass = 0.0;
    helikopter04day4OptMedFeed_B.Add1 = 0.0;
    helikopter04day4OptMedFeed_B.KalibrerPitch = 0.0;
    helikopter04day4OptMedFeed_B.KalibrerVandring = 0.0;
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
  helikopter04day4OptMedFeed_M->Sizes.numBlocks = (53);/* Number of blocks */
  helikopter04day4OptMedFeed_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  helikopter04day4OptMedFeed_M->Sizes.numBlockPrms = (162);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04day4OptMedFeed_X.VandringLavpass_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  helikopter04day4OptMedFeed_X.Integrator_CSTATE =
    helikopter04day4OptMedFeed_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04day4OptMedFeed_X.VandringDeriv_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04day4OptMedFeed_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04day4OptMedFeed_X.TransferFcn5_CSTATE = 0.0;
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
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1420658357704068E+000,
      3.1372960764361335E+000, 3.1272833755869738E+000, 3.1120277332229280E+000,
      3.0915291493439954E+000, 3.0657876239501767E+000, 3.0348031570414715E+000,
      2.9985757486178795E+000, 2.9571053986794009E+000, 2.9103921072260364E+000,
      2.8584358742577849E+000, 2.8012366997746474E+000, 2.7387945837766230E+000,
      2.6711095262637126E+000, 2.5981815272359152E+000, 2.5200105866932319E+000,
      2.4365967046356616E+000, 2.3479398810632053E+000, 2.2590311453805323E+000,
      2.1695127457171903E+000, 2.0795551946980977E+000, 1.9899874662417665E+000,
      1.9010971357140660E+000, 1.8124264926906268E+000, 1.7230686904092991E+000,
      1.6332405728951642E+000, 1.5439307732042922E+000, 1.4554558150081471E+000,
      1.3670668137120510E+000, 1.2775818116800541E+000, 1.1875819363340963E+000,
      1.0988681704483230E+000, 1.0116524106438682E+000, 9.2351533323549440E-001,
      8.3222718980919808E-001, 7.3990568326316364E-001, 6.5250874811715842E-001,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -4.4077625609130909E-033, -4.0895881891834510E-033,
      1.8927287224539443E-003, -1.9079037337091962E-002,
      -4.0050803396637864E-002, -6.1022569456183777E-002,
      -8.1994335515729683E-002, -1.0296610157527558E-001,
      -1.2393786763482148E-001, -1.4490963369436741E-001,
      -1.6588139975391331E-001, -1.8685316581345923E-001,
      -2.0782493187300516E-001, -2.2879669793255106E-001,
      -2.4976846399209698E-001, -2.7074023005164288E-001,
      -2.9171199611118875E-001, -3.1268376217073468E-001,
      -3.3365552823028055E-001, -3.5462729428982642E-001,
      -3.5563494273069124E-001, -3.5807359865336780E-001,
      -3.5983020407636984E-001, -3.5827091382532572E-001,
      -3.5556132211080205E-001, -3.5468257209375681E-001,
      -3.5743120912531062E-001, -3.5931247005653921E-001,
      -3.5723919876348809E-001, -3.5389983278458054E-001,
      -3.5355600518438468E-001, -3.5794000812798765E-001,
      -3.5999950138383136E-001, -3.5485506354309360E-001,
      -3.4886303921781853E-001, -3.5254830963349570E-001,
      -3.6515257370518522E-001, -3.6928602618413753E-001,
      -3.4958774058402109E-001, -3.2861597452447522E-001, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -3.5061837325305646E-032,
      -4.9278326917104043E-002, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      2.6234731209693354E-002, 6.3491868840128085E-002, 4.5734275214475331E-002,
      -4.0597056428658379E-002, -7.0545844597877855E-002,
      -2.2878783475226601E-002, 7.1562412833127378E-002, 4.8979756097992093E-002,
      -5.3978860971877700E-002, -8.6942395099869424E-002,
      -8.9517576843272176E-003, 1.1414014470088504E-001, 5.3620141513707399E-002,
      -1.3393852310325810E-001, -1.5600594532813666E-001,
      9.5948224469390567E-002, 3.2815957094418630E-001, 1.0761691315702274E-001,
      -5.1285667406711022E-001, -5.4601250123760248E-001,
      5.4601250123760248E-001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, -1.9711330766841617E-001, 2.3811633126188263E+000,
      1.5295560662190389E-016, 1.3205387195521477E-016, -1.2520573390937258E-016,
      -2.2470658682831298E-017, -1.7130070488395549E-016,
      -6.3996630708885454E-017, -8.4458885167324189E-017,
      1.0350487887541135E-016, 7.3505556720575766E-017, -7.6554179787467677E-017,
      -6.7284155282945915E-017, 9.1723529994926695E-017,
      -9.5730675809915104E-017, 5.1131362396799312E-017,
      -1.7115902349037996E-017, -1.3430577454427303E-017,
      -2.0791110801116366E+000, 1.4902855052173897E-001,
      -7.1030374502611029E-002, -3.4532532657253484E-001,
      -1.1979515267687790E-001, 1.9066824449060499E-001, 3.7776478523341595E-001,
      -9.0330626940541087E-002, -4.1183446827947917E-001,
      -1.3185413651196690E-001, 3.1196254966216880E-001, 4.9236760954084902E-001,
      -2.4208001274871060E-001, -7.5023465846786197E-001,
      -8.8269688899514295E-002, 1.0078166791901089E+000, 9.2884538589918297E-001,
      -8.8217063114865424E-001, -2.4818943488965317E+000,
      -1.3262330868196878E-001, 4.3681000099008198E+000, 3.5359785811884699E+000,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.8539816339744828E-001,
      7.8539816339744828E-001, 7.8539816339744828E-001, 7.4687572307541517E-001,
      6.8130806830362367E-001, 5.9876397615880350E-001, 5.0774967196814058E-001,
      4.1516533431983538E-001, 3.2634661829998535E-001, 2.4516766663324069E-001,
      1.7418485391772343E-001, 1.1480370566216638E-001, 6.7454804174236299E-002,
      3.1767844382779312E-002, 6.7361812212876652E-003, -9.1328882546046312E-003,
      -1.7684318560659707E-002, -2.0998049787424748E-002,
      -2.1286623810046174E-002, -2.1171874685219982E-002,
      -4.8342999238043249E-003, 2.9994639150057872E-002, 7.9667452204749092E-002,
      1.2089756579811749E-001, 1.5321737728617096E-001, 1.7655129390343036E-001,
      1.9116879526486588E-001, 1.9763057102385981E-001, 1.9673062357173307E-001,
      1.8943700947768041E-001, 1.7683360480369043E-001, 1.6006493844759306E-001,
      1.4028576365244450E-001, 1.1861664892850232E-001, 9.6106482272262220E-002,
      7.3702411002850993E-002, 5.2227395636116780E-002, 3.2365249308542565E-002,
      1.4652771109132733E-002, -5.2163345172925965E-004,
      -1.2913616776220254E-002, -2.2413725639303692E-002, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.5408976128813248E-001,
      -2.6227061908716576E-001, -3.3017636857928084E-001,
      -3.6405721676265179E-001, -3.7033735059322076E-001,
      -3.5527486407940023E-001, -3.2471580666697858E-001,
      -2.8393125086206905E-001, -2.3752459302222823E-001,
      -1.8939560595172028E-001, -1.4274783916582798E-001,
      -1.0012665264596657E-001, -6.3476277903569189E-002,
      -3.4205721224220297E-002, -1.3254924907060164E-002,
      -1.1542960904857064E-003, 4.5899649930475415E-004, 6.5350299045662627E-002,
      1.3931575629544879E-001, 1.9869125221876488E-001, 1.6492045437347358E-001,
      1.2927924595221388E-001, 9.3335666469037584E-002, 5.8470005445742081E-002,
      2.5847103035975660E-002, -3.5997898085069219E-003,
      -2.9174456376210651E-002, -5.0413618695959943E-002,
      -6.7074665424389487E-002, -7.9116699180594316E-002,
      -8.6676458895768665E-002, -9.0040666624960450E-002,
      -8.9616285077644880E-002, -8.5900061466936878E-002,
      -7.9448585310296874E-002, -7.0849912797639331E-002,
      -6.0697618243447972E-002, -4.9567933297963974E-002,
      -3.8000435452333753E-002, -2.9572823739071073E-002, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0 } ;

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
      -2.4644176231959486E-001, -1.0851813000903712E-001,
      3.6569566163379801E-003, 9.1235835653193612E-002, 1.5624702471437471E-001,
      2.0124236101164916E-001, 2.2899731687850611E-001, 2.4226714339566971E-001,
      2.4359880083660199E-001, 2.3519664173760585E-001, 2.1883860064854563E-001,
      1.9583882696488317E-001, 1.6705248998256558E-001, 1.3291834872284236E-001,
      9.3534812852986440E-002, 4.8765384633923471E-002, -1.1464593678555172E-002,
      4.1375354735926229E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      2.2413725639303689E-002, 2.2413725639303689E-002, 2.2413725639303696E-002,
      2.2413725639303692E-002, 2.2413725639303689E-002, 2.2413725639303689E-002,
      2.2413725639303692E-002, 2.2413725639303689E-002, 2.2413725639303692E-002,
      2.2413725639303689E-002, 2.2413725639303689E-002, 2.2413725639303692E-002,
      2.2413725639303692E-002, 2.2413725639303692E-002, 2.2413725639303692E-002,
      2.2413725639303689E-002, 2.2413725639303689E-002, 2.2413725639303692E-002,
      2.2413725639303689E-002, 1.7201940290535265E-003, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    } ;

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
      -2.2300825042311581E-002, 2.6382266981388530E-001, 1.8071142101511773E-002,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      5.4601250123760248E-001, 5.4601250123760248E-001, 5.4601250123760248E-001,
      3.1078793426367846E-001, 5.0406701528041320E-001, 2.2413725639303692E-002,
      2.2413725639303689E-002, 2.2413725639303689E-002, -2.2413725639303689E-002,
      -2.2413725639303692E-002, -2.2413725639303692E-002,
      2.2413725639303692E-002, 2.2413725639303692E-002, -2.2413725639303689E-002,
      -2.2413725639303696E-002, -2.2413725639303692E-002,
      2.2413725639303692E-002, 2.2413725639303696E-002, -2.2413725639303692E-002,
      -2.2413725639303696E-002, 2.2413725639303696E-002, 2.2413725639303696E-002,
      2.2413725639303696E-002, -2.2413725639303696E-002,
      -2.2413666459326045E-002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
