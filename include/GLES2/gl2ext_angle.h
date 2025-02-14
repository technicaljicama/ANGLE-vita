//
// Copyright (c) 2017 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// gl2ext_angle.h: ANGLE modifications to the gl2ext.h header file.
//   Currently we don't include this file directly, we patch gl2ext.h
//   to include it implicitly so it is visible throughout our code.

#ifndef INCLUDE_GLES2_GL2EXT_ANGLE_H_
#define INCLUDE_GLES2_GL2EXT_ANGLE_H_

// clang-format off

#ifndef GL_ANGLE_client_arrays
#define GL_ANGLE_client_arrays 1
#define GL_CLIENT_ARRAYS_ANGLE 0x93AA
#endif /* GL_ANGLE_client_arrays */

#ifndef GL_ANGLE_request_extension
#define GL_ANGLE_request_extension 1
#define GL_REQUESTABLE_EXTENSIONS_ANGLE   0x93A8
#define GL_NUM_REQUESTABLE_EXTENSIONS_ANGLE 0x93A8
typedef void (GL_APIENTRYP PFNGLREQUESTEXTENSIONANGLEPROC) (const GLchar *name);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glRequestExtensionANGLE (const GLchar *name);
#endif
#endif /* GL_ANGLE_webgl_compatibility */

#ifndef GL_ANGLE_robust_resource_initialization
#define GL_ANGLE_robust_resource_initialization 1
#define GL_ROBUST_RESOURCE_INITIALIZATION_ANGLE 0x93AB
#endif /* GL_ANGLE_robust_resource_initialization */

#ifndef GL_CHROMIUM_framebuffer_mixed_samples
#define GL_CHROMIUM_frambuffer_mixed_samples 1
#define GL_COVERAGE_MODULATION_CHROMIUM 0x9332
typedef void (GL_APIENTRYP PFNGLCOVERAGEMODULATIONCHROMIUMPROC) (GLenum components);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCoverageModulationCHROMIUM(GLenum components);
#endif
#endif /* GL_CHROMIUM_framebuffer_mixed_samples */

#ifndef GL_CHROMIUM_bind_generates_resource
#define GL_CHROMIUM_bind_generates_resource 1
#define GL_BIND_GENERATES_RESOURCE_CHROMIUM 0x9244
#endif /* GL_CHROMIUM_bind_generates_resource */

#ifndef GL_ANGLE_memory_size
#define GL_ANGLE_memory_size
#define GL_MEMORY_SIZE_ANGLE 0x93AD
#endif /* GL_ANGLE_memory_size */

// needed by NV_path_rendering (and thus CHROMIUM_path_rendering)
// but CHROMIUM_path_rendering only needs MatrixLoadfEXT, MatrixLoadIdentityEXT
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
typedef void(GL_APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum matrixMode, const GLfloat *m);
typedef void(GL_APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum matrixMode);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glMatrixLoadfEXT(GLenum matrixMode, const GLfloat *m);
GL_APICALL void GL_APIENTRY glMatrixLoadIdentityEXT(GLenum matrixMode);
#endif
#endif /* GL_EXT_direct_state_access */

