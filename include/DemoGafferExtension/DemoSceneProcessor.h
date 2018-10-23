#ifndef DEMOGAFFEREXTENSION_DEMOSCENEPROCESSOR_H
#define DEMOGAFFEREXTENSION_DEMOSCENEPROCESSOR_H

#include "DemoGafferExtension/TypeIds.h"

#include "GafferScene/SceneElementProcessor.h"
#include "GafferScene/ScenePlug.h"

#include "Gaffer/ValuePlug.h"
#include "Gaffer/StringPlug.h"

namespace DemoGafferExtension
{

class DemoSceneProcessor : public GafferScene::SceneElementProcessor
{

public:

	DemoSceneProcessor( const std::string &name = defaultName<DemoSceneProcessor>() );
	~DemoSceneProcessor() = default;

	IE_CORE_DECLARERUNTIMETYPEDEXTENSION( DemoGafferExtension::DemoSceneProcessor, TypeId::DemoSceneProcessorTypeId, GafferScene::SceneElementProcessor );

	GafferScene::ScenePlug *aPlug();
	const GafferScene::ScenePlug *aPlug() const;

	Gaffer::StringPlug *bPlug();
	const Gaffer::StringPlug *bPlug() const;

	void affects( const Gaffer::Plug *input, AffectedPlugsContainer &outputs ) const override;

	bool processesBound() const override;
	void hashProcessedBound( const ScenePath &path, const Gaffer::Context *context, IECore::MurmurHash &h ) const override;
	Imath::Box3f computeProcessedBound( const ScenePath &path, const Gaffer::Context *context, const Imath::Box3f &inputBound ) const override;

	bool processesObject() const override;
	void hashProcessedObject( const ScenePath &path, const Gaffer::Context *context, IECore::MurmurHash &h ) const override;
	IECore::ConstObjectPtr computeProcessedObject( const ScenePath &path, const Gaffer::Context *context, IECore::ConstObjectPtr inputObject ) const override;

private :

	static size_t g_firstPlugIndex;

};

} // namespace DemoGafferExtension

#endif // DEMOGAFFEREXTENSION_DEMOSCENEPROCESSOR_H
