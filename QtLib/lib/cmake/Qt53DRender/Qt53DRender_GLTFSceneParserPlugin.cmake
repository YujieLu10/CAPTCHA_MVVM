
add_library(Qt5::GLTFSceneParserPlugin MODULE IMPORTED)

_populate_3DRender_plugin_properties(GLTFSceneParserPlugin RELEASE "sceneparsers/gltfsceneparser.dll")
_populate_3DRender_plugin_properties(GLTFSceneParserPlugin DEBUG "sceneparsers/gltfsceneparserd.dll")

list(APPEND Qt53DRender_PLUGINS Qt5::GLTFSceneParserPlugin)
