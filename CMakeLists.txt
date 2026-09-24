cmake_minimum_required(VERSION 3.18)

set(PROJECT MoonCSFML)

project(${PROJECT} C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(MAIN_FILE main.c)								# For tests only

set(
	ASSERT_MOON_VERTEX_LAYOUT 1
#[[
	This is because of 'reinterpret_cast' array of vertices.
	Set to 0 if you want to skip check.
]]
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_SHARED "Build as shared library" ON)

option(BUILD_STATIC "Build as static library" OFF)	# Static build may not include all deps.

option(USE_STATIC_STD_LIBS "Try to link static standard libraries" ON)

# on Windows you may not have libasan
option(USE_ADDRESS_SANITAZERS "Use address sanitazers for Debug build or not" OFF)

# If neither shared nor static is specified, it builds executable

if(BUILD_SHARED AND BUILD_STATIC)
    message(FATAL_ERROR
        "You cannot have both BUILD_SHARED and BUILD_STATIC \"ON\" in the same time."
    )
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(BUILD_DEBUG ON)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(BUILD_DEBUG OFF)
else()
	set(BUILD_DEBUG ON)
endif()

if (APPLE)
	message(FATAL_ERROR
		"Apple is not supported."
	)
endif()

if (NOT CMAKE_C_COMPILER_ID STREQUAL "GNU"
    OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR
        "Only GCC/MinGW supported.\n"
        "C compiler: ${CMAKE_C_COMPILER_ID}\n"
        "CXX compiler: ${CMAKE_CXX_COMPILER_ID}"
    )
endif()

if(NOT BUILD_DEBUG)
	set(CMAKE_C_FLAGS_DEBUG   "-g -O0")
	set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG -ffunction-sections -fdata-sections -Wl,--gc-sections")
	set(CMAKE_CXX_FLAGS_DEBUG   "-g -O0")
	set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -ffunction-sections -fdata-sections -Wl,--gc-sections")
	add_link_options(
        -Wl,--gc-sections
    )
endif()

add_compile_options(
	-Wall -Wextra -Wpedantic
)

if (BUILD_DEBUG AND USE_ADDRESS_SANITAZERS)
	add_compile_options(
		-fsanitize=address,undefined
	)
	add_link_options(
        -fsanitize=address,undefined
    )
endif()

if (USE_STATIC_STD_LIBS)
	add_compile_options(
		-static -static-libgcc -static-libstdc++ -pthread
	)
endif()


set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML2")

set(INCLUDE_DIR "${SFML_DIR}/include")

set(SFML_LIB_DIR "${SFML_DIR}/libs")

# SFML 2.6.2

if(WIN32)
	set(SFML_LIBS_DIR "${SFML_LIB_DIR}/Win_mingw")
else()
	set(SFML_LIBS_DIR "${SFML_LIB_DIR}/Lin_gcc")
endif()

# Trying to keep everything locally

set(LIB_SFML_SYSTEM  		"${SFML_LIBS_DIR}/libsfml-system-s.a")
set(LIB_SFML_WINDOW  		"${SFML_LIBS_DIR}/libsfml-window-s.a")
set(LIB_SFML_GRAPHICS 		"${SFML_LIBS_DIR}/libsfml-graphics-s.a")
set(LIB_SFML_AUDIO    		"${SFML_LIBS_DIR}/libsfml-audio-s.a")
set(LIB_FLAC				"${SFML_LIBS_DIR}/libFLAC.a")
set(LIB_FREETYPE 			"${SFML_LIBS_DIR}/libfreetype.a")
set(LIB_HARFBUZZ_GPU 		"${SFML_LIBS_DIR}/libharfbuzz-gpu.a")
set(LIB_HARFBUZZ_RASTER 	"${SFML_LIBS_DIR}/libharfbuzz-raster.a")
set(LIB_HARFBUZZ_SUBSET 	"${SFML_LIBS_DIR}/libharfbuzz-subset.a")
set(LIB_HARFBUZZ_VECTOR 	"${SFML_LIBS_DIR}/libharfbuzz-vector.a")
set(LIB_HARFBUZZ 			"${SFML_LIBS_DIR}/libharfbuzz.a")
set(LIB_OGG					"${SFML_LIBS_DIR}/libogg.a")
set(LIB_VORBIS 				"${SFML_LIBS_DIR}/libvorbis.a")
set(LIB_VORBISENC 			"${SFML_LIBS_DIR}/libvorbisenc.a")
set(LIB_VORBISFILE 			"${SFML_LIBS_DIR}/libvorbisfile.a")
set(LIB_OPENAL 				"${SFML_LIBS_DIR}/libopenal.a")
set(LIB_MYSOFA				"${SFML_LIBS_DIR}/libmysofa.a")
set(LIB_BZIP2				"${SFML_LIBS_DIR}/libbz2.a")
set(LIB_PNG					"${SFML_LIBS_DIR}/libpng.a")
set(LIB_ZLIB				"${SFML_LIBS_DIR}/libz.a")
set(LIB_BROTLI 				"${SFML_LIBS_DIR}/libbrotlidec.a")
set(LIB_BROTLIENC 			"${SFML_LIBS_DIR}/libbrotlienc.a")
set(LIB_BROTLICOMMON 		"${SFML_LIBS_DIR}/libbrotlicommon.a")

