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

PmfMessageId double_pendulum_2_836bb176_1_recordLog(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, double *logVector, double *errorResult,
  NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[1];
  double xx[30];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) inputDot;
  (void) inputDdot;
  (void) neDiagMgr;
  xx[0] = 57.29577951308232;
  xx[1] = 0.0187817175;
  xx[2] = 0.1715;
  xx[3] = 2.0;
  xx[4] = 0.5;
  xx[5] = xx[4] * state[2];
  xx[6] = cos(xx[5]);
  xx[7] = sin(xx[5]);
  xx[5] = xx[2] * xx[7];
  xx[8] = 0.306 - xx[3] * xx[5] * xx[7];
  xx[9] = xx[8] * state[1] * state[1];
  xx[10] = xx[9] * xx[7];
  xx[11] = xx[3] * xx[6] * xx[5];
  xx[5] = xx[11] * state[1] * state[1];
  xx[12] = xx[5] * xx[7];
  xx[13] = 1.89;
  xx[14] = (xx[3] * (xx[6] * xx[10] + xx[12] * xx[7]) - xx[5]) * xx[13];
  xx[5] = 0.07437087000000001;
  ii[0] = factorSymmetricPosDef(xx + 5, 1, xx + 15);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'double_pendulum_2/Subsystem/Revolute Joint1' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[15] = (input[1] - xx[2] * xx[14]) / xx[5];
  xx[16] = 0.324135;
  xx[17] = xx[14] + xx[16] * xx[15];
  xx[14] = xx[13] * ((xx[10] * xx[7] - xx[6] * xx[12]) * xx[3] - xx[9] - xx[2] *
                     (state[1] + state[1] + state[3]) * state[3]) - input[2];
  xx[2] = xx[7] * xx[14];
  xx[9] = xx[17] * xx[7];
  xx[10] = xx[17] + xx[3] * (xx[6] * xx[2] - xx[9] * xx[7]);
  xx[12] = xx[16] / xx[5];
  xx[17] = xx[1] * xx[12];
  xx[18] = xx[3] * xx[6] * xx[7];
  xx[19] = xx[6] * xx[6];
  xx[20] = 1.0;
  xx[21] = (xx[19] + xx[7] * xx[7]) * xx[3] - xx[20];
  xx[22] = xx[17] * xx[18] * xx[21];
  xx[23] = xx[13] * xx[18];
  xx[24] = xx[3] * xx[19] - xx[20];
  xx[19] = xx[13] - xx[16] * xx[12];
  xx[16] = xx[19] * xx[24];
  xx[20] = xx[23] * xx[24] - xx[18] * xx[16];
  xx[25] = xx[13] * xx[24];
  xx[13] = xx[18] * xx[19];
  xx[19] = xx[8] * xx[20] - (xx[25] * xx[24] + xx[18] * xx[13]) * xx[11];
  xx[26] = xx[22] + xx[19];
  xx[27] = 0.1345;
  xx[28] = xx[27] * state[1] * state[1];
  xx[29] = xx[25] * xx[18] - xx[13] * xx[24];
  xx[13] = xx[1] / xx[5];
  xx[5] = xx[17] * xx[24] * xx[21];
  xx[17] = xx[8] * xx[5] + xx[11] * xx[22];
  xx[22] = xx[23] * xx[18] + xx[16] * xx[24];
  xx[16] = xx[22] * xx[8] - xx[11] * xx[29];
  xx[18] = xx[16] - xx[5];
  xx[5] = xx[18] + (1.75 + xx[22]) * xx[27];
  xx[22] = (xx[1] - xx[1] * xx[13]) * xx[21] * xx[21] - xx[17] - xx[17] + xx[8] *
    xx[16] - xx[19] * xx[11] + xx[27] * xx[18] + xx[5] * xx[27] +
    0.01078597916666667;
  ii[0] = factorSymmetricPosDef(xx + 22, 1, xx + 16);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'double_pendulum_2/Subsystem/Revolute Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[16] = xx[4] * state[0];
  xx[4] = 9.806649999999999;
  xx[17] = sin(xx[16]);
  xx[18] = xx[4] * xx[17];
  xx[19] = xx[3] * cos(xx[16]) * xx[18];
  xx[16] = xx[4] - xx[3] * xx[18] * xx[17];
  xx[4] = (input[0] - (xx[1] * xx[15] + xx[10] * xx[8] - xx[11] * (xx[14] - (xx
              [6] * xx[9] + xx[2] * xx[7]) * xx[3]) - xx[26] * xx[28] + xx[27] *
                       (xx[10] - xx[28] * xx[29]))) / xx[22] - ((xx[26] + xx[27]
    * xx[20]) / xx[22] * xx[19] + xx[5] / xx[22] * xx[16]);
  xx[1] = xx[16] + xx[27] * xx[4] + xx[8] * xx[4];
  logVector[0] = xx[0] * state[0];
  logVector[1] = xx[0] * state[1];
  logVector[2] = xx[0] * state[2];
  logVector[3] = xx[0] * state[3];
  logVector[4] = xx[0] * xx[4];
  logVector[5] = xx[0] * (xx[15] - (xx[13] * xx[4] + xx[12] * (xx[1] - (xx[6] *
    (xx[19] - xx[28] - xx[11] * xx[4]) * xx[7] + xx[1] * xx[7] * xx[7]) * xx[3])));
  errorResult[0] = 0.0;
  return NULL;
}
