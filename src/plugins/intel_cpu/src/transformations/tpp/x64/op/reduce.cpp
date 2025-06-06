// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "reduce.hpp"

#include <libxsmm_typedefs.h>

#include <cstddef>
#include <memory>

#include "openvino/core/attribute_visitor.hpp"
#include "openvino/core/node.hpp"
#include "openvino/core/node_output.hpp"
#include "openvino/core/node_vector.hpp"
#include "snippets/op/reduce.hpp"
#include "transformations/tpp/x64/op/eltwise.hpp"

namespace ov::intel_cpu::tpp::op {

ReduceMax::ReduceMax(const Output<Node>& arg, size_t axis)
    : UnaryEltwiseTPP(LIBXSMM_MELTW_TYPE_UNARY_REDUCE_X_OP_MAX),
      ov::snippets::op::ReduceMax(arg, axis) {}

std::shared_ptr<Node> ReduceMax::clone_with_new_inputs(const OutputVector& new_args) const {
    check_new_args_count(this, new_args);
    const auto& new_op = std::make_shared<ReduceMax>(new_args.at(0), m_axis);
    new_op->clone_memory_access_ports(*this);
    return new_op;
}

bool ReduceMax::visit_attributes(AttributeVisitor& visitor) {
    ReduceBase::visit_attributes(visitor);
    return UnaryEltwiseTPP::visit_attributes(visitor);
}

ReduceSum::ReduceSum(const Output<Node>& arg, size_t axis)
    : UnaryEltwiseTPP(LIBXSMM_MELTW_TYPE_UNARY_REDUCE_X_OP_ADD),
      ov::snippets::op::ReduceSum(arg, axis) {}

std::shared_ptr<Node> ReduceSum::clone_with_new_inputs(const OutputVector& new_args) const {
    check_new_args_count(this, new_args);
    const auto& new_op = std::make_shared<ReduceSum>(new_args.at(0), m_axis);
    new_op->clone_memory_access_ports(*this);
    return new_op;
}

bool ReduceSum::visit_attributes(AttributeVisitor& visitor) {
    ReduceBase::visit_attributes(visitor);
    return UnaryEltwiseTPP::visit_attributes(visitor);
}

}  // namespace ov::intel_cpu::tpp::op
