/*
 * helikopter04day2.c
 *
 * Real-Time Workshop code generation for Simulink model "helikopter04day2.mdl".
 *
 * Model version              : 1.79
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 16 12:51:51 2015
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "helikopter04day2.h"
#include "helikopter04day2_private.h"
#include <stdio.h>
#include "helikopter04day2_dt.h"

/* Block signals (auto storage) */
BlockIO_helikopter04day2 helikopter04day2_B;

/* Continuous states */
ContinuousStates_helikopter04da helikopter04day2_X;

/* Block states (auto storage) */
D_Work_helikopter04day2 helikopter04day2_DWork;

/* Real-time model */
RT_MODEL_helikopter04day2 helikopter04day2_M_;
RT_MODEL_helikopter04day2 *helikopter04day2_M = &helikopter04day2_M_;

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
  helikopter04day2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter04day2_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_HILReadEncoder_o2;
  real_T rtb_HILReadEncoder_o3;
  real_T rtb_Saturation_m;
  real_T rtb_Sum;
  real_T rtb_Gain[6];
  real_T rtb_Gain1;
  real_T tmp[6];
  int32_T tmp_0;
  int32_T tmp_1;
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    /* set solver stop time */
    if (!(helikopter04day2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter04day2_M->solverInfo,
                            ((helikopter04day2_M->Timing.clockTickH0 + 1) *
        helikopter04day2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter04day2_M->solverInfo,
                            ((helikopter04day2_M->Timing.clockTick0 + 1) *
        helikopter04day2_M->Timing.stepSize0 +
        helikopter04day2_M->Timing.clockTickH0 *
        helikopter04day2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter04day2_M)) {
    helikopter04day2_M->Timing.t[0] = rtsiGetT(&helikopter04day2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder' */

    /* S-Function Block: helikopter04day2/Heli 3D/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder
        (helikopter04day2_DWork.HILInitialize_Card,
         helikopter04day2_P.HILReadEncoder_Channels, 3,
         &helikopter04day2_DWork.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder_o1 = helikopter04day2_DWork.HILReadEncoder_Buffer[0];
        rtb_HILReadEncoder_o2 = helikopter04day2_DWork.HILReadEncoder_Buffer[1];
        rtb_HILReadEncoder_o3 = helikopter04day2_DWork.HILReadEncoder_Buffer[2];
      }
    }

    /* Gain: '<S2>/Kalibrer-Elev' */
    helikopter04day2_B.KalibrerElev = helikopter04day2_P.KalibrerElev_Gain *
      rtb_HILReadEncoder_o3;

    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Constant'
     */
    helikopter04day2_B.Add = helikopter04day2_B.KalibrerElev +
      helikopter04day2_P.Constant_Value;
  }

  /* TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04day2_B.VandringLavpass = helikopter04day2_P.VandringLavpass_C*
    helikopter04day2_X.VandringLavpass_CSTATE;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  helikopter04day2_B.Add1 = helikopter04day2_P.Constant1_Value +
    helikopter04day2_B.VandringLavpass;
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    /* Gain: '<S2>/Kalibrer -Vandring' */
    helikopter04day2_B.KalibrerVandring =
      helikopter04day2_P.KalibrerVandring_Gain * rtb_HILReadEncoder_o1;
  }

  /* TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04day2_B.VandringDeriv = helikopter04day2_P.VandringDeriv_D*
    helikopter04day2_B.KalibrerVandring;
  helikopter04day2_B.VandringDeriv += helikopter04day2_P.VandringDeriv_C*
    helikopter04day2_X.VandringDeriv_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
  }

  /* TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04day2_B.TransferFcn5 = helikopter04day2_P.TransferFcn5_D*
    helikopter04day2_B.KalibrerElev;
  helikopter04day2_B.TransferFcn5 += helikopter04day2_P.TransferFcn5_C*
    helikopter04day2_X.TransferFcn5_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    /* Gain: '<S2>/Kalibrer-Pitch' */
    helikopter04day2_B.KalibrerPitch = helikopter04day2_P.KalibrerPitch_Gain *
      rtb_HILReadEncoder_o2;
  }

  /* TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04day2_B.TransferFcn4 = helikopter04day2_P.TransferFcn4_D*
    helikopter04day2_B.KalibrerPitch;
  helikopter04day2_B.TransferFcn4 += helikopter04day2_P.TransferFcn4_C*
    helikopter04day2_X.TransferFcn4_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
  }

  /* Integrator: '<S1>/Integrator'
   *
   * Regarding '<S1>/Integrator':
   *  Limited Integrator
   */
  if (helikopter04day2_X.Integrator_CSTATE >=
      helikopter04day2_P.Integrator_UpperSat ) {
    helikopter04day2_X.Integrator_CSTATE =
      helikopter04day2_P.Integrator_UpperSat;
  } else if (helikopter04day2_X.Integrator_CSTATE <=
             helikopter04day2_P.Integrator_LowerSat ) {
    helikopter04day2_X.Integrator_CSTATE =
      helikopter04day2_P.Integrator_LowerSat;
  }

  rtb_Saturation_m = helikopter04day2_X.Integrator_CSTATE;

  /* Gain: '<Root>/Gain' incorporates:
   *  SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1'
   */
  tmp[0] = helikopter04day2_B.Add1;
  tmp[1] = helikopter04day2_B.VandringDeriv;
  tmp[2] = helikopter04day2_B.KalibrerPitch;
  tmp[3] = helikopter04day2_B.TransferFcn4;
  tmp[4] = helikopter04day2_B.Add;
  tmp[5] = helikopter04day2_B.TransferFcn5;
  for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
    rtb_Gain[tmp_0] = 0.0;
    for (tmp_1 = 0; tmp_1 < 6; tmp_1++) {
      rtb_Gain[tmp_0] += helikopter04day2_P.Gain_Gain[6 * tmp_1 + tmp_0] *
        tmp[tmp_1];
    }
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<Root>/elevation'
   */
  rtb_Sum = helikopter04day2_P.elevation_Value - rtb_Gain[4];

  /* Gain: '<S1>/K_ei' */
  helikopter04day2_B.K_ei = helikopter04day2_P.K_ei_Gain * rtb_Sum;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/K_ed'
   *  Gain: '<S1>/K_ep'
   */
  rtb_Saturation_m = (helikopter04day2_P.K_ep_Gain * rtb_Sum + rtb_Saturation_m)
    + helikopter04day2_P.K_ed_Gain * rtb_Gain[5];

  /* Saturate: '<S1>/Saturation' */
  rtb_Saturation_m = rt_SATURATE(rtb_Saturation_m,
    helikopter04day2_P.Saturation_LowerSat,
    helikopter04day2_P.Saturation_UpperSat);

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter04day2_DWork.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter04day2_DWork.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = helikopter04day2_DWork.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter04day2_M->Timing.t[0];

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

    helikopter04day2_DWork.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Sum = pDataValues[currTimeIndex];
        } else {
          rtb_Sum = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/K_pd'
   *  Gain: '<S3>/K_pp'
   *  Saturate: '<S3>/Saturation'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Sum = (rt_SATURATE(rtb_Sum, helikopter04day2_P.Saturation_LowerSat_e,
              helikopter04day2_P.Saturation_UpperSat_l) - rtb_Gain[2]) *
    helikopter04day2_P.K_pp_Gain - helikopter04day2_P.K_pd_Gain * rtb_Gain[3];

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Gain1 = (rtb_Saturation_m - rtb_Sum) * helikopter04day2_P.Gain2_Gain;

  /* Saturate: '<S2>/Sat B' */
  helikopter04day2_B.SatB = rt_SATURATE(rtb_Gain1,
    helikopter04day2_P.SatB_LowerSat, helikopter04day2_P.SatB_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Gain1 = (rtb_Sum + rtb_Saturation_m) * helikopter04day2_P.Gain1_Gain;

  /* Saturate: '<S2>/Sat' */
  helikopter04day2_B.Sat = rt_SATURATE(rtb_Gain1,
    helikopter04day2_P.Sat_LowerSat, helikopter04day2_P.Sat_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
  }

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   */
  helikopter04day2_B.Add_j = helikopter04day2_B.SatB -
    helikopter04day2_P.Constant_Value_i;
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: helikopter04day2/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter04day2_DWork.HILWriteAnalog_Buffer[0] = helikopter04day2_B.Add_j;
      helikopter04day2_DWork.HILWriteAnalog_Buffer[1] = helikopter04day2_B.Sat;
      result = hil_write_analog(helikopter04day2_DWork.HILInitialize_Card,
        helikopter04day2_P.HILWriteAnalog_Channels, 2,
        &helikopter04day2_DWork.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
      }
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void helikopter04day2_update(int_T tid)
{
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter04day2_M->solverInfo);
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
  if (!(++helikopter04day2_M->Timing.clockTick0)) {
    ++helikopter04day2_M->Timing.clockTickH0;
  }

  helikopter04day2_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter04day2_M->solverInfo);
  if (rtmIsMajorTimeStep(helikopter04day2_M)) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helikopter04day2_M->Timing.clockTick1)) {
      ++helikopter04day2_M->Timing.clockTickH1;
    }

    helikopter04day2_M->Timing.t[1] = helikopter04day2_M->Timing.clockTick1 *
      helikopter04day2_M->Timing.stepSize1 +
      helikopter04day2_M->Timing.clockTickH1 *
      helikopter04day2_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void helikopter04day2_derivatives(void)
{
  /* Derivatives for TransferFcn: '<S2>/Vandring Lavpass' */
  {
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->VandringLavpass_CSTATE = helikopter04day2_B.KalibrerVandring;
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->VandringLavpass_CSTATE += (helikopter04day2_P.VandringLavpass_A)*
      helikopter04day2_X.VandringLavpass_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Vandring Deriv' */
  {
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->VandringDeriv_CSTATE = helikopter04day2_B.KalibrerVandring;
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->VandringDeriv_CSTATE += (helikopter04day2_P.VandringDeriv_A)*
      helikopter04day2_X.VandringDeriv_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn5' */
  {
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->TransferFcn5_CSTATE = helikopter04day2_B.KalibrerElev;
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->TransferFcn5_CSTATE += (helikopter04day2_P.TransferFcn5_A)*
      helikopter04day2_X.TransferFcn5_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn4' */
  {
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->TransferFcn4_CSTATE = helikopter04day2_B.KalibrerPitch;
    ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs)
      ->TransferFcn4_CSTATE += (helikopter04day2_P.TransferFcn4_A)*
      helikopter04day2_X.TransferFcn4_CSTATE;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter04day2_X.Integrator_CSTATE <=
            helikopter04day2_P.Integrator_LowerSat );
    usat = ( helikopter04day2_X.Integrator_CSTATE >=
            helikopter04day2_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter04day2_B.K_ei > 0)) ||
        (usat && (helikopter04day2_B.K_ei < 0)) ) {
      ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs
        )->Integrator_CSTATE = helikopter04day2_B.K_ei;
    } else {
      /* in saturation */
      ((StateDerivatives_helikopter04da *) helikopter04day2_M->ModelData.derivs
        )->Integrator_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void helikopter04day2_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter04day2_P.Integrator_UpperSat = rtInf;
  helikopter04day2_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter04day2_M, 0,
                sizeof(RT_MODEL_helikopter04day2));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter04day2_M->solverInfo,
                          &helikopter04day2_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter04day2_M->solverInfo, &rtmGetTPtr(helikopter04day2_M));
    rtsiSetStepSizePtr(&helikopter04day2_M->solverInfo,
                       &helikopter04day2_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter04day2_M->solverInfo,
                 &helikopter04day2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter04day2_M->solverInfo,
                         &helikopter04day2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter04day2_M->solverInfo,
      &helikopter04day2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter04day2_M->solverInfo, (&rtmGetErrorStatus
      (helikopter04day2_M)));
    rtsiSetRTModelPtr(&helikopter04day2_M->solverInfo, helikopter04day2_M);
  }

  rtsiSetSimTimeStep(&helikopter04day2_M->solverInfo, MAJOR_TIME_STEP);
  helikopter04day2_M->ModelData.intgData.f[0] =
    helikopter04day2_M->ModelData.odeF[0];
  helikopter04day2_M->ModelData.contStates = ((real_T *) &helikopter04day2_X);
  rtsiSetSolverData(&helikopter04day2_M->solverInfo, (void *)
                    &helikopter04day2_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter04day2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helikopter04day2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter04day2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter04day2_M->Timing.sampleTimes =
      (&helikopter04day2_M->Timing.sampleTimesArray[0]);
    helikopter04day2_M->Timing.offsetTimes =
      (&helikopter04day2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter04day2_M->Timing.sampleTimes[0] = (0.0);
    helikopter04day2_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    helikopter04day2_M->Timing.offsetTimes[0] = (0.0);
    helikopter04day2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter04day2_M, &helikopter04day2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter04day2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter04day2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter04day2_M, -1);
  helikopter04day2_M->Timing.stepSize0 = 0.001;
  helikopter04day2_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  helikopter04day2_M->Sizes.checksums[0] = (1245189675U);
  helikopter04day2_M->Sizes.checksums[1] = (2962303157U);
  helikopter04day2_M->Sizes.checksums[2] = (365132111U);
  helikopter04day2_M->Sizes.checksums[3] = (502189207U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter04day2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter04day2_M->extModeInfo,
      &helikopter04day2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter04day2_M->extModeInfo,
                        helikopter04day2_M->Sizes.checksums);
    rteiSetTPtr(helikopter04day2_M->extModeInfo, rtmGetTPtr(helikopter04day2_M));
  }

  helikopter04day2_M->solverInfoPtr = (&helikopter04day2_M->solverInfo);
  helikopter04day2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&helikopter04day2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&helikopter04day2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter04day2_M->ModelData.blockIO = ((void *) &helikopter04day2_B);

  {
    helikopter04day2_B.KalibrerElev = 0.0;
    helikopter04day2_B.Add = 0.0;
    helikopter04day2_B.VandringLavpass = 0.0;
    helikopter04day2_B.Add1 = 0.0;
    helikopter04day2_B.KalibrerVandring = 0.0;
    helikopter04day2_B.VandringDeriv = 0.0;
    helikopter04day2_B.TransferFcn5 = 0.0;
    helikopter04day2_B.KalibrerPitch = 0.0;
    helikopter04day2_B.TransferFcn4 = 0.0;
    helikopter04day2_B.K_ei = 0.0;
    helikopter04day2_B.SatB = 0.0;
    helikopter04day2_B.Sat = 0.0;
    helikopter04day2_B.Add_j = 0.0;
  }

  /* parameters */
  helikopter04day2_M->ModelData.defaultParam = ((real_T *)&helikopter04day2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter04day2_X;
    helikopter04day2_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter04day2_X, 0,
                  sizeof(ContinuousStates_helikopter04da));
  }

  /* states (dwork) */
  helikopter04day2_M->Work.dwork = ((void *) &helikopter04day2_DWork);
  (void) memset((void *)&helikopter04day2_DWork, 0,
                sizeof(D_Work_helikopter04day2));

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      helikopter04day2_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      helikopter04day2_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  helikopter04day2_DWork.HILInitialize_AOMinimums[0] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMinimums[1] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMinimums[2] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMinimums[3] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMaximums[0] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMaximums[1] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMaximums[2] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOMaximums[3] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOVoltages[0] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOVoltages[1] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOVoltages[2] = 0.0;
  helikopter04day2_DWork.HILInitialize_AOVoltages[3] = 0.0;
  helikopter04day2_DWork.HILWriteAnalog_Buffer[0] = 0.0;
  helikopter04day2_DWork.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter04day2_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void helikopter04day2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter04day2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(helikopter04day2_DWork.HILInitialize_Card);
    hil_task_delete_all(helikopter04day2_DWork.HILInitialize_Card);
    hil_monitor_stop_all(helikopter04day2_DWork.HILInitialize_Card);
    hil_monitor_delete_all(helikopter04day2_DWork.HILInitialize_Card);
    is_switching = false;
    if ((helikopter04day2_P.HILInitialize_AOTerminate && !is_switching) ||
        (helikopter04day2_P.HILInitialize_AOExit && is_switching)) {
      helikopter04day2_DWork.HILInitialize_AOVoltages[0] =
        helikopter04day2_P.HILInitialize_AOFinal;
      helikopter04day2_DWork.HILInitialize_AOVoltages[1] =
        helikopter04day2_P.HILInitialize_AOFinal;
      helikopter04day2_DWork.HILInitialize_AOVoltages[2] =
        helikopter04day2_P.HILInitialize_AOFinal;
      helikopter04day2_DWork.HILInitialize_AOVoltages[3] =
        helikopter04day2_P.HILInitialize_AOFinal;
      result = hil_write_analog(helikopter04day2_DWork.HILInitialize_Card,
        &helikopter04day2_P.HILInitialize_AOChannels[0], 4U,
        &helikopter04day2_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
      }
    }

    hil_close(helikopter04day2_DWork.HILInitialize_Card);
    helikopter04day2_DWork.HILInitialize_Card = NULL;
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
  helikopter04day2_output(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter04day2_update(tid);
}

