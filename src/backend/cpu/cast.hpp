/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once
#include <af/dim4.hpp>
#include <af/defines.h>
#include <ArrayInfo.hpp>
#include <complex>
#include <err_cpu.hpp>
#include <math.hpp>
#include <optypes.hpp>
#include <types.hpp>
#include <TNJ/UnaryNode.hpp>

namespace cpu
{

template<typename To, typename Ti>
struct UnOp<To, Ti, af_cast_t>
{
    To eval(Ti in)
    {
        return To(in);
    }
};

template<typename To>
struct UnOp<To, std::complex<float>, af_cast_t>
{
    To eval(std::complex<float> in)
    {
        return To(std::abs(in));
    }
};

template<typename To>
struct UnOp<To, std::complex<double>, af_cast_t>
{
    To eval(std::complex<double> in)
    {
        return To(std::abs(in));
    }
};

template<typename To, typename Ti>
Array<To>* cast(const Array<Ti> &in)
{
    TNJ::Node *in_node = in.getNode();
    TNJ::UnaryNode<To, Ti, af_cast_t> *node = new TNJ::UnaryNode<To, Ti, af_cast_t>(in_node);

    return createNodeArray<To>(in.dims(), reinterpret_cast<TNJ::Node *>(node));
}

}
