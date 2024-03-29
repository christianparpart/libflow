// This file is part of the "x0" project, http://github.com/christianparpart/libflow//
//   (c) 2009-2014 Christian Parpart <trapni@gmail.com>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#ifndef flow_api_hpp
#define flow_api_hpp (1)

#include <stx/Defines.h>

// libflow exports
#if defined(BUILD_FLOW)
#define FLOW_API STX_EXPORT
#else
#define FLOW_API STX_IMPORT
#endif

#endif
