import GafferUI

import DemoGafferExtension
import DemoGafferExtensionUI

nodeMenu = GafferUI.NodeMenu.acquire( application )
nodeMenu.append( "/DemoGafferExtension/DemoSceneProcessor", DemoGafferExtension.DemoSceneProcessor, searchText = "Demo SceneProcessor" )
