// This file is part of fTetWild, a software for generating tetrahedral meshes.
//
// Copyright (C) 2019 Yixin Hu <yixin.hu@nyu.edu>
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
//
// C Api  
#pragma once

#include <floattetwild/Parameters.h>

namespace floatTetWild {

#ifndef CAPIONLY
int tetrahedralization(GEO::Mesh&       sf_mesh,
                       Parameters       params,
                       Eigen::MatrixXd& VO,
                       Eigen::MatrixXi& TO,
                       int              boolean_op    = -1,
                       bool             skip_simplify = false);
#endif

// C API
extern "C"
{
    int __declspec(dllexport) __cdecl tetrahedralizationFlat(size_t        nvI,
                                                             const double* vI,
                                                             size_t        ntI,
                                                             const size_t* tI,
                                                             void*         params,
                                                             void**        vo,
                                                             void**        to,
                                                             int           boolean_op,
                                                             int           skip_simplify);

    int __declspec(dllexport) __cdecl tetrahedralizationClean(void* v, void* t);
}
}  // namespace floatTetWild
