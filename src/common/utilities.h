//
// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// utilities.h: Conversion functions and other utility routines.

#ifndef COMMON_UTILITIES_H_
#define COMMON_UTILITIES_H_
#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <math.h>
#include <string>
#include <vector>
#include "angle_gl.h"

#include "common/PackedEnums.h"
#include "common/mathutil.h"

namespace sh
{
struct ShaderVariable;
}

namespace gl
{

int VariableComponentCount(GLenum type);
GLenum VariableComponentType(GLenum type);
size_t VariableComponentSize(GLenum type);
size_t VariableInternalSize(GLenum type);
size_t VariableExternalSize(GLenum type);
int VariableRowCount(GLenum type);
int VariableColumnCount(GLenum type);
bool IsSamplerType(GLenum type);
bool IsImageType(GLenum type);
bool IsAtomicCounterType(GLenum type);
bool IsOpaqueType(GLenum type);
bool IsMatrixType(GLenum type);
GLenum TransposeMatrixType(GLenum type);
int VariableRegisterCount(GLenum type);
int MatrixRegisterCount(GLenum type, bool isRowMajorMatrix);
int MatrixComponentCount(GLenum type, bool isRowMajorMatrix);
int VariableSortOrder(GLenum type);
GLenum VariableBoolVectorType(GLenum type);

int AllocateFirstFreeBits(unsigned int *bits, unsigned int allocationSize, unsigned int bitsSize);

// Parse the base resource name and array indices. Returns the base name of the resource.
// If the provided name doesn't index an array, the outSubscripts vector will be empty.
// If the provided name indexes an array, the outSubscripts vector will contain indices with
// outermost array indices in the back. If an array index is invalid, GL_INVALID_INDEX is added to
// outSubscripts.
std::string ParseResourceName(const std::string &name, std::vector<unsigned int> *outSubscripts);

// Find the child field which matches 'fullName' == var.name + "." + field.name.
// Return nullptr if not found.
const sh::ShaderVariable *FindShaderVarField(const sh::ShaderVariable &var,
                                             const std::string &fullName);

// Find the range of index values in the provided indices pointer.  Primitive restart indices are
// only counted in the range if primitive restart is disabled.
IndexRange ComputeIndexRange(GLenum indexType,
                             const GLvoid *indices,
                             size_t count,
                             bool primitiveRestartEnabled);

// Get the primitive restart index value for the given index type.
GLuint GetPrimitiveRestartIndex(GLenum indexType);

bool IsTriangleMode(PrimitiveMode drawMode);
bool IsLineMode(PrimitiveMode primitiveMode);
bool IsIntegerFormat(GLenum unsizedFormat);

// Returns the product of the sizes in the vector, or 1 if the vector is empty. Doesn't currently
// perform overflow checks.
unsigned int ArraySizeProduct(const std::vector<unsigned int> &arraySizes);

// Return the array index at the end of name, and write the length of name before the final array
// index into nameLengthWithoutArrayIndexOut. In case name doesn't include an array index, return
// GL_INVALID_INDEX and write the length of the original string.
unsigned int ParseArrayIndex(const std::string &name, size_t *nameLengthWithoutArrayIndexOut);

struct UniformTypeInfo final : angle::NonCopyable
{
    constexpr UniformTypeInfo(GLenum type,
                              GLenum componentType,
                              GLenum textureType,
                              GLenum transposedMatrixType,
                              GLenum boolVectorType,
                              int rowCount,
                              int columnCount,
                              int componentCount,
                              size_t componentSize,
                              size_t internalSize,
                              size_t externalSize,
                              bool isSampler,
                              bool isMatrixType,
                              bool isImageType)
        : type(type),
          componentType(componentType),
          textureType(textureType),
          transposedMatrixType(transposedMatrixType),
          boolVectorType(boolVectorType),
          rowCount(rowCount),
          columnCount(columnCount),
          componentCount(componentCount),
          componentSize(componentSize),
          internalSize(internalSize),
          externalSize(externalSize),
          isSampler(isSampler),
          isMatrixType(isMatrixType),
          isImageType(isImageType)
    {
    }

    GLenum type;
    GLenum componentType;
    GLenum textureType;
    GLenum transposedMatrixType;
    GLenum boolVectorType;
    int rowCount;
    int columnCount;
    int componentCount;
    size_t componentSize;
    size_t internalSize;
    size_t externalSize;
    bool isSampler;
    bool isMatrixType;
    bool isImageType;
};

const UniformTypeInfo &GetUniformTypeInfo(GLenum uniformType);

const char *GetGenericErrorMessage(GLenum error);

unsigned int ElementTypeSize(GLenum elementType);

}  // namespace gl

namespace egl
{
static const EGLenum FirstCubeMapTextureTarget = EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_KHR;
static const EGLenum LastCubeMapTextureTarget  = EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_KHR;
bool IsCubeMapTextureTarget(EGLenum target);
size_t CubeMapTextureTargetToLayerIndex(EGLenum target);
EGLenum LayerIndexToCubeMapTextureTarget(size_t index);
bool IsTextureTarget(EGLenum target);
bool IsRenderbufferTarget(EGLenum target);

const char *GetGenericErrorMessage(EGLint error);
}  // namespace egl

namespace egl_gl
{
GLuint EGLClientBufferToGLObjectHandle(EGLClientBuffer buffer);
}

namespace gl_egl
{
EGLenum GLComponentTypeToEGLColorComponentType(GLenum glComponentType);
EGLClientBuffer GLObjectHandleToEGLClientBuffer(GLuint handle);
}  // namespace gl_egl

#if !defined(ANGLE_ENABLE_WINDOWS_STORE)
std::string getTempPath();
void writeFile(const char *path, const void *data, size_t size);
#endif

#if defined(ANGLE_PLATFORM_WINDOWS)
void ScheduleYield();
#endif

#endif  // COMMON_UTILITIES_H_
