import GafferUI

import DemoGafferExtension

nodeMenu = GafferUI.NodeMenu.acquire( application )
nodeMenu.append( "/DemoGafferExtension/DemoSceneProcessor", DemoGafferExtension.DemoSceneProcessor, searchText = "Demo SceneProcessor" )
