/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'double_pendulum_2/Subsystem/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "double_pendulum_2_836bb176_1_geometries.h"

PmfMessageId double_pendulum_2_836bb176_1_compDerivs(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *deriv, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[1];
  double xx[29];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 0.0187817175;
  xx[1] = 0.1715;
  xx[2] = 2.0;
  xx[3] = 0.5;
  xx[4] = xx[3] * state[2];
  xx[5] = cos(xx[4]);
  xx[6] = sin(xx[4]);
  xx[4] = xx[1] * xx[6];
  xx[7] = 0.306 - xx[2] * xx[4] * xx[6];
  xx[8] = xx[7] * state[1] * state[1];
  xx[9] = xx[8] * xx[6];
  xx[10] = xx[2] * xx[5] * xx[4];
  xx[4] = xx[10] * state[1] * state[1];
  xx[11] = xx[4] * xx[6];
  xx[12] = 1.89;
  xx[13] = (xx[2] * (xx[5] * xx[9] + xx[11] * xx[6]) - xx[4]) * xx[12];
  xx[4] = 0.07437087000000001;
  ii[0] = factorSymmetricPosDef(xx + 4, 1, xx + 14);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'double_pendulum_2/Subsystem/Revolute Joint1' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[14] = (input[1] - xx[1] * xx[13]) / xx[4];
  xx[15] = 0.324135;
  xx[16] = xx[13] + xx[15] * xx[14];
  xx[13] = xx[12] * ((xx[9] * xx[6] - xx[5] * xx[11]) * xx[2] - xx[8] - xx[1] *
                     (state[1] + state[1] + state[3]) * state[3]) - input[2];
  xx[1] = xx[6] * xx[13];
  xx[8] = xx[16] * xx[6];
  xx[9] = xx[16] + xx[2] * (xx[5] * xx[1] - xx[8] * xx[6]);
  xx[11] = xx[15] / xx[4];
  xx[16] = xx[0] * xx[11];
  xx[17] = xx[2] * xx[5] * xx[6];
  xx[18] = xx[5] * xx[5];
  xx[19] = 1.0;
  xx[20] = (xx[18] + xx[6] * xx[6]) * xx[2] - xx[19];
  xx[21] = xx[16] * xx[17] * xx[20];
  xx[22] = xx[12] * xx[17];
  xx[23] = xx[2] * xx[18] - xx[19];
  xx[18] = xx[12] - xx[15] * xx[11];
  xx[15] = xx[18] * xx[23];
  xx[19] = xx[22] * xx[23] - xx[17] * xx[15];
  xx[24] = xx[12] * xx[23];
  xx[12] = xx[17] * xx[18];
  xx[18] = xx[7] * xx[19] - (xx[24] * xx[23] + xx[17] * xx[12]) * xx[10];
  xx[25] = xx[21] + xx[18];
  xx[26] = 0.1345;
  xx[27] = xx[26] * state[1] * state[1];
  xx[28] = xx[24] * xx[17] - xx[12] * xx[23];
  xx[12] = xx[0] / xx[4];
  xx[4] = xx[16] * xx[23] * xx[20];
  xx[16] = xx[7] * xx[4] + xx[10] * xx[21];
  xx[21] = xx[22] * xx[17] + xx[15] * xx[23];
  xx[15] = xx[21] * xx[7] - xx[10] * xx[28];
  xx[17] = xx[15] - xx[4];
  xx[4] = xx[17] + (1.75 + xx[21]) * xx[26];
  xx[21] = (xx[0] - xx[0] * xx[12]) * xx[20] * xx[20] - xx[16] - xx[16] + xx[7] *
    xx[15] - xx[18] * xx[10] + xx[26] * xx[17] + xx[4] * xx[26] +
    0.01078597916666667;
  ii[0] = factorSymmetricPosDef(xx + 21, 1, xx + 15);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'double_pendulum_2/Subsystem/Revolute Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[15] = xx[3] * state[0];
  xx[3] = 9.806649999999999;
  xx[16] = sin(xx[15]);
  xx[17] = xx[3] * xx[16];
  xx[18] = xx[2] * cos(xx[15]) * xx[17];
  xx[15] = xx[3] - xx[2] * xx[17] * xx[16];
  xx[3] = (input[0] - (xx[0] * xx[14] + xx[9] * xx[7] - xx[10] * (xx[13] - (xx[5]
              * xx[8] + xx[1] * xx[6]) * xx[2]) - xx[25] * xx[27] + xx[26] *
                       (xx[9] - xx[27] * xx[28]))) / xx[21] - ((xx[25] + xx[26] *
    xx[19]) / xx[21] * xx[18] + xx[4] / xx[21] * xx[15]);
  xx[0] = xx[15] + xx[26] * xx[3] + xx[7] * xx[3];
  deriv[0] = state[1];
  deriv[1] = xx[3];
  deriv[2] = state[3];
  deriv[3] = xx[14] - (xx[12] * xx[3] + xx[11] * (xx[0] - (xx[5] * (xx[18] - xx
    [27] - xx[10] * xx[3]) * xx[6] + xx[0] * xx[6] * xx[6]) * xx[2]));
  errorResult[0] = 0.0;
  return NULL;
}

PmfMessageId double_pendulum_2_836bb176_1_numJacPerturbLoBounds(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *bounds, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[1];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 1.0e-8;
  bounds[0] = xx[0];
  bounds[1] = xx[0];
  bounds[2] = xx[0];
  bounds[3] = xx[0];
  errorResult[0] = 0.0;
  return NULL;
}

PmfMessageId double_pendulum_2_836bb176_1_numJacPerturbHiBounds(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *bounds, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[2];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 1.0;
  xx[1] = +pmf_get_inf();
  bounds[0] = xx[0];
  bounds[1] = xx[1];
  bounds[2] = xx[0];
  bounds[3] = xx[1];
  errorResult[0] = 0.0;
  return NULL;
}
