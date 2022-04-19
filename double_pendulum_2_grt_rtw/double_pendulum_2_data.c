/*
 * double_pendulum_2_data.c
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

/* Block parameters (default storage) */
P_double_pendulum_2_T double_pendulum_2_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S20>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S21>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative2_ICPrevScale
   * Referenced by: '<S22>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative3_ICPrevScale
   * Referenced by: '<S23>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative4_ICPrevScale
   * Referenced by: '<S24>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative5_ICPrevScale
   * Referenced by: '<S25>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S20>/TSamp'
   */
  1000.0,

  /* Computed Parameter: TSamp_WtEt_n
   * Referenced by: '<S21>/TSamp'
   */
  1000.0,

  /* Computed Parameter: TSamp_WtEt_a
   * Referenced by: '<S22>/TSamp'
   */
  1000.0,

  /* Computed Parameter: TSamp_WtEt_f
   * Referenced by: '<S23>/TSamp'
   */
  1000.0,

  /* Computed Parameter: TSamp_WtEt_e
   * Referenced by: '<S24>/TSamp'
   */
  1000.0,

  /* Computed Parameter: TSamp_WtEt_h
   * Referenced by: '<S25>/TSamp'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0
};
