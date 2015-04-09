/*
 * helikopter04.c
 *
 * Real-Time Workshop code generation for Simulink model "helikopter04.mdl".
 *
 * Model version              : 1.76
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Mar 12 14:00:15 2015
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "helikopter04.h"
#include "helikopter04_private.h"
#include <stdio.h>
#include "helikopter04_dt.h"

/* Block signals (auto storage) */
BlockIO_helikopter04 helikopter04_B;

/* Continuous states */
ContinuousStates_helikopter04 helikopter04_X;

/* Block states (auto storage) */
D_Work_helikopter04 helikopter04_DWork;

/* Real-time model */
RT_MODEL_helikopter04 helikopter04_M_;
RT_MODEL_helikopter04 *helikopter04_M = &helikopter04_M_;

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
  helikopter04_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter04_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_HILReadEncoder_o2;
  real_T rtb_HILReadEncoder_o3;
  real_T rtb_Gain2;
  real_T rtb_Sum[4];
  real_T rtb_Sum_e;
  real_T rtb_Gain1;
  real_T rtb_Gain[6];
  real_T tmp[6];
  int32_T tmp_0;
  int32_T tmp_1;
  real_T tmp_2;
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* set solver stop time */
    if (!(helikopter04_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter04_M->solverInfo,
                            ((helikopter04_M->Timing.clockTickH0 + 1) *
        helikopter04_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter04_M->solverInfo,
                            ((helikopter04_M->Timing.clockTick0 + 1) *
        helikopter04_M->Timing.stepSize0 + helikopter04_M->Timing.clockTickH0 *
        helikopter04_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter04_M)) {
    helikopter04_M->Timing.t[0] = rtsiGetT(&helikopter04_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder' */

    /* S-Function Block: helikopter04/Heli 3D/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(helikopter04_DWork.HILInitialize_Card,
        helikopter04_P.HILReadEncoder_Channels, 3,
        &helikopter04_DWork.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder_o1 = helikopter04_DWork.HILReadEncoder_Buffer[0];
        rtb_HILReadEncoder_o2 = helikopter04_DWork.HILReadEncoder_Buffer[1];
        rtb_HILReadEncoder_o3 = helikopter04_DWork.HILReadEncoder_Buffer[2];
      }
    }

    /* Gain: '<S2>/Kalibrer-Elev' */
    helikopter04_B.KalibrerElev = helikopter04_P.KalibrerElev_Gain *
      rtb_HILReadEncoder_o3;

    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Constant'
     */
    helikopter04_B.Add = helikopter04_B.KalibrerElev +
      helikopter04_P.Constant_Value;
  }

  /* TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04_B.VandringLavpass = helikopter04_P.VandringLavpass_C*
    helikopter04_X.VandringLavpass_CSTATE;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  helikopter04_B.Add1 = helikopter04_P.Constant1_Value +
    helikopter04_B.VandringLavpass;
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* Gain: '<S2>/Kalibrer -Vandring' */
    helikopter04_B.KalibrerVandring = helikopter04_P.KalibrerVandring_Gain *
      rtb_HILReadEncoder_o1;
  }

  /* TransferFcn: '<S2>/Vandring Deriv' */
  rtb_Gain2 = helikopter04_P.VandringDeriv_D*helikopter04_B.KalibrerVandring;
  rtb_Gain2 += helikopter04_P.VandringDeriv_C*
    helikopter04_X.VandringDeriv_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* Gain: '<S2>/Kalibrer-Pitch' */
    helikopter04_B.KalibrerPitch = helikopter04_P.KalibrerPitch_Gain *
      rtb_HILReadEncoder_o2;
  }

  /* TransferFcn: '<S2>/Transfer Fcn4' */
  rtb_Sum_e = helikopter04_P.TransferFcn4_D*helikopter04_B.KalibrerPitch;
  rtb_Sum_e += helikopter04_P.TransferFcn4_C*helikopter04_X.TransferFcn4_CSTATE;

  /* TransferFcn: '<S2>/Transfer Fcn5' */
  rtb_Gain1 = helikopter04_P.TransferFcn5_D*helikopter04_B.KalibrerElev;
  rtb_Gain1 += helikopter04_P.TransferFcn5_C*helikopter04_X.TransferFcn5_CSTATE;

  /* Gain: '<Root>/Gain' incorporates:
   *  SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1'
   */
  tmp[0] = helikopter04_B.Add1;
  tmp[1] = rtb_Gain2;
  tmp[2] = helikopter04_B.KalibrerPitch;
  tmp[3] = rtb_Sum_e;
  tmp[4] = helikopter04_B.Add;
  tmp[5] = rtb_Gain1;
  for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
    rtb_Gain[tmp_0] = 0.0;
    for (tmp_1 = 0; tmp_1 < 6; tmp_1++) {
      rtb_Gain[tmp_0] += helikopter04_P.Gain_Gain[6 * tmp_1 + tmp_0] * tmp[tmp_1];
    }
  }

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helikopter04_DWork.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter04_DWork.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = helikopter04_DWork.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helikopter04_M->Timing.t[0];

    /* get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter04_DWork.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Sum[0] = pDataValues[currTimeIndex];
          pDataValues += 141;
          rtb_Sum[1] = pDataValues[currTimeIndex];
          pDataValues += 141;
          rtb_Sum[2] = pDataValues[currTimeIndex];
          pDataValues += 141;
          rtb_Sum[3] = pDataValues[currTimeIndex];
          pDataValues += 141;
        } else {
          rtb_Sum[0] = pDataValues[currTimeIndex + 1];
          pDataValues += 141;
          rtb_Sum[1] = pDataValues[currTimeIndex + 1];
          pDataValues += 141;
          rtb_Sum[2] = pDataValues[currTimeIndex + 1];
          pDataValues += 141;
          rtb_Sum[3] = pDataValues[currTimeIndex + 1];
          pDataValues += 141;
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum[0] = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum[1] = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum[2] = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum[3] = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* Gain: '<Root>/Gain1' */

  /* Sum: '<Root>/Sum' */
  rtb_Sum[0] = rtb_Gain[0] - rtb_Sum[0];
  tmp_2 = helikopter04_P.Gain1_Gain[0] * rtb_Sum[0];

  /* Sum: '<Root>/Sum' */
  rtb_Sum[1] = rtb_Gain[1] - rtb_Sum[1];
  tmp_2 += helikopter04_P.Gain1_Gain[1] * rtb_Sum[1];

  /* Sum: '<Root>/Sum' */
  rtb_Sum[2] = rtb_Gain[2] - rtb_Sum[2];
  tmp_2 += helikopter04_P.Gain1_Gain[2] * rtb_Sum[2];

  /* Sum: '<Root>/Sum' */
  rtb_Sum[3] = rtb_Gain[3] - rtb_Sum[3];
  rtb_Gain1 = helikopter04_P.Gain1_Gain[3] * rtb_Sum[3] + tmp_2;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter04_DWork.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter04_DWork.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = helikopter04_DWork.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter04_M->Timing.t[0];

    /* get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter04_DWork.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Sum_e = pDataValues[currTimeIndex];
        } else {
          rtb_Sum_e = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum_e = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* Sum: '<Root>/Sum1' */
  helikopter04_B.Sum1 = rtb_Sum_e - rtb_Gain1;
  if (rtmIsMajorTimeStep(helikopter04_M)) {
  }

  /* Integrator: '<S1>/Integrator'
   *
   * Regarding '<S1>/Integrator':
   *  Limited Integrator
   */
  if (helikopter04_X.Integrator_CSTATE >= helikopter04_P.Integrator_UpperSat ) {
    helikopter04_X.Integrator_CSTATE = helikopter04_P.Integrator_UpperSat;
  } else if (helikopter04_X.Integrator_CSTATE <=
             helikopter04_P.Integrator_LowerSat ) {
    helikopter04_X.Integrator_CSTATE = helikopter04_P.Integrator_LowerSat;
  }

  rtb_Gain1 = helikopter04_X.Integrator_CSTATE;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<Root>/elevation'
   */
  rtb_Sum_e = helikopter04_P.elevation_Value - rtb_Gain[4];

  /* Gain: '<S1>/K_ei' */
  helikopter04_B.K_ei = helikopter04_P.K_ei_Gain * rtb_Sum_e;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/K_ed'
   *  Gain: '<S1>/K_ep'
   */
  rtb_Gain1 = (helikopter04_P.K_ep_Gain * rtb_Sum_e + rtb_Gain1) +
    helikopter04_P.K_ed_Gain * rtb_Gain[5];

  /* Saturate: '<S1>/Saturation' */
  rtb_Gain1 = rt_SATURATE(rtb_Gain1, helikopter04_P.Saturation_LowerSat,
    helikopter04_P.Saturation_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04_M)) {
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/K_pd'
   *  Gain: '<S3>/K_pp'
   *  Saturate: '<S3>/Saturation'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Sum_e = (rt_SATURATE(helikopter04_B.Sum1,
    helikopter04_P.Saturation_LowerSat_f, helikopter04_P.Saturation_UpperSat_m)
               - rtb_Gain[2]) * helikopter04_P.K_pp_Gain -
    helikopter04_P.K_pd_Gain * rtb_Gain[3];

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Gain2 = (rtb_Gain1 - rtb_Sum_e) * helikopter04_P.Gain2_Gain;

  /* Saturate: '<S2>/Sat B' */
  helikopter04_B.SatB = rt_SATURATE(rtb_Gain2, helikopter04_P.SatB_LowerSat,
    helikopter04_P.SatB_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04_M)) {
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Gain1 = (rtb_Sum_e + rtb_Gain1) * helikopter04_P.Gain1_Gain_g;

  /* Saturate: '<S2>/Sat' */
  helikopter04_B.Sat = rt_SATURATE(rtb_Gain1, helikopter04_P.Sat_LowerSat,
    helikopter04_P.Sat_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04_M)) {
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   */
  helikopter04_B.Add_m = helikopter04_B.SatB - helikopter04_P.Constant_Value_n;
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: helikopter04/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter04_DWork.HILWriteAnalog_Buffer[0] = helikopter04_B.Add_m;
      helikopter04_DWork.HILWriteAnalog_Buffer[1] = helikopter04_B.Sat;
      result = hil_write_analog(helikopter04_DWork.HILInitialize_Card,
        helikopter04_P.HILWriteAnalog_Channels, 2,
        &helikopter04_DWork.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
      }
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void helikopter04_update(int_T tid)
{
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter04_M->solverInfo);
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
  if (!(++helikopter04_M->Timing.clockTick0)) {
    ++helikopter04_M->Timing.clockTickH0;
  }

  helikopter04_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter04_M->solverInfo);
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helikopter04_M->Timing.clockTick1)) {
      ++helikopter04_M->Timing.clockTickH1;
    }

    helikopter04_M->Timing.t[1] = helikopter04_M->Timing.clockTick1 *
      helikopter04_M->Timing.stepSize1 + helikopter04_M->Timing.clockTickH1 *
      helikopter04_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void helikopter04_derivatives(void)
{
  /* Derivatives for TransferFcn: '<S2>/Vandring Lavpass' */
  {
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->VandringLavpass_CSTATE = helikopter04_B.KalibrerVandring;
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->VandringLavpass_CSTATE += (helikopter04_P.VandringLavpass_A)*
      helikopter04_X.VandringLavpass_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Vandring Deriv' */
  {
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->VandringDeriv_CSTATE = helikopter04_B.KalibrerVandring;
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->VandringDeriv_CSTATE += (helikopter04_P.VandringDeriv_A)*
      helikopter04_X.VandringDeriv_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn4' */
  {
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->TransferFcn4_CSTATE = helikopter04_B.KalibrerPitch;
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->TransferFcn4_CSTATE += (helikopter04_P.TransferFcn4_A)*
      helikopter04_X.TransferFcn4_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn5' */
  {
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->TransferFcn5_CSTATE = helikopter04_B.KalibrerElev;
    ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
      ->TransferFcn5_CSTATE += (helikopter04_P.TransferFcn5_A)*
      helikopter04_X.TransferFcn5_CSTATE;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter04_X.Integrator_CSTATE <=
            helikopter04_P.Integrator_LowerSat );
    usat = ( helikopter04_X.Integrator_CSTATE >=
            helikopter04_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter04_B.K_ei > 0)) ||
        (usat && (helikopter04_B.K_ei < 0)) ) {
      ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
        ->Integrator_CSTATE = helikopter04_B.K_ei;
    } else {
      /* in saturation */
      ((StateDerivatives_helikopter04 *) helikopter04_M->ModelData.derivs)
        ->Integrator_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void helikopter04_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter04_P.Integrator_UpperSat = rtInf;
  helikopter04_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter04_M, 0,
                sizeof(RT_MODEL_helikopter04));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter04_M->solverInfo,
                          &helikopter04_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter04_M->solverInfo, &rtmGetTPtr(helikopter04_M));
    rtsiSetStepSizePtr(&helikopter04_M->solverInfo,
                       &helikopter04_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter04_M->solverInfo, &helikopter04_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter04_M->solverInfo,
                         &helikopter04_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter04_M->solverInfo,
      &helikopter04_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter04_M->solverInfo, (&rtmGetErrorStatus
      (helikopter04_M)));
    rtsiSetRTModelPtr(&helikopter04_M->solverInfo, helikopter04_M);
  }

  rtsiSetSimTimeStep(&helikopter04_M->solverInfo, MAJOR_TIME_STEP);
  helikopter04_M->ModelData.intgData.f[0] = helikopter04_M->ModelData.odeF[0];
  helikopter04_M->ModelData.contStates = ((real_T *) &helikopter04_X);
  rtsiSetSolverData(&helikopter04_M->solverInfo, (void *)
                    &helikopter04_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter04_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helikopter04_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter04_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter04_M->Timing.sampleTimes =
      (&helikopter04_M->Timing.sampleTimesArray[0]);
    helikopter04_M->Timing.offsetTimes =
      (&helikopter04_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter04_M->Timing.sampleTimes[0] = (0.0);
    helikopter04_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    helikopter04_M->Timing.offsetTimes[0] = (0.0);
    helikopter04_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter04_M, &helikopter04_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter04_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter04_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter04_M, -1);
  helikopter04_M->Timing.stepSize0 = 0.001;
  helikopter04_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  helikopter04_M->Sizes.checksums[0] = (2170064209U);
  helikopter04_M->Sizes.checksums[1] = (3197341573U);
  helikopter04_M->Sizes.checksums[2] = (2189218525U);
  helikopter04_M->Sizes.checksums[3] = (2132371646U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter04_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter04_M->extModeInfo,
      &helikopter04_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter04_M->extModeInfo,
                        helikopter04_M->Sizes.checksums);
    rteiSetTPtr(helikopter04_M->extModeInfo, rtmGetTPtr(helikopter04_M));
  }

  helikopter04_M->solverInfoPtr = (&helikopter04_M->solverInfo);
  helikopter04_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&helikopter04_M->solverInfo, 0.001);
  rtsiSetSolverMode(&helikopter04_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter04_M->ModelData.blockIO = ((void *) &helikopter04_B);

  {
    helikopter04_B.KalibrerElev = 0.0;
    helikopter04_B.Add = 0.0;
    helikopter04_B.VandringLavpass = 0.0;
    helikopter04_B.Add1 = 0.0;
    helikopter04_B.KalibrerVandring = 0.0;
    helikopter04_B.KalibrerPitch = 0.0;
    helikopter04_B.Sum1 = 0.0;
    helikopter04_B.K_ei = 0.0;
    helikopter04_B.SatB = 0.0;
    helikopter04_B.Sat = 0.0;
    helikopter04_B.Add_m = 0.0;
  }

  /* parameters */
  helikopter04_M->ModelData.defaultParam = ((real_T *)&helikopter04_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter04_X;
    helikopter04_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter04_X, 0,
                  sizeof(ContinuousStates_helikopter04));
  }

  /* states (dwork) */
  helikopter04_M->Work.dwork = ((void *) &helikopter04_DWork);
  (void) memset((void *)&helikopter04_DWork, 0,
                sizeof(D_Work_helikopter04));

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      helikopter04_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      helikopter04_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  helikopter04_DWork.HILInitialize_AOMinimums[0] = 0.0;
  helikopter04_DWork.HILInitialize_AOMinimums[1] = 0.0;
  helikopter04_DWork.HILInitialize_AOMinimums[2] = 0.0;
  helikopter04_DWork.HILInitialize_AOMinimums[3] = 0.0;
  helikopter04_DWork.HILInitialize_AOMaximums[0] = 0.0;
  helikopter04_DWork.HILInitialize_AOMaximums[1] = 0.0;
  helikopter04_DWork.HILInitialize_AOMaximums[2] = 0.0;
  helikopter04_DWork.HILInitialize_AOMaximums[3] = 0.0;
  helikopter04_DWork.HILInitialize_AOVoltages[0] = 0.0;
  helikopter04_DWork.HILInitialize_AOVoltages[1] = 0.0;
  helikopter04_DWork.HILInitialize_AOVoltages[2] = 0.0;
  helikopter04_DWork.HILInitialize_AOVoltages[3] = 0.0;
  helikopter04_DWork.HILWriteAnalog_Buffer[0] = 0.0;
  helikopter04_DWork.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter04_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void helikopter04_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter04/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(helikopter04_DWork.HILInitialize_Card);
    hil_task_delete_all(helikopter04_DWork.HILInitialize_Card);
    hil_monitor_stop_all(helikopter04_DWork.HILInitialize_Card);
    hil_monitor_delete_all(helikopter04_DWork.HILInitialize_Card);
    is_switching = false;
    if ((helikopter04_P.HILInitialize_AOTerminate && !is_switching) ||
        (helikopter04_P.HILInitialize_AOExit && is_switching)) {
      helikopter04_DWork.HILInitialize_AOVoltages[0] =
        helikopter04_P.HILInitialize_AOFinal;
      helikopter04_DWork.HILInitialize_AOVoltages[1] =
        helikopter04_P.HILInitialize_AOFinal;
      helikopter04_DWork.HILInitialize_AOVoltages[2] =
        helikopter04_P.HILInitialize_AOFinal;
      helikopter04_DWork.HILInitialize_AOVoltages[3] =
        helikopter04_P.HILInitialize_AOFinal;
      result = hil_write_analog(helikopter04_DWork.HILInitialize_Card,
        &helikopter04_P.HILInitialize_AOChannels[0], 4U,
        &helikopter04_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
      }
    }

    hil_close(helikopter04_DWork.HILInitialize_Card);
    helikopter04_DWork.HILInitialize_Card = NULL;
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
  helikopter04_output(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter04_update(tid);
}

