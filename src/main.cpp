#include "tadpole_lib.h"

#include "platform.h"

#define APIENTRY
#include "glcorearb.h"

#ifdef _WIN32
#include "win32_platform.cpp"
#endif

#include "gl_renderer.h"

int main()
{
    platform_create_window(1200, 720, "Tadpole Motor");
    
    while (running)
    {
        platform_update_window();

        // SM_TRACE("Test");
        // SM_WARN("Test");
        // SM_ERROR("Test");
        // SM_ASSERT(false, "Assertion Not Hit!");
    }

    return 0;
}