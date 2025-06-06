// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <cstdint>

#include "openvino/core/type/bfloat16.hpp"
#include "openvino/core/type/float16.hpp"

namespace ov::Extensions::Cpu::XARCH {

void llm_mlp_transpose_epi32_16x16(void* dst, void* src, int stride);
void llm_mlp_quantize_bf16_i8(ov::bfloat16* psrc,
                              int src_stride,
                              int8_t* pdst,
                              int dst_stride,
                              int rows,
                              int cols,
                              float* p_scales,
                              float* p_zp,
                              bool asym);
void llm_mlp_quantize_f16_i8(ov::float16* psrc,
                             int src_stride,
                             int8_t* pdst,
                             int dst_stride,
                             int rows,
                             int cols,
                             float* p_scales,
                             float* p_zp,
                             bool asym);
void llm_mlp_dequantize_i32_f32(int Batch,
                                int OC,
                                const int32_t* src,
                                int stride_src,
                                float* dst,
                                int stride_dst,
                                const float* p_src_scale_per_row,
                                const float* p_src_zp_per_row,
                                const float* p_wsum_per_oc,
                                const float* p_wscale_per_oc,
                                bool asym);
}  // namespace ov::Extensions::Cpu::XARCH
