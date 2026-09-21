#ifndef MOON_CSFML_GRAPHICS_MOON_RENDER_WINDOW_H
#define MOON_CSFML_GRAPHICS_MOON_RENDER_WINDOW_H


#include "./moon_rect.h"

#include "./moon_view.h"

#include "./moon_image.h"

#include "./moon_color.h"


#include "../system/moon_vector2.h"


#include "../window/moon_event.h"

#include "../window/moon_window_handle.h"

#include "../window/moon_context_settings.h"


#ifdef __cplusplus
extern "C" {
#endif


#include <wchar.h>


struct MOON_CSFML_API moon_RenderWindow;


/**
 * Window that can serve as a target for 2D drawing.
 */
typedef struct moon_RenderWindow moon_RenderWindow;


/**
 * Creates default, empty, window.
 */
MOON_CSFML_API moon_RenderWindow*
moon_RenderWindow_default();

/**
 * Creates a window from given parameters.
 * Takes title as ansi string.
 * Context settings are default.
 */
MOON_CSFML_API moon_RenderWindow*
moon_RenderWindow_createA(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const char* title,
	unsigned int style
);

/**
 * Creates a window from given parameters.
 * Takes title as ansi string.
 */
MOON_CSFML_API moon_RenderWindow*
moon_RenderWindow_createA_ex(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const char* title,
	unsigned int style,
	const moon_ContextSettings* settings
);

/**
 * Creates a window from given parameters.
 * Takes title as wide string.
 * Context settings are default.
 */
MOON_CSFML_API moon_RenderWindow*
moon_RenderWindow_createW(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const wchar_t* title,
	unsigned int style
);

/**
 * Creates a window from given parameters.
 * Takes title as wide string.
 */
MOON_CSFML_API moon_RenderWindow*
moon_RenderWindow_createW_ex(
	unsigned int width,
	unsigned int height,
	unsigned int bits_per_pixel,
	const wchar_t* title,
	unsigned int style,
	const moon_ContextSettings* settings
);

/**
 * Destroys the window.
 */
MOON_CSFML_API void
moon_RenderWindow_destroy(moon_RenderWindow* self);

/**
 * Closes the window and destroy all the attached resources.
 * After calling this function, the sf::Window instance remains
 *valid and you can call create() to recreate the window.
 * All other functions such as pollEvent() or display() will
 *still work (i.e. you don't have to test isOpen() every time),
 *and will have no effect on closed windows.
 */
MOON_CSFML_API void
moon_RenderWindow_close(moon_RenderWindow* self);

/**
 * Tells whether or not the window is open.
 * This function returns whether or not the window exists.
 * Note that a hidden window (setVisible(0)) is open
 *(therefore this function would return 1).
 * Returns 1 if the window is open, 0 if it has been closed.
 */
MOON_CSFML_API int
moon_RenderWindow_is_open(const moon_RenderWindow* self);

/**
 * Pops the event on top of the event queue, if any, and return it.
 * This function is not blocking: if there's no pending event then
 *it will return false and leave \a event unmodified.
 * Note that more than one event may be present in the event queue,
 *thus you should always call this function in a loop
 *to make sure that you process every pending event.
 * SFML example:
 * \code
 * sf::Event event;
 * while (window.pollEvent(event))
 * {
 *    // process event...
 * }
 * \endcode
 * Returns 1 if an event was returned, or 0 if the event queue was empty.
 */
MOON_CSFML_API int
moon_RenderWindow_poll_event(
	moon_RenderWindow* self,
	moon_Event* event
);

/**
 * Wait for an event and returns it.
 * This function is blocking: if there's no pending event then
 *it will wait until an event is received.
 * After this function returns (and no error occurred),
 *the \a event object is always valid and filled properly.
 * This function is typically used when you have a thread that
 *is dedicated to events handling: you want to make this thread
 *sleep as long as no new event is received.
 * SFML example:
 * \code
 * sf::Event event;
 * if (window.waitEvent(event))
 * {
 *    // process event...
 * }
 * \endcode
 * Returns 1 if any error occurred, 0 otherwise.
 */
MOON_CSFML_API int
moon_RenderWindow_wait_event(
	moon_RenderWindow* self,
	moon_Event* event
);

/**
 * Returns position of the window, in pixels.
 */
MOON_CSFML_API moon_Vector2i
moon_RenderWindow_get_position(const moon_RenderWindow* self);

/**
 * Changes the position(in pixels) of the window on screen.
 * This function only works for top-level windows
 *(i.e. it will be ignored for windows created from
 *the handle of a child window/control).
 */
MOON_CSFML_API void
moon_RenderWindow_set_position(
	moon_RenderWindow* self,
	int x, int y
);

/**
 * Returns the size(in pixels) of the rendering region of the window.
 * The size doesn't include the titlebar and borders
 *of the window.
 */
MOON_CSFML_API moon_Vector2u
moon_RenderWindow_get_size(const moon_RenderWindow* self);

/**
 * Changes the size(in pixels) of the rendering region of the window.
 */
MOON_CSFML_API void
moon_RenderWindow_set_size(
	moon_RenderWindow* self,
	unsigned int x, unsigned int y
);

/**
 * Changes the title of the window.
 * Title should be ansi string.
 */
MOON_CSFML_API void
moon_RenderWindow_set_titleA(
	moon_RenderWindow* self,
	const char* title
);

/**
 * Changes the title of the window.
 * Title should be wide string.
 */
MOON_CSFML_API void
moon_RenderWindow_set_titleW(
	moon_RenderWindow* self,
	const wchar_t* title
);

/**
 * Changes the window's icon(array of pixels).
 * The OS default icon is used by default.
 */
MOON_CSFML_API void
moon_RenderWindow_set_icon(
	moon_RenderWindow* self,
	unsigned int icon_width,
	unsigned int icon_height,
	const moon_Image* icon
);

/**
 * Show or hide the window.
 * Pass 1 to show the window, 0 to hide it.
 * The window is shown by default.
 */
MOON_CSFML_API void
moon_RenderWindow_set_visible(
	moon_RenderWindow* self,
	int is_visible
);

/**
 * Show or hide the mouse cursor.
 * Pass 1 to show the mouse cursor, 0 to hide it.
 * The mouse cursor is visible by default.
 */
MOON_CSFML_API void
moon_RenderWindow_set_mouse_cursor_visible(
	moon_RenderWindow* self,
	int is_mvisible
);

/**
 * Grab or release the mouse cursor.
 * If set, grabs the mouse cursor inside this window's client
 *area so it may no longer be moved outside its bounds.
 * Note that grabbing is only active while the window has
 *focus.
 * Pass 1 to enable, 0 to disable.
 */
MOON_CSFML_API void
moon_RenderWindow_set_mouse_cursor_grabbed(
	moon_RenderWindow* self,
	int is_mgrabbed
);

/**
 * Enable or disable automatic key-repeat.
 * If key repeat is enabled, you will receive repeated
 *KeyPressed events while keeping a* key pressed. If it is disabled,
 *you will only get a single event when the key is pressed.
 *
 * Key repeat is enabled by default.
 */
MOON_CSFML_API void
moon_RenderWindow_set_key_repeat_enabled(
	moon_RenderWindow* self,
	int is_krenabled
);

/**
 * Requests the current window to be made the active
 *foreground window.
 * At any given time, only one window may have the input focus
 *to receive input events such as keystrokes or mouse events.
 * If a window requests focus, it only hints to the operating
 *system, that it would like to be focused. The operating system
 *is free to deny the request.
 * This is not to be confused with setActive().
 */
MOON_CSFML_API void
moon_RenderWindow_request_focus(moon_RenderWindow* self);


/**
 * Why are ‘i’ and ‘j’ a good source of information?
 * They’re always in the loop.
 *
 * Why do developers use dark IDE themes?
 * Because bugs are attracted to the light.
 *
 * If you’re paid to code, you’re a programmer. But what if it’s a hobby?
 * Then you are just a grammer.
 *
 * PSA: Please be advised that “beef stew” is no longer an allowable password.
 * It’s not stroganoff.
 *
 * How do hackers escape the police?
 * \police
 *
 * A man walks into a pet shop and sees 3 monkeys, each in a cage, each with a computer.
 * The man is curious and walks up to the clerk and asks,
 *“What is the story with the monkeys?
 * “They are programming monkeys – for exampl*e this one here can complete 100 lines of C++
 *in an hour – only 100$.” The first monkey was busy typing away, and sure
 *enough it was flawless code.
 * They moved on to the second monkey who was typing even faster.
 * “This monkey knows Java, C++ and helped develop Julia – 1000$ for this one.”
 * “What about that last monkey in the biggest cage?” the man asked.
 * “Well he is 10000$’s….”
 * “That’s must be an amazing monkey! What does he do?” the man asked.
 * “Well, when he was brought in all he did was sit there while the
 *other monkeys worked, so we figured he must be executive management.”
 *
 * Why does Task Manager use the phrase “Kill the Application”?
 * Because they are all executable!
 *
 * Why do programmers confuse Halloween with Christmas?
 * Because 25 Dec == 31 Oct.
 *
 * How long does a loop last?
 * For a while.
 *
 * Why did this girl dump her boyfriend after he named a class after her?
 * She felt like he treated her like an object.
 *
 * As a programmer, sometimes I feel a void.
 * And I know I’ve reached the point of no return.
 *
 * How did pirates collaborate before computers?
 * Pier to pier networking.
 *
 * A programmer shows up for an interview at a small corporation.
 * During the interview, he is told that if he were to take the job,
 *his tasks would primarily involve going through a list of projects
 *stored in an Excel spreadsheet, one by one. The programmer asks the
 *interviewer if the company gives increased salaries over time.
 * The interviewer responds, “Yes. You’ll receive a single raise while working here.
 *It will happen after you begin the 26th row on the project list.
 *After that, you will not receive another raise for the rest of your time here.”
 * The interviewer offers the programmer a position, and the programmer accepts
 *the job, and celebrates by going to a bar with his friend. After telling his
 *friend about the interview, his friend asks, “Why would you take a job with
 *no room for growth?
 * ”The programmer responds, “because a raise starts at Z row.”
 *
 * Why do software testers have so many children?
 * Because they’re trained to reproduce mistakes.
 *
 * Why does x86 have so many instructions?
 * Because having too few would be too RISC-y.
 *
 * Why are people from Norway so good at editing files in Linux?
 * Their ancestors are vi-kings.
 *
 * Where does the USA keep its backups?
 * USB.
 *
 * Why did the database administrator leave his wife?
 * Because she had one-to-many relationships.
 *
 * What’s the difference between a dentist and a web page?
 * The doctype.
 *
 * How much does the first parameter of a shell script cost?
 * $1.
 *
 * Why did true get expelled from Java?
 * Because he was boolean all the other variables.
 *
 * Why doesn’t Jeff Bezos let Amazon programmers use C/C++?
 * Because he’s against unions.
 *
 * Two SQL developers walk into a bar & then walk straight out.
 * Because there were no tables they could join.
 *
 * What did the suicidal programmer name his final project?
 * Goodbye World.
 *
 * If you hold the Unix shell up to your ear?
 * Can you hear the C?
 *
 * Did you hear that Bash got cancer?
 * It’s terminal.
 */


/**
 * Check whether the window has the input focus.
 * At any given time, only one window may have the input focus
 *to receive input events such as keystrokes or most mouse
 *events.
 * Returns 1 if window has focus, 0 otherwise.
 */
MOON_CSFML_API int
moon_RenderWindow_has_focus(const moon_RenderWindow* self);

/**
 * Returns the OS-specific handle of the window.
 * The type of the returned handle is sf::WindowHandle,
 *which is a typedef to the handle type defined by the OS.
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't support,
 *or implement a temporary workaround until a bug is fixed.
 */
MOON_CSFML_API moon_WindowHandle
moon_RenderWindow_get_system_handle(const moon_RenderWindow* self);

/**
 * Returns the copy of the settings of the OpenGL context of the window.
 * Note that these settings may be different from what was
 *passed to the constructor or *the create() function,
 *if one or more settings were not supported. In this case,
 *SFML chose the closest match.
 */
MOON_CSFML_API moon_ContextSettings
moon_RenderWindow_get_settings(const moon_RenderWindow* self);

/**
 * Enable or disable vertical synchronization.
 * Activating vertical synchronization will limit the number
 *of frames displayed to the refresh rate of the monitor.
 * This can avoid some visual artifacts, and limit the framerate
 *to a good value (but not constant across different computers).
 *
 *Vertical synchronization is disabled by default.
 * Pass 1 to enable v-sync, 0 to deactivate it.
 */
MOON_CSFML_API void
moon_RenderWindow_set_vertical_sync_enabled(
	moon_RenderWindow* self,
	int is_vsenabled
);

/**
 * Limits the framerate(in frames per second) to a maximum fixed frequency.
 * If a limit is set, the window will use a small delay after
 *each call to display() to ensure that the current frame
 *lasted long enough to match the framerate limit.
 * SFML will try to match the given limit as much as it can,
 *but since it internally uses sf::sleep, whose precision
 *depends on the underlying OS, the results may be a little
 *unprecise as well (for example, you can get 65 FPS when
 *requesting 60).
 * Use 0 to disable limit.
 */
MOON_CSFML_API void
moon_RenderWindow_set_framerate_limit(
	moon_RenderWindow* self,
	unsigned int limit
);

/**
 * Activate or deactivate the window as the current target
 *for OpenGL rendering.
 * A window is active only on the current thread, if you want to
 *make it active on another thread you have to de*activate it
 *on the previous thread first if it was active.
 * Only one window can be active on a thread at a time, thus
 *the window previously active (if any) automatically gets deactivated.
 * This is not to be confused with requestFocus().
 * Pass 1 to activate, 0 to deactivate.
 * Returns 1 if operation was successful, 0 otherwise.
 */
MOON_CSFML_API int
moon_RenderWindow_set_active(
	moon_RenderWindow* self,
	int is_oglactive
);

/**
 * Displays on screen what has been rendered to the window so far.
 * This function is typically called after all OpenGL rendering
 *has been done for the current frame, in order to show
 *it on screen.
 */
MOON_CSFML_API void
moon_RenderWindow_display(moon_RenderWindow* self);

/**
 * Clears the entire target with a single color.
 * This function is usually called once every frame,
 *to clear the previous contents of the target.
 */
MOON_CSFML_API void
moon_RenderWindow_clear(
	moon_RenderWindow* self,
	const moon_Color* color
);

/**
 * Changes the current active view.
 *
 * The passed view will be copied, so screw it as much
 *as you want after.
 * The view is like a 2D camera, it controls which part of
 *the 2D scene is visible, and how it is viewed in the
 *render target.
 * The new view will affect everything that is drawn, until
 *another view is set.
 * The render target keeps its own copy of the view object,
 *so it is not necessary to keep the original one alive
 *after calling this function.
 * To restore the original view of the target, you can pass
 *the result of getDefaultView() to this function.
 */
MOON_CSFML_API void
moon_RenderWindow_set_view(
	moon_RenderWindow* self,
	const moon_View* view
);

/**
 * Returns copy of the view currently in use in the render target.
 */
MOON_CSFML_API moon_View
moon_RenderWindow_get_view(const moon_RenderWindow* self);

/**
 * Returns copy of the default view of the render target.
 * The default view has the initial size of the render target,
 *and never changes after the target has been created.
 */
MOON_CSFML_API moon_View
moon_RenderWindow_get_default_view(const moon_RenderWindow* self);

/**
 * Returns the viewport of a view, applied to this render target.
 * The viewport is defined in the view as a ratio, this function
 *simply applies this ratio to the current dimensions of the
 *render target to calculate the pixels rectangle that the viewport
 *actually covers in the target.
 */
MOON_CSFML_API moon_IntRect
moon_RenderWindow_get_viewport(
	const moon_RenderWindow* self,
	const moon_View* view
);

/**
 * Converts a point from target coordinates to world
 *coordinates, using the current view.
 * Returns the converted point, in "world" coordinates.
 */
MOON_CSFML_API moon_Vector2f
moon_RenderWindow_map_pixel_to_coords(
	const moon_RenderWindow* self,
	int x, int y
);

/**
 * Convert a point from target coordinates to world coordinates.
 * Returns converted point, in "world" units.
 *
 * 'view' -- view which we will use for converting the point.
 * 'view_inversed_transform' -- inversed transform of the
 *view which we will use for converting the point.
 *
 * This function finds the 2D position that matches the
 *given pixel of the render target. In other words, it does
 *the inverse of what the graphics card does, to find the
 *initial position of a rendered pixel.
 *
 * Initially, both coordinate systems (world units and target pixels)
 *match perfectly. But if you define a custom view or resize your
 *render target, this assertion is not true anymore, i.e. a point
 *located at (10, 50) in your render target may map to the point
 *(150, 75) in your 2D world -- if the view is translated by (140, 25).
 *
 * For render-windows, this function is typically used to find
 *which point (or object) is located below the mouse cursor.
 *
 * This version uses a custom view for calculations, see the other
 *overload of the function if you want to use the current view of the
 *render target.
 */
MOON_CSFML_API moon_Vector2f
moon_RenderWindow_map_pixel_to_coords_ex(
	const moon_RenderWindow* self,
	int x, int y,
	const moon_View* view,
	const moon_Transform* view_inversed_transform
);

/**
 * Converts a point from world coordinates to target
 *coordinates, using the current view.
 * Returns the converted point, in target coordinates (pixels).
 */
MOON_CSFML_API moon_Vector2i
moon_RenderWindow_map_coords_to_pixel(
	const moon_RenderWindow* self,
	float x, float y
);

/**
 * Convert a point from world coordinates to target coordinates.
 * Returns the converted point, in target coordinates (pixels).
 *
 * 'view' 			-- view which we will use for converting the point.
 * 'view_transform' -- transform of the view which we will use for converting the point.
 *
 * This function finds the pixel of the render target that matches
 *the given 2D point. In other words, it goes through the same process
 *as the graphics card, to compute the final position of a rendered point.
 *
 * Initially, both coordinate systems (world units and target pixels)
 *match perfectly. But if you define a custom view or resize your
 *render target, this assertion is not true anymore, i.e. a point
 *located at (150, 75) in your 2D world may map to the pixel
 *(10, 50) of your render target -- if the view is translated by (140, 25).
 *
 * This version uses a custom view for calculations, see the other
 *overload of the function if you want to use the current view of the
 *render target.
 */
MOON_CSFML_API moon_Vector2i
moon_RenderWindow_map_coords_to_pixel_ex(
	const moon_RenderWindow* self,
	float x, float y,
	const moon_View* view,
	const moon_Transform* view_transform
);

/**
 * Tells if the render target will use sRGB encoding when drawing on it.
 * Returns 1 if the render target use sRGB encoding, 0 otherwise.
 */
MOON_CSFML_API int
moon_RenderWindow_is_srgb(const moon_RenderWindow* self);

/**
 * Save the current OpenGL render states and matrices.
 *
 * This function can be used when you mix SFML drawing
 *and direct OpenGL rendering. Combined with popGLStates,
 *it ensures that:
 * \li SFML's internal states are not messed up by your OpenGL code
 * \li your OpenGL states are not modified by a call to a SFML function
 *
 * More specifically, it must be used around code that
 *calls Draw functions. Example(SFML):
 * \code
 * // OpenGL code here...
 * window.pushGLStates();
 * window.draw(...);
 * window.draw(...);
 * window.popGLStates();
 * // OpenGL code here...
 * \endcode
 *
 * Note that this function is quite expensive: it saves all the
 *possible OpenGL states and matrices, even the ones you
 *don't care about. Therefore it should be used wisely.
 * It is provided for convenience, but the best results will
 *be achieved if you handle OpenGL states yourself (because
 *you know which states have really changed, and need to be
 *saved and restored). Take a look at the resetGLStates
 *function if you do so.
 */
MOON_CSFML_API void
moon_RenderWindow_push_gl_states(moon_RenderWindow* self);

/**
 * Restores the previously saved OpenGL render states and matrices.
 * See the description of pushGLStates to get a detailed
 *description of these functions.
 */
MOON_CSFML_API void
moon_RenderWindow_pop_gl_states(moon_RenderWindow* self);

/**
 * Reset the internal OpenGL states so that the target is ready for drawing.
 *
 * This function can be used when you mix SFML drawing
 *and direct OpenGL rendering, if you choose not to use
 *pushGLStates/popGLStates. It makes sure that all OpenGL
 *states needed by SFML are set, so that subsequent draw()
 *calls will work as expected.
 *
 * Example(SFML):
 * \code
 * // OpenGL code here...
 * glPushAttrib(...);
 * window.resetGLStates();
 * window.draw(...);
 * window.draw(...);
 * glPopAttrib(...);
 * // OpenGL code here...
 * \endcode
 */
MOON_CSFML_API void
moon_RenderWindow_reset_gl_states(moon_RenderWindow* self);


/**
 * Why are Jedi banned from GitHub?
 * They kept force pushing their changes.
 *
 * Why is programming a lot like love making?
 * One mistake and you’re providing support for a lifetime.
 *
 * A UDP packet walks into a bar. A UDP packet walks into a bar.
 *A UDP packet walks into a bar. A UDP packet walks into a bar.
 *A UDP packet walks into a bar. The bartender says “hello.”                                                                                          * A TCP packet walks into a bar and says “I’d like a beer.” The
 *barman replies “You’d like a beer?” “Yes,” replies the
 *TCP packet, “I’d like a beer.”
 * A BitTorrent packet walks into a bar and asks for a beer. Everyone
 *in the bar who already has a beer gives him a sip. A BitTorrent packet walks
 *into a bar and asks for a beer. Everyone in the bar who already has a
 *beer gives him a sip.
 *
 * I saw a Mac user amusing himself – switching between viewing text
 *file contents through terminal and then clicking the file icon
 *to open it.
 * It was a bizarre game of cat and mouse.
 *
 * How many programmers does it take to change a lightbulb?
 * None, they prefer the dark mode.
 *
 * Why is Java like an overprotective mother?
 * Doesn’t even let you take out your garbage.
 *
 * My girlfriend is learning Linux and asked me what a kernel panic is.
 * I told her it’s what happened when the kernel only has 10 herbs and spices.
 *
 * What’s the second movie about a database engineer called?
 * The SQL.
 *
 * What did the doctor say to the man who is moving from a GUI to a CLI?
 * “You’re now entering the terminal stage of your life.”
 *
 * Who is MongoDB’s favorite singer?
 * JSON derulo.
 *
 * A guy walks into a bar and asks for 1.4 root beers.
 * The bartender says “I’ll have to charge you extra,
 *that’s a root beer float.”
 * The guy says, “In that case, better make it a double.”
 *
 * A man flying in a hot air balloon suddenly realizes he’s lost.
 *He reduces height and spots a man down below. He lowers the balloon
 *further and shouts to get directions, “Excuse me, can you tell me where I am?”
 * The man below says: “Yes. You’re in a hot air balloon, hovering 30 feet above this field.”
 * “You must work in Information Technology,” says the balloonist.
 * “I do” replies the man. “How did you know?”
 * “Well,” says the balloonist, “everything you have told me is
 *technically correct, but It’s of no use to anyone.”
 * The man below replies, “You must work in management.”
 * “I do,” replies the balloonist, “But how’d you know?”
 * “Well”, says the man, “you don’t know where you are or where you’re going,
 *but you expect me to be able to help. You’re in the same position you were
 *before we met, but now it’s my fault.”
 *
 * Why do frontend devs always eat alone?
 * They dont know how to join tables!
 *
 * Why did the web developer accept a 200 dollar raise?
 * 200 is OK.
 *
 * Age is just a number and death is just a Boolean.
 *
 * How does Karl Marx know when it’s time to free up memory?
 * When the class has no function.
 *
 * Why don’t bachelors like Git?
 * Because they are afraid to commit.
 *
 * Why do programmers take forever to wash their hair?
 * The instructions on the shampoo bottle say “lather, rinse, repeat”,
 *but don’t have a loop termination condition.
 *
 * Do you know what the hackers did when the police came to their door?
 * They ransomware safe.
 *
 * A developer was arrested for writing bad code.
 * We reached out to the alleged criminal but he refused to comment.
 *
 * One of my CS students asked me for a book on references in C++.
 * I didn’t have one, so instead I offered him a few pointers.
 *
 * My computer showed up late to work today.
 * Must’ve had a hard drive.
 *
 * Why does Yoda’s code always crash?
 * Because there is no try.
 *
 * Humans are being tested against the new AI program.
 * The robot beats the hu*man in every category.
 * It comes to one of the last ones: hunting. The robot again beats the human.
 *However, someone working there sets the animals free again and tells them
 *to try get them again. The robot doesn’t move whilst the
 *human wins because ROBOTS CANT RECAPTCHA.
 *
 * Why is code like a joke?
 * If you have to explain it, it’s bad.
 * See? Because if you have to explain a joke, it’s not funny.
 */


/**
 * Moves window across the screen using given offsets.
 */
MOON_CSFML_API void
moon_RenderWindow_move(
	moon_RenderWindow* self,
	int dx, int dy
);


#ifdef __cplusplus
}
#endif


#endif
