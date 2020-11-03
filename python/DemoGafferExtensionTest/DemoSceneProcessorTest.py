import unittest

import Gaffer
import GafferScene

import GafferTest
import GafferSceneTest

import DemoGafferExtension

class DemoSceneProcessorTest( GafferSceneTest.SceneTestCase ) :

	def testConstruct( self ) :

		node = DemoGafferExtension.DemoSceneProcessor()
		self.assertEqual( node.getName(), "DemoSceneProcessor" )

	def testCompute( self ) :

		node = DemoGafferExtension.DemoSceneProcessor()
		sphere = GafferScene.Sphere()
		node["in"].setInput( sphere["out"] )

		# DemoSceneProcessor is a no-op, so we should just
		# be passing through the input scene unchanged
		self.assertScenesEqual( node["out"], sphere["out"] )

		node["b"].setValue( "test" )
		# DemoSceneProcessor is a no-op, so we should just
		# be passing through the input scene unchanged
		self.assertScenesEqual( node["out"], sphere["out"] )

	def testAffects( self ) :

		node = DemoGafferExtension.DemoSceneProcessor()
		s = GafferTest.CapturingSlot( node.plugDirtiedSignal() )

		sphere = GafferScene.Sphere()
		node["a"].setInput( sphere["out"] )
		affected = [ c[0] for c in s ]
		self.assertTrue( node["a"] in affected )
		self.assertTrue( node["out"]["bound"] in affected )
		self.assertTrue( node["out"]["object"] in affected )
		self.assertTrue( node["out"] in affected )

		del s[:]

		node["b"].setValue( "test" )
		self.assertEqual( len( s ), 5 )
		self.failUnless( s[0][0].isSame( node["b"] ) )
		self.failUnless( s[1][0].isSame( node["out"]["childBounds"] ) )
		self.failUnless( s[2][0].isSame( node["out"]["bound"] ) )
		self.failUnless( s[3][0].isSame( node["out"]["object"] ) )
		self.failUnless( s[4][0].isSame( node["out"] ) )

if __name__ == "__main__":
	unittest.main()