set(SOURCES
	src/system/Converters.cpp
	src/system/moon_time.cpp
	src/system/moon_angle.cpp
	src/system/moon_sleep.cpp
	src/system/moon_clock.cpp
	src/system/moon_utils.cpp
	src/system/moon_strutils.cpp

	src/window/Converters.cpp
	src/window/moon_event.cpp
	src/window/moon_mouse.cpp
	src/window/moon_touch.cpp
	src/window/moon_sensor.cpp
	src/window/moon_keyboard.cpp
	src/window/moon_clipboard.cpp
	src/window/moon_video_mode.cpp
	src/window/moon_video_modes_gen.cpp
	src/window/moon_context_settings.cpp

	src/graphics/Converters.cpp
	src/graphics/moon_font.cpp
	src/graphics/moon_text.cpp
	src/graphics/moon_rect.cpp
	src/graphics/moon_view.cpp
	src/graphics/moon_glyph.cpp
	src/graphics/moon_color.cpp
	src/graphics/moon_image.cpp
	src/graphics/moon_shader.cpp
	src/graphics/moon_sprite.cpp
	src/graphics/moon_texture.cpp
	src/graphics/moon_transform.cpp
	src/graphics/moon_blend_mode.cpp
	src/graphics/moon_convex_shape.cpp
	src/graphics/moon_circle_shape.cpp
	src/graphics/moon_rectangle_shape.cpp
	src/graphics/moon_vertex.cpp
	src/graphics/moon_vertex_array.cpp
	src/graphics/moon_vertex_buffer.cpp
	src/graphics/moon_render_states.cpp
	src/graphics/moon_render_window.cpp

	src/audio/moon_music.cpp
	src/audio/moon_sound.cpp
	src/audio/moon_sound_buffer.cpp
	src/audio/moon_sound_buffer_recorder.cpp
	src/audio/moon_listener.cpp
	src/audio/moon_audio_capture_devices.cpp

	src/extras/moon_utf8.c
	src/extras/moon_path.c
	src/extras/moon_pathgen.c
	src/extras/moon_winstuff.c
	src/extras/moon_file.cpp
	src/extras/moon_filelines.cpp
	src/extras/moon_destroyer.cpp
	src/extras/moon_destroyable.cpp
	src/extras/moon_draw_group.cpp
	src/extras/moon_text_write.cpp
	src/extras/moon_gui_fpscntr.cpp
	src/extras/moon_useful_funcs.cpp
	src/extras/moon_standard_sizes.cpp
	src/extras/moon_slide_animation.cpp
	src/extras/moon_sprite_transform.cpp
)

if(BUILD_STATIC OR BUILD_SHARED)
	set(LINK_SCOPE PUBLIC)
elseif(BUILD_SHARED)
	set(LINK_SCOPE PUBLIC)
else()
	set(LINK_SCOPE PRIVATE)
endif()

if(BUILD_SHARED)
	add_library(${PROJECT} SHARED ${SOURCES})
	target_compile_definitions(${PROJECT}
		PRIVATE MOON_CSFML_EXPORTS
	)
