/*
 * helikopter04day4OptMedFeed_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&helikopter04day4OptMedFeed_B.VandringLavpass), 0, 0, 15 }
  ,

  { (char_T *)(&helikopter04day4OptMedFee_DWork.HILInitialize_AIMinimums[0]), 0,
    0, 46 },

  { (char_T *)(&helikopter04day4OptMedFee_DWork.HILReadEncoder_PWORK), 11, 0, 21
  },

  { (char_T *)(&helikopter04day4OptMedFee_DWork.HILInitialize_ClockModes[0]), 6,
    0, 9 },

  { (char_T *)(&helikopter04day4OptMedFee_DWork.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&helikopter04day4OptMedFee_DWork.FromWorkspace1_IWORK.PrevIndex),
    10, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&helikopter04day4OptMedFeed_P.HILInitialize_OOStart), 0, 0, 93 },

  { (char_T *)(&helikopter04day4OptMedFeed_P.HILInitialize_CKChannels[0]), 6, 0,
    8 },

  { (char_T *)(&helikopter04day4OptMedFeed_P.HILInitialize_AIChannels[0]), 7, 0,
    26 },

  { (char_T *)(&helikopter04day4OptMedFeed_P.HILInitialize_Active), 8, 0, 35 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] helikopter04day4OptMedFeed_dt.h */
