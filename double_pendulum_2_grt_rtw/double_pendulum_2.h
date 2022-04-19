/*
 * double_pendulum_2.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "double_pendulum_2".
 *
 * Model version              : 1.117
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Mon Apr 18 13:30:08 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_double_pendulum_2_h_
#define RTW_HEADER_double_pendulum_2_h_
#ifndef double_pendulum_2_COMMON_INCLUDES_
#define double_pendulum_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "nesl_rtw.h"
#include "double_pendulum_2_836bb176_1_gateway.h"
#include "double_pendulum_2_836bb176_2_gateway.h"
#include "double_pendulum_2_836bb176_3_gateway.h"
#endif                                 /* double_pendulum_2_COMMON_INCLUDES_ */

#include "double_pendulum_2_types.h"
#include <string.h>
#include <float.h>
#include "math.h"
#include <math.h>
#include "rt_matrixlib.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMassMatrixIr
#define rtmGetMassMatrixIr(rtm)        ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
#define rtmSetMassMatrixIr(rtm, val)   ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
#define rtmGetMassMatrixJc(rtm)        ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
#define rtmSetMassMatrixJc(rtm, val)   ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
#define rtmGetMassMatrixNzMax(rtm)     ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
#define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
#define rtmGetMassMatrixPr(rtm)        ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
#define rtmSetMassMatrixPr(rtm, val)   ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
#define rtmGetMassMatrixType(rtm)      ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
#define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
#define rtmGetOdeDELTA(rtm)            ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
#define rtmSetOdeDELTA(rtm, val)       ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
#define rtmGetOdeDFDX(rtm)             ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
#define rtmSetOdeDFDX(rtm, val)        ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
#define rtmGetOdeE(rtm)                ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
#define rtmSetOdeE(rtm, val)           ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeF0
#define rtmGetOdeF0(rtm)               ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
#define rtmSetOdeF0(rtm, val)          ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
#define rtmGetOdeF1(rtm)               ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
#define rtmSetOdeF1(rtm, val)          ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
#define rtmGetOdeFAC(rtm)              ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
#define rtmSetOdeFAC(rtm, val)         ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
#define rtmGetOdeMASSMATRIX_M(rtm)     ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
#define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdePIVOTS
#define rtmGetOdePIVOTS(rtm)           ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
#define rtmSetOdePIVOTS(rtm, val)      ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
#define rtmGetOdeW(rtm)                ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
#define rtmSetOdeW(rtm, val)           ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
#define rtmGetOdeX1START(rtm)          ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
#define rtmSetOdeX1START(rtm, val)     ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
#define rtmGetOdeXTMP(rtm)             ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
#define rtmSetOdeXTMP(rtm, val)        ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
#define rtmGetOdeZTMP(rtm)             ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
#define rtmSetOdeZTMP(rtm, val)        ((rtm)->odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T STATE_1[4];                   /* '<S19>/STATE_1' */
  real_T OUTPUT_1_0[4];                /* '<S19>/OUTPUT_1_0' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T INPUT_1_1_1[4];               /* '<S19>/INPUT_1_1_1' */
  real_T INTERNAL_3_1_1[4];            /* '<S19>/INTERNAL_3_1_1' */
  real_T STATE_2;                      /* '<S19>/STATE_2' */
  real_T OUTPUT_2_0;                   /* '<S19>/OUTPUT_2_0' */
  real_T INTERNAL_2_1_1[4];            /* '<S19>/INTERNAL_2_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S19>/INPUT_2_1_1' */
  real_T INTERNAL_4_1_1[4];            /* '<S19>/INTERNAL_4_1_1' */
  real_T STATE_3;                      /* '<S19>/STATE_3' */
  real_T OUTPUT_3_0;                   /* '<S19>/OUTPUT_3_0' */
  real_T INTERNAL_1_1_1[4];            /* '<S19>/INTERNAL_1_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S19>/INPUT_3_1_1' */
  real_T y1;                           /* '<S3>/MATLAB Function1' */
  real_T y2;                           /* '<S3>/MATLAB Function1' */
  real_T u[2];                         /* '<Root>/MATLAB Function' */
} B_double_pendulum_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[2];          /* '<Root>/Unit Delay' */
  real_T UnitDelay1_DSTATE[2];         /* '<Root>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S20>/UD' */
  real_T UD_DSTATE_g;                  /* '<S21>/UD' */
  real_T UD_DSTATE_d;                  /* '<S22>/UD' */
  real_T UD_DSTATE_h;                  /* '<S23>/UD' */
  real_T UD_DSTATE_m;                  /* '<S24>/UD' */
  real_T UD_DSTATE_o;                  /* '<S25>/UD' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S19>/INPUT_1_1_1' */
  real_T INTERNAL_3_1_1_Discrete[2];   /* '<S19>/INTERNAL_3_1_1' */
  real_T INTERNAL_2_1_1_Discrete[2];   /* '<S19>/INTERNAL_2_1_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S19>/INPUT_2_1_1' */
  real_T INTERNAL_4_1_1_Discrete[2];   /* '<S19>/INTERNAL_4_1_1' */
  real_T INTERNAL_1_1_1_Discrete[2];   /* '<S19>/INTERNAL_1_1_1' */
  real_T INPUT_3_1_1_Discrete[2];      /* '<S19>/INPUT_3_1_1' */
  real_T STATE_1_Discrete;             /* '<S19>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S19>/OUTPUT_1_0' */
  real_T STATE_2_Discrete;             /* '<S19>/STATE_2' */
  real_T OUTPUT_2_0_Discrete;          /* '<S19>/OUTPUT_2_0' */
  real_T STATE_3_Discrete;             /* '<S19>/STATE_3' */
  real_T OUTPUT_3_0_Discrete;          /* '<S19>/OUTPUT_3_0' */
  real_T ti1;                          /* '<S3>/MATLAB Function1' */
  real_T yi1;                          /* '<S3>/MATLAB Function1' */
  real_T tf1;                          /* '<S3>/MATLAB Function1' */
  real_T yf1;                          /* '<S3>/MATLAB Function1' */
  real_T T1;                           /* '<S3>/MATLAB Function1' */
  real_T flag1;                        /* '<S3>/MATLAB Function1' */
  real_T count1;                       /* '<S3>/MATLAB Function1' */
  real_T yi2;                          /* '<S3>/MATLAB Function1' */
  real_T tf2;                          /* '<S3>/MATLAB Function1' */
  real_T yf2;                          /* '<S3>/MATLAB Function1' */
  real_T T2;                           /* '<S3>/MATLAB Function1' */
  real_T flag2;                        /* '<S3>/MATLAB Function1' */
  real_T count2;                       /* '<S3>/MATLAB Function1' */
  real_T theta[7];                     /* '<Root>/MATLAB Function' */
  void* STATE_1_Simulator;             /* '<S19>/STATE_1' */
  void* STATE_1_SimData;               /* '<S19>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S19>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S19>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S19>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S19>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S19>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S19>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S19>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S19>/OUTPUT_1_0' */
  void* STATE_2_Simulator;             /* '<S19>/STATE_2' */
  void* STATE_2_SimData;               /* '<S19>/STATE_2' */
  void* STATE_2_DiagMgr;               /* '<S19>/STATE_2' */
  void* STATE_2_ZcLogger;              /* '<S19>/STATE_2' */
  void* STATE_2_TsInfo;                /* '<S19>/STATE_2' */
  void* OUTPUT_2_0_Simulator;          /* '<S19>/OUTPUT_2_0' */
  void* OUTPUT_2_0_SimData;            /* '<S19>/OUTPUT_2_0' */
  void* OUTPUT_2_0_DiagMgr;            /* '<S19>/OUTPUT_2_0' */
  void* OUTPUT_2_0_ZcLogger;           /* '<S19>/OUTPUT_2_0' */
  void* OUTPUT_2_0_TsInfo;             /* '<S19>/OUTPUT_2_0' */
  void* STATE_3_Simulator;             /* '<S19>/STATE_3' */
  void* STATE_3_SimData;               /* '<S19>/STATE_3' */
  void* STATE_3_DiagMgr;               /* '<S19>/STATE_3' */
  void* STATE_3_ZcLogger;              /* '<S19>/STATE_3' */
  void* STATE_3_TsInfo;                /* '<S19>/STATE_3' */
  void* OUTPUT_3_0_Simulator;          /* '<S19>/OUTPUT_3_0' */
  void* OUTPUT_3_0_SimData;            /* '<S19>/OUTPUT_3_0' */
  void* OUTPUT_3_0_DiagMgr;            /* '<S19>/OUTPUT_3_0' */
  void* OUTPUT_3_0_ZcLogger;           /* '<S19>/OUTPUT_3_0' */
  void* OUTPUT_3_0_TsInfo;             /* '<S19>/OUTPUT_3_0' */
  void* SINK_1_RtwLogger;              /* '<S19>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S19>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S19>/SINK_1' */
  uint32_T method;                     /* '<S3>/MATLAB Function1' */
  uint32_T state;                      /* '<S3>/MATLAB Function1' */
  uint32_T state_a[2];                 /* '<S3>/MATLAB Function1' */
  uint32_T state_m[625];               /* '<S3>/MATLAB Function1' */
  int_T STATE_1_Modes;                 /* '<S19>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S19>/OUTPUT_1_0' */
  int_T STATE_2_Modes;                 /* '<S19>/STATE_2' */
  int_T OUTPUT_2_0_Modes;              /* '<S19>/OUTPUT_2_0' */
  int_T STATE_3_Modes;                 /* '<S19>/STATE_3' */
  int_T OUTPUT_3_0_Modes;              /* '<S19>/OUTPUT_3_0' */
  int32_T STATE_2_MASS_MATRIX_PR;      /* '<S19>/STATE_2' */
  int32_T STATE_3_MASS_MATRIX_PR;      /* '<S19>/STATE_3' */
  boolean_T STATE_1_FirstOutput;       /* '<S19>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S19>/OUTPUT_1_0' */
  boolean_T STATE_2_FirstOutput;       /* '<S19>/STATE_2' */
  boolean_T OUTPUT_2_0_FirstOutput;    /* '<S19>/OUTPUT_2_0' */
  boolean_T STATE_3_FirstOutput;       /* '<S19>/STATE_3' */
  boolean_T OUTPUT_3_0_FirstOutput;    /* '<S19>/OUTPUT_3_0' */
  boolean_T ti1_not_empty;             /* '<S3>/MATLAB Function1' */
  boolean_T theta_not_empty;           /* '<Root>/MATLAB Function' */
} DW_double_pendulum_2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T double_pendulum_2SubsystemRevol[4];/* '<S19>/STATE_1' */
  real_T double_pendulum_2SubsystemPS_Ad;/* '<S19>/STATE_2' */
  real_T double_pendulum_2SubsystemPS__b;/* '<S19>/STATE_3' */
} X_double_pendulum_2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T double_pendulum_2SubsystemRevol[4];/* '<S19>/STATE_1' */
  real_T double_pendulum_2SubsystemPS_Ad;/* '<S19>/STATE_2' */
  real_T double_pendulum_2SubsystemPS__b;/* '<S19>/STATE_3' */
} XDot_double_pendulum_2_T;

