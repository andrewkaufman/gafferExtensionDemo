#ifndef DEMOGAFFEREXTENSION_TYPEIDS_H
#define DEMOGAFFEREXTENSION_TYPEIDS_H

namespace DemoGafferExtension
{

enum class TypeId
{
	// make sure to claim a range with Cortex
	FirstTypeId = 120000,

	DemoSceneProcessorTypeId = 120001,

	LastTypeId = 120499,
};

} // namespace DemoGafferExtension

#endif // DEMOGAFFEREXTENSION_TYPEIDS_H