elseif(BUILD_STATIC)
	add_library(${PROJECT} STATIC ${SOURCES})
else()
	list(APPEND SOURCES ${MAIN_FILE})
	add_executable(${PROJECT} ${SOURCES})
endif()

if (USE_STATIC_STD_LIBS)
	target_compile_options(${PROJECT} PRIVATE
        -pthread
    )

    if (WIN32)
		target_link_options(${PROJECT} PRIVATE
			-static
			-static-libgcc
			-static-libstdc++
			-pthread
		)
	else()										# Because of elf format
		target_link_options(${PROJECT} PRIVATE
			-static-libgcc
			-static-libstdc++
			-pthread
		)
	endif()

endif()

target_include_directories(${PROJECT} PRIVATE "${INCLUDE_DIR}")

target_compile_options(${PROJECT} PRIVATE
    -finput-charset=UTF-8
)

if(UNIX)
	cmake_policy(SET CMP0072 NEW)
	set(OpenGL_GL_PREFERENCE GLVND)
	find_package(OpenGL REQUIRED)
	target_link_libraries(${PROJECT} ${LINK_SCOPE}
		X11 Xrandr Xcursor Xinerama Xi Xxf86vm
		xkbcommon-x11 Xrender
		-Wl,--whole-archive "${LIB_SFML_SYSTEM}" -Wl,--no-whole-archive
		"LINKER:--start-group"

			"${LIB_SFML_WINDOW}"
			"${LIB_SFML_GRAPHICS}"
			"${LIB_SFML_AUDIO}"

			"${LIB_PNG}"
			"${LIB_BZIP2}"

			"${LIB_FLAC}"
			"${LIB_ZLIB}"
			"${LIB_FREETYPE}"

			"${LIB_HARFBUZZ_GPU}"
			"${LIB_HARFBUZZ_RASTER}"
			"${LIB_HARFBUZZ_SUBSET}"
			"${LIB_HARFBUZZ_VECTOR}"
			"${LIB_HARFBUZZ}"

			"${LIB_BROTLI}"
			"${LIB_BROTLIENC}"
			"${LIB_BROTLICOMMON}"

			"${LIB_VORBISFILE}"
			"${LIB_VORBISENC}"
			"${LIB_OPENAL}"
			"${LIB_MYSOFA}"
			"${LIB_VORBIS}"
			"${LIB_OGG}"

		"LINKER:--end-group"
		udev m pthread dl OpenGL::GL
	)
else()
	target_link_libraries(${PROJECT} ${LINK_SCOPE}
		-Wl,--whole-archive "${LIB_SFML_SYSTEM}" -Wl,--no-whole-archive
		"-Wl,--start-group"

			"${LIB_SFML_WINDOW}"
			"${LIB_SFML_GRAPHICS}"
			"${LIB_SFML_AUDIO}"

			"${LIB_PNG}"
			"${LIB_BZIP2}"

			"${LIB_FLAC}"
			"${LIB_ZLIB}"
			"${LIB_FREETYPE}"

			"${LIB_HARFBUZZ_GPU}"
			"${LIB_HARFBUZZ_RASTER}"
			"${LIB_HARFBUZZ_SUBSET}"
			"${LIB_HARFBUZZ_VECTOR}"
			"${LIB_HARFBUZZ}"

			"${LIB_BROTLI}"
			"${LIB_BROTLIENC}"
			"${LIB_BROTLICOMMON}"

			"${LIB_VORBISFILE}"
			"${LIB_VORBISENC}"
			"${LIB_OPENAL}"
			"${LIB_MYSOFA}"
			"${LIB_VORBIS}"
			"${LIB_OGG}"

		"-Wl,--end-group"
		m pthread
		avrt winmm ws2_32 opengl32 gdi32
		user32 kernel32 advapi32
	)
endif()

target_compile_definitions(${PROJECT} PRIVATE SFML_STATIC)

target_compile_definitions(${PROJECT} PRIVATE
	MOON_CSFML_ASSERT_MOON_VERTEX_LAYOUT=${ASSERT_MOON_VERTEX_LAYOUT}
)