/* State disabled  */
typedef struct {
  boolean_T double_pendulum_2SubsystemRevol[4];/* '<S19>/STATE_1' */
  boolean_T double_pendulum_2SubsystemPS_Ad;/* '<S19>/STATE_2' */
  boolean_T double_pendulum_2SubsystemPS__b;/* '<S19>/STATE_3' */
} XDis_double_pendulum_2_T;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[6];
  int_T jc[7];
  real_T pr[6];
} MassMatrix_double_pendulum_2_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Parameters (default storage) */
struct P_double_pendulum_2_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S20>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S21>/UD'
                               */
  real_T DiscreteDerivative2_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                               * Referenced by: '<S22>/UD'
                               */
  real_T DiscreteDerivative3_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative3_ICPrevScale
                               * Referenced by: '<S23>/UD'
                               */
  real_T DiscreteDerivative4_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative4_ICPrevScale
                               * Referenced by: '<S24>/UD'
                               */
  real_T DiscreteDerivative5_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative5_ICPrevScale
                               * Referenced by: '<S25>/UD'
                               */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S20>/TSamp'
                                        */
  real_T TSamp_WtEt_n;                 /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S21>/TSamp'
                                        */
  real_T TSamp_WtEt_a;                 /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S22>/TSamp'
                                        */
  real_T TSamp_WtEt_f;                 /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S23>/TSamp'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S24>/TSamp'
                                        */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S25>/TSamp'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_double_pendulum_2_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_double_pendulum_2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[6];
  real_T odeF0[6];
  real_T odeX1START[6];
  real_T odeF1[6];
  real_T odeDELTA[6];
  real_T odeE[4*6];
  real_T odeFAC[6];
  real_T odeDFDX[6*6];
  real_T odeW[6*6];
  int_T odePIVOTS[6];
  real_T odeXTMP[6];
  real_T odeZTMP[6];
  real_T odeMASSMATRIX_M[6];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_double_pendulum_2_T double_pendulum_2_P;