void MdlInitializeSizes(void)
{
  helikopter04day2_M->Sizes.numContStates = (5);/* Number of continuous states */
  helikopter04day2_M->Sizes.numY = (0);/* Number of model outputs */
  helikopter04day2_M->Sizes.numU = (0);/* Number of model inputs */
  helikopter04day2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter04day2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter04day2_M->Sizes.numBlocks = (52);/* Number of blocks */
  helikopter04day2_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  helikopter04day2_M->Sizes.numBlockPrms = (151);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04day2_X.VandringLavpass_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04day2_X.VandringDeriv_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04day2_X.TransferFcn5_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04day2_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  helikopter04day2_X.Integrator_CSTATE = helikopter04day2_P.Integrator_IC;
}

void MdlStart(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter04day2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("sensoray_model_626", "0",
                      &helikopter04day2_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((helikopter04day2_P.HILInitialize_CKPStart && !is_switching) ||
        (helikopter04day2_P.HILInitialize_CKPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_ClockModes =
          &helikopter04day2_DWork.HILInitialize_ClockModes[0];
        for (i1=0; i1 < 6; i1++) {
          dw_ClockModes[i1] = helikopter04day2_P.HILInitialize_CKModes;
        }
      }

      result = hil_set_clock_mode(helikopter04day2_DWork.HILInitialize_Card,
        (t_clock *) &helikopter04day2_P.HILInitialize_CKChannels[0], 6U,
        (t_clock_mode *) &helikopter04day2_DWork.HILInitialize_ClockModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(helikopter04day2_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
      return;
    }

    if ((helikopter04day2_P.HILInitialize_AIPStart && !is_switching) ||
        (helikopter04day2_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &helikopter04day2_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 16; i1++) {
          dw_AIMinimums[i1] = helikopter04day2_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &helikopter04day2_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 16; i1++) {
          dw_AIMaximums[i1] = helikopter04day2_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (helikopter04day2_DWork.HILInitialize_Card,
         &helikopter04day2_P.HILInitialize_AIChannels[0], 16U,
         &helikopter04day2_DWork.HILInitialize_AIMinimums[0],
         &helikopter04day2_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter04day2_P.HILInitialize_AOPStart && !is_switching) ||
        (helikopter04day2_P.HILInitialize_AOPEnter && is_switching)) {
      helikopter04day2_DWork.HILInitialize_AOMinimums[0] =
        helikopter04day2_P.HILInitialize_AOLow;
      helikopter04day2_DWork.HILInitialize_AOMinimums[1] =
        helikopter04day2_P.HILInitialize_AOLow;
      helikopter04day2_DWork.HILInitialize_AOMinimums[2] =
        helikopter04day2_P.HILInitialize_AOLow;
      helikopter04day2_DWork.HILInitialize_AOMinimums[3] =
        helikopter04day2_P.HILInitialize_AOLow;
      helikopter04day2_DWork.HILInitialize_AOMaximums[0] =
        helikopter04day2_P.HILInitialize_AOHigh;
      helikopter04day2_DWork.HILInitialize_AOMaximums[1] =
        helikopter04day2_P.HILInitialize_AOHigh;
      helikopter04day2_DWork.HILInitialize_AOMaximums[2] =
        helikopter04day2_P.HILInitialize_AOHigh;
      helikopter04day2_DWork.HILInitialize_AOMaximums[3] =
        helikopter04day2_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (helikopter04day2_DWork.HILInitialize_Card,
         &helikopter04day2_P.HILInitialize_AOChannels[0], 4U,
         &helikopter04day2_DWork.HILInitialize_AOMinimums[0],
         &helikopter04day2_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter04day2_P.HILInitialize_AOStart && !is_switching) ||
        (helikopter04day2_P.HILInitialize_AOEnter && is_switching)) {
      helikopter04day2_DWork.HILInitialize_AOVoltages[0] =
        helikopter04day2_P.HILInitialize_AOInitial;
      helikopter04day2_DWork.HILInitialize_AOVoltages[1] =
        helikopter04day2_P.HILInitialize_AOInitial;
      helikopter04day2_DWork.HILInitialize_AOVoltages[2] =
        helikopter04day2_P.HILInitialize_AOInitial;
      helikopter04day2_DWork.HILInitialize_AOVoltages[3] =
        helikopter04day2_P.HILInitialize_AOInitial;
      result = hil_write_analog(helikopter04day2_DWork.HILInitialize_Card,
        &helikopter04day2_P.HILInitialize_AOChannels[0], 4U,
        &helikopter04day2_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter04day2_M, _rt_error_message);
        return;
      }
    }
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

    helikopter04day2_DWork.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues;
    helikopter04day2_DWork.FromWorkspace_PWORK.DataPtr = (void *) pDataValues;
    helikopter04day2_DWork.FromWorkspace_IWORK.PrevIndex = 0;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  helikopter04day2_terminate();
}

RT_MODEL_helikopter04day2 *helikopter04day2(void)
{
  helikopter04day2_initialize(1);
  return helikopter04day2_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
