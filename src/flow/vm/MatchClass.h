// This file is part of the "x0" project, http://github.com/christianparpart/libflow//
//   (c) 2009-2014 Christian Parpart <trapni@gmail.com>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#include <flow/Api.h>
#include <string>

namespace flow {
namespace vm {

enum class MatchClass { Same, Head, Tail, RegExp, };

CORTEX_FLOW_API std::string tos(MatchClass c);

}  // namespace vm
}  // namespace flow
