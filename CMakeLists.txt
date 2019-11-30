cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

include_directories(src SoundFile)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if (MSVC)
target_link_libraries(rend glew32 opengl32 OpenAL32)
else()
target_link_libraries(rend GLEW GL)
endif()


add_library(engine
src/engine/Application.h
src/engine/Application.cpp
src/engine/Entity.h
src/engine/Entity.cpp
src/engine/Component.h
src/engine/Component.cpp
src/engine/Renderer.h
src/engine/Renderer.cpp
src/engine/stb_image.h
src/engine/Audio.h
src/engine/Audio.cpp
src/engine/Camera.cpp
src/engine/Camera.h
src/engine/Transform.h
src/engine/Transform.cpp
src/engine/Environment.h
src/engine/Environment.cpp
)
target_link_libraries(engine SDL2 rend OpenAL32)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game engine)