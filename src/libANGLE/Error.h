//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Error.h: Defines the egl::Error and gl::Error classes which encapsulate API errors
// and optional error messages.

#ifndef LIBANGLE_ERROR_H_
#define LIBANGLE_ERROR_H_

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "angle_gl.h"
#include "common/angleutils.h"
#include "common/debug.h"

#include <memory>
#include <ostream>
#include <string>

namespace angle
{
template <typename ErrorT, typename ErrorBaseT, ErrorBaseT NoErrorVal, typename CodeT, CodeT EnumT>
class ErrorStreamBase : angle::NonCopyable
{
  public:
    ErrorStreamBase() : mID(EnumT) {}
    ErrorStreamBase(GLuint id) : mID(id) {}

    template <typename T>
    ErrorStreamBase &operator<<(T value)
    {
        mErrorStream << value;
        return *this;
    }

    operator ErrorT() { return ErrorT(EnumT, mID, mErrorStream.str()); }

  private:
    GLuint mID;
    std::ostringstream mErrorStream;
};
}  // namespace angle

namespace egl
{
class Error;
}  // namespace egl

namespace gl
{

class ANGLE_NO_DISCARD Error final
{
  public:
    explicit inline Error(GLenum errorCode);
    Error(GLenum errorCode, std::string &&message);
    Error(GLenum errorCode, GLuint id, std::string &&message);
    inline Error(const Error &other);
    inline Error(Error &&other);
    inline ~Error() = default;

    // automatic error type conversion
    // inline Error(egl::Error &&eglErr);
    inline Error(egl::Error eglErr);

    inline Error &operator=(const Error &other);
    inline Error &operator=(Error &&other);

    inline GLenum getCode() const;
    inline GLuint getID() const;
    inline bool isError() const;

    const std::string &getMessage() const;

    // Useful for mocking and testing
    bool operator==(const Error &other) const;
    bool operator!=(const Error &other) const;

    static inline Error NoError();

  private:
    void createMessageString() const;

    friend std::ostream &operator<<(std::ostream &os, const Error &err);
    friend class egl::Error;

    GLenum mCode;
    GLuint mID;
    mutable std::unique_ptr<std::string> mMessage;
};

namespace priv
{

template <GLenum EnumT>
using ErrorStream = angle::ErrorStreamBase<Error, GLenum, GL_NO_ERROR, GLenum, EnumT>;

}  // namespace priv

using InternalError = priv::ErrorStream<GL_INVALID_OPERATION>;

using InvalidEnum                 = priv::ErrorStream<GL_INVALID_ENUM>;
using InvalidValue                = priv::ErrorStream<GL_INVALID_VALUE>;
using InvalidOperation            = priv::ErrorStream<GL_INVALID_OPERATION>;
using StackOverflow               = priv::ErrorStream<GL_STACK_OVERFLOW>;
using StackUnderflow              = priv::ErrorStream<GL_STACK_UNDERFLOW>;
using OutOfMemory                 = priv::ErrorStream<GL_OUT_OF_MEMORY>;
using InvalidFramebufferOperation = priv::ErrorStream<GL_INVALID_FRAMEBUFFER_OPERATION>;

inline Error NoError()
{
    return Error::NoError();
}
}  // namespace gl

namespace egl
{

class ANGLE_NO_DISCARD Error final
{
  public:
    explicit inline Error(EGLint errorCode);
    Error(EGLint errorCode, std::string &&message);
    Error(EGLint errorCode, EGLint id, std::string &&message);
    inline Error(const Error &other);
    inline Error(Error &&other);
    inline ~Error() = default;

    // automatic error type conversion
    inline Error(gl::Error &&glErr);
    inline Error(const gl::Error &glErr);

    inline Error &operator=(const Error &other);
    inline Error &operator=(Error &&other);

    inline EGLint getCode() const;
    inline EGLint getID() const;
    inline bool isError() const;

    const std::string &getMessage() const;

    static inline Error NoError();

  private:
    void createMessageString() const;

    friend std::ostream &operator<<(std::ostream &os, const Error &err);
    friend class gl::Error;

