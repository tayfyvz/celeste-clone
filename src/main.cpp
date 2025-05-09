// #############################################################################
//                           Platform Globals
// #############################################################################

static bool running = true;

// #############################################################################
//                           Platform Functions
// #############################################################################
bool platform_create_window(int width, int height, char* title);
void platform_update_window();

// #############################################################################
//                           Windows Platform
// #############################################################################
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINAX
#include <Windows.h>


// #############################################################################
//                           Windows Globals
// #############################################################################
static HWND window;

// #############################################################################
//                           Platform Implementations
// #############################################################################
LRESULT CALLBACK windows_window_callback(HWND window, UINT msg,
                                        WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (msg)
    {
    case WM_CLOSE:
    {
        running = false;
        break;
    }
    
    default:
    {
        // Let window handle the default input for now
        result = DefWindowProcA(window, msg, wParam, lParam);
    }
}

return result;
}

bool platform_create_window(int width, int height, char* title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};

    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title; // this is not the title, just a unique identifier(ID)
    wc.lpfnWndProc = windows_window_callback; // Callback for input the Window

    if (!RegisterClassA(&wc))
    {
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(0, title, // This references lpszClassName from wc
                                title,      // This is the actual Title
                                dwStyle,
                                100,
                                100,
                                width,
                                height,
                                NULL,       // Parent
                                NULL,       // Menu
                                instance,
                                NULL);      // lpParam
    if (window == NULL)
    {
        return false;
    }
    
    ShowWindow(window, SW_SHOW);

    return true;
}

void platform_update_window()
{
    MSG msg;

    while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg); // Calls the callback specified when creating the window
    }
    
}

#endif

int main()
{
    platform_create_window(1200, 720, "Tadpole Motor");
    
    while (running)
    {
        platform_update_window();
    }

    return 0;
}