#ifndef GL_CHROMIUM_path_rendering
#define GL_CHROMIUM_path_rendering 1
#define GL_PATH_MODELVIEW_CHROMIUM 0x1700
#define GL_PATH_PROJECTION_CHROMIUM 0x1701
#define GL_CLOSE_PATH_CHROMIUM 0x00
#define GL_MOVE_TO_CHROMIUM 0x02
#define GL_LINE_TO_CHROMIUM 0x04
#define GL_QUADRATIC_CURVE_TO_CHROMIUM 0x0A
#define GL_CUBIC_CURVE_TO_CHROMIUM 0x0C
#define GL_CONIC_CURVE_TO_CHROMIUM 0x1A
#define GL_PATH_MODELVIEW_MATRIX_CHROMIUM 0x0BA6
#define GL_PATH_PROJECTION_MATRIX_CHROMIUM 0x0BA7
#define GL_PATH_STROKE_WIDTH_CHROMIUM 0x9075
#define GL_PATH_END_CAPS_CHROMIUM 0x9076
#define GL_PATH_JOIN_STYLE_CHROMIUM 0x9079
#define GL_PATH_MITER_LIMIT_CHROMIUM 0x907a
#define GL_PATH_STROKE_BOUND_CHROMIUM 0x9086
#define GL_FLAT_CHROMIUM 0x1D00
#define GL_SQUARE_CHROMIUM 0x90a3
#define GL_ROUND_CHROMIUM 0x90a4
#define GL_BEVEL_CHROMIUM 0x90A6
#define GL_MITER_REVERT_CHROMIUM 0x90A7
#define GL_COUNT_UP_CHROMIUM 0x9088
#define GL_COUNT_DOWN_CHROMIUM 0x9089
#define GL_CONVEX_HULL_CHROMIUM 0x908B
#define GL_BOUNDING_BOX_CHROMIUM 0x908D
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_CHROMIUM 0x909C
#define GL_EYE_LINEAR_CHROMIUM 0x2400
#define GL_OBJECT_LINEAR_CHROMIUM 0x2401
#define GL_CONSTANT_CHROMIUM 0x8576
#define GL_TRANSLATE_X_CHROMIUM 0x908E
#define GL_TRANSLATE_Y_CHROMIUM 0x908F
#define GL_TRANSLATE_2D_CHROMIUM 0x9090
#define GL_TRANSLATE_3D_CHROMIUM 0x9091
#define GL_AFFINE_2D_CHROMIUM 0x9092
#define GL_AFFINE_3D_CHROMIUM 0x9094
#define GL_TRANSPOSE_AFFINE_2D_CHROMIUM 0x9096
#define GL_TRANSPOSE_AFFINE_3D_CHROMIUM 0x9098
typedef void(GL_APIENTRYP PFNGLMATRIXLOADFCHROMIUMPROC)(GLenum matrixMode, const GLfloat *m);
typedef void(GL_APIENTRYP PFNGLMATRIXLOADIDENTITYCHROMIUMPROC)(GLenum matrixMode);
typedef GLuint(GL_APIENTRYP PFNGLGENPATHSCHROMIUMPROC)(GLsizei range);
typedef void(GL_APIENTRYP PFNGLDELETEPATHSCHROMIUMPROC)(GLuint path, GLsizei range);
typedef GLboolean(GL_APIENTRYP PFNGLISPATHCHROMIUMPROC)(GLuint path);
typedef void(GL_APIENTRYP PFNGLPATHCOMMANDSCHROMIUMPROC)(GLuint path,
                                                         GLsizei numCommands,
                                                         const GLubyte *commands,
                                                         GLsizei numCoords,
                                                         GLenum coordType,
                                                         const void *coords);
typedef void(GL_APIENTRYP PFNGLPATHPARAMETERICHROMIUMPROC)(GLuint path, GLenum pname, GLint value);
typedef void(GL_APIENTRYP PFNGLPATHPARAMETERFCHROMIUMPROC)(GLuint path,
                                                           GLenum pname,
                                                           GLfloat value);
typedef void(GL_APIENTRYP PFNGLGETPATHPARAMETERIVCHROMIUMPROC)(GLuint path,
                                                               GLenum pname,
                                                               GLint *value);
typedef void(GL_APIENTRYP PFNGLGETPATHPARAMETERFVCHROMIUMPROC)(GLuint path,
                                                               GLenum pname,
                                                               GLfloat *value);
typedef void(GL_APIENTRYP PFNGLPATHSTENCILFUNCCHROMIUMPROC)(GLenum func, GLint ref, GLuint mask);
typedef void(GL_APIENTRYP PFNGLSTENCILFILLPATHCHROMIUMPROC)(GLuint path,
                                                            GLenum fillMode,
                                                            GLuint mask);
typedef void(GL_APIENTRYP PFNGLSTENCILSTROKEPATHCHROMIUMPROC)(GLuint path,
                                                              GLint reference,
                                                              GLuint mask);