    EGLint mCode;
    EGLint mID;
    mutable std::unique_ptr<std::string> mMessage;
};

namespace priv
{

template <EGLint EnumT>
using ErrorStream = angle::ErrorStreamBase<Error, EGLint, EGL_SUCCESS, EGLint, EnumT>;

}  // namespace priv

using EglNotInitialized    = priv::ErrorStream<EGL_NOT_INITIALIZED>;
using EglBadAccess         = priv::ErrorStream<EGL_BAD_ACCESS>;
using EglBadAlloc          = priv::ErrorStream<EGL_BAD_ALLOC>;
using EglBadAttribute      = priv::ErrorStream<EGL_BAD_ATTRIBUTE>;
using EglBadConfig         = priv::ErrorStream<EGL_BAD_CONFIG>;
using EglBadContext        = priv::ErrorStream<EGL_BAD_CONTEXT>;
using EglBadCurrentSurface = priv::ErrorStream<EGL_BAD_CURRENT_SURFACE>;
using EglBadDisplay        = priv::ErrorStream<EGL_BAD_DISPLAY>;
using EglBadMatch          = priv::ErrorStream<EGL_BAD_MATCH>;
using EglBadNativeWindow   = priv::ErrorStream<EGL_BAD_NATIVE_WINDOW>;
using EglBadParameter      = priv::ErrorStream<EGL_BAD_PARAMETER>;
using EglBadSurface        = priv::ErrorStream<EGL_BAD_SURFACE>;
using EglContextLost       = priv::ErrorStream<EGL_CONTEXT_LOST>;
using EglBadStream         = priv::ErrorStream<EGL_BAD_STREAM_KHR>;
using EglBadState          = priv::ErrorStream<EGL_BAD_STATE_KHR>;
using EglBadDevice         = priv::ErrorStream<EGL_BAD_DEVICE_EXT>;

inline Error NoError()
{
    return Error::NoError();
}

}  // namespace egl

#define ANGLE_CONCAT1(x, y) x##y
#define ANGLE_CONCAT2(x, y) ANGLE_CONCAT1(x, y)
#define ANGLE_LOCAL_VAR ANGLE_CONCAT2(_localVar, __LINE__)

#define ANGLE_TRY_TEMPLATE(EXPR, FUNC)                 \
    {                                                  \
        auto ANGLE_LOCAL_VAR = EXPR;                   \
        if (ANGLE_UNLIKELY(ANGLE_LOCAL_VAR.isError())) \
        {                                              \
            FUNC(ANGLE_LOCAL_VAR);                     \
        }                                              \
    }                                                  \
    ANGLE_EMPTY_STATEMENT

#define ANGLE_RETURN(X) return X;
#define ANGLE_TRY(EXPR) ANGLE_TRY_TEMPLATE(EXPR, ANGLE_RETURN);

// TODO(jmadill): Remove this once refactor is complete. http://anglebug.com/2491
#define ANGLE_TRY_HANDLE(CONTEXT, EXPR)                \
    {                                                  \
        auto ANGLE_LOCAL_VAR = (EXPR);                 \
        if (ANGLE_UNLIKELY(ANGLE_LOCAL_VAR.isError())) \
        {                                              \
            CONTEXT->handleError(ANGLE_LOCAL_VAR);     \
            return angle::Result::Stop();              \
        }                                              \
    }                                                  \
    ANGLE_EMPTY_STATEMENT

// TODO(jmadill): Introduce way to store errors to a const Context. http://anglebug.com/2491
#define ANGLE_SWALLOW_ERR(EXPR)                                       \
    {                                                                 \
        auto ANGLE_LOCAL_VAR = EXPR;                                  \
        if (ANGLE_UNLIKELY(ANGLE_LOCAL_VAR.isError()))                \
        {                                                             \
            ERR() << "Unhandled internal error: " << ANGLE_LOCAL_VAR; \
        }                                                             \
    }                                                                 \
    ANGLE_EMPTY_STATEMENT

#undef ANGLE_LOCAL_VAR
#undef ANGLE_CONCAT2
#undef ANGLE_CONCAT1

#define ANGLE_CHECK(CONTEXT, EXPR, MESSAGE, ERROR)                                    \
    {                                                                                 \
        if (ANGLE_UNLIKELY(!(EXPR)))                                                  \
        {                                                                             \
            CONTEXT->handleError(ERROR, MESSAGE, __FILE__, ANGLE_FUNCTION, __LINE__); \
            return angle::Result::Stop();                                             \
        }                                                                             \
    }

namespace angle
{
// Result signals if calling code should continue running or early exit. A value of Stop() can
// either indicate an Error or a non-Error early exit condition such as a detected no-op.  A few
// other values exist to signal special cases that are neither success nor failure but require
// special attention.
class ANGLE_NO_DISCARD Result
{
  public:
    // TODO(jmadill): Rename when refactor is complete. http://anglebug.com/2491
    bool isError() const { return mValue == Value::Stop; }

    static Result Stop() { return Result(Value::Stop); }
    static Result Continue() { return Result(Value::Continue); }
    static Result Incomplete() { return Result(Value::Incomplete); }

    // TODO(jmadill): Remove when refactor is complete. http://anglebug.com/2491
    operator gl::Error() const;

    bool operator==(Result other) const { return mValue == other.mValue; }

    bool operator!=(Result other) const { return mValue != other.mValue; }

  private:
    enum class Value
    {
        Continue,
        Stop,
        Incomplete,
    };

    Result(Value value) : mValue(value) {}
    Value mValue;
};
}  // namespace angle

#include "Error.inl"

#endif // LIBANGLE_ERROR_H_
