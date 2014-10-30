/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include "reduce_impl.hpp"

namespace opencl
{
    //alltrue
    INSTANTIATE(af_and_t, float  , uchar)
    INSTANTIATE(af_and_t, double , uchar)
    INSTANTIATE(af_and_t, cfloat , uchar)
    INSTANTIATE(af_and_t, cdouble, uchar)
    INSTANTIATE(af_and_t, int    , uchar)
    INSTANTIATE(af_and_t, uint   , uchar)
    INSTANTIATE(af_and_t, char   , uchar)
    INSTANTIATE(af_and_t, uchar  , uchar)
}
