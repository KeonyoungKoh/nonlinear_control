/*
 * double_pendulum_2.c
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

#include "double_pendulum_2.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "double_pendulum_2_private.h"

/* Block signals (default storage) */
B_double_pendulum_2_T double_pendulum_2_B;

/* Continuous states */
X_double_pendulum_2_T double_pendulum_2_X;

/* Block states (default storage) */
DW_double_pendulum_2_T double_pendulum_2_DW;

/* Mass Matrices */
MassMatrix_double_pendulum_2_T double_pendulum_2_MassMatrix;

/* Real-time model */
static RT_MODEL_double_pendulum_2_T double_pendulum_2_M_;
RT_MODEL_double_pendulum_2_T *const double_pendulum_2_M = &double_pendulum_2_M_;

/* Forward declaration for local functions */
static real_T double_pendulum_2_rand(void);

/* Projection for root system: '<Root>' */
void double_pendulum_2_projection(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  real_T tmp_0[12];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[4];
  boolean_T tmp;

  /* Projection for SimscapeExecutionBlock: '<S19>/STATE_1' */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_1_SimData;
  time = double_pendulum_2_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 4;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemRevol[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (double_pendulum_2_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&double_pendulum_2_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = double_pendulum_2_B.INTERNAL_2_1_1[0];
  tmp_0[1] = double_pendulum_2_B.INTERNAL_2_1_1[1];
  tmp_0[2] = double_pendulum_2_B.INTERNAL_2_1_1[2];
  tmp_0[3] = double_pendulum_2_B.INTERNAL_2_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = double_pendulum_2_B.INTERNAL_1_1_1[0];
  tmp_0[5] = double_pendulum_2_B.INTERNAL_1_1_1[1];
  tmp_0[6] = double_pendulum_2_B.INTERNAL_1_1_1[2];
  tmp_0[7] = double_pendulum_2_B.INTERNAL_1_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = double_pendulum_2_B.INPUT_3_1_1[0];
  tmp_0[9] = double_pendulum_2_B.INPUT_3_1_1[1];
  tmp_0[10] = double_pendulum_2_B.INPUT_3_1_1[2];
  tmp_0[11] = double_pendulum_2_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_1_Simulator, NESL_SIM_PROJECTION, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(double_pendulum_2_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S19>/STATE_1' */
}

/* ForcingFunction for root system: '<Root>' */
void double_pendulum_2_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  XDot_double_pendulum_2_T *_rtXdot;
  real_T tmp_1[12];
  real_T tmp_5[8];
  real_T tmp_7[8];
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_tmp;
  int32_T tmp_3;
  int_T tmp_2[4];
  int_T tmp_6[3];
  int_T tmp_8[3];
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_4;
  _rtXdot = ((XDot_double_pendulum_2_T *) double_pendulum_2_M->derivs);

  /* ForcingFunction for SimscapeExecutionBlock: '<S19>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S19>/STATE_2'
   *  SimscapeExecutionBlock: '<S19>/STATE_3'
   */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_1_SimData;
  time_tmp = double_pendulum_2_M->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 4;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemRevol[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  tmp = rtmIsMajorTimeStep(double_pendulum_2_M);
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0 = rtsiIsModeUpdateTimeStep(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_2[0] = 0;
  tmp_1[0] = double_pendulum_2_B.INTERNAL_2_1_1[0];
  tmp_1[1] = double_pendulum_2_B.INTERNAL_2_1_1[1];
  tmp_1[2] = double_pendulum_2_B.INTERNAL_2_1_1[2];
  tmp_1[3] = double_pendulum_2_B.INTERNAL_2_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = double_pendulum_2_B.INTERNAL_1_1_1[0];
  tmp_1[5] = double_pendulum_2_B.INTERNAL_1_1_1[1];
  tmp_1[6] = double_pendulum_2_B.INTERNAL_1_1_1[2];
  tmp_1[7] = double_pendulum_2_B.INTERNAL_1_1_1[3];
  tmp_2[2] = 8;
  tmp_1[8] = double_pendulum_2_B.INPUT_3_1_1[0];
  tmp_1[9] = double_pendulum_2_B.INPUT_3_1_1[1];
  tmp_1[10] = double_pendulum_2_B.INPUT_3_1_1[2];
  tmp_1[11] = double_pendulum_2_B.INPUT_3_1_1[3];
  tmp_2[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  simulationData->mData->mDx.mN = 4;
  simulationData->mData->mDx.mX = &_rtXdot->double_pendulum_2SubsystemRevol[0];
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_3 != 0) {
    tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp_4) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(double_pendulum_2_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S19>/STATE_1' */

  /* ForcingFunction for SimscapeExecutionBlock: '<S19>/STATE_2' */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_2_SimData;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemPS_Ad;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_2_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_2_Modes;
  tmp_4 = false;
  simulationData->mData->mFoundZcEvents = tmp_4;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_4 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_4;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_4 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_4;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_6[0] = 0;
  tmp_5[0] = double_pendulum_2_B.INPUT_1_1_1[0];
  tmp_5[1] = double_pendulum_2_B.INPUT_1_1_1[1];
  tmp_5[2] = double_pendulum_2_B.INPUT_1_1_1[2];
  tmp_5[3] = double_pendulum_2_B.INPUT_1_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = double_pendulum_2_B.INTERNAL_3_1_1[0];
  tmp_5[5] = double_pendulum_2_B.INTERNAL_3_1_1[1];
  tmp_5[6] = double_pendulum_2_B.INTERNAL_3_1_1[2];
  tmp_5[7] = double_pendulum_2_B.INTERNAL_3_1_1[3];
  tmp_6[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  simulationData->mData->mDx.mN = 1;
  simulationData->mData->mDx.mX = &_rtXdot->double_pendulum_2SubsystemPS_Ad;
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_2_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_2_Simulator, NESL_SIM_FORCINGFUNCTION,
    simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp_4) {
      char *msg_0;
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(double_pendulum_2_M, msg_0);
    }
  }

  /* ForcingFunction for SimscapeExecutionBlock: '<S19>/STATE_3' */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_3_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemPS__b;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_3_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_3_Modes;
  tmp_4 = false;
  simulationData->mData->mFoundZcEvents = tmp_4;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_8[0] = 0;
  tmp_7[0] = double_pendulum_2_B.INPUT_2_1_1[0];
  tmp_7[1] = double_pendulum_2_B.INPUT_2_1_1[1];
  tmp_7[2] = double_pendulum_2_B.INPUT_2_1_1[2];
  tmp_7[3] = double_pendulum_2_B.INPUT_2_1_1[3];
  tmp_8[1] = 4;
  tmp_7[4] = double_pendulum_2_B.INTERNAL_4_1_1[0];
  tmp_7[5] = double_pendulum_2_B.INTERNAL_4_1_1[1];
  tmp_7[6] = double_pendulum_2_B.INTERNAL_4_1_1[2];
  tmp_7[7] = double_pendulum_2_B.INTERNAL_4_1_1[3];
  tmp_8[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_7[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_8[0];
  simulationData->mData->mDx.mN = 1;
  simulationData->mData->mDx.mX = &_rtXdot->double_pendulum_2SubsystemPS__b;
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_3_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_3_Simulator, NESL_SIM_FORCINGFUNCTION,
    simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp) {
      char *msg_1;
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(double_pendulum_2_M, msg_1);
    }
  }
}

/* MassMatrix for root system: '<Root>' */
void double_pendulum_2_massmatrix(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  real_T tmp_1[8];
  real_T tmp_7[8];
  real_T time;
  real_T time_0;
  real_T time_tmp;
  real_T *tmp_3;
  real_T *tmp_4;
  real_T *tmp_9;
  int32_T tmp_5;
  int_T tmp_2[3];
  int_T tmp_8[3];
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_6;

  /* MassMatrix for SimscapeExecutionBlock: '<S19>/STATE_2' incorporates:
   *  SimscapeExecutionBlock: '<S19>/STATE_3'
   */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_2_SimData;
  time_tmp = double_pendulum_2_M->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemPS_Ad;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_2_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_2_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  tmp = rtmIsMajorTimeStep(double_pendulum_2_M);
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0 = rtsiIsModeUpdateTimeStep(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_2[0] = 0;
  tmp_1[0] = double_pendulum_2_B.INPUT_1_1_1[0];
  tmp_1[1] = double_pendulum_2_B.INPUT_1_1_1[1];
  tmp_1[2] = double_pendulum_2_B.INPUT_1_1_1[2];
  tmp_1[3] = double_pendulum_2_B.INPUT_1_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = double_pendulum_2_B.INTERNAL_3_1_1[0];
  tmp_1[5] = double_pendulum_2_B.INTERNAL_3_1_1[1];
  tmp_1[6] = double_pendulum_2_B.INTERNAL_3_1_1[2];
  tmp_1[7] = double_pendulum_2_B.INTERNAL_3_1_1[3];
  tmp_2[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  tmp_3 = double_pendulum_2_M->massMatrixPr;
  tmp_4 = double_pointer_shift(tmp_3,
    double_pendulum_2_DW.STATE_2_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 1;
  simulationData->mData->mMassMatrixPr.mX = tmp_4;
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_2_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_5 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_2_Simulator, NESL_SIM_MASSMATRIX, simulationData,
    diagnosticManager);
  if (tmp_5 != 0) {
    tmp_6 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp_6) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(double_pendulum_2_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S19>/STATE_2' */

  /* MassMatrix for SimscapeExecutionBlock: '<S19>/STATE_3' */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_3_SimData;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemPS__b;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_3_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_3_Modes;
  tmp_6 = false;
  simulationData->mData->mFoundZcEvents = tmp_6;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_8[0] = 0;
  tmp_7[0] = double_pendulum_2_B.INPUT_2_1_1[0];
  tmp_7[1] = double_pendulum_2_B.INPUT_2_1_1[1];
  tmp_7[2] = double_pendulum_2_B.INPUT_2_1_1[2];
  tmp_7[3] = double_pendulum_2_B.INPUT_2_1_1[3];
  tmp_8[1] = 4;
  tmp_7[4] = double_pendulum_2_B.INTERNAL_4_1_1[0];
  tmp_7[5] = double_pendulum_2_B.INTERNAL_4_1_1[1];
  tmp_7[6] = double_pendulum_2_B.INTERNAL_4_1_1[2];
  tmp_7[7] = double_pendulum_2_B.INTERNAL_4_1_1[3];
  tmp_8[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_7[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_8[0];
  tmp_9 = double_pendulum_2_M->massMatrixPr;
  tmp_4 = double_pointer_shift(tmp_9,
    double_pendulum_2_DW.STATE_3_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 1;
  simulationData->mData->mMassMatrixPr.mX = tmp_4;
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_3_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_5 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_3_Simulator, NESL_SIM_MASSMATRIX, simulationData,
    diagnosticManager);
  if (tmp_5 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp) {
      char *msg_0;
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(double_pendulum_2_M, msg_0);
    }
  }
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  double_pendulum_2_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 6;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    double_pendulum_2_step();
    rtsiSetdX(si,p);
    double_pendulum_2_forcingfunction();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  if (id->isFirstStep) {
    local_evaluateMassMatrix(si,M );
    id->isFirstStep = false;
  }

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  double_pendulum_2_forcingfunction();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
        real_T m_row_col = M[rowidx];
        row = Mpattern_ir[rowidx];
        p[row] += m_row_col;
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      double_pendulum_2_step();
      double_pendulum_2_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        double_pendulum_2_step();
        double_pendulum_2_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  double_pendulum_2_step();
  double_pendulum_2_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S3>/MATLAB Function1' */
static real_T double_pendulum_2_rand(void)
{
  real_T r;
  int32_T k;
  int32_T kk;
  uint32_T u[2];
  if (double_pendulum_2_DW.method == 4U) {
    uint32_T mti;
    uint32_T y;
    k = (int32_T)(double_pendulum_2_DW.state / 127773U);
    mti = (double_pendulum_2_DW.state - k * 127773U) * 16807U;
    y = 2836U * k;
    if (mti < y) {
      mti = ~(y - mti) & 2147483647U;
    } else {
      mti -= y;
    }

    r = (real_T)mti * 4.6566128752457969E-10;
    double_pendulum_2_DW.state = mti;
  } else if (double_pendulum_2_DW.method == 5U) {
    uint32_T mti;
    uint32_T y;
    mti = 69069U * double_pendulum_2_DW.state_a[0] + 1234567U;
    y = double_pendulum_2_DW.state_a[1] << 13 ^ double_pendulum_2_DW.state_a[1];
    y ^= y >> 17;
    y ^= y << 5;
    double_pendulum_2_DW.state_a[0] = mti;
    double_pendulum_2_DW.state_a[1] = y;
    r = (real_T)(mti + y) * 2.328306436538696E-10;
  } else {
    /* ========================= COPYRIGHT NOTICE ============================ */
    /*  This is a uniform (0,1) pseudorandom number generator based on:        */
    /*                                                                         */
    /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
    /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
    /*                                                                         */
    /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
    /*  All rights reserved.                                                   */
    /*                                                                         */
    /*  Redistribution and use in source and binary forms, with or without     */
    /*  modification, are permitted provided that the following conditions     */
    /*  are met:                                                               */
    /*                                                                         */
    /*    1. Redistributions of source code must retain the above copyright    */
    /*       notice, this list of conditions and the following disclaimer.     */
    /*                                                                         */
    /*    2. Redistributions in binary form must reproduce the above copyright */
    /*       notice, this list of conditions and the following disclaimer      */
    /*       in the documentation and/or other materials provided with the     */
    /*       distribution.                                                     */
    /*                                                                         */
    /*    3. The names of its contributors may not be used to endorse or       */
    /*       promote products derived from this software without specific      */
    /*       prior written permission.                                         */
    /*                                                                         */
    /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
    /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
    /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
    /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
    /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
    /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
    /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
    /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
    /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
    /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
    /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
    /*                                                                         */
    /* =============================   END   ================================= */
    int32_T exitg1;
    do {
      uint32_T mti;
      exitg1 = 0;
      for (k = 0; k < 2; k++) {
        uint32_T y;
        mti = double_pendulum_2_DW.state_m[624] + 1U;
        if (double_pendulum_2_DW.state_m[624] + 1U >= 625U) {
          for (kk = 0; kk < 227; kk++) {
            mti = (double_pendulum_2_DW.state_m[kk + 1] & 2147483647U) |
              (double_pendulum_2_DW.state_m[kk] & 2147483648U);
            if ((mti & 1U) == 0U) {
              mti >>= 1U;
            } else {
              mti = mti >> 1U ^ 2567483615U;
            }

            double_pendulum_2_DW.state_m[kk] = double_pendulum_2_DW.state_m[kk +
              397] ^ mti;
          }

          for (kk = 0; kk < 396; kk++) {
            mti = (double_pendulum_2_DW.state_m[kk + 227] & 2147483648U) |
              (double_pendulum_2_DW.state_m[kk + 228] & 2147483647U);
            if ((mti & 1U) == 0U) {
              mti >>= 1U;
            } else {
              mti = mti >> 1U ^ 2567483615U;
            }

            double_pendulum_2_DW.state_m[kk + 227] =
              double_pendulum_2_DW.state_m[kk] ^ mti;
          }

          mti = (double_pendulum_2_DW.state_m[623] & 2147483648U) |
            (double_pendulum_2_DW.state_m[0] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          double_pendulum_2_DW.state_m[623] = double_pendulum_2_DW.state_m[396] ^
            mti;
          mti = 1U;
        }

        y = double_pendulum_2_DW.state_m[(int32_T)mti - 1];
        double_pendulum_2_DW.state_m[624] = mti;
        y ^= y >> 11U;
        y ^= y << 7U & 2636928640U;
        y ^= y << 15U & 4022730752U;
        u[k] = y >> 18U ^ y;
      }

      r = ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)(u[1] >> 6U)) *
        1.1102230246251565E-16;
      if (r == 0.0) {
        boolean_T b_isvalid;
        if ((double_pendulum_2_DW.state_m[624] >= 1U) &&
            (double_pendulum_2_DW.state_m[624] < 625U)) {
          boolean_T exitg2;
          b_isvalid = false;
          k = 1;
          exitg2 = false;
          while ((!exitg2) && (k < 625)) {
            if (double_pendulum_2_DW.state_m[k - 1] == 0U) {
              k++;
            } else {
              b_isvalid = true;
              exitg2 = true;
            }
          }
        } else {
          b_isvalid = false;
        }

        if (!b_isvalid) {
          mti = 5489U;
          double_pendulum_2_DW.state_m[0] = 5489U;
          for (k = 0; k < 623; k++) {
            mti = ((mti >> 30U ^ mti) * 1812433253U + k) + 1U;
            double_pendulum_2_DW.state_m[k + 1] = mti;
          }

          double_pendulum_2_DW.state_m[624] = 624U;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return r;
}

/* Model step function */
void double_pendulum_2_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_TSamp_n;
  real_T rtb_TSamp_k;
  real_T rtb_TSamp_d;
  real_T rtb_TSamp_i;
  real_T rtb_TSamp_m;
  if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
    /* set solver stop time */
    if (!(double_pendulum_2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&double_pendulum_2_M->solverInfo,
                            ((double_pendulum_2_M->Timing.clockTickH0 + 1) *
        double_pendulum_2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&double_pendulum_2_M->solverInfo,
                            ((double_pendulum_2_M->Timing.clockTick0 + 1) *
        double_pendulum_2_M->Timing.stepSize0 +
        double_pendulum_2_M->Timing.clockTickH0 *
        double_pendulum_2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(double_pendulum_2_M)) {
    double_pendulum_2_M->Timing.t[0] = rtsiGetT(&double_pendulum_2_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    NeuDiagnosticTree *diagnosticTree_2;
    NeuDiagnosticTree *diagnosticTree_3;
    NeuDiagnosticTree *diagnosticTree_4;
    real_T tmp_4[16];
    real_T Y[14];
    real_T b[14];
    real_T tmp_1[12];
    real_T tmp_8[9];
    real_T tmp_c[9];
    real_T tmp_6[8];
    real_T tmp_a[8];
    real_T rtb_theta2[7];
    real_T Y_0[2];
    real_T rtb_qd[2];
    real_T rtb_s[2];
    real_T tmp_e[2];
    real_T DigitalClock;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    real_T time_5;
    real_T time_6;
    real_T time_7;
    real_T time_8;
    real_T time_9;
    real_T time_a;
    real_T x1;
    int32_T i;
    int32_T i_0;
    int_T tmp_5[5];
    int_T tmp_2[4];
    int_T tmp_9[4];
    int_T tmp_d[4];
    int_T tmp_7[3];
    int_T tmp_b[3];
    boolean_T tmp;
    boolean_T tmp_0;
    boolean_T tmp_3;
    static const int8_T b_0[7] = { 1, 1, 1, 1, 1, 3, 3 };

    if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
      real_T a;
      real_T rtb_UnitDelay1_idx_0;
      real_T rtb_UnitDelay1_idx_1;
      real_T rtb_UnitDelay_idx_0;
      real_T rtb_UnitDelay_idx_1;
      real_T z_idx_1;

      /* UnitDelay: '<Root>/Unit Delay' */
      rtb_UnitDelay_idx_0 = double_pendulum_2_DW.UnitDelay_DSTATE[0];

      /* UnitDelay: '<Root>/Unit Delay1' */
      rtb_UnitDelay1_idx_0 = double_pendulum_2_DW.UnitDelay1_DSTATE[0];

      /* UnitDelay: '<Root>/Unit Delay' */
      rtb_UnitDelay_idx_1 = double_pendulum_2_DW.UnitDelay_DSTATE[1];

      /* UnitDelay: '<Root>/Unit Delay1' */
      rtb_UnitDelay1_idx_1 = double_pendulum_2_DW.UnitDelay1_DSTATE[1];

      /* DigitalClock: '<Root>/Digital Clock' */
      DigitalClock = (((double_pendulum_2_M->Timing.clockTick1+
                        double_pendulum_2_M->Timing.clockTickH1* 4294967296.0)) *
                      0.001);

      /* MATLAB Function: '<S3>/MATLAB Function1' */
      if (!double_pendulum_2_DW.ti1_not_empty) {
        double_pendulum_2_DW.ti1_not_empty = true;
        double_pendulum_2_DW.yf1 = 0.52359877559829882 * double_pendulum_2_rand()
          + 0.52359877559829882;
        x1 = double_pendulum_2_DW.tf1 - double_pendulum_2_DW.ti1;
        double_pendulum_2_DW.T1 = x1;
        double_pendulum_2_DW.yf2 = 0.52359877559829882 * double_pendulum_2_rand()
          + 0.52359877559829882;
        double_pendulum_2_DW.T2 = x1;
      }

      x1 = DigitalClock - double_pendulum_2_DW.count1;
      DigitalClock -= double_pendulum_2_DW.count2;
      if (double_pendulum_2_DW.flag1 == 0.0) {
        a = (double_pendulum_2_DW.yf1 - double_pendulum_2_DW.yi1) / 2.0;
        double_pendulum_2_B.y1 = (sin(6.2831853071795862 / (2.0 *
          double_pendulum_2_DW.T1) * (x1 - double_pendulum_2_DW.T1 / 2.0)) * a +
          a) + double_pendulum_2_DW.yi1;
      } else {
        a = -(double_pendulum_2_DW.yf1 - double_pendulum_2_DW.yi1) / 2.0;
        double_pendulum_2_B.y1 = (sin(6.2831853071795862 / (2.0 *
          double_pendulum_2_DW.T1) * (double_pendulum_2_DW.T1 / 2.0 + x1)) * a +
          double_pendulum_2_DW.yi1) - a;
      }

      if (double_pendulum_2_DW.flag2 == 0.0) {
        a = (double_pendulum_2_DW.yf2 - double_pendulum_2_DW.yi2) / 2.0;
        double_pendulum_2_B.y2 = (sin(6.2831853071795862 / (2.0 *
          double_pendulum_2_DW.T2) * (DigitalClock - double_pendulum_2_DW.T2 /
          2.0)) * a + a) + double_pendulum_2_DW.yi2;
      } else {
        a = -(double_pendulum_2_DW.yf2 - double_pendulum_2_DW.yi2) / 2.0;
        double_pendulum_2_B.y2 = (sin(6.2831853071795862 / (2.0 *
          double_pendulum_2_DW.T2) * (double_pendulum_2_DW.T2 / 2.0 +
          DigitalClock)) * a + double_pendulum_2_DW.yi2) - a;
      }

      if (x1 >= double_pendulum_2_DW.T1) {
        double_pendulum_2_DW.count1 += double_pendulum_2_DW.T1;
        if (double_pendulum_2_DW.flag1 == 0.0) {
          double_pendulum_2_DW.ti1 = double_pendulum_2_DW.tf1;
          double_pendulum_2_DW.yi1 = double_pendulum_2_DW.yf1;
          double_pendulum_2_DW.tf1 = double_pendulum_2_DW.count1 + 0.5;
          double_pendulum_2_DW.yf1 = -0.52359877559829882 *
            double_pendulum_2_rand() - 0.52359877559829882;
          double_pendulum_2_DW.T1 = double_pendulum_2_DW.tf1 -
            double_pendulum_2_DW.ti1;
          double_pendulum_2_DW.flag1 = 1.0;
        } else {
          double_pendulum_2_DW.ti1 = double_pendulum_2_DW.tf1;
          double_pendulum_2_DW.yi1 = double_pendulum_2_DW.yf1;
          double_pendulum_2_DW.tf1 = double_pendulum_2_DW.count1 + 0.5;
          double_pendulum_2_DW.yf1 = 0.52359877559829882 *
            double_pendulum_2_rand() + 0.52359877559829882;
          double_pendulum_2_DW.T1 = double_pendulum_2_DW.tf1 -
            double_pendulum_2_DW.ti1;
          double_pendulum_2_DW.flag1 = 0.0;
        }
      }

      if (DigitalClock >= double_pendulum_2_DW.T2) {
        double_pendulum_2_DW.count2 += double_pendulum_2_DW.T2;
        if (double_pendulum_2_DW.flag2 == 0.0) {
          x1 = double_pendulum_2_DW.tf2;
          double_pendulum_2_DW.yi2 = double_pendulum_2_DW.yf2;
          double_pendulum_2_DW.tf2 = (double_pendulum_2_rand() + 1.0) +
            double_pendulum_2_DW.count2;
          double_pendulum_2_DW.yf2 = -0.52359877559829882 *
            double_pendulum_2_rand() - 0.52359877559829882;
          double_pendulum_2_DW.T2 = double_pendulum_2_DW.tf2 - x1;
          double_pendulum_2_DW.flag2 = 1.0;
        } else {
          x1 = double_pendulum_2_DW.tf2;
          double_pendulum_2_DW.yi2 = double_pendulum_2_DW.yf2;
          double_pendulum_2_DW.tf2 = (double_pendulum_2_rand() + 1.0) +
            double_pendulum_2_DW.count2;
          double_pendulum_2_DW.yf2 = 0.52359877559829882 *
            double_pendulum_2_rand() + 0.52359877559829882;
          double_pendulum_2_DW.T2 = double_pendulum_2_DW.tf2 - x1;
          double_pendulum_2_DW.flag2 = 0.0;
        }
      }

      /* End of MATLAB Function: '<S3>/MATLAB Function1' */

      /* SampleTimeMath: '<S20>/TSamp'
       *
       * About '<S20>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp = double_pendulum_2_B.y1 * double_pendulum_2_P.TSamp_WtEt;

      /* SampleTimeMath: '<S21>/TSamp'
       *
       * About '<S21>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_n = double_pendulum_2_B.y1 * double_pendulum_2_P.TSamp_WtEt_n;

      /* SampleTimeMath: '<S22>/TSamp' incorporates:
       *  Sum: '<S21>/Diff'
       *  UnitDelay: '<S21>/UD'
       *
       * About '<S22>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_k = (rtb_TSamp_n - double_pendulum_2_DW.UD_DSTATE_g) *
        double_pendulum_2_P.TSamp_WtEt_a;

      /* SampleTimeMath: '<S23>/TSamp'
       *
       * About '<S23>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_d = double_pendulum_2_B.y2 * double_pendulum_2_P.TSamp_WtEt_f;

      /* SampleTimeMath: '<S24>/TSamp'
       *
       * About '<S24>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_i = double_pendulum_2_B.y2 * double_pendulum_2_P.TSamp_WtEt_e;

      /* SampleTimeMath: '<S25>/TSamp' incorporates:
       *  Sum: '<S24>/Diff'
       *  UnitDelay: '<S24>/UD'
       *
       * About '<S25>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_m = (rtb_TSamp_i - double_pendulum_2_DW.UD_DSTATE_m) *
        double_pendulum_2_P.TSamp_WtEt_h;

      /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
       *  Sum: '<S20>/Diff'
       *  Sum: '<S22>/Diff'
       *  Sum: '<S23>/Diff'
       *  Sum: '<S25>/Diff'
       *  UnitDelay: '<S20>/UD'
       *  UnitDelay: '<S22>/UD'
       *  UnitDelay: '<S23>/UD'
       *  UnitDelay: '<S25>/UD'
       */
      if (!double_pendulum_2_DW.theta_not_empty) {
        for (i = 0; i < 7; i++) {
          double_pendulum_2_DW.theta[i] = 0.0;
        }

        double_pendulum_2_DW.theta_not_empty = true;
      }

      rtb_qd[0] = double_pendulum_2_B.y1 - 1.5707963267948966;
      rtb_qd[1] = double_pendulum_2_B.y2;
      x1 = rtb_UnitDelay1_idx_0 - (rtb_TSamp - double_pendulum_2_DW.UD_DSTATE);
      DigitalClock = rtb_UnitDelay1_idx_1 - (rtb_TSamp_d -
        double_pendulum_2_DW.UD_DSTATE_h);
      rtb_s[0] = (rtb_UnitDelay_idx_0 - rtb_qd[0]) + x1;
      rtb_s[1] = (rtb_UnitDelay_idx_1 - rtb_qd[1]) + DigitalClock;
      a = (rtb_TSamp_k - double_pendulum_2_DW.UD_DSTATE_d) - x1;
      z_idx_1 = (rtb_TSamp_m - double_pendulum_2_DW.UD_DSTATE_o) - DigitalClock;
      x1 = cos(rtb_UnitDelay_idx_1);
      DigitalClock = sin(rtb_UnitDelay_idx_1);
      Y[0] = a;
      Y[2] = z_idx_1;
      Y[4] = (2.0 * a + z_idx_1) * x1 - (2.0 * rtb_UnitDelay1_idx_0 *
        rtb_UnitDelay1_idx_1 + rtb_UnitDelay1_idx_1 * rtb_UnitDelay1_idx_1) *
        DigitalClock;
      Y[6] = 9.80665 * cos(rtb_UnitDelay_idx_0);
      rtb_UnitDelay_idx_0 = cos(rtb_UnitDelay_idx_0 + rtb_UnitDelay_idx_1) *
        9.80665;
      Y[8] = rtb_UnitDelay_idx_0;
      Y[10] = tanh(20.0 * rtb_UnitDelay1_idx_0);
      Y[12] = rtb_UnitDelay1_idx_0;
      Y[1] = 0.0;
      Y[3] = a + z_idx_1;
      Y[5] = rtb_UnitDelay1_idx_0 * rtb_UnitDelay1_idx_0 * DigitalClock + a * x1;
      Y[7] = 0.0;
      Y[9] = rtb_UnitDelay_idx_0;
      Y[11] = tanh(20.0 * rtb_UnitDelay1_idx_1);
      Y[13] = rtb_UnitDelay1_idx_1;
      for (i = 0; i < 7; i++) {
        rtb_theta2[i] = double_pendulum_2_DW.theta[i];
      }

      for (i = 0; i < 2; i++) {
        for (i_0 = 0; i_0 < 7; i_0++) {
          b[i_0 + 7 * i] = Y[(i_0 << 1) + i] * (real_T)b_0[i_0];
        }
      }

      for (i = 0; i <= 4; i += 2) {
        __m128d tmp_f;
        __m128d tmp_g;
        __m128d tmp_h;

        /* MATLAB Function: '<Root>/MATLAB Function' */
        tmp_f = _mm_loadu_pd(&b[i]);
        tmp_g = _mm_loadu_pd(&b[i + 7]);
        tmp_h = _mm_loadu_pd(&double_pendulum_2_DW.theta[i]);
        _mm_storeu_pd(&double_pendulum_2_DW.theta[i], _mm_sub_pd(tmp_h,
          _mm_mul_pd(_mm_add_pd(_mm_mul_pd(tmp_g, _mm_set1_pd(rtb_s[1])),
          _mm_add_pd(_mm_mul_pd(tmp_f, _mm_set1_pd(rtb_s[0])), _mm_set1_pd(0.0))),
                     _mm_set1_pd(0.001))));
      }

      /* MATLAB Function: '<Root>/MATLAB Function' */
      for (i = 6; i < 7; i++) {
        double_pendulum_2_DW.theta[i] -= (b[i + 7] * rtb_s[1] + b[i] * rtb_s[0])
          * 0.001;
      }

      if (fabs(rtb_s[0]) > 0.5) {
        if (rtIsNaN(rtb_s[0])) {
          x1 = rtb_s[0];
        } else if (rtb_s[0] < 0.0) {
          x1 = -1.0;
        } else {
          x1 = (rtb_s[0] > 0.0);
        }
      } else {
        x1 = rtb_s[0] / 0.5;
      }

      if (fabs(rtb_s[1]) > 0.5) {
        if (rtIsNaN(rtb_s[1])) {
          DigitalClock = rtb_s[1];
        } else if (rtb_s[1] < 0.0) {
          DigitalClock = -1.0;
        } else {
          DigitalClock = (rtb_s[1] > 0.0);
        }
      } else {
        DigitalClock = rtb_s[1] / 0.5;
      }

      tmp_e[0] = 6.0 * x1;
      tmp_e[1] = 6.0 * DigitalClock;
      for (i = 0; i < 2; i++) {
        Y_0[i] = 0.0;
        for (i_0 = 0; i_0 < 7; i_0++) {
          Y_0[i] += Y[(i_0 << 1) + i] * double_pendulum_2_DW.theta[i_0];
        }

        double_pendulum_2_B.u[i] = Y_0[i] - tmp_e[i];
      }
    }

    /* SimscapeExecutionBlock: '<S19>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S19>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S19>/OUTPUT_2_0'
     *  SimscapeExecutionBlock: '<S19>/OUTPUT_3_0'
     *  SimscapeExecutionBlock: '<S19>/STATE_2'
     *  SimscapeExecutionBlock: '<S19>/STATE_3'
     *  Sin: '<Root>/Sine Wave'
     */
    simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_1_SimData;
    x1 = double_pendulum_2_M->Timing.t[0];
    time = x1;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 4;
    simulationData->mData->mContStates.mX =
      &double_pendulum_2_X.double_pendulum_2SubsystemRevol[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp = rtmIsMajorTimeStep(double_pendulum_2_M);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_0 = rtsiIsModeUpdateTimeStep(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_2[0] = 0;
    tmp_1[0] = double_pendulum_2_B.INTERNAL_2_1_1[0];
    tmp_1[1] = double_pendulum_2_B.INTERNAL_2_1_1[1];
    tmp_1[2] = double_pendulum_2_B.INTERNAL_2_1_1[2];
    tmp_1[3] = double_pendulum_2_B.INTERNAL_2_1_1[3];
    tmp_2[1] = 4;
    tmp_1[4] = double_pendulum_2_B.INTERNAL_1_1_1[0];
    tmp_1[5] = double_pendulum_2_B.INTERNAL_1_1_1[1];
    tmp_1[6] = double_pendulum_2_B.INTERNAL_1_1_1[2];
    tmp_1[7] = double_pendulum_2_B.INTERNAL_1_1_1[3];
    tmp_2[2] = 8;
    tmp_1[8] = double_pendulum_2_B.INPUT_3_1_1[0];
    tmp_1[9] = double_pendulum_2_B.INPUT_3_1_1[1];
    tmp_1[10] = double_pendulum_2_B.INPUT_3_1_1[2];
    tmp_1[11] = double_pendulum_2_B.INPUT_3_1_1[3];
    tmp_2[3] = 12;
    simulationData->mData->mInputValues.mN = 12;
    simulationData->mData->mInputValues.mX = &tmp_1[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_2[0];
    simulationData->mData->mOutputs.mN = 4;
    simulationData->mData->mOutputs.mX = &double_pendulum_2_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    DigitalClock = double_pendulum_2_M->Timing.t[0];
    time_0 = DigitalClock;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (i != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_3) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(double_pendulum_2_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S19>/STATE_1' */

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)
      double_pendulum_2_DW.OUTPUT_1_0_SimData;
    time_1 = x1;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &double_pendulum_2_DW.OUTPUT_1_0_Modes;
    tmp_3 = false;
    simulationData->mData->mFoundZcEvents = tmp_3;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_3 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_3;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_5[0] = 0;
    tmp_4[0] = double_pendulum_2_B.INTERNAL_2_1_1[0];
    tmp_4[1] = double_pendulum_2_B.INTERNAL_2_1_1[1];
    tmp_4[2] = double_pendulum_2_B.INTERNAL_2_1_1[2];
    tmp_4[3] = double_pendulum_2_B.INTERNAL_2_1_1[3];
    tmp_5[1] = 4;
    tmp_4[4] = double_pendulum_2_B.INTERNAL_1_1_1[0];
    tmp_4[5] = double_pendulum_2_B.INTERNAL_1_1_1[1];
    tmp_4[6] = double_pendulum_2_B.INTERNAL_1_1_1[2];
    tmp_4[7] = double_pendulum_2_B.INTERNAL_1_1_1[3];
    tmp_5[2] = 8;
    tmp_4[8] = double_pendulum_2_B.INPUT_3_1_1[0];
    tmp_4[9] = double_pendulum_2_B.INPUT_3_1_1[1];
    tmp_4[10] = double_pendulum_2_B.INPUT_3_1_1[2];
    tmp_4[11] = double_pendulum_2_B.INPUT_3_1_1[3];
    tmp_5[3] = 12;
    tmp_4[12] = double_pendulum_2_B.STATE_1[0];
    tmp_4[13] = double_pendulum_2_B.STATE_1[1];
    tmp_4[14] = double_pendulum_2_B.STATE_1[2];
    tmp_4[15] = double_pendulum_2_B.STATE_1[3];
    tmp_5[4] = 16;
    simulationData->mData->mInputValues.mN = 16;
    simulationData->mData->mInputValues.mX = &tmp_4[0];
    simulationData->mData->mInputOffsets.mN = 5;
    simulationData->mData->mInputOffsets.mX = &tmp_5[0];
    simulationData->mData->mOutputs.mN = 4;
    simulationData->mData->mOutputs.mX = &double_pendulum_2_B.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_2 = DigitalClock;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (i != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_3) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(double_pendulum_2_M, msg_0);
      }
    }

    if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
    }

    /* Sin: '<Root>/Sine Wave' */
    double_pendulum_2_B.SineWave = sin(double_pendulum_2_P.SineWave_Freq *
      DigitalClock + double_pendulum_2_P.SineWave_Phase) *
      double_pendulum_2_P.SineWave_Amp + double_pendulum_2_P.SineWave_Bias;

    /* SimscapeInputBlock: '<S19>/INPUT_1_1_1' */
    double_pendulum_2_B.INPUT_1_1_1[0] = double_pendulum_2_B.u[0];
    double_pendulum_2_B.INPUT_1_1_1[1] = 0.0;
    double_pendulum_2_B.INPUT_1_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
      double_pendulum_2_DW.INPUT_1_1_1_Discrete[0] =
        !(double_pendulum_2_B.INPUT_1_1_1[0] ==
          double_pendulum_2_DW.INPUT_1_1_1_Discrete[1]);
      double_pendulum_2_DW.INPUT_1_1_1_Discrete[1] =
        double_pendulum_2_B.INPUT_1_1_1[0];
    }

    double_pendulum_2_B.INPUT_1_1_1[0] =
      double_pendulum_2_DW.INPUT_1_1_1_Discrete[1];
    double_pendulum_2_B.INPUT_1_1_1[3] =
      double_pendulum_2_DW.INPUT_1_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S19>/INPUT_1_1_1' */

    /* SimscapeInputBlock: '<S19>/INTERNAL_3_1_1' */
    double_pendulum_2_B.INTERNAL_3_1_1[0] = double_pendulum_2_B.OUTPUT_1_0[1];
    double_pendulum_2_B.INTERNAL_3_1_1[1] = 0.0;
    double_pendulum_2_B.INTERNAL_3_1_1[2] = 0.0;
    double_pendulum_2_B.INTERNAL_3_1_1[3] = 0.0;

    /* SimscapeExecutionBlock: '<S19>/STATE_2' */
    simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_2_SimData;
    time_3 = x1;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 1;
    simulationData->mData->mContStates.mX =
      &double_pendulum_2_X.double_pendulum_2SubsystemPS_Ad;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.STATE_2_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_2_Modes;
    tmp_3 = false;
    simulationData->mData->mFoundZcEvents = tmp_3;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_3 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_3;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_3 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_3;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_7[0] = 0;
    tmp_6[0] = double_pendulum_2_B.INPUT_1_1_1[0];
    tmp_6[1] = double_pendulum_2_B.INPUT_1_1_1[1];
    tmp_6[2] = double_pendulum_2_B.INPUT_1_1_1[2];
    tmp_6[3] = double_pendulum_2_B.INPUT_1_1_1[3];
    tmp_7[1] = 4;
    tmp_6[4] = double_pendulum_2_B.INTERNAL_3_1_1[0];
    tmp_6[5] = double_pendulum_2_B.INTERNAL_3_1_1[1];
    tmp_6[6] = double_pendulum_2_B.INTERNAL_3_1_1[2];
    tmp_6[7] = double_pendulum_2_B.INTERNAL_3_1_1[3];
    tmp_7[2] = 8;
    simulationData->mData->mInputValues.mN = 8;
    simulationData->mData->mInputValues.mX = &tmp_6[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_7[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S19>/STATE_2' */
    simulationData->mData->mOutputs.mX = &double_pendulum_2_B.STATE_2;

    /* SimscapeExecutionBlock: '<S19>/STATE_2' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_4 = DigitalClock;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_2_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.STATE_2_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (i != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_3) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(double_pendulum_2_M, msg_1);
      }
    }

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_2_0' */
    simulationData = (NeslSimulationData *)
      double_pendulum_2_DW.OUTPUT_2_0_SimData;
    time_5 = x1;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_5;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.OUTPUT_2_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &double_pendulum_2_DW.OUTPUT_2_0_Modes;
    tmp_3 = false;
    simulationData->mData->mFoundZcEvents = tmp_3;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_3 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_3;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_9[0] = 0;
    tmp_8[0] = double_pendulum_2_B.INPUT_1_1_1[0];
    tmp_8[1] = double_pendulum_2_B.INPUT_1_1_1[1];
    tmp_8[2] = double_pendulum_2_B.INPUT_1_1_1[2];
    tmp_8[3] = double_pendulum_2_B.INPUT_1_1_1[3];
    tmp_9[1] = 4;
    tmp_8[4] = double_pendulum_2_B.INTERNAL_3_1_1[0];
    tmp_8[5] = double_pendulum_2_B.INTERNAL_3_1_1[1];
    tmp_8[6] = double_pendulum_2_B.INTERNAL_3_1_1[2];
    tmp_8[7] = double_pendulum_2_B.INTERNAL_3_1_1[3];
    tmp_9[2] = 8;
    tmp_8[8] = double_pendulum_2_B.STATE_2;
    tmp_9[3] = 9;
    simulationData->mData->mInputValues.mN = 9;
    simulationData->mData->mInputValues.mX = &tmp_8[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_9[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_2_0' */
    simulationData->mData->mOutputs.mX = &double_pendulum_2_B.OUTPUT_2_0;

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_2_0' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_6 = DigitalClock;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_6;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.OUTPUT_2_0_DiagMgr;
    diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.OUTPUT_2_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (i != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_3) {
        char *msg_2;
        msg_2 = rtw_diagnostics_msg(diagnosticTree_2);
        rtmSetErrorStatus(double_pendulum_2_M, msg_2);
      }
    }

    /* SimscapeInputBlock: '<S19>/INTERNAL_2_1_1' */
    double_pendulum_2_B.INTERNAL_2_1_1[0] = double_pendulum_2_B.OUTPUT_2_0;
    double_pendulum_2_B.INTERNAL_2_1_1[1] = 0.0;
    double_pendulum_2_B.INTERNAL_2_1_1[2] = 0.0;
    double_pendulum_2_B.INTERNAL_2_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S19>/INPUT_2_1_1' */
    double_pendulum_2_B.INPUT_2_1_1[0] = double_pendulum_2_B.u[1];
    double_pendulum_2_B.INPUT_2_1_1[1] = 0.0;
    double_pendulum_2_B.INPUT_2_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
      double_pendulum_2_DW.INPUT_2_1_1_Discrete[0] =
        !(double_pendulum_2_B.INPUT_2_1_1[0] ==
          double_pendulum_2_DW.INPUT_2_1_1_Discrete[1]);
      double_pendulum_2_DW.INPUT_2_1_1_Discrete[1] =
        double_pendulum_2_B.INPUT_2_1_1[0];
    }

    double_pendulum_2_B.INPUT_2_1_1[0] =
      double_pendulum_2_DW.INPUT_2_1_1_Discrete[1];
    double_pendulum_2_B.INPUT_2_1_1[3] =
      double_pendulum_2_DW.INPUT_2_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S19>/INPUT_2_1_1' */

    /* SimscapeInputBlock: '<S19>/INTERNAL_4_1_1' */
    double_pendulum_2_B.INTERNAL_4_1_1[0] = double_pendulum_2_B.OUTPUT_1_0[3];
    double_pendulum_2_B.INTERNAL_4_1_1[1] = 0.0;
    double_pendulum_2_B.INTERNAL_4_1_1[2] = 0.0;
    double_pendulum_2_B.INTERNAL_4_1_1[3] = 0.0;

    /* SimscapeExecutionBlock: '<S19>/STATE_3' */
    simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_3_SimData;
    time_7 = x1;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_7;
    simulationData->mData->mContStates.mN = 1;
    simulationData->mData->mContStates.mX =
      &double_pendulum_2_X.double_pendulum_2SubsystemPS__b;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.STATE_3_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_3_Modes;
    tmp_3 = false;
    simulationData->mData->mFoundZcEvents = tmp_3;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_3 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_3;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_3 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_3;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_b[0] = 0;
    tmp_a[0] = double_pendulum_2_B.INPUT_2_1_1[0];
    tmp_a[1] = double_pendulum_2_B.INPUT_2_1_1[1];
    tmp_a[2] = double_pendulum_2_B.INPUT_2_1_1[2];
    tmp_a[3] = double_pendulum_2_B.INPUT_2_1_1[3];
    tmp_b[1] = 4;
    tmp_a[4] = double_pendulum_2_B.INTERNAL_4_1_1[0];
    tmp_a[5] = double_pendulum_2_B.INTERNAL_4_1_1[1];
    tmp_a[6] = double_pendulum_2_B.INTERNAL_4_1_1[2];
    tmp_a[7] = double_pendulum_2_B.INTERNAL_4_1_1[3];
    tmp_b[2] = 8;
    simulationData->mData->mInputValues.mN = 8;
    simulationData->mData->mInputValues.mX = &tmp_a[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_b[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S19>/STATE_3' */
    simulationData->mData->mOutputs.mX = &double_pendulum_2_B.STATE_3;

    /* SimscapeExecutionBlock: '<S19>/STATE_3' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_8 = DigitalClock;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_8;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_3_DiagMgr;
    diagnosticTree_3 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.STATE_3_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (i != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_3) {
        char *msg_3;
        msg_3 = rtw_diagnostics_msg(diagnosticTree_3);
        rtmSetErrorStatus(double_pendulum_2_M, msg_3);
      }
    }

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_3_0' */
    simulationData = (NeslSimulationData *)
      double_pendulum_2_DW.OUTPUT_3_0_SimData;
    time_9 = x1;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_9;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.OUTPUT_3_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &double_pendulum_2_DW.OUTPUT_3_0_Modes;
    tmp_3 = false;
    simulationData->mData->mFoundZcEvents = tmp_3;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_d[0] = 0;
    tmp_c[0] = double_pendulum_2_B.INPUT_2_1_1[0];
    tmp_c[1] = double_pendulum_2_B.INPUT_2_1_1[1];
    tmp_c[2] = double_pendulum_2_B.INPUT_2_1_1[2];
    tmp_c[3] = double_pendulum_2_B.INPUT_2_1_1[3];
    tmp_d[1] = 4;
    tmp_c[4] = double_pendulum_2_B.INTERNAL_4_1_1[0];
    tmp_c[5] = double_pendulum_2_B.INTERNAL_4_1_1[1];
    tmp_c[6] = double_pendulum_2_B.INTERNAL_4_1_1[2];
    tmp_c[7] = double_pendulum_2_B.INTERNAL_4_1_1[3];
    tmp_d[2] = 8;
    tmp_c[8] = double_pendulum_2_B.STATE_3;
    tmp_d[3] = 9;
    simulationData->mData->mInputValues.mN = 9;
    simulationData->mData->mInputValues.mX = &tmp_c[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_d[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_3_0' */
    simulationData->mData->mOutputs.mX = &double_pendulum_2_B.OUTPUT_3_0;

    /* SimscapeExecutionBlock: '<S19>/OUTPUT_3_0' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_a = DigitalClock;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_a;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.OUTPUT_3_0_DiagMgr;
    diagnosticTree_4 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.OUTPUT_3_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (i != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp) {
        char *msg_4;
        msg_4 = rtw_diagnostics_msg(diagnosticTree_4);
        rtmSetErrorStatus(double_pendulum_2_M, msg_4);
      }
    }

    /* SimscapeInputBlock: '<S19>/INTERNAL_1_1_1' */
    double_pendulum_2_B.INTERNAL_1_1_1[0] = double_pendulum_2_B.OUTPUT_3_0;
    double_pendulum_2_B.INTERNAL_1_1_1[1] = 0.0;
    double_pendulum_2_B.INTERNAL_1_1_1[2] = 0.0;
    double_pendulum_2_B.INTERNAL_1_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S19>/INPUT_3_1_1' */
    double_pendulum_2_B.INPUT_3_1_1[0] = double_pendulum_2_B.SineWave;
    double_pendulum_2_B.INPUT_3_1_1[1] = 0.0;
    double_pendulum_2_B.INPUT_3_1_1[2] = 0.0;
    double_pendulum_2_B.INPUT_3_1_1[3] = 0.0;
  }

  if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(double_pendulum_2_M->rtwLogInfo,
                        (double_pendulum_2_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    real_T tmp_1[12];
    real_T tmp_5[8];
    real_T tmp_7[8];
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_tmp;
    int32_T tmp_3;
    int_T tmp_2[4];
    int_T tmp_6[3];
    int_T tmp_8[3];
    boolean_T tmp;
    boolean_T tmp_0;
    boolean_T tmp_4;
    if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
      /* Update for UnitDelay: '<Root>/Unit Delay' */
      double_pendulum_2_DW.UnitDelay_DSTATE[0] = double_pendulum_2_B.OUTPUT_1_0
        [0];
      double_pendulum_2_DW.UnitDelay_DSTATE[1] = double_pendulum_2_B.OUTPUT_1_0
        [2];

      /* Update for UnitDelay: '<Root>/Unit Delay1' */
      double_pendulum_2_DW.UnitDelay1_DSTATE[0] =
        double_pendulum_2_B.OUTPUT_1_0[1];
      double_pendulum_2_DW.UnitDelay1_DSTATE[1] =
        double_pendulum_2_B.OUTPUT_1_0[3];

      /* Update for UnitDelay: '<S20>/UD' */
      double_pendulum_2_DW.UD_DSTATE = rtb_TSamp;

      /* Update for UnitDelay: '<S21>/UD' */
      double_pendulum_2_DW.UD_DSTATE_g = rtb_TSamp_n;

      /* Update for UnitDelay: '<S22>/UD' */
      double_pendulum_2_DW.UD_DSTATE_d = rtb_TSamp_k;

      /* Update for UnitDelay: '<S23>/UD' */
      double_pendulum_2_DW.UD_DSTATE_h = rtb_TSamp_d;

      /* Update for UnitDelay: '<S24>/UD' */
      double_pendulum_2_DW.UD_DSTATE_m = rtb_TSamp_i;

      /* Update for UnitDelay: '<S25>/UD' */
      double_pendulum_2_DW.UD_DSTATE_o = rtb_TSamp_m;
    }

    /* Update for SimscapeExecutionBlock: '<S19>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S19>/STATE_2'
     *  SimscapeExecutionBlock: '<S19>/STATE_3'
     */
    simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_1_SimData;
    time_tmp = double_pendulum_2_M->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 4;
    simulationData->mData->mContStates.mX =
      &double_pendulum_2_X.double_pendulum_2SubsystemRevol[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp = rtmIsMajorTimeStep(double_pendulum_2_M);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_0 = rtsiIsModeUpdateTimeStep(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_2[0] = 0;
    tmp_1[0] = double_pendulum_2_B.INTERNAL_2_1_1[0];
    tmp_1[1] = double_pendulum_2_B.INTERNAL_2_1_1[1];
    tmp_1[2] = double_pendulum_2_B.INTERNAL_2_1_1[2];
    tmp_1[3] = double_pendulum_2_B.INTERNAL_2_1_1[3];
    tmp_2[1] = 4;
    tmp_1[4] = double_pendulum_2_B.INTERNAL_1_1_1[0];
    tmp_1[5] = double_pendulum_2_B.INTERNAL_1_1_1[1];
    tmp_1[6] = double_pendulum_2_B.INTERNAL_1_1_1[2];
    tmp_1[7] = double_pendulum_2_B.INTERNAL_1_1_1[3];
    tmp_2[2] = 8;
    tmp_1[8] = double_pendulum_2_B.INPUT_3_1_1[0];
    tmp_1[9] = double_pendulum_2_B.INPUT_3_1_1[1];
    tmp_1[10] = double_pendulum_2_B.INPUT_3_1_1[2];
    tmp_1[11] = double_pendulum_2_B.INPUT_3_1_1[3];
    tmp_2[3] = 12;
    simulationData->mData->mInputValues.mN = 12;
    simulationData->mData->mInputValues.mX = &tmp_1[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_2[0];
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_4) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(double_pendulum_2_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S19>/STATE_1' */

    /* Update for SimscapeExecutionBlock: '<S19>/STATE_2' */
    simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_2_SimData;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 1;
    simulationData->mData->mContStates.mX =
      &double_pendulum_2_X.double_pendulum_2SubsystemPS_Ad;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.STATE_2_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_2_Modes;
    tmp_4 = false;
    simulationData->mData->mFoundZcEvents = tmp_4;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_4 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_4;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_4 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_4;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_6[0] = 0;
    tmp_5[0] = double_pendulum_2_B.INPUT_1_1_1[0];
    tmp_5[1] = double_pendulum_2_B.INPUT_1_1_1[1];
    tmp_5[2] = double_pendulum_2_B.INPUT_1_1_1[2];
    tmp_5[3] = double_pendulum_2_B.INPUT_1_1_1[3];
    tmp_6[1] = 4;
    tmp_5[4] = double_pendulum_2_B.INTERNAL_3_1_1[0];
    tmp_5[5] = double_pendulum_2_B.INTERNAL_3_1_1[1];
    tmp_5[6] = double_pendulum_2_B.INTERNAL_3_1_1[2];
    tmp_5[7] = double_pendulum_2_B.INTERNAL_3_1_1[3];
    tmp_6[2] = 8;
    simulationData->mData->mInputValues.mN = 8;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_2_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.STATE_2_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_4) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(double_pendulum_2_M, msg_0);
      }
    }

    /* Update for SimscapeExecutionBlock: '<S19>/STATE_3' */
    simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_3_SimData;
    time_1 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 1;
    simulationData->mData->mContStates.mX =
      &double_pendulum_2_X.double_pendulum_2SubsystemPS__b;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &double_pendulum_2_DW.STATE_3_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_3_Modes;
    tmp_4 = false;
    simulationData->mData->mFoundZcEvents = tmp_4;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_8[0] = 0;
    tmp_7[0] = double_pendulum_2_B.INPUT_2_1_1[0];
    tmp_7[1] = double_pendulum_2_B.INPUT_2_1_1[1];
    tmp_7[2] = double_pendulum_2_B.INPUT_2_1_1[2];
    tmp_7[3] = double_pendulum_2_B.INPUT_2_1_1[3];
    tmp_8[1] = 4;
    tmp_7[4] = double_pendulum_2_B.INTERNAL_4_1_1[0];
    tmp_7[5] = double_pendulum_2_B.INTERNAL_4_1_1[1];
    tmp_7[6] = double_pendulum_2_B.INTERNAL_4_1_1[2];
    tmp_7[7] = double_pendulum_2_B.INTERNAL_4_1_1[3];
    tmp_8[2] = 8;
    simulationData->mData->mInputValues.mN = 8;
    simulationData->mData->mInputValues.mX = &tmp_7[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_8[0];
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_3_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)
      double_pendulum_2_DW.STATE_3_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(double_pendulum_2_M, msg_1);
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(double_pendulum_2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(double_pendulum_2_M)!=-1) &&
          !((rtmGetTFinal(double_pendulum_2_M)-
             (((double_pendulum_2_M->Timing.clockTick1+
                double_pendulum_2_M->Timing.clockTickH1* 4294967296.0)) * 0.001))
            > (((double_pendulum_2_M->Timing.clockTick1+
                 double_pendulum_2_M->Timing.clockTickH1* 4294967296.0)) * 0.001)
            * (DBL_EPSILON))) {
        rtmSetErrorStatus(double_pendulum_2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&double_pendulum_2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++double_pendulum_2_M->Timing.clockTick0)) {
      ++double_pendulum_2_M->Timing.clockTickH0;
    }

    double_pendulum_2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&double_pendulum_2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      double_pendulum_2_M->Timing.clockTick1++;
      if (!double_pendulum_2_M->Timing.clockTick1) {
        double_pendulum_2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void double_pendulum_2_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  XDot_double_pendulum_2_T *_rtXdot;
  real_T tmp_1[12];
  real_T tmp_5[8];
  real_T tmp_7[8];
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_tmp;
  int32_T tmp_3;
  int_T tmp_2[4];
  int_T tmp_6[3];
  int_T tmp_8[3];
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_4;
  _rtXdot = ((XDot_double_pendulum_2_T *) double_pendulum_2_M->derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S19>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S19>/STATE_2'
   *  SimscapeExecutionBlock: '<S19>/STATE_3'
   */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_1_SimData;
  time_tmp = double_pendulum_2_M->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 4;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemRevol[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  tmp = rtmIsMajorTimeStep(double_pendulum_2_M);
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0 = rtsiIsModeUpdateTimeStep(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_2[0] = 0;
  tmp_1[0] = double_pendulum_2_B.INTERNAL_2_1_1[0];
  tmp_1[1] = double_pendulum_2_B.INTERNAL_2_1_1[1];
  tmp_1[2] = double_pendulum_2_B.INTERNAL_2_1_1[2];
  tmp_1[3] = double_pendulum_2_B.INTERNAL_2_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = double_pendulum_2_B.INTERNAL_1_1_1[0];
  tmp_1[5] = double_pendulum_2_B.INTERNAL_1_1_1[1];
  tmp_1[6] = double_pendulum_2_B.INTERNAL_1_1_1[2];
  tmp_1[7] = double_pendulum_2_B.INTERNAL_1_1_1[3];
  tmp_2[2] = 8;
  tmp_1[8] = double_pendulum_2_B.INPUT_3_1_1[0];
  tmp_1[9] = double_pendulum_2_B.INPUT_3_1_1[1];
  tmp_1[10] = double_pendulum_2_B.INPUT_3_1_1[2];
  tmp_1[11] = double_pendulum_2_B.INPUT_3_1_1[3];
  tmp_2[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  simulationData->mData->mDx.mN = 4;
  simulationData->mData->mDx.mX = &_rtXdot->double_pendulum_2SubsystemRevol[0];
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_3 != 0) {
    tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp_4) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(double_pendulum_2_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S19>/STATE_1' */

  /* Derivatives for SimscapeExecutionBlock: '<S19>/STATE_2' */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_2_SimData;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemPS_Ad;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_2_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_2_Modes;
  tmp_4 = false;
  simulationData->mData->mFoundZcEvents = tmp_4;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_4 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_4;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_4 = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_4;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_6[0] = 0;
  tmp_5[0] = double_pendulum_2_B.INPUT_1_1_1[0];
  tmp_5[1] = double_pendulum_2_B.INPUT_1_1_1[1];
  tmp_5[2] = double_pendulum_2_B.INPUT_1_1_1[2];
  tmp_5[3] = double_pendulum_2_B.INPUT_1_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = double_pendulum_2_B.INTERNAL_3_1_1[0];
  tmp_5[5] = double_pendulum_2_B.INTERNAL_3_1_1[1];
  tmp_5[6] = double_pendulum_2_B.INTERNAL_3_1_1[2];
  tmp_5[7] = double_pendulum_2_B.INTERNAL_3_1_1[3];
  tmp_6[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  simulationData->mData->mDx.mN = 1;
  simulationData->mData->mDx.mX = &_rtXdot->double_pendulum_2SubsystemPS_Ad;
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_2_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_2_Simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_3 != 0) {
    tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp_4) {
      char *msg_0;
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(double_pendulum_2_M, msg_0);
    }
  }

  /* Derivatives for SimscapeExecutionBlock: '<S19>/STATE_3' */
  simulationData = (NeslSimulationData *)double_pendulum_2_DW.STATE_3_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &double_pendulum_2_X.double_pendulum_2SubsystemPS__b;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &double_pendulum_2_DW.STATE_3_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &double_pendulum_2_DW.STATE_3_Modes;
  tmp_4 = false;
  simulationData->mData->mFoundZcEvents = tmp_4;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&double_pendulum_2_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
  tmp_8[0] = 0;
  tmp_7[0] = double_pendulum_2_B.INPUT_2_1_1[0];
  tmp_7[1] = double_pendulum_2_B.INPUT_2_1_1[1];
  tmp_7[2] = double_pendulum_2_B.INPUT_2_1_1[2];
  tmp_7[3] = double_pendulum_2_B.INPUT_2_1_1[3];
  tmp_8[1] = 4;
  tmp_7[4] = double_pendulum_2_B.INTERNAL_4_1_1[0];
  tmp_7[5] = double_pendulum_2_B.INTERNAL_4_1_1[1];
  tmp_7[6] = double_pendulum_2_B.INTERNAL_4_1_1[2];
  tmp_7[7] = double_pendulum_2_B.INTERNAL_4_1_1[3];
  tmp_8[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_7[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_8[0];
  simulationData->mData->mDx.mN = 1;
  simulationData->mData->mDx.mX = &_rtXdot->double_pendulum_2SubsystemPS__b;
  diagnosticManager = (NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_3_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)
    double_pendulum_2_DW.STATE_3_Simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
    if (tmp) {
      char *msg_1;
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(double_pendulum_2_M, msg_1);
    }
  }
}

/* Model initialize function */
void double_pendulum_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)double_pendulum_2_M, 0,
                sizeof(RT_MODEL_double_pendulum_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&double_pendulum_2_M->solverInfo,
                          &double_pendulum_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&double_pendulum_2_M->solverInfo, &rtmGetTPtr
                (double_pendulum_2_M));
    rtsiSetStepSizePtr(&double_pendulum_2_M->solverInfo,
                       &double_pendulum_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&double_pendulum_2_M->solverInfo, &double_pendulum_2_M->derivs);
    rtsiSetContStatesPtr(&double_pendulum_2_M->solverInfo, (real_T **)
                         &double_pendulum_2_M->contStates);
    rtsiSetNumContStatesPtr(&double_pendulum_2_M->solverInfo,
      &double_pendulum_2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&double_pendulum_2_M->solverInfo,
      &double_pendulum_2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&double_pendulum_2_M->solverInfo,
      &double_pendulum_2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&double_pendulum_2_M->solverInfo,
      &double_pendulum_2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&double_pendulum_2_M->solverInfo, (&rtmGetErrorStatus
      (double_pendulum_2_M)));
    rtsiSetSolverMassMatrixIr(&double_pendulum_2_M->solverInfo,
      double_pendulum_2_MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&double_pendulum_2_M->solverInfo,
      double_pendulum_2_MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&double_pendulum_2_M->solverInfo,
      double_pendulum_2_MassMatrix.pr);
    rtsiSetRTModelPtr(&double_pendulum_2_M->solverInfo, double_pendulum_2_M);
  }

  rtsiSetSimTimeStep(&double_pendulum_2_M->solverInfo, MAJOR_TIME_STEP);
  double_pendulum_2_M->intgData.x0 = double_pendulum_2_M->odeX0;
  double_pendulum_2_M->intgData.f0 = double_pendulum_2_M->odeF0;
  double_pendulum_2_M->intgData.x1start = double_pendulum_2_M->odeX1START;
  double_pendulum_2_M->intgData.f1 = double_pendulum_2_M->odeF1;
  double_pendulum_2_M->intgData.Delta = double_pendulum_2_M->odeDELTA;
  double_pendulum_2_M->intgData.E = double_pendulum_2_M->odeE;
  double_pendulum_2_M->intgData.fac = double_pendulum_2_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = double_pendulum_2_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(double_pendulum_2_M->odeFAC)/sizeof(real_T));
         i++) {
      f[i] = 1.5e-8;
    }
  }

  double_pendulum_2_M->intgData.DFDX = double_pendulum_2_M->odeDFDX;
  double_pendulum_2_M->intgData.W = double_pendulum_2_M->odeW;
  double_pendulum_2_M->intgData.pivots = double_pendulum_2_M->odePIVOTS;
  double_pendulum_2_M->intgData.xtmp = double_pendulum_2_M->odeXTMP;
  double_pendulum_2_M->intgData.ztmp = double_pendulum_2_M->odeZTMP;
  double_pendulum_2_M->intgData.M = double_pendulum_2_M->odeMASSMATRIX_M;
  double_pendulum_2_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&double_pendulum_2_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&double_pendulum_2_M->solverInfo, 1);
  double_pendulum_2_M->contStates = ((X_double_pendulum_2_T *)
    &double_pendulum_2_X);
  double_pendulum_2_M->massMatrixType = ((ssMatrixType)1);
  double_pendulum_2_M->massMatrixNzMax = (6);
  double_pendulum_2_M->massMatrixIr = (double_pendulum_2_MassMatrix.ir);
  double_pendulum_2_M->massMatrixJc = (double_pendulum_2_MassMatrix.jc);
  double_pendulum_2_M->massMatrixPr = (double_pendulum_2_MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&double_pendulum_2_M->solverInfo, (ssMatrixType)1);
  rtsiSetSolverMassMatrixNzMax(&double_pendulum_2_M->solverInfo, 6);
  rtsiSetSolverData(&double_pendulum_2_M->solverInfo, (void *)
                    &double_pendulum_2_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&double_pendulum_2_M->solverInfo, false);
  rtsiSetSolverName(&double_pendulum_2_M->solverInfo,"ode14x");
  rtmSetTPtr(double_pendulum_2_M, &double_pendulum_2_M->Timing.tArray[0]);
  rtmSetTFinal(double_pendulum_2_M, 100.0);
  double_pendulum_2_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    double_pendulum_2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(double_pendulum_2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(double_pendulum_2_M->rtwLogInfo, (NULL));
    rtliSetLogT(double_pendulum_2_M->rtwLogInfo, "tout");
    rtliSetLogX(double_pendulum_2_M->rtwLogInfo, "");
    rtliSetLogXFinal(double_pendulum_2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(double_pendulum_2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(double_pendulum_2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(double_pendulum_2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(double_pendulum_2_M->rtwLogInfo, 1);
    rtliSetLogY(double_pendulum_2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(double_pendulum_2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(double_pendulum_2_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &double_pendulum_2_B), 0,
                sizeof(B_double_pendulum_2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&double_pendulum_2_X, 0,
                  sizeof(X_double_pendulum_2_T));
  }

  /* global mass matrix */
  {
    int_T *ir = double_pendulum_2_MassMatrix.ir;
    int_T *jc = double_pendulum_2_MassMatrix.jc;
    real_T *pr = double_pendulum_2_MassMatrix.pr;
    (void) memset((void *)ir, 0,
                  6*sizeof(int_T));
    (void) memset((void *)jc, 0,
                  (6+1)*sizeof(int_T));
    (void) memset((void *)pr, 0,
                  6*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&double_pendulum_2_DW, 0,
                sizeof(DW_double_pendulum_2_T));

  /* Root-level init GlobalMassMatrixPr offset */
  {
    double_pendulum_2_DW.STATE_2_MASS_MATRIX_PR = 4;/* '<S19>/STATE_2' */
    double_pendulum_2_DW.STATE_3_MASS_MATRIX_PR = 5;/* '<S19>/STATE_3' */
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(double_pendulum_2_M->rtwLogInfo, 0.0,
    rtmGetTFinal(double_pendulum_2_M), double_pendulum_2_M->Timing.stepSize0,
    (&rtmGetErrorStatus(double_pendulum_2_M)));

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeModelParameters modelParameters_2;
    NeModelParameters modelParameters_3;
    NeModelParameters modelParameters_4;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    NeuDiagnosticTree *diagnosticTree_2;
    NeuDiagnosticTree *diagnosticTree_3;
    NeuDiagnosticTree *diagnosticTree_4;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for SimscapeExecutionBlock: '<S19>/STATE_1' */
    tmp = nesl_lease_simulator(
      "double_pendulum_2/Subsystem/Solver Configuration_1", 0, 0);
    double_pendulum_2_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(double_pendulum_2_DW.STATE_1_Simulator);
    if (tmp_0) {
      double_pendulum_2_836bb176_1_gateway();
      tmp = nesl_lease_simulator(
        "double_pendulum_2/Subsystem/Solver Configuration_1", 0, 0);
      double_pendulum_2_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    double_pendulum_2_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    double_pendulum_2_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 5.72189389E+8;
    modelParameters.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      double_pendulum_2_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_0) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(double_pendulum_2_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S19>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S19>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator(
      "double_pendulum_2/Subsystem/Solver Configuration_1", 1, 0);
    double_pendulum_2_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(double_pendulum_2_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      double_pendulum_2_836bb176_1_gateway();
      tmp = nesl_lease_simulator(
        "double_pendulum_2/Subsystem/Solver Configuration_1", 1, 0);
      double_pendulum_2_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    double_pendulum_2_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    double_pendulum_2_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 5.72189389E+8;
    modelParameters_0.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      double_pendulum_2_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_0) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(double_pendulum_2_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S19>/OUTPUT_1_0' */

    /* Start for SimscapeExecutionBlock: '<S19>/STATE_2' */
    tmp = nesl_lease_simulator(
      "double_pendulum_2/Subsystem/Solver Configuration_2", 0, 0);
    double_pendulum_2_DW.STATE_2_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(double_pendulum_2_DW.STATE_2_Simulator);
    if (tmp_0) {
      double_pendulum_2_836bb176_2_gateway();
      tmp = nesl_lease_simulator(
        "double_pendulum_2/Subsystem/Solver Configuration_2", 0, 0);
      double_pendulum_2_DW.STATE_2_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    double_pendulum_2_DW.STATE_2_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    double_pendulum_2_DW.STATE_2_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverTolerance = 0.001;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mIsUsingODEN = false;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mFixedStepSize = 0.001;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_1.mRTWModifiedTimeStamp = 5.72182455E+8;
    modelParameters_1.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_1.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_1.mIsUsingODEN = tmp_0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_2_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      double_pendulum_2_DW.STATE_2_Simulator, &modelParameters_1,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_0) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(double_pendulum_2_M, msg_1);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S19>/STATE_2' */

    /* Start for SimscapeExecutionBlock: '<S19>/OUTPUT_2_0' */
    tmp = nesl_lease_simulator(
      "double_pendulum_2/Subsystem/Solver Configuration_2", 1, 0);
    double_pendulum_2_DW.OUTPUT_2_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(double_pendulum_2_DW.OUTPUT_2_0_Simulator);
    if (tmp_0) {
      double_pendulum_2_836bb176_2_gateway();
      tmp = nesl_lease_simulator(
        "double_pendulum_2/Subsystem/Solver Configuration_2", 1, 0);
      double_pendulum_2_DW.OUTPUT_2_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    double_pendulum_2_DW.OUTPUT_2_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    double_pendulum_2_DW.OUTPUT_2_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_2.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_2.mSolverTolerance = 0.001;
    modelParameters_2.mSolverAbsTol = 0.001;
    modelParameters_2.mSolverRelTol = 0.001;
    modelParameters_2.mVariableStepSolver = false;
    modelParameters_2.mIsUsingODEN = false;
    modelParameters_2.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_2.mFixedStepSize = 0.001;
    modelParameters_2.mStartTime = 0.0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mUseSimState = false;
    modelParameters_2.mLinTrimCompile = false;
    modelParameters_2.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_2.mRTWModifiedTimeStamp = 5.72182455E+8;
    modelParameters_2.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_2.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters_2.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_2.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_2.mIsUsingODEN = tmp_0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.OUTPUT_2_0_DiagMgr;
    diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      double_pendulum_2_DW.OUTPUT_2_0_Simulator, &modelParameters_2,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_0) {
        char *msg_2;
        msg_2 = rtw_diagnostics_msg(diagnosticTree_2);
        rtmSetErrorStatus(double_pendulum_2_M, msg_2);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S19>/OUTPUT_2_0' */

    /* Start for SimscapeExecutionBlock: '<S19>/STATE_3' */
    tmp = nesl_lease_simulator(
      "double_pendulum_2/Subsystem/Solver Configuration_3", 0, 0);
    double_pendulum_2_DW.STATE_3_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(double_pendulum_2_DW.STATE_3_Simulator);
    if (tmp_0) {
      double_pendulum_2_836bb176_3_gateway();
      tmp = nesl_lease_simulator(
        "double_pendulum_2/Subsystem/Solver Configuration_3", 0, 0);
      double_pendulum_2_DW.STATE_3_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    double_pendulum_2_DW.STATE_3_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    double_pendulum_2_DW.STATE_3_DiagMgr = (void *)diagnosticManager;
    modelParameters_3.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_3.mSolverTolerance = 0.001;
    modelParameters_3.mSolverAbsTol = 0.001;
    modelParameters_3.mSolverRelTol = 0.001;
    modelParameters_3.mVariableStepSolver = false;
    modelParameters_3.mIsUsingODEN = false;
    modelParameters_3.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_3.mFixedStepSize = 0.001;
    modelParameters_3.mStartTime = 0.0;
    modelParameters_3.mLoadInitialState = false;
    modelParameters_3.mUseSimState = false;
    modelParameters_3.mLinTrimCompile = false;
    modelParameters_3.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_3.mRTWModifiedTimeStamp = 5.72182455E+8;
    modelParameters_3.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_3.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters_3.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_3.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_3.mIsUsingODEN = tmp_0;
    modelParameters_3.mLoadInitialState = false;
    modelParameters_3.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.STATE_3_DiagMgr;
    diagnosticTree_3 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      double_pendulum_2_DW.STATE_3_Simulator, &modelParameters_3,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_0) {
        char *msg_3;
        msg_3 = rtw_diagnostics_msg(diagnosticTree_3);
        rtmSetErrorStatus(double_pendulum_2_M, msg_3);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S19>/STATE_3' */

    /* Start for SimscapeExecutionBlock: '<S19>/OUTPUT_3_0' */
    tmp = nesl_lease_simulator(
      "double_pendulum_2/Subsystem/Solver Configuration_3", 1, 0);
    double_pendulum_2_DW.OUTPUT_3_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(double_pendulum_2_DW.OUTPUT_3_0_Simulator);
    if (tmp_0) {
      double_pendulum_2_836bb176_3_gateway();
      tmp = nesl_lease_simulator(
        "double_pendulum_2/Subsystem/Solver Configuration_3", 1, 0);
      double_pendulum_2_DW.OUTPUT_3_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    double_pendulum_2_DW.OUTPUT_3_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    double_pendulum_2_DW.OUTPUT_3_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_4.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_4.mSolverTolerance = 0.001;
    modelParameters_4.mSolverAbsTol = 0.001;
    modelParameters_4.mSolverRelTol = 0.001;
    modelParameters_4.mVariableStepSolver = false;
    modelParameters_4.mIsUsingODEN = false;
    modelParameters_4.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_4.mFixedStepSize = 0.001;
    modelParameters_4.mStartTime = 0.0;
    modelParameters_4.mLoadInitialState = false;
    modelParameters_4.mUseSimState = false;
    modelParameters_4.mLinTrimCompile = false;
    modelParameters_4.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_4.mRTWModifiedTimeStamp = 5.72182455E+8;
    modelParameters_4.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_4.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters_4.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_4.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_4.mIsUsingODEN = tmp_0;
    modelParameters_4.mLoadInitialState = false;
    modelParameters_4.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      double_pendulum_2_DW.OUTPUT_3_0_DiagMgr;
    diagnosticTree_4 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      double_pendulum_2_DW.OUTPUT_3_0_Simulator, &modelParameters_4,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(double_pendulum_2_M));
      if (tmp_0) {
        char *msg_4;
        msg_4 = rtw_diagnostics_msg(diagnosticTree_4);
        rtmSetErrorStatus(double_pendulum_2_M, msg_4);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S19>/OUTPUT_3_0' */
  }

  {
    int32_T i;
    int_T tmp_1;
    int_T tmp_2;
    int_T tmp_3;
    int_T tmp_4;
    int_T tmp_5;
    boolean_T tmp;
    boolean_T tmp_0;
    static const uint32_T tmp_6[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    double_pendulum_2_DW.UnitDelay_DSTATE[0] =
      double_pendulum_2_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    double_pendulum_2_DW.UnitDelay1_DSTATE[0] =
      double_pendulum_2_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    double_pendulum_2_DW.UnitDelay_DSTATE[1] =
      double_pendulum_2_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    double_pendulum_2_DW.UnitDelay1_DSTATE[1] =
      double_pendulum_2_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S20>/UD' */
    double_pendulum_2_DW.UD_DSTATE =
      double_pendulum_2_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for UnitDelay: '<S21>/UD' */
    double_pendulum_2_DW.UD_DSTATE_g =
      double_pendulum_2_P.DiscreteDerivative1_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S22>/UD' */
    double_pendulum_2_DW.UD_DSTATE_d =
      double_pendulum_2_P.DiscreteDerivative2_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S23>/UD' */
    double_pendulum_2_DW.UD_DSTATE_h =
      double_pendulum_2_P.DiscreteDerivative3_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S24>/UD' */
    double_pendulum_2_DW.UD_DSTATE_m =
      double_pendulum_2_P.DiscreteDerivative4_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S25>/UD' */
    double_pendulum_2_DW.UD_DSTATE_o =
      double_pendulum_2_P.DiscreteDerivative5_ICPrevScale;

    /* InitializeConditions for SimscapeExecutionBlock: '<S19>/STATE_2' */
    tmp = false;
    tmp_0 = false;
    if (tmp_0 || tmp) {
      i = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo), "daessc");
      tmp_1 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode14x");
      tmp_2 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode15s");
      tmp_3 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode1be");
      tmp_4 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode23t");
      tmp_5 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo), "odeN");
      if ((boolean_T)((i != 0) & (tmp_1 != 0) & (tmp_2 != 0) & (tmp_3 != 0) &
                      (tmp_4 != 0) & (tmp_5 != 0))) {
        rtmSetErrorStatus(double_pendulum_2_M,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S19>/STATE_2' */

    /* InitializeConditions for SimscapeExecutionBlock: '<S19>/STATE_3' */
    tmp = false;
    tmp_0 = false;
    if (tmp_0 || tmp) {
      i = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo), "daessc");
      tmp_1 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode14x");
      tmp_2 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode15s");
      tmp_3 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode1be");
      tmp_4 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo),
                     "ode23t");
      tmp_5 = strcmp(rtsiGetSolverName(&double_pendulum_2_M->solverInfo), "odeN");
      if ((boolean_T)((i != 0) & (tmp_1 != 0) & (tmp_2 != 0) & (tmp_3 != 0) &
                      (tmp_4 != 0) & (tmp_5 != 0))) {
        rtmSetErrorStatus(double_pendulum_2_M,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S19>/STATE_3' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function1' */
    memcpy(&double_pendulum_2_DW.state_m[0], &tmp_6[0], 625U * sizeof(uint32_T));
    double_pendulum_2_DW.ti1_not_empty = false;
    double_pendulum_2_DW.method = 7U;
    double_pendulum_2_DW.state = 1144108930U;
    double_pendulum_2_DW.state_a[0] = 362436069U;
    double_pendulum_2_DW.state_a[1] = 521288629U;
    double_pendulum_2_DW.ti1 = 0.0;
    double_pendulum_2_DW.yi1 = 0.0;
    double_pendulum_2_DW.tf1 = 0.5;
    double_pendulum_2_DW.flag1 = 0.0;
    double_pendulum_2_DW.count1 = 0.0;
    double_pendulum_2_DW.yi2 = 0.0;
    double_pendulum_2_DW.tf2 = 0.5;
    double_pendulum_2_DW.flag2 = 0.0;
    double_pendulum_2_DW.count2 = 0.0;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    double_pendulum_2_DW.theta_not_empty = false;

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[6] = { 0, 1, 2, 3, 4, 5 };

      static int_T modelMassMatrixJc[7] = { 0, 1, 2, 3, 4, 5, 6 };

      static real_T modelMassMatrixPr[6] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

      (void) memcpy(double_pendulum_2_MassMatrix.ir, modelMassMatrixIr,
                    6*sizeof(int_T));
      (void) memcpy(double_pendulum_2_MassMatrix.jc, modelMassMatrixJc,
                    7*sizeof(int_T));
      (void) memcpy(double_pendulum_2_MassMatrix.pr, modelMassMatrixPr,
                    6*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void double_pendulum_2_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S19>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    double_pendulum_2_DW.STATE_1_SimData);
  nesl_erase_simulator("double_pendulum_2/Subsystem/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S19>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    double_pendulum_2_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    double_pendulum_2_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("double_pendulum_2/Subsystem/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S19>/STATE_2' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_2_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    double_pendulum_2_DW.STATE_2_SimData);
  nesl_erase_simulator("double_pendulum_2/Subsystem/Solver Configuration_2");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S19>/OUTPUT_2_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    double_pendulum_2_DW.OUTPUT_2_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    double_pendulum_2_DW.OUTPUT_2_0_SimData);
  nesl_erase_simulator("double_pendulum_2/Subsystem/Solver Configuration_2");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S19>/STATE_3' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    double_pendulum_2_DW.STATE_3_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    double_pendulum_2_DW.STATE_3_SimData);
  nesl_erase_simulator("double_pendulum_2/Subsystem/Solver Configuration_3");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S19>/OUTPUT_3_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    double_pendulum_2_DW.OUTPUT_3_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    double_pendulum_2_DW.OUTPUT_3_0_SimData);
  nesl_erase_simulator("double_pendulum_2/Subsystem/Solver Configuration_3");
  nesl_destroy_registry();
}