/* Block signals (default storage) */
extern B_double_pendulum_2_T double_pendulum_2_B;

/* Continuous states (default storage) */
extern X_double_pendulum_2_T double_pendulum_2_X;

/* Block states (default storage) */
extern DW_double_pendulum_2_T double_pendulum_2_DW;

/* global MassMatrix */
extern MassMatrix_double_pendulum_2_T double_pendulum_2_MassMatrix;

/* Model entry point functions */
extern void double_pendulum_2_initialize(void);
extern void double_pendulum_2_step(void);
extern void double_pendulum_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_double_pendulum_2_T *const double_pendulum_2_M;

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
 * '<Root>' : 'double_pendulum_2'
 * '<S1>'   : 'double_pendulum_2/MATLAB Function'
 * '<S2>'   : 'double_pendulum_2/Subsystem'
 * '<S3>'   : 'double_pendulum_2/reference generator'
 * '<S4>'   : 'double_pendulum_2/Subsystem/PS-Simulink Converter'
 * '<S5>'   : 'double_pendulum_2/Subsystem/PS-Simulink Converter1'
 * '<S6>'   : 'double_pendulum_2/Subsystem/PS-Simulink Converter2'
 * '<S7>'   : 'double_pendulum_2/Subsystem/PS-Simulink Converter3'
 * '<S8>'   : 'double_pendulum_2/Subsystem/Simulink-PS Converter'
 * '<S9>'   : 'double_pendulum_2/Subsystem/Simulink-PS Converter1'
 * '<S10>'  : 'double_pendulum_2/Subsystem/Simulink-PS Converter2'
 * '<S11>'  : 'double_pendulum_2/Subsystem/Solver Configuration'
 * '<S12>'  : 'double_pendulum_2/Subsystem/PS-Simulink Converter/EVAL_KEY'
 * '<S13>'  : 'double_pendulum_2/Subsystem/PS-Simulink Converter1/EVAL_KEY'
 * '<S14>'  : 'double_pendulum_2/Subsystem/PS-Simulink Converter2/EVAL_KEY'
 * '<S15>'  : 'double_pendulum_2/Subsystem/PS-Simulink Converter3/EVAL_KEY'
 * '<S16>'  : 'double_pendulum_2/Subsystem/Simulink-PS Converter/EVAL_KEY'
 * '<S17>'  : 'double_pendulum_2/Subsystem/Simulink-PS Converter1/EVAL_KEY'
 * '<S18>'  : 'double_pendulum_2/Subsystem/Simulink-PS Converter2/EVAL_KEY'
 * '<S19>'  : 'double_pendulum_2/Subsystem/Solver Configuration/EVAL_KEY'
 * '<S20>'  : 'double_pendulum_2/reference generator/Discrete Derivative'
 * '<S21>'  : 'double_pendulum_2/reference generator/Discrete Derivative1'
 * '<S22>'  : 'double_pendulum_2/reference generator/Discrete Derivative2'
 * '<S23>'  : 'double_pendulum_2/reference generator/Discrete Derivative3'
 * '<S24>'  : 'double_pendulum_2/reference generator/Discrete Derivative4'
 * '<S25>'  : 'double_pendulum_2/reference generator/Discrete Derivative5'
 * '<S26>'  : 'double_pendulum_2/reference generator/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_double_pendulum_2_h_ */
