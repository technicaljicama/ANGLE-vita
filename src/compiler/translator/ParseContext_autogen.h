// GENERATED FILE - DO NOT EDIT.
// Generated by gen_builtin_symbols.py using data from builtin_variables.json and
// builtin_function_declarations.txt.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// ParseContext_autogen.h:
//   Helpers for built-in related checks.

#ifndef COMPILER_TRANSLATOR_PARSECONTEXT_AUTOGEN_H_
#define COMPILER_TRANSLATOR_PARSECONTEXT_AUTOGEN_H_

namespace sh
{

namespace BuiltInGroup
{

bool isTextureOffsetNoBias(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 671 && id <= 740;
}
bool isTextureOffsetBias(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 741 && id <= 760;
}
bool isTextureGatherOffset(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 838 && id <= 851;
}
bool isTextureGather(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 814 && id <= 851;
}
bool isAtomicMemory(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 868 && id <= 885;
}
bool isImageLoad(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 910 && id <= 921;
}
bool isImageStore(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 922 && id <= 933;
}
bool isImage(const TFunction *func)
{
    int id = func->uniqueId().get();
    return id >= 886 && id <= 933;
}

}  // namespace BuiltInGroup

}  // namespace sh

#endif  // COMPILER_TRANSLATOR_PARSECONTEXT_AUTOGEN_H_