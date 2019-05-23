# Demo Gaffer Extension

This is a simple demonstration of how a software vendor or studio can add extensions to Gaffer.

By following the instructions below, you should be able to compile, install, and run Gaffer with
your custom extension.

> Note : The DemoGafferExtension is basically a no-op, and is intended as a starting point for those
> writing a real extension. You should expect to rename folders, files, and classes as appropriate.

### Build Instructions

**Requires:**

* cmake
* Gaffer Install

**In a terminal:**

```
setenv GAFFER_ROOT <gaffer install path>
setenv DEMO_INSTALL_PREFIX <your extension install path>

mkdir gafferExtensionDemo/cmake-build-default
cd gafferExtensionDemo/cmake-build-default
cmake -DGAFFER_ROOT=$GAFFER_ROOT -DCMAKE_INSTALL_PREFIX=$DEMO_INSTALL_PREFIX ..
make install -j <num cores>
```

### Runtime Instructions

Now that you've installed the extension to `$DEMO_INSTALL_PREFIX`, you need to tell Gaffer about it:

`setenv GAFFER_EXTENSION_PATHS $DEMO_INSTALL_PREFIX:$GAFFER_EXTENSION_PATHS`

And then run `gaffer` as normal.
