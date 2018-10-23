#include "DemoGafferExtension/DemoSceneProcessor.h"

#include "IECore/NullObject.h"

#include "OpenEXR/ImathBox.h"

IE_CORE_DEFINERUNTIMETYPED( DemoGafferExtension::DemoSceneProcessor );

using namespace Gaffer;
using namespace GafferScene;
using namespace DemoGafferExtension;

size_t DemoSceneProcessor::g_firstPlugIndex = 0;

DemoSceneProcessor::DemoSceneProcessor( const std::string &name )
	:	SceneElementProcessor( name, IECore::PathMatcher::NoMatch )
{
	storeIndexOfNextChild( g_firstPlugIndex );

	addChild( new ScenePlug( "a" ) );
	addChild( new StringPlug( "b" ) );

	// Fast pass-throughs for things we don't modify
	outPlug()->attributesPlug()->setInput( inPlug()->attributesPlug() );
	outPlug()->transformPlug()->setInput( inPlug()->transformPlug() );
}

ScenePlug* DemoSceneProcessor::aPlug()
{
	return getChild<ScenePlug>( g_firstPlugIndex );
}

const ScenePlug* DemoSceneProcessor::aPlug() const
{
	return getChild<ScenePlug>( g_firstPlugIndex );
}

StringPlug* DemoSceneProcessor::bPlug()
{
	return getChild<StringPlug>( g_firstPlugIndex + 1);
}

const StringPlug* DemoSceneProcessor::bPlug() const
{
	return getChild<StringPlug>( g_firstPlugIndex + 1);
}

void DemoSceneProcessor::affects( const Plug *input, AffectedPlugsContainer &outputs ) const
{
	SceneElementProcessor::affects( input, outputs );

	if( input->parent<ScenePlug>() == aPlug() || input == bPlug() )
	{
		outputs.push_back( outPlug()->boundPlug() );
		outputs.push_back( outPlug()->objectPlug() );
	}
}

bool DemoSceneProcessor::processesBound() const
{
	return true;
}

void DemoSceneProcessor::hashProcessedBound( const ScenePath &path, const Context *context, IECore::MurmurHash &h ) const
{
	h.append( aPlug()->boundPlug()->hash() );
	h.append( bPlug()->hash() );
}

Imath::Box3f DemoSceneProcessor::computeProcessedBound( const ScenePath &path, const Context *context, const Imath::Box3f &inputBound ) const
{
	// modify the bound here

	return inputBound;
}

bool DemoSceneProcessor::processesObject() const
{
	return true;
}

void DemoSceneProcessor::hashProcessedObject( const ScenePath &path, const Context *context, IECore::MurmurHash &h ) const
{
	h.append( aPlug()->objectPlug()->hash() );
	h.append( bPlug()->hash() );
}

IECore::ConstObjectPtr DemoSceneProcessor::computeProcessedObject( const ScenePath &path, const Context *context, IECore::ConstObjectPtr inputObject ) const
{
	IECore::ObjectPtr outputObject = inputObject->copy();

	// modify the object here

	return outputObject;
}
