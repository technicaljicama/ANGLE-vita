//
// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// libEGL.cpp: Implements the exported EGL functions.

#include "libGLESv2/entry_points_egl.h"
#include "libGLESv2/entry_points_egl_ext.h"

extern "C" {

EGLBoolean EGLAPIENTRY aeglChooseConfig(EGLDisplay dpy,
                                       const EGLint *attrib_list,
                                       EGLConfig *configs,
                                       EGLint config_size,
                                       EGLint *num_config)
{
    return egl::ChooseConfig(dpy, attrib_list, configs, config_size, num_config);
}

EGLBoolean EGLAPIENTRY aeglCopyBuffers(EGLDisplay dpy,
                                      EGLSurface surface,
                                      EGLNativePixmapType target)
{
    return egl::CopyBuffers(dpy, surface, target);
}

EGLContext EGLAPIENTRY aeglCreateContext(EGLDisplay dpy,
                                        EGLConfig config,
                                        EGLContext share_context,
                                        const EGLint *attrib_list)
{
    return egl::CreateContext(dpy, config, share_context, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreatePbufferSurface(EGLDisplay dpy,
                                               EGLConfig config,
                                               const EGLint *attrib_list)
{
    return egl::CreatePbufferSurface(dpy, config, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreatePixmapSurface(EGLDisplay dpy,
                                              EGLConfig config,
                                              EGLNativePixmapType pixmap,
                                              const EGLint *attrib_list)
{
    return egl::CreatePixmapSurface(dpy, config, pixmap, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreateWindowSurface(EGLDisplay dpy,
                                              EGLConfig config,
                                              EGLNativeWindowType win,
                                              const EGLint *attrib_list)
{
    return egl::CreateWindowSurface(dpy, config, win, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
    return egl::DestroyContext(dpy, ctx);
}

EGLBoolean EGLAPIENTRY aeglDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
    return egl::DestroySurface(dpy, surface);
}

EGLBoolean EGLAPIENTRY aeglGetConfigAttrib(EGLDisplay dpy,
                                          EGLConfig config,
                                          EGLint attribute,
                                          EGLint *value)
{
    return egl::GetConfigAttrib(dpy, config, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglGetConfigs(EGLDisplay dpy,
                                     EGLConfig *configs,
                                     EGLint config_size,
                                     EGLint *num_config)
{
    return egl::GetConfigs(dpy, configs, config_size, num_config);
}

EGLDisplay EGLAPIENTRY aeglGetCurrentDisplay(void)
{
    return egl::GetCurrentDisplay();
}

EGLSurface EGLAPIENTRY aeglGetCurrentSurface(EGLint readdraw)
{
    return egl::GetCurrentSurface(readdraw);
}

EGLDisplay EGLAPIENTRY aeglGetDisplay(EGLNativeDisplayType display_id)
{
    return egl::GetDisplay(display_id);
}

EGLint EGLAPIENTRY aeglGetError(void)
{
    return egl::GetError();
}

EGLBoolean EGLAPIENTRY aeglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor)
{
    return egl::Initialize(dpy, major, minor);
}

EGLBoolean EGLAPIENTRY aeglMakeCurrent(EGLDisplay dpy,
                                      EGLSurface draw,
                                      EGLSurface read,
                                      EGLContext ctx)
{
    return egl::MakeCurrent(dpy, draw, read, ctx);
}

EGLBoolean EGLAPIENTRY aeglQueryContext(EGLDisplay dpy,
                                       EGLContext ctx,
                                       EGLint attribute,
                                       EGLint *value)
{
    return egl::QueryContext(dpy, ctx, attribute, value);
}

const char *EGLAPIENTRY aeglQueryString(EGLDisplay dpy, EGLint name)
{
    return egl::QueryString(dpy, name);
}

EGLBoolean EGLAPIENTRY aeglQuerySurface(EGLDisplay dpy,
                                       EGLSurface surface,
                                       EGLint attribute,
                                       EGLint *value)
{
    return egl::QuerySurface(dpy, surface, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    return egl::SwapBuffers(dpy, surface);
}

EGLBoolean EGLAPIENTRY aeglTerminate(EGLDisplay dpy)
{
    return egl::Terminate(dpy);
}

EGLBoolean EGLAPIENTRY aeglWaitGL(void)
{
    return egl::WaitGL();
}

EGLBoolean EGLAPIENTRY aeglWaitNative(EGLint engine)
{
    return egl::WaitNative(engine);
}

EGLBoolean EGLAPIENTRY aeglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    return egl::BindTexImage(dpy, surface, buffer);
}

EGLBoolean EGLAPIENTRY aeglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    return egl::ReleaseTexImage(dpy, surface, buffer);
}

EGLBoolean EGLAPIENTRY aeglSurfaceAttrib(EGLDisplay dpy,
                                        EGLSurface surface,
                                        EGLint attribute,
                                        EGLint value)
{
    return egl::SurfaceAttrib(dpy, surface, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglSwapInterval(EGLDisplay dpy, EGLint interval)
{
    return egl::SwapInterval(dpy, interval);
}

EGLBoolean EGLAPIENTRY aeglBindAPI(EGLenum api)
{
    return egl::BindAPI(api);
}

EGLenum EGLAPIENTRY aeglQueryAPI(void)
{
    return egl::QueryAPI();
}

EGLSurface EGLAPIENTRY aeglCreatePbufferFromClientBuffer(EGLDisplay dpy,
                                                        EGLenum buftype,
                                                        EGLClientBuffer buffer,
                                                        EGLConfig config,
                                                        const EGLint *attrib_list)
{
    return egl::CreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglReleaseThread(void)
{
    return egl::ReleaseThread();
}

EGLBoolean EGLAPIENTRY aeglWaitClient(void)
{
    return egl::WaitClient();
}

EGLContext EGLAPIENTRY aeglGetCurrentContext(void)
{
    return egl::GetCurrentContext();
}

EGLSync EGLAPIENTRY aeglCreateSync(EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list)
{
    return egl::CreateSync(dpy, type, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglDestroySync(EGLDisplay dpy, EGLSync sync)
{
    return egl::DestroySync(dpy, sync);
}

EGLint EGLAPIENTRY aeglClientWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout)
{
    return egl::ClientWaitSync(dpy, sync, flags, timeout);
}

EGLBoolean EGLAPIENTRY aeglGetSyncAttrib(EGLDisplay dpy,
                                        EGLSync sync,
                                        EGLint attribute,
                                        EGLAttrib *value)
{
    return egl::GetSyncAttrib(dpy, sync, attribute, value);
}

EGLImage EGLAPIENTRY aeglCreateImage(EGLDisplay dpy,
                                    EGLContext ctx,
                                    EGLenum target,
                                    EGLClientBuffer buffer,
                                    const EGLAttrib *attrib_list)
{
    return egl::CreateImage(dpy, ctx, target, buffer, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglDestroyImage(EGLDisplay dpy, EGLImage image)
{
    return egl::DestroyImage(dpy, image);
}

EGLDisplay EGLAPIENTRY aeglGetPlatformDisplay(EGLenum platform,
                                             void *native_display,
                                             const EGLAttrib *attrib_list)
{
    return egl::GetPlatformDisplay(platform, native_display, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreatePlatformWindowSurface(EGLDisplay dpy,
                                                      EGLConfig config,
                                                      void *native_window,
                                                      const EGLAttrib *attrib_list)
{
    return egl::CreatePlatformWindowSurface(dpy, config, native_window, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreatePlatformPixmapSurface(EGLDisplay dpy,
                                                      EGLConfig config,
                                                      void *native_pixmap,
                                                      const EGLAttrib *attrib_list)
{
    return egl::CreatePlatformPixmapSurface(dpy, config, native_pixmap, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags)
{
    return egl::WaitSync(dpy, sync, flags);
}

EGLBoolean EGLAPIENTRY aeglQuerySurfacePointerANGLE(EGLDisplay dpy,
                                                   EGLSurface surface,
                                                   EGLint attribute,
                                                   void **value)
{
    return egl::QuerySurfacePointerANGLE(dpy, surface, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglPostSubBufferNV(EGLDisplay dpy,
                                          EGLSurface surface,
                                          EGLint x,
                                          EGLint y,
                                          EGLint width,
                                          EGLint height)
{
    return egl::PostSubBufferNV(dpy, surface, x, y, width, height);
}

EGLDisplay EGLAPIENTRY aeglGetPlatformDisplayEXT(EGLenum platform,
                                                void *native_display,
                                                const EGLint *attrib_list)
{
    return egl::GetPlatformDisplayEXT(platform, native_display, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreatePlatformWindowSurfaceEXT(EGLDisplay dpy,
                                                         EGLConfig config,
                                                         void *native_window,
                                                         const EGLint *attrib_list)
{
    return egl::CreatePlatformWindowSurfaceEXT(dpy, config, native_window, attrib_list);
}

EGLSurface EGLAPIENTRY aeglCreatePlatformPixmapSurfaceEXT(EGLDisplay dpy,
                                                         EGLConfig config,
                                                         void *native_pixmap,
                                                         const EGLint *attrib_list)
{
    return egl::CreatePlatformPixmapSurfaceEXT(dpy, config, native_pixmap, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglQueryDisplayAttribEXT(EGLDisplay dpy, EGLint attribute, EGLAttrib *value)
{
    return egl::QueryDisplayAttribEXT(dpy, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglQueryDeviceAttribEXT(EGLDeviceEXT device,
                                               EGLint attribute,
                                               EGLAttrib *value)
{
    return egl::QueryDeviceAttribEXT(device, attribute, value);
}

const char *EGLAPIENTRY aeglQueryDeviceStringEXT(EGLDeviceEXT device, EGLint name)
{
    return egl::QueryDeviceStringEXT(device, name);
}

EGLImageKHR EGLAPIENTRY aeglCreateImageKHR(EGLDisplay dpy,
                                          EGLContext ctx,
                                          EGLenum target,
                                          EGLClientBuffer buffer,
                                          const EGLint *attrib_list)
{
    return egl::CreateImageKHR(dpy, ctx, target, buffer, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglDestroyImageKHR(EGLDisplay dpy, EGLImageKHR image)
{
    return egl::DestroyImageKHR(dpy, image);
}

EGLDeviceEXT EGLAPIENTRY aeglCreateDeviceANGLE(EGLint device_type,
                                              void *native_device,
                                              const EGLAttrib *attrib_list)
{
    return egl::CreateDeviceANGLE(device_type, native_device, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglReleaseDeviceANGLE(EGLDeviceEXT device)
{
    return egl::ReleaseDeviceANGLE(device);
}

__eglMustCastToProperFunctionPointerType EGLAPIENTRY aeglGetProcAddress(const char *procname)
{
    return egl::GetProcAddress(procname);
}

EGLStreamKHR EGLAPIENTRY aeglCreateStreamKHR(EGLDisplay dpy, const EGLint *attrib_list)
{
    return egl::CreateStreamKHR(dpy, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglDestroyStreamKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return egl::DestroyStreamKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY aeglStreamAttribKHR(EGLDisplay dpy,
                                          EGLStreamKHR stream,
                                          EGLenum attribute,
                                          EGLint value)
{
    return egl::StreamAttribKHR(dpy, stream, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglQueryStreamKHR(EGLDisplay dpy,
                                         EGLStreamKHR stream,
                                         EGLenum attribute,
                                         EGLint *value)
{
    return egl::QueryStreamKHR(dpy, stream, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglQueryStreamu64KHR(EGLDisplay dpy,
                                            EGLStreamKHR stream,
                                            EGLenum attribute,
                                            EGLuint64KHR *value)
{
    return egl::QueryStreamu64KHR(dpy, stream, attribute, value);
}

EGLBoolean EGLAPIENTRY aeglStreamConsumerGLTextureExternalKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return egl::StreamConsumerGLTextureExternalKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY aeglStreamConsumerAcquireKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return egl::StreamConsumerAcquireKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY aeglStreamConsumerReleaseKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return egl::StreamConsumerReleaseKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY aeglStreamConsumerGLTextureExternalAttribsNV(EGLDisplay dpy,
                                                                   EGLStreamKHR stream,
                                                                   const EGLAttrib *attrib_list)
{
    return egl::StreamConsumerGLTextureExternalAttribsNV(dpy, stream, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglCreateStreamProducerD3DTextureANGLE(EGLDisplay dpy,
                                                              EGLStreamKHR stream,
                                                              const EGLAttrib *attrib_list)
{
    return egl::CreateStreamProducerD3DTextureANGLE(dpy, stream, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglStreamPostD3DTextureANGLE(EGLDisplay dpy,
                                                    EGLStreamKHR stream,
                                                    void *texture,
                                                    const EGLAttrib *attrib_list)
{
    return egl::StreamPostD3DTextureANGLE(dpy, stream, texture, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglGetSyncValuesCHROMIUM(EGLDisplay dpy,
                                                EGLSurface surface,
                                                EGLuint64KHR *ust,
                                                EGLuint64KHR *msc,
                                                EGLuint64KHR *sbc)
{
    return egl::GetSyncValuesCHROMIUM(dpy, surface, ust, msc, sbc);
}

EGLBoolean EGLAPIENTRY aeglSwapBuffersWithDamageKHR(EGLDisplay dpy,
                                                   EGLSurface surface,
                                                   EGLint *rects,
                                                   EGLint n_rects)
{
    return egl::SwapBuffersWithDamageKHR(dpy, surface, rects, n_rects);
}

EGLBoolean EGLAPIENTRY aeglPresentationTimeANDROID(EGLDisplay dpy,
                                                  EGLSurface surface,
                                                  EGLnsecsANDROID time)
{
    return egl::PresentationTimeANDROID(dpy, surface, time);
}

EGLint EGLAPIENTRY aeglProgramCacheGetAttribANGLE(EGLDisplay dpy, EGLenum attrib)
{
    return egl::ProgramCacheGetAttribANGLE(dpy, attrib);
}

void EGLAPIENTRY aeglProgramCacheQueryANGLE(EGLDisplay dpy,
                                           EGLint index,
                                           void *key,
                                           EGLint *keysize,
                                           void *binary,
                                           EGLint *binarysize)
{
    egl::ProgramCacheQueryANGLE(dpy, index, key, keysize, binary, binarysize);
}

void EGLAPIENTRY aeglProgramCachePopulateANGLE(EGLDisplay dpy,
                                              const void *key,
                                              EGLint keysize,
                                              const void *binary,
                                              EGLint binarysize)
{
    egl::ProgramCachePopulateANGLE(dpy, key, keysize, binary, binarysize);
}

EGLint EGLAPIENTRY aeglProgramCacheResizeANGLE(EGLDisplay dpy, EGLint limit, EGLenum mode)
{
    return egl::ProgramCacheResizeANGLE(dpy, limit, mode);
}

EGLint EGLAPIENTRY aeglDebugMessageControlKHR(EGLDEBUGPROCKHR callback, const EGLAttrib *attrib_list)
{
    return egl::DebugMessageControlKHR(callback, attrib_list);
}

EGLBoolean EGLAPIENTRY aeglQueryDebugKHR(EGLint attribute, EGLAttrib *value)
{
    return egl::QueryDebugKHR(attribute, value);
}

EGLint EGLAPIENTRY aeglLabelObjectKHR(EGLDisplay dpy,
                                     EGLenum objectType,
                                     EGLObjectKHR object,
                                     EGLLabelKHR label)
{
    return egl::LabelObjectKHR(dpy, objectType, object, label);
}

void EGLAPIENTRY aeglSetBlobCacheFuncsANDROID(EGLDisplay dpy,
                                             EGLSetBlobFuncANDROID set,
                                             EGLGetBlobFuncANDROID get)
{
    return egl::SetBlobCacheFuncsANDROID(dpy, set, get);
}

}  // extern "C"
