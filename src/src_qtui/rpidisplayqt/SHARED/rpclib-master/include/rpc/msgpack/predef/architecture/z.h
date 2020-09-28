/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef MSGPACK_PREDEF_ARCHITECTURE_Z_H
#define MSGPACK_PREDEF_ARCHITECTURE_Z_H

#include "../version_number.h"
#include "../make.h"

/*`
[heading `MSGPACK_ARCH_Z`]

[@http://en.wikipedia.org/wiki/Z/Architecture z/Architecture] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SYSC_ZARCH__`] [__predef_detection__]]
    ]
 */

#define MSGPACK_ARCH_Z MSGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC_ZARCH__)
#   undef MSGPACK_ARCH_Z
#   define MSGPACK_ARCH_Z MSGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if MSGPACK_ARCH_Z
#   define MSGPACK_ARCH_Z_AVAILABLE
#endif

#define MSGPACK_ARCH_Z_NAME "z/Architecture"

#endif

#include "../detail/test.h"
MSGPACK_PREDEF_DECLARE_TEST(MSGPACK_ARCH_Z,MSGPACK_ARCH_Z_NAME)