typedef void(GL_APIENTRYP PFNGLCOVERFILLPATHCHROMIUMPROC)(GLuint path, GLenum coverMode);
typedef void(GL_APIENTRYP PFNGLCOVERSTROKEPATHCHROMIUMPROC)(GLuint path, GLenum coverMode);
typedef void(GL_APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHCHROMIUMPROC)(GLuint path,
                                                                     GLenum fillMode,
                                                                     GLuint mask,
                                                                     GLenum coverMode);
typedef void(GL_APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHCHROMIUMPROC)(GLuint path,
                                                                       GLint reference,
                                                                       GLuint mask,
                                                                       GLenum coverMode);
typedef void(GL_APIENTRYP PFNGLCOVERFILLPATHINSTANCEDCHROMIUMPROC)(GLsizei numPaths,
                                                                   GLenum pathNameType,
                                                                   const void *paths,
                                                                   GLuint pathBase,
                                                                   GLenum coverMode,
                                                                   GLenum transformType,
                                                                   const GLfloat *transformValues);
typedef void(GL_APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDCHROMIUMPROC)(
    GLsizei numPaths,
    GLenum pathNameType,
    const void *paths,
    GLuint pathBase,
    GLenum coverMode,
    GLenum transformType,
    const GLfloat *transformValues);
typedef void(GL_APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDCHROMIUMPROC)(
    GLsizei numPaths,
    GLenum pathNameType,
    const void *paths,
    GLuint pathBase,
    GLenum fillMode,
    GLuint mask,
    GLenum transformType,
    const GLfloat *transformValues);
typedef void(GL_APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDCHROMIUMPROC)(
    GLsizei numPaths,
    GLenum pathNameType,
    const void *paths,
    GLuint pathBase,
    GLint reference,
    GLuint mask,
    GLenum transformType,
    const GLfloat *transformValues);
typedef void(GL_APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDCHROMIUMPROC)(
    GLsizei numPaths,
    GLenum pathNameType,
    const void *paths,
    GLuint pathBase,
    GLenum fillMode,
    GLuint mask,
    GLenum coverMode,
    GLenum transformType,
    const GLfloat *transformValues);
typedef void(GL_APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDCHROMIUMPROC)(
    GLsizei numPaths,
    GLenum pathNameType,
    const void *paths,
    GLuint pathBase,
    GLint reference,
    GLuint mask,
    GLenum coverMode,
    GLenum transformType,
    const GLfloat *transformValues);

typedef void(GL_APIENTRY PFNGLBINDFRAGMENTINPUTLOCATIONCHROMIUMPROC)(GLuint program,
                                                                     GLint location,
                                                                     const GLchar *name);
typedef void(GL_APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENCHROMIUMPROC)(GLuint program,
                                                                        GLint location,
                                                                        GLenum genMode,
                                                                        GLint components,
                                                                        const GLfloat *coeffs);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glMatrixLoadfCHROMIUM(GLenum matrixMode, const GLfloat *m);
GL_APICALL void GL_APIENTRY glMatrixLoadIdentityCHROMIUM(GLenum matrixMode);
GL_APICALL GLuint GL_APIENTRY glGenPathsCHROMIUM(GLsizei range);
GL_APICALL void GL_APIENTRY glDeletePathsCHROMIUM(GLuint path, GLsizei range);
GL_APICALL GLboolean GL_APIENTRY glIsPathCHROMIUM(GLuint path);
GL_APICALL void GL_APIENTRY glPathCommandsCHROMIUM(GLuint path,
                                                   GLsizei numCommands,
                                                   const GLubyte *commands,
                                                   GLsizei numCoords,
                                                   GLenum coordType,
                                                   const void *coords);
