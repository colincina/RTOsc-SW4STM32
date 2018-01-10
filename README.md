# UGFX Folder

This _ugfx_ folder is referenced by one ore more projects. The
idea is that all projects within this repository make reference
to this project in case the uGFX display library is used.

For the moment the folders `src` and `include` make reference 
to the ugfx library stored in the 
[libheivs_stm32](https://repos.hevs.ch/svn/armebs4/trunk/libheivs_stm32/)
project. 

Later on, the sources for [uFGX](http://ugfx.io/) may directly be pulled 
from the official [uGFX repository](http://git.ugfx.io/uGFX/uGFX).
For the projects it will make no change as the reference
[uFGX](http://ugfx.io/) from the _ugfx_ folder.

The actual code is a copy from 
[libheivs_stm32](https://repos.hevs.ch/svn/armebs4/trunk/libheivs_stm32/) 
and based on r740.

svn:externals to `Peg r740`.

## Supplement

The whole story does not work with svn:externals. There are also relations
to FreeRTOS which are not compatible with the structure found in the CubeMX
created project.

Made a copy of the three folders and removed svn:externals from ugfx folder.