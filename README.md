# ANGLE - Almost Native Graphics Layer Engine

## Vita version

This is a port of ANGLE that runs on the Playstation Vita via [PVR_PSP2](https://github.com/GrapheneCt/PVR_PSP2)

### Compiling

To compile this port for use with vitasdk, do the following in the project root:

```
cmake .
make -j8
```

Then, you'll have to copy liblibGLESv2.a to (VITASDK)/arm-vita-eabi/lib/
You'll also have to copy the include/GLES2 folder into (VITASDK)/arm-vita-eabi/include/angle/ (make a folder called angle there)

### Usage

Remove the includes to GLES2 from PVRPSP2, if you have any

My includes look like this as an example:
```
#include <angle/GLES2/gl2.h>
#include <angle/GLES2/gl2ext.h>
#include <EGL/eglplatform.h>
#include <EGL/egl.h>
#include <gpu_es4/psp2_pvr_hint.h>
```


To use it inside your project link the following libraries:

```
liblibGLESv2.a
liblibIMGEGL_stub.a
liblibgpu_es4_ext_stub.a
```

Then, initialize PVR_PSP2 and EGL as usual. 
After the EGL context is created, call `glInitAngle(0, 0, 0);` before any GLES2 call.

## VPK
The vpk should include:
```
libGLESv2.suprx
libgpu_es4_ext.suprx
libIMGEGL.suprx
libpvrPSP2_WSEGL.suprx
```
Make sure these files are from [PVR_PSP2 Version 3.5](https://github.com/GrapheneCt/PVR_PSP2/releases/tag/v3.5) if you have issues with the latest release of PVR_PSP2.

# About the original project

The goal of ANGLE is to allow users of multiple operating systems to seamlessly run WebGL and other
OpenGL ES content by translating OpenGL ES API calls to one of the hardware-supported APIs available
for that platform. ANGLE currently provides translation from OpenGL ES 2.0 and 3.0 to desktop
OpenGL, OpenGL ES, Direct3D 9, and Direct3D 11. Support for translation from OpenGL ES to Vulkan is
underway, and future plans include compute shader support (ES 3.1) and MacOS support.

### Level of OpenGL ES support via backing renderers

|                |  Direct3D 9   |  Direct3D 11     |   Desktop GL   |    GL ES      |    Vulkan     |
|----------------|:-------------:|:----------------:|:--------------:|:-------------:|:-------------:|
| OpenGL ES 2.0  |    complete   |    complete      |    complete    |   complete    |  in progress  |
| OpenGL ES 3.0  |               |    complete      |    complete    |  in progress  |  not started  |
| OpenGL ES 3.1  |               |   not started    |   in progress  |  in progress  |  not started  |

### Platform support via backing renderers

|             |    Direct3D 9  |   Direct3D 11  |   Desktop GL  |    GL ES    |   Vulkan    |
|------------:|:--------------:|:--------------:|:-------------:|:-----------:|:-----------:|
| Windows     |    complete    |    complete    |   complete    |   complete  | in progress |
| Linux       |                |                |   complete    |             | in progress |
| Mac OS X    |                |                |  in progress  |             |             |
| Chrome OS   |                |                |               |   complete  |   planned   |
| Android     |                |                |               |   complete  | in progress |

ANGLE v1.0.772 was certified compliant by passing the ES 2.0.3 conformance tests in October 2011.
ANGLE also provides an implementation of the EGL 1.4 specification.

ANGLE is used as the default WebGL backend for both Google Chrome and Mozilla Firefox on Windows
platforms. Chrome uses ANGLE for all graphics rendering on Windows, including the accelerated
Canvas2D implementation and the Native Client sandbox environment.

Portions of the ANGLE shader compiler are used as a shader validator and translator by WebGL
implementations across multiple platforms. It is used on Mac OS X, Linux, and in mobile variants of
the browsers. Having one shader validator helps to ensure that a consistent set of GLSL ES shaders
are accepted across browsers and platforms. The shader translator can be used to translate shaders
to other shading languages, and to optionally apply shader modifications to work around bugs or
quirks in the native graphics drivers. The translator targets Desktop GLSL, Direct3D HLSL, and even
ESSL for native GLES2 platforms.

## Sources

ANGLE repository is hosted by Chromium project and can be
[browsed online](https://chromium.googlesource.com/angle/angle) or cloned with

    git clone https://chromium.googlesource.com/angle/angle


## Building

View the [Dev setup instructions](doc/DevSetup.md).

## Contributing

* Join our [Google group](https://groups.google.com/group/angleproject) to keep up to date.
* Join us on IRC in the #ANGLEproject channel on FreeNode.
* [File bugs](http://anglebug.com/new) in the [issue tracker](https://bugs.chromium.org/p/angleproject/issues/list) (preferably with an isolated test-case).
* [Choose an ANGLE branch](doc/ChoosingANGLEBranch.md) to track in your own project.


* Read ANGLE development [documentation](doc).
* Look at [pending](https://chromium-review.googlesource.com/q/project:angle/angle+status:open)
  and [merged](https://chromium-review.googlesource.com/q/project:angle/angle+status:merged) changes.
* Become a [code contributor](doc/ContributingCode.md).
* Use ANGLE's [coding standard](doc/CodingStandard.md).
* Learn how to [build ANGLE for Chromium development](doc/BuildingAngleForChromiumDevelopment.md).
* Get help on [debugging ANGLE](doc/DebuggingTips.md).


* Read about WebGL on the [Khronos WebGL Wiki](http://khronos.org/webgl/wiki/Main_Page).
* Learn about implementation details in the [OpenGL Insights chapter on ANGLE](http://www.seas.upenn.edu/~pcozzi/OpenGLInsights/OpenGLInsights-ANGLE.pdf) and this [ANGLE presentation](https://drive.google.com/file/d/0Bw29oYeC09QbbHoxNE5EUFh0RGs/view?usp=sharing).
* Learn about the past, present, and future of the ANGLE implementation in [this presentation](https://docs.google.com/presentation/d/1CucIsdGVDmdTWRUbg68IxLE5jXwCb2y1E9YVhQo0thg/pub?start=false&loop=false).
* Watch a [short presentation](https://youtu.be/QrIKdjmpmaA) on the Vulkan back-end.
* If you use ANGLE in your own project, we'd love to hear about it!
