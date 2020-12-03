cmake_minimum_required(VERSION 3.0)
project(DemoGafferExtension)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE OFF)

if(APPLE)
  set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
endif(APPLE)

# build the library
file( GLOB DemoGafferExtensionSrc src/DemoGafferExtension/*.cpp )
link_directories( DemoGafferExtension ${GAFFER_ROOT}/lib )
add_library( DemoGafferExtension SHARED ${DemoGafferExtensionSrc} )
target_compile_definitions( DemoGafferExtension PRIVATE BOOST_SIGNALS_NO_DEPRECATION_WARNING=1 -D_GLIBCXX_USE_CXX11_ABI=0 )
target_include_directories( DemoGafferExtension PRIVATE include ${GAFFER_ROOT}/include )
target_link_libraries( DemoGafferExtension Gaffer GafferScene IECore )
install( TARGETS DemoGafferExtension DESTINATION lib)

# build the python bindings
file( GLOB DemoGafferExtensionModuleSrc src/DemoGafferExtensionModule/*.cpp )
add_library( DemoGafferExtensionModule SHARED ${DemoGafferExtensionModuleSrc} )
set_target_properties( DemoGafferExtensionModule PROPERTIES PREFIX "" OUTPUT_NAME "_DemoGafferExtension" )
target_compile_definitions( DemoGafferExtensionModule PRIVATE BOOST_SIGNALS_NO_DEPRECATION_WARNING=1 -D_GLIBCXX_USE_CXX11_ABI=0 )
target_link_libraries( DemoGafferExtensionModule DemoGafferExtension )

if(APPLE)
  target_include_directories( DemoGafferExtensionModule PRIVATE include ${GAFFER_ROOT}/include ${GAFFER_ROOT}/lib/Python.framework/Versions/2.7/include/python2.7 )
  target_link_libraries( DemoGafferExtensionModule GafferBindings IECorePython boost_python Python)
else()
  target_include_directories( DemoGafferExtensionModule PRIVATE include ${GAFFER_ROOT}/include ${GAFFER_ROOT}/include/python2.7 )
  target_link_libraries( DemoGafferExtensionModule GafferBindings IECorePython boost_python python2.7)
endif(APPLE)

install( TARGETS DemoGafferExtensionModule DESTINATION python/DemoGafferExtension )

# build the python modules
file( GLOB DemoGafferExtensionModuleFiles python/DemoGafferExtension/*.py )
install( FILES ${DemoGafferExtensionModuleFiles} DESTINATION python/DemoGafferExtension )
file( GLOB DemoGafferExtensionTestModuleFiles python/DemoGafferExtensionTest/*.py )
install( FILES ${DemoGafferExtensionTestModuleFiles} DESTINATION python/DemoGafferExtensionTest )
file( GLOB DemoGafferExtensionUIModuleFiles python/DemoGafferExtensionUI/*.py )
install( FILES ${DemoGafferExtensionUIModuleFiles} DESTINATION python/DemoGafferExtensionUI )
file( GLOB DemoGafferExtensionUITestModuleFiles python/DemoGafferExtensionUITest/*.py )
install( FILES ${DemoGafferExtensionUITestModuleFiles} DESTINATION python/DemoGafferExtensionUITest )

# build the startup configs
install( DIRECTORY startup DESTINATION . FILES_MATCHING PATTERN "*.py" )