GL_APICALL void GL_APIENTRY glPathParameteriCHROMIUM(GLuint path, GLenum pname, GLint value);
GL_APICALL void GL_APIENTRY glPathParameterfCHROMIUM(GLuint path, GLenum pname, GLfloat value);
GL_APICALL void GL_APIENTRY glGetPathParameterivCHROMIUM(GLuint path, GLenum pname, GLint *value);
GL_APICALL void GL_APIENTRY glGetPathParameterfvCHROMIUM(GLuint path, GLenum pname, GLfloat *value);
GL_APICALL void GL_APIENTRY glPathStencilFuncCHROMIUM(GLenum func, GLint ref, GLuint mask);
GL_APICALL void GL_APIENTRY glStencilFillPathCHROMIUM(GLuint path, GLenum fillMode, GLuint mask);
GL_APICALL void GL_APIENTRY glStencilStrokePathCHROMIUM(GLuint path, GLint reference, GLuint mask);
GL_APICALL void GL_APIENTRY glCoverFillPathCHROMIUM(GLuint path, GLenum coverMode);
GL_APICALL void GL_APIENTRY glCoverStrokePathCHROMIUM(GLuint path, GLenum coverMode);
GL_APICALL void GL_APIENTRY glStencilThenCoverFillPathCHROMIUM(GLuint path,
                                                               GLenum fillMode,
                                                               GLuint mask,
                                                               GLenum coverMode);
GL_APICALL void GL_APIENTRY glStencilThenCoverStrokePathCHROMIUM(GLuint path,
                                                                 GLint reference,
                                                                 GLuint mask,
                                                                 GLenum coverMode);
GL_APICALL void GL_APIENTRY glCoverFillPathInstancedCHROMIUM(GLsizei numPaths,
                                                             GLenum pathNameType,
                                                             const void *paths,
                                                             GLuint pathBase,
                                                             GLenum coverMode,
                                                             GLenum transformType,
                                                             const GLfloat *transformValues);
GL_APICALL void GL_APIENTRY glCoverStrokePathInstancedCHROMIUM(GLsizei numPaths,
                                                               GLenum pathNameType,
                                                               const void *paths,
                                                               GLuint pathBase,
                                                               GLenum coverMode,
                                                               GLenum transformType,
                                                               const GLfloat *transformValues);
GL_APICALL void GL_APIENTRY glStencilFillPathInstancedCHROMIUM(GLsizei numPaths,
                                                               GLenum pathNameType,
                                                               const void *paths,
                                                               GLuint pathBase,
                                                               GLenum fillMode,
                                                               GLuint mask,
                                                               GLenum transformType,
                                                               const GLfloat *transformValues);
GL_APICALL void GL_APIENTRY glStencilStrokePathInstancedCHROMIUM(GLsizei numPaths,
                                                                 GLenum pathNameType,
                                                                 const void *paths,
                                                                 GLuint pathBase,
                                                                 GLint reference,
                                                                 GLuint mask,
                                                                 GLenum transformType,
                                                                 const GLfloat *transformValues);
GL_APICALL void GL_APIENTRY
glStencilThenCoverFillPathInstancedCHROMIUM(GLsizei numPaths,
                                            GLenum pathNameType,
                                            const void *paths,
                                            GLuint pathBase,
                                            GLenum fillMode,
                                            GLuint mask,
                                            GLenum coverMode,
                                            GLenum transformType,
                                            const GLfloat *transformValues);

GL_APICALL void GL_APIENTRY
glStencilThenCoverStrokePathInstancedCHROMIUM(GLsizei numPaths,
                                              GLenum pathNameType,
                                              const void *paths,
                                              GLuint pathBase,
                                              GLint reference,
                                              GLuint mask,
                                              GLenum coverMode,
                                              GLenum transformType,
                                              const GLfloat *transformValues);

GL_APICALL void GL_APIENTRY glBindFragmentInputLocationCHROMIUM(GLuint program,
                                                                GLint location,
                                                                const GLchar *name);
GL_APICALL void GL_APIENTRY glProgramPathFragmentInputGenCHROMIUM(GLuint program,
                                                                  GLint location,
                                                                  GLenum genMode,
                                                                  GLint components,
                                                                  const GLfloat *coeffs);

#endif
#endif /* GL_CHROMIUM_path_rendering */

