import IECore

import Gaffer
import DemoGafferExtension


Gaffer.Metadata.registerNode(

    DemoGafferExtension.DemoSceneProcessor,

    "description",
    """
    Describe what the node does
    """,

    plugs = {

        "a" : [

            "description",
            """
            Describe what plug A is used for
            """,

            "plugValueWidget:type", "",

        ],

        "b" : [

            "description",
            """
            Descrive what plug B is used for
            """,
        ],

    },

)
