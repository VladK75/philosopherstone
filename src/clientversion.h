#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

//
// client versioning
//

// These need to be macros, as version.cpp's and bitcoin-qt.rc's voodoo requires it

// Set to true for release, false for prerelease or test build
#define CLIENT_VERSION_IS_RELEASE true

#define CLIENT_VERSION_MAJOR       1
#define CLIENT_VERSION_MINOR       6
#define CLIENT_VERSION_REVISION    6


// ARM cpus do not have "MMX" extensions and must use a "new" separate ARM-compatible "srcypt-arm.S" file without mmx-commands of
// Diamond-coin: https://github.com/feldenthorne/Diamond/commit/01046753bf3e566d000854a41a2417493bd8db7c#diff-692b9d8596020ed1936d7f5af9508722
// For distinguishing ARM-builds from "normal"-builds a dot "." as marker is added to the number of CLIENT_VERSION_BUILD
#define CLIENT_VERSION_BUILD       8.


// If cpu is not an ARM-cpu number of CLIENT_VERSION_BUILD is without additional dot "." 
// No feature or function changes from 1.6.6.7 to 1.6.6.8 for non-ARM-cpus, only some configuration file optimizations. (see source code changes)
extern "C" {
  #ifndef NOSSE
  #ifndef NO_ASM
  #define CLIENT_VERSION_BUILD     8
  #endif
  #endif
}

// Converts the parameter X to a string after macro replacement on X has been performed.
// Don't merge these into one macro!
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

#endif // CLIENTVERSION_H