#ifndef GL_CHROMIUM_copy_texture
#define GL_CHROMIUM_copy_texture 1
typedef void(GL_APIENTRYP PFNGLCOPYTEXTURECHROMIUMPROC)(GLuint sourceId,
                                                        GLint sourceLevel,
                                                        GLenum destTarget,
                                                        GLuint destId,
                                                        GLint destLevel,
                                                        GLint internalFormat,
                                                        GLenum destType,
                                                        GLboolean unpackFlipY,
                                                        GLboolean unpackPremultiplyAlpha,
                                                        GLboolean unpackUnmultiplyAlpha);
typedef void(GL_APIENTRYP PFNGLCOPYSUBTEXTURECHROMIUMPROC)(GLuint sourceId,
                                                           GLint sourceLevel,
                                                           GLenum destTarget,
                                                           GLuint destId,
                                                           GLint destLevel,
                                                           GLint xoffset,
                                                           GLint yoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLsizei width,
                                                           GLsizei height,
                                                           GLboolean unpackFlipY,
                                                           GLboolean unpackPremultiplyAlpha,
                                                           GLboolean unpackUnmultiplyAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCopyTextureCHROMIUM(GLuint sourceId,
                                                  GLint sourceLevel,
                                                  GLenum destTarget,
                                                  GLuint destId,
                                                  GLint destLevel,
                                                  GLint internalFormat,
                                                  GLenum destType,
                                                  GLboolean unpackFlipY,
                                                  GLboolean unpackPremultiplyAlpha,
                                                  GLboolean unpackUnmultiplyAlpha);
GL_APICALL void GL_APIENTRY glCopySubTextureCHROMIUM(GLuint sourceId,
                                                     GLint sourceLevel,
                                                     GLenum destTarget,
                                                     GLuint destId,
                                                     GLint destLevel,
                                                     GLint xoffset,
                                                     GLint yoffset,
                                                     GLint x,
                                                     GLint y,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLboolean unpackFlipY,
                                                     GLboolean unpackPremultiplyAlpha,
                                                     GLboolean unpackUnmultiplyAlpha);
#endif
#endif /* GL_CHROMIUM_copy_texture */

#ifndef GL_CHROMIUM_compressed_copy_texture
#define GL_CHROMIUM_compressed_copy_texture 1
typedef void(GL_APIENTRYP PFNGLCOMPRESSEDCOPYTEXTURECHROMIUMPROC)(GLuint sourceId, GLuint destId);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCompressedCopyTextureCHROMIUM(GLuint sourceId, GLuint destId);
#endif
#endif /* GL_CHROMIUM_compressed_copy_texture */


#ifndef GL_ANGLE_copy_texture_3d
#define GL_ANGLE_copy_texture_3d 1
typedef void(GL_APIENTRYP PFNGLCOPYTEXTURE3DANGLEPROC)(GLuint sourceId,
                                                        GLint sourceLevel,
                                                        GLenum destTarget,
                                                        GLuint destId,
                                                        GLint destLevel,
                                                        GLint internalFormat,
                                                        GLenum destType,
                                                        GLboolean unpackFlipY,
                                                        GLboolean unpackPremultiplyAlpha,
                                                        GLboolean unpackUnmultiplyAlpha);
typedef void(GL_APIENTRYP PFNGLCOPYSUBTEXTURE3DANGLEPROC)(GLuint sourceId,
                                                           GLint sourceLevel,
                                                           GLenum destTarget,
                                                           GLuint destId,
                                                           GLint destLevel,
                                                           GLint xoffset,
                                                           GLint yoffset,
                                                           GLint zoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLint z,
                                                           GLsizei width,
                                                           GLsizei height,
                                                           GLsizei depth,
                                                           GLboolean unpackFlipY,
                                                           GLboolean unpackPremultiplyAlpha,
                                                           GLboolean unpackUnmultiplyAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCopyTexture3DANGLE(GLuint sourceId,
                                                  GLint sourceLevel,
                                                  GLenum destTarget,
                                                  GLuint destId,
                                                  GLint destLevel,
                                                  GLint internalFormat,
                                                  GLenum destType,
                                                  GLboolean unpackFlipY,
                                                  GLboolean unpackPremultiplyAlpha,
                                                  GLboolean unpackUnmultiplyAlpha);
GL_APICALL void GL_APIENTRY glCopySubTexture3DANGLE(GLuint sourceId,
                                                     GLint sourceLevel,
                                                     GLenum destTarget,
                                                     GLuint destId,
                                                     GLint destLevel,
                                                     GLint xoffset,
                                                     GLint yoffset,
                                                     GLint zoffset,
                                                     GLint x,
                                                     GLint y,
                                                     GLint z,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLsizei depth,
                                                     GLboolean unpackFlipY,
                                                     GLboolean unpackPremultiplyAlpha,
                                                     GLboolean unpackUnmultiplyAlpha);
#endif
#endif /* GL_ANGLE_copy_texture_3d */

#ifndef GL_CHROMIUM_sync_query
#define GL_CHROMIUM_sync_query 1
#define GL_COMMANDS_COMPLETED_CHROMIUM    0x84F7
#endif  /* GL_CHROMIUM_sync_query */

#ifndef GL_EXT_texture_compression_s3tc_srgb
#define GL_EXT_texture_compression_s3tc_srgb 1
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT  0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#endif /* GL_EXT_texture_compression_s3tc_srgb */

#ifndef GL_ANGLE_lossy_etc_decode
#define GL_ANGLE_lossy_etc_decode 1
#define GL_ETC1_RGB8_LOSSY_DECODE_ANGLE                                  0x9690
#define GL_COMPRESSED_R11_LOSSY_DECODE_EAC_ANGLE                         0x9691
#define GL_COMPRESSED_SIGNED_R11_LOSSY_DECODE_EAC_ANGLE                  0x9692
#define GL_COMPRESSED_RG11_LOSSY_DECODE_EAC_ANGLE                        0x9693
#define GL_COMPRESSED_SIGNED_RG11_LOSSY_DECODE_EAC_ANGLE                 0x9694
#define GL_COMPRESSED_RGB8_LOSSY_DECODE_ETC2_ANGLE                       0x9695
#define GL_COMPRESSED_SRGB8_LOSSY_DECODE_ETC2_ANGLE                      0x9696
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_LOSSY_DECODE_ETC2_ANGLE   0x9697
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_LOSSY_DECODE_ETC2_ANGLE  0x9698
#define GL_COMPRESSED_RGBA8_LOSSY_DECODE_ETC2_EAC_ANGLE                  0x9699
#define GL_COMPRESSED_SRGB8_ALPHA8_LOSSY_DECODE_ETC2_EAC_ANGLE           0x969A
#endif /* GL_ANGLE_lossy_etc_decode */

#ifndef GL_ANGLE_robust_client_memory
#define GL_ANGLE_robust_client_memory 1
typedef void (GL_APIENTRYP PFNGLGETBOOLEANVROBUSTANGLE) (GLenum pname, GLsizei bufSize, GLsizei *length, GLboolean *data);
typedef void (GL_APIENTRYP PFNGLGETBUFFERPARAMETERIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETFLOATVROBUSTANGLE) (GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *data);
typedef void (GL_APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVROBUSTANGLE) (GLenum target, GLenum attachment, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETINTEGERVROBUSTANGLE) (GLenum pname, GLsizei bufSize, GLsizei *length, GLint *data);
typedef void (GL_APIENTRYP PFNGLGETPROGRAMIVROBUSTANGLE) (GLuint program, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETSHADERIVROBUSTANGLE) (GLuint shader, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERFVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETUNIFORMFVROBUSTANGLE) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETUNIFORMIVROBUSTANGLE) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBFVROBUSTANGLE) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBIVROBUSTANGLE) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVROBUSTANGLE) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, void **pointer);
typedef void (GL_APIENTRYP PFNGLREADPIXELSROBUSTANGLE) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXIMAGE2DROBUSTANGLE) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERFVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, const GLfloat *params);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
typedef void (GL_APIENTRYP PFNGLTEXSUBIMAGE2DROBUSTANGLE) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXIMAGE3DROBUSTANGLE) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXSUBIMAGE3DROBUSTANGLE) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DROBUSTANGLE) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DROBUSTANGLE) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DROBUSTANGLE) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DROBUSTANGLE) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLGETQUERYIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTUIVROBUSTANGLE) (GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETBUFFERPOINTERVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
typedef void (GL_APIENTRYP PFNGLGETINTEGERI_VROBUSTANGLE) (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint *data);
typedef void (GL_APIENTRYP PFNGETINTERNALFORMATIVROBUSTANGLE) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBIIVROBUSTANGLE) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBIUIVROBUSTANGLE) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETUNIFORMUIVROBUSTANGLE) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVROBUSTANGLE) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETINTEGER64VROBUSTANGLE) (GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *data);
typedef void (GL_APIENTRYP PFNGLGETINTEGER64I_VROBUSTANGLE) (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint64 *data);
typedef void (GL_APIENTRYP PFNGLGETBUFFERPARAMETERI64VROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERIVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERFVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLfloat *param);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERIVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERFVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETPROGRAMINTERFACEIVROBUSTANGLE) (GLuint program, GLenum programInterface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETBOOLEANI_VROBUSTANGLE) (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLboolean *data);
typedef void (GL_APIENTRYP PFNGLGETMULTISAMPLEFVROBUSTANGLE) (GLenum pname, GLuint index, GLsizei bufSize, GLsizei *length, GLfloat *val);
typedef void (GL_APIENTRYP PFNGLGETTEXLEVELPARAMETERIVROBUSTANGLE) (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXLEVELPARAMETERFVROBUSTANGLE) (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETPOINTERVROBUSTANGLEROBUSTANGLE) (GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
typedef void (GL_APIENTRYP PFNGLREADNPIXELSROBUSTANGLE) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *data);
typedef void (GL_APIENTRYP PFNGLGETNUNIFORMFVROBUSTANGLE) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETNUNIFORMIVROBUSTANGLE) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETNUNIFORMUIVROBUSTANGLE) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERIIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERIUIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, const GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERIIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERIUIVROBUSTANGLE) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERIIVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERIUIVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLuint *param);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERIIVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVROBUSTANGLE) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTIVROBUSTANGLE)(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTI64VROBUSTANGLE)(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTUI64VROBUSTANGLE)(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint64 *params);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glGetBooleanvRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLboolean *data);
GL_APICALL void GL_APIENTRY glGetBufferParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetFloatvRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *data);
GL_APICALL void GL_APIENTRY glGetFramebufferAttachmentParameterivRobustANGLE (GLenum target, GLenum attachment, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetIntegervRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLint *data);
GL_APICALL void GL_APIENTRY glGetProgramivRobustANGLE (GLuint program, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetRenderbufferParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetShaderivRobustANGLE (GLuint shader, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetTexParameterfvRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetTexParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetUniformfvRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetUniformivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribfvRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribivRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribPointervRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, void **pointer);
GL_APICALL void GL_APIENTRY glReadPixelsRobustANGLE (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *pixels);
GL_APICALL void GL_APIENTRY glTexImage2DRobustANGLE (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glTexParameterfvRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLfloat *params);
GL_APICALL void GL_APIENTRY glTexParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
GL_APICALL void GL_APIENTRY glTexSubImage2DRobustANGLE (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glTexImage3DRobustANGLE (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glTexSubImage3DRobustANGLE (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glCompressedTexImage2DRobustANGLE(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glCompressedTexSubImage2DRobustANGLE(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glCompressedTexImage3DRobustANGLE(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glCompressedTexSubImage3DRobustANGLE(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glGetQueryivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetQueryObjectuivRobustANGLE (GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetBufferPointervRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
GL_APICALL void GL_APIENTRY glGetIntegeri_vRobustANGLE (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint *data);
GL_APICALL void GL_APIENTRY glGetInternalformativRobustANGLE (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribIivRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribIuivRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetUniformuivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetActiveUniformBlockivRobustANGLE (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetInteger64vRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *data);
GL_APICALL void GL_APIENTRY glGetInteger64i_vRobustANGLE (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint64 *data);
GL_APICALL void GL_APIENTRY glGetBufferParameteri64vRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
GL_APICALL void GL_APIENTRY glSamplerParameterivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
GL_APICALL void GL_APIENTRY glSamplerParameterfvRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLfloat *param);
GL_APICALL void GL_APIENTRY glGetSamplerParameterivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetSamplerParameterfvRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetFramebufferParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetProgramInterfaceivRobustANGLE (GLuint program, GLenum programInterface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetBooleani_vRobustANGLE (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLboolean *data);
GL_APICALL void GL_APIENTRY glGetMultisamplefvRobustANGLE (GLenum pname, GLuint index, GLsizei bufSize, GLsizei *length, GLfloat *val);
GL_APICALL void GL_APIENTRY glGetTexLevelParameterivRobustANGLE (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetTexLevelParameterfvRobustANGLE (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetPointervRobustANGLERobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
GL_APICALL void GL_APIENTRY glReadnPixelsRobustANGLE (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *data);
GL_APICALL void GL_APIENTRY glGetnUniformfvRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetnUniformivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetnUniformuivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glTexParameterIivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
GL_APICALL void GL_APIENTRY glTexParameterIuivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLuint *params);
GL_APICALL void GL_APIENTRY glGetTexParameterIivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetTexParameterIuivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glSamplerParameterIivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
GL_APICALL void GL_APIENTRY glSamplerParameterIuivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLuint *param);
GL_APICALL void GL_APIENTRY glGetSamplerParameterIivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetSamplerParameterIuivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetQueryObjectivRobustANGLE(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetQueryObjecti64vRobustANGLE(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
GL_APICALL void GL_APIENTRY glGetQueryObjectui64vRobustANGLE(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint64 *params);
#endif
#endif /* GL_ANGLE_robust_client_memory */

#ifndef GL_ANGLE_program_cache_control
#define GL_ANGLE_program_cache_control 1
#define GL_PROGRAM_CACHE_ENABLED_ANGLE 0x93AC
#endif  /* GL_ANGLE_program_cache_control */

#ifndef GL_ANGLE_multiview
#define GL_ANGLE_multiview 1
// The next four enums coincide with the enums introduced by the GL_OVR_multiview extension and use the values reserved by that extension.
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_ANGLE 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_ANGLE 0x9632
#define GL_MAX_VIEWS_ANGLE 0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_ANGLE 0x9633
// The next four enums are reserved specifically for ANGLE.
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_VIEWPORT_OFFSETS_ANGLE 0x969B
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_MULTIVIEW_LAYOUT_ANGLE 0x969C
#define GL_FRAMEBUFFER_MULTIVIEW_SIDE_BY_SIDE_ANGLE 0x969D
#define GL_FRAMEBUFFER_MULTIVIEW_LAYERED_ANGLE 0x969E
typedef void(GL_APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWLAYEREDANGLE)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
typedef void(GL_APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWSIDEBYSIDEANGLE)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLsizei numViews, const GLint *viewportOffsets);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glFramebufferTextureMultiviewLayeredANGLE(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
GL_APICALL void GL_APIENTRY glFramebufferTextureMultiviewSideBySideANGLE(GLenum target, GLenum attachment, GLuint texture, GLint level, GLsizei numViews, const GLint *viewportOffsets);
#endif
#endif /* GL_ANGLE_multiview */

#ifndef GL_ANGLE_texture_rectangle
#define GL_ANGLE_texture_rectangle 1
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ANGLE 0x84F8
#define GL_TEXTURE_RECTANGLE_ANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ANGLE 0x84F6
#define GL_SAMPLER_2D_RECT_ANGLE 0x8B63
#endif /* GL_ANGLE_texture_rectangle */

#ifndef GL_ANGLE_explicit_context
#define GL_ANGLE_explicit_context
typedef void *GLeglContext;
#include "gl2ext_explicit_context_autogen.inc"
// #include "../GLES3/gl3ext_explicit_context_autogen.inc"
// #include "../GLES3/gl31ext_explicit_context_autogen.inc"
#endif /* GL_ANGLE_explicit_context */

// clang-format on

#endif  // INCLUDE_GLES2_GL2EXT_ANGLE_H_
