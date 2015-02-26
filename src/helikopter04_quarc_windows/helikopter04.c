/*
 * helikopter04.c
 *
 * Real-Time Workshop code generation for Simulink model "helikopter04.mdl".
 *
 * Model version              : 1.76
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Feb 26 15:06:59 2015
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
  real_T rtb_VandringDeriv;
  real_T rtb_Add2;
  real_T rtb_Gain2;
  real_T rtb_Saturation_o;
  real_T rtb_Gain1;
  real_T rtb_Gain[6];
  real_T tmp[6];
  int32_T tmp_0;
  int32_T tmp_1;
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
    /* Gain: '<S2>/Kalibrer-Pitch' */
    helikopter04_B.KalibrerPitch = helikopter04_P.KalibrerPitch_Gain *
      rtb_HILReadEncoder_o2;
  }

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
          rtb_Add2 = pDataValues[currTimeIndex];
        } else {
          rtb_Add2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Add2 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* Sum: '<Root>/Add2' incorporates:
   *  Constant: '<Root>/elevation1'
   */
  rtb_Add2 += helikopter04_P.elevation1_Value;

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

  rtb_Saturation_o = helikopter04_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(helikopter04_M)) {
    /* Gain: '<S2>/Kalibrer -Vandring' */
    helikopter04_B.KalibrerVandring = helikopter04_P.KalibrerVandring_Gain *
      rtb_HILReadEncoder_o1;
  }

  /* TransferFcn: '<S2>/Vandring Deriv' */
  rtb_VandringDeriv = helikopter04_P.VandringDeriv_D*
    helikopter04_B.KalibrerVandring;
  rtb_VandringDeriv += helikopter04_P.VandringDeriv_C*
    helikopter04_X.VandringDeriv_CSTATE;

  /* TransferFcn: '<S2>/Transfer Fcn4' */
  rtb_Gain2 = helikopter04_P.TransferFcn4_D*helikopter04_B.KalibrerPitch;
  rtb_Gain2 += helikopter04_P.TransferFcn4_C*helikopter04_X.TransferFcn4_CSTATE;

  /* TransferFcn: '<S2>/Transfer Fcn5' */
  rtb_Gain1 = helikopter04_P.TransferFcn5_D*helikopter04_B.KalibrerElev;
  rtb_Gain1 += helikopter04_P.TransferFcn5_C*helikopter04_X.TransferFcn5_CSTATE;

  /* Gain: '<Root>/Gain' incorporates:
   *  SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1'
   */
  tmp[0] = helikopter04_B.Add1;
  tmp[1] = rtb_VandringDeriv;
  tmp[2] = helikopter04_B.KalibrerPitch;
  tmp[3] = rtb_Gain2;
  tmp[4] = helikopter04_B.Add;
  tmp[5] = rtb_Gain1;
  for (tmp_0 = 0; tmp_0 < 6; tmp_0++) {
    rtb_Gain[tmp_0] = 0.0;
    for (tmp_1 = 0; tmp_1 < 6; tmp_1++) {
      rtb_Gain[tmp_0] += helikopter04_P.Gain_Gain[6 * tmp_1 + tmp_0] * tmp[tmp_1];
    }
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<Root>/elevation'
   */
  rtb_Gain1 = helikopter04_P.elevation_Value - rtb_Gain[4];

  /* Gain: '<S1>/K_ei' */
  helikopter04_B.K_ei = helikopter04_P.K_ei_Gain * rtb_Gain1;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/K_ed'
   *  Gain: '<S1>/K_ep'
   */
  rtb_Saturation_o = (helikopter04_P.K_ep_Gain * rtb_Gain1 + rtb_Saturation_o) +
    helikopter04_P.K_ed_Gain * rtb_Gain[5];

  /* Saturate: '<S1>/Saturation' */
  rtb_Saturation_o = rt_SATURATE(rtb_Saturation_o,
    helikopter04_P.Saturation_LowerSat, helikopter04_P.Saturation_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04_M)) {
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/K_pd'
   *  Gain: '<S3>/K_pp'
   *  Saturate: '<S3>/Saturation'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Gain1 = (rt_SATURATE(rtb_Add2, helikopter04_P.Saturation_LowerSat_f,
    helikopter04_P.Saturation_UpperSat_m) - rtb_Gain[2]) *
    helikopter04_P.K_pp_Gain - helikopter04_P.K_pd_Gain * rtb_Gain[3];

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Sum4'
   */
  rtb_Gain2 = (rtb_Saturation_o - rtb_Gain1) * helikopter04_P.Gain2_Gain;

  /* Saturate: '<S2>/Sat B' */
  helikopter04_B.SatB = rt_SATURATE(rtb_Gain2, helikopter04_P.SatB_LowerSat,
    helikopter04_P.SatB_UpperSat);
  if (rtmIsMajorTimeStep(helikopter04_M)) {
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum3'
   */
  rtb_Gain1 = (rtb_Gain1 + rtb_Saturation_o) * helikopter04_P.Gain1_Gain;

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
  helikopter04_M->Sizes.checksums[0] = (3659401125U);
  helikopter04_M->Sizes.checksums[1] = (482111496U);
  helikopter04_M->Sizes.checksums[2] = (4040032832U);
  helikopter04_M->Sizes.checksums[3] = (1712036215U);

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
    helikopter04_B.KalibrerPitch = 0.0;
    helikopter04_B.KalibrerVandring = 0.0;
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
  helikopter04_M->Sizes.numBlocks = (50);/* Number of blocks */
  helikopter04_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  helikopter04_M->Sizes.numBlockPrms = (152);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for TransferFcn: '<S2>/Vandring Lavpass' */
  helikopter04_X.VandringLavpass_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  helikopter04_X.Integrator_CSTATE = helikopter04_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S2>/Vandring Deriv' */
  helikopter04_X.VandringDeriv_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn4' */
  helikopter04_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn5' */
  helikopter04_X.TransferFcn5_CSTATE = 0.0;
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
      2.3695375670178623E-001, 5.9238439175441915E-002, 7.4048048969303989E-002,
      7.4048048969304128E-002, 7.4048048969306418E-002, 7.4048048969306474E-002,
      7.4048048969306210E-002, 7.4048048969307695E-002, 7.4048048969304531E-002,
      7.1058068400491961E-002, 5.1321880280375640E-002, 4.4388783011123589E-002,
      3.8296625328151611E-002, 3.2492481058041152E-002, 2.7017179340067154E-002,
      2.1872787630958603E-002, 1.7050501959815393E-002, 1.2540378424316486E-002,
      8.3323062323419836E-003, 4.4160686556925640E-003, 7.8137443869717282E-004,
      -2.5821078143518088E-003, -5.6847168350237075E-003,
      -8.5367682738180031E-003, -1.1148526642985020E-002,
      -1.3530179525141047E-002, -1.5691813954108697E-002,
      -1.7643394875974244E-002, -1.9394745599055602E-002,
      -2.0955530142873716E-002, -2.2335237397161083E-002,
      -2.3543167003758535E-002, -2.4588416875498807E-002,
      -2.5479872268104588E-002, -2.6226196322799815E-002,
      -2.6835821999417940E-002, -2.7316945321628771E-002,
      -2.7677519858071171E-002, -2.7925252365367376E-002,
      -2.8067599521040272E-002, -2.8111765676724885E-002,
      -2.8064701564303372E-002, -2.7933103889722779E-002,
      -2.7723415751821020E-002, -2.7441827825486771E-002,
      -2.7094280250994977E-002, -2.6686465173544255E-002,
      -2.6223829879230148E-002, -2.5711580476146752E-002,
      -2.5154686071111213E-002, -2.4557883395333685E-002,
      -2.3925681833678554E-002, -2.3262368815026118E-002,
      -2.2572015522791249E-002, -2.1858482886928675E-002,
      -2.1125427820518575E-002, -2.0376309666146116E-002,
      -1.9614396818922256E-002, -1.8842773494869711E-002,
      -1.8064346615217004E-002, -1.7281852778573584E-002,
      -1.6497865294832284E-002, -1.5714801255950050E-002,
      -1.4934928620426119E-002, -1.4160373289556483E-002,
      -1.3393126154982921E-002, -1.2635050098321500E-002,
      -1.1887886924841724E-002, -1.1153264214375390E-002,
      -1.0432702073683785E-002, -9.7276197755801937E-003,
      -9.0393422710347213E-003, -8.3691065614753396E-003,
      -7.7180679192209185E-003, -7.0873059449624133E-003,
      -6.4778304517366242E-003, -5.8905871657155152E-003,
      -5.3264632346138379E-003, -4.7862925352077628E-003,
      -4.2708607718937204E-003, -3.7809103588044672E-003,
      -3.3171450783052252E-003, -2.8802345092103199E-003,
      -2.4708182183265618E-003, -2.0895097092748422E-003,
      -1.7369001228006091E-003, -1.4135616830319828E-003,
      -1.1200508843207399E-003, -8.5691141351561251E-004,
      -6.2467680261714268E-004, -4.2387280683786306E-004,
      -2.5501950246303862E-004, -1.1863309594150077E-004,
      -1.5227471574025091E-005, 5.4683735039819190E-005, 9.0577804129513516E-005,
      9.1901722526909748E-005, 5.8665427347653855E-005, 1.0269088747663548E-006,
      -7.5986800760581585E-017, -7.5986800760581585E-017, 0.0, 0.0, 0.0, 0.0,
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