void MdlInitializeSizes(void)
{
  helikopter04_M->Sizes.numContStates = (5);/* Number of continuous states */
  helikopter04_M->Sizes.numY = (0);    /* Number of model outputs */
  helikopter04_M->Sizes.numU = (0);    /* Number of model inputs */
  helikopter04_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter04_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter04_M->Sizes.numBlocks = (53);/* Number of blocks */
  helikopter04_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  helikopter04_M->Sizes.numBlockPrms = (155);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04_X.VandringLavpass_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04_X.VandringDeriv_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04_X.TransferFcn5_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  helikopter04_X.Integrator_CSTATE = helikopter04_P.Integrator_IC;
}

void MdlStart(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter04/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("sensoray_model_626", "0",
                      &helikopter04_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter04_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((helikopter04_P.HILInitialize_CKPStart && !is_switching) ||
        (helikopter04_P.HILInitialize_CKPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_ClockModes = &helikopter04_DWork.HILInitialize_ClockModes[0];
        for (i1=0; i1 < 6; i1++) {
          dw_ClockModes[i1] = helikopter04_P.HILInitialize_CKModes;
        }
      }

      result = hil_set_clock_mode(helikopter04_DWork.HILInitialize_Card,
        (t_clock *) &helikopter04_P.HILInitialize_CKChannels[0], 6U,
        (t_clock_mode *) &helikopter04_DWork.HILInitialize_ClockModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(helikopter04_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter04_M, _rt_error_message);
      return;
    }

    if ((helikopter04_P.HILInitialize_AIPStart && !is_switching) ||
        (helikopter04_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &helikopter04_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 16; i1++) {
          dw_AIMinimums[i1] = helikopter04_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &helikopter04_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 16; i1++) {
          dw_AIMaximums[i1] = helikopter04_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(helikopter04_DWork.HILInitialize_Card,
        &helikopter04_P.HILInitialize_AIChannels[0], 16U,
        &helikopter04_DWork.HILInitialize_AIMinimums[0],
        &helikopter04_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter04_P.HILInitialize_AOPStart && !is_switching) ||
        (helikopter04_P.HILInitialize_AOPEnter && is_switching)) {
      helikopter04_DWork.HILInitialize_AOMinimums[0] =
        helikopter04_P.HILInitialize_AOLow;
      helikopter04_DWork.HILInitialize_AOMinimums[1] =
        helikopter04_P.HILInitialize_AOLow;
      helikopter04_DWork.HILInitialize_AOMinimums[2] =
        helikopter04_P.HILInitialize_AOLow;
      helikopter04_DWork.HILInitialize_AOMinimums[3] =
        helikopter04_P.HILInitialize_AOLow;
      helikopter04_DWork.HILInitialize_AOMaximums[0] =
        helikopter04_P.HILInitialize_AOHigh;
      helikopter04_DWork.HILInitialize_AOMaximums[1] =
        helikopter04_P.HILInitialize_AOHigh;
      helikopter04_DWork.HILInitialize_AOMaximums[2] =
        helikopter04_P.HILInitialize_AOHigh;
      helikopter04_DWork.HILInitialize_AOMaximums[3] =
        helikopter04_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (helikopter04_DWork.HILInitialize_Card,
         &helikopter04_P.HILInitialize_AOChannels[0], 4U,
         &helikopter04_DWork.HILInitialize_AOMinimums[0],
         &helikopter04_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter04_P.HILInitialize_AOStart && !is_switching) ||
        (helikopter04_P.HILInitialize_AOEnter && is_switching)) {
      helikopter04_DWork.HILInitialize_AOVoltages[0] =
        helikopter04_P.HILInitialize_AOInitial;
      helikopter04_DWork.HILInitialize_AOVoltages[1] =
        helikopter04_P.HILInitialize_AOInitial;
      helikopter04_DWork.HILInitialize_AOVoltages[2] =
        helikopter04_P.HILInitialize_AOInitial;
      helikopter04_DWork.HILInitialize_AOVoltages[3] =
        helikopter04_P.HILInitialize_AOInitial;
      result = hil_write_analog(helikopter04_DWork.HILInitialize_Card,
        &helikopter04_P.HILInitialize_AOChannels[0], 4U,
        &helikopter04_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04_M, _rt_error_message);
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
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues[] = { 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897931E+000,
      3.1415926535897931E+000, 3.1415926535897931E+000, 3.1415926535897922E+000,
      3.1415926535897913E+000, 3.1415926535897940E+000, 3.1365649339835477E+000,
      3.1265094947710566E+000, 3.1114263359523178E+000, 3.0913154575273296E+000,
      3.0661768594960943E+000, 3.0360105418586159E+000, 3.0008165046148898E+000,
      2.9605947477649179E+000, 2.9153452713086989E+000, 2.8650680752462332E+000,
      2.8097631595775194E+000, 2.7494305243025634E+000, 2.6840701694213576E+000,
      2.6136820949339068E+000, 2.5382663008402084E+000, 2.4578227871402643E+000,
      2.3723515538340734E+000, 2.2818526009216344E+000, 2.1863259284029501E+000,
      2.0857715362780209E+000, 1.9801894245468434E+000, 1.8695795932094224E+000,
      1.7539420422657506E+000, 1.6332767717158370E+000, 1.5075837815596758E+000,
      1.3817731523156986E+000, 1.2606226008041761E+000, 1.1444997688988996E+000,
      1.0334046565998665E+000, 9.2733726390708593E-001, 8.2629759082054843E-001,
      7.3028563734025798E-001, 6.3930140346621522E-001, 5.5334488919841696E-001,
      4.7241609453686828E-001, 3.9651501948156237E-001, 3.2564166403249950E-001,
      2.5979602818968683E-001, 1.9897811195312171E-001, 1.4318791532280109E-001,
      9.2425438298725043E-002, 4.6690680880901697E-002, 5.9836430693216086E-003,
      -2.9695675136011700E-002, -6.0347273735098975E-002,
      -8.5971152727943215E-002, -1.0656731211453827E-001,
      -1.2213575189488550E-001, -1.3267647206898564E-001,
      -1.3853474065345417E-001, -1.4053260370093026E-001,
      -1.3944851440949871E-001, -1.3588852375650351E-001,
      -1.3036872662645657E-001, -1.2335919201463813E-001,
      -1.1527795237518552E-001, -1.0648399763981058E-001,
      -9.7280881960550555E-002, -8.7922945537728142E-002,
      -7.8620071897585991E-002, -6.9541714473863481E-002,
      -6.0821071780829419E-002, -5.2559347723382457E-002,
      -4.4829838828516266E-002, -3.7681761795900368E-002,
      -3.1143821384996908E-002, -2.5227511673263849E-002,
      -1.9930134438114248E-002, -1.5237526373313433E-002,
      -1.1126497174880833E-002, -7.5669864653181802E-003,
      -4.5239509580008034E-003, -1.9589960835439753E-003,
      1.6823138952124308E-004, 1.8988716535705389E-003, 3.2738821524053866E-003,
      4.3332506418963211E-003, 5.1153719343336509E-003, 5.6565697277814117E-003,
      5.9907456935170958E-003, 6.1491389834430797E-003, 6.1601804655148813E-003,
      6.0494272481002743E-003, 5.8395643699792436E-003, 5.5504618734983895E-003,
      5.1992768154454439E-003, 4.8005910869652526E-003, 4.3665771886463537E-003,
      3.9071852802757172E-003, 3.4303458503136958E-003, 2.9421833959144541E-003,
      2.4472378960774680E-003, 1.9486920415979414E-003, 1.4486010172562421E-003,
      9.4811878932865297E-004, 4.4772134938181107E-004, -5.2549741954872284E-005,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      4.4881791849378187E-016, 1.4437322545247437E-015, -2.0110878424985441E-002,
      -4.0221756849971819E-002, -6.0332635274958003E-002,
      -8.0443513699944597E-002, -1.0055439212493118E-001,
      -1.2066527054991684E-001, -1.4077614897490481E-001,
      -1.6088702739988917E-001, -1.8099790582487468E-001,
      -2.0110878424986089E-001, -2.2121966267484799E-001,
      -2.4133054109983507E-001, -2.6144141952482031E-001,
      -2.8155229794980519E-001, -3.0166317637479140E-001,
      -3.2177405479977728E-001, -3.4188493322476371E-001,
      -3.6199581164975053E-001, -3.8210669007473680E-001,
      -4.0221756849972179E-001, -4.2232844692470839E-001,
      -4.4243932534969599E-001, -4.6255020377468054E-001,
      -4.8266108219966608E-001, -5.0277196062465024E-001,
      -5.0324251697590350E-001, -4.8460220604609827E-001,
      -4.6449132762111123E-001, -4.4438044919612596E-001,
      -4.2426957077113997E-001, -4.0415869234615304E-001,
      -3.8404781392116666E-001, -3.6393693549617934E-001,
      -3.4382605707119107E-001, -3.2371517864620536E-001,
      -3.0360430022121954E-001, -2.8349342179623344E-001,
      -2.6338254337124711E-001, -2.4327166494626112E-001,
      -2.2316078652127591E-001, -2.0304990809629084E-001,
      -1.8293902967130349E-001, -1.6282815124631711E-001,
      -1.4271727282133145E-001, -1.2260639439634506E-001,
      -1.0249551597135963E-001, -8.2384637546373957E-002,
      -6.2273759121387162E-002, -4.2162880696400319E-002,
      -2.3433074337873852E-002, -7.9914521898988393E-003,
      4.3363571657305533E-003, 1.4239962611985631E-002, 2.2079188520189738E-002,
      2.8038138447272043E-002, 3.2324958557811624E-002, 3.5175818941497274E-002,
      3.6812462717038884E-002, 3.7431745691289445E-002, 3.7211494560564835E-002,
      3.6313429694888343E-002, 3.4882570772135857E-002, 3.3046896229788833E-002,
      3.0918035579460601E-002, 2.8592308130466166E-002, 2.6151761643618883E-002,
      2.3665238846930392E-002, 2.1189508940596489E-002, 1.8770432259202094E-002,
      1.6444116793729067E-002, 1.4238042838250939E-002, 1.2172142029271058E-002,
      1.0259819497824915E-002, 8.5089098922600612E-003, 6.9225610561987451E-003,
      5.5000419953398381E-003, 4.2374739579663203E-003, 3.1284851697496751E-003,
      2.1647911737884495E-003, 1.3367038629409458E-003, 6.3357315970345317E-004,
      4.4165928288301196E-005, -4.4301286966034705E-004,
      -8.3945151248486093E-004, -1.1564099859213831E-003,
      -1.4047402322175404E-003, -1.5947429139207777E-003,
      -1.7360555932776022E-003, -1.8375676334854781E-003,
      -1.9073577198458428E-003, -1.9526498175999980E-003,
      -1.9797819993488627E-003, -1.9941834179155568E-003,
      -2.0003640973639976E-003, -2.0019289117106315E-003,
      -2.0015897597850242E-003, -2.0010843653460201E-003,
      -2.0010322436571238E-003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 2.7048463276208756E-016, 5.2359877559829882E-001,
      5.2359877559829882E-001, 5.2359877559829882E-001, 5.2359877559829693E-001,
      5.2359877559829882E-001, 5.2359877559829882E-001, 5.2359877559829793E-001,
      5.2359877559829882E-001, 5.2359877559829882E-001, 5.2359877559829782E-001,
      5.2359877559829882E-001, 5.2359877559829882E-001, 5.2359877559829882E-001,
      5.2359877559829882E-001, 5.2359877559829548E-001, 5.2359877559829715E-001,
      5.2359877559829882E-001, 5.2359877559829504E-001, 5.2359877559829882E-001,
      5.2359877559829882E-001, 5.2359877559829882E-001, 5.2359877559829882E-001,
      5.2359877559829793E-001, 5.2359877559829882E-001, 5.2359877559827883E-001,
      1.2251216687794350E-002, -4.8531166930487890E-001,
      -5.2359877559829882E-001, -5.2359877559829815E-001,
      -5.2359877559829882E-001, -5.2359877559829882E-001,
      -5.2359877559829437E-001, -5.2359877559829482E-001,
      -5.2359877559829882E-001, -5.2359877559829859E-001,
      -5.2359877559829460E-001, -5.2359877559829882E-001,
      -5.2359877559829826E-001, -5.2359877559829293E-001,
      -5.2359877559829793E-001, -5.2359877559829882E-001,
      -5.2359877559829882E-001, -5.2359877559829882E-001,
      -5.2359877559829859E-001, -5.2359877559829882E-001,
      -5.2359877559829882E-001, -5.2359877559829882E-001,
      -5.2359877559829882E-001, -5.2359877559829204E-001,
      -4.8764173644115083E-001, -4.0203188936223272E-001,
      -3.2096190668613361E-001, -2.5784630467584202E-001,
      -2.0409894587570951E-001, -1.5514483354416125E-001,
      -1.1160993138418357E-001, -7.4223859085374502E-002,
      -4.2611001809822836E-002, -1.6123403474197499E-002,
      5.7343702216407716E-003, 2.3381657137931600E-002, 3.7253269806290630E-002,
      4.7792887135913904E-002, 5.5426163212556223E-002, 6.0551708330931903E-002,
      6.3541090811652282E-002, 6.4738111599626683E-002, 6.4457112229260594E-002,
      6.2982111556240936E-002, 6.0567017692479012E-002, 5.7436457898952312E-002,
      5.3786966000722927E-002, 4.9788463480063348E-002, 4.5585981193050566E-002,
      4.1301542910304856E-002, 3.7036136502397218E-002, 3.2871715720622918E-002,
      2.8873187903172375E-002, 2.5090350887396973E-002, 2.1559749548747772E-002,
      1.8306429362296834E-002, 1.5345570599955774E-002, 1.2683992052103686E-002,
      1.0321517717738560E-002, 8.2522038619970983E-003, 6.4654268280574341E-003,
      4.9468337184280370E-003, 3.6791603193006722E-003, 2.6429268199132756E-003,
      1.8170267352351070E-003, 1.1792069161321612E-003, 7.0640261666317665E-004,
      3.7494956556348707E-004, 1.6091769456942100E-004, 4.0740879579220642E-005,
      -8.8300236847697083E-006, -1.3158247189475884E-005,
      -1.3570194189570075E-006, 4.2103274230647550E-006, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0943951023931899E+000,
      2.5443230210441341E-015, 5.3113892317974319E-017, -9.8995895227095657E-015,
      2.9035543500047888E-015, 2.7325821804526298E-015, -4.7091651875831314E-015,
      -3.4273854352749680E-015, 1.0174582388251130E-016,
      -1.6681059533001867E-015, 5.8692667768140044E-015, 2.9787387864512834E-015,
      -1.9175739234813234E-015, 4.4426426057101605E-015,
      -1.3336174884610979E-014, -6.5521263985234978E-015,
      5.0451464080639454E-015, -1.2091007664216664E-014, 1.2351543971205755E-014,
      1.0186396881989142E-014, -5.7915912851266823E-016,
      -1.3426730251415696E-015, 2.5508191621206712E-015, 3.1613726216838018E-015,
      -7.5324970027839055E-014, -2.0453902356419458E+000,
      -1.9902515439706927E+000, -1.5314842517368360E-001,
      2.2633950385802152E-016, 1.0551090231123589E-015, -2.5629632577096910E-015,
      2.9541735715163623E-014, -5.7991809698386364E-015,
      -1.4554132707560477E-014, -5.4827022981544087E-015,
      1.3185308682056687E-014, -1.6549599880783458E-014,
      -8.2266097798755302E-015, 1.8557684580628466E-014,
      -1.5484088791875080E-014, -1.2205745868153750E-014,
      -6.3558873561403644E-015, 3.9304232640578018E-015,
      -4.2578537766830778E-015, 3.5664095205977234E-015,
      -3.1461630944363873E-015, 5.4253010458397060E-015,
      -9.2407999013209837E-015, 1.7240981591689692E-014, 1.4382815662856555E-001,
      3.4243938831567500E-001, 3.2427993070439615E-001, 2.5246240804116543E-001,
      2.1498943520052974E-001, 1.9581644932619308E-001, 1.7413960863991162E-001,
      1.4954428919523535E-001, 1.2645142910220572E-001, 1.0595039334249670E-001,
      8.7431094783355520E-002, 7.0589147665156990E-002, 5.5486450673434190E-002,
      4.2158469318489683E-002, 3.0533104306567121E-002, 2.0502180473508803E-002,
      1.1957529922878834E-002, 4.7880831518967298E-003, -1.1239974814593419E-003,
      -5.9000026920736472E-003, -9.6603754550487145E-003,
      -1.2522239174103153E-002, -1.4597967592916329E-002,
      -1.5994010082638600E-002, -1.6809929148049761E-002,
      -1.7137753130985763E-002, -1.7061625631631772E-002,
      -1.6657683127099060E-002, -1.5994111269803594E-002,
      -1.5131348063102245E-002, -1.4122405354598438E-002,
      -1.3013280745801424E-002, -1.1843435049363638E-002,
      -1.0646314191406532E-002, -9.4498973374610752E-003,
      -8.2772554229664421E-003, -7.1471081357601159E-003,
      -6.0743724385198096E-003, -5.0706935965104576E-003,
      -4.1449339975503019E-003, -3.3036003387116870E-003,
      -2.5512792764118496E-003, -1.8912171978761431E-003,
      -1.3258122043976106E-003, -8.5612748397726705E-004,
      -4.8070725996191916E-004, -1.9828361305667075E-004,
      -1.7312894017302496E-005, 4.7204911081471840E-005, 2.2269387367156062E-005,
      6.4271235766565723E-006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter04_DWork.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues;
    helikopter04_DWork.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues;
    helikopter04_DWork.FromWorkspace1_IWORK.PrevIndex = 0;
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
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      2.3695375670177166E-001, 5.9238439175449124E-002, 5.2359877559829371E-001,
      5.2359877559829782E-001, 5.2359877559829748E-001, 5.2359877559829882E-001,
      5.2359877559829848E-001, 5.2359877559829826E-001, 5.2359877559829882E-001,
      5.2359877559829704E-001, 5.2359877559829693E-001, 5.2359877559829882E-001,
      5.2359877559829859E-001, 5.2359877559829870E-001, 5.2359877559829826E-001,
      5.2359877559829804E-001, 5.2359877559829882E-001, 5.2359877559829882E-001,
      5.2359877559829882E-001, 5.2359877559829449E-001, 5.2359877559829526E-001,
      5.2359877559829815E-001, 5.2359877559829882E-001, 5.2359877559829870E-001,
      5.2359877559829882E-001, 2.9218928667106642E-001, 2.4057514528508317E-001,
      -6.1368364227489661E-002, -4.8964336090361105E-001,
      -5.2359877559829815E-001, -5.2359877559829882E-001,
      -5.2359877559829648E-001, -5.2359877559829737E-001,
      -5.2359877559829882E-001, -5.2359877559829882E-001,
      -5.2359877559829948E-001, -5.2359877559829882E-001,
      -5.2359877559829882E-001, -5.2359877559829771E-001,
      -5.2359877559829882E-001, -5.2359877559829882E-001,
      -5.2359877559829882E-001, -5.2359877559829737E-001,
      -5.2359877559829870E-001, -5.2359877559829660E-001,
      -5.2359877559829882E-001, -5.2359877559829848E-001,
      -5.2359877559829882E-001, -5.2359877559829882E-001,
      -5.0732647721787871E-001, -4.8078810682344364E-001,
      -4.4126800181560821E-001, -3.6429700692678713E-001,
      -2.8949791345510922E-001, -2.2961138290546154E-001,
      -1.7885877260546082E-001, -1.3330041666203643E-001,
      -9.3073834063652397E-002, -5.8660353908721992E-002,
      -2.9722572944489038E-002, -5.6642282751285643E-003,
      1.4008508106953475E-002, 2.9720737285666637E-002, 4.1900117804808644E-002,
      5.0976050674855701E-002, 5.7358892525385612E-002, 6.1431628121216754E-002,
      6.3549352455688268E-002, 6.4038811043965277E-002, 6.3197288233865931E-002,
      6.1292145238813399E-002, 5.8561263782814593E-002, 5.5214049345843945E-002,
      5.1432760698514809E-002, 4.7374091451874233E-002, 4.3170949745770883E-002,
      3.8934365551332797E-002, 3.4755458948407134E-002, 3.0707417327279579E-002,
      2.6847440975351598E-002, 2.3218624293946558E-002, 1.9851746668563465E-002,
      1.6766953479356923E-002, 1.3975313523366997E-002, 1.1480244042278893E-002,
      9.2787985995836202E-003, 7.3628163260133564E-003, 5.7199341379623840E-003,
      4.3344670953736142E-003, 3.1881641695176706E-003, 2.2608425915118541E-003,
      1.5308988593025221E-003, 9.7571668787021734E-004, 5.7204321673451082E-004,
      2.9634880545874196E-004, 1.2488801005528720E-004, 3.3173841721565721E-005,
      -3.9790802379737414E-006, -9.3035971095037235E-006,
      -1.8297622208256311E-033, -1.8297622208256311E-033, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0 } ;

    helikopter04_DWork.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues;
    helikopter04_DWork.FromWorkspace_PWORK.DataPtr = (void *) pDataValues;
    helikopter04_DWork.FromWorkspace_IWORK.PrevIndex = 0;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  helikopter04_terminate();
}

RT_MODEL_helikopter04 *helikopter04(void)
{
  helikopter04_initialize(1);
  return helikopter04_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
