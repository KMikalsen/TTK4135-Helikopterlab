/*
 * helikopter04day4OptUnFeed_private.h
 *
 * Real-Time Workshop code generation for Simulink model "helikopter04day4OptUnFeed.mdl".
 *
 * Model version              : 1.81
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 09 12:38:45 2015
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_helikopter04day4OptUnFeed_private_h_
#define RTW_HEADER_helikopter04day4OptUnFeed_private_h_
#include "rtwtypes.h"

/* Used by FromWorkspace Block: '<Root>/From Workspace2' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];

/* private model entry point functions */
extern void helikopter04day4OptUnFeed_derivatives(void);

#endif                                 /* RTW_HEADER_helikopter04day4OptUnFeed_private_h_ */